N = int(input())
l = []
while N>0:
    tmp = int(N % 10)
    l.append(tmp)
    N = int((N - tmp)/10)

l.sort()

print (l)
