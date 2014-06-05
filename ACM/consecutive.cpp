#include <cstdio>
#include <iostream>
#include <set>
#include <vector>

#define MAX_COL 450

using namespace std;

int main() {

    int n_tc;
    scanf("%d", &n_tc);

    for (int tc = 0; tc < n_tc; ++tc) {
        if(tc) printf("\n");

        int n_l, n_c;
        scanf("%d", &n_l);
        scanf("%d", &n_c);

        set<int> belong[n_c];
        set<int> group[n_l];

        for (int i = 0; i < n_l; ++i) {
            char next[MAX_COL];
            scanf("%s", next);
            for (int j = 0; j < n_c; ++j) {
                if(next[j]=='1'){
                    belong[j].insert(i);
                    group[i].insert(j);
                }
            }
        }

        for (int i = 0; i < n_l; ++i) {
            if(group[i].size()==1){
                set<int>::iterator it = group[i].begin();
                belong[*it].erase(i);
            }
        }


        int last = -1;
        for (int i = 0; i < n_c; ++i) {
            if(belong[i].size()==0) last = i;
        }

        int val = 0;
        int n_perm = 1;
        printf("%d\n", 0);

        while(n_perm<n_c){

            int next=-1;
            int min_size = n_c+2;
            int gr_i=-1;
            for (set<int>::iterator gr = belong[val].begin(); gr!=belong[val].end(); ++gr){
                if(group[*gr].size()<min_size){
                    min_size = group[*gr].size();
                    gr_i = *gr;
                    if(min_size==2) break;
                }
            }
            if(gr_i==-1) {
                printf("%d\n", last);
                break;
            }

            if(min_size==2){
                int first, sec;
                set<int>::iterator it = group[gr_i].begin();
                first = *it;
                it++;
                sec = *it;
                next = first==val?sec:first;
            }
            else {
                int min_d = n_c;
                for (set<int>::iterator cand = group[gr_i].begin(); cand!=group[gr_i].end(); ++cand){
                    if(*cand==val) continue;
                    if(belong[*cand].size()<min_d){
                        min_d = belong[*cand].size();
                        next = *cand;
                    }
                }
            }
            for (set<int>::iterator gr = belong[val].begin(); gr!=belong[val].end(); ++gr){
                group[*gr].erase(val);
                if(group[*gr].size()==1){
                    belong[*group[*gr].begin()].erase(*gr);
                }
            }
            printf("%d\n", next);
            val = next;
            n_perm++;
        }

    }
    return 0;
}
