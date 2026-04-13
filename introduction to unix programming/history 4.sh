gzip aaa.txt
gunzip aaa.txt.gz
grip -d aaa.txt.gz

tar -cvzf archiv.tar.gz * ( create verbose gzip file )
tar -xvzf archiv.tar.gz ( extract verbose gzip file )

ps -ef ( every full )
ps aux
ps aux | grep "gedit"
# 이때 tty 값이 ?로 되어있다면 터미널에 묶여있지 않다는 말
ps -fH ( full hierarchy, 계층구조를 보여줌 )
ps -l ( long format )
# uid = user id, pid = process id, ppid = parent process id, tty = terminal, stat = process status, time = cpu time, cmd = command

gedit &
nohup gedit &
# tty 값이 ?로 되면서 gedit 실행, 터미널이 꺼져도 동작

lllll > abc.txt ( error message 를 파일에 저장 )

# 0번 ( standard input )
# 1번 ( standard output )
# 2번 ( standard error )

lllll > abc.txt
lllll > abc.txt 2>1 ( 정상 출력만 abc.txt에 저장, error message는 1이라는 파일에 출력 )
lllll > abc.txt 2>&1 ( 정상 출력과 error message 모두 abc.txt에 저장 )

ls -R /

kill -9 ( sigkill, 강제종료 )
kill -15 ( sigterm, 정상종료 )
kill -18 ( sigstop, 일시정지 )
kill -19 ( sigcont, 계속 )

pstree -p ( process tree with pid )
pstree -p 1 ( process tree with pid 1 )
