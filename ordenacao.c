#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* Com 10, 100, 1000 números aleatorios o tempo para odernar é quase insignificante, mostrando os resultados de 0.00 s

   A partir de 10.000 numeros aleatorios temos :
   10.000
   Ordena1 - Bubble sort = 0.39 s
   Ordena2 - Selection sort = 0.10 s
   Ordena3 - Insertion sort = 0.06 s

   100.000
   Ordena1 - Bubble sort = 35.20 s
   Ordena2 - Selection sort = 9.84 s
   Ordena3 - Insertion sort = 5.48 s

   250.000
   Ordena1 - Bubble sort = 217.86 s
   Ordena2 - Selection sort = 62.81 s
   Ordena3 - Insertion sort = 35.00 s

*/
void Ordena1(int *vetor, int tamanho) // algoritmo de ordenação Bubble-sort
{
    int aux, i, j;
    for(i = 1; i < tamanho; i++)
    {
        for(j = 0; j < tamanho - 1; j++)
        {
            if(vetor[j] > vetor[j+1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1]= aux;


            }
        }


    }
}

void Ordena2 (int *vetor, int tamanho) //algoritmo de ordenação Selection-sort
{
    int i, j, aux, i_menor;
    for(i = 0; i < tamanho; i++)
    {
        i_menor = i;
        for(j = i + 1; j < tamanho; j++)
        {
            if(vetor[j]< vetor[i_menor])
            {
                i_menor = j;
            }
        }
        aux = vetor[i];
        vetor[i]= vetor[i_menor];
        vetor[i_menor] = aux;

    }

}

void Ordena3 (int *vetor, int tamanho) //algoritmo de ordenação Insertion-sort
{
    int i,j, aux;
    for (i = 1; i <= tamanho-1; i++)
    {

        aux = vetor[i];
        j = i - 1;
        while (j >= 0 && aux < vetor[j])
        {

            vetor[j+1] = vetor[j];
            j--;
        }

        vetor[j+1] = aux;
    }

}

void Imprimir (int *A, int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        printf("%d, ", A[i]);
    }
    printf("\n");
}

/*Função que retorna 1 se a ordenação estiver correta e 0 caso contrário.*/
int Verifica_Ordenacao (int *A, int tamanho)
{
    int i;
    for (i = 0; i < tamanho-1; i++)
    {
        if (A[i] > A[i+1])
        {
            return 0;
        }
    }
    return 1;
}


int main ()
{

    clock_t start, end;
    double elapsed_time;
    srand(time(NULL));

    int i;

    int tamanho = 250000;

    int *v1 = (int *)malloc(tamanho * sizeof(int));
    int *v2 = (int *)malloc(tamanho * sizeof(int));
    int *v3 = (int *)malloc(tamanho * sizeof(int));

    for (i = 0; i < tamanho; i++)
    {
        v1[i] = rand() % (tamanho+1);
        v2[i] = rand() % (tamanho+1);
        v3[i] = rand() % (tamanho+1);
    }

    start = clock();
    //Imprimir(v1, tamanho);
    Ordena1 (v1, tamanho);
    //Imprimir(v1, tamanho);
    end = clock();
    elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
    printf("Tempo de execução (ordenação 1): %.2f\n", elapsed_time);
    if (!Verifica_Ordenacao(v1, tamanho))
    {
        printf("Erro: a ordenação 1 não está correta!\n");
    }

    start = clock();
    //Imprimir(v2, tamanho);
    Ordena2 (v2, tamanho);
    //Imprimir(v2, tamanho);
    end = clock();
    elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
    printf("Tempo de execução (ordenação 2): %.2f\n", elapsed_time);
    if (!Verifica_Ordenacao(v2, tamanho))
    {
        printf("Erro: a ordenação 2 não está correta!\n");
    }

    start = clock();
    //Imprimir(v3, tamanho);
    Ordena3 (v3, tamanho);
    //Imprimir(v3, tamanho);
    end = clock();
    elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
    printf("Tempo de execução (ordenação 3): %.2f\n", elapsed_time);
    if (!Verifica_Ordenacao(v3, tamanho))
    {
        printf("Erro: a ordenação 3 não está correta!\n");
    }

    free (v1);
    free (v2);
    free (v3);

    return 0;
}

