#include <stdio.h>

const char* can_fold_to_area(int L, int W, int A) {
    int area = L * W;

    // Periksa apakah A adalah bagian yang valid dari area
    while (area >= A) {
        if (area == A) {
            return "YA";
        }
        // Bagi dua area (melipat)
        if (area % 2 == 0) {
            area /= 2;
        } else {
            break;
        }
    }
    return "TIDAK";
}

int main() {
    int L, W, A;

    // Input
    scanf("%d %d %d", &L, &W, &A);

    // Output
    printf("%s\n", can_fold_to_area(L, W, A));
    return 0;
}
