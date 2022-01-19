from random import * 
def main():
    T=[randint(65,90) for x in range (46)]
    print(T)

    for x in range (len(T)):
        if T.count(T[x])>1:
            T.remove(T[x])

    print(T)

main()

