sem_prime = 294199324249
from random import randint
finder = []
def random_num(n):
    range_start = 10**(n-1)
    range_end = (10**n)-1
    return randint(range_start, range_end)
if len(str(sem_prime))%2==0:
	l_p = len(str(sem_prime))//2
else:
	l_p = (len(str(sem_prime))+1)//2
arr = [[-1, random_num(2*l_p)] for i in range(1000)]
#print(arr)
def odd_checker(arr):
	for i in arr:
		if i[1]%10 in {0, 2, 4, 6, 8}:
			i[1]+=1

		if str(i[1])[2] in {0, 2, 4, 6, 8}:
			i[1]+= 10**(l_p)
odd_checker(arr)


def fitness_val(arr):
	for i in arr:
		val = int(str(i[1])[0:l_p])*int(str(i[1])[l_p:2*l_p])
		i[0] = val-sem_prime
		if i[0] ==0 and len(finder)==0:
			finder.append(i[0])

fitness_val(arr)

def crossover(arr):
	for i in range(len(arr)//2):
		if int(str(arr[i][1])[0:l_p]) >= int(str(arr[i][1])[l_p:2*l_p]) and int(str(arr[len(arr)-1-i][1])[0:l_p]) >= int(str(arr[len(arr)-1-i][1])[l_p:2*l_p]):
			temp1 = int(str(arr[len(arr)-i-1][1])[0:l_p]+ str(arr[i][1])[l_p:2*l_p])
			temp2 = int(str(arr[i][1])[0:l_p]+ str(arr[len(arr)-i-1][1])[l_p:2*l_p])
			arr[i][1] = temp1
			arr[len(arr)-i-1][1] = temp2

		elif int(str(arr[i][1])[0:l_p]) <= int(str(arr[i][1])[l_p:2*l_p]) and int(str(arr[len(arr)-1-i][1])[0:l_p]) <= int(str(arr[len(arr)-1-i][1])[l_p:2*l_p]):
			temp1 = int(str(arr[len(arr)-i-1][1])[0:l_p]+ str(arr[i][1])[l_p:2*l_p])
			temp2 = int(str(arr[i][1])[0:l_p]+ str(arr[len(arr)-i-1][1])[l_p:2*l_p])
			arr[i][1] = temp1
			arr[len(arr)-i-1][1] = temp2

		else:
			temp1 = int(str(arr[len(arr)-i-1][1])[0:l_p]+ str(arr[i][1])[0:l_p])
			temp2 = int(str(arr[i][1])[l_p:2*l_p]+ str(arr[len(arr)-i-1][1])[l_p:2*l_p])
			arr[i][1] = temp1
			arr[len(arr)-i-1][1] = temp2
	odd_checker(arr)
	fitness_val(arr)
def Rand(start, end, num): 
    res = [] 
  
    for j in range(num): 
        res.append(randint(start, end)) 
  
    return res 

def mutation(arr):
	for i in range(len(arr)):
		if abs(arr[i][0])<0.0001*sem_prime:
			if arr[i][0] >0:
				a = list(map(lambda x:int(x), list(str(arr[i][1]))))
				for j in range(2,len(a)//2,2):
					if a[j]!=0:
						a[j]-=1
					else:
						a[j]+=1
					
				for j in range(3,len(a)//2,2):
					if a[j]!=9:
						a[j]+=1
					else:
						a[j]-=1
				for j in range(len(a)//2+2, len(a), 2):
					if a[j]!=0:
						a[j]-=1
					else:
						a[j]+=1
				for j in range(len(a)//2+3, len(a), 2):
					if a[j]!=9:
						a[j]+=1
					else:
						a[j]-=1
				b = list(map(lambda x:str(x), a))
				c = int("".join(b))
				arr[i][1] = c
			elif arr[i][0]<0:
				a = list(map(lambda x:int(x), list(str(arr[i][1]))))
				for j in range(2,len(a)//2,2):
					if a[j]!=9:
						a[j]+=1
					else:
						a[j]-=1
					
				for j in range(3,len(a)//2,2):
					if a[j]!=0:
						a[j]-=1
					else:
						a[j]+=1
				for j in range(len(a)//2+2, len(a), 2):
					
					if a[j]!=9:
						a[j]+=1
					else:
						a[j]-=1
				for j in range(len(a)//2+3, len(a), 2):
					if a[j]!=0:
						a[j]-=1
					else:
						a[j]+=1
				b = list(map(lambda x:str(x), a))
				c = int("".join(b))
				arr[i][1] = c

		elif abs(arr[i][0])<0.001*sem_prime:
			if arr[i][0] >0:
				a = list(map(lambda x:int(x), list(str(arr[i][1]))))
				for j in range(1,len(a)//2,2):
					if a[j]!=0:
						a[j]-=1
					else:
						a[j]+=1
					
				for j in range(2,len(a)//2,2):
					if a[j]!=9:
						a[j]+=1
					else:
						a[j]-=1
				for j in range(len(a)//2+1, len(a), 2):
					if a[j]!=0:
						a[j]-=1
					else:
						a[j]+=1
				for j in range(len(a)//2+2, len(a), 2):
					if a[j]!=9:
						a[j]+=1
					else:
						a[j]-=1
				b = list(map(lambda x:str(x), a))
				c = int("".join(b))
				arr[i][1] = c
			elif arr[i][0]<0:
				a = list(map(lambda x:int(x), list(str(arr[i][1]))))
				for j in range(1,len(a)//2,2):
					if a[j]!=9:
						a[j]+=1
					else:
						a[j]-=1
					
				for j in range(2,len(a)//2,2):
					if a[j]!=0:
						a[j]-=1
					else:
						a[j]+=1
				for j in range(len(a)//2+1, len(a), 2):
					
					if a[j]!=9:
						a[j]+=1
					else:
						a[j]-=1
				for j in range(len(a)//2+2, len(a), 2):
					if a[j]!=0:
						a[j]-=1
					else:
						a[j]+=1
				b = list(map(lambda x:str(x), a))
				c = int("".join(b))
				arr[i][1] = c
		else:
			if arr[i][0] >0:
				a = list(map(lambda x:int(x), list(str(arr[i][1]))))
				for j in range(0,len(a)//2,2):
					if a[j]!=0:
						if j==0 and a[j]==1:
							a[j]+=1
						else:
							a[j]-=1
					else:
						a[j]+=1
					
				for j in range(1,len(a)//2,2):
					if a[j]!=9:
						a[j]+=1
					else:
						a[j]-=1
				for j in range(len(a)//2, len(a), 2):
					if a[j]!=0:
						if j==len(a)//2 and a[j]==1:
							a[j]+=1
						else:
							a[j]-=1
					else:
						a[j]+=1
				for j in range(len(a)//2+1, len(a), 2):
					if a[j]!=9:
						a[j]+=1
					else:
						a[j]-=1
				b = list(map(lambda x:str(x), a))
				c = int("".join(b))
				arr[i][1] = c
			elif arr[i][0]<0:
				a = list(map(lambda x:int(x), list(str(arr[i][1]))))
				for j in range(0,len(a)//2,2):
					if a[j]!=9:
						a[j]+=1
					else:
						a[j]-=1
					
				for j in range(1,len(a)//2,2):
					if a[j]!=0:
						a[j]-=1
					else:
						a[j]+=1
				for j in range(len(a)//2, len(a), 2):
					
					if a[j]!=9:
						a[j]+=1
					else:
						a[j]-=1
				for j in range(len(a)//2+1, len(a), 2):
					if a[j]!=0:
						a[j]-=1
					else:
						a[j]+=1
				b = list(map(lambda x:str(x), a))
				c = int("".join(b))
				arr[i][1] = c
	odd_checker(arr)
	fitness_val(arr)
n = 5000
iter_num = 0
while iter_num <=n:
	mutation(arr)
	arr.sort()
	crossover(arr)
	mutation(arr)
	iter_num+=1
arr.sort()
print(arr)
print(finder)