import itertools
from sys import *
from numpy import *
from subprocess import call
from math import factorial 
'''
def list_powerset(lst):
    # the power set of the empty set has one element, the empty set
    result = [[]]
    for x in lst:
        # for every additional element in our set
        # the power set consists of the subsets that don't
        # contain this element (just take the previous power set)
        # plus the subsets that do contain the element (use list
        # comprehension to add [x] onto everything in the
        # previous power set)
        result.extend([subset + [x] for subset in result])
    return result
    
print list_powerset([1,2,3])
'''

'''
def k_subsets_i(n, k):
    
    #Yield each subset of size k from the set of intergers 0 .. n - 1
    #n -- an integer > 0
    #k -- an integer > 0
    
    # Validate args
    if n < 0:
        raise ValueError('n must be > 0, got n=%d' % n)
    if k < 0:
        raise ValueError('k must be > 0, got k=%d' % k)
    # check base cases
    if k == 0 or n < k:
        yield set()
    elif n == k:
        yield set(range(n))

    else:
        # Use recursive formula based on binomial coeffecients:
        # choose(n, k) = choose(n - 1, k - 1) + choose(n - 1, k)
        for s in k_subsets_i(n - 1, k - 1):
            s.add(n - 1)
            yield s
        for s in k_subsets_i(n - 1, k):
            yield s
            
for two in k_subsets_i(5,2):
    print two
    for i in two:
        print i
'''
matrix=[[0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1], [0,1,1,0,0,1,1,0,0,1,1,0,1,0,0,1,0,1,1,0,1,0,0,1,1,0,0,1,1,0,0,1], [0,0,0,1,0,0,0,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,1,1,1,0,1,1,1]]


def findsubsets(S,m):
    return list(itertools.combinations(S, m))

o=3
s=[]
for i in range(o):
    s.append(i)


'''
cor={}
for i in range(len(l)):
    cor[l[i]]=1

print cor
'''
maximum=0
if o>1:
    print "\nComputing correlation among outputs"
    corr={}
    outs=matrix[0:o]

    l=findsubsets(s,1)
    for one in l:
        corr[one]=1

    l= findsubsets(s,2)
    #print l
    for two in l:
        vout=[]
        for i in two:
            vout.append(outs[i])
        numerator=1
        denominator=1
        for k in range(len(vout)):
            numerator=numerator*(vout[k]-mean(vout[k]))
            denominator=denominator*var(vout[k])
        if denominator==0:
            corr[two]=0
        else:
            if(abs(mean(numerator)/denominator**0.5)>maximum and abs(mean(numerator)/denominator**0.5)<1 and abs(mean(numerator)/denominator**0.5)>0 ):
                maximum=abs(mean(numerator)/denominator**0.5)
            corr[two]=(mean(numerator)/denominator**0.5)
                #level=1/(-1*(1-maximum))
            level=1/(1-maximum)

    if level>2:
        for j in range(3,level+1):
            l=findsubsets(s,j)
            for size in l:
                vout=[]
                for i in two:
                    vout.append(outs[i])
                numerator=1
                denominator=1
                for k in range(len(vout)):
                    numerator=numerator*(vout[k]-mean(vout[k]))
                    denominator=denominator*var(vout[k])
                if denominator==0:
                    corr[two]=0
                else:
                    corr[two]=(mean(numerator)/denominator**0.5)
               
        
            
        


print level
print corr