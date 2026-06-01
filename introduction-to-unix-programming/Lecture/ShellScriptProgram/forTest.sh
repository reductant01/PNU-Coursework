# // for Test shell sript
#!/bin/bash
# test for loop

# for i in {1..5}
# do 
#     echo "i = $i"
# done

# for test in Alice Bob Charlie
# do 
#     echo "Hello, $test"
# done

# for file in *.txt
# do 
#     echo "file: $file"
# done

# for test in {A..E}
# do 
#     echo "Letter $test"
# done

# for test in "Hello World"
# do 
#     echo "String $test"
# done

# for test in I do not know
# do 
#     echo "String $test"
# done

# list="one two three"
# list=$list" four five"

# for test in $list
# do 
#     echo "test: $test"
# done

# for state in 'cat aaa.txt'
# do 
#     echo "state: $state"
# done

# IFS=$'\n'
# for state in `cat aaa.txt`
# do 
#     echo "State: $state"
# done

# IFS=$'\n'                      # 1. 첫 번째 칼날 세팅 (줄바꿈)
# for state in `cat /etc/passwd` # 2. 바깥쪽 반복문 (한 줄씩 가져오기)
# do 
#     IFS=:                      # 3. 두 번째 칼날 세팅 (콜론)
#     for field in $state        # 4. 안쪽 반복문 (가져온 한 줄을 조각내기)
#     do 
#         echo "Field: $field"   # 5. 조각난 단어 출력
#     done                       # 6. 안쪽 반복문 끝
# done                           # 7. 바깥쪽 반복문 끝 (추가됨!)

# for file in $HOME/*
# do 
#     if [ -d "$file" ]
#     then 
#         echo "$file is a directory"
#     else
#         echo "$file is a file"
#     fi
# done


# # 결과를 ccc.txt 파일로 저장
# for ((a=1, b=10; a<=5; a++, b+=10))
# do 
#     echo "a: $a, b: $b"
# done > ccc.txt

# //while test shell script
# var=1
# while [ $var -le 5 ]

# do  
#     echo "var: $var"
#     var=$((var+1))
# done

# var1=100
# until [ $var1 -le 50 ]
# do 
#     echo "var1: $var1"
#     var1=$((var1-10))
# done

//for loop break and continue test shell script
do
    if [ $i -eq 3 ]; then
        echo "Skipping iteration $i"
        continue
    fi
    if [ $i -eq 7 ]; then
        echo "Breaking at iteration $i"
        break
    fi
    echo "Iteration $i"
done