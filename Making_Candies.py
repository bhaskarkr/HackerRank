import sys
import math
prev=sys.maxsize
d=0
m,w,p,C=[int(x) for x in input().split()]
c = 0
while(c<C):
    k=math.ceil((p-c)/(w*m))
    if k>0:
        c+=k*w*m
        d+=k
    else:
        d+=1
        t = c//p + m + w
        c = c%p
        if(w>m):
            w = max(w,t//2)
            m = t - w
        else:            
            m = max(m,t//2)
            w = t - m
        c += w * m
    prev=min(prev,d+math.ceil((C-c)/(w*m)))
print(min(prev,d))

