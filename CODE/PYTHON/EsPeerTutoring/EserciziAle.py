import math

#EsPeerTutoring/1.jpg
#1 #TODO: Matematica di base
def es1():
    raggio = int(input("Raggio:"))
    print(f"L'area del cerchio e' {math.pi * (raggio ** 2)}")

#2
def es2():
    num = float(input("Numero:"))
    #print(f"Assoluto {abs(num)}") # <-- Modo migliore ma non so se lo avete visto
    if num < 0:
        print(f"Assoluto {-num}")
    else:
        print(f"Assoluto {num}")

#3
def es3():
    num = int(input("Eta:"))
    # Sarebbe da controllare anche se e' maggiore di zero e minore di 120 ma non e' richiesto
    if num < 18:
        print(f"Minorenne")
    else:
        print(f"Maggiorenne")  
        
#4 #TODO: If con condizioni interessanti
def es4():
    angolo = int(input("Angolo:"))
    if angolo < 0 or angolo > 180: # <-- Prima questo per verificare che sia un angolo
        print(f"Errore")
    elif angolo == 90:  
        print(f"Retto")
    elif angolo < 90:
        print(f"Acuto")
    else: #<-- Qui se ti senti piu sicuro puoi fare la condizione angolo > 90
        print(f"Ottuso")

#5 #TODO: Matematica più figa
def es5():
    # L'unico di cui non sono sicuro da un punto di vista matematico
    ipotenusa = int(input("Ipotenusa:"))
    ipotenusa = (ipotenusa ** 2) / 25 # <-- 16 + 9 = 25 
    cateto1 = math.sqrt(ipotenusa * 16) 
    cateto2 = math.sqrt(ipotenusa * 9)
    print(f"Cateto 1: {cateto1}")
    print(f"Cateto 2: {cateto2}")
    
#6 #TODO: If con condizioni interessanti
def es6():
    lato1 = int(input("Lato1:"))
    lato2 = int(input("Lato2:"))
    lato3 = int(input("Lato3:"))
    
    if lato1 == lato2:
        if lato1 == lato3:
            print(f"Equilatero")
        else:
            print(f"Isoscele")
    elif lato1 == lato3:
        print(f"Isoscele")
    elif lato2 == lato3:
        print(f"Isoscele")
    else:
        print(f"Scaleno")
        
#7
def es7():
    # Es un po strano perche' e' un cazzo di calcolo e lo puoi fare a mente ma va bene    
    print(f"MB necessari: {(1920*1080*24)/8}")
    
#8 #TODO: Ordinamento dei numeri
def es8(): 
    num1 = float(input("Num1:"))
    num2 = float(input("Num2:"))
    num3 = float(input("Num3:"))
    
    # Si potrebbe usare un sort o cose cosi ma non so se le avete viste
    
    if num1 > num2:
        if num2 > num3:
            print(f"{num1}, {num2}, {num3}")
        elif num3 > num1:
            print(f"{num3}, {num1}, {num2}")
        else:
            print(f"{num1}, {num3}, {num2}")
    elif num2 > num3:
        if num1 > num3:
            print(f"{num2}, {num1}, {num3}")
        else:
            print(f"{num2}, {num3}, {num1}")
    else:
        print(f"{num3}, {num2}, {num1}")
    
#9
def es9():
    a = int(input("A:"))
    b = int(input("B:"))
    c = int(input("c:"))
    
    if (b**2 - (4*a*c)) < 0:
        print("Sei scemo")
        return # <-- utilizzabile un else o roba cosi, non so se avete gia visto il return
    
    # Lo metto qua pk se no ti si incrociano gli occhi a gurarlo nel print e diventi deficente a corrggere gli errori
    
    risultato = (-b + math.sqrt(b**2 - (4*a*c))) / (2*a)
    print(f"Risultato 1: {risultato}")
    
    risultato = (-b - math.sqrt(b**2 - (4*a*c))) / (2*a)
    print(f"Risultato 2: {risultato}")
    
#10 #TODO: Problema complesso, se su carta lo stendimento del codice è diverso: meglio usare degli appunti o frasi sintetiche ( Top down )
def es10():
    # Per questo problema idealmente dovresti usare un do-while ma ho usato un while normale perchè dopo ci sono pure gli esercizi con do-while
    
    lato1 = int(input("Lato1:"))
    lato2 = int(input("Lato2:"))
    lato3 = int(input("Lato3:"))
    flag = True
    
    # Per il controllo o metti tutto in due while per l'ordine o fai una flag e un if nel while (meglio)
    while flag:
        
        print("Errore")
        lato1 = int(input("Lato1:"))
        lato2 = int(input("Lato2:"))
        lato3 = int(input("Lato3:"))
        
        if lato1 < 0 or lato2 < 0 or lato3 < 0:
            flag = True
        else:
            if lato1 + lato2 < lato3:
                flag = True
            elif lato1 + lato3 < lato2:
                flag = True
            elif lato2 + lato3 < lato1:
                flag = True
            else:
                flag = False
    
    p = (lato1 + lato2 + lato3)/2 
    
    print(f"Area {math.sqrt(p*(p-lato1)*(p-lato2)*(p-lato3))}")
    
