#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>


int main(){

//creating the array
int n = 1000;
int *A = malloc(n*sizeof(int)); 

//checking if allocation happened corectly 

if(A==NULL){
    printf("allocation failed");
    return 1;
}
//filling the array
int i;
for(i=0;i<n;i++){
  A[i]=i*2;    
}
//reading the value we want to search for
int val;
printf("Enter the value to search: ");
//reading and cheking if input is valid
if (scanf("%d", &val) != 1) {
    printf("Invalid input\n");
    free(A);
    return 1;
}

//sequential search 

clock_t start ,end;
start = clock();

bool found=false;i=0;


while (i<n && !found )
{
    if (A[i]==val){
        found=true;
    }
    i++;
}

end = clock();
double elapsed=(double)(end - start)/CLOCKS_PER_SEC;
if(found){
    printf("value found\n");
}else printf("value not found\n");
printf("execution time for sequential search is : %.9f seconds\n",elapsed);



//binary search 
start=clock();
int left,right,mid;
found=false;
//cheking if the value is withvin the range of the array's elemetns 
if(A[0]<=val && A[n-1]>=val){
    left=0;right=n-1;;

while (left<=right && !found)
{
    mid=(left+right)/2;

    if(A[mid]==val){
        found=true;
    }else if (A[mid]<val){
        left=mid+1;
    }else right=mid-1;
}
}

end=clock();
elapsed=(double)(end - start)/CLOCKS_PER_SEC;
if(found){
    printf("value found\n");
}else printf("value not found\n");
printf("execution time for binary search is : %.9f seconds\n",elapsed);

free(A);
    return 0;
}