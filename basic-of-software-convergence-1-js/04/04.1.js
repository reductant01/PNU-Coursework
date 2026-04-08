// 1. DOM 생성이 되면 img, button 요소를 가져오기
// 2. button 클릭이 되는 경우를 찾아야 함
// 3. img src 속성을 변경
//     - 랜덤수를 발생 -> 해당하는 랜덤수의 이미지를 가져오기

// 1. DOM 생성이 되면 img, button 요소를 가져오기
document.addEventListener("DOMContentLoaded", () => {
  //img, button 요소를 가져오기
  // const img = document.querySelector("#divContent > p > img"); 아래와 같음
  const img = document.querySelector("#divContent img");
  const bt = document.querySelector("#divContent button");

  // 2. button 클릭이 되는 경우를 찾아야 함
  bt.addEventListener("click", () => {
    //랜덤수를 발생
    const n = Math.floor(Math.random() * 6) + 1;
    //console.log(n); 아래와 같음 (``안의 문자는 변수로 취급을 안하기 때문에 ${}로 변수임을 나타냄)
    console.log(`${n}.png`);
    
    // 3. img src 속성을 변경
    img.setAttribute("src", `./img/${n}.png`);
  });
});