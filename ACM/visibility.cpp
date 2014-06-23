#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define MIN(a, b) ((a)<(b)?(a):(b))
#define MAX(a, b) ((a)>(b)?(a):(b))

using namespace std;

// True = left
bool cross(double x1,double  y1,double  x2,double  y2){
    return x1*y2-x2*y1 > 0;
}

double dot(double x1,double  y1,double  x2,double  y2){
    return x1*y1 + x2*y2;
}

double norme(double x, double y){
    return sqrt(x*x + y*y);
}

int main() {

    int tc = 0;

    while(1){
        ++tc;
        int n1, n2;
        scanf("%d", &n1);
        if(!n1) break;
        scanf("%d", &n2);

        int p1x[n1];
        int p1y[n1];
        int p2x[n2];
        int p2y[n2];

        double moy1x=0;
        double moy1y=0;
        double moy2x=0;
        double moy2y=0;


        for (int i = 0; i < n1; ++i) {
            scanf("%d", p1x+i);
            scanf("%d", p1y+i);
            moy1x+= p1x[i];
            moy1y+= p1y[i];

        }
        for (int i = 0; i < n2; ++i) {
            scanf("%d", p2x+i);
            scanf("%d", p2y+i);
            moy2x+= p2x[i];
            moy2y+= p2y[i];
        }

        moy1x /= n1;
        moy1y /= n1;
        moy2x /= n2;
        moy2y /= n2;

        double moyX = moy1x-moy2x;
        double moyY = moy1y-moy2y;
        double norm = norme(moyX, moyY);
        moyX /= norm;
        moyY /= norm;

        int imL1 = 0;
        int imR1 = 0;
        int imL2 = 0;
        int imR2 = 0;
        double maxCosL = 1;
        double maxCosR = 1;

        for (int vi1 = 0; vi1 < n1; ++vi1){
            for (int vi2 = 0; vi2 < n2; ++vi2){

                double vecX = p1x[vi1] - p2x[vi2];
                double vecY = p1y[vi1] - p2y[vi2];
                double normV = norme(vecX, vecY);
                vecX /= normV;
                vecY /= normV;


                double  angle = dot(vecX, vecY, moyX, moyY);

                if(cross(vecX, vecY, moyX, moyY)) {
                    if(angle < maxCosL){
                        maxCosL = angle;
                        imL1 = vi1;
                        imL2 = vi2;
                    }
                }
                else {
                    if(angle < maxCosR){
                        maxCosR = angle;
                        imR1 = vi1;
                        imR2 = vi2;
                    }
                }
            }
        }

        printf("Instance %d:\n", tc);
        double dirX = p1x[imR1] - p2x[imR2];
        double dirY = p1y[imR1] - p2y[imR2];
        if(dirX==0) printf("VERTICAL\n");
        else{
            double p= dirY/dirX;
            printf("%.3f\n", p);
        }
        for(int i=imR1; i<=imL1; ++i){
            printf("%d %d \n", p1x[i], p1y[i]);
        }

        dirX = p1x[imL1] - p2x[imL2];
        dirY = p1y[imL1] - p2y[imL2];
        if(dirX==0) printf("VERTICAL\n");
        else{
            double p= dirY/dirX;
            printf("%.3f\n", p);
        }
    }
    return 0;
}
