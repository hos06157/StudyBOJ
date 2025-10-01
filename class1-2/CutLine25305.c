#include <stdio.h>


int main() {
    int N, k;
    scanf("%d %d", &N, &k);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (arr[j] > arr[i]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    printf("%d\n", arr[k - 1]);
    return 0;
}