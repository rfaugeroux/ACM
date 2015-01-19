#include <cstdio>
#include <iostream>
#include <cmath>

#define MIN(a, b) ((a)>(b) || ((a) < 0) ? (b) : (a))

using namespace std;

int manhattan(int x0, int y0, int x1, int y1) {

    return abs(x1-x0) + abs(y1-y0);
}

int main() {

    int ntc;
    scanf("%d", &ntc);
    bool begin = true;

    while(ntc--){

        if(!begin) printf("\n");
        begin = false;

        int C, np;
        scanf("%d", &C);
        scanf("%d", &np);

        int X[np];
        int Y[np];
        int W[np];

        for (int i = 0; i < np; ++i) {
            scanf("%d", X+i);
            scanf("%d", Y+i);
            scanf("%d", W+i);
        }

        int result[np+1];
        for (int i = 0; i < np+1; ++i) {
            result[i] = -1;
        }

        result[0] = 0;

        for (int si = 0; si < np; ++si) {
            int weight = 0;
            int oldX = 0;
            int oldY = 0;
            int dist = result[si];
            for (int pi = si+1; pi < np+1; ++pi) {
                int newX = X[pi-1];
                int newY = Y[pi-1];
                weight += W[pi-1];
                if(weight > C) break;

                dist += manhattan(newX, newY, oldX, oldY);

                result[pi] = MIN (result[pi], dist + manhattan(newX, newY, 0, 0));

                oldX = newX;
                oldY = newY;
            }
        }

        printf("%d\n", result[np]);
    }

    return 0;
}
