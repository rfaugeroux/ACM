#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n_v, n_e;
    scanf("%d", &n_v);
    scanf("%d", &n_e);

    int dist[n_v][n_v];

    for (int i = 0; i < n_v; ++i) {
        for (int j = 0; j < n_v; ++j) {
            dist[i][j] = i==j?0:-1;
        }
    }

    for (int i = 0; i < n_e; ++i) {
        int a, b;
        scanf("%d", &a);
        scanf("%d", &b);
        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    int min_cycle = -1;

    for (int k = 0; k < n_v; ++k) {
        for (int i = 0; i < n_v; ++i) {
            for (int j = 0; j < n_v; ++j) {
                if(i==j || k==j || k==i) continue;
                int dist1 = dist[i][j];
                if(dist[i][k]==-1 || dist[k][j]==-1){
                    continue;
                }
                int dist2 = dist[i][k] + dist[k][j];
                if(dist1==-1){
                    dist[i][j] = dist2;
                    continue;
                }
                if(dist1+dist2==6) cout << "Ici: " << i << " " << j << " " << k << endl;

                if(min_cycle==-1 || dist1+dist2 < min_cycle){
                    min_cycle = dist1+dist2;
                    cout << i << " " << j << " " << k << endl;
                    cout << dist1 << " " << dist2 << endl;
                    cout << "-------" << endl;
                }
                if(dist2<dist1) dist[i][j] = dist2;
            }
        }
    }

    for (int i = 0; i < n_v; ++i) {
        for (int j = 0; j < n_v; ++j) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    if (min_cycle != -1) printf("%d\n", min_cycle);
    else printf("No cycle\n");

    return 0;
}
