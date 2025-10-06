#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);
    int arr[1000][1000];
    int zeros = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 0) {
                zeros++;
            }
        }
    }
    int total = r * c;
    int is_sparse = (2 * zeros > total);
    int non_zeros = total - zeros;
    if(!is_sparse || non_zeros == 0) {
        printf("-1\n");
    } else {
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(arr[i][j] != 0) {
                    printf("%d %d %d\n", i, j, arr[i][j]);
                }
            }
        }
    }
    return 0;
}
