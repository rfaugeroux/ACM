#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>

#define MAX(a, b) ((a)>(b)?(a):(b))
#define MIN(a, b) ((a)<(b)?(a):(b))

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

int parent[50000];
int cost[50000];

int find_parent(int x) {

    return (parent[x]==x)?x:
                          parent[x] = find_parent(parent[x]);
}

int find_cost(int x) {
    return (cost[x]==x)?x:
                          parent[x] = find_parent(parent[x]);
}

void connect(int x, int y, int cost){
    parent[find_parent(y)]=find_parent(x);
}

int main() {

    int tc = -1;

    while(1){
        int nc, nr;
        int ret = scanf("%d", &nc);
        if (!ret || ret==EOF) break;

        if(++tc) printf("\n");

        scanf("%d", &nr);

        priority_queue<Edge> edges;

        for (int i = 0; i < nr; ++i) {
            int to, from, danger;
            scanf("%d", &to);
            scanf("%d", &from);
            scanf("%d", &danger);
            edges.push(Edge(to-1, from-1, danger));
        }

        int np;
        scanf("%d", &np);

        int start[nc];
        int end[nc];
        for (int i = 0; i < nc; ++i) {
            start[i]=-1;
            end[i]=-1;
        }

        for (int i = 0; i < np; ++i) {
            int st, en;
            scanf("%d", &st);
            scanf("%d", &en);
            st--;
            en--;
            start[st] = en;
            end[en] = st;
        }

        int result[np];
        for (int i = 0; i < np; ++i) {
            result[i]=-1;
        }

        for (int i = 0; i < nc; ++i) {
            parent[i]=i;
        }

        while(edges.empty()){

            Edge e = edges.top();
            edges.pop();


        }
        printf("%d\n", dist[si][ei]);
    }
    return 0;
}
