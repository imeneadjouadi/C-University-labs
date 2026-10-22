//exo1: comparing execution time of deletion of all values that are less or equal than 50 from  two identical arrays
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main (){
// creating and filling the arrays with random values from 0 to 100
int i,j,n=10000;
int *A1=malloc(n*sizeof(int));
int *A2=malloc(n*sizeof(int));

//checking if the allocation happened corectly
if (A1==NULL || A2 == NULL){
   printf("Allocation Error"); return 1;
}
srand(time(NULL));
for(i=0;i<n;i++){
   A1[i]=rand()%101;
   A2[i]=A1[i];
}

//first method:two nested loops

clock_t start ,end;
start = clock();
i=0;
while(i<n) {
  if(A1[i]<=50){
    j=i;
    while(j<n-1){
        A1[j]=A1[j+1];
        j++;
    } n=n-1;
  } else i++;
}

end = clock();
double elapsed=(double)(end - start)/CLOCKS_PER_SEC;
printf("execution time for method 1 is : %.9f seconds\n",elapsed);

int n1 = n;

//method 2 :using a single loop 
start = clock();
n=10000;j=-1;
for(i=0;i<n;i++){
  if (A2[i]>50){
     j= j+1;
     A2[j]=A2[i];
     
  }

}n=j+1;
end =clock();
elapsed=(double)(end - start)/CLOCKS_PER_SEC;
printf("execution time for method 2 is : %.9f seconds\n",elapsed);

int n2 = n;
// checking if the two methods works and give same result without printing all the array's elements
if (n1 != n2) {
    printf("Error: different numbers of elements!\n");
} else {
    int correct = 1;

    for (i = 0; i < n1; i++) {
        if (A1[i] != A2[i] || A1[i] <= 50) {
            correct = 0;
            break;
        }
    }

    if (correct == 1) {
        printf("Both methods produced the same correct result.\n");
    } else {
        printf("Error: the results are different or incorrect.\n");
    }
}
free(A1);
free(A2);

return 0;
}