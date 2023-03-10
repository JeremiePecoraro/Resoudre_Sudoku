#include <stdio.h>

void afficherSudoku(int sudoku[9][9]) {
    int i = 0;
    while (i < 9) {
        int j = 0;
        while (j < 9) {
            printf("%d ", sudoku[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    printf("\n");
}

int verifierCase(int sudoku[9][9], int row, int col, int num) {
    int i = 0;
    while (i < 9) {
        if (sudoku[row][i] == num) {
            return 0;
        }
        i++;
    }

    int j = 0;
    while (j < 9) {
        if (sudoku[j][col] == num) {
            return 0;
        }
        j++;
    }

    int squareRow = row - row % 3;
    int squareCol = col - col % 3;
    i = squareRow;
    while (i < squareRow + 3) {
        j = squareCol;
        while (j < squareCol + 3) {
            if (sudoku[i][j] == num) {
                return 0;
            }
            j++;
        }
        i++;
    }

    return 1;
}

int resoudreSudoku(int sudoku[9][9]) {
    int row = -1;
    int col = -1;
    int estVide = 0;

    int i = 0;
    while (i < 9 && !estVide) {
        int j = 0;
        while (j < 9 && !estVide) {
            if (sudoku[i][j] == 0) {
                row = i;
                col = j;
                estVide = 1;
            }
            j++;
        }
        i++;
    }

    if (!estVide) {
        return 1;
    }

    int num = 1;
    while (num <= 9) {
        if (verifierCase(sudoku, row, col, num)) {
            sudoku[row][col] = num;

            if (resoudreSudoku(sudoku)) {
                return 1;
            }

            sudoku[row][col] = 0;
        }
        num++;
    }

    return 0;
}


