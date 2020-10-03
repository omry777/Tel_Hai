var json;

function readJSONFiles() {
    var temp;
    json = $.getJSON("../Questions/", function () {
        for (let i = 0; i < json.responseJSON.length; i++) {
            temp = json.responseJSON[i];
            temp = temp.substr(0, temp.indexOf(".json"));
            console.log(temp);
            document.getElementById('container').innerHTML += (<button class="cataBtn" type="button" id="cataBtn'+i +'" onclick="updateCata(' +temp +')">' + temp + '</button></a>');
        }
    })
}

function updateCata(category){
    var temp = String(category);
    temp = temp.substr(temp.indexOf(" ")+1);
    temp = temp.substr(0, temp.indexOf("()"));
    sessionStorage.value = temp;
}
