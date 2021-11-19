#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int front=0;
int rear=-1;
int q[10];

void qInsert(item){
    if(rear==SIZE-1){
        printf("Queue is full \n");
    }
    else{
        q[++rear]=item;
    }
}

int qDelete(){
    return q[front++];
}

void display(){
    int i;
    if(front>rear){
        printf("Queue is Empty \n");
    }
    else{
        for(i=front;i<=rear;i++){
            printf("%d \t",q[i]);
        }
        printf("\n");
    }
}

void main(){
    int choice, item;
    printf("1.Enqueue 2.Dequeue 3.display 4.exit");
    while(1){
        printf("enter a choice \n");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf("Enter an element to Enqueue \n");
                scanf("%d",&item);
                qInsert(item);
                break;

            case 2:
                if (front>rear){
                    printf("Queue is empty\n");
                }
                else{
                    printf("item deleted is %d \n",qDelete());
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