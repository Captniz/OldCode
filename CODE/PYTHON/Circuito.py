y=False
x0=False
x1=False
x2=False
x0=bool(int(input("X0=")))
x1=bool(int(input("X1=")))
x2=bool(int(input("X2=")))

#y= x0  *  not(x2) +  (not(x0 +  x1) *   x1 *   not(x2))

if  x0 and not(x2) or (not(x0 or x1) and x1 and not(x2)):
    y=True

print(y)