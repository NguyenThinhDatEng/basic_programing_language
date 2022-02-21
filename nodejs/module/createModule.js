// create a function
var hello = function (name) {
    console.log('Hello ' + name);
};

hello('Thinh');

// use syntax: module.exports.module_name = variable_name;
module.exports.hi = hello;