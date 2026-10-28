// Note: A larger array would provide more significant execution-time
// differences. For practical testing, n is set to 1000 to keep memory
// usage reasonable. Consequently, the measured execution times may
// be too small to demonstrate the differences clearly.

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

//indexed sequential search 
//devide the array to 100 blocks
int numBlocks = 100;
int blockSize = n / numBlocks;
//store the last element of each block in an array
int *index = malloc(numBlocks * sizeof(int));
//check allocation
if(index==NULL){
    printf("allocation failed");
    free(A);
    return 1;
}
//fill the array
int j;
for(i=0;i<numBlocks;i++){
  j=(i + 1) * blockSize - 1;
  index[i]=A[j];

}
start = clock();
//finding the right block where val belongs
int block = 0;
while (block<numBlocks && index[block]<val)
{
    block++;//index of first value bigger or equal to val
}
//searching sequentially in the chosen block
found=false;
if(block <numBlocks){
int last = (block+1)*blockSize -1;
int first=last - blockSize+1;

i=first;

while (i<=last && !found )
{
    if (A[i]==val){
        found=true;
    }
    i++;
}
}
end=clock();
elapsed=(double)(end - start)/CLOCKS_PER_SEC;

if(found==false){
    printf("value not  found\n");
}else printf("value found\n ");

printf("execution time for indexed sequential search is : %.9f seconds\n",elapsed);

free(index);
free(A);
    return 0;
}