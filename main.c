#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr, int size) {
    int numberOfSuccessfulComparisonsWithoutInteruption = 0;
    while (numberOfSuccessfulComparisonsWithoutInteruption < size) {
        for (int i = 0; i < size; i++) {
            if (i != size - 1) {
                if (arr[i] > arr[i + 1]) {
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                    numberOfSuccessfulComparisonsWithoutInteruption = 0;
                } else {
                    numberOfSuccessfulComparisonsWithoutInteruption++;
                }
            }
        }
    }
}

void selection_sort(int *arr, int size) {
    int indexOfSmallestNumber = 0;
    for (int i = 0; i < size; ++i) {
        int min = INT_MAX;
        for (int j = i; j < size; ++j) {
            if (arr[j] < min) {
                min = arr[j];
                indexOfSmallestNumber = j;
            }
        }
        arr[indexOfSmallestNumber] = arr[i];
        arr[i] = min;
    }
}
/*

void counting_sort(int *arr, int size) {
    int max = INT_MIN;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int cumulativeCount[max + 1];
    for (int i = 0; i < max; ++i) {
        cumulativeCount[i] = 0;
    }
    for (int i = 0; i < size; ++i) {
        cumulativeCount[arr[i]]++;
    }
    for (int i = 1; i < size; ++i) {
        cumulativeCount[i] += cumulativeCount[i - 1];
    }
    for (int i = 0; i < max + 1; ++i) {
        printf("%d: ", i);
        printf("%d \n", cumulativeCount[arr[i]]);
    }
}
*/

int main(void) {
    int arr[] = {5, 4, 1, 7, 2, 6, 3, 10, 9, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    //selection_sort(arr, size);
    //bubble_sort(arr, size);
    counting_sort(arr, size);
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}
