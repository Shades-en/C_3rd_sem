#include <stdio.h>
#include<stdlib.h>
#define MALLOC(p,n,type) \
p=(type*)malloc(n*sizeof(type)); \
if(p==NULL){ \
    printf("Insufficient memory \n"); \
    exit(0); \
}

struct node{
    float coeff;
    int exp;
    struct node *link;
};

typedef struct node *NODE;


NODE insert(NODE head,float co_eff,int expo){
    NODE temp,cur;
    MALLOC(temp,1,struct node);
    temp->coeff=co_eff;
    temp->exp=expo;
    temp->link=NULL;
    if(temp->coeff==0)
        return head;
    if(head==NULL || expo>head->exp){
        temp->link=head;
        return temp;
    }

/*----- code snippet only to eliminate multiple similar exponent terms entered by the user -----*/ 
    cur=head;
    int flag=0;
    while (cur!=NULL){
        if(temp->exp==cur->exp){
            flag=1;
            break;
        }
        cur=cur->link;
    }
    if(flag==1){
        cur->coeff+=temp->coeff;
        return head;
    }
/*---------------------------------------------------------------------------*/ 

    cur=head;
    while(cur->link!=NULL && expo<cur->link->exp){
        cur=cur->link;
    }
    temp->link=cur->link;
    cur->link=temp;
    return head;
}

NODE create(NODE head){
    int expo,n,i;
    float co_eff;
    printf("Enter the number of terms in the polynomial \n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter coefficient of term %d \n",i+1);
        scanf("%f",&co_eff);
        printf("Enter exponent of term %d\n",i+1);
        scanf("%d",&expo);
        head=insert(head,co_eff,expo);
    }
    return head;
}

NODE add(NODE head1, NODE head2){
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    NODE head=NULL;
    NODE cur1=head1;
    NODE cur2=head2;
    int sum=0;
    while(cur2!=NULL || cur1!=NULL){
        if(cur1==NULL || cur2==NULL || cur2->exp!=cur1->exp){
            if(cur2==NULL || cur1->exp>cur2->exp){
                head=insert(head, cur1->coeff, cur1->exp);
                cur1=cur1->link;
            }
            else if(cur1==NULL || cur2->exp>cur1->exp ){
                head=insert(head, cur2->exp, cur2->exp);
                cur2=cur2->link;
            }
        }
        else{
            sum=cur1->coeff+cur2->coeff;
            head=insert(head,sum,cur1->exp);
            cur2=cur2->link;
            cur1=cur1->link;
        }
    }
    return head;
}

void print(NODE head){
    if(head==NULL){
        printf("Empty expression\n");
        return;
    }
    NODE cur=head;
    while(cur->link!=NULL){
        printf("%fx^%d + ",cur->coeff,cur->exp);
        cur=cur->link;
    }
    printf("%fx^%d \n",cur->coeff,cur->exp);
    return;
}

void main(){
    NODE head1=NULL;
    printf("Enter polynomial 1 \n");
    head1=create(head1);
    NODE head2=NULL;
    printf("Enter polynomial 2\n");
    head2=create(head2);
    print(head1);
    print(head2);
    NODE head=NULL;
    printf("result: \n");
    head=add(head1,head2);
    print(head);
}
