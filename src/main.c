#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

bool input(int *N, int *M);

int main() {
    int N, M;

    if (input(&N, &M) == true) {

        int** arr = (int**)malloc(N * sizeof(int*));

        for (int i = 0; i < N; i++) {
            arr[i] = (int*)malloc(M *sizeof(int));
        }
        
        for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr[i][j] = i * j;
            if (abs(arr[i][j]) < 10) {
                printf("%d  ", arr[i][j]);
            } else (printf("%d ", arr[i][j]));

        }
        printf("\n");
    }

        for (int i = 0; i < N; i++) {
            free(arr[i]);
        }
        free(arr);
    } else (printf("n/a"));

}

bool input(int *N, int *M) {
    char term;
    bool flag;

    if (scanf("%d %d%c", N, M, &term) == 3 && term == '\n') {
        flag = true;
    } else flag = false;

    return(flag);
}