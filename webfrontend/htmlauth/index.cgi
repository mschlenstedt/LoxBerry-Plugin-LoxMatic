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

##########################################################################
# Modules
##########################################################################

use LoxBerry::System;
use LoxBerry::JSON;
use LoxBerry::Web;
use LoxBerry::Log;
use CGI::Carp qw(fatalsToBrowser);
use CGI;
use warnings;
use strict;

##########################################################################
# Variables
##########################################################################

my $helplink = "https://www.loxwiki.eu/x/1IaxAg";
my $helptemplate = "help.html";

##########################################################################
# Read Settings
##########################################################################

# Version of this script
my $version = "0.0.1";
my $cgi = CGI->new;
$cgi->import_names('R');

my $cfgfile = "$lbpconfigdir/loxmatic.json";

##########################################################################
# Main program
##########################################################################

# Prevent 'only used once' warnings from Perl
$R::saveformdata if 0;
%LoxBerry::Web::htmltemplate_options if 0;

# CGI Vars
my $supportkey = $R::supportkey;

# Template
my $maintemplate = HTML::Template->new(
	filename => "$lbptemplatedir/settings.html",
	global_vars => 1,
	loop_context_vars => 1,
	die_on_bad_params=> 0,
	#associate => $cfg,
	%LoxBerry::Web::htmltemplate_options,
	# debug => 1,
	);
my %SL = LoxBerry::System::readlanguage($maintemplate, "language.ini");

# Save config
if ($saveformdata) {

	my $jsonobj = LoxBerry::JSON->new();
	my $cfg = $jsonobj->open(filename => $cfgfile);
	$cfg->{Remote}->{Httpproxy} = $R::Remote_Httpproxy;
	$cfg->{Remote}->{Httpport} = $R::Remote_Httpport;
	if ($R::Remote_Autoconnect) {
	       $cfg->{Remote}->{Autoconnect} = "1";
	} else {
	       $cfg->{Remote}->{Autoconnect} = "0";
	}
	$jsonobj->write();

	if ($R::Remote_Httpproxy) {
		my $proxy = $R::Remote_Httpproxy;
		my $port = $R::Remote_Httpport;
		$resp = `/bin/sed -i 's#^;http-proxy .*#http-proxy $proxy $port#g' $lbhomedir/system/supportvpn/loxberry.cfg 2>&1`;
		$resp = `/bin/sed -i 's#^http-proxy .*#http-proxy $proxy $port#g' $lbhomedir/system/supportvpn/loxberry.cfg 2>&1`;
		$resp = `/bin/sed -i 's#^;http-proxy\$#http-proxy $proxy $port#g' $lbhomedir/system/supportvpn/loxberry.cfg 2>&1`;
		$resp = `/bin/sed -i 's#^http-proxy\$#http-proxy $proxy $port#g' $lbhomedir/system/supportvpn/loxberry.cfg 2>&1`;
	} else {
		$resp = `/bin/sed -i 's#^http-proxy .*#;http-proxy#g' $lbhomedir/system/supportvpn/loxberry.cfg 2>&1`;
	}

}

$maintemplate->param("FORM1", 1);

# Print Template
my $template_title = $SL{'COMMON.LOXBERRY_MAIN_TITLE'} . ": " . $SL{'REMOTE.WIDGETLABEL'};
LoxBerry::Web::head();
LoxBerry::Web::pagestart($template_title, $helplink, $helptemplate);
if ($maintemplate->param("FORM1")) {
	print LoxBerry::Log::get_notifications_html("remote");
}
print $maintemplate->output();
LoxBerry::Web::pageend();
LoxBerry::Web::foot();

exit;
