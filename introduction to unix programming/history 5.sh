ps -l 
ps aux | egrep "init|bash"
# ps의 실행코드가 어떻게 bash process에 overwrite 되는지 확인
# fork를 호출하여 복사됨

top 
# NI 로 나오는 nice 값 확인
# nice 값이 낮을수록 우선순위가 높음

nice -n 15 ps
# nice 값을 15로 설정하여 ps를 실행

mount 
mount -t [타입] [무엇을(장치명)] [어디에(마운트 포인트)]
umount

df
df -h (Human-readable)
# Mounted on 아래에 값을 확인 
# 어느 루트에 마운트 되어있는지를 볼 수 있다

du ( disk usage )
du -sh (Summarize + Human-readable)
du | sort | more
du -sh * | sort -hr (Reverse)

sort ( ctrl + d 로 종료 )
sort file1 ( 알파벳 순 정렬 )
sort file2 ( 숫자순 정렬 )
# 1, 100 ,2 20 
sort -n ( Numeric,수학적 정렬 )
# 1, 2, 10, 20 
sort -t ':' -k 3 -n /etc/passwd | more
# -t ':' : 콜론을 기준으로 정렬
# -k 3 : 3번째 필드를 기준으로 정렬
# -n : 숫자순 정렬

grep t file1
grep -n t file1 ( Number, 파일에서 t를 포함한 줄 번호와 함께 출력 )
grep -v t file1 ( inVert, 파일에서 t를 제외한 나머지 출력 )
grep -e t -e f file1 ( Expression, t 또는 f를 포함한 줄 출력 )
    = grep '[tf]' file1
grep -v "^$" file1 ( Empty line 제외 )
# ^ = start of line
# $ = end of line
# ^$ = empty line
grep -R ".*two" . ( Recursive, 현재 디렉토리에서 two를 포함한 파일을 출력 )

grep, egrep ( grep -E ), fgrep ( grep -F )의 차이
    grep "." file3 ( . = any character )
    egrep "." file3
    fgrep "." file3 ( 파일에서 .을 포함한 문장만 출력 )

bzip2
gzip 

bzcat 

bunzip2 


-------------------------------------------------------
test=testing (변수 생성)

env (environment variable 확인, env는 전역변수)

echo $test (변수 출력)

test='testing a b c' (변수 값 변경)

bash (자식 쉘 생성 및 입장)

ctrl + d (쉘 종료)

export test (만들어져있는 변수를 전역변수로 설정)

unset test (변수 삭제)

test=$test:. (기존 test 변수에 :. 값 추가)



