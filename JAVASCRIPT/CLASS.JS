// CLASS AND OBJECTS IN JAVA SCRIPT->>>


// OBJECT CREATION=>
const student={
    fullname:"vansh dada",
    marks:98,
    printmarks:function(){
        console.log("marks is equal to->",this.marks);
    },

};

//PROTOTYPES IN JAVA SCRIPT->
// WHEN EVER WE CRAETE AN OBJECT IN JAVA SCRIPT THERE IS A PROPERTY KNOWN AS PROTOTYPE AND IT ITSELT IF A OBJECT

// IF WE WANT TO INHERIT SOME DEFAULT PRPPERTIES OF ANY ONE OBJECT TO ANOTHER THEN WE CAN SET A PROTOTYPEUSING __PROTO__ METHOD ;

const boss={
    eachslary:50000,
    calsalary(){
        console.log("i have best employess ans each have the salary of ",this.eachslary);
    },
};
// if new boss has also has the same property of above boss->

const newboss={
    workingemployee:500,

};
//  and rest same property is of old boss->
 newboss.__proto__=boss;
// by this in new boss we can acess the oler boss propeties;


//  CLASSES =>

// Classes are a template for creating objects. They encapsulate data with code to work on that data. Classes in JS are built on prototypes but also have some syntax and semantics that are unique to classes.
// Declaration
class Rectangle {
    // constructor automatically invokes

    constructor(height, width) {
      this.height = height;
      this.width = width;
    }
}

let newrectangle=new Rectangle();  // class object creation
class parent{
    hello(){
        console.log("hello");
    }

}
  // inheitence->
class child extends parent{}
 
let child2=new child();
child.hello();

// errror handling=>
// try...catch
// The try...catch statement is comprised of a try block and either a catch block, a finally block, or both. The code in the try block is executed first, and if it throws an exception, the code in the catch block will be executed. The code in the finally block will always be executed before control flow exits the entire construct.

try {
    nonExistentFunction();
  } catch (error) {
    console.error(error);
    // Expected output: ReferenceError: nonExistentFunction is not defined
    // (Note: the exact output may be browser-dependent)
  }
  
    
