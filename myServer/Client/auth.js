let data;

firebase.auth().onAuthStateChanged( (user) => {
  let isPremium = false;
  if (user) {
    // User is signed in.
    document.getElementById('user_div').style.display = 'block';
    document.getElementById('login_div').style.display = 'none';
      
    console.log('new user logged in');
    let uid = user.uid;
    sessionStorage.setItem('uid', user.uid);
    let fetchData = {
      method: 'POST',
      headers: {
        'Accept': 'application/json',
        'Content-Type': 'application/json'
      },
      body: JSON.stringify({
        uid: uid
      })
    };
      // eslint-disable-next-line no-inner-declarations
    let userName;
    data = callFunc(fetchData); // gets information about the user, function at line 49
    data.then(async (info) => {
      console.log(info.x['userName']); 
      userName = info.x['userName'];
      sessionStorage.setItem('isPremuim', info.y);
      sessionStorage.setItem('userName', userName);
      if (info.y === false) { document.getElementById('signUp').style.visibility = 'hidden'; } else {
        document.getElementById('signUp').style.visibility = 'visible';
      }
      // console.log(user);
      if (userName) {
        document.getElementById('user_para').innerHTML = 'Welcome User : ' + userName;
      }
      else{
        document.getElementById('user_para').innerHTML = 'Welcome User : ' + sessionStorage.getItem('user_mail');
      }
    });
  } else {
    // No user is signed in.
    document.getElementById('user_div').style.display = 'none';
    document.getElementById('login_div').style.display = 'block';
  }
});

async function callFunc(fetchData) {   // function that call the server in order  to receive information about the user.
  let res = await fetch('/user-info', fetchData);
  data = {};
  console.log( res.status );
  data.x = JSON.parse(await res.text()); 
  // data += JSON.parse({ 'isPremium':'true' });
  console.log(data.x['userName']);
  console.log("is this user premium? " + data.x['isPremium']);
  if (res.status === 200) {
    data.y = true; // data.y data.x holds the premium situation.
    console.log('this is a premium account');
  } else { console.log('this is not a premium account!'); data.y = false; }

  return data;
}

function login() {
  let userEmail = document.getElementById('email_field').value;
  let userPass = document.getElementById('password_field').value;

  let user = firebase.auth().signInWithEmailAndPassword(userEmail, userPass)
    .then(async (creds) => {
      sessionStorage.setItem('firebase-id-token', await creds.getIdToken());
      sessionStorage.setItem('user_mail', userEmail);
    })
    .catch((error) => {
    // Handle Errors here.
      let errorCode = error.code;
      let errorMessage = error.message;
      // eslint-disable-next-line no-alert
      window.alert('Error : ' + errorMessage + ':' + errorCode);

    // ...
    });

}


function logout() {
  firebase.auth().signOut();
}
