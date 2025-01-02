#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000
#define MAX_Q 1000

// Struktur untuk menggantikan map
typedef struct {
    long long key;
    long long value;
} Map;

Map map[MAX_N];
int map_size = 0;

void map_insert(long long key, long long value) {
    for (int i = 0; i < map_size; i++) {
        if (map[i].key == key) {
            map[i].value = value;
            return;
        }
    }
    map[map_size].key = key;
    map[map_size].value = value;
    map_size++;
}

long long map_get(long long key) {
    for (int i = 0; i < map_size; i++) {
        if (map[i].key == key) {
            return map[i].value;
        }
    }
    return 0;
}

void map_erase(long long key) {
    for (int i = 0; i < map_size; i++) {
        if (map[i].key == key) {
            for (int j = i; j < map_size - 1; j++) {
                map[j] = map[j + 1];
            }
            map_size--;
            return;
        }
    }
}

// Struktur untuk menggantikan set
long long set[MAX_N];
int set_size = 0;

void set_insert(long long value) {
    for (int i = 0; i < set_size; i++) {
        if (set[i] == value) {
            return;
        }
    }
    set[set_size++] = value;
}

void set_erase(long long value) {
    for (int i = 0; i < set_size; i++) {
        if (set[i] == value) {
            for (int j = i; j < set_size - 1; j++) {
                set[j] = set[j + 1];
            }
            set_size--;
            return;
        }
    }
}

long long set_lower_bound(long long value) {
    for (int i = 0; i < set_size; i++) {
        if (set[i] >= value) {
            return set[i];
        }
    }
    return 0;
}

long long set_upper_bound(long long value) {
    for (int i = 0; i < set_size; i++) {
        if (set[i] > value) {
            return set[i];
        }
    }
    return 0;
}

int main() {
    int t = 1;
    while (t--) {
        long long n, q, k, b, f;
        scanf("%lld %lld %lld %lld %lld", &n, &q, &k, &b, &f);

        long long add[MAX_N][MAX_N] = {0};
        long long rem[MAX_N][MAX_N] = {0};
        int add_size[MAX_N] = {0};
        int rem_size[MAX_N] = {0};

        while (q--) {
            long long x, l, r;
            scanf("%lld %lld %lld", &x, &l, &r);
            l--;
            r--;
            add[l][add_size[l]++] = x;
            if (r + 1 < n) {
                rem[r + 1][rem_size[r + 1]++] = x;
            }
        }

        set_size = 0;
        set_insert(0LL);
        set_insert(f);

        long long ans = 0;
        long long res = f / k;
        map_size = 0;
        map_insert(f, res);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < rem_size[i]; j++) {
                long long x = rem[i][j];
                long long it = set_lower_bound(x);
                it--;
                res -= map_get(x);
                set_erase(x);
                it = set_lower_bound(x);
                long long p2 = it;
                res -= map_get(p2);
                map_insert(p2, (p2 - it) / k);
                res += map_get(p2);
            }

            for (int j = 0; j < add_size[i]; j++) {
                long long x = add[i][j];
                long long it = set_upper_bound(x);
                long long p = it;
                it--;
                long long p1 = it;
                res -= map_get(p1);
                map_insert(x, (x - p1) / k);
                map_insert(p, (p - p1) / k);
                res += map_get(x);
                res += map_get(p);
                set_insert(x);
            }

            ans += res < b ? res : b;
        }

        printf("%lld\n", ans);
    }
    return 0;
}
