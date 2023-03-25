import csv
import time

def data_managment():
    global initial_data
    global stringapacchi
    global portata
    print('Software per soluzione automatica problema KNAPSACK')

    n_data_input = int(input('N. pacchi da consegnare dal corriere: '))

    for i in range(n_data_input):
        new_sigla = f'''p{i+1}'''
        new_guadagno = int(input(f'''Inserire guadagno pacco {new_sigla}: '''))
        new_peso = int(input(f'''Inserire peso pacco {new_sigla}: '''))
        new_datas = (new_sigla, new_guadagno, new_peso)

        initial_data.append(new_datas)
        stringapacchi += f'''Pacco {i+1}, '''

    portata = int(input('Inserire la portata del camion: '))

def svolgimento_combinazioni():
    global initial_data
    global final_data
    global portata
    

    for i in range(1, pow(2, len(initial_data))):
        i_bin = bin(i)
        l_bin = list(i_bin)
        l_bin.pop(0)
        l_bin.pop(0)

        new_proposal = []

        len_l_bin = len(l_bin)

        for_range = len(initial_data) - len_l_bin

        for j in range(for_range):
            l_bin.insert(-(len_l_bin+j), '0')

        for j in range(len(initial_data)):
            if l_bin[j] == '1':
                new_proposal.append(initial_data[j])
            else:
                new_proposal.append('')

        sum_prezz = 0
        for element in new_proposal:
            try:
                sum_prezz = sum_prezz + element[1]
            except IndexError:
                pass
        
        
        sum_peso = 0
        for element in new_proposal:
            try:
                sum_peso = sum_peso + element[2]
            except IndexError:
                pass
            
        
        new_proposal.append(str(sum_prezz))
        new_proposal.append(str(sum_peso))

        if sum_peso <= portata:
        	final_data.append(new_proposal)
    
def data_analysis():
    global final_data
    global stringapacchi

    nomefile = f'''{time.strftime("%y%m%d")}-{time.strftime("%H%M%S")}_data.csv'''

    listastringapacchi = stringapacchi.split(',')


    with open(nomefile, 'w', newline='') as datatable:
        a = csv.writer(datatable, delimiter=',')
        a.writerows([listastringapacchi + ['', 'Somma Prezzo', 'Somma Peso']])
        for dato in final_data:
            dato.insert(-2, '')
            dato.insert(-2, '')
            a.writerows([dato])

if __name__ == "__main__":
    initial_data = []
    final_data = []
    stringapacchi = ''
    portata = 0
    data_managment()
    svolgimento_combinazioni()
    data_analysis()