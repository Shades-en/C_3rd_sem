#include <stdio.h>

int tower(int n,char s,char t, char d);

int main(){
    int n;
    printf("Enter the number of disks \n");
    scanf("%d",&n);
    tower(n,'A','B','C');
}

int tower(int n,char s,char t, char d){
    if(n==1){
        printf("move %d disks from %c to %c \n",n,s,d);
        return ;
    }
    tower(n-1,s,d,t);
    printf("move %d disks from %c to %c \n",n,s,d);
    tower(n-1,t,s,d);
}