const http = require('http');
const func = require('./module.js');

http.createServer(func.module01).listen(3000)