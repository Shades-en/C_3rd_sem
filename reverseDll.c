//Reversal doubly Linked List
#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, n,type) ((p) = (type*)malloc((n) * sizeof (type)));
struct node{
struct node *llink;
 int info;
 struct node *rlink;
};
typedef struct node *NODE;
NODE insert_rear(NODE head,int item){
 NODE temp,cur;
 MALLOC(temp,1,struct node);
 temp->rlink=NULL;
 temp->info=item;
 temp->llink=NULL;
 if(head==NULL)
 return temp;
 cur=head;
 while(cur->rlink!=NULL)
 cur=cur->rlink;
 cur->rlink=temp;
 temp->llink=cur;
 return head;
}
void display(NODE head){
 NODE cur;
 if(head==NULL){
 printf("List is empty\n");
 return;
 }
 cur=head;
 printf("The contents of the list:\n");
 while(cur!=NULL){
 printf("%d ", cur->info);
 cur=cur->rlink;
 }
 printf("\n");
}
NODE reverse(NODE head){
 NODE temp=NULL, cur, next;
 
next= head->rlink;
 cur=head;
 while(cur->rlink!= NULL){
 temp=cur->llink;
 cur->llink=cur->rlink;
 cur->rlink=temp;
 cur=next;
 next=next->rlink;
 }
 temp=cur->llink;
 cur->llink=cur->rlink;
 cur->rlink=temp;
 return cur;
}
int main(){
 int i,n, item,t;
 NODE head=NULL;
 printf("Enter the number of the elements to be reversed\n");
 scanf("%d",&n);
 printf("Enter the elements to be reversed\n");
 for(i=0;i<n;i++){
 scanf("%d", &t);
 head=insert_rear(head,t);
 }
 printf("Before reversal:\n");
 display(head);
 head=reverse(head);
 printf("After reversal:\n");
 display(head);
}
