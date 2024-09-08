#include <stdio.h>
#include <stdlib.h>

int* allocate_array(int n) {
    return (int *)malloc(n * sizeof(int));
}

void free_array(int* arr) {
    free(arr);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int *a = allocate_array(n);
    int *max_trai = allocate_array(n);
    int *min_phai = allocate_array(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    if (n == 1) {
        printf("1 %d\n", a[0]);
        free_array(a);
        free_array(max_trai);
        free_array(min_phai);
        return 0;
    }

    max_trai[0] = a[0];
    for (int i = 1; i < n; i++) {
        if (max_trai[i-1] > a[i])
            max_trai[i] = max_trai[i-1];
        else
            max_trai[i] = a[i];
    }

    min_phai[n-1] = a[n-1];
    for (int i = n-2; i >= 0; i--) {
        if (min_phai[i+1] < a[i])
            min_phai[i] = min_phai[i+1];
        else
            min_phai[i] = a[i];
    }

    int dem = 0;
    int *ket_qua = allocate_array(n);

    for (int i = 0; i < n; i++) {
        if ((i == 0 || max_trai[i-1] <= a[i]) && (i == n-1 || a[i] < min_phai[i+1])) {
            ket_qua[dem++] = a[i];
        }
    }

    printf("%d ", dem);
    for (int i = 0; i < dem && i < 100; i++) {
        printf("%d ", ket_qua[i]);
    }
    printf("\n");

    free_array(a);
    free_array(max_trai);
    free_array(min_phai);
    free_array(ket_qua);

    return 0;
}
