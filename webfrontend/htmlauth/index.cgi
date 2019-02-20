#!/usr/bin/perl

# Copyright 2016-2018 Michael Schlenstedt, michael@loxberry.de
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
#     http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Modules
use LoxBerry::System;
use LoxBerry::JSON;
use LoxBerry::Web;
use LoxBerry::Log;
use CGI::Carp qw(fatalsToBrowser);
use CGI;
use warnings;
use strict;

# Version of this script
my $version = "0.0.4.0";

# CGI
my $cgi = CGI->new;
my $q = $cgi->Vars;

# Everything from Forms
my $saveformdata = $q->{saveformdata};

my %pids;
my $template;

## Handle all ajax requests 
if( $q->{ajax} ) {
	
	#require JSON;
	my %response;
	ajax_header();

	if( $q->{ajax} eq "getpids" ) {
		pids();
		$response{pids} = \%pids;
		print JSON::encode_json(\%response);
	}

	if( $q->{ajax} eq "cleannamesfile" ) {
		cleannamesfile();
		$response{response} = "OK";
		print JSON::encode_json(\%response);
	}

	exit;

}

# Config
my $cfgfile = "$lbpconfigdir/loxmatic.json";

# Read json config
my $jsonobj = LoxBerry::JSON->new();
my $cfg = $jsonobj->open(filename => $cfgfile);

# Init Template
$template = HTML::Template->new (
	filename => "$lbptemplatedir/settings.html",
	global_vars => 1,
	loop_context_vars => 1,
	die_on_bad_params=> 0,
	#associate => $cfg,
	%LoxBerry::Web::htmltemplate_options,
	# debug => 1,
	);

# Language
my %SL = LoxBerry::System::readlanguage($template, "language.ini");

# Switch between forms
our %navbar;
if( !$q->{form} or $q->{form} eq "settings" ) {
	$navbar{10}{active} = 1;
	$template->param("FORM_SETTINGS", 1);
	settings_form();
}
elsif ( $q->{form} eq "sniffer" ) {
	$navbar{20}{active} = 1;
	$template->param("FORM_SNIFFER", 1);
	#sniffer_form();
}
elsif ( $q->{form} eq "firmware" ) {
	$navbar{30}{active} = 1;
	$template->param("FORM_FIRMWARE", 1);
	#firmware_form();
}

print_form();

exit;

######################################################################
# Print Form
######################################################################
sub print_form
{
        my $plugintitle = "LoxMatic v" . LoxBerry::System::pluginversion();
	my $helplink = "https://www.loxwiki.eu/x/1IaxAg";
	my $helptemplate = "help.html";

        $navbar{10}{Name} = $SL{'SETTINGS.LABEL_NAV_SETTINGS'};
        $navbar{10}{URL} = 'index.cgi';
        $navbar{10}{Notify_Package} = $lbpplugindir;

        $navbar{20}{Name} = $SL{'SETTINGS.LABEL_NAV_SNIFFER'};
        $navbar{20}{URL} = 'index.cgi?form=sniffer';

        $navbar{30}{Name} = $SL{'SETTINGS.LABEL_NAV_FIRMWARE'};
        $navbar{30}{URL} = 'index.cgi?form=firmware';

        $navbar{90}{Name} = $SL{'SETTINGS.LABEL_NAV_LOGFILES'};
	$navbar{90}{URL} =  LoxBerry::Web::loglist_url();
        $navbar{90}{target} = '_blank';

        LoxBerry::Web::lbheader($plugintitle, $helplink, $helptemplate);

	print LoxBerry::Log::get_notifications_html($lbpplugindir);
        print $template->output();

        LoxBerry::Web::lbfooter();

}

