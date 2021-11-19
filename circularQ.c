#include <stdio.h>
#include <stdlib.h>
#define SIZE 6

int front = 0;
int rear = -1;
int count = 0;
int q[SIZE];

void enQ(int item){
    if(count==SIZE){
        printf("Queue is full \n");
    }
    else{
        rear=(rear+1)%SIZE;
        q[rear]=item;
        count++;
    }
}

int deQ(){
    int del;
    del=q[front];
    front=(front+1)%SIZE;
    count--;
    return del;
}

void display(){
    int i,temp;
    temp=front;
    if(count==0){
        printf("Queue is empty \n");
    }
    else{
        printf("The elements are \n");
        for(i=0;i<count;i++){
            printf("%d \t", q[front]);
            front=(front+1)%SIZE;
        }
        printf("\n");
        front=temp;
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
                enQ(item);
                break;

            case 2:
                if (count==0){
                    printf("Queue is empty\n");
                }
                else{
                    printf("item deleted is %d \n",deQ());
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