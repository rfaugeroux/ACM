#include <cstdio>
#include <iostream>


using namespace std;

int main() {

    while(1){

        int nr, nc, nw;
        int ret = scanf("%d", &nr);
        if(!ret || ret==EOF) break;

        scanf("%d", &nc);
        scanf("%d", &nw);

        string words[nw];


        for(int i=0; i<nw; ++i){
            cin >> words[i];
        }

        char c;
        scanf("%c", &c);

        char grid[nr][nc];

        for(int i=0; i<nr; ++i){
            for(int j=0; j<nc; ++j){
                scanf("%c", grid[i]+j);
            }
            scanf("%c", &c);
        }

        bool highlighted[nr][nc];
        for(int i=0; i<nr; ++i){
            for(int j=0; j<nc; ++j){
                highlighted[i][j] = false;
            }
        }

        int found[nw];
        for(int i=0; i<nw; ++i){
            found[i] = 0;
        }


        for (int dir_i=-1; dir_i<=1; ++dir_i){
            for (int dir_j=-1; dir_j<=1; ++dir_j){
                if(dir_i==0 && dir_j==0) continue;
                for (int wi=0; wi < nw; ++wi) {
                    string w = words[wi];
                    int l = w.length();
                    int si = dir_i<0?l-1:0;
                    int ei = dir_i>0?nr-l+1:nr;
                    int sj = dir_j<0?l-1:0;
                    int ej = dir_j>0?nc-l+1:nc;
                    for (int i = si; i<ei; ++i){
                        for (int j = sj; j<ej; ++j){
                            int k=0;
                            while(k<l && grid[i+dir_i*k][j+dir_j*k]==w[k]) ++k;
                            if(k==l){
                                found[wi]++;
                                for(int p=0; p<l; ++p){
                                    highlighted[i+dir_i*p][j+dir_j*p] = true;
                                }
                            }
                        }
                    }
                }
            }
        }

        for(int i=0; i<nr; ++i){
            for(int j=0; j<nc; ++j){
                if(!highlighted[i][j]) printf("%c", grid[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
