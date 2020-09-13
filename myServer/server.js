
require('dotenv').config(); // remember to create .env !
const firebase = require('firebase-admin');
const serviceAccount = require('./fb-service-account.json');
let config = {
  apiKey: 'AIzaSyDPHPnY-OEUMQ_79r2eFmrSOPN5Ajc-7K0',
  authDomain: 'sacnnershop.firebaseapp.com',
  databaseURL: 'https://sacnnershop.firebaseio.com',
  projectId: 'sacnnershop',
  storageBucket: 'sacnnershop.appspot.com',
  messagingSenderId: '743639413044',
  appId: '1:743639413044:web:f7010c06eb14558a79b561',
  measurementId: 'G-0DCJTMZR0J'
};
firebase.credential.cert(serviceAccount);
firebase.initializeApp({
  credential: firebase.credential.applicationDefault(),
  databaseURL: config.databaseURL,
  serviceAccountId: 'firebase-adminsdk-853kh@sacnnershop.iam.gserviceaccount.com'
});

const express = require('express');

const app = express();
const path  = require('path');
let fs = require('fs');

// parse form data when received
app.use(express.urlencoded({ extended:false }));
app.use(express.json());
// build multiple CRUD interfaces:
app.use(express.static('client'));

app.get('/', (req, res) => {
  res.sendFile(path.resolve(__dirname, 'client', 'html', 'index.html'));
});

app.get('/login', (req, res) => {
  res.sendFile(path.resolve(__dirname, 'client', 'html', 'index.html'));
});

app.get('/signup', (req, res) => {
  res.sendFile(path.resolve(__dirname, 'client', 'html', 'signup.html'));
});


app.get('/worker', (req, res) => {
  res.sendFile(path.resolve(__dirname, 'client', 'html', 'workerPage.html'));
});

app.get('/Menu', (req, res) => {
  res.sendFile(path.resolve(__dirname, 'client', 'html', 'menu.html'));
});



app.get('/user-info', async (req, res) => {
  const user = await firebase.auth().getUser(sessionStorage.getItem('uid'));
  const root = firebase.database().ref('/');
  console.log(sessionStorage.getItem('firebase-token-id'));

  // const user = await firebase.auth().verifyIdToken('8mKr0oLjicbSZXy5QDkv9wYM4d62');
  res.send(user.toJSON());
});

app.post('/user-info', async (req, res) => { // Gets the user information from it's claims !
  await firebase.auth().getUser(req.body.uid).then((userRecord) => {
    // The claims can be accessed on the user record.
    console.log(userRecord.customClaims['premiumAccount']);
    console.log(userRecord.customClaims['displayName']);
    let user_name = userRecord.customClaims['displayName'];
    // console.log(res.status.toString());
    if (userRecord.customClaims['premiumAccount']) {
      console.log('is premium');
      return res.status(200).send({ userName:user_name, isPremium:true });  
    } else { return res.status(201).json({ userName:user_name, isPremium:false }); }
  });
  res.send();
});

// fetch('/add-worker', { method:'POST',body:JSON.stringify()})
app.post('/add-worker', async (req, res)=>{
  const additionalClaims = {
    premiumAccount: false,
    displayName: req.body.username
  };
  if ( req.body.email && req.body.password) {
   
    let user;
    try {
      user = await firebase.auth().createUser({
        email:req.body.email,
        password:req.body.password,
      }); 
      await firebase.auth().setCustomUserClaims(user.uid, additionalClaims);  // add the userName and premium to its claims !
    } catch (err) {
      console.log(err.message);
      return res.status(400).send({ error:err.message });
    }
    return res.status(200).send({ success:true });  
  }
  return res.status(400).end();
});
async function authorize(req, res, next) {
  const tokenId = req.headers['firebase-token-id'];
  const user = await firebase.auth().verifyIdToken(tokenId);
  req.user = user;
  req.user.claims =  (await firebase.auth().getUser(user.uid)).customClaims;
}

function onlyAdmin(req, res, next) {
  if ( req.user.customClaims.isAdmin ) {
    next();
  }
}
app.get('/sales', async (req, res)=>{
  // const tokenId = req.headers['firebase-token-id'];
  // const user = await firebase.auth().verifyIdToken(tokenId);
  
 
  // firebase.auth().setCustomUserClaims(user.uid, {
  //   isAdmin:true
  // });
  // (await firebase.auth().getUser(user.uid));
  // const dbref = firebase.database().ref(`/sales/${user.uid}`);
});

app.get('/forgotPass', (req, res) => {
  fs.readFile(__dirname + 'html/forgotPass.html', null, (error, data) => {
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



app.get('/timestamp', (request, response) => {
  response.send(`${Date.now()}`);
});
     
app.listen(process.env.PORT, ()=>{
  console.log('server is running http://localhost:3000');
});
// const express = require("express");
// const admin = require("firebase-admin");

// var serviceAccount = require("path/to/serviceAccountKey.json");

// admin.initializeApp({
//   credential: admin.credential.cert(serviceAccount),
//   databaseURL: "https://sacnnershop.firebaseio.com"
// });