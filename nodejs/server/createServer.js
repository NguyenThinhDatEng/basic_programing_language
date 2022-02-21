const http = require('http');

// req -> yeu cau tu client gui xuong
// res -> phan hoi tu phia sever gui cho client
// createServer(req, res) -> khi co request gui den sever -> chay vao trong function nay
const server = http.createServer((req, res) => {
    res.writeHead(200, {
        'Content-Type' : 'text/html'
    })
    res.write('<h1 style = "color : red"> Hello Server </h1>');
    res.end();     // tra ve phia client 1 message
});

const PORT = 830;

server.listen(PORT, '127.0.0.1', () => {
    console.log('Sever is listening on port: ' + PORT);
})