#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 26
#define N_MAX 500

int main() {
    int n;
    char original[N_MAX + 1], mapped1[N_MAX + 1], mapped2[N_MAX + 1];
    char mapping1[MAX] = {0}, mapping2[MAX] = {0};

    // Input handling
    scanf("%d", &n);
    scanf("%s", original);
    scanf("%s", mapped1);
    scanf("%s", mapped2);

    // Validate and construct mappings
    for (int i = 0; i < n; i++) {
        char a = original[i], b = mapped1[i];

        if ((mapping1[a - 'A'] && mapping1[a - 'A'] != b) || (mapping2[b - 'A'] && mapping2[b - 'A'] != a)) {
            printf("Pak Dengklek bingung\n");
            return 0;
        }

        mapping1[a - 'A'] = b;
        mapping2[b - 'A'] = a;
    }

    // Decode the second message
    for (int i = 0; i < n; i++) {
        char b = mapped2[i];
        if (mapping2[b - 'A']) {
            printf("%c", mapping2[b - 'A']);
        } else {
            printf("?");
        }
    }
    printf("\n");

    return 0;
}
