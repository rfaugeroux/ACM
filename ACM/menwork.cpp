#include <cstdio>
#include <iostream>

using namespace std;


int main() {

    bool notfirst = false;
    while(1){

        int N;
        int ret = scanf("%d", &N);
        if(!ret || ret==EOF) break;
        if(notfirst) printf("\n");
        notfirst = true;

        int offset[N][N];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                offset[i][j] = 0;
            }
        }

        int period[N][N];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                period[i][j] = 0;
            }
        }

        for (int i = 0; i < N; ++i) {
            char line[N+5];
            scanf("%s", line);
            for (int j = 0; j < N; ++j) {
                if(line[j]=='*') offset[i][j]=1;
            }
        }

        for (int i = 0; i < N; ++i) {
            char line[N+5];
            scanf("%s", line);
            for (int j = 0; j < N; ++j) {
                period[i][j] = line[j] - '0';
            }
        }

        int MAX_T = N*N*9;
        bool reach[N][N];
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                reach[j][k] = false;
            }
        }

        reach[0][0]=1;
        int result=0;
        for (int t = 0; t < MAX_T-1; ++t) {

            if(reach[N-1][N-1]) result = t;

            bool new_reach[N][N];
            for (int a = 0; a < N; ++a) {
                for (int b = 0; b < N; ++b) {
                    new_reach[a][b] = false;
                }
            }

            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if(!reach[i][j]) continue;

                    //Rest
                    new_reach[i][j] = new_reach[i][j] || !period[i][j] || ((t+1)/period[i][j])%2 == offset[i][j];

                    //Left right up down
                    for (int off = -1; off < 2; off+=2) {
                        for (int sel = 0; sel < 2; ++sel) {
                            int nxt_i = i + sel*off;
                            int nxt_j = j + (1-sel)*off;
                            if(nxt_i>=0 && nxt_i<N && nxt_j>=0 && nxt_j<N){
                                if(!period[nxt_i][nxt_j]){
                                    if(!offset[nxt_i][nxt_j]) new_reach[nxt_i][nxt_j] = true;
                                    continue;
                                }
                                if(((t+1)/period[nxt_i][nxt_j]) % 2 == offset[nxt_i][nxt_j]){
                                    new_reach[nxt_i][nxt_j] = true;
                                }
                            }
                        }
                    }
                }
            }

            for (int a = 0; a < N; ++a) {
                for (int b = 0; b < N; ++b) {
                    reach[a][b] = new_reach[a][b];
                }
            }

            if(result) break;
        }
        if(result) printf("%d\n", result);
        else printf("NO\n");
    }
    return 0;
}
