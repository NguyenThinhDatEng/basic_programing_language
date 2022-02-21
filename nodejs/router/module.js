const fs = require('fs');

function readHTML(path, res) {
    res.writeHead(200, {
        'Content-Type' : 'text/html'
    })
    fs.ReadStream(path).pipe(res);
}

var module01 = function(req, res) {
    console.log("Sever is running...");
    var path = req.url
    console.log(req.url)
    switch(path) {
        case "/author":
            readHTML(__dirname + '\\author.html', res)
            break
        case "/author/university":
            readHTML(__dirname + "\\university.html", res)
            break
        case "/author/university/class":
            readHTML(__dirname + "\\class.html", res)
            break;
        
        default:
            res.writeHead(400, {
                'Content-Type' : 'text/html'
            })
            fs.ReadStream(__dirname + '\\404.html').pipe(res);
            break
    }
}

module.exports.module01 = module01;

