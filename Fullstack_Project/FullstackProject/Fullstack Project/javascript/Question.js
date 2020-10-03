var num = 1;
var json;
var score = 0;
var wasAsked = [-1,-1,-1,-1,-1,-1,-1,-1,-1,-1]
var questions;

function readJSONFile() {
    json = $.getJSON("../Databases/Questions/" +sessionStorage.value +".json", function(){
        questions = JSON.parse(json.responseText);
    });
    changeQuestion(1);
}

function changeQuestion(ansNum) {
    if (ansNum == 0){
        console.log("Right Answer!");
        document.getElementById("Score").innerHTML = "Score:" +(score+=50);
    }
    if (num > questions.length)
    {
        resetScreen();
        return;
    }
    wasAsked[num] = getNewQuestion();
    var qstn = questions[wasAsked[num]];        //json["Highscores"]["Yair"]
    document.getElementById("questionText").innerText = qstn["question"]; //change the question text
    var btn;
    var rand = Math.random()*4;
    for (let index = 0; index < 4; index++) {  //change the buttons text
        btn = document.getElementById("ans" +Math.round(rand+index)%4); //randomise answers placement
        btn.innerText  = qstn["answers"][index]["txt"];;
        btn.value = index;
    }

    document.getElementById("questionNum").innerHTML = "#" + num++; //change question number
}

function getNewQuestion(){
    var temp;
    do{
        temp = Math.round(Math.random()*(questions.length-0.51));
    } while (num <= questions.length && wasAsked.includes(temp));

    return temp;
}

function resetScreen(){
    var btn;
    for (let index = 0; index < 4; index++) {  //change the buttons text
        btn = document.getElementById("ans" +index); //randomise answers placement
        btn.innerText  = "Start";
        btn.value = "start";
    }
    document.getElementById("questionNum").innerHTML = "";
    document.getElementById("questionText").innerText = "Press any Button to start!";
    for (let i = 0; i < num; i++) {
        wasAsked[i] = -1;
    }
    num=1;

}