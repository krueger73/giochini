# giochini
Tutti i programmi sono sviluppati in C standard, utilizzando MS Visual Studio su Windows. In genere preferisco usare le applicazioni console, perchè li ho imparato la maggior parte delle cose. 
Non dovrebbe essere un grosso problema adattarli ad altri target.
## Regine01.cpp - versione finale del programma che calcola tutte le soluzioni al problema delle regine di un dato ordine
```
#define DIM 8
```
qui configuriamo quante regine dobbiamo disporre su una scacchiera DIMxDIM
```
#define PRINT_PROGRESS 1
```
Qui decidiamo se stampare un progress durante il calcolo. Puntini, intervallati dal numero di soluzioni trovate fino a quel momento. Diversamente il programma stampa solo il risultato alla fine del calcolo.

```
#define PRINT_TAB 1
```
Qui decidiamo se stampare, per ogni soluzione trovata, il render della scacchiera con le regine disposte
```
#define PRINT_SOL 1
```
Qui decidiamo se stampare, per ogni soluzione trovata, la versione "compressa". Ovvero le posizioni delle regine sulle varie righe.

Chiaramente disabilitando le stampe sulla console, la velocità di esecuzione aumenta. 
Il codice dovrebbe essere commentato in modo abbastanza esauriente. 
Enjoy
