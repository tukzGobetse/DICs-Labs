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
	int limit=   arg_Struct->limit;   
	int i = arg_Struct->ID ;
	int pos = 0 ;
	int pos1 = 0 ;
	for(int j = 0 ; j < i ; j++)
	{
		int temp=0;
		pos = i*limit + j ;
		temp = *(ptr+pos) ; 
		pos1 = j*limit + i ; 
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
	struct timeval start, stop;
	long int Dimen =0 ;
	double secs = 0 ;
	int numThreads = 0;
	
	
	printf("insert <Matrix dimensions>\n");
	scanf("%ld",&Dimen);
	
	int *ptr =(int*)calloc(Dimen*Dimen,sizeof(int)); 
	fillMatrix(ptr, Dimen) ; 
	pthread_t tids[numThreads] ; 
	struct arrayInfo args[Dimen];
	
	for(int loop1 = 0; loop1 < 6; loop1++){
		numThreads = pow(2,loop1 + 2 );
		gettimeofday(&start, NULL);	
		for(int i = 0 ; i < Dimen ; i++ )
		{
			args[i].ID = i ; 
			args[i].limit = Dimen ; 
			args[i].ptr= ptr;  
			int temp = i % numThreads;
			pthread_create(&tids[temp], NULL, p_transpose , &args[i]);
		}
		

		
		for(int i = 0 ; i <  numThreads ; i++ )
		{
			if(numThreads <= Dimen)
			{
			
			pthread_join(tids[i], NULL) ; 
			} else {
				pthread_join(tids[i%Dimen], NULL) ; 
			}
			
		}
		gettimeofday(&stop, NULL);

		
		secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
		printf("time taken %f with threads %d \n",secs,numThreads);
	}
	
	free(ptr);
	
	pthread_exit(0);
}

