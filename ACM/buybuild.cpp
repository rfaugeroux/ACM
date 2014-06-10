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

        //Initial EMST (without sub-networks)
        bool used0[n_city];
        for (int i = 0; i < n_city; ++i) {
            used0[i] = false;
        }
        priority_queue<Node> toAdd;
        used0[0] = true;
        for (int i = 1; i < n_city; ++i) {
            toAdd.push(Node(i, d[0][i]));
        }

        int n_cities_used = 1;
        int mst_cost = 0;
        while(n_cities_used < n_city){

            Node e = toAdd.top();
            toAdd.pop();
            if(used0[e.idx]) continue;
            used0[e.idx] = true;
            mst_cost += e.cost;
            ++n_cities_used;
            for (int i = 0; i < n_city; ++i) {
                if(i==e.idx || used0[i]) continue;
                toAdd.push(Node(i, d[e.idx][i]));
            }
        }

        vector<int> selected_networks;
        vector<int> net_left;
        for (int i = 0; i < n_subn; ++i) {
            net_left.push_back(i);
        }

        for (int n_s = 0; n_s < n_subn; ++n_s) {
            int best_net = -1;
            for (unsigned int sub_i = 0; sub_i < net_left.size(); ++sub_i) {
                bool used[n_city];
                for (int i = 0; i < n_city; ++i) {
                    used[i] = false;
                }
                priority_queue<Node> toAdd;
                used[0] = true;
                for (int i = 1; i < n_city; ++i) {
                    int dist0 = d[0][i];
                    for (unsigned int s_i = 0; s_i < selected_networks.size(); ++s_i) {
                        if(subn[selected_networks[s_i]][i] && subn[selected_networks[s_i]][0]){
                            dist0 = 0;
                            break;
                        }
                    }
                    if(subn[net_left[sub_i]][0] && subn[net_left[0]][i]) dist0 = 0;
                    toAdd.push(Node(i, dist0));
                }

                int n_city_used = 1;
                int temp_cost = subn_cost[net_left[sub_i]];
                for (unsigned int c_i = 0; c_i < selected_networks.size(); ++c_i) {
                    temp_cost += subn_cost[selected_networks[c_i]];
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
                        for (unsigned int net_i = 0; net_i < selected_networks.size(); ++net_i) {
                            if(subn[selected_networks[net_i]][e.idx] && subn[selected_networks[net_i]][i]) {
                                distance = 0;
                                break;
                            }
                        }
                        if(subn[net_left[sub_i]][e.idx] && subn[net_left[sub_i]][i]) distance = 0;
                        toAdd.push(Node(i, distance));
                    }
                }
                if(temp_cost<mst_cost){
                    mst_cost = temp_cost;
                    best_net = sub_i;
                }
            }
            if(best_net==-1) break;
            selected_networks.push_back(net_left[best_net]);
            net_left.erase(net_left.begin()+best_net);
        }
        printf("%d\n", mst_cost);
    }
    return 0;
}
