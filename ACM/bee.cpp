#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

    int n_tc;
    scanf("%d", &n_tc);

    for (int tc = 0; tc < n_tc; ++tc) {

        int n_v, n_e;
        scanf("%d", &n_v);
        scanf("%d", &n_e);
        vector<int> adj_list[n_v];

        for (int i = 0; i < n_e; ++i) {
            int a, b;
            scanf("%d", &a);
            scanf("%d", &b);
            adj_list[a].push_back(b);
            adj_list[b].push_back(a);
        }

        int min_cycle = -1;
        for (int start = 0; start < n_v; ++start) {
            int father[n_v];
            int dist[n_v];
            for (int i = 0; i < n_v; ++i) {
                father[i]=-1;
                dist[i] = -1;
            }
            dist[start] = 0;
            father[start] = start;

            queue<int> toVisit;
            toVisit.push(start);

            while(!toVisit.empty()){
                int node = toVisit.front();
                toVisit.pop();
                for (unsigned int v_i = 0; v_i < adj_list[node].size(); ++v_i) {
                    int voisin = adj_list[node][v_i];
                    if(dist[voisin]==-1){
                        dist[voisin] = dist[node] + 1;
                        father[voisin] = node;
                        toVisit.push(voisin);
                        continue;
                    }
                    if(father[node]!=voisin && voisin!=start){
                        int cycle_dist =  dist[voisin] + dist[node] + 1;
                        if(min_cycle==-1 || min_cycle > cycle_dist){
                            min_cycle = cycle_dist;
                        }
                    }
                }
            }
        }

        printf("Case %d: ", tc+1);
        if(min_cycle == -1) printf("impossible\n");
        else printf("%d\n", min_cycle);
    }
    return 0;
}
