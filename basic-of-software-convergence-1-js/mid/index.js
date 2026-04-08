document.addEventListener("DOMContentLoaded", ()=>{
  const imgSec = document.querySelector("#imgSec img");
  const wSec = document.querySelector("#wSec h2");
  const txt1 = document.querySelector("[type='text']");
  const bt = document.querySelectorAll("button");
  //const inSec = document.querySelectorAll("#inSec");
  const sec3 = document.querySelector("#sec3");
  //const sec2 = document.querySelectorAll("#sec2");
  // const txt1 = document.querySelector("[type='text']");

  
  const obj = ["사과", "바나나", "당근", "포도"];

  // imgSec.style.display = "none";
  // wSec.style.display = "none";
  // inSec.style.display = "none";
  // sec3.style.display = "none";

  bt[1].addEventListener("click", ()=>{
    imgSec.style.display = ""; 
    wSec.style.display = "";

    const n = Math.floor(Math.random() * 4) + 1;
    console.log(n);
    imgSec.setAttribute("src", `./img/${n}.png`);
    
    wSec.textContent = obj[n-1];
  });

  bt[2].addEventListener("click", ()=>{
    sec3.style.display = "";
    

  });
});