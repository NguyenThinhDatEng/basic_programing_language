var http = require('http');
var fs = require('fs');

const server = http.createServer((req, res) => {
    res.writeHead(200, {
        'Content-Type' : 'text/html'
    })
    fs.ReadStream("background.html").pipe(res);
}).listen(3000);