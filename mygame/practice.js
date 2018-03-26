

myDiv = document.getElementById('mydiv');
console.log(mydiv);

function mousePressed(someInfo){
    console.log("You pressed the mouse!");
    console.log(someInfo.clientX +" ," + someInfo.clientY);
}

myDiv.addEventListener('mousedown',mousePressed);

var bird = {
    x : 10,
    y : 30,
    color : "green",
    eggs : [1,2,3,4,5],
    
    fly: function(){
        console.log("Bird is flying"); 
        console.log(this.x);
        console.log(this.color);
    }  
};
console.log(bird.x); 




