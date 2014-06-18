#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

using namespace std;

double solve(double l, double r, int nw, int nh, int * pos){


    double dist = (r+l)*0.5;
    if(round(10*r)==round(10*l)) return r;
    int r_need = 1;

    int li = 0;
    for (int hi = 0; hi < nh; ++hi) {
        if(pos[hi]-pos[li]>2*dist){
            r_need++;
            if(r_need>nw) return solve(dist, r, nw, nh, pos);
            li = hi;
        }
    }
    return solve(l, dist, nw, nh, pos);
}

int main() {

    int tc;
    scanf("%d", &tc);

    while(tc--){

        int nh, nw;
        scanf("%d", &nw);
        scanf("%d", &nh);

        int * d  = new int[nh];
        for (int i = 0; i < nh; ++i) {
            scanf("%d", d+i);
        }

        sort(d, d+nh);

        double result = solve(0, d[nh-1]-d[0], nw, nh, d);
        result = round(10*result)/10;

        printf("%.1f\n", result);
    }
    return 0;
}
