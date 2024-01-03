// // to acess the elements in html from java script ->
// // we can give a id or  a class to various tags->
// // by id ->
// let para=document.getElementById("para");
// console.dir(para);
// console.log(para);
// // by class->
// let heading =document.getElementsByClassName("headingclass");
// console.dir(heading);
// console.log(heading);


// //  third we can directly do it by the tag name directly

// // best way to acess ->     QUERY SELECTOR

// let firstEL=ducument.querySelector("heading");  
// // it will give first tag from that tag
// console.dir(firstEL);

// // for all ->
// let allEL=ducument.querySelectorAll("p");  
// // it will give all tag from that tag
// console.dir(allEL);

// PROPERTIES OF DOM->
//1=>TAG NAME-> return tag name for the element node 
//2=>INNER TEXT=return the text content of the element and all its children 
//3=>INNER HTML=>return the plane text with the html content in the element
//4=>TEXT CONTENT=>return textual contet even for hidden element
// WE CAN USE THESE AS FOR EX->heading.innertext,div.innerhtml and etc....


// DOM MANUPULATIONS ->

/*
ATTRIBUTES->
 we have two functions -> 1-> getattribute(),, 2-> setattribute();

 //  INSERT ELEMENT=>
 1->node.append(elemenet)   =>  add inside at the end 
 2->node.prepend(element)   =>  add inside at the start
 3->node.before(element)    =>  add outside before the node 
 4->node.after(element)     =>  add outside after the node 
 */

// we can acees any element and tag in js by query selector->
let paras=document.querySelectorAll("p");  // and by accesing can do anything 
console.log(paras.innerHTML="hello bete");

let headinggood=document.createElement("h5");
headinggood.innerHTML="hey i am the new heading";
document.querySelector("body").append(headinggood);
console.log(headinggood);