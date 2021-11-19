#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int s[SIZE];
int top=-1;

void push(int item){
    if(top==SIZE-1){
        printf("Stack overflow \n");
    }
    else{
        s[++top]=item;
    }
}

int pop(){
    return s[top--];
}

void display(){
    int i;
    if(top==-1){
        printf("Stack Empty \n");
    }
    else {
        for (i = top; i >= 0; i--) {
            printf("%d \n",s[i]);
        }
    }
}

void main(){
    int item,choice;
    printf("1.push 2.pop 3.display 4.exit");
    while(1){
        printf("enter a choice \n");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf("Enter an element to push \n");
                scanf("%d",&item);
                push(item);
                break;

            case 2:
                if (top==-1){
                    printf("Stack underflow \n");
                }
                else{
                    printf("item deleted is %d \n",pop());
                }
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Wrong choice \n");
                break;
        }
    }
}