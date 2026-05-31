chmod u+x myshell1
./myshell1

date > test
cat test
who > test
cat test
ls -al | sort > test
cat test

wc < test
wc # 표준 입력을 받아서 출력, ctrl + d 로 종료
wc << EOF # EOF로 종료
cat << EOF 
EOF #  cat을 통해 입력을 받고 출력, EOF로 종료
 
expr 1 + 5 
expr 1+5 
expr 5 * 2 # *를 곱하기 연산자가 아닌 모든 연산자를 뜻하는 와일드카드로 인식 
expr 5 \* 2

bc # Basic Calculator, quit로 종료
bc << EOF # EOF로 종료