#EsPeerTutoring/2.jpg
#1 #TODO: Primo esempio di un for
def es11():
    num = int(input("Numero:"))
    for x in range(0, num): #<-- Attento al range: Il punto di inizio è compreso mentre la fine è esclusa > [inizio,fine)
        print(f"Ciao ")
    print("Fine")
 
#2
def es12():
    num = int(input("Numero:"))
    for x in range(0, num):
        if x % 2 == 0:
            print(f"{x} Pari")
        else:
            print(f"{x} Dispari")
    print("Fine")
    
#3
def es13():
    num = int(input("Numero:"))
    for x in range(0, num+1):
        if (num%x==0):
            print(f"{x} E' divisore")
 
#4 #TODO: Ragionamento interessante per il countdown
def es14():
    num = int(input("Numero:"))
    for x in range(0, num+1):
        print(f"{num-x}")
    print("Fine")

#5
def es15():
    num = int(input("Numero:"))
    k = int(input("Numero di multipli:"))
    for x in range(1, k+1):
        print(f"{x*num}")
    print("Fine")
    
#6 
def es16():
    num = int(input("Numero:"))
    risultato = 0
    for x in range(1, num+1):
        risultato += x
    print(f"Risultato: {risultato}")    
    print("Fine")
    
#7
def es17():
    num = int(input("Numero:"))
    risultato = 1
    for x in range(1, num+1):
        risultato *= x
    print(f"Risultato: {risultato}")    
    print("Fine")

#8
def es18():
    num = int(input("Numero:"))
    risultato = 0
    for x in range(1, num+1):
        print(f"{x}^2 = {x**2}")
        risultato += x**2
    print(f"Risultato: {risultato}")    
    print("Fine")

#9
def es19():
    num = int(input("Numero:"))
    num2 = int(input("Numero2:"))
    risultato = 0
    for x in range(num, num2+1):
        if x % 2 == 0:
            risultato += x
    print(f"Risultato: {risultato}")    
    print("Fine")
    
#10
def es20():
    num = int(input("Numero:"))
    risultato = 0
    for x in range(1, num+1):
        risultato += (1/x)
    print(f"Risultato: {risultato}")    
    print("Fine")
    
#11
def es21():
    num = int(input("Numero:"))
    risultato = 0
    for x in range(1, num+1):
        if x % 2 == 0:
            risultato -= (1/x)
        else:
            risultato += (1/x)
    print(f"Risultato: {risultato}")    
    print("Fine")

#12
def es22():
    num = int(input("Numero:"))
    risultato = 0
    for x in range(1, num):
        if (num%x==0):
            risultato += x
    if risultato == num:
        print(f"Numero perfetto")
    else:
        print(f"Numero non perfetto")
    print("Fine")
    
#EsPeerTutoring/3.jpg
#13
def es23():
    num = int(input("Numero:"))
    flag = False
    for x in range(2, num):
        if (num%x==0):
            flag = True
            # print(f"Non primo") # <-- Modo migliore ma non so se lo avete visto
            # return
    if flag:
        print(f"Numero non primo")
    else:
        print(f"Numero primo")
    print("Fine")

#14 #TODO: Ragionamento interessante con if
def es24():
    num = int(input("Numero:"))
    for x in range(1, num+1):
        if (x%3==0):
            if (x%5==0):
                print("FizzBuzz, ")
            else:
                print("Fizz, ")
        elif (x%5==0):
            if (x%3==0):
                print("FizzBuzz, ")
            else:
                print("Buzz, ")
        else:
            print(f"{x}, ")

#15
def es25():
    num1 = int(input("Numero1:"))
    num2 = int(input("Numero2:"))
    
    while num1<0 or num2<0:
        print("Errore")
        num1 = int(input("Numero1:"))
        num2 = int(input("Numero2:"))
    risultato = 1 # <-- 0 * x = 0 quindi 1
        
    for x in range(0, num2):
        risultato *= num1
    
    print(f"Risultato: {risultato}")
        
#16
def es26():
    num = int(input("Numero di valori:"))
    media = 0
    for x in range(0, num):
        media += float(input(f"Numero {x+1}:"))
    media /= num
    print("Fine")

