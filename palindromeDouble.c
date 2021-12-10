//Pallindrome doubly Linked List
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


int main(){
 int i,n,flag=0,t;
 NODE head=NULL,cur,rcur;
 printf("Enter the number of the elements to be reversed\n");
 scanf("%d",&n);
 printf("Enter the elements to be reversed\n");
 for(i=0;i<n;i++){
 scanf("%d", &t);
 head=insert_rear(head,t);
 }
 
 rcur=cur=head;
 
 while(rcur->rlink!=NULL){
 rcur=rcur->rlink;
}
 while(cur!=rcur){
 if(cur->info!=rcur->info){
 flag=1;
 break;
}
cur=cur->rlink;
rcur=rcur->llink;
}
if(flag!=1)
printf("Pallindrome\n");
else
 printf("NOT Pallindrome\n");
 
}