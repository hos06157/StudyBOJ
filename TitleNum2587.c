int main() {
    int arr[5];
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (arr[j] < arr[i]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    int avg = 0;
    for (int i = 0; i < 5; i++) {
        avg += arr[i];
    }
    avg = avg / 5;
    printf("%d\n%d", avg, arr[2]);
    return 0;
}