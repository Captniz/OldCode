N = int(input("N:"))
ctr = 0

for i in range(N):
    for j in range(N):
        print(ctr, end=" ")
        ctr += 1
    print()