#include "ordenacao.c"

int* criaVetorEmbaralhado(int n);

int main(void){
  setlocale(LC_ALL, "Portuguese");

  int n1 = pow(10, 1);
  int n2 = pow(10, 2);
  int n3 = pow(10, 3);
  int n4 = pow(10, 4);

  int* vetor1 = criaVetorEmbaralhado(n1);
  int* vetor2 = criaVetorEmbaralhado(n2);
  int* vetor3 = criaVetorEmbaralhado(n3);
  int* vetor4 = criaVetorEmbaralhado(n4);

  int opcao;
  printf("\nDeseja imprimir os 4 vetores embaralhados?\n1) Sim\n2) Não\nOpção: ");
  scanf("%d", &opcao);

  if (opcao == 1){
    printf("\n\t\tImpressão (vetor1 Embaralhado)");
    for (int i = 0; i < n1; i++){
      printf("\nvetor1[%d] = %d", i, vetor1[i]);
    }

    printf("\n\n\n\t\tImpressão (vetor2 Embaralhado)");
    for (int i = 0; i < n2; i++){
      printf("\nvetor2[%d] = %d", i, vetor2[i]);
    }

    printf("\n\n\n\t\tImpressão (vetor3 Embaralhado)");
    for (int i = 0; i < n3; i++){
      printf("\nvetor3[%d] = %d", i, vetor3[i]);
    }   

    printf("\n\n\n\t\tImpressão (vetor4 Embaralhado)");
    for (int i = 0; i < n4; i++){
      printf("\nvetor4[%d] = %d", i, vetor4[i]);
    }
  }

  printf("\n\n\nInforme o método de ordenação desejado:\n1) BubbleSort\n2) QuickSort\n3) MergeSort\nOpção: ");
  scanf("%d", &opcao);

  int condicaoFinal = 1;
  clock_t t1;
  clock_t t2;
  clock_t t3;
  clock_t t4;

  switch (opcao){
    case 1:
      t1 = clock();
      bubbleSort(n1, vetor1);
      t1 = clock() - t1;

      t2 = clock();
      bubbleSort(n2, vetor2);
      t2 = clock() - t2;

      t3 = clock();
      bubbleSort(n3, vetor3);
      t3 = clock() - t3;
      
      t4 = clock();
      bubbleSort(n4, vetor4);
      t4 = clock() - t4;
      break;

    case 2:
      t1 = clock();
      quickSort(0, n1 - 1, vetor1);
      t1 = clock() - t1;

      t2 = clock();
      quickSort(0, n2 - 1, vetor2);
      t2 = clock() - t2;

      t3 = clock();
      quickSort(0, n3 - 1, vetor3);
      t3 = clock() - t3;

      t4 = clock();
      quickSort(0, n4 - 1, vetor4);
      t4 = clock() - t4;
      break;    
      
    case 3:
      t1 = clock();
      mergeSort(0, n1 - 1, vetor1);
      t1 = clock() - t1;

      t2 = clock();
      mergeSort(0, n2 - 1, vetor2);
      t2 = clock() - t2;

      t3 = clock();
      mergeSort(0, n3 - 1, vetor3);
      t3 = clock() - t3;

      t4 = clock();
      mergeSort(0, n4 - 1, vetor4);
      t4 = clock() - t4;
      break;    

    default:
      printf("\nOpção inexistente");
      condicaoFinal = 0;
  }

  if (condicaoFinal){
    printf("\nDeseja imprimir os 4 vetores ordenados?\n1) Sim\n2) Não\nOpção: ");
    scanf("%d", &opcao);

    if (opcao == 1){
      printf("\n\t\tImpressão (vetor1 Ordenado)");
      for (int i = 0; i < n1; i++){
        printf("\nvetor1[%d] = %d", i, vetor1[i]);
      }

      printf("\n\n\n\t\tImpressão (vetor2 Ordenado)");
      for (int i = 0; i < n2; i++){
        printf("\nvetor2[%d] = %d", i, vetor2[i]);
      }

      printf("\n\n\n\t\tImpressão (vetor3 Ordenado)");
      for (int i = 0; i < n3; i++){
        printf("\nvetor3[%d] = %d", i, vetor3[i]);
      }

      printf("\n\n\n\t\tImpressão (vetor4 Ordenado)");
      for (int i = 0; i < n4; i++){
        printf("\nvetor4[%d] = %d", i, vetor4[i]);
      }
    }

    printf("\n\nTempo total gasto para ordenar vetor1: %lfms", ((double)t1)/((CLOCKS_PER_SEC/1000)));
    printf("\n\nTempo total gasto para ordenar vetor2: %lfms", ((double)t2)/((CLOCKS_PER_SEC/1000)));
    printf("\n\nTempo total gasto para ordenar vetor3: %lfms", ((double)t3)/((CLOCKS_PER_SEC/1000)));
    printf("\n\nTempo total gasto para ordenar vetor4: %lfms\n", ((double)t4)/((CLOCKS_PER_SEC/1000)));
  }

  free(vetor1);
  free(vetor2);
  free(vetor3);
  free(vetor4);
}

int* criaVetorEmbaralhado(int n){
  int* v =  (int*) malloc(n*sizeof(int));

  for (int i = 0; i < n; i++){
    v[i] = i + 1;
  }

  srand(time(NULL));

  for (int j = 0; j < n; j++){
    int r = rand() % n;
    int tmp = v[j];
    v[j] = v[r];
    v[r] = tmp;
  }
  return v;
}