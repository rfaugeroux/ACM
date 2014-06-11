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

    int tc = 0;
    while(1){

        int nb;
        scanf("%d", &nb);
        if(!nb) break;

        printf("Box %d: ", ++tc);

        int c[2][3];
        int ctmp[2][3];

        for (int j = 0; j < 2; ++j) {
            for (int i = 0; i < 3; ++i) {
                int a0;
                scanf("%d", &a0);
                ctmp[j][i] = a0;
            }
        }
        for (int i = 0; i < 3; ++i) {
            c[0][i] = min(ctmp[0][i], ctmp[1][i]);
            c[1][i] = max(ctmp[0][i], ctmp[1][i]);
        }

        int p[nb][3];
        int perm[nb];
        for (int i = 0; i < nb; ++i) {
            scanf("%d", p[i]);
            scanf("%d", p[i]+1);
            scanf("%d", p[i]+2);
            perm[i] = i;
        }

        float vbox = (c[1][2]-c[0][2])*(c[1][1]-c[0][1])*(c[1][0]-c[0][0]);
        float volume = vbox;
        sort(perm, perm+nb);
        do {
            float radius[nb];
            float curr_V = vbox;
            for (int i = 0; i < nb; ++i) {
                radius[i] = 0;
            }
            for (int pi = 0; pi < nb; ++pi) {
                int min_r = c[1][2]-c[0][2];
                int * pa = p[perm[pi]];

                for (int d = 0; d < 3; ++d) {
                    min_r = min(min_r, pa[d]-c[0][d]);
                    min_r = min(min_r, c[1][d] - pa[d]);
                }

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
