#include <stdio.h>
#include <stdlib.h>
//병합정렬
void merge(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge(arr, left, mid);
        merge(arr, mid + 1, right);

        int n1 = mid - left + 1;
        int n2 = right - mid;

        int* leftArr = (int*)malloc(n1 * sizeof(int));
        int* rightArr = (int*)malloc(n2 * sizeof(int));

        for (int i = 0; i < n1; i++) {
            leftArr[i] = arr[left + i];
        }
        for (int j = 0; j < n2; j++) {
            rightArr[j] = arr[mid + 1 + j];
        }

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            }
            else {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            arr[k] = leftArr[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = rightArr[j];
            j++;
            k++;
        }

        free(leftArr);
        free(rightArr);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int* num = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &num[i]);
    }

    merge(num, 0, N - 1);

    for (int i = 0; i < N; i++) {
        printf("%d\n", num[i]);
    }

    free(num);
    return 0;
}