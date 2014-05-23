#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main() {

    int n_tc;
    scanf("%d", &n_tc);

    for (int tc = 0; tc < n_tc; ++tc) {

        if(tc) printf("\n");

        int n_task;
        scanf("%d", &n_task);
        int n_rule;
        scanf("%d", &n_rule);

        vector<int> dependent[n_task];

        for (int i = 0; i < n_rule; ++i) {

            int task, n_d;
            scanf("%d", &task);
            task--;
            scanf("%d", &n_d);
            for (int j = 0; j < n_d; ++j) {
                int dep;
                scanf("%d", &dep);
                dep--;
                dependent[dep].push_back(task);
            }
        }

        int left_dep[n_task];
        for (int i = 0; i < n_task; ++i) {
            left_dep[i] = 0;
        }

        for (int i = 0; i < n_task; ++i) {
            vector<int> tasks = dependent[i];
            for (unsigned int j = 0; j < tasks.size(); ++j) {
                left_dep[tasks[j]]++;
            }
        }

        priority_queue<int, vector<int>, greater<int> > available_tasks;

        for (int i = 0; i < n_task; ++i) {
            if(!left_dep[i]) available_tasks.push(i);
        }

        while(!available_tasks.empty()) {
            int to_add = available_tasks.top();
            available_tasks.pop();
            //if(left_dep[to_add]==-1){
            //    continue;
            //}
            //left_dep[to_add] = -1;
            printf("%d", to_add+1);
            vector<int> deps = dependent[to_add];
            for (unsigned int d = 0; d < deps.size(); ++d) {
                if(!--left_dep[deps[d]]) available_tasks.push(deps[d]);
            }
            if(!available_tasks.empty()) printf(" ");
        }
        printf("\n");
    }

    return 0;
}
