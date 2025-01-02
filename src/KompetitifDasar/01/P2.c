#include <stdio.h>

#define MAX_R 100
#define MAX_C 100

// Fungsi untuk menghitung jumlah tetangga hidup (nilai '1') untuk sebuah sel
int countNeighbors(char board[MAX_R][MAX_C], int r, int c, int R, int C) {
    int count = 0;
    int dr[] = {-1, 1, 0, 0, -1, 1, -1, 1}; // Pergerakan arah baris
    int dc[] = {0, 0, -1, 1, -1, -1, 1, 1}; // Pergerakan arah kolom
    
    for (int i = 0; i < 8; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
            count += (board[nr][nc] == '1'); // Menambah 1 jika tetangga hidup
        }
    }
    return count;
}

int main() {
    int R, C;
    char board[MAX_R][MAX_C];
    char newBoard[MAX_R][MAX_C];

    // Membaca ukuran papan dan status awal papan
    scanf("%d %d", &R, &C);
    getchar(); // Untuk menangani karakter newline setelah angka R dan C

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%c", &board[i][j]);
        }
        getchar(); // Untuk menangani karakter newline setelah setiap baris
    }

    // Proses permainan untuk menghasilkan papan baru berdasarkan aturan
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int liveNeighbors = countNeighbors(board, i, j, R, C);
            
            // Aturan perubahan papan berdasarkan jumlah tetangga hidup
            if (board[i][j] == '1') {
                // Jika sel hidup dan memiliki lebih dari 2 tetangga hidup, tetap hidup
                if (liveNeighbors < 2 || liveNeighbors > 3) {
                    newBoard[i][j] = '0'; // Mati jika terlalu sedikit atau terlalu banyak tetangga hidup
                } else {
                    newBoard[i][j] = '1'; // Tetap hidup jika memiliki 2 atau 3 tetangga hidup
                }
            } else {
                // Jika sel mati dan memiliki tepat 3 tetangga hidup, ia hidup
                if (liveNeighbors == 3) {
                    newBoard[i][j] = '1';
                } else {
                    newBoard[i][j] = '0'; // Tetap mati
                }
            }
        }
    }

    printf("\nHasil:\n");
    // Menampilkan papan hasil akhir
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%c", newBoard[i][j]);
        }
        printf("\n");
    }

    return 0;
}
