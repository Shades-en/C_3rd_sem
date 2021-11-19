#include <stdio.h>
#include <ctype.h>

int top=-1;
int s[30];

void push(int n){
    s[++top]=n;
}

int pop(){
    return s[top--];
}

void main(){
    int n1,n2,num;
    char exp[30];
    char *e;

    printf("Enter expression\n");
    scanf("%s",exp);
    e=exp;

    while (*e!='\0'){
        if(isdigit(*e)){
            num=*e-'0';
            push(num);
        }

        else{
            n1=pop();
            n2=pop();
            switch (*e) {
                case '+':
                    push(n1+n2);
                    break;

                case '-':
                    push(n2-n1);
                    break;

                case '*':
                    push(n1*n2);
                    break;

                case '/':
                    push(n2/n1);
                    break;
            }
        }e++;
    }
    printf("ans=%d\n",pop());
}
