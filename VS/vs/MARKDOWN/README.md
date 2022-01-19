# Palindromo di Fibonacci <img src="logo.png" align="right" /> <!-- omit in toc -->

---

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

---

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

---

## 🔀 Operazioni del programma

- Inclusione delle librerie:

```c
#include <stdio.h>
```

- Assegnazione variabili:

```c
	unsigned long long int v[3];
	int end=0;
	unsigned long long int reversed, seg, i;

  v[0]=34;v[1]=55;
```

- Creazione numero successivo:

```c
		v[2] = v[0]+v[1];
		v[0] = v[1];
		v[1] = v[2];
		printf("Generato num %llu\n", v[2]);
```

- Reset variabili:

```c
		i=10;
		reversed=0;
```

- Calcolo numero palindromo attraverso potenze di 10:

```c
		while(i<(v[2]*2)){
			seg = v[2]%i;
			seg = (int) seg / (i / 10);
			reversed = (reversed * 10) + seg;
			i*=10;
		}
```

- Stampa numero palindromo:

```c
		if(v[2]==reversed){
			printf("%llu è un numero della seq di fibonacci palindromo\n", reversed);
		}
```

---

## 🔽 Installazione

Nel caso si scarichi l'`.exe` del file, sarà possibile eseguirlo immediatamente senza altri passaggi.

Nel caso si scarichi il `.c` del file, si dovra scaricare un compiler e un IDE per `c`. Il compilatore raccomandato è [MingW](https://www.mingw-w64.org/) mentre l'IDE raccomandato è [DevC++](https://bloodshed-dev-c.download.it/) che ha pure un compilatore integrato (non richiede MingW).

---

## ✔ Uso

Basta lanciare il programma attraverso l'`.exe` o il `.c` (con un IDE) ed eventualmente verrà stampato il numero palindromo.

---

## 💬 Supporto

Nel caso sia necessario dell'supporto potete contattarci attraverso questi link:

| Badge                                                                                                                    | Link o Contatto                                             |
| ------------------------------------------------------------------------------------------------------------------------ | ----------------------------------------------------------- |
| <img src="https://img.shields.io/badge/Gmail-D14836?style=for-the-badge&logo=gmail&logoColor=white" />                   | `placeholder@placeholder.edu.it`                            |
| <img src="https://img.shields.io/badge/WhatsApp-25D366?style=for-the-badge&logo=whatsapp&logoColor=white" />             | `+placeholder`                                              |
| <img src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white" />             | `@placeholder`                                              |
| <img src="https://img.shields.io/badge/Discord-7289DA?style=for-the-badge&logo=discord&logoColor=white" />               | [Invito](placeholder)                                       |
| <img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white" />                 | [Profilo](https://github.com/Captniz)                       |
| <img src="https://img.shields.io/badge/Stack_Overflow-FE7A16?style=for-the-badge&logo=stack-overflow&logoColor=white" /> | [Profilo](https://stackoverflow.com/users/17375922/captniz) |

---

## 🤝 Contribuire

Per contribuire a questo programma basta contattarci attraverso i link preposti, siamo aperti a qualunque tipo di collaborazione.

---

## 👨‍💻 Autori

**Collaborazione alla presentazione:**

| GitHub o Nome | Mail                           |
| ------------- | ------------------------------ |
| Michele       | placeholder@placeholder.edu.it |
| Luca          | placeholder@placeholder.edu.it |
| Tommaso       | placeholder@placeholder.edu.it |
| Singh         | placeholder@placeholder.edu.it |
| Alberto       | placeholder@placeholder.edu.it |
| Simone        | placeholder@placeholder.edu.it |

**Creazione del programma:**

| GitHub o Nome | Mail                           |
| ------------- | ------------------------------ |
| Davide        | placeholder@placeholder.edu.it |

---

## 📃 Licenza

Il programma è completamente _open source_.

---

## 🔄 Status del progetto

Il progetto non sta più venendo seguito dagli sviluppatori originali ma siamo comunque aperti a richieste di supporto o di mantenimento del progetto.
