print("\n********PROGRAM FOR SPARSE MATRIX OPERATIONS**********")

def add(matrix1, matrix2):
	matrix3 = []
	n = matrix1[0][2]+1
	matrix3.append([matrix1[0][0],matrix1[0][1],matrix1[0][2]])
	i = 1; j = 1; k = 1
	while i < n and j < n:
		if matrix1[i][0] == matrix2[j][0]:
			if matrix1[i][1] == matrix2[j][1]:
				s = matrix1[i][2] + matrix2[j][2]
				matrix3.append([matrix1[i][0],matrix1[i][1],s])
				i += 1
				j += 1
				k += 1
			else :
				if matrix1[i][1] < matrix2[j][1] :
					matrix3.append([matrix1[i][0],matrix1[i][1],matrix1[i][2]])
					i += 1
					k += 1
				else :
					matrix3.append([matrix2[j][0],matrix2[j][1],matrix2[j][2]])
					j += 1
					k += 1	
		else:
			if(matrix1[i][0] < matrix2[j][0]):
				matrix3.append([matrix1[i][0],matrix1[i][1],matrix1[i][2]])
				k += 1
				i += 1
			else :
				matrix3.append([matrix2[j][0],matrix2[j][1],matrix2[j][2]])
				k += 1
				j += 1
	if i < n:
		for x in range(i,n):
			matrix3.append(matrix1[x])
			k += 1
	if j < n:
		for x in range(j,n):
			matrix3.append(matrix2[x])
			k += 1
	matrix3[0][2] = k-1
	return matrix3


def simpleTranspose(matrix):
	n = matrix[0][2]+1
	matrix2 = []
	matrix2.append([matrix[0][1],matrix[0][0],matrix[0][2]])
	for i in range(matrix[0][1]):
		for j in range(1,n):
			if matrix[j][1] == i:
				list = [matrix[j][1],matrix[j][0],matrix[j][2]]
				matrix2.append(list)
	return matrix2
				
def fastTranspose(matrix):
	n = matrix[0][2]+1	
	matrix2 = [[0]]*(n)
	matrix2[0] = [matrix[0][1],matrix[0][0],matrix[0][2]]
	total = [0]*(matrix[0][1])
	index = [0]*(len(total)+1)
	index[0] = 1
	for i in range(matrix[0][1]):
		c = 0;
		for j in range(1,n):
			if matrix[j][1] == i:
				c += 1
		total[i] = c
	for i in range(1,matrix[0][1]+1):
		index[i] = index[i-1]+total[i-1]
	for i in range(1,n):
		loc = index[matrix[i][1]]
		matrix2[loc] = [matrix[i][1],matrix[i][0],matrix[i][2]]
		index[matrix[i][1]] += 1
	return matrix2
		

def putData(matrix):
	r = int(input("Enter no. of rows: "))
	c = int(input("Enter no. of columns: "))
	n = int(input("Enter no. of non-zero elements: "))
	matrix.append([r,c,n])
	print("Now give the input in the sparse matrix:(Row, Column, Element)")
	for i in range(n):
		list = []
		row = int(input())
		list.append(row)
		col = int(input())
		list.append(col)
		elm = int(input())
		list.append(elm)
		matrix.append(list)
	

def display(matrix):
	print("Row          Column       Element")
	for i in matrix:
		for j in i:
			print("",j,end = "            ")
		print()


print("Menu:\n1. Simple Transpose\n2. Fast Transpose\n3. Addition of two sparse matrices\n4. Exit")
while(1):
	print("Enter choice: ")
	ch = int(input())
	if ch == 1:
		matrix = []
		putData(matrix)
		matrix2 = simpleTranspose(matrix)
		print("Simple Transpose: ")
		display(matrix2)
	elif ch == 2:
		matrix = []
		putData(matrix)
		matrix2 = fastTranspose(matrix)
		print("Fast Transpose: ")
		display(matrix2)
	elif ch == 3:
		matrix1 = []
		matrix2 = []
		putData(matrix1)
		putData(matrix2)
		matrix3 = add(matrix1,matrix2)
		print("Addition of matrix1 and matrix2: ")
		display(matrix3)
	elif ch == 4:
		print("----EXITTING-------")
		exit()

