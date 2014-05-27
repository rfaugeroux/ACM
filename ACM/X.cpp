#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {

public:

    int idx;
    int dist;

    Node(int _idx, int _dist){
        idx = _idx;
        dist = _dist;
    }

    bool operator< (const Node& n2) const{
        return dist>n2.dist;
    }
};


int main() {

    int n_tc;
    scanf("%d", &n_tc);

    for (int tc = 0; tc < n_tc; ++tc) {
        if(tc) printf("\n");

        int n_X;
        scanf("%d", &n_X);

        vector<int> amis[n_X];

        for (int i = 0; i < n_X; ++i) {
            int firstX, n_v;
            scanf("%d", &firstX);
            scanf("%d", &n_v);

            for (int j = 0; j < n_v; ++j) {
                int voisin;
                scanf("%d", &voisin);
                amis[firstX].push_back(voisin);
            }
        }

        int from, to;
        scanf("%d", &from);
        scanf("%d", &to);

        priority_queue<Node> conn_left;
        bool treated[n_X];
        for (int i = 0; i < n_X; ++i) {
            treated[i]=false;
        }
        conn_left.push(Node(from, 0));

        while(!conn_left.empty()){
            Node next = conn_left.top();
            conn_left.pop();
            if(treated[next.idx]){
                continue;
            }
            if(next.idx == to){
                printf("%d %d %d\n", from, to, next.dist-1);
                break;
            }
            treated[next.idx] = true;
            for (unsigned int a_i = 0; a_i < amis[next.idx].size(); ++a_i) {
                int ami = amis[next.idx][a_i];
                if(!treated[ami]) conn_left.push(Node(ami, next.dist+1));
            }
        }
    }
    return 0;
}
