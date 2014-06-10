#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))

using namespace std;

int main() {

    float PI = 4*atan(1);

    int tc = 1;
    while(1){

        int nb;
        scanf("%d", &nb);
        if(!nb) break;

        printf("Box %d: ", tc);
        tc++;

        int c1[3];
        int c2[3];
        int x1, y1, z1, x2, y2, z2;
        scanf("%d", &x1);
        scanf("%d", &y1);
        scanf("%d", &z1);
        scanf("%d", &x2);
        scanf("%d", &y2);
        scanf("%d", &z2);

        c1[0] = min(x1, x2);
        c2[0] = max(x1, x2);
        c1[1] = min(y1, y2);
        c2[1] = max(y1, y2);
        c1[2] = min(z1, z2);
        c2[2] = max(z1, z2);

        int p[nb][3];
        int perm[nb];
        for (int i = 0; i < nb; ++i) {
            scanf("%d", p[i]);
            scanf("%d", p[i]+1);
            scanf("%d", p[i]+2);
            perm[i] = i;
        }

        float vbox = (c2[2]-c1[2])*(c2[1]-c1[1])*(c2[0]-c1[0]);
        float volume = vbox;
        sort(perm, perm+nb);
        do {
            float radius[nb];
            float curr_V = vbox;
            for (int i = 0; i < nb; ++i) {
                radius[i] = 0;
            }
            for (int pi = 0; pi < nb; ++pi) {
                int min_r = c2[2]-c1[2];
                int * pa = p[perm[pi]];
                min_r = min(min_r, pa[0]-c1[0]);
                min_r = min(min_r, pa[1]-c1[1]);
                min_r = min(min_r, pa[2]-c1[2]);
                min_r = min(min_r, c2[0] - pa[0]);
                min_r = min(min_r, c2[1] - pa[1]);
                min_r = min(min_r, c2[2] - pa[2]);
                for (int i = 0; i < pi-1; ++i) {
                    int * pb = p[perm[i]];
                    int rb = radius[i];
                    if(rb==0) continue;
                    int dx = pa[0]-pb[0];
                    int dy = pa[1]-pb[1];
                    int dz = pa[2]-pb[2];
                    float d = dx*dx + dy*dy + dz*dz;
                    d = sqrt(d);
                    min_r = min(min_r, d-rb);
                }
                if(min_r <= 0) continue;
                radius[pi] = min_r;
                curr_V -= 4*min_r*min_r*min_r*PI/3.f;
            }
            if(curr_V < volume || volume==-1){
                volume = curr_V;
            }
        } while(next_permutation(perm, perm+nb));

        printf("%d\n\n", int(round(volume)));

    }
    return 0;
}
