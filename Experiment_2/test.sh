#Write a program to display your Name, Semester, Batch, Roll Number and Register Number.
#Write a program to display the sum of 2 Numbers.
#Write a program to find the greatest among two numbers.
#Write a program to display the first 10 natural numbers.
#Write a program to find the factorial of a given number.
#Write a program to find the fibonacci series of n numbers.
#Write a program to implement a simple calculator.

echo "Welcome to the program. Choose between number 1 - 7."
echo "Enter the number:"
read n

case $n in

1) 
    echo "Program to print your Name, Semester, Rollno"
    echo "Enter Name"
    read N
    echo "Enter Semester"
    read S
    echo "Enter Rollno"
    Read R
    echo "The name of the student is $N of semester $S. The rollno is $R."
    ;;
2)
    echo "Program to display the sum of 2 Numbers"
