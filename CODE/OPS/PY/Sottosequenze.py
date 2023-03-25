import math

Seq= []
x=""
BufferString=""

while x!="stop":
    x=input("Elemento della lista:")
    if x!="stop":
        Seq.append(x)
    print(Seq)

for index, item in enumerate(Seq):
    if len(item)>=4 and item[:3]=="rad":
        print("Radice trovata")
        BufferString = item.replace('rad','')
        BufferString = int(math.sqrt(int(BufferString)))
        Seq[index] = BufferString
    elif len(item)>=4 and item[1:-1]=="fr":
        pass



print(Seq)