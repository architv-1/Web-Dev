#include<stdio.h>
void main(){
    int num;
    printf("Enter the Number: ");
    scanf("%d",&num);
    int one = num;
    int two, five, six , three, four;
    int Two_Times = two = five = six = num*2;
    int Three_Times = three = four = num*3;
    int sum = one + two + three + four + five + six;

    printf("Number is %d",sum);  
}  // num=3  one =3   two = 6 five = 6 six = 6 three = 9 four = 9 
