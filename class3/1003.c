#include <stdio.h>

int main() {
    int arr[41] = {0, 1, 1}; // arr[i] = 피보나치 수

    // 피보나치 수 미리 계산 (DP)
    for (int i = 3; i < 41; i++)
        arr[i] = arr[i-1] + arr[i-2];

    int T;
    scanf("%d", &T); // 테스트 케이스 수

    for (int t = 0; t < T; t++) {
        int n;
        scanf("%d", &n);

        if (n == 0)
            printf("1 0\n"); // 0 호출 1번, 1 호출 0번
        else if (n == 1)
            printf("0 1\n"); // 0 호출 0번, 1 호출 1번
        else
            printf("%d %d\n", arr[n-1], arr[n]); // 0 호출 = F(n-1), 1 호출 = F(n)
    }

    return 0;
}
