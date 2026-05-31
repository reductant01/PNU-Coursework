gedit (gnome)
gedit &

fg
fg %1

sudo apt update (Superuser do Advanced Package Tool)
sudo apt install gedit

ps

kill -9 5764
kill + 20 == ctrl + z (suspend)

-------------------------------------------------------

echo $PATH
PATH=$PATH: (nano ~/.bashrc에 추가)
source ~/.bashrc

gcc -c main.c 
./a.out

gcc main.c -o myMain
chmod +x myMain
./myMain

mkdir subDir3
chmod -x subDir3
#cd subDir3 (permission denied)
chmod 0555 subDir3
chmod 0777 subDir3
-4 = read only
-2 = write only
-1 = execute only
-0 = no permission

-------------------------------------------------------

sudo apt update
sudo apt install vim

vi abc.txt
vim abc.txt
- normal mode
- i = insert mode
- v = visual mode
- V = visual line mode
- : = command mode

# 1. Saving & Exiting (Command Mode)
:q   = quit
:q!  = quit without saving
:w   = write (save)
:wq  = write and quit
:x   = save and quit

# 2. Editor Settings (Command Mode)
:set nonumber = hide line number
:set number   = show line number

:%s/is/was/gc
:1,$s/is/was/gc
  - :command mode
  - % = all lines
  - 1,$ = from line 1 to last line
  - s = substitute
  - / = search
  - /is = search for "is"
  - /was = search for "was"
  - g = global
  - c = confirm

# 3. Navigation & Movement
$    = move to end of line
^    = move to beginning of line (first non-blank character)
gg   = go to first line
G    = go to last line
h    = move left
j    = move down
k    = move up
l    = move right

# 4. Inserting Text (Mode Switch)
a    = move one character right and insert
A    = move to end of line and insert
i    = insert at current cursor position
I    = move to beginning of line and insert
o    = insert line below
O    = insert line above

# 5. Editing (Copy, Paste, Delete, Change, Undo)
* = find the exact word under cursor
n    = next occurrence
N    = previous occurrence

.    = repeat last command
c    = change (requires motion key)
C    = change to end of line
dd   = delete line (cut)
10dd = delete 10 lines
D    = delete to end of line
J    = join line
p    = paste after cursor
P    = paste before cursor

u    = undo last action
U    = undo all changes on current line
R    = replace text
yy   = copy line
Y    = copy line
m    = mark

-------------------------------------------------------

env ( 진행 중인 process의 environment variable 확인 )
env | grep USER ( | 는 pipe로 process 간의 연결, grep는 특정 단어를 검색 )\
env | sort ( env의 표준 출력을 sort의 표준 입력으로 사용 )
env | sort | more ( env | sort의 표준 출력을 more의 표준 입력으로 사용 )

ls -l (long format)
ls -l *.txt
    10칸을 1칸 3칸 3칸 3칸으로 분류
    제일 앞칸은 -(일반파일), d(Directory), l(Link)
ls -s (size)
ls -sl    
ls -sh (human-reactable)
ls -i (inode)
ls -il
ls a*
ls a?

touch -t 202512251204 a.txt (a.txt의 파일이 time 수정)

cp -p a,txt b.txt ( preserve )
cp -l a.txt c.txt ( link/하드링크 생성 )
cp -s a.txt d.txt ( symbolic link/소프트 링크 생성 )
    symbolic link는 가리키는 대상이 삭제되면 오류 발생


ln aaa.txt xxx.txt ( link/하드링크 생성 )

rm -i c.txt (interactive)

-------------------------------------------------------

umask 
umask 0044
    권한의 압수
    최대권한 666에서 umask 값을 빼았음 ( 파일의 기본 권한은 666, 단 폴더의 기본 권한은 777 )


chmod o-r aaa.txt
chmod u-x tempDir/
    o (누구에게?) : Others (나머지 제3자들)

        u = User (주인, 나)

        g = Group (우리 그룹)

        o = Others (나와 그룹을 제외한 나머지 지나가는 사람들)

        a = All (위의 셋 전부 다)

    - (어떻게 할래?) : 권한 빼앗기

        + = 권한 주기

        - = 권한 뺏기

        = = 딱 이것만 남기고 다 덮어쓰기

    r (무슨 권한을?) : Read (읽기 권한)

        r = Read (읽기)

        w = Write (쓰기)

        x = eXecute (실행)

   
   dumpe2fs (dump ext4)