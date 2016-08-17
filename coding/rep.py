'''
def repeat(name,n):
	for i in range(n):
		print name

def main():
	if name=='dev':
		print repeat(name,2)
	else:
		print repeet(name,1)

	



name="devd"
main()
'''


def repeat(s, exclaim):
    """
    Returns the string 's' repeated 3 times.
    If exclaim is true, add exclamation marks.
    """

    result = s + s + s # can also use "s * 3" which is faster (Why?)
    if exclaim:
        result = result + '!!!'
    return result

name='Guido'

def main():
    if name == 'Guido':
        print repeeeet(name,'!') + '!!!'
    else:
        print repeat(name,'!')
   

main()