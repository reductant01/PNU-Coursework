gcc -M unix3-1.c (-Make, 의존성 확인) # 시스템 헤더를 포함하여 어떤 파일들에 의존하고 있는지 터미널에 출력
gcc -MM unix3-1.c (-Make, 의존성 확인) # 내가 만든 파일 간의 의존성만 확인


# preprocess(전처리) -> compile(문법 check) -> assemble(기계어로 변환) -> linking(함수 찾기)

gcc -E -H unix3-1.c (-Expand -Header) # 1단게 전처리 확인용
gcc -S unix3-1.c (-Assembly, assembly 파일 생성) # 2단게 컴파일 확인용    
gcc -c unix3-1.c (-Compile, object file 생성) # 3단게 어셈블 확인용
gcc unix3-1.c -o unix3-1 (실행파일 생성, 실행파일을 a.out이 아닌 unix3-1로 생성) # 4단게 최종 완성
gcc unix3-1.c -o unix3-1 -I[헤더폴더경로] -l[라이브러리이름] (-I는 include 추가, -l은 library 추가) 


