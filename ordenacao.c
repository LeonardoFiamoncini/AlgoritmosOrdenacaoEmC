#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <locale.h>
#include <math.h>

//____________________________________BUBBLESORT____________________________________

void bubbleSort(int n, int* v){
    for (int i = n - 1; i > 0; i--){
        for (int j = 0; j < i; j++){
            if (v[j] > v[j+1]){
                int tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
            }
        }
    }
}

//__________________________________________________________________________________


//_____________________________________QUICKSORT____________________________________

void troca(int a, int b, int* v){
    int tmp = v[a];
    v[a] = v[b];
    v[b] = tmp;
}

int particiona(int a, int b, int* v){
    int pivo = v[a];
    while (a < b){
        while (v[a] < pivo) a++;
        while (v[b] > pivo) b--;
        troca(a, b, v);
    }
    return a;
}

void quickSort(int a, int b, int* v){
    if (a < b){
        int index = particiona(a, b, v);
        quickSort(a, index - 1, v);
        quickSort(index + 1, b, v);
    }
}

//__________________________________________________________________________________


//_____________________________________MERGESORT____________________________________

void merge(int p, int q, int r, int* v){
    int n1 = q - p + 1;
    int n2 = r - q;

    int left[n1+1];
    int right[n2+1];

    for (int i = 0; i < n1; i++){
        left[i] = v[p + i];
    }

    for (int i = 0; i < n2; i++){
        right[i] = v[q + i + 1];
    }

    left[n1] = INT_MAX;
    right[n2] = INT_MAX;

    int j = 0;
    int k = 0;
    for (int i = p; i <= r; i++){
        if (left[j] <= right[k]){
            v[i] = left[j];
            j++;
        } else {
            v[i] = right[k];
            k++;
        }
    }
}

void mergeSort(int a, int b, int* v){
    if (a < b){
        int c = (a + b)/2;
        mergeSort(a, c, v);
        mergeSort(c + 1, b, v);
        merge(a, c, b, v);
    }
}

//__________________________________________________________________________________