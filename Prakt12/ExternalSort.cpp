#include <bits/stdc++.h>
using namespace std;

struct MinHeapNode {
    int element;
    int i;
};

int comparisons = 0;
int moves = 0;

void swap(MinHeapNode *x, MinHeapNode *y);

class MinHeap {
    MinHeapNode *harr;
    int heap_size;

public:
    MinHeap(MinHeapNode a[], int size);

    void MinHeapify(int);

    ~MinHeap() {delete [] harr;}
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
    MinHeapNode getMin() { return harr[0]; }

    void replaceMin(MinHeapNode x) {
        harr[0] = x;
        MinHeapify(0);
    }
};

MinHeap::MinHeap(MinHeapNode a[], int size) {
    heap_size = size;
    harr = a;
    int i = (heap_size - 1) / 2;
    while (i >= 0) {
        MinHeapify(i);
        i--;
    }
}

void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < heap_size && harr[l].element < harr[i].element) {
        smallest = l;
        comparisons++;
    }

    if (r < heap_size && harr[r].element < harr[smallest].element) {
        smallest = r;
        comparisons++;
    }

    if (smallest != i) {
        swap(&harr[i], &harr[smallest]);
        moves++;
        MinHeapify(smallest);
    }
}

void swap(MinHeapNode *x, MinHeapNode *y) {
    MinHeapNode temp = *x;
    *x = *y;
    *y = temp;
    moves++;
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
        moves++;
    }

    while (i < n1) {
        arr[k++] = L[i++];
        moves++;
    }

    while (j < n2) {
        arr[k++] = R[j++];
        moves++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

FILE *openFile(char *fileName, char *mode) {
    FILE *fp = fopen(fileName, mode);
    if (fp == NULL) {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    return fp;
}

void mergeFiles(char *output_file, int n, int k) {
    FILE *in[k];
    for (int i = 0; i < k; i++) {
        char fileName[2];
        snprintf(fileName, sizeof(fileName), "%d", i);
        in[i] = openFile(fileName, "r");
    }

    FILE *out = openFile(output_file, "w");

    MinHeapNode *harr = new MinHeapNode[k];
    int i;
    for (i = 0; i < k; i++) {
        if (fscanf(in[i], "%d ", &harr[i].element) != 1)
            break;
        harr[i].i = i;
    }
    MinHeap hp(harr, i);

    int count = 0;
    while (count != i) {
        MinHeapNode root = hp.getMin();
        fprintf(out, "%d ", root.element);

        if (fscanf(in[root.i], "%d ", &root.element) != 1) {
            root.element = INT_MAX;
            count++;
        }

        hp.replaceMin(root);
    }

    for (int i = 0; i < k; i++)
        fclose(in[i]);

    fclose(out);
}

void createInitialRuns(char *input_file, int run_size, int num_ways) {
    FILE *in = openFile(input_file, "r");
    FILE *out[num_ways];
    char fileName[2];
    for (int i = 0; i < num_ways; i++) {
        snprintf(fileName, sizeof(fileName), "%d", i);
        out[i] = openFile(fileName, "w");
    }

    int *arr = (int *) malloc(run_size * sizeof(int));
    bool more_input = true;
    int next_output_file = 0;
    int i;
    while (more_input) {
        for (i = 0; i < run_size; i++) {
            if (fscanf(in, "%d ", &arr[i]) != 1) {
                more_input = false;
                break;
            }
        }

        mergeSort(arr, 0, i - 1);

        for (int j = 0; j < i; j++)
            fprintf(out[next_output_file], "%d ", arr[j]);

        next_output_file++;
    }

    for (int i = 0; i < num_ways; i++)
        fclose(out[i]);

    fclose(in);
}

void externalSort(char *input_file, char *output_file, int num_ways, int run_size) {
    createInitialRuns(input_file, run_size, num_ways);
    mergeFiles(output_file, run_size, num_ways);
}

void sortAndPrint(int num_ways, char input_file[], char output_file[], int run_size, int *data) {
    moves = 0;
    comparisons = 0;
    mergeSort(data, 0, num_ways * run_size - 1);
    cout << "Merge: ";
    cout << "Comparisons: " << comparisons << ", ";
    cout << "Moves: " << moves << endl;


    moves = 0;
    comparisons = 0;
    externalSort(input_file, output_file, num_ways, run_size);

    cout << "External: ";
    cout << "Comparisons: " << comparisons << ", ";
    cout << "Moves: " << moves << endl;
}

int main() {
    int num_ways = 10;
    int run_sizes[] = {1, 10, 100, 1000, 10000, 100000};
    char input_file[] = "input.txt";
    char output_file[] = "output.txt";

    for (auto run_size: run_sizes) {
        cout << "Size: " << run_size * num_ways << endl;
        FILE *in = openFile(input_file, "w");
        srand(time(NULL));
        int *data = new int[run_size * num_ways];

        cout << "Worst case: " << endl;
        for (int i = 0; i < num_ways * run_size; i++) {
            int number = num_ways * run_size - i - 1;
            fprintf(in, "%d ", number);
            data[i] = number;
        }
        fclose(in);
        sortAndPrint(num_ways, input_file, output_file, run_size, data);

        in = openFile(input_file, "w");
        cout << "Best case: " << endl;
        for (int i = 0; i < num_ways * run_size; i++) {
            int number = i;
            fprintf(in, "%d ", number);
            data[i] = number;
        }
        fclose(in);
        sortAndPrint(num_ways, input_file, output_file, run_size, data);

        in = openFile(input_file, "w");
        cout << "Random case: " << endl;
        for (int i = 0; i < num_ways * run_size; i++) {
            int number = rand();
            fprintf(in, "%d ", number);
            data[i] = number;
        }

        fclose(in);
        sortAndPrint(num_ways, input_file, output_file, run_size, data);
        delete [] data;
    }

    return 0;
}
