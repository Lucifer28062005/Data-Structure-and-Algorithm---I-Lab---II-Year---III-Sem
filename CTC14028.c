#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    int x;
    scanf("%d", &x);
    int left = 0, right = n - 1;
    int result = -1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == x) {
            result = mid;
            left = mid + 1; 
        } else if(arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("%d\n", result);
    return 0;
}
