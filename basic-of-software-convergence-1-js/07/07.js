document.addEventListener("DOMContentLoaded", () => {
  //DOM 요소 가져오기
  const txt1 = document.querySelector("#txt1");  
  const txt2 = document.querySelector("#txt2");

  const bt1 = document.querySelector("#bt1");
  const bt2 = document.querySelector("#bt2");

  //회문 확인
  bt1.addEventListener("click", (e)=>{
    e.preventDefault();


    if (txt1.value == "") {
      alert("글자를 입력하세요.");
      txt1.focus();
      return;
    }

    console.log(txt1.value); //문자열 내용 가져오기
    console.log(txt1.value.length); //문자열 글자 길이 확인
    console.log(txt1.value[1]); //문자열 접근 (2번째 글자)
    console.log(txt1.value.charAt(0)); //문자열 첫번째 글자 추출

    //문자열을 한글자씩 추출
    for(let c of txt1.value) {
      console.log(c);
    }

    //문자열 변경 => 공백제거후 사용
    let txt = txt1.value.replaceAll(" ", "");

    //문자열을 뒤집는 첫번째 방법 : 반복문
    let tm = "";
    for(let i=txt.length -1; i >= 0; i--) {
      tm = tm + txt1.value[i];
    }
    console.log(tm);

    //문자열을 뒤집는 두번째 방법 : 함수로
    tm = txt.split("").reverse().join(""); 
    //split은 문자열을 ""안의 문자를 기준으로 쪼개서 배열로 만든다.(""안이 비어있으므로 한글자씩 쪼개는 역할을 함) 
    //reverse는 이를 뒤집는 함수이고 join은 배열 사이사이에 ""안의 문자를 포함하여 하나의 문자열로 만든다 (""안이 비어있으므로 단순히 하나의 문자열이 된다)
    console.log(tm);

    //회문확인
    if ( txt1.value == tm ) {
      txt2.value = "회문입니다"
    }
    else {
      txt2.value = "회문이 아닙니다"
    }
  });

  //숫자 합계
  bt2.addEventListener("click", (e)=>{
    e.preventDefault();

    if (txt1.value == "") {
      alert("글자를 입력하세요.");
      txt1.focus();
      return;
    }

    let sum = 0;
    for(let c of txt1.value) {
      if(!isNaN(c)) { //숫자인지 확인 : 숫자이면 isNaN() 결과는 false
        sum = sum + parseInt(c);
      }
    }

    txt2.value = sum;
  });
});