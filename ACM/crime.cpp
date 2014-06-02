#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;


int main() {

    while(1){
        int n_street, n_inter;
        int ret = scanf("%d", &n_inter);
        if(!ret || ret==EOF) break;
        scanf("%d", &n_street);

        vector<int> conn[n_inter];
        for (int i = 0; i < n_street; ++i) {
            int s1, s2;
            scanf("%d", &s1);
            scanf("%d", &s2);
            s1--;
            s2--;
            conn[s1].push_back(s2);
            conn[s2].push_back(s1);
        }

        int n_visited = 0;
        int result = 0;
        int status[n_inter];
        for (int i = 0; i < n_inter; ++i) {
            status[i] = -1;
        }

        bool impossible = false;

        while(n_visited < n_inter and !impossible) {

            int start=-1;
            for (int i = 0; i < n_inter; ++i) {
                if(status[i]==-1){
                    start = i;
                    break;
                }
            }
            int n_station = 0;
            int n_interconn = 0;

            vector<int> toVisit;
            toVisit.push_back(start);
            status[start] = 0;
            while(!toVisit.empty()){
                int inter = toVisit.back();
                toVisit.pop_back();
                n_visited++;
                n_interconn++;
                for (unsigned int v_i = 0; v_i < conn[inter].size(); ++v_i) {
                    int v = conn[inter][v_i];
                    if(status[v]==-1){
                        status[v] = (status[inter]+1) %2;
                        n_station += status[v];
                        toVisit.push_back(v);
                        continue;
                    }
                    if(status[v]==status[inter]){
                        printf("Impossible\n");
                        impossible = true;
                        break;
                    }
                }
                if(impossible) break;
            }
            result += (2*n_station>n_interconn)?n_interconn-n_station:n_station;
        }
        if(!impossible) printf("%d\n", result);
    }
    return 0;
}
