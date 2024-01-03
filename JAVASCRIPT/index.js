// alert("hello world");
// let x=50; let can be changed 
// alert(x);
// const x=100;  // const can not be changed
// console.log(x);

// VARIABLES->

// let a= 67; // a contains 67   // let can be changed but can not be re declare 
// a=90;
// console.log(a);
// console.log("hello world");
// const author=98;
// console.log(author);  // constant can not be changed 
// a=100;
// console.log(a);

// ARRAYS IN JAVA SCRIPT->
let arr =[1,2,3,4,5];    // arrays are mutable can be changed 
arr[0]=56;
console.log(arr);
console.log(arr.length);

// METHODS OF ARRYS ->>
// by this array will be converted to the string
console.log(arr.toString());   
//  conerts commas into the any thing written inside join ;
console.log(arr.join (" mere aaage h "));  
// pop method->pops the last element
console.log(arr.pop()); 
console.log(arr);
//there are some more methods ->shift,unshift,delete,concat,sort ,splice->>

// objects creation--
const profile={
    username:"vansh",
    followers:500,
    likes:100,
    isfollowed:true,

};
console.log(profile);
profile["followers"]=500+100;
console.log(profile["followers"]);
//---------------------------------------------------------------------------------------------------------------

// FOR LOOPS->
// 1-> SIMPLE FOR LOOP
//2-> FOR IN
// 3->FOR OF 
// SEE HARRY NOTES ON MY DESKTOP FOR MORE KNOWLEDGE->
//-------------------------------------------------------------------------------------------------------------------
// STRINGS ->>>

// Tempelate literals 
//tempelate liteearls are used to embed objecs by using ${};
let specialstring = `this is my  tempelate string literals ${1+2+3}`;
console.log(specialstring);  // that is why it is diff from normal string 


// STRINGS METHODS AND FUNCTIONS ->
//1->BUILT IN FUNCTIONS->>
//->str.toUpperCase();
//->str.toLowerCase();
//->str.trim() removes whitespaces

// for more checkout MDN website
//---------------------------------------------------------------------------------------------------------------

//->>.>>>>>>>>

// FUNCTIONS=>

// higher order function-> a function which can take fn as a parameter and can return the function
// is known as higher 
//order function

//for ex->
 arr=[1,3,4,5,5,5,5,5,5];
arr.forEach((val)=>{   // for each used for arays
    console.log(val*val);
})


//  MAP METHOD=>
let newarr=arr.map((val)=>{  // we can create new array by using map method
    return val;
})
console.log(newarr);


// filter method->
 let ARR=[34,56,43,56,54];
 let evenarr=ARR.filter((val)=>{
    return val%2===0;
 })
 console.log(evenarr);

 // REDUCE =>
 let n=prompt("enter a number :");
 let brr=[];
 for ( let i=1;i<=n;i++){
    brr[i-1]=i;
 }
 console.log(brr);
 let sum=brr.reduce((res,curr)=>{
    return res+curr;
 })
 console.log(sum);