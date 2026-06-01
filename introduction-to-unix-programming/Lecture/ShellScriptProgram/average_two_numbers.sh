#!/bin/bash
echo "Enter the first number:"
read num1
echo "Enter the second number:"
read num2
average=$(( (num1 + num2) / 2 ))
echo "The average of $num1 and $num2 is: $average"
