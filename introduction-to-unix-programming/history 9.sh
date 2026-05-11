ldconfig -v 

ar rcs libadd.a add.o (archiver replace create sort)

gcc main.o -L. -ladd -o app (-L 뒤에는 폴더 경로, -l 뒤에 파일 이름 입력)

gcc -fPIC -c add.c

gcc -shared -o libadd.so add.o

export LD_LIBRARY_PATH=.