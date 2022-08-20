N = int(input())

X = 1 

flag = 0

while X < 10000000 :
	if X == N:
		X+=1 
		continue
	if X % N == 0:
		i = [int(a) for a in str(X)]
		j = sum(i)
		if j == N:
			print(X)
			flag=1 
			break 
	X+=1 

if flag == 0:
	print(-1) 