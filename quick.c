#include <stdio.h>

void quicksort(int *vetor, int inicio, int fim){
    int direita = fim;
    int esquerda = inicio;
    int pivo = vetor[(inicio+fim)/2];

    while(inicio<=fim){
        while(vetor[inicio]<pivo && inicio < direita){
            inicio++;
        }
        while(vetor[fim]>pivo && fim > esquerda){
            fim--;
        }
        if(inicio<=fim){
            int aux = vetor[inicio];
            vetor[inicio] = vetor[fim];
            vetor[fim] = aux;
            inicio++;
            fim--;
        }
    }
    if(inicio<direita){
        quicksort(vetor, inicio, direita);
    }
    if(fim>esquerda){
        quicksort(vetor, esquerda, fim);
    }
}

int main(){

    int lista[7];
    
    for(int num = 0; num <7; num++){
        scanf("%d", &lista[num]);
    }
    quicksort(lista, 0, 6);

    for(int i = 0; i < 7; i++){
        printf("%d ", lista[i]);
    }

    return 0;
}