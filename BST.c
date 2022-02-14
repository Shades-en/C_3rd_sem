#include <stdio.h>
#include <stdlib.h>
#define COUNT 10
#define MALLOC(p,n,type)\
p=(type*)malloc(n*sizeof(type));\
if(p==NULL){\
    printf("Insufficient memory\n");\
    exit(0);\
}

struct node{
    int info;
    struct node *llink, *rlink;
};

typedef struct node *NODE;

//--------------------------with recursion------------------//

NODE insertBST(NODE root , int item){
    NODE temp;
    if(root == NULL){   
        MALLOC(temp,1,struct node);
        temp->info=item;
        temp->llink=temp->rlink=NULL;
        return temp;
    }
    else{
        if(item > root->info)
            root->rlink = insertBST(root->rlink , item);
        else if(item < root->info)
            root->llink = insertBST(root->llink , item);
        else
            printf("Duplicates are not allowed\n");
        return root;
    }
}

//-------------------without recursion--------------------//

NODE insert(NODE root, int item){
    NODE temp, prev, cur;
    MALLOC(temp,1,struct node);
    temp->info=item;
    temp->llink=temp->rlink=NULL;
    if(root==NULL)
        return temp;
    prev=NULL;
    cur=root;
    while(cur!=NULL){
        prev=cur;
        if(item==cur->info){
            printf("No duplicate items are allowed\n");
            free(temp);
            return root;
        }
        if(item<cur->info)
            cur=cur->llink;
        else
            cur=cur->rlink;
    }
    if(item<prev->info)
        prev->llink=temp;
    else    
        prev->rlink=temp;
    return root;
}

//----------------------------------------------//

void display(NODE root, int space){
    if (root == NULL)
        return;
    space += COUNT;
    display(root->rlink, space);
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->info);
    display(root->llink, space);
}

void main(){
    NODE root=NULL;
    int item,ch;
    printf("1. Insert  2. Display  3. exit");
    while(1){
        printf("\n");
        printf("Enter your choice \n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the element to be inserted \n");
                scanf("%d",&item);
                root=insert(root,item);
                break;

            case 2: 
                if(root==NULL){
                    printf("Empty tree \n");
                    break;
                }
                display(root,0);
                break;

            case 3:
                exit(0);

            default:
                printf("wrong choice \n");
                break;
        }
    }
}