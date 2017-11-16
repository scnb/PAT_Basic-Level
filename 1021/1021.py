l = []

l = list(input())


l.sort()
print (l)
res = {}
for i in l:
    res[i] = res.get(i,0)+1

for k in res.keys():
    print (str(k)+":"+str(res[k]))

#print ([k for k in res.keys()])
#print ([v for v in res.values()])

