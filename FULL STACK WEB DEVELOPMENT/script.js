const btn=document.querySelector('#increment');
let counter=0

function incrementbtn(){
  const counterel=document.getElementById('counter');
  counter++;
  counterel.innerText=counter;

}
btn.addEventListener('click', incrementbtn);
