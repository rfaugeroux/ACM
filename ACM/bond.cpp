#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>

#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))

using namespace std;

class Edge {
public:
    int a, b, cost;

    Edge(int i, int j, int c){
        a = i;
        b = j;
        cost = c;
    }

    bool operator< (const Edge& e2) const {
        return cost > e2.cost;
    }
};


int main() {

    int tc = -1;

    while(1){
        int nc, nr;
        int ret = scanf("%d", &nc);
        if (!ret || ret==EOF) break;

        if(++tc) printf("\n");

        scanf("%d", &nr);

        vector<Edge> adj[nc];

        for (int i = 0; i < nr; ++i) {
            int to, from, danger;
            scanf("%d", &to);
            scanf("%d", &from);
            scanf("%d", &danger);
            to--;
            from--;
            adj[to].push_back(Edge(from, to, danger));
            adj[from].push_back(Edge(to, from, danger));
        }


        priority_queue<Edge> toAdd;

        int father[nc];
        int cost[nc];
        int depth[nc];
        depth[0]=-1;
        for (int i = 0; i < nc; ++i) {
            father[i]=-1;
        }

        toAdd.push(Edge(0,0,0));
        int nAdded=0;
        while(nAdded<nc){
            Edge n = toAdd.top();
            toAdd.pop();
            if(father[n.a]!=-1) continue;
            nAdded++;
            father[n.a] = n.b;
            cost[n.a] = n.cost;
            depth[n.a] = depth[n.b]+1;
            for (unsigned int vi = 0; vi < adj[n.a].size(); ++vi) {
                Edge e = adj[n.a][vi];
                if(father[e.a]!=-1) continue;
                toAdd.push(e);
            }
        }

        int np;
        scanf("%d", &np);

        for (int i = 0; i < np; ++i) {
            int st, en;
            scanf("%d", &st);
            scanf("%d", &en);
            st--;
            en--;

            int d=0;

            while(depth[st]>depth[en]){
                d = max(d, cost[st]);
                st = father[st];
            }
            while(depth[st]<depth[en]){
                d = max(d, cost[en]);
                en = father[en];
            }
            while(st!=en){
                d = max(d, cost[st]);
                st = father[st];
                d = max(d, cost[en]);
                en = father[en];
            }
            printf("%d\n", d);
        }
    }
    return 0;
}
