#include <cstdio>
#include <iostream>
#include <vector>

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
        for (int start = 0; start < total; ++start) {
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

            }
        }

        printf("Case %d: ", tc);
        if(min_cycle == -1) printf("impossible\n", tc);
        else printf("%d\n", min_cycle);
    }
    return 0;
}
