#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool valid(vector<float> pos, float cut_width, float size) {
    sort(pos.begin(), pos.end());
    if (2*pos[0] > cut_width) return false;
    for (int i = 0; i < pos.size()-1; ++i) {
        if (pos[i+1]-pos[i] > cut_width) return false;
    }
    if (2*(size - pos.back()) > cut_width) return false;
    return true;
}


int main() {

    float height = 100;
    float width = 75;

    int nx = 1;
    int ny = 1;
    float w = 1;

    while (true){
        scanf("%d", &nx);
        scanf("%d", &ny);
        scanf("%f", &w);

        vector<float> posX(nx);
        vector<float> posY(ny);

        if (nx==0) break;

        for (int i = 0; i < nx; ++i) {
            float p;
            scanf("%f", &p);
            posX.push_back(p);
        }

        for (int i = 0; i < ny; ++i) {
            float p;
            scanf("%f", &p);
            posY.push_back(p);
        }

        if (valid(posX, w, width) && valid(posY, w, height)) {
            printf("YES\n");
            continue;
        }

        printf("NO\n");
    }

    return 0;
}
