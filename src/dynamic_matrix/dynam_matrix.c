#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool input(int *N, int *M);
int **create_matrix(int N, int M);
void free_matrix(int **arr, int N);
bool matrix_input(int **arr, int N, int M);
void matrix_output(int **arr, int N, int M);

int main() {
    int N, M;
    int **arr;

    if (input(&N, &M) == true) {
        arr = create_matrix(N, M);
        if (matrix_input(arr, N, M) == true) {
            matrix_output(arr, N, M);
            free_matrix(arr, N);
        } else 
            (printf("n/a"));
    } else
        (printf("n/a"));
}

bool input(int *N, int *M) {
    char term;
    bool flag;

    if (scanf("%d %d%c", N, M, &term) == 3 && term == '\n') {
        flag = true;
    } else
        flag = false;

    return (flag);
}

int **create_matrix(int N, int M) {
    int **arr = (int **)malloc(N * sizeof(int *));

    for (int i = 0; i < N; i++) {
        arr[i] = (int *)malloc(M * sizeof(int));
    }

    return arr;
}

void free_matrix(int **arr, int N) {
    for (int i = 0; i < N; i++) {
        free(arr[i]);
    }
    free(arr);
}

bool matrix_input(int **arr, int N, int M) {
    char term;
    bool flag = true;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (scanf("%d%c", &arr[i][j], &term) != 2 || (term != '\n' && term != ' ')) {
                flag = false;
            }
        }
    }
    return flag;
}

void matrix_output(int **arr, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (abs(arr[i][j]) < 10) {
                printf("%d  ", arr[i][j]);
            } else
                (printf("%d ", arr[i][j]));
        }
        printf("\n");
    }
}