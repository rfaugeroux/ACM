#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

using namespace std;

double findDistance(double x, double y, int nw, int nh, int * pos){


    double dist = (y+x)*0.5;
    if(round(10*y)==round(10*x)) return y;
    int r_need = 1;

    int li = 0;
    for (int hi = 0; hi < nh; ++hi) {
        if(pos[hi]-pos[li]>2*dist){
            r_need++;
            if(r_need>nw) return findDistance(dist, y, nw, nh, pos);
            li = hi;
        }
    }
    return findDistance(x, dist, nw, nh, pos);
}

int main() {

    int tcs;
    scanf("%d", &tcs);

    while(tcs--){

        int nh, nw;
        scanf("%d", &nw);
        scanf("%d", &nh);

        int * d  = new int[nh];
        for (int i = 0; i < nh; ++i) {
            scanf("%d", d+i);
        }

        sort(d, d+nh);

        double result = findDistance(0, d[nh-1]-d[0], nw, nh, d);
        result = round(10*result)/10;

        printf("%.1f\n", result);
    }
    return 0;
}
