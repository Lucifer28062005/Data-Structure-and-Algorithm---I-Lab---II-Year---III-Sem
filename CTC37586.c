#include <stdio.h>
int main(){
    int n;
    scanf("%d\n", &n);
    int array[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    if(n > 0){
        int max = array[0];
        for(int i = 1; i < n; i++){
            if(array[i] > max){
                max = array[i];
            }
        }
        printf("[");
        for(int i = 0; i < n; i++){
            printf("%d", array[i]);
            if(i < n - 1){
                printf(", ");
            }
        }
        printf("]\n");
        printf("%d\n", max);
    }
    return 0;
}
