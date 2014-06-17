#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

using namespace std;

float solve(float li, float ri, int nw, int nh, int * d){

    if(nw==1) return (d[li]+d[ri])*0.5;

    float middle = (d[li]+d[ri])*0.5;

    if(li==ri) return 0;

    vector<int> leftH;
    vector<int> rightH;

    for (int i = li; i <= ri; ++i) {
        if(d[i]<middle) leftH.push_back(i);
        else rightH.push_back(i);
    }




}

int main() {

    int ntc;
    scanf("%d", &ntc);

    for (int tc = 0; tc < ntc; ++tc) {

        int nh, nw;
        scanf("%d", &nw);
        scanf("%d", &nh);

        int d[nh];
        for (int i = 0; i < nh; ++i) {
            scanf("%d", d+i);
        }

        sort(d, d+nh);

        float result = solve(d[0], d[nh-1]);

    }

    return 0;
}
