#include <stdio.h>

int main() {
    int M, N;
    scanf("%d %d", &M, &N);
    int arr[M][N];
    int zeros = 0;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 0) {
                zeros++;
            }
        }
    }
    int total = M * N;
    int non_zeros = total - zeros;
    int is_sparse = (zeros > non_zeros);
    printf("%s\n", is_sparse ? "True" : "False");
    if(is_sparse) {
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                if(arr[i][j] != 0) {
                    printf("%d %d %d\n", i, j, arr[i][j]);
                }
            }
        }
    }
    return 0;
}
