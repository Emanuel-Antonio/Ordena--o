#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimir_vetor(int *vetor, int tamanho)
{
  int i;

  for (i = 0; i < tamanho; i++)
  {
    printf("%d ", vetor[i]);
  }
  printf("\n");
}

void merge_sort(int *vetor, int ini, int fim, int tamanho)
{
  int meio, i, j, k, aux[tamanho];
  // tamanho do vetor é maior que 1?
  if (ini < fim)
  {
    meio = (ini + fim) / 2;
    merge_sort(vetor, ini, meio, tamanho);
    merge_sort(vetor, meio + 1, fim, tamanho);

    i = ini;
    j = meio + 1;
    k = ini;

    while (i <= meio && j <= fim)
    {
      if (vetor[i] < vetor[j])
      {
        aux[k] = vetor[i];
        i++;
      }
      else
      {
        aux[k] = vetor[j];
        j++;
      }
      k++;
    }
    while (i <= meio)
    {
      aux[k] = vetor[i];
      i++;
      k++;
    }
    while (j <= fim)
    {
      aux[k] = vetor[j];
      j++;
      k++;
    }
    for (i = ini; i <= fim; i++)
      vetor[i] = aux[i];
  }
}

int main()
{
  int tamanho = 9;
  int vetor[tamanho];

  for (int i = 0; i < 9; i++)
  {
    printf("vetor %d = ",i+1);
    scanf("%d", &vetor[i]);
  }
  printf("\n");

  printf("Vetor original: ");
  imprimir_vetor(vetor, tamanho);

  merge_sort(vetor, 0, tamanho-1, tamanho);

  printf("\nVetor ordenado: ");
  imprimir_vetor(vetor, tamanho);

  return 0;
}
