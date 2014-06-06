#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n_tc;
    scanf("%d", &n_tc);
    for (int tc = 0; tc < n_tc; ++tc) {
        if(tc) printf("\n");

        int n_city, n_subn;
        scanf("%d", &n_city);
        scanf("%d", &n_subn);
        vector<int> subn[n_subn];
        int subn_cost[n_subn];
        int coord[n_city][2];
        for (int i = 0; i < n_subn; ++i) {
            int sub_size;
            scanf("%d", &sub_size);
            int cost;
            scanf("%d", &cost);
            subn_cost[i] = cost;
            for (int j = 0; j < sub_size; ++j) {
                int city_idx;
                scanf("%d", &city_idx);
                subn[i].push_back(city_idx-1);
            }
        }

        for (int i = 0; i < n_city; ++i) {
            int x,y;
            scanf("%d", &x);
            scanf("%d", &y);
            coord[i][0] = x;
            coord[j][1] = y;
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


    }
    return 0;
}
