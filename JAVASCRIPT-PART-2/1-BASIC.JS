

// 2

console.log("vansh");

//--------------------------------------------------------------------------------------------------------------

//3

// VARIABLES AND CONSTANT->

const accountId = 144553
let accountEmail = "hitesh@google.com"
var accountPassword = "12345"
accountCity = "Jaipur"
let accountState;

// accountId = 2 // not allowed


accountEmail = "hc@hc.com"
accountPassword = "21212121"
accountCity = "Bengaluru"

console.log(accountId);

/*
Prefer not to use var
because of issue in block scope and functional scope
*/


console.table([accountId, accountEmail, accountPassword, accountCity, accountState])


//-----------------------------------------------------------------------------------------------------------------

//4

// DATA TYPES AND ECMA SCRIPT->

"use strict"; // treat all JS code as newer version

// alert( 3 + 3) // we are using nodejs, not browser

console.log(3 
    +
     3) // code readability should be high

console.log("Hitesh")


let name = "hitesh"
let age = 18
let isLoggedIn = false
let state;

// number => 2 to power 53
// bigint
// string => ""
// boolean => true/false
// null => standalone value
// undefined => 
// symbol => unique


// object

console.log(typeof undefined); // undefined
console.log(typeof null); // object

//-----------------------------------------------------------------------------------------------------------------

//5

// DATA TYPES COVERSION ->

let score = "hitesh"

//console.log(typeof score);
//console.log(typeof(score));

let valueInNumber = Number(score)
//console.log(typeof valueInNumber);
//console.log(valueInNumber);


// "33" => 33
// "33abc" => NaN
//  true => 1; false => 0

//let isLoggedIn = "hitesh"

let booleanIsLoggedIn = Boolean(isLoggedIn)
//  console.log(booleanIsLoggedIn);

// 1 => true; 0 => false
// "" => false
// "hitesh" => true

let someNumber = 33

let stringNumber = String(someNumber)
// console.log(stringNumber);
// console.log(typeof stringNumber);

// *********************** Operations ***********************

let value = 3
let negValue = -value
 console.log(negValue);


console.log(2+2);

console.log(2-2);

console.log(2*2);

 console.log(2**3);

 console.log(2/3);

 console.log(2%3);

let str1 = "hello"
let str2 = " hitesh"

let str3 = str1 + str2

console.log(str3);


 console.log("1" + 2);

 console.log(1 + "2");

 console.log("1" + 2 + 2);
// console.log(1 + 2 + "2");


console.log( (3 + 4) * 5 % 3);


 console.log(+true);

 console.log(+"");

let num1, num2, num3

num1 = num2 = num3 = 2 + 2

let gameCounter = 100
++gameCounter;
console.log(gameCounter);

// link to study
// https://tc39.es/ecma262/multipage/abstract-operations.html#sec-type-conversion

//------------------------------------------------------------------------------------------------------------------

//COMPARISONS ->
 console.log(2 > 1);
 console.log(2 >= 1);
 console.log(2 < 1);
 console.log(2 == 1);
 console.log(2 != 1);


 console.log("2" > 1);
 console.log("02" > 1);

console.log(null > 0);
console.log(null == 0);
console.log(null >= 0);

console.log(undefined == 0);
console.log(undefined > 0);
console.log(undefined < 0);

// === 

console.log("2" === 2);

//-----------------------------------------------------------------------------------------------------------------

// more on data types

//  Primitive

//  7 types : String, Number, Boolearn, null, undefined, Symbol, BigInt

const myscore = 100
const scoreValue = 100.3

const LoggedIn = false
const outsideTemp = null
let userEmail;

const id = Symbol('123')
const anotherId = Symbol('123')

console.log(id === anotherId);

// const bigNumber = 3456543576654356754n



// Reference (Non primitive)

// Array, Objects, Functions

const heros = ["shaktiman", "naagraj", "doga"];
let myObj = {
    name: "hitesh",
    age: 22,
}

const myFunction = function(){
    console.log("Hello world");
}

console.log(typeof anotherId);

// https://262.ecma-international.org/5.1/#sec-11.4.3



//*************************** stack and heap memory in java script*********************** */

// stack and heap memory ->>
