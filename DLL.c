#include <stdio.h>
#include<stdlib.h>
#define MALLOC(p,n,type) \
p=(type*)malloc(n*sizeof(type)); \
if(p==NULL){ \
    printf("Insufficient memory \n"); \
    exit(0); \
}

struct node{
    struct node *llink;
    int info;
    struct node *rlink;
};

typedef struct node *NODE;

NODE insert(NODE first,int item,int pos){
    NODE temp,cur;
    MALLOC(temp,1,struct node)
    temp->llink=NULL;
    temp->info=item;
    temp->rlink=NULL;
    if(pos==1){
        temp->rlink=first;
        if(first!=NULL)
            first->llink=temp;
        return temp;
    }
    if(first==NULL && pos>1){
        free(temp);
        printf("Invalid position \n");
        return first;
    }
    cur=first;
    int count=1;
    while(cur->rlink!=NULL){
        cur=cur->rlink;
        count++;
        if(count==pos)
            break;
    }
    if(pos>count+1){
        free(temp);
        printf("Invalid position \n");
        return first;
    }
    if(pos==count+1){
        cur->rlink=temp;
        temp->llink=cur;
        return first;
    }
    temp->llink=cur->llink;
    temp->rlink=cur;
    cur->llink->rlink=temp;
    cur->llink=temp;
    return first;
}

NODE delete(NODE first,int pos){
    NODE temp,cur;
    if(first==NULL){
        printf("Empty list \n");
        return first;
    }
    if(pos==1){
        temp=first;
        first=first->rlink;
        if(first!=NULL)
            first->llink=NULL;
        printf("Element deleted is %d\n",temp->info);
        free(temp);
        return first;
    }
    cur=first;
    int count=1;
    while(cur->rlink!=NULL){
        cur=cur->rlink;
        count++;
        if(count==pos)
            break;
    }
    if(pos>count){
        printf("Invalid position \n");
        return first;
    }
    temp=cur;
    cur->llink->rlink=cur->rlink;
    if(cur->rlink!=NULL)
        cur->rlink->llink=cur->llink;
    printf("Element deleted is %d\n",temp->info);
    free(temp);
    return first;
}

void display(NODE first){
    if(first==NULL){
        printf("Empty list\n");
        return;
    }
    NODE cur;
    cur=first;
    while(cur!=NULL){
        printf("%d ",cur->info);
        cur=cur->rlink;
    }
    printf("\n");
}

void main(){
    int item,ch,pos;
    NODE first=NULL;
    printf("1.Insert at pos 2.Delete at pos 3.display 4.exit \n");
    while(1){
        printf("Enter a choice \n");
        scanf("%d",&ch);
        printf("\n");
        switch (ch)
        {
        case 1:
            printf("Enter an element to insert\n");
            scanf("%d",&item);
            printf("Enter the position to insert \n");
            scanf("%d",&pos);
            first=insert(first,item,pos);
            break;

        case 2:
            printf("Enter position to delete \n");
            scanf("%d",&pos);
            first=delete(first,pos);
            break;

        case 3:
            display(first);
            break;
        
        case 4:
            exit(0);

        default:
            printf("Wrong choice\n");
            break;
        }
    }
}