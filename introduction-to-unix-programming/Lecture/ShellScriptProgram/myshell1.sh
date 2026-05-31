#!/bin/bash
# A simple shell script to demonstrate basic scripting concepts
date
echo "Let's see who is currently logged in"
who
var1="Hello, World!" # = 좌우에 공백이 있으면 안됨
echo "$var1" # 변수를 출력하려면 $변수명 이렇게 치면 됨 
echo "Uset infomation"
echo "Current user: $USER"
echo "Home directory: $HOME"
echo "Current working directory: $(pwd)" # pwd는 현재 작업 디렉토리를 출력하는 명령어, $pwd라고 치면 pwd의 변수를 찾음
echo "Listing files in the current directory:"
echo "The cost of item is $0 $1500" # $0은 스크립트 이름, $1은 첫 번째 인자, $2는 두 번째 인자, ...
var2=10
var3==20
var4=testing
echo "var2: $var2, var3: $var3, var4: $var4"
#ls -l