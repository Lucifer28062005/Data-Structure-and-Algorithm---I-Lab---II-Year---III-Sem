#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100005

int main() {
    char line1[2000000];  // Large enough for input line (up to 10^5 elements)
    char line2[100];
    char line3[2000000];
    char line4[100];

    if (fgets(line1, sizeof(line1), stdin) == NULL) {
        printf("[]\n");
        return 1;
    }
    if (fgets(line2, sizeof(line2), stdin) == NULL) {
        printf("[]\n");
        return 1;
    }
    if (fgets(line3, sizeof(line3), stdin) == NULL) {
        printf("[]\n");
        return 1;
    }
    if (fgets(line4, sizeof(line4), stdin) == NULL) {
        printf("[]\n");
        return 1;
    }

    // Parse line1 for A (nums1)
    int A[MAX_SIZE];
    int total = 0;
    char *tk = strtok(line1, " \t\n");
    while (tk != NULL && total < MAX_SIZE) {
        A[total++] = atoi(tk);
        tk = strtok(NULL, " \t\n");
    }

    // Parse line2 for m
    tk = strtok(line2, " \t\n");
    int m = (tk != NULL) ? atoi(tk) : 0;

    // Parse line3 for B (nums2)
    int B[MAX_SIZE];
    int bcount = 0;
    tk = strtok(line3, " \t\n");
    while (tk != NULL && bcount < MAX_SIZE) {
        B[bcount++] = atoi(tk);
        tk = strtok(NULL, " \t\n");
    }

    // Parse line4 for n
    tk = strtok(line4, " \t\n");
    int n = (tk != NULL) ? atoi(tk) : 0;

    // Ensure bcount == n (in case of parsing issues, but assume input is correct)
    // Now merge in-place into A, assuming total == m + n
    int i = m - 1;
    int j = n - 1;
    int k = total - 1;

    while (i >= 0 && j >= 0) {
        if (A[i] >= B[j]) {
            A[k] = A[i];
            i--;
        } else {
            A[k] = B[j];
            j--;
        }
        k--;
    }

    // Copy remaining elements from B (if any)
    while (j >= 0) {
        A[k] = B[j];
        j--;
        k--;
    }

    // Copy remaining elements from A (if any) - THIS WAS MISSING
    while (i >= 0) {
        A[k] = A[i];
        i--;
        k--;
    }

    // Output
    if (total == 0) {
        printf("[]\n");
    } else {
        printf("[");
        printf("%d", A[0]);
        for (int p = 1; p < total; p++) {
            printf(", %d", A[p]);
        }
        printf("]\n");
    }

    return 0;
}
