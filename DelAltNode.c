#include <stdio.h>
#include<stdlib.h>
#define MALLOC(p,n,type) \
p=(type*)malloc(n*sizeof(type)); \
if(p==NULL){ \
    printf("Insufficient memory \n"); \
    exit(0); \
}

struct node{
    int info;
    struct node *link;
};

typedef struct node *NODE;

NODE insert(NODE first,int item){
    NODE temp,cur;
    MALLOC(temp,1,struct node);
    temp->info=item;
    temp->link=NULL;
    if(first==NULL){
        temp->link=first;
        return temp;
    }
    cur=first;
    while(cur->link!=NULL){
        cur=cur->link;
    }
    cur->link=temp;
    return first;
}

NODE DelAlt(NODE first){
    if(first==NULL){
        printf("Empty list\n");
        return first;
    }
    NODE temp,cur;
    cur=first;
    while(cur->link!=NULL){
        temp=cur->link;
        cur->link=cur->link->link;
        free(temp);
        cur=cur->link;
        if(cur==NULL)
            break;
    }
    return first;
}

NODE display(NODE first){
    if(first==NULL){
        printf("Empty list\n");
        return first;
    }
    NODE cur;
    cur=first;
    printf("list elements are \n");
    while(cur!=NULL){
        printf("%d ",cur->info);
        cur=cur->link;
    }
    printf("\n");
    return first;
}

void main(){
    int item;
    NODE first=NULL;
    while(1){
        printf("Enter the element to insert (enter -1 to stop inserting)\n");
        scanf("%d",&item);
        if(item==-1)
            break;
        else
            first=insert(first,item);
    }
    first=display(first);
    first=DelAlt(first);
    printf("New ");
    first=display(first);
}