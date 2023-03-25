from termcolor import colored

#Dati variabili
var1={"Nome":0, "opt1":0, "opt2":0, "opt3":0}
var2={"Nome":0, "opt1":0, "opt2":0, "opt3":0}
var3={"Nome":0, "opt1":0, "opt2":0, "opt3":0}

#Dati nomi
a={"Nome":0}
b={"Nome":0}
c={"Nome":0}

#Dati liste combinazioni
NegAttr = []
NegNomi = []
ComAttr = []
ComNomi = []
AttrEccesso = []
XAttrEccesso = []
VarTot = []

#Liste risultati
Combo1 = []
Combo2 = []
Combo3 = []

#Counter coppie variabili
NCoppieNV = 0
NCoppieVV = 0
NCoppieXNV = 0
NCoppieXVV = 0
TipoPresente = False

#Variabili counter/input
i=0
x="a"
q=0

#Inserimento dati variabili
var1["Nome"] = input("Nome // Variabile 1:")
var1["opt1"] = input("Opzione 1 // Variabile 1:")
VarTot.append(var1["opt1"])
var1["opt2"] = input("Opzione 2 // Variabile 1:")
VarTot.append(var1["opt2"])
var1["opt3"] = input("Opzione 3 // Variabile 1:")
VarTot.append(var1["opt3"])
print(colored('==========================================', 'green'))
var2["Nome"] = input("Nome // Variabile 2:")
var2["opt1"] = input("Opzione 1 // Variabile 2:")
VarTot.append(var2["opt1"])
var2["opt2"] = input("Opzione 2 // Variabile 2:")
VarTot.append(var2["opt2"])
var2["opt3"] = input("Opzione 3 // Variabile 2:")
VarTot.append(var2["opt3"])
print(colored('==========================================', 'green'))
var3["Nome"] = input("Nome // Variabile 3:")
var3["opt1"] = input("Opzione 1 // Variabile 3:")
VarTot.append(var3["opt1"])
var3["opt2"] = input("Opzione 2 // Variabile 3:")
VarTot.append(var3["opt2"])
var3["opt3"] = input("Opzione 3 // Variabile 3:")
VarTot.append(var3["opt3"])
print(colored('==========================================', 'green'))

#Inserimento dati nomi
a["Nome"] = input("1°persona:")
Combo1.append(a["Nome"])
b["Nome"] = input("2°persona:")
Combo2.append(b["Nome"])
c["Nome"] = input("3°persona:")
Combo3.append(c["Nome"])

#Inserimento combinazioni
print(colored('==========================================', 'green'))
print(colored('Scrivi prima nome e poi variabile', 'yellow'))
i = input("Esistono correlazioni tra nomi e variabili?    [" + colored('1 Si', 'cyan') + " / " + colored('0 No', 'red') +"]:")

while i=="1":    
    NCoppieNV+=1
    x = input("Prima variabile:")
    ComNomi.append(x)
    x = input("Seconda variabile:")
    ComNomi.append(x)
    VarTot.remove(x)
    i = input("Fine?    [" + colored('0 Si', 'cyan') + " / " + colored('1 No', 'red') +"]:")

print(colored('==========================================', 'green'))
i = input("Esistono correlazioni tra variabili?    [" + colored('1 Si', 'cyan') + " / " + colored('0 No', 'red') +"]:")

while i=="1":
    NCoppieVV+=1
    x = input("Prima variabile:")
    ComAttr.append(x)
    x = input("Seconda variabile:")
    ComAttr.append(x) 
    i = input("Fine?    [" + colored('0 Si', 'cyan') + " / " + colored('1 No', 'red') +"]:")

print(colored('==========================================', 'green'))
print(colored('Scrivi prima nome e poi variabile', 'yellow'))
i = input("Esistono negazioni tra nomi e variabili?    [" + colored('1 Si', 'cyan') + " / " + colored('0 No', 'red') +"]:")

while i=="1":    
    NCoppieXNV+=1
    x = input("Prima variabile:")
    NegNomi.append(x)
    x = input("Seconda variabile:")
    NegNomi.append(x)
    i = input("Fine?    [" + colored('0 Si', 'cyan') + " / " + colored('1 No', 'red') +"]:")

print(colored('==========================================', 'green'))
i = input("Esistono negazioni tra variabili?    [" + colored('1 Si', 'cyan') + " / " + colored('0 No', 'red') +"]:")

while i=="1":
    NCoppieXVV+=1
    x = input("Prima variabile:")
    NegAttr.append(x)
    x = input("Seconda variabile:")
    NegAttr.append(x)
    i = input("Fine?    [" + colored('0 Si', 'cyan') + " / " + colored('1 No', 'red') +"]:")


