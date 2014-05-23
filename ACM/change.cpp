#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;



int main() {

    int N;
    scanf("%d", &N);

    for (int test_case = 0; test_case < N; ++test_case) {
        int amount, n_val;
        scanf("%d%d", &amount, &n_val);

        vector<int> values;
        int val;
        scanf("%d", &val);
        values.push_back(val);
        for (int i = 1; i < n_val; ++i) {
            scanf("%d", &val);
            values.push_back(values.back() + val);
        }

        bool can[amount+1];
        can[0] = true;
        for (int i = 1; i < amount+1; ++i) {
            can[i] = false;
        }

        for (int val_i = 0; val_i < n_val; ++val_i) {
            int value = values.at(val_i);
            for (int am = value; am < amount+1; ++am) {
                can[am] = can[am] || can[am-value];
            }
        }
        if (can[amount]) {
            printf("YES\n\n");
        }
        else {
            printf("NO\n\n");
        }
    }
    return 0;
}
