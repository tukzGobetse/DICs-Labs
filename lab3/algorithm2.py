from mrjob.job import MRJob
from mrjob.step import MRStep
import os
import re
import sys


class matrixMANU(MRJob):
	def steps(self):
		return [MRStep(mapper = self.mapper, reducer = self.reducer1),MRStep(reducer = self.reducer2)]
	def mapper(self, _, value):
		
		if len(value.split()) == 2: 
			return 
		
		i,j,val = value.split()		 
		
		nameofMatrix = os.environ['map_input_file'] #checks from which input the element is from

		if nameofMatrix  == "Matrix1.txt":
			yield(j, ('M', i , val))
		else: 
			yield(i, ('N', j , val))
				
		
	def reducer1(self, key, values):
		listA = []
		listB = []
		for index in values: 
			if index[0] ==  'N':
				listB.append((index[2], index[1]))
			else:
				listA.append((index[2], index[1]))
		
		for elem1 in listA:
			for elem2 in listB:
				yield (elem1[1],elem2[1]), int(elem1[0])*int(elem2[0]) 
		
	def reducer2(self, key, values):
		yield [int(key[0]),int(key[1])] , sum(values)
		output.write('\n' + key[0] + " " + key[1] + " " + str(sum(values)))
		

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
	output = open("outputOfAlgorithm2.txt",'w')
	output.write(i_m + " " + i_n)	
	matrixMANU.run()

