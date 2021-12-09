#include <stdio.h>
#include <stdlib.h>

#define MAX 6

void quickSort(int vetor[], int esquerda, int direita) {
    int indEsq, indDir, pivo, aux;
     
    indEsq = esquerda;
    indDir = direita;
    pivo = vetor[(esquerda + direita) / 2];
    pivo = vetor[direita];
     
    while(indEsq <= indDir) {
        while(vetor[indEsq] < pivo && indEsq < direita) {
            indEsq++;
        }
        while(vetor[indDir] > pivo && indDir > esquerda) {
            indDir--;
        }
        if(indEsq <= indDir) {
            aux = vetor[indEsq];    
            vetor[indEsq] = vetor[indDir];
            vetor[indDir] = aux;
            indEsq++;
            indDir--;
        }
    }
    if(indDir > esquerda) {
        quickSort(vetor, esquerda, indDir);
    }
    if(indEsq < direita) {
        quickSort(vetor, indEsq, direita);
    }
}
 
int main(int argc, char** argv){
 //int vetor[MAX] = {3, 0, 1, 8, 7, 2, 5, 4, 9, 6};
 int vetor[MAX] = {3, 0, 1, 4, 2, 5};
 //int vetor[MAX] = {3, 5, 2, 1, 4};
 
 printf("\nValores desordenados\n");
 for(int i = 0; i < MAX; i++){
     printf("%d", vetor[i]);
     if(i != MAX - 1){
         printf(", ");
     }
  }

 quickSort(vetor, 0, MAX - 1);
 
 printf("\nValores ordenados\n");
 for(int i = 0; i < MAX; i++){
     printf("%d", vetor[i]);
     if(i != MAX - 1){
         printf(", ");
     }
 }
 return 0;
}