#17 #TODO: Primo esempio di do-while
def es27():
    #DO
    while 1: # <-- la mia versione, non ho idea di comne lo vogliate voi
        num = int(input("Numero:"))
        
        #WHILE
        if num > 100 and num%2==0:
            break
        else:
            continue
        
    print("Fine")

#18
def es28():
    # Questo esercizio ha la consegna scritta di merda quindi la cambio in queso modo:
    
    # La macchinetta accetta solo monete da 5, 10, 20, 50 centesimi, l'obbiettivo e' di raggiungere i 5 euro
    # inserendo le monete, ovviamente le monete diverse da quelle indicate vengono scartate. 
    # Inoltre facciamo che i cent in input devono essere inseriti come float.
    # Usa il do-while.
    
    obiettivo = 5.0
    
    #DO
    while 1: 
        num = float(input("Moneta ( Inserita come float per i centesimi ): "))
        
        #WHILE
        if num != 0.05 and num != 0.10 and num != 0.20 and num != 0.50:
            print("Moneta scartata")
            continue
        else:
            obiettivo -= num
            print(f"Saldo mancante: {obiettivo}")
            if obiettivo <= 0:
                break
            continue
        
    print("Fine")
    
#19 #TODO: Problema complesso, se su carta lo stendimento del codice è diverso: meglio usare degli appunti o frasi sintetiche ( Top down )

def es29():
    
    while 1: 
        # Anche qua ci sarebbe una soluzione migliore con i dizionari ma non la sto neanche a scrivere pk non penso la facciante neanche
        # in quinta, scrivo questo commento solo perche' mi piace scrivere cose inutili
        selezione = int(input(f"Prodotti disponibili:\n1 - Acqua 0.50 euro\n2 - Lattina 0.80 euro\n3 - Bottiglietta 1.00 euro\nSelezione: "))
        
        if selezione > 3 or selezione < 1: 
            print("Non esiste")
            continue
        else:
            if selezione == 1:
                obiettivo = 50
            elif selezione == 2:
                obiettivo = 80
            else:
                obiettivo = 100
            break
    
    while obiettivo > 0:
        print(f"Saldo mancante: {obiettivo}")
        num = int(input("Centesimi: "))
        
        # cents = (5,10,20,50,100,200) <-- Modo migliore ma non so se lo avete visto
        # if num not in cents:
        if num != 5 and num != 10 and num != 20 and num != 50 and num != 100 and num != 200: 
            print("Moneta scartata")
            continue
        else:
            obiettivo -= num
            continue
    
    print("Prodotto erogato")
    if obiettivo < 0:
        print(f"Resto: {-obiettivo}")
    print("Fine")

def es29for():

    selezione = int(input(f"Prodotti disponibili:\n1 - Acqua 0.50 euro\n2 - Lattina 0.80 euro\n3 - Bottiglietta 1.00 euro\nSelezione: "))

    # Controllo selezione
    while selezione>3 and selezione<1:
        selezione = int(input(f"Prodotti disponibili:\n1 - Acqua 0.50 euro\n2 - Lattina 0.80 euro\n3 - Bottiglietta 1.00 euro\nSelezione: "))

    #Conversione a prezzo
    prezzo=0;
    if(selezione==1):
        prezzo = 50
    elif(selezione==2):
        prezzo=80
    else:
        prezzo=100

    soldi = 0
    while soldi<prezzo :
        c = int(input("Cents:"))

        # controllo monete giuste
        while c!=10 and c!= 20 and c!= 50 and c != 100 and c!= 200:
            print("pirla")
            c = int(input("Cents:"))

        soldi += c
        
    print("Resto",soldi-prezzo)


    '''
    selezione = int(input(f"Prodotti disponibili:\n1 - Acqua 0.50 euro\n2 - Lattina 0.80 euro\n3 - Bottiglietta 1.00 euro\nSelezione: "))

    while(selezione!=1 and selezione!= 2 and selezione!= 3):
        selezione = int(input(f"Prodotti disponibili:\n1 - Acqua 0.50 euro\n2 - Lattina 0.80 euro\n3 - Bottiglietta 1.00 euro\nSelezione: "))
    
    acconto=0
    if (selezione==1):
        acconto=50
    elif(selezione==2):
        acconto=80
    else:
        acconto=100
    

    while(acconto>0):
        c = int(input("Cents:"))
        while(c!=10 and c!= 20 and c!= 50 and c != 100 and c!= 200):
            c = int(input("Cents:"))
        
        acconto -= c
    
    
    print("Resto:", -acconto)
    '''

#main
def main():
    es29for() # <-- Cambiare esercizio

if __name__ == "__main__":
    main()
