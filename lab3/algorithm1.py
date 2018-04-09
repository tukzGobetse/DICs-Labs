from mrjob.job import MRJob
import os
import re
import sys


class matrixMANU(MRJob):
	def mapper(self, _, value):
		
		if len(value.split()) == 2: 
			return 
		
		x,y,val = value.split()		 
		
		nameofMatrix = os.environ['map_input_file'] #checks from which input the element is from

		if nameofMatrix  == "Matrix1.txt":
			for col1 in range(0,int(j_n)):
				yield (int(x),col1) , ('Matrix1', int(y),int(val))
		else: 
			for row1 in range(0,int(i_m)):
				yield (row1, int(y)), ('Matrix2', int(x), int(val))
				
		
	def reducer(self, key, values):
		listA = []
		listB = []
		MatrixC = [] 
		
		for index in values: 
			if index[0]==  'Matrix2':
				listB.append([index[2], index[1]])
			else:
				listA.append([index[2], index[1]])
		for elem1 in listA:
			for elem2 in listB:
				if elem1[1] == elem2[1]:
					MatrixC.append(elem1[0]*elem2[0])
		if sum(MatrixC) > 0:
			yield key , sum(MatrixC)
			output.write('\n' + str(key[0]) + " " + str(key[1]) + " " + str(sum(MatrixC)) )
		

 		
		

if __name__ == '__main__':
	matrix1 = open("./Matrix1.txt","r")
	i_m,j_m = matrix1.readline().split()
	if i_m == '0':
		i_m = '1'
	if j_m == '0':
		j_m = '1'
	matrix2 = open("./Matrix2.txt","r")
	i_n,j_n = matrix2.readline().split()	
	if i_n == '0':
		i_n = '1'
	if j_n == '0':
		j_n = '1'
		
	output = open("outputOfAlgorithm1.txt",'w')
	output.write(i_m + " " + i_n)
	matrixMANU.run()

