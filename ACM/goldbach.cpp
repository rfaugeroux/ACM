#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int max = 1000000;

    bool prime[max+1];

    for (int i = 0; i < max+1; ++i) {
        prime[i] = true;
    }

    prime[0] = false;
    prime[1] = false;

    for (int i = 0; i < max+1; ++i) {
        if(prime[i]){
            int k = 2;
            while (k*i < max+1){
                prime[k*i] = false;
                k++;
            }
        }
    }

    int n;

    while (true){
        scanf("%d", &n);

        if (n==0) break;

        for (int i = 0; i < n; ++i) {
            if(prime[i] && prime[n-i]){
                printf("%d = %d + %d\n", n, i, n-i);
                break;
            }
        }


    }

    return 0;
}
