#include <stdio.h>

void bubbleSort(int arr[6]) {
    // Loop setiap elemen array
	for (int i = 0; i < 6 - 1; i++) {
	// Loop membandingkan elemen bersebelahan
        for (int j = 0; j < 6 - i - 1; j++) {
            if (arr[j] < arr[j + 1]) { 					// < descending, > ascending
                // Tukar elemen arr[j] dengan arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[6]) {
	for (int i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int data[6] = {22, 10, 15, 3, 8, 2};

    printf("Data sebelum diurutkan: ");
    printArray(data);

    bubbleSort(data);

    printf("Data setelah diurutkan (descending): ");
    printArray(data);

    return 0;
}
