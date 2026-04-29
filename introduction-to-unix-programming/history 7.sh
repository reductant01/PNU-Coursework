gcc -c unix3-1.c (Compile)
gcc -E -H unix3-1.c (preprocess, header file 확인)
gcc -M unix3-1.c (makefile 생성)
gcc -S unix3-1.c (assemble 파일 생성)
gcc -c unix3-1.c (compile, object file 생성)
gcc unix3-1.c -o unix3-1 -I[헤더폴더경로] -l[라이브러리이름] (실행파일을 a.out이 아닌 unix3-1로 생성, -I는 include 추가, -l은 library 추가)

preprocess(전처리) -> compile(문법 check) -> assemble(기계어로 변환) -> linking(함수 찾기)
