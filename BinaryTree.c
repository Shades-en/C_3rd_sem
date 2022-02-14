#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

NODE creation(NODE root, int item){
    NODE temp, cur, prev;
    char directions[10];
    int i;
    MALLOC(temp,1,struct node);
    temp->info=item;
    temp->llink=temp->rlink=NULL;
    if(root==NULL)
        return temp;
    printf("Enter directions to insert(l/r)\n");
    scanf("%s",directions);
    cur=root;
    prev=NULL;
    for(i=0;i<strlen(directions);i++){
        if(cur==NULL)
            break;
        prev=cur;
        if(directions[i]=='l')
            cur=cur->llink;
        else
            cur=cur->rlink;
    }
    if(cur!=NULL||i!=strlen(directions)){
        printf("Insertion is Not Possible \n");
        free(temp);
        return root;
    }
    if(directions[i-1]=='l')
        prev->llink=temp;
    else
        prev->rlink=temp;
    return root;    
}

void inorder(NODE root){
    if(root==NULL){
        return;
    }
    inorder(root->llink);
    printf("%d \n",root->info);
    inorder(root->rlink);
}

void preorder(NODE root){
    if(root==NULL){
        return;
    }
    printf("%d \n",root->info);
    preorder(root->llink);
    preorder(root->rlink);
}

void postorder(NODE root){
    if(root==NULL){
        return;
    }
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d \n",root->info);
}

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
    int ch,item;
    printf("1. Insert  2. Inorder Display  3. Preorder Display  4. Postorder Display 5. Exit 6. Display \n");
    while (1){
        printf("\n");
        printf("Enter choice \n");
        scanf("%d",&ch);
        switch (ch){
            case 1:
                printf("Enter item to insert \n");
                scanf("%d",&item);
                root=creation(root, item);
                break;

            case 2:
                if(root==NULL){
                    printf("Empty tree\n");
                    break;
                }
                inorder(root);
                break;

            case 3:
                if(root==NULL){
                    printf("Empty tree\n");
                    break;
                }
                preorder(root);
                break;

            case 4:
                if(root==NULL){
                    printf("Empty tree\n");
                    break;
                }
                postorder(root);
                break;

            case 5:
                exit(0);

            case 6:
                if(root==NULL){
                    printf("Empty tree\n");
                    break;
                }
                display(root, 0);
                break;
        
            default:
                printf("wrong choice \n");
                break;
        }
    }
}