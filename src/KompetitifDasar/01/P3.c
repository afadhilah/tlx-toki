#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 26
#define N_MAX 100

bool is_valid_mapping(char *original, char *mapped, int n, char *mapping) {
    char reverse_mapping[MAX] = {0};
    for (int i = 0; i < n; i++) {
        char o = original[i];
        char m = mapped[i];
        if (mapping[o - 'A'] == 0 && reverse_mapping[m - 'A'] == 0) {
            mapping[o - 'A'] = m;
            reverse_mapping[m - 'A'] = o;
        } else if (mapping[o - 'A'] != m || reverse_mapping[m - 'A'] != o) {
            return false;
        }
    }
    return true;
}

void decode_message(char *mapped, char *decoded, char *mapping, int n) {
    for (int i = 0; i < n; i++) {
        char m = mapped[i];
        if (mapping[m - 'A'] != 0) {
            decoded[i] = mapping[m - 'A'];
        } else {
            decoded[i] = '?';
        }
    }
    decoded[n] = '\0';
}

int main() {
    int n;
    char original[N_MAX + 1], mapped1[N_MAX + 1], mapped2[N_MAX + 1];
    char mapping[MAX] = {0};

    // Input handling
    scanf("%d", &n);
    scanf("%s", original);
    scanf("%s", mapped1);
    scanf("%s", mapped2);

    // Check mapping validity
    if (!is_valid_mapping(original, mapped1, n, mapping)) {
        printf("Pak Dengklek bingung\n");
        return 0;
    }

    // Decode the second message
    char decoded[N_MAX + 1];
    decode_message(mapped2, decoded, mapping, n);

    printf("%s\n", decoded);

    return 0;
}
