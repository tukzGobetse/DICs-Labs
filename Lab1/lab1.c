#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define factor 0.1f


void setKArrayToZeros(int *Data, int numElements ){
/*
This function accept a K dimensional array of 
integers with unknown dimension lengths
*/	
	int newValue = 0;
	for(int i = 0 ; i<numElements; i++ ){
		*Data = newValue;
		Data++;
	}	
}

void setTenPercentToOnes(int *Data, int numElements ){
/*	
	This function accept a  K dimensional array of integers with 
	unknown dimension lengths
*/	
	int maxPoints = factor*numElements;
	int newValue = 1;
	for(int i = 0 ; i<maxPoints; i++ ){
		*Data = newValue;
		Data++;
	}
}

void printArray(int *Data, int numElements ){
	for(int i = 0 ; i<numElements; i++ ){
		printf("%d \n", *Data);
		Data++;
	}	
	printf("\n");
}

void findFivePercent(int *Data, int numElements, int * bounds, int lengthOfBounds){
	/*
		The function randomly chooses 5 percent of elements in array 
		Data and then it displays the coordinates of the element and
		its value.
	*/
	int fivePercent = 0.05*numElements;
	
	for(int element = 1; element <= fivePercent; element++){
		int tempNumElements = numElements;
		int *P1 = Data;
		int randPos = rand()%tempNumElements;
		P1 += randPos;
		int *P2 = Data;
		int iter = 0;
		int count = 0;
		printf("coordinates: ");
		for(int i =0; i <  lengthOfBounds; i++){
			
			iter = tempNumElements/(*(bounds + i));
			
			while(P2 < P1){
				P2 += iter;
				if(P1 >= P2 ){
					count++;
				} else {
					tempNumElements = iter;
					P2 -= iter;
					break;
				}
			}
			printf("%d ", count );
			count = 0;
		}
		printf(" value= %d\n",*P1);
	}
}


int main(){
	srand(0);
	printf("Test of array 1");
	{
		int dem =100*100;     //1000k
		int *ptr = (int*)calloc(dem,sizeof(int)); //pointer pointing to zeroeth element
		//Test Function1:
		setKArrayToZeros(ptr,dem);
		//Test Function2:
		setTenPercentToOnes(ptr,dem);
		//Test Function 3:
		int Bounds[2] = {100,100};
		int *bounds = (int*)Bounds;
		int lengthOfBounds = sizeof(Bounds)/sizeof(Bounds[0]);
		findFivePercent(ptr, dem, bounds ,lengthOfBounds);
		free(ptr);
	}//Test Array 1
	
	
	printf("Test of array 2");
	{
		int dem =100*100*100;     //1000k
		int *ptr = (int*)calloc(dem,sizeof(int)); //pointer pointing to zeroeth element
		
		//Test Function1:
		setKArrayToZeros(ptr,dem);
		//Test Function2:
		setTenPercentToOnes(ptr,dem);
		//Test Function 3:
		int Bounds[3] = {100,100,100};
		int *bounds = (int*)Bounds;
		int lengthOfBounds = sizeof(Bounds)/sizeof(Bounds[0]);
		findFivePercent(ptr, dem, bounds ,lengthOfBounds);
		free(ptr);
	}//Test Array 3
	
	
	printf("Test of array 3");
	{
		int dem =50*50*50*50;     //1000k
		int *ptr = (int*)calloc(dem,sizeof(int)); //pointer pointing to zeroeth element
		
		//Test Function1:
		setKArrayToZeros(ptr,dem);
		//Test Function2:
		setTenPercentToOnes(ptr,dem);
		//Test Function 3:
		int Bounds[4] = {50,50,50,50};
		int *bounds = (int*)Bounds;
		int lengthOfBounds = sizeof(Bounds)/sizeof(Bounds[0]);
		findFivePercent(ptr, dem, bounds ,lengthOfBounds);
		free(ptr);
	}//Test Array 4

	printf("Test of array 4");
	{
		int dem =20*20*20*20*20;     //1000k
		int *ptr = (int*)calloc(dem,sizeof(int)); //pointer pointing to zeroeth element
		
		//Test Function1:
		setKArrayToZeros(ptr,dem);
		//Test Function2:
		setTenPercentToOnes(ptr,dem);
		//Test Function 3:
		int Bounds[5] = {20,20,20,20,20};
		int *bounds = (int*)Bounds;
		int lengthOfBounds = sizeof(Bounds)/sizeof(Bounds[0]);
		findFivePercent(ptr, dem, bounds ,lengthOfBounds);
		free(ptr);
	}
	
	return 0;
}