#Analisi combinazioni nomi

while q!=NCoppieNV:
    if Combo1.count(ComNomi[0])==1:
        Combo1.append(ComNomi[1])
        del ComNomi[0:2]
    elif Combo2.count(ComNomi[0])==1:
        Combo2.append(ComNomi[1])
        del ComNomi[0:2]
    elif Combo3.count(ComNomi[0])==1:
        Combo3.append(ComNomi[1])
        del ComNomi[0:2]
    q+=1
q=0

#Analisi combinazioni variabili 

while q!=NCoppieVV:
    if Combo1.count(ComAttr[0])==1:
        Combo1.append(ComAttr[1])
        VarTot.remove(ComAttr[1])
        del ComAttr[0:2]
    elif Combo1.count(ComAttr[1])==1:
        Combo1.append(ComAttr[0])
        VarTot.remove(ComAttr[0])
        del ComAttr[0:2]
    elif Combo2.count(ComAttr[0])==1:
        Combo2.append(ComAttr[1])
        VarTot.remove(ComAttr[1])
        del ComAttr[0:2]
    elif Combo2.count(ComAttr[1])==1:
        Combo2.append(ComAttr[0])
        VarTot.remove(ComAttr[0])
        del ComAttr[0:2]
    elif Combo3.count(ComAttr[0])==1:
        Combo3.append(ComAttr[1])
        VarTot.remove(ComAttr[1])
        del ComAttr[0:2]
    elif Combo3.count(ComAttr[1])==1:
        Combo3.append(ComAttr[0])
        VarTot.remove(ComAttr[0])
        del ComAttr[0:2]
    else:
        AttrEccesso.append(ComAttr[0:2])
        del ComAttr[0:2]
    q+=1
q=0

#Analisi negazioni nomi 

while q!=NCoppieXNV: 
    if Combo1.count(NegNomi[0])==1:
        Combo1.append("NOT" + NegNomi[1])
        del NegNomi[0:2]
    elif Combo2.count(NegNomi[0])==1:
        Combo2.append("NOT" + NegNomi[1])
        del NegNomi[0:2]
    elif Combo3.count(NegNomi[0])==1:
        Combo3.append("NOT" + NegNomi[1])
        del NegNomi[0:2]
    q+=1
q=0

#Analisi negazioni variabili 

while q!=NCoppieXVV:
    if Combo1.count(NegAttr[0])==1:
        Combo1.append("NOT" + NegAttr[1])
        del NegAttr[0:2]
    elif Combo1.count(NegAttr[1])==1:
        Combo1.append("NOT" + NegAttr[0])
        del NegAttr[0:2]
    elif Combo2.count(NegAttr[0])==1:
        Combo2.append("NOT" + NegAttr[1])
        del NegAttr[0:2]
    elif Combo2.count(NegAttr[1])==1:
        Combo2.append("NOT" + NegAttr[0])
        del NegAttr[0:2]
    elif Combo3.count(NegAttr[0])==1:
        Combo3.append("NOT" + NegAttr[1])
        del NegAttr[0:2]
    elif Combo3.count(NegAttr[1])==1:
        Combo3.append("NOT" + NegAttr[0])
        del NegAttr[0:2]
    else:
        XAttrEccesso.append(NegAttr[0:2])
        del NegAttr[0:2]
    q+=1
q=0 

#Analisi var non assegnate in varTot

for elements in VarTot:
    #Controllo gruppo di variabili dell'elemento
    TipoPresente=False
    if var1.count(elements)==1:
        #Controllo presenza negazione della variabile
        if Combo1.count("NOT"+elements)==0:
            #Controllo presenza altri elementi del gruppo dell'elemento
            for elements in var1:
                if Combo1.count(elements)==1:
                    TipoPresente=True
            #Controllo verità presenza altri elementi del gruppo dell'elemento
            if TipoPresente==False:
                #Scrittura
                Combo1.append(elements)
                VarTot.remove(elements)
        TipoPresente=False
        #Controllo presenza negazione della variabile
        if Combo2.count("NOT"+elements)==0:
            #Controllo presenza altri elementi del gruppo dell'elemento
            for elements in var1:
                if Combo2.count(elements)==1:
                    TipoPresente=True
            #Controllo verità presenza altri elementi del gruppo dell'elemento
            if TipoPresente==False:
                #Scrittura
                Combo2.append(elements)
                VarTot.remove(elements)
        TipoPresente=False
        #Controllo presenza negazione della variabile
        if Combo3.count("NOT"+elements)==0:
            #Controllo presenza altri elementi del gruppo dell'elemento
            for elements in var1:
                if Combo3.count(elements)==1:
                    TipoPresente=True
            #Controllo verità presenza altri elementi del gruppo dell'elemento
            if TipoPresente==False:
                #Scrittura
                Combo3.append(elements)
                VarTot.remove(elements)
    TipoPresente=False
    if var2.count(elements)==1:
        #Controllo presenza negazione della variabile
        if Combo1.count("NOT"+elements)==0:
            #Controllo presenza altri elementi del gruppo dell'elemento
            for elements in var2:
                if Combo1.count(elements)==1:
                    TipoPresente=True
            #Controllo verità presenza altri elementi del gruppo dell'elemento
            if TipoPresente==False:
                #Scrittura
                Combo1.append(elements)
                VarTot.remove(elements)
        TipoPresente=False
        #Controllo presenza negazione della variabile
        if Combo2.count("NOT"+elements)==0:
            #Controllo presenza altri elementi del gruppo dell'elemento
            for elements in var2:
                if Combo2.count(elements)==1:
                    TipoPresente=True
            #Controllo verità presenza altri elementi del gruppo dell'elemento
            if TipoPresente==False:
                #Scrittura
                Combo2.append(elements)
                VarTot.remove(elements)
        TipoPresente=False
        #Controllo presenza negazione della variabile
        if Combo3.count("NOT"+elements)==0:
            #Controllo presenza altri elementi del gruppo dell'elemento
            for elements in var2:
                if Combo3.count(elements)==1:
                    TipoPresente=True
            #Controllo verità presenza altri elementi del gruppo dell'elemento
            if TipoPresente==False:
                #Scrittura
                Combo3.append(elements)
                VarTot.remove(elements)
    TipoPresente=False
    if var3.count(elements)==1:
        #Controllo presenza negazione della variabile
        if Combo1.count("NOT"+elements)==0:
            #Controllo presenza altri elementi del gruppo dell'elemento
            for elements in var3:
                if Combo1.count(elements)==1:
                    TipoPresente=True
            #Controllo verità presenza altri elementi del gruppo dell'elemento
            if TipoPresente==False:
                #Scrittura
                Combo1.append(elements)
                VarTot.remove(elements)
        TipoPresente=False
        #Controllo presenza negazione della variabile
        if Combo2.count("NOT"+elements)==0:
            #Controllo presenza altri elementi del gruppo dell'elemento
            for elements in var3:
                if Combo2.count(elements)==1:
                    TipoPresente=True
            #Controllo verità presenza altri elementi del gruppo dell'elemento
            if TipoPresente==False:
                #Scrittura
                Combo2.append(elements)
                VarTot.remove(elements)
        TipoPresente=False
        #Controllo presenza negazione della variabile
        if Combo3.count("NOT"+elements)==0:
            #Controllo presenza altri elementi del gruppo dell'elemento
            for elements in var3:
                if Combo3.count(elements)==1:
                    TipoPresente=True
            #Controllo verità presenza altri elementi del gruppo dell'elemento
            if TipoPresente==False:
                #Scrittura
                Combo3.append(elements)
                VarTot.remove(elements)

#Analisi coppie variabili non assegnate dopo la assegnazione parziale
while q!=AttrEccesso:
    if Combo1.count(ComAttr[0])==1:
        Combo1.append(ComAttr[1])
        del ComAttr[0:2]
    elif Combo1.count(ComAttr[1])==1:
        Combo1.append(ComAttr[0])
        del ComAttr[0:2]
    elif Combo2.count(ComAttr[0])==1:
        Combo2.append(ComAttr[1])
        del ComAttr[0:2]
    elif Combo2.count(ComAttr[1])==1:
        Combo2.append(ComAttr[0])
        VarTot.remove(ComAttr[0])
        del ComAttr[0:2]
    elif Combo3.count(ComAttr[0])==1:
        Combo3.append(ComAttr[1])
        del ComAttr[0:2]
    elif Combo3.count(ComAttr[1])==1:
        Combo3.append(ComAttr[0])
        del ComAttr[0:2]
    q+=1
q=0


print(Combo1)
print(Combo2)
print(Combo3)
print(NegAttr)
print(NegNomi)
print(ComAttr)
print(ComNomi)
print(AttrEccesso)
print(VarTot)

#TODO:  
#aggiungi

#assunzioni
#DEBUG=================
# File "g:\VS\vs\OPS\Programmi\FattiEConclusioni.py", line 217, in <module>
#if var1.count(elements)==1:
#AttributeError: 'dict' object has no attribute 'count'
#TEST
#aggiungi la lista xAttrEccesso alle combo