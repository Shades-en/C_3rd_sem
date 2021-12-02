#include<stdio.h>

int fib(int n){
    if(n<2) return n;
    return fib(n-1)+fib(n-2);
}

void main(){
    int n;
    printf("Enter the number of elements in the fibonacci series");
    scanf("%d",&n);
    printf("%d \n",fib(n));
}