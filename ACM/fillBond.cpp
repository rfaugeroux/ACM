#include <iostream>
#include <cstdio>

using namespace std;

int main() {

    int n = 50000;
    int m = n-1;

    printf("%d %d\n", n, m);

    for (int i = 1; i < n; ++i) {
        printf("%d %d %d\n", 1, i+1, i);
    }

    int q = n-1;
    for (int i = 1; i < n; ++i) {
        printf("%d %d\n", i, i+1);
    }

    return 0;
}
