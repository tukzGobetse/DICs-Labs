#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#include "omp.h"

#include <sys/time.h>





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

    FILE* resultsFile = fopen("resultsOPM.txt","w");

	if (resultsFile  == NULL)

	{

		printf("Error opening file!\n");

		exit(1);

	}

	

	struct timeval start, stop;

	double secs = 0;

	int No = 0;

	int numThreads = 0;

	

	for(int matrixSize = 0; matrixSize <= 13; matrixSize++ ){

		No = pow(2,matrixSize);

		int* Pr = (int*)calloc(No*No,sizeof(int));

		fillMatrix(Pr,No);

		fprintf(resultsFile, "Matrix Size %d \n", No);

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

				

			

			secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);

			//printf("time taken %f with threads %d \n",secs,numThreads);

			fprintf(resultsFile,"%f \t %d \n",secs,numThreads);

		}

		free(Pr);

	}

	fclose(resultsFile);

	return 0;

}