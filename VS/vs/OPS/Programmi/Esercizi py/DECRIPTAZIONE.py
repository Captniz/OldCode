#Alfabeto
Alfa=('a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z')

q=int(input("1.Vignere criptazione\n2.Standard Criptazione\n3.Standard Decriptazione\n4.Criptazione Cesare\n5.Decriptazione Cesare\n"))

while q!=1 and q!=2 and q!=3 and q!=4 and q!=5:
    print("Errore")
    q=int(input("1.Vignere criptazione\n2.Standard\n3.Standard Criptazione\n4.Criptazione Cesare\n5.Decriptazione Cesare\n"))

if q==1:        

    #Variabili+input
    i=0
    Res=""
    p = str(input("\n\nparola:"))
    c = str(input("(gia scritta piu' volte nel caso sia piu' corta della parola)\nchiave:"))
    r = int(input("\nripetizioni:"))
    
    #Calcolo
    while i<len(c):
        Res=str(Alfa[((r*int(Alfa.index(c[i])))%26)+int(Alfa.index(p[i]))])
        print(Res)
        i+=1

    input("\n\n\nEnter per terminare.....")

elif q==2:

    v=0
    w=0
    p = str(input("\n\nparola:"))
    c = str(input("\nchiave:"))
    r = int(input("\nripetizioni:"))

    Chiave=list(c)
    Parola=list(p)

    while w<r:
        v=0
        while v<len(p):
            Parola[v]=Chiave[int(Alfa.index(Parola[v]))]
            v+=1
        w+=1

    print(Parola)
    input("\n\n\nEnter per terminare.....")

elif q==3:

    v=0
    w=0
    p = str(input("\n\nparola:"))
    c = str(input("\nchiave:"))
    r = int(input("\nripetizioni:"))

    Chiave=list(c)
    Parola=list(p)

    while w<r:
        v=0
        while v<len(p):
            Parola[v]=Alfa[int(Chiave.index(Parola[v]))]
            v+=1
        w+=1

    print("".join(Parola))
    input("\n\n\nEnter per terminare.....")

elif q==4:

    v=0
    w=0
    p = str(input("\n\nparola:"))
    c = int(input("\nchiave:"))
    r = int(input("\nripetizioni:"))
    
    Parola=list(p)

    while w<r:
        v=0
        while v<len(p):
            Parola[v]=Alfa[int(Alfa.index(Parola[v])) + c]
            v+=1
        w+=1

    print("".join(Parola))
    input("\n\n\nEnter per terminare.....")

elif q==5:

    v=0
    w=0
    p = str(input("\n\nparola:"))
    c = int(input("\nchiave:"))
    r = int(input("\nripetizioni:"))
    
    Parola=list(p)

    while w<r:
        v=0
        while v<len(p):
            Parola[v]=Alfa[int(Alfa.index(Parola[v])) + 52 - c]
            v+=1
        w+=1

    print("".join(Parola))
    input("\n\n\nEnter per terminare.....")  
