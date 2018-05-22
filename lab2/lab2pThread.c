#include <stdio.h>

#include <stdlib.h>

#include <pthread.h>

#include <math.h>

#include <sys/time.h>





struct arrayInfo

{

	int ID ;

	int limit;

    int *ptr;

 

};





void *p_transpose(void *arg)

{

   	struct arrayInfo *arg_Struct = (struct arrayInfo*)  arg ; 

			

	//used for switching

	int *ptr =  arg_Struct->ptr;
<<<<<<< HEAD

	int limit1=   arg_Struct->limit;   

=======
	int limit1=   arg_Struct->limit;   
>>>>>>> 8fb73c3d31c1ae211783fd0c23b33ea887608375
	int i = arg_Struct->ID ;

	int pos = 0 ;

	int pos1 = 0 ;

	for(int j = 0 ; j < i ; j++)

	{

		int temp=0;
<<<<<<< HEAD

		pos = i*limit1 + j ;

		temp = *(ptr+pos) ; 

		pos1 = j*limit1 + i ; 

=======
		pos = i*limit1 + j ;
		temp = *(ptr+pos) ; 
		pos1 = j*limit1 + i ; 
>>>>>>> 8fb73c3d31c1ae211783fd0c23b33ea887608375
		*(ptr+pos) = *(ptr+pos1) ; 

		*(ptr+pos1) = temp;

	}

}



void fillMatrix(int* matrix , int No)

{

	for(int i = 0 ; i < No*No ; i++)

	{

			matrix[i] = i+1;

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



int main(void)

{
<<<<<<< HEAD

	FILE* resultsFile = fopen("resultspThread.txt","w");

	if (resultsFile  == NULL)

	{

		printf("Error opening file!\n");

		exit(1);

	}

	struct timeval start, stop;

	long Dimen =0 ;

=======
	FILE* resultsFile = fopen("resultspThread.txt","w");
	if (resultsFile  == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
	struct timeval start, stop;
	long Dimen =0 ;
>>>>>>> 8fb73c3d31c1ae211783fd0c23b33ea887608375
	double secs = 0 ;

	int numThreads = 0;

	

	
<<<<<<< HEAD

	struct arrayInfo args[Dimen];

	int loop1 = 0;

	int tepp= Dimen ; 

	

	for(int matrixSize = 0; matrixSize <= 13; matrixSize++ ){

		Dimen = pow(2,matrixSize);

		int* ptr = (int*)calloc(Dimen*Dimen,sizeof(int));

		fillMatrix(ptr,Dimen);

		fprintf(resultsFile, "Matrix Size %d \n", Dimen);

		for(loop1 = 0; loop1 < 6; loop1++){

			numThreads = pow(2,loop1 + 2 );

			pthread_t* tids = calloc(numThreads, sizeof(pthread_t)) ; 

			gettimeofday(&start, NULL);	

			for(int i = 0 ; i < tepp ; i++ )

			{

				

				args[i].ID = i ; 

				args[i].limit = Dimen ; 

				args[i].ptr= ptr;  

				int temp = i % numThreads;

				pthread_create(&tids[temp], NULL, p_transpose , &args[i]);

			}

			



			

			for(int i = 0 ; i <  numThreads ; i++ )

			{

				if(numThreads <= tepp)

				{

				

				pthread_join(tids[i], NULL) ; 

				} else {

					pthread_join(tids[i%Dimen], NULL) ; 

				}

				

			}

			gettimeofday(&stop, NULL);



			

			secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);

			fprintf(resultsFile,"%f \t %d \n",secs,numThreads);

		}

		free(ptr);

=======
	struct arrayInfo args[Dimen];
	int loop1 = 0;
	int tepp= Dimen ; 
	
	for(int matrixSize = 0; matrixSize <= 13; matrixSize++ ){
		Dimen = pow(2,matrixSize);
		int* ptr = (int*)calloc(Dimen*Dimen,sizeof(int));
		fillMatrix(ptr,Dimen);
		fprintf(resultsFile, "Matrix Size %d \n", Dimen);
		for(loop1 = 0; loop1 < 6; loop1++){
			numThreads = pow(2,loop1 + 2 );
			pthread_t* tids = calloc(numThreads, sizeof(pthread_t)) ; 
			gettimeofday(&start, NULL);	
			for(int i = 0 ; i < tepp ; i++ )
			{
				
				args[i].ID = i ; 
				args[i].limit = Dimen ; 
				args[i].ptr= ptr;  
				int temp = i % numThreads;
				pthread_create(&tids[temp], NULL, p_transpose , &args[i]);
			}
			

			
			for(int i = 0 ; i <  numThreads ; i++ )
			{
				if(numThreads <= tepp)
				{
				
				pthread_join(tids[i], NULL) ; 
				} else {
					pthread_join(tids[i%Dimen], NULL) ; 
				}
				
			}
			gettimeofday(&stop, NULL);

			
			secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
			fprintf(resultsFile,"%f \t %d \n",secs,numThreads);
		}
		free(ptr);
>>>>>>> 8fb73c3d31c1ae211783fd0c23b33ea887608375
	}

	
<<<<<<< HEAD

=======
>>>>>>> 8fb73c3d31c1ae211783fd0c23b33ea887608375
	pthread_exit(0);

}