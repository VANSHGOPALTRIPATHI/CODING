// CALL BACK DATA

function getdata(id, getnextdata) {
  setTimeout(() => {
    console.log("data", id);
    if (getnextdata) {
      getnextdata();
    }
  }, 2000);
  // 2000 is 2s delay in milisecond
}
// function using lot of callbacks with 2s delay =>
// AND THIS TYPE OF CODE WHICH IS COMPLEXT AND NT EASY TO UNDERSTAND IS KNOWN AS
//"CALL-BACK HELL"=>

getdata(1, () => {
  getdata(2, () => {
    getdata(3, () => {
      getdata(4, () => {
        getdata(5);
      });
    });
  });
});
//-------------------------------------------------------------------------------------------------------------

                            //                  PROMISES


// promises=> to resolve the call back hell problem we have the term promises which helps in resoluing the call back hell problem->

// The Promise object represents the eventual completion (or failure) of an asynchronous operation and its resulting value.
// A Promise is a proxy for a value not necessarily known when the promise is created. It allows you to associate handlers with an asynchronous action's eventual success value or failure reason. This lets asynchronous methods return values like synchronous methods: instead of immediately returning the final value, the asynchronous method returns a promise to supply the value at some point in the future.

// A Promise is in one of these states:

// pending: initial state, neither fulfilled nor rejected.
// fulfilled: meaning that the operation was completed successfully.
// rejected: meaning that the operation failed.
// The eventual state of a pending promise can either be fulfilled with a value or rejected with a reason (error). When either of these options occur, the associated handlers queued up by a promise's then method are called. If the promise has already been fulfilled or rejected when a corresponding handler is attached, the handler will be called, so there is no race condition between an asynchronous operation completing and its handlers being attached.

// A promise is said to be settled if it is either fulfilled or rejected, but not pending.

let promise=new promise(( resolve,reject)=>{
    console.log("hey i am a promise ");  // curently here u+it is in pending state 
    resolve("success");  // by writing resolve promise is fullfilled/completed
    reject("error aagaya bhai nahi hopayega sorry");  // by this eror occured
});

// Promise.prototype.then()


// The then() method of Promise instances takes up to two arguments: callback functions for the fulfilled and rejected cases of the Promise. It immediately returns an equivalent Promise object, allowing you to chain calls to other promise methods.
const promise1 = new Promise((resolve, reject) => {
    resolve('Success!');
  });
  
  promise1.then((value) => {
    console.log(value);
    // Expected output: "Success!"
  });

//   Promise.prototype.catch()


// The catch() method of Promise instances schedules a function to be called when the promise is rejected. It immediately returns an equivalent Promise object, allowing you to chain calls to other promise methods. It is a shortcut for Promise.prototype.then(undefined, onRejected).

const promise2 = new Promise((resolve, reject) => {
    throw new Error('Uh-oh!');
  });
  
  promise1.catch((error) => {
    console.error(error);
  });
  // Expected output: Error: Uh-oh!


  //             ASYNC-AWAIT=>

//   The async function declaration creates a binding of a new async function to a given name. The await keyword is permitted within the function body, enabling asynchronous, promise-based behavior to be written in a cleaner style and avoiding the need to explicitly configure promise chains.

// You can also define async functions using the async function expression.

// SYNTAX=>

async function name(param0) {
  statements
}
async function name(param0, param1) {
  statements
}
async function name(param0, param1, /* …, */ paramN) {
  statements
}


// The await operator is used to wait for a Promise and get its fulfillment value. It can only be used inside an async function or at the top level of a module.
  


function resolveAfter2Seconds(x) {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve(x);
    }, 2000);
  });
}

async function f1() {
  const x = await resolveAfter2Seconds(10);
  console.log(x); // 10
}

f1();
