#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int>  couple;

class Edge {
public:
    int a, b, cost;

    Edge(int a0, int b0, int c){
        a = a0;
        b = b0;
        cost = c;
    }

    bool operator< (const Edge & n) const{
        return cost > n.cost;
    }


};


int find(int x, int * parent){
    return (parent[x]==x)?x:(parent[x]=find(parent[x], parent));
}

void unio(int x, int y, int * parent){
    parent[x] = find(y, parent);
}

int main() {

    int nv, ne;
    scanf("%d", &nv);
    scanf("%d", &ne);
    priority_queue<Edge> edges;
    vector<int> adj[nv];
    for (int i = 0; i < ne; ++i) {
        int a, b, c;
        scanf("%d", &a);
        scanf("%d", &b);
        scanf("%d", &c);
        edges.push(Edge(a, b, c));
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int nt = 0;

    int parent[nv];
    for (int i = 0; i < nv; ++i) {
        parent[i] = i;
    }

    vector<Edge> keptEdges;

    while(nt < nv-1){
        Edge e = edges.top();
        edges.pop();
        if(find(e.a, parent)==find(e.b, parent)) continue;
        unio(e.a, e.b, parent);
        nt++;
        keptEdges.push_back(e);
    }

    //    for (unsigned int i = 0; i < keptEdges.size(); ++i) {
    //        Edge edge = keptEdges[i];
    //        printf("%d %d %d\n", edge.a, edge.b, edge.cost);
    //    }

    int dist[nv];
    for (int i = 0; i < nv; ++i) {
        dist[i] = -1;
    }

    queue<couple> nodes;
    int start = 0;
    nodes.push(make_pair(start, 0));

    while(!nodes.empty()){
        couple node = nodes.front();
        nodes.pop();
        if(dist[node.first] != -1) continue;
        dist[node.first] = node.second;

        for (unsigned int vi = 0; vi < adj[node.first].size(); ++vi) {
            int neigh = adj[node.first][vi];
            if(dist[neigh]!=-1) continue;
            nodes.push(make_pair(neigh, node.second+1));
        }

    }

    printf("%d\n", dist[4]);

    return 0;
}
