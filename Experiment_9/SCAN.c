#include <stdio.h>

// Global variables
int head, a[20], i, distance, n, seektime, size;

// Bubble Sort function to sort the array of disk requests
void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Main function
int main() {
    // Input head position
    printf("\nEnter Head position: ");
    scanf("%d", &head);

    // Input number of disk requests
    printf("\nEnter number of disk requests: ");
    scanf("%d", &n);

    // Input disk size
    printf("\nEnter the disk size: ");
    scanf("%d", &size);

    // Input the disk requests
    printf("\nEnter the disk requests: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Add the current head position to the array of requests
    a[n] = head;
    n++;

    // Sort the array of requests
    bubbleSort(a, n);

    // Find the position of the head in the sorted array
    int pos;
    for (i = 0; i < n; i++) {
        if (a[i] == head) {
            pos = i;
            break;
        }
    }

    // SCAN disk scheduling
    printf("\n\tSCAN DISK SCHEDULING\n\n");

    // Move from head position to the end of the array
    for (i = pos; i < n - 1; i++) {
        distance = a[i + 1] - a[i];
        printf("Head movement from %d to %d : %d\n", a[i], a[i + 1], distance);
        seektime += distance;
    }

    // Move to the end of the disk if needed
    if (a[n - 1] != size - 1) {
        distance = size - 1 - a[n - 1];
        printf("Head movement from %d to %d : %d\n", a[n - 1], size - 1, distance);
        seektime += distance;
    }

    // Move back to the start of the array if needed
    if (pos > 0) {
        printf("Head movement from %d to %d : %d\n", size - 1, a[pos - 1], size - 1 - a[pos - 1]);
        seektime += size - 1 - a[pos - 1];

        for (i = pos - 1; i > 0; i--) {
            distance = a[i] - a[i - 1];
            printf("Head movement from %d to %d : %d\n", a[i], a[i - 1], distance);
            seektime += distance;
        }
    }

    // Print the total seek time
    printf("\nTotal seek time is : %d\n", seektime);
    return 0;
}
