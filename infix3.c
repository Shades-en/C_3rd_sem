#include <stdio.h>
#include <ctype.h>

int s[30];
int top=-1;
void push(char item){
    s[++top]=item;
}
int pop(){
    if(top==-1)
        return -1;
    else
        return s[top--];
}
int priority(char sym){
    if(sym=='('){
        return 0;
    }
    if(sym=='+'||sym=='-'){
        return 1;
    }
    if(sym=='*'||sym=='/'||sym=='%'){
        return 2;
    }
    if(sym=='^'){
        return 3;
    }
    return 0;
}
void main(){
    char *e;
    char exp[30];
    int i;
    printf("Enter a valid infix expression:\n");
    scanf("%s",exp);
    e=exp;

    while(*e!='\0'){
        if(isalnum(*e)){
            printf("%c",*e);
        }
        else if(*e=='('){
            push(*e);
        }
        else if(*e==')'){
            char x;
            while ((x=pop())!='(') {
                printf("%c", x);
            }
        }
        else{
            while ((priority(s[top]))>= priority(*e)){
                printf("%c",pop());
            }
            push(*e);
        }
        e++;
    }
    while (top!=-1){
        printf("%c",pop());
    }
}