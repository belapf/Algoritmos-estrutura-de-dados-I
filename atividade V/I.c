#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Função para trocar dois elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


// Bubble Sort
void bubbleSort(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}



// Insertion Sort
void insertionSort(int array[], int n) {
    for (int i = 1; i < n; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}



// Merge Sort otimizado com alocação dinâmica
void merge(int array[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    if (!L || !R) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    for (int i = 0; i < n1; i++)
        L[i] = array[l + i];

    for (int j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];
    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        array[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }

    while (i < n1) array[k++] = L[i++];
    while (j < n2) array[k++] = R[j++];
    free(L);
    free(R);
}



void mergeSort(int array[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, m, r);
    }
}



// Quick Sort
int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            swap(&array[++i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);

    return (i + 1);
}



void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}



// Gerar array aleatório
void generateArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 100000;
    }
}



// Medir tempo de execução
void testSortingAlgorithm(void (*sortFunction)(int[], int), int array[], int n, const char *name) {
    clock_t start, end;
    int *copy = (int *)malloc(n * sizeof(int));
    if (!copy) {
        printf("Erro ao alocar memoria para %s\n", name);

        return;
    }

    for (int i = 0; i < n; i++) {
        copy[i] = array[i];
    }

    start = clock();
    sortFunction(copy, n);
    end = clock();
    printf("%s: %f segundos\n", name, ((double)(end - start)) / CLOCKS_PER_SEC);
    free(copy);
}



void testSortingAlgorithmRecursive(void (*sortFunction)(int[], int, int), int array[], int n, const char *name) {
    clock_t start, end;
    int *copy = (int *)malloc(n * sizeof(int));
    if (!copy) {
        printf("Erro ao alocar memoria para %s\n", name);

        return;
    }

    for (int i = 0; i < n; i++) {
        copy[i] = array[i];
    }

    start = clock();
    sortFunction(copy, 0, n - 1);
    end = clock();
    printf("%s: %f segundos\n", name, ((double)(end - start)) / CLOCKS_PER_SEC);
    free(copy);
}



int main() {
    srand(time(NULL));
    int sizes[] = {1000, 100000, 1000000};

    for (int i = 0; i < 3; i++) {
        int n = sizes[i];
        printf("\nTestando com %d elementos:\n", n);
        int *array = (int *)malloc(n * sizeof(int));

        if (!array) {
            printf("Erro ao alocar memoria para %d elementos!\n", n);
            continue;
        }

        generateArray(array, n);
        if (n <= 10000) {
            testSortingAlgorithm(bubbleSort, array, n, "Bubble Sort");
            testSortingAlgorithm(insertionSort, array, n, "Insertion Sort");
        }

        testSortingAlgorithmRecursive(mergeSort, array, n, "Merge Sort");
        testSortingAlgorithmRecursive(quickSort, array, n, "Quick Sort");
        
        free(array);
    }

    
    return 0;
}
