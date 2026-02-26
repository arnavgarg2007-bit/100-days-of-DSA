#include <stdio.h>

int main() {
    int n, k;

    // Input size
    scanf("%d", &n);

    int arr[n], res[n];

    // Input array
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Input k
    scanf("%d", &k);

    // If k > n
    k = k % n;

    // Rotate array
    for(int i = 0; i < n; i++) {
        res[(i + k) % n] = arr[i];
    }

    // Print result
    for(int i = 0; i < n; i++)
        printf("%d ", res[i]);

    return 0;
}