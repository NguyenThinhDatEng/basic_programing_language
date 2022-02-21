const http = require('http');

http.createServer((req, res) => {
    console.log('Server is running...');
    console.log(req.url);
}).listen(3000);