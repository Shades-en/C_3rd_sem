#include<stdio.h>
#include<stdlib.h>

#define MALLOC(p,n,type)\
p=(type*)malloc(n*sizeof(type));\
if (p==NULL){\
 printf("Insufficient memory");\
 exit(0);\
}

struct node{
 int info;
 struct node *link;
};

typedef struct node *NODE;

NODE insert(NODE first, int item, int pos){
    NODE temp,cur;
    MALLOC(temp,1,struct node)
    temp->info=item;
    temp->link=NULL;
    if (pos==1 && first==NULL){
        temp->link=temp;
        return temp;
    }
    if(first==NULL){
        printf("invalid position \n");
        return first;
    }
    NODE prev=NULL;
    cur=first;
    int count=1;
    do{
        prev=cur;
        cur=cur->link;
        count++;
        if(count==pos)
            break;
    }while (cur!=first);
    if(pos>count){
        printf("invalid position \n");
        return first;
    }
    prev->link=temp;
    temp->link=cur;
    if (pos==1){
        return temp;
    }
    return first;
}

NODE delete(NODE first, int pos){
    NODE temp,cur;
    if(first==NULL){
        printf("Empty list \n");
        return first;
    }
    if(first->link==first && pos==1){
        printf("Deleted element is %d\n",first->info);
        free(first);
        return NULL;
    }
    NODE prev=NULL;
    cur=first;
    int count=1;
    do{
        prev=cur;
        cur=cur->link;
        if(prev->link!=first)
            count++;
        if(pos==count)
            break;
    }while(cur!=first);
    if(pos>count){
        printf("invalid position \n");
        return first;
    }
    temp=cur;
    prev->link=cur->link;
    printf("Deleted element is %d\n",temp->info);
    free(temp);
    if(pos==1)
        return prev->link;
    return first;
}


void display(NODE first){
 NODE cur;
 if(first==NULL){
 printf("List is empty\n");
 return;
 }
 cur=first;
 printf("The contents of the list:\n");
 while(cur->link!=first){
 printf("%d ", cur->info);
 cur=cur->link;
 }
 printf("%d ", cur->info);
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