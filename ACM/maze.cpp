#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {

public:

    int idx;
    int dist;

    Node(int _idx, int _dist){
        idx = _idx;
        dist = _dist;
    }

    bool operator< (const Node& n2) const{
        return dist>n2.dist;
    }
};


int main() {

    int n_tc;
    scanf("%d", &n_tc);

    for (int tc = 0; tc < n_tc; ++tc) {
        int n_cells, exit, timer, n_conn;
        scanf("%d", &n_cells);
        scanf("%d", &exit);
        scanf("%d", &timer);
        scanf("%d", &n_conn);

        exit--;

        vector<Node> neighb[n_cells];

        for (int i = 0; i < n_cells; ++i) {
            neighb[i].clear();
        }

        for (int conn = 0; conn < n_conn; ++conn) {
            int a, b, cost;
            scanf("%d", &b);
            scanf("%d", &a);
            scanf("%d", &cost);

            b--;
            a--;

            neighb[a].push_back(Node(b, cost));
        }

        int dists[n_cells];
        for (int i = 0; i < n_cells; ++i) {
            dists[i] = -1;
        }
        dists[exit] = 0;
        bool treated[n_cells];
        for (int i = 0; i < n_cells; ++i) {
            treated[i] = false;
        }

        priority_queue<Node> nodes;
        nodes.push(Node(exit, 0));

        while(!nodes.empty()){
            int node = nodes.top().idx;
            nodes.pop();
            if(treated[node]) continue;

            treated[node] = true;

            for (unsigned int v_i = 0; v_i < neighb[node].size(); ++v_i) {
                int v = neighb[node][v_i].idx;
                int new_cost = dists[node] + neighb[node][v_i].dist;
                if(dists[v] < 0 || new_cost < dists[v]) {
                    dists[v] = new_cost;
                    nodes.push(Node(v, new_cost));
                }
            }

        }

        int result = 0;
        for (int i = 0; i < n_cells; ++i) {
            if( dists[i]>=0 && dists[i] <= timer) result++;
        }

        if(tc) printf("\n");
        printf("%d\n", result);
    }
    return 0;
}
