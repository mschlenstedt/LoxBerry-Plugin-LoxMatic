var fs = require('fs');
var ppath = require('persist-path');
var mkdirp = require('mkdirp');

function Pjson(folder, options) {
    if (!(this instanceof Pjson)) {
        return new Pjson(folder, options);
    }
    if (typeof folder !== 'string' || folder === '') {
        throw new Error('param folder missing');
    }
    this.folder = folder;
    this.options = options || {};

    var p = ppath(folder);
    mkdirp(p);
}

Pjson.prototype.save = function (file, content, cb) {
    if (typeof file !== 'string' || file === '') {
        throw new Error('param file missing');
    }
    var json = JSON.stringify(content, null, '  ');
    file = ppath(this.folder, file);
    if (typeof cb === 'function') {
        if (this.options.secure) {
            fs.writeFile(file + '.new', json, err => {
                /* istanbul ignore if */
                if (err) {
                    cb(err);
                } else {
                    fs.rename(file, file + '.bak', () => {
                        fs.rename(file + '.new', file, err => {
                            cb(err);
                        });
                    });
                }
            });
        } else {
            fs.writeFile(file, json, cb);
        }
    } else if (this.options.secure) {
        fs.writeFileSync(file + '.new', json);
        try {
            fs.renameSync(file, file + '.bak');
        } catch (err) {

        }
        fs.renameSync(file + '.new', file);
        return;
    }
    return fs.writeFileSync(file, json);
};

Pjson.prototype.load = function (file, cb) {
    if (typeof file !== 'string' || file === '') {
        throw new Error('param file missing');
    }
    var f = ppath(this.folder, file);
    if (typeof cb === 'function') {
        fs.readFile(f, function (err, res) {
            if (err) {
                cb(err);
            } else {
                try {
                    var obj = JSON.parse(res);
                    cb(null, obj);
                } catch (err) {
                    cb(err);
                }
            }
        });
    } else {
        try {
            return JSON.parse(fs.readFileSync(f));
        } catch (err) {
            return undefined;
        }
    }
};

module.exports = Pjson;
