#include <stdio.h>

#define MAX_R 100
#define MAX_C 100

void play(int i, int C, char board[MAX_R][MAX_C]){
    for (int a = 0; a < C; a++){
        board[i][a] = '0';
    }
}

// Fungsi untuk menghitung jumlah tetangga hidup (nilai '1') untuk sebuah sel
void countNeighbors(char board[MAX_R][MAX_C], int R, int C, int m) {
    for (int i = 0; i < C; i++){
        for (int j = m; j >= 0; j--){
            if (board[j][i] == '1'){
                board[j][i] = '0';
                if (m == R-1)
                {
                    board[m][i] = '1';
                }
                else {
                    for (int k = m; k < R; k++){
                        if (k == R-1 && board[k][i] == '0'){
                            board[k][i] = '1';
                            break;
                        }
                        else if (board[k][i] == '1'){
                            board[k-1][i] = '1';
                            break;
                        }
                    }
                }
                break;
            }
        }
    }
    if (m > 0){
        countNeighbors(board, R, C, m-1);
    }
}

void FungsiP2() {
    int R = 11, C = 6, m, n;
    char board[MAX_R][MAX_C];

    char isi[1001] = "000000000000011100110011111111111000111111111111111001001100111011";
    // Membaca ukuran papan dan status awal papan
    //scanf("%d %d", &R, &C);
    //getchar(); // Untuk menangani karakter newline setelah angka R dan C

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            board[i][j] = isi[i*C+j];
            //scanf("%c", &board[i][j]);
        }
        //getchar(); // Untuk menangani karakter newline setelah setiap baris
    }

    // Proses permainan untuk menghasilkan papan baru berdasarkan aturan
    do{
        m = 0, n = 0;
        for (int i = 0; i < R; i++){
            for (int j = 0; j < C; j++){
                if (board[i][j] == '0'){
                    break;
                }
                else if (j == C-1){
                    n = 1;
                    play(i, C, board);
                }
            }
        }
        if (n == 1){
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    if (board[i][j] == '1'){
                        break;
                    }else if (j == C-1){
                        m = i;
                    }
                }
            }
        }
        countNeighbors(board, R, C, m);
        /* code */
    } while (m!=0);
    
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            printf("%c", board[i][j]); 
        }
        printf("\n");
    }
}
