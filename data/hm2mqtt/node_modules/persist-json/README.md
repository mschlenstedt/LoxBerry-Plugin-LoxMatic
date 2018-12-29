# persist-json

[![NPM version](https://badge.fury.io/js/persist-json.svg)](http://badge.fury.io/js/persist-json)
[![Dependency Status](https://img.shields.io/gemnasium/hobbyquaker/persist-json.svg?maxAge=2592000)](https://gemnasium.com/github.com/hobbyquaker/persist-json)
[![Build Status](https://travis-ci.org/hobbyquaker/persist-json.svg?branch=master)](https://travis-ci.org/hobbyquaker/persist-json)
[![Coverage Status](https://coveralls.io/repos/github/hobbyquaker/persist-json/badge.svg?branch=master)](https://coveralls.io/github/hobbyquaker/persist-json?branch=master)
[![XO code style](https://img.shields.io/badge/code_style-XO-5ed9c7.svg)](https://github.com/sindresorhus/xo)
[![License][mit-badge]][mit-url]

> Persist an object as plain JSON file

## Usage

```npm install persist-json```

```Javascript
var pjson = require('persist-json')('project-name');
```

The path where the JSON file will be stored is determinated by the [persist-path](https://github.com/hobbyquaker/persist-path) module.

## Methods

Both methods save and load can be used either asynchronous (by providing a callback as last param) or synchronous.
On asynchronous usage the callback is called with the params of `fs.writeFileSync` respectively `fs.readFileSync`.

#### *undefined* save( *string* filename , *object* content [, *function* callback ] )

#### *object|undefined* load( *string* filename [, *function* callback ] )


## Secure mode

```Javascript
var pjson = require('persist-json')('project-name', {secure: true});
```

Secure mode saves the file first with suffixed `.new`, then renames an eventually existing `file` to `file.bak` and then
renames the `file.new` file to `file`.


# License

MIT (c) 2016-2017 [Sebastian Raff](https://github.com/hobbyquaker)

[mit-badge]: https://img.shields.io/badge/License-MIT-blue.svg?style=flat
[mit-url]: LICENSE
