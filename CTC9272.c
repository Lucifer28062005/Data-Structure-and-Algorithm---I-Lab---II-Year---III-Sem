#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * mergeSort(char *Arr[], int ArrLen) {
    if (ArrLen <= 1) {
        if (ArrLen == 0) {
            char *result = (char *)malloc(1);
            if (result) *result = '\0';
            return result;
        }
        size_t totalLen = strlen(Arr[0]);
        char *result = (char *)malloc(totalLen + 1);
        if (result) {
            strcpy(result, Arr[0]);
        }
        return result;
    }

    char **temp = (char **)malloc(ArrLen * sizeof(char *));
    if (temp == NULL) {
        return NULL;
    }
    int width;
    for (width = 1; width < ArrLen; width *= 2) {
        int left;
        for (left = 0; left < ArrLen; left += 2 * width) {
            int mid = (left + width - 1 < ArrLen - 1) ? left + width - 1 : ArrLen - 1;
            int right = (left + 2 * width - 1 < ArrLen - 1) ? left + 2 * width - 1 : ArrLen - 1;

            int i = left;
            int j = mid + 1;
            int k = left;

            while (i <= mid && j <= right) {
                if (strcmp(Arr[i], Arr[j]) <= 0) {
                    temp[k++] = Arr[i++];
                } else {
                    temp[k++] = Arr[j++];
                }
            }
            while (i <= mid) {
                temp[k++] = Arr[i++];
            }
            while (j <= right) {
                temp[k++] = Arr[j++];
            }

            for (int p = left; p <= right; p++) {
                Arr[p] = temp[p];
            }
        }
    }
    free(temp);

    size_t totalLen = 0;
    for (int i = 0; i < ArrLen; i++) {
        totalLen += strlen(Arr[i]);
        if (i < ArrLen - 1) {
            totalLen += 4;  // " -> "
        }
    }
    char *result = (char *)malloc(totalLen + 1);
    if (result == NULL) {
        return NULL;
    }
    strcpy(result, Arr[0]);
    for (int i = 1; i < ArrLen; i++) {
        strcat(result, " -> ");
        strcat(result, Arr[i]);
    }
    return result;
}

int readStringArray(char *argsArray, char *arr[]) {
    int col = 0;
    char *token = strtok(argsArray, ",");
    while (token != NULL) {
        arr[col] = token;
        token = strtok(NULL, ",");
        col++;
    }
    return col;
}
int main(int argc, char *argv[]) {
    char *Arr[100001];  // Fixed size to handle up to 1e5
    int ArrLen = readStringArray(argv[1], Arr);
    printf("%s\n", mergeSort(Arr, ArrLen));
    return 0;
}
