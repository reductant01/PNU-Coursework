# MakeFileTest
재컴파일 되는 문제 발생
    - object 만드는 부분과 object를 이용해서 실행파일을 만드는 부분 구분

gcc -g ( debug )
gcc -Wall ( warning 메시지 출력 )
gcc -O0 ( optimization, 실행 속도 최적화 안함 )
gcc -O2 ( optimization, 실행 속도 최적화 2단계 )
gcc -O3 ( optimization, 실행 속도 최적화 3단계 )

$@ = target file name
$^ = all dependencies
$< = first dependency