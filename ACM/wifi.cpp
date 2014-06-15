#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int ntc;
    scanf("%d", &ntc);

    for (int tc = 0; tc < ntc; ++tc) {

        int nh, nw;
        scanf("%d", &nw);
        scanf("%d", &nh);

        int d[nh];
        for (int i = 0; i < nh; ++i) {
            scanf("%d", d+i);
        }

        sort(d, d+nh);

    }

    return 0;
}
