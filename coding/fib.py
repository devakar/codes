def fib(n):
	if n==1:
		return 1
	elif n==0:
		return 0;
	else:
		return (fib(n-1)+fib(n-2))



for i in range(10):
	print fib(i)

	    