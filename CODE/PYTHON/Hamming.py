import math
ADDON=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
bit=input("BIT?:")
BIT=list(bit)
BITC=[]

i=0
result=0
count=0
som=0
c=0
pow2=0
coeff=0

if BIT.count("1") + BIT.count("0") != len(bit):
    while True:
        print("error")

while pow2<len(bit):
    pow2=pow(2,coeff)
    if pow2<len(bit):
        BITC.append(pow2-1)
        coeff+=1

for element in BITC:
    BIT.insert(element, 0)

truelen=len(bit)+len(BITC)
BIT.extend(ADDON)

for element in BITC:

    #element=1
    count=element+1
    #count=2
    a=element
    b=element+count
    #a=1
    #b=3

    for element in BIT[a:b]:

        som=som + int(element)
         #[1:3]

    while b<truelen:

        a=b+count
        #a=3+2=5

        b=a+count
        #b=5+2=7

        for element in BIT[a:b]:
            som=som + int(element)
            #[5:7]

    if som%2==0 or som==0:
        result=0
    else: 
        result=1
    
    BIT[int(BITC[i])]=result
    i+=1
    som=0
    result=0

print(BIT[0:truelen])

input()


"""
som=BIT[0:1]
som=BIT[2:3]
som=BIT[4:5]

som=BIT[1:3]
som=BIT[5:7]
som=BIT[9:11]

som=BIT[3:7]
som=BIT[11:15]
som=BIT[19:23]

som=BIT[7:15]
som=BIT[23:31]
som=BIT[39:47]
"""
