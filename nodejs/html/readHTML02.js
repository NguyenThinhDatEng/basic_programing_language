const http = require('http')
const fs = require('fs')

const sever = http.createServer((req, res) => {
    fs.readFile(__dirname + "\\background.html", "utf-8", (err, content) => {
        if (err)
        {
            console.log(err)
        }
        else
        {
            res.writeHead(200, {'content-type' : 'text/html'})
            res.write(content)
            res.end();
        }
    })
}).listen(3000);