document.addEventListener("DOMContentLoaded", ()=>{
  // 요소 가져오기
  const lotto = document.querySelector("#lotto");
  const bt = document.querySelector(".bt");

  // 로또 번호 저장
  let arr = [];

  bt.addEventListener("click", ()=>{
    // 배열 초기화
    arr.length = 0;
    // 로또 번호 생성
    while(arr.length < 7) {
      const n = Math.floor(Math.random() * 45) + 1;
      
      if(!arr.includes(n)) arr.push(n); 
    }

    // 로또 번호 정렬
    arr.sort((a, b)=>a-b); // 오름차순 정렬
    console.log(arr);
    
    let tm = arr.map(item => `<span class="sp${Math.floor(item / 10)}">
                                ${item}
                              </span>`);

    // 배열의 6번째 추가                          
    tm.splice(6,0, `<span id="spplus">+</span>`);  
    // splice(시작위치, 삭제, 추가할 내용)                        

    lotto.innerHTML = tm.join("");
  });
});