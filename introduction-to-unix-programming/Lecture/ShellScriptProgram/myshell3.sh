#!bin/bash
# A simple shell script to demonstrate basic scripting concepts
var1=10
var2=20
var3=$var1+$var2
echo "var1: $var1, var2: $var2, var3: $var3"
var3=$((var1+var2))
echo "var1: $var1, var2: $var2, var3: $var3"
var4='expr $var1 + $var2'
echo "var4: $var4"

