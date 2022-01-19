#ID armi                   
# Danno&BonusDanni:               '000'         IdArma1[0:3]
# TipoDannoFlat&Percentuale:      'f,p,x'       IdArma1[3:4]
# DannoGenerale&Fisico&Magico:    'f,m,g,x'     IdArma1[4:5]
# ElementoDanno:                  'f,e,m,o,x'   IdArma1[5:6]
# VitaNecessaria:                 '000,xxx'     IdArma1[6:11]
# 2nd Danno                  
# Danno&BonusDanni:               '000'         IdArma1[0:3]
# TipoDannoFlat&Percentuale:      'f,p,x'       IdArma1[3:4]
# DannoGenerale&Fisico&Magico:    'f,m,g,x'     IdArma1[4:5]
# ElementoDanno:                  'f,e,m,o,x'   IdArma1[5:6]
# VitaNecessaria:                 '000,xxx'     IdArma1[6:11]

#var
vita=0
arma1=''

#DANNI
DannoGenerale=0
DannoFisico=0
DannoMagico=0
DannoFuoco=0
DannoElettro=0
DannoOscuro=0

#calcolo vita
vita=input('Vita percentuale:')
print('[',end='' )
vita=int(vita)/10 
for number in range(int(vita)):
  print('❤',end='')
print(']')
vita=int(vita)*10

#primary hand
arma1=input('StatsArma1, Formato:000xxx000xxx:')
IdArma1=list(arma1)
DannoGenerale + IdArma1[0:3]
