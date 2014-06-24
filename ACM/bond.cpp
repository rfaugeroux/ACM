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

class Arete {
public:
    int a1;
    int a2;
    int weight;


    Arete(int _a1, int _a2, int w){
        a1 = _a1;
        a2 = _a2;
        weight = w;
    }

        bool operator< (const Arete& e2) const {
        return weight > e2.weight;
    }
};


int main() {

    int y = -1;

    while(1){
        int ntown, nroad;
        int ret = scanf("%d", &ntown);
        if (!ret || ret==EOF) break;

        if(++y) printf("\n");

        scanf("%d", &nroad);

        vector<Arete> adj[ntown];

        for (int i = 0; i < nroad; ++i) {

            int dep, arr, danger;

            scanf("%d", &dep);
            scanf("%d", &arr);
            scanf("%d", &danger);

            dep--;
            arr--;

            adj[dep].push_back(Arete(arr, dep, danger));
            adj[arr].push_back(Arete(dep, arr, danger));
        }


        priority_queue<Arete> depAdd;

        int father[ntown];
        int cost[ntown];
        int depth[ntown];

        depth[0]=-1;

        for (int i = 0; i < ntown; ++i) {
            father[i]=-1;
        }

        depAdd.push(Arete(0,0,0));

        int nAdded=0;

        while(nAdded<ntown){
            if(depAdd.empty()){
                for (int i = 0; i < ntown; ++i) {
                    if(father[i]==-1){
                        depAdd.push(Arete(i,i,0));
                        depth[i]=-1;
                        break;
                    }
                }
            }
            Arete n = depAdd.top();
            depAdd.pop();
            if(father[n.a1]!=-1) continue;
            nAdded++;
            father[n.a1] = n.a2;
            cost[n.a1] = n.weight;
            depth[n.a1] = depth[n.a2]+1;
            for (unsigned int vi = 0; vi < adj[n.a1].size(); ++vi) {
                Arete e = adj[n.a1][vi];
                if(father[e.a1]!=-1) continue;
                depAdd.push(e);
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