########################################################################
# Settings Form
########################################################################
sub settings_form
{

	# Save config
	if ( $saveformdata ) {

		my $error = 0;
		my $uploadfile = $cgi->param('NamesFile');
		#print STDERR "The upload file is $uploadfile.\n";
		if ($uploadfile) {
			# Max filesize (KB)
			my $max_filesize = 5000;

			# Filter Backslashes
			$uploadfile =~ s/.*[\/\\](.*)/$1/;

			# Filesize
			my $filesize = -s $uploadfile;
			$filesize /= 1000;
			#print STDERR "The upload file is $filesize kB.\n";

			# If it's larger than allowed...
			if ($filesize > $max_filesize) {
				notify( $lbpplugindir, "webif", $SL{'SETTINGS.MSG_FILESIZETOBIG'}, "error");
				$error = 1;
			}

			# json ending is important for nodejs
			my $savefile;
			if ($uploadfile !~ /^.+\.(json)$/) {
				$savefile = "$uploadfile.json";
			} else {
				$savefile = $uploadfile;
			}

			# Save file
			if (!$error) {
				open (FILE, ">/tmp/$savefile");
				while (read ($uploadfile, my $Buffer, 1024)) {
					    print FILE $Buffer;
				}
				close FILE;
			}

			# Test if we have a valid json
			if (!$error) {
				my $jsontest = LoxBerry::JSON->new();
				my $testcfg = $jsontest->open(filename => "/tmp/$savefile");
				if (!$testcfg) {
					notify( $lbpplugindir, "webif", $SL{'SETTINGS.MSG_NOTJSON'}, "error");
					$error = 1;
				} else {
					#print STDERR "$savefile is a valid json file.\n";
					if ($cfg->{NamesFile}) {
						system ("rm $lbpconfigdir/$cfg->{NamesFile}");
					}
					system ("mv /tmp/$savefile $lbpconfigdir");
					$cfg->{NamesFile} = "$lbpconfigdir/$savefile";
				}
			}

			# If an error occurred, do not use the namesfile
			if ($error) {
				$cfg->{NamesFile} = "";
				system ("rm /tmp/$savefile");
			}

		}

		$cfg->{BrokerPassword} = $q->{BrokerPassword};
		$cfg->{BrokerUsername} = $q->{BrokerUsername};
		if (LoxBerry::System::pluginloglevel() eq "7") {
			$cfg->{Debug} = "1";
		} else {
			$cfg->{Debug} = "0";
		}
		$cfg->{EnableHM2MQTT} = $q->{EnableHM2MQTT};
		$cfg->{EnableRFD} = $q->{EnableRFD};
		$cfg->{EnableHMIPSERVER} = $q->{EnableHMIPSERVER};
		$cfg->{HM2MQTTPort} = $q->{HM2MQTTPort};
		$cfg->{HM2MQTTPrefix} = $q->{HM2MQTTPrefix};
		$jsonobj->write();

		# Kill / Restart
		system ("sudo $lbhomedir/system/daemons/plugins/$lbpplugindir");

	}

	# Push json config to template
	my $cfgfilecontent = LoxBerry::System::read_file($cfgfile);
	$cfgfilecontent =~ s/[\r\n]//g;
	$template->param('JSONCONFIG', $cfgfilecontent);

	my $loglevelhtml = LoxBerry::Web::loglevel_select_html( LABEL => '', FORM => 'loglevel', DATA_MINI => 1 );
	$template->param('LOGLEVEL', $loglevelhtml);
	
	$template->param('CURRENTNAMESFILE', $cfg->{NamesFile});

}

######################################################################
# AJAX functions
######################################################################

sub pids 
{
	$pids{'rfd'} = trim(`pgrep -f rfd`) ;
	$pids{'hm2mqtt'} = trim(`pgrep -f hm2mqtt/index.js`) ;
	$pids{'hmserver'} = trim(`pgrep -f HMIPServer.jar`) ;
}	

sub cleannamesfile
{
	# Read json config
	my $cfgfile = "$lbpconfigdir/loxmatic.json";
	my $jsonobj = LoxBerry::JSON->new();
	my $cfg = $jsonobj->open(filename => $cfgfile);
	if ($cfg->{NamesFile}) {
		system ("rm $lbpconfigdir/$cfg->{NamesFile}");
	}
	$cfg->{NamesFile} = "";
	$jsonobj->write();
}	


sub pkill 
{
	my ($process) = @_;
	`pkill $process`;
	sleep 1;
	`pkill --signal SIGKILL $process`;
}
	
sub ajax_header
{
	print $cgi->header(
			-type => 'application/json',
			-charset => 'utf-8',
			-status => '200 OK',
	);
}

