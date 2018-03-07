#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "omp.h"
#include <sys/time.h>


#define NUM_THREADS 128
#define MATRIX_DIM 500

void swap(int* A, int* B){
	
	int temp = *A;
	*A = *B;
	*B = temp;
}

void transposeFromDiagonal(int* diagonalElement,int index, int n){
	
	//diagonalElement is the memory address of the element in the diagonalElement
	//index is the position of the diagonal element, counting diagonally from [1][1] top left element ss zeroeth index.
	//n is the dimension of square matrix
	
	 for(int j = 1; j<=index; j++)
     {
       swap(diagonalElement - n*j, diagonalElement - j); 
     }
	
}

void Print(int* squareMatrix, int n){
	
	for(int i = 0 ; i < n  ; i++ )
	{
		for(int j = 0 ; j <n ; j++)
		{
			printf("%d\t", *(squareMatrix + n*i + j));
		}
		printf("\n");
	} 
	printf("\n");	
}

void fillMatrix(int* matrix, int No){
	
	for(int i = 0 ; i < No*No  ; i++ )
	{
		matrix[i] = i +1;
	} 
}

int main(void)
{
    
	struct timeval start, stop;
	double secs = 0;
	long int No = 0;
	int numThreads = 0;
	
	printf("insert <Matrix dimensions>\n");
	scanf("%ld",&No);
	
	int* Pr = (int*)calloc(No*No,sizeof(int));
	
	fillMatrix(Pr,No);
	
	
	if(No < 10)
		Print(Pr,No);
	for(int loop1 = 0; loop1 < 6; loop1++){
		numThreads = pow(2,loop1 + 2 );
		gettimeofday(&start, NULL);
		
		#pragma omp parallel num_threads(numThreads)
		{
			#pragma omp for
			for(int index = 0; index < No; index++){
				transposeFromDiagonal(Pr + (No + 1)*index,index, No); 
			}
		}
		gettimeofday(&stop, NULL);
		if(No < 10)
			Print(Pr,No);	
		
		secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
		printf("time taken %f with threads %d \n",secs,numThreads);
	}
	free(Pr);
	
	return 0;
}

