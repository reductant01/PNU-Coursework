# list
ls
ls -a
ls; whoami
ls ba*
ls sh
ls a*
ls aaa? 
ls -l ../subsubDir2


cat ~/.bash_history
cat /etc/passwd
cat ccc.txt
cat 
    I am 
cat > zzz.txt
    I am

# process status
ps 
ps aux

# change directory
cd /
cd ~
cd . 
cd ..
cd ../..
cd /bin
cd /dev/pts # 어떤 파일이 있는지 확인

# print working directory
pwd

touch aaa1
touch aaa.txt 

# make directory
mkdir dir1

# manual
man touch 
man ls

# remove directory
rmdir Dir1 ( remove directory )
rm -ri Dir1 ( recursive and interactive )
rm -rf Dir1 ( recursive and force )

# copy file
cp aaa.txt bbb.txt
cp -p aaa.txt ccc.txt ( preserve )
cp aaa.txt ../subsubDir2

echo "Hello, World!" 
echo "Hello, World!" > ccc.txt
echo $myVAR # 변수 생성 후 출력
echo "Hello" > /dev/pts/0 # 터미널에 출력


myVAR="aaaaa"

# 0: standard input (stdin)
# 1: standard output (stdout)
# 2: standard error (stderr)



