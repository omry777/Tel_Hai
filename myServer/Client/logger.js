let url = require('url');
let fs = require('fs');

function renderHTML(path, response) {
  fs.readFile(path, null, function (error, data) {
    if (error) {
      response.writeHead(404);
      // eslint-disable-next-line no-undef
      respone.write('Whoops! File not found!');
    } else {
      response.write(data);
    }
    response.end();
  });
}

module.exports = {
  handleRequest: function (request, response) {
    response.writeHead(200, {
      'Content-Type': 'html'
    });
    let path = url.parse(request.url).pathname;
    switch (path) {
      case '/':
        renderHTML('./Client/login.html', response);
        break;
      case '/login':
        renderHTML('./Client/login.html', response);
        break;  
      case '/signup':
        renderHTML('./Client/signup.html', response);
        break;
      case '/forgotPass':
        renderHTML('./Client/forgotPass.html', response);
        break;  
      default:
        response.writeHead(404);
        response.write('Route not defined');
        response.end();
    }
  }
};