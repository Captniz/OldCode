# Palindromo di Fibonacci <img src="logo.png" align="right" /> <!-- omit in toc -->

<!------->

## 🔠 Indice<!-- omit in toc -->

- [❓ Descrizione](#-descrizione)
- [🔀 Operazioni del programma](#-operazioni-del-programma)
- [🔽 Installazione](#-installazione)
- [✔ Uso](#-uso)
- [💬 Supporto](#-supporto)
- [🤝 Contribuire](#-contribuire)
- [👨‍💻 Autori](#-autori)
- [📃 Licenza](#-licenza)
- [🔄 Status del progetto](#-status-del-progetto)

<!------->

## ❓ Descrizione

**_Questo programma ha il compito di trovare e stampare i numeri palindromi della sequenza di fibonacci dopo il 55._**

- I numeri palindromi sono numeri che si possono leggere ugualmente partendo sia da destra che da sinistra:

  > 55  
  > 575  
  > 1090901

- La sequenza di fibonacci è una sequenza di numeri in cui il numero successivo è composto dalla somma dei due precedenti

  > 1  
  > 1  
  > 2  
  > 3  
  > 5  
  > 8  
  > 13  
  > ...

- Questo programma analizzera i numeri fino al **18, 446, 744, 073, 709, 551, 615** ( 2^64 – 1 )  
  dati i limiti dell' `unsigned long long int`

<!------->

## 🔀 Operazioni del programma

- Inclusione delle librerie:

```c
#include <stdio.h>
```

- Assegnazione variabili:

```c
unsigned long long n1,n2,f,i,temp,rev,cifra,flag,npal;
npal=0;
n1=1;
n2=1;
i=0;
flag=0;
```

- Creazione numero successivo:

```c
f=n1+n2;
n2=n1;
n1=f;
temp=f;
```

- Reset variabili:

```c
rev=0;
```

- Calcolo numero palindromo attraverso potenze di 10:

```c
if(f>9){
    while(f>0){
        cifra=f%10;
        rev=rev*10+cifra;
        f=f/10;  
    }
}
```

- Stampa numero palindromo:

```c
if(temp==rev){
    putchar('\n');
    printf("Il numero %llu e' palindromo",temp);
    printf(" e si trova nella %llu posizione della successione di fibonacci",i);
    putchar('\n');
    npal++;
}
```

<!------->

## 🔽 Installazione

Nel caso si scarichi l'`.exe` del file, sarà possibile eseguirlo immediatamente senza altri passaggi.

Nel caso si scarichi il `.c` del file, si dovra scaricare un compiler e un IDE per `c`. Il compilatore raccomandato è [MingW](https://www.mingw-w64.org/) mentre l'IDE raccomandato è [DevC++](https://bloodshed-dev-c.download.it/) che ha pure un compilatore integrato (non richiede MingW).

<!------->

## ✔ Uso

Basta lanciare il programma attraverso l'`.exe` o il `.c` (con un IDE) ed eventualmente verrà stampato il numero palindromo.

<!------->

## 💬 Supporto

Nel caso sia necessario dell'supporto potete contattarci attraverso questi link:

| Badge                                                                                                                    | Link o Contatto                                             |
| ------------------------------------------------------------------------------------------------------------------------ | ----------------------------------------------------------- |
| <img src="https://img.shields.io/badge/Gmail-D14836?style=for-the-badge&logo=gmail&logoColor=white" />                   | `stardiani@fermimn.edu.it`                                  |
| <img src="https://img.shields.io/badge/WhatsApp-25D366?style=for-the-badge&logo=whatsapp&logoColor=white" />             | `+39 3924722479`                                            |
| <img src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white" />             | `@simone-tardiani`                                          |
| <img src="https://img.shields.io/badge/Discord-7289DA?style=for-the-badge&logo=discord&logoColor=white" />               | [Invito](https://discord.gg/VNUFsST6F3)                                    |
| <img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white" />                 | [Profilo](https://github.com/Captniz)                       |
| <img src="https://img.shields.io/badge/Stack_Overflow-FE7A16?style=for-the-badge&logo=stack-overflow&logoColor=white" /> | [Profilo](https://stackoverflow.com/users/17375922/captniz) |

<!------->

## 🤝 Contribuire

Per contribuire a questo programma basta contattarci attraverso i link preposti, siamo aperti a qualunque tipo di collaborazione.

<!------->

## 👨‍💻 Autori

**Collaborazione alla presentazione:**

GitHub o Nome | Mail
------ | ------
Michele Pedroni | pedronim@fermimn.edu.it
Luca Veneri | vluca@fermimn.edu.it
Tommaso Malinverno | tmalinverno@fermimn.edu.it
Singh Jashanpreet | sjashanpreet@fermimn.edu.it
Alberto Tellaroli | atellaroli@fermimn.edu.it
[Simone Tardiani](https://github.com/Captniz) | stardiani@fermimn.edu.it

**Creazione del programma:**

GitHub o Nome | Mail
------ | ------
[Davide Sirico](https://drive.google.com/file/d/1s8SchCV4XYJFjpdnsN53fbV3jc6aC3Td/view?usp=sharing) | dsirico@fermimn.edu.it


<!------->

## 📃 Licenza

Il programma è completamente _open source_.

<!------->

## 🔄 Status del progetto

Il progetto non sta più venendo seguito dagli sviluppatori originali ma siamo comunque aperti a richieste di supporto o di mantenimento del progetto.