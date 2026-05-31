touch e.txt

mkdir subDir4

mv subDir4 subDir5
mv e.txt ./subDir5

rm -r subDir5 ( Recursive )

cat > a.txt
cat a.txt
cat -n a.txt ( number all lines )
cat -b a.txt ( number non-blank lines )
cat -s a.txt ( squeeze blank lines )
cat -T a.txt ( show tab as ^I )
cat -T a.txt > b.txt

last

file a.txt
file /bin/ls