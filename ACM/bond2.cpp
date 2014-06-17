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

class Node {
public:
    int idx, dist;

    Node(int i, int c){
        idx = i;
        dist = c;
    }

    bool operator< (const Node& n2) const {
        return dist > n2.dist;
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

        vector<Node> adj[nc];

        for (int i = 0; i < nr; ++i) {
            int to, from, danger;
            scanf("%d", &to);
            scanf("%d", &from);
            scanf("%d", &danger);
            to--;
            from--;
            adj[to].push_back(Node(from, danger));
            adj[from].push_back(Node(to, danger));
        }

        int np;
        scanf("%d", &np);

        map<int, map<int, int> > dist;

        int start[np];
        int end[np];
        for (int i = 0; i < np; ++i) {
            int st, en;
            scanf("%d", &st);
            scanf("%d", &en);
            start[i] = st-1;
            end[i] = en-1;
        }

        for (int pi = 0; pi < np; ++pi) {
            int si = start[pi];
            int ei = end[pi];

            set<int> visited;
            priority_queue<Node> toVisit;
            toVisit.push(Node(si, 0));

            while(!toVisit.empty()){
                Node node = toVisit.top();
                toVisit.pop();
                if(visited.count(node.idx)) continue;
                visited.insert(node.idx);

                dist[si][node.idx] = node.dist;
                dist[node.idx][si] = node.dist;
                if(node.idx==ei) {
                    break;
                }
                if(dist.count(node.idx) && dist[node.idx].count(ei)){
                    dist[si][ei] = max(dist[node.idx][ei], dist[si][node.idx]);
                    dist[ei][si] = dist[si][ei];
                    break;
                }
                for (unsigned int vi = 0; vi < adj[node.idx].size(); ++vi) {
                    Node v = adj[node.idx][vi];
                    if(visited.count(v.idx)) continue;
                    toVisit.push(Node(v.idx, max(node.dist,v.dist)));
                }
            }
            printf("%d\n", dist[si][ei]);
        }
    }
    return 0;
}