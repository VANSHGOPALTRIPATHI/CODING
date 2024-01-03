// Events are fired to notify code of "interesting changes" that may affect code execution. These can arise from user interactions such as using a mouse or resizing a window, changes in the state of the underlying environment (e.g. low battery or media events from the operating system), and other causes.

// Each event is represented by an object that is based on the Event interface, and may have additional custom fields and/or functions to provide information about what happened. The documentation for every event has a table (near the top) that includes a link to the associated event interface, and other relevant information. A full list of the different event types is given in Event > Interfaces based on Event.

// let button1 = document.querySelector("#btn1");
// button1.onclick = () => {
//   alert("hey man dont click me na ");
// };
//--------------------------------------------------------------------------------------

// for defining event handler we can give a handler inside parenthesis>

let button3 = document.querySelector(".box");
button3.onmouseover = (eventhandler) => {
  // name can be anything variable
  console.log(eventhandler);
  console.log(eventhandler.type);
  console.log(eventhandler.clientX, eventhandler.clientY);
};

//-----------------------------------------------------------------------------------------

// EVENT LSITENER->

// by eventlistener we can add multiple events to single element->
let button2 = document.querySelector(".button2");
button2.addEventListener("click", (evt) => {
  console.log("hey guys why you clicked me ");
});
button2.addEventListener("click", () => {
  console.log("hey guys why you clicked me again beta ");
});
const handler2 = () => {
  console.log("hello bacchu"); // by making this as a call back we can add and remove the function };
  button2.addEventListener("click", handler2); // added
  //removing
  button2.removeEventListener("click", handler2);
};
//------------------------------------------------------------------------------
//creating a toggle button which changes the screen to light and dark mode on each click

let togglebtn = document.querySelector("#togglebutton");

let mode = "dark";
togglebtn.addEventListener("click", () => {
  if (mode === "dark") {
    mode = "light";
    document.querySelector("body").style.backgroundColor = "white";
  } 
  else {
    mode = "dark";
    document.querySelector("body").style.backgroundColor = "black";
  }
});
//-----------------------------------------------------------------------------------
