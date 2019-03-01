import re
#k = ["CHARGE: card_country=US&currency=USD&amount=150&ip_country=CA","ALLOW: amount < 100 AND amount > 50 OR currency != ME","BLOCK: card_country != ip_country AND amount > 100"]
k = [
  "CHARGE: card_country=US&currency=USD&amount=150&ip_country=CA",
  "ALLOW: amount < 100",
  "BLOCK: card_country != ip_country AND amount > 100",
]
names = re.findall("([a-z_]+)",k[0])
values = re.findall("([A-Z0-9]+)",k[0])
values.pop(0)
mm={}
for i in range(len(names)):
    if(names[i]=='amount'):
        mm[names[i]]=int(values[i])
    else:
        mm[names[i]]=values[i]
#print(mm)
con=k[1].split()
#print(con)
if(con[0]=='ALLOW:'):
    c=[]
    op = []
    con.pop(0)
    #print(con)
    i=0
    j=-1
    fin=True
    while i<len(con):
        if(con[i]=='amount'):
            con[i+2]=int(con[i+2])
            if con[i+1]=='<=':
                ans=(mm[con[i]]<con[i+2])
            elif con[i+1]=='>=':
                ans=(mm[con[i]]>con[i+2])
            elif con[i+1]=='=':
                ans=(mm[con[i]]==con[i+2])
            elif con[i+1]=='!=':
                ans=(mm[con[i]]!=con[i+2])
            elif con[i+1]=='<':
                ans=(mm[con[i]]<=con[i+2])
            elif con[i+1]=='>':
                ans=(mm[con[i]]>=con[i+2])
        else:
            if con[i+1]=='=':
                ans=(mm[con[i]]==con[i+2])
            elif con[i+1]=='!=':
                ans=(mm[con[i]]!=con[i+2])
        if len(op)==0:
            if not ans:
                print(0)
        elif(j>=0):
            if(op[j]=='AND'):
                fin&=ans
            else:
                fin|=ans
            j+=1
        else:
                j+=1
        if not fin:
            print(0)   
        #c.append([con[i],con[i+1],con[i+2]])
        #print(c[-1])
        i+=3
        if i < len(con):
            op.append(con[i])
            i+=1
fin = True
if(len(k)>1):
    con=k[2].split()
    con.pop(0)
    #print(con)
    i=0
    j=-1
    fin=True
    while i<len(con):
        if(con[i]=='amount'):
            con[i+2]=int(con[i+2])
            if con[i+1]=='<=':
                ans=(mm[con[i]]<con[i+2])
            elif con[i+1]=='>=':
                ans=(mm[con[i]]>con[i+2])
            elif con[i+1]=='=':
                ans=(mm[con[i]]==con[i+2])
            elif con[i+1]=='!=':
                ans=(mm[con[i]]!=con[i+2])
            elif con[i+1]=='<':
                ans=(mm[con[i]]<=con[i+2])
            elif con[i+1]=='>':
                ans=(mm[con[i]]>=con[i+2])
        else:
            if con[i+1]=='=':
                ans=(mm[con[i]]==con[i+2])
            elif con[i+1]=='!=':
                ans=(mm[con[i]]!=con[i+2])
        if len(op)==0:
            if not ans:
                print(1)
            else:
                print(0)
        elif(j>=0):
            if(op[j]=='AND'):
                fin&=(not ans)
            else:
                fin|=(not ans)
            j+=1
        else:
            j+=1
        if not fin:
            print(0)   
        #c.append([con[i],con[i+1],con[i+2]])
        #print(c[-1])
        i+=3
        if i < len(con):
            op.append(con[i])
            i+=1
        #print(i)
    #print(c)
    #print(op)