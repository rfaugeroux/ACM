#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {

    int ntc;
    scanf("%d", &ntc);

    for (int tc = 0; tc < ntc; ++tc) {
        if(tc) printf("\n");

        int n_line, n_col;
        scanf("%d", &n_line);
        scanf("%d", &n_col);

        bool wall[n_line][n_col];

        for (int i = 0; i < n_line; ++i) {
            char line[150];
            scanf("%s", line);
            for (int j = 0; j < n_col; ++j) {
                wall[i][j] = (line[j]=='#');
            }
        }

        bool central[n_line][n_col];
        for (int i = 0; i < n_line; ++i) {
            for (int j = 0; j < n_col; ++j) {
                central[i][j] = false;
            }
        }
        for (int i = 0; i < n_line-1; ++i) {
            for (int j = 0; j < n_col-1; ++j) {
                if(!wallcentral[i][j] && wallcentral[i+1][j] && wallcentral[i][j+1] && wallcentral[i+1][j+1]){
                    central[i][j] = true;
                    central[i+1][j] = true;
                    central[i][j+1] = true;
                    central[i+1][j+1] = true;
                }
            }
        }

        int xi = 0;
        int xj = 0;
        int vi = 1;
        int vj = 0;

        bool foundWall = false;

        while(!foundWall){
            if(xi+vi < n_line && xj+vj < n_col){
                xi += vi;
                xj += vj;
                continue;
            }

        }

        bool foundCourtyard = false;

        while(!foundCourtyard){

        }


    }
    return 0;
}
