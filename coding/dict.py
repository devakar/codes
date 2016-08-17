
from operator import itemgetter

ds=[['a','2'],['b','1']]
for i in ds:
	i[1]=int(i[1])

print(type(ds[0][0]))

for line in sorted(ds, key=itemgetter(1), reverse= False): print "%s, %d"% (line[0], line[-1])