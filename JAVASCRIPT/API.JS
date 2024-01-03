// API's IN JAVA SCRIPT-> 
    
// TO FETCH DATA FROM A URL WE USE THE TERM FECTH( ) AND IT COLLECT THE DATA FROM THE SERVER

// let URL=  "https://catfact.ninja/fact";
// let promise =fetch(URL);
// console.log(promise);

const URL="https://catfact.ninja/fact";

const getfacts=async()=>{
    console.log(" fething data from the api........");
    let response=await fetch(URL);
    console.log(response);
    // USING JSON
    let data=await response.json();
}

//UNDERSTANDING THE TERMS ->
// THESE ARE ALL FETCHING API TYPES OR FORMS OR METHODS
// 1-> AJAX -> asynchronous js and XML

// 2->JSON
// 3-> .json(); ,method -> java script object notation
// JSON()= RETURNS THE 2ND PROMISE AND FETECHES THE USEFUL DATA FROM THE API URL
 