# [col, row, dir]

def finito():
    global dir_partenza
    global part
    
    print(f"\n\nCOORDINATE = {part} DIREZIONE = {dir_partenza}\n")

    exit()

def coreapp():
    global dir_partenza
    global part

    list_direzioni = ["N", "E", "S", "W"]

    print('''ATTENZIONE: Versione BETA del programma - non contiene data entry !\n\n-\t-1 = ESCE''')

    col_partenza = input("Inserire la colonna di partenza: ")
    row_partenza = input("Inserire la riga di partenza: ")
    dir_partenza = input("Inserire la direzione di partenza: ")

    col_partenza.upper()
    row_partenza.upper()
    dir_partenza.upper()

    part = []
    part.append(col_partenza)
    part.append(row_partenza)

    c = "o"

    while (c != -1):
        c = input("\tInserisci il comando: ")
        c.lower

        if c == "-1":
            finito()

        if c == "o":
            d = list_direzioni.index(dir_partenza)
            if d!=3:
                d+=1
            else:
                d=0
            dir_partenza = list_direzioni[d]

        if c == "a":
            d = list_direzioni.index(dir_partenza)
            if d!=0:
                d-=1
            else:
                d=3
            dir_partenza = list_direzioni[d]

        if c == "f":
            if dir_partenza == "N":
                part[1] = int(part[1]) + 1

            if dir_partenza == "E":
                part[0] = int(part[0]) + 1

            if dir_partenza == "S":
                part[1] = int(part[1]) - 1

            if dir_partenza == "W":
                part[0] = int(part[0]) - 1
        
        print(f'''Posizione attuale: [{part[0]}, {part[1]}, {dir_partenza}]''')

if __name__ == "__main__":
    coreapp()