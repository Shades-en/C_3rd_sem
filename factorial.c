#include <stdio.h>

int fact(int n){
    if(n==0){
        return 1;
    }
    return n*fact(n-1);
}

void main(){
    int n;
    printf("Enter the number \n");
    scanf("%d",&n);
    printf("Factorial is %d \n",fact(n));
}