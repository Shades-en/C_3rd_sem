#include <stdio.h>

int binSearch( int a[], int key,int low,int high){

    if (low<high) {
        int mid = (low + high) / 2.0;
        if (key > a[mid]) {
            binSearch(a, key, mid + 1, high);
        } else if (key < a[mid]) {
            binSearch(a, key, low, mid - 1);
        } else if (key == a[mid]) {
            return mid + 1;
        }
    }
    else{
        return -1;
    }
}

void main(){
    int n,key,pos,i,high,low,a[20];
    printf("enter size of array \n");
    scanf("%d",&n);
    printf("enter array elements \n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter element to be searched \n");
    scanf("%d",&key);
    high=n-1;
    low=0;
    pos=binSearch(a,key,low,high);
    if(pos==-1){
        printf("element not found \n");
    }
    else{
        printf("element found in position %d",pos);
    }
}