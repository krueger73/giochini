#include <stdlib.h>
#include <stdio.h>

#define DIM 20

#define PRINT_PROGRESS 1
#define PRINT_TAB 0
#define PRINT_SOL 0

/* restituisce 0 se (row, col) non è minacciata */
int minaccia(int row, int col, int pos[]);

/* piazza regine da riga rowstart in avanti */
void piazza(int rowstart, int pos[]);

/* stampa soluzione in formato lineare
 colonne dove piazzare le regine, riga per riga 
*/
void stampa_sol(int pos[]);

/* stampa scacchiera */
void stampa_tab(int pos[]);

/* conta soluzioni */
static long int conta = 0;
static int occupa[DIM] = { 0 };

int main(void)
{  
  int pos[DIM] = { 0 };
  
  piazza(0, pos);
  printf("\nFinito!\nconta: %ld\n", conta);
}

int minaccia(int row, int col, int pos[]) {
  int locRet = 0;
  int i, c1, c2;
  /* check diagonali superiori */
  if (row == 0) {
    /* sono in riga 0, nessuna minaccia */
    locRet = 0;
  }
  else {
    /* check in verticale in alto già fatto fuori */    
    /* check in diagonale in alto a destra e sinistra fino a row == 0 */
    locRet = 0;
    i = 1;
    /* while (row - i) >= 0 */
    /* ho solo riscritto la diseguaglianza con una equivalente */
    while (row >= i) { 
      /* check in riga row-i,  col+i e col-i */
      c1 = col + i;
      c2 = col - i;
      /* controllo se la regina in row-1 è in posizione c1 o c2 */
      /* non ho bisogno di controllare i limiti di c1 e c2 (>=0 e <DIM) */
      if ((pos[row - i] == c1) || (pos[row - i] == c2)) {
        /* trovata, abbandona */
        locRet = 1;
        i = row; /* forza uscita */
      }
      i++;
    } /* while */
    /* qui locRet è impostato correttamente */    
  }
  return locRet;
}

void piazza(int rowstart, int pos[]) {
  /* piazza regina in riga rowstart, 
     cominciando da (rowstart, 0) e andando avanti */ 
  int reg;

  pos[rowstart] = 0;
  while (pos[rowstart] < DIM) {
    reg = pos[rowstart];
    /* se la casella (rowstart, reg) non è minacciata  */
    if ((occupa[reg] == 0) && (minaccia(rowstart, reg, pos) == 0)) {
      if ((rowstart + 1) == DIM) {
        /* sono nell'ultima riga e ho piazzato la regina in casella non minacciata 
           soluzione ok */
        /* stampa, salva soluzione */        
        conta++;
        if (PRINT_SOL == 1) {
          stampa_sol(pos);
        }
        if (PRINT_TAB == 1) {
          stampa_tab(pos);
        }        
      }
      else {
        /* ho piazzato la regina in posizione non minacciata, ma ne ho altre da piazzare  */        
        /* piazza regine rimanenti da riga rowstart+1 in avanti */
        /* occupa la colonna */
        occupa[reg] = 1;
        piazza(rowstart + 1, pos);
        occupa[reg] = 0;
        /* libera la colonna */
      }
    } /* if non minacciata */
    /* next */
    pos[rowstart]++;
    /*
    * 16 o inferiori: -> 0, 1
    * 20 -> 3, 4
    * 24 -> 5, 6
    * 28 -> 8, 9
    * 32 -> 10, 11
    * 64 -> 30, 31
    */
    if (PRINT_PROGRESS == 1) {
      if (rowstart <= 3) {
        printf("%ld", conta);
      }
      if (rowstart <= 4) {
        printf(".");
      }
    }
  } /* while */
}

void stampa_sol(int pos[]) {
  int i;
  printf("S[%ld]: ", conta);
  for (i = 0; i < DIM; i++) {
    printf("%d ", pos[i]);
  }
  printf("\n\n");
}

void stampa_tab(int pos[]) {
  int i, j;
  printf("  ");
  for (i = 0; i < DIM; i++) {
    printf("%3d", i);
  }
  printf("\n");
  for (i = 0; i < DIM; i++) {
    printf("%3d ", i);
    for (j = 0; j < DIM; j++) {
      if (pos[i] == j) {
        printf("R  ");
      }
      else {
        printf(".  ");
      }
    }
    printf("\n");
  }
  printf("\n");
}