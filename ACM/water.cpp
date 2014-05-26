#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;


int main() {

    int n_tc;
    scanf("%d", &n_tc);

    for (int tc = 0; tc < n_tc; ++tc) {
        int n_cist;
        scanf("%d", &n_cist);
        map<float, float> surface;
        surface[0] = 0;
        for (int i = 0; i < n_cist; ++i) {
            float level, height, width, depth;
            scanf("%f", &level);
            scanf("%f", &height);
            scanf("%f", &width);
            scanf("%f", &depth);
            float mult = width*depth;
            surface[level] = mult;
            surface[level+height] = -mult;
            cout << level << endl;
            cout << level+height << endl;

        }

        float volume;
        scanf("%f", &volume);

        float curr_v = 0;
        float curr_l = 0;
        float m = 0;
        bool found = false;
        for (map<float, float>::iterator i = surface.begin(); i != surface.end(); ++i) {
            if((++i)==surface.end()) break;
            --i;
            map<float, float>::iterator next = ++i;
            --i;
            cout << "I: " << i->first<< " and next: " << next->first << endl;
            m += i->second;
            float curr_h = next->first - i->first;
            float next_v = curr_h*m + curr_v;
            if(volume >= curr_v && volume < next_v) {
                float k = (volume - curr_v)/m;
                printf("%f\n", curr_h+k);
                found = true;
                break;
            }
            curr_v = next_v;
            curr_l += curr_h;
        }
        if(!found) printf("OVERFLOW\n");
    }
    return 0;
}
