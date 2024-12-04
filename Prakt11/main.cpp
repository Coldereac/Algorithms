#include <algorithm>
#include <iostream>
#include <fstream>

#define FILE_NAME "prakt11.txt"

using namespace std;

struct SortMetrics {
    unsigned long long comparisons = 0; // Кількість порівнянь
    unsigned long long swaps = 0; // Кількість замін
};

// Сортування вставками
SortMetrics insertionSort(int arr[], int n) {
    SortMetrics metrics;
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Порівняння ключа з елементами
        while (j >= 0 && arr[j] > key) {
            metrics.comparisons++;
            arr[j + 1] = arr[j];
            metrics.swaps++;
            --j;
        }
        metrics.comparisons++; // Останнє порівняння в while
        if (arr[j + 1] != key) {
            // Враховуємо тільки справжню заміну
            arr[j + 1] = key;
            metrics.swaps++;
        }
    }
    return metrics;
}

// Сортування бульбашкою
SortMetrics bubbleSort(int arr[], int n) {
    SortMetrics metrics;

    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            metrics.comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                metrics.swaps++;
                swapped = true;
            }
        }
        if (!swapped) break; // Якщо нічого не змінювалось, масив уже відсортований
    }
    return metrics;
}

// Сортування вибором
SortMetrics selectionSort(int arr[], int n) {
    SortMetrics metrics;

    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        // Знаходимо мінімум серед елементів після i-го індексу
        for (int j = i + 1; j < n; ++j) {
            metrics.comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Якщо мінімум знаходиться не на своєму місці, робимо обмін
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            metrics.swaps++;
        }
    }
    return metrics;
}


int *fillArrayRandom(int n) {
    int *arr = new int[n];
    srand(time(nullptr));
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % n;
    }
    return arr;
}

int *fillArrayWorst(int n) {
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = n - i - 1;
    }
    return arr;
}

int *fillArrayBest(int n) {
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = i;
    }
    return arr;
}

void doSortAndPrint(SortMetrics (*func)(int *, int), int data[], int n, ofstream &file) {
    SortMetrics metrics = func(data, n);
    file << "Comparisons = " << metrics.comparisons
            << ", Moves = " << metrics.swaps << "\n";
}

void doSortAndPrintForRandom(SortMetrics (*func)(int *, int), int n, ofstream &file) {
    SortMetrics sum = {0, 0};

    for (int i = 0; i < 10; ++i) {
        int *arr = fillArrayRandom(n);
        SortMetrics metrics = func(arr, n);
        sum.comparisons += metrics.comparisons;
        sum.swaps += metrics.swaps;
        delete[] arr;
    }

    file << "Comparisons = " << sum.comparisons / 10
            << ", Moves = " << sum.swaps / 10 << "\n";
}

void doAllCases(int n, ofstream &file, SortMetrics (*func)(int *, int)) {
    file << "Worst Case: \n";
    int *data = fillArrayWorst(n);
    doSortAndPrint(func, data, n, file);
    delete[] data;

    file << "Best Case: \n";
    data = fillArrayBest(n);
    doSortAndPrint(func, data, n, file);
    delete[] data;

    file << "Random Case: \n";
    doSortAndPrintForRandom(func, n, file);

    file << "\n";
}

int main() {
    const int sizes[] = {10, 100, 1000, 10000, 100000};
    ofstream file(FILE_NAME);
    file << "Insertion Sort: \n\n";
    for (int n: sizes) {
        file << "Size: " << n << endl;
        doAllCases(n, file, insertionSort);
    }

    file << "Bubble Sort: \n\n";
    for (int n: sizes) {
        file << "Size: " << n << endl;
        doAllCases(n, file, bubbleSort);
    }

    file << "Selection Sort: \n\n";
    for (int n: sizes) {
        file << "Size: " << n << endl;
        doAllCases(n, file, selectionSort);
    }
    file.close();
    return 0;
}
