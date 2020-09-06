var num = 1;
var json;
var score = 0;
var wasAsked = [-1,-1,-1,-1,-1,-1,-1,-1,-1,-1]
var questions;

function readJSONFile(file) {
    json = $.getJSON("../Databases/Questions/" +file +".json");
}

function changeQuestion(ansNum) {
    questions = JSON.parse(json.responseText);
    
    if (ansNum == 0){
        console.log("Right Answer!");
        document.getElementById("Score").innerHTML = "Score:" +(score+=50);
    }
    if (num > questions.length)
        return;
    
    wasAsked[num] = getNewQuestion();
    var qstn = questions[wasAsked[num]];
    document.getElementById("questionText").innerText = qstn["question"]; //change the question text
    var btn;
    var rand = Math.random()*4;
    for (let index = 0; index < qstn["answers"].length; index++) {  //change the buttons text
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
    console.log(temp);
    return temp;
}