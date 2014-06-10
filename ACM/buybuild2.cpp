#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {

public:
    int idx, cost;

    Node(int _idx, int _cost){
        idx = _idx;
        cost = _cost;
    }

    bool operator< (const Node& e2) const{
        return cost>e2.cost;
    }
};

int main() {

    int n_tc;
    scanf("%d", &n_tc);
    for (int tc = 0; tc < n_tc; ++tc) {
        if(tc) printf("\n");

        int n_city, n_subn;
        scanf("%d", &n_city);
        scanf("%d", &n_subn);

        bool subn[n_subn][n_city];
        for (int i = 0; i < n_subn; ++i) {
            for (int j = 0; j < n_city; ++j) {
                subn[i][j] = false;
            }
        }

        int subn_cost[n_subn];
        for (int i = 0; i < n_subn; ++i) {
            int sub_size;
            scanf("%d", &sub_size);
            int cost;
            scanf("%d", &cost);
            subn_cost[i] = cost;
            for (int j = 0; j < sub_size; ++j) {
                int city_idx;
                scanf("%d", &city_idx);
                subn[i][city_idx-1] = true;
            }
        }

        int coord[n_city][2];
        for (int i = 0; i < n_city; ++i) {
            int x,y;
            scanf("%d", &x);
            scanf("%d", &y);
            coord[i][0] = x;
            coord[i][1] = y;
        }

        int d[n_city][n_city];
        for (int i = 0; i < n_city; ++i) {
            for (int j = 0; j < n_city; ++j) {
                int a = coord[i][0]-coord[j][0];
                int b = coord[i][1]-coord[j][1];
                int dist = a*a + b*b;
                d[i][j] = dist;
                d[j][i] = dist;
            }
        }

        int result = -1;

        for (int mask = 0; mask < 1<<n_subn; ++mask) {
            vector<int> sel_net;

            int bits = mask;
            for (int i = 0; i < n_subn; ++i) {
                if(bits&1) sel_net.push_back(i);
                bits>>=1;
            }

            bool used[n_city];
            for (int i = 0; i < n_city; ++i) {
                used[i] = false;
            }
            priority_queue<Node> toAdd;
            used[0] = true;
            for (int i = 1; i < n_city; ++i) {
                int dist0 = d[0][i];
                for (unsigned int s_i = 0; s_i < sel_net.size(); ++s_i) {
                    if(subn[sel_net[s_i]][i] && subn[sel_net[s_i]][0]){
                        dist0 = 0;
                        break;
                    }
                }
                toAdd.push(Node(i, dist0));
            }

            int n_city_used = 1;
            int temp_cost = 0;
            for (unsigned int c_i = 0; c_i < sel_net.size(); ++c_i) {
                temp_cost += subn_cost[sel_net[c_i]];
            }
            while(n_city_used < n_city){

                Node e = toAdd.top();
                toAdd.pop();
                if(used[e.idx]) continue;
                used[e.idx] = true;
                temp_cost += e.cost;
                ++n_city_used;
                for (int i = 0; i < n_city; ++i) {
                    if(i==e.idx || used[i]) continue;
                    int distance = d[e.idx][i];
                    for (unsigned int net_i = 0; net_i < sel_net.size(); ++net_i) {
                        if(subn[sel_net[net_i]][e.idx] && subn[sel_net[net_i]][i]) {
                            distance = 0;
                            break;
                        }
                    }
                    toAdd.push(Node(i, distance));
                }
            }
            if(temp_cost<result || result == -1){
                result = temp_cost;
            }
        }
        printf("%d\n", result);
    }
    return 0;
}
