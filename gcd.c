#include <stdio.h>

int gcd(int a,int b){
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    if(a==b){
        return a;
    }
    if(a>b){
        return gcd(a-b,b);
    }
    return gcd(a,b-a);
}

void main(){
    int a,b;
    printf("Enter two numbers \n");
    scanf("%d%d",&a,&b);
    printf("GCD of two numbers is =%d",gcd(a,b));
}