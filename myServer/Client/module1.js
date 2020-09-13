// let http = require('http');
// let https = require('https');
let fs = require('fs');
const express = require('express');
const app = express();
// let app = require('./logger.js');
// const fs = require('fs');
// const options = {
//   key: fs.readFileSync('key.pem'),
//   cert: fs.readFileSync('cert.pem')
// };
app.use(express.static(__dirname));
app.get('/', (req, res) => {
  fs.readFile(__dirname + '/login.html', null, function (error, data) {
    if (error) {
      res.writeHead(404);
      // eslint-disable-next-line no-undef
      res.write('Whoops! File not found!');
    } else {
      res.write(data);
    }
    res.end();
  });
});

app.get('/signup', (req, res) => {
  fs.readFile(__dirname + '/signup.html', null, function (error, data) {
    if (error) {
      res.writeHead(404);
      // eslint-disable-next-line no-undef
      res.write('Whoops! File not found!');
    } else {
      res.write(data);
    }
    res.end();
  });
});

app.get('/forgotPass', (req, res) => {
  fs.readFile(__dirname + '/forgotPass.html', null, function (error, data) {
    if (error) {
      res.writeHead(404);
      // eslint-disable-next-line no-undef
      res.write('Whoops! File not found!');
    } else {
      res.write(data);
    }
    res.end();
  });
});

app.post('/workerPage.html', (req, res) => {
  fs.readFile(__dirname + '/workerPage.html', null, function (error, data) {
    if (error) {
      res.writeHead(404);
      // eslint-disable-next-line no-undef
      res.write('Whoops! File not found!');
    } else {
      res.write(data);
      
    }
    res.end();
  });
});

app.listen(5000);
// https.createServer(options, app.handleRequest).listen(3000);
// http.createServer(app.handleRequest).listen(5000);