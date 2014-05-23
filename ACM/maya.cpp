#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int * convert(int absolute){
    int * result = new int[5];
    result[0] = absolute / 144000;
    absolute -= result[0] * 144000;
    result[1] = absolute / 7200;
    absolute -= result[1] * 7200;
    result[2] = absolute / 360;
    absolute -= result[2] * 360;
    result[3] = absolute / 20;
    absolute -= result[3] * 20;
    result[4] = absolute;

    return result;
}

void print(int p[]){
    cout << p[0] << " " << p[1] << " " << p[2] << " " << p[3] << " " <<endl;
    cout << "----------" << endl;
}



int main() {

    int start = 8*144000;
    int MAX = 144000*2;
    int PERIOD = 260*365/5;

    int** dates = new int*[MAX];
    for (int i = 0; i < MAX; ++i) {
        dates[i] = new int[4];
    }

    dates[0][0] = 8;
    dates[0][1] = 19;
    dates[0][2] = 2;
    dates[0][3] = 2;

    for (int i = 1; i < MAX; ++i) {
        dates[i][0] = (dates[i-1][0]+1) % 13;
        dates[i][1] = (dates[i-1][1]+1) % 20;
        if (dates[i-1][3]==18 && dates[i-1][2]==4){
            dates[i][2] = 0;
            dates[i][3] = 0;
            continue;
        }
        dates[i][2] = (dates[i-1][2]+1) % 20;
        if(!dates[i][2]){
            dates[i][3] = (dates[i-1][3]+1) % 19;
        }
        else {
            dates[i][3] = dates[i-1][3];
        }
    }

    map<string, int> trad;
    trad["Imix"] = 0;
    trad["Ik"] = 1;
    trad["Akbal"] = 2;
    trad["Kan"] = 3;
    trad["Chikchan"] = 4;
    trad["Kimi"] = 5;
    trad["Manik"] = 6;
    trad["Lamat"] = 7;
    trad["Muluk"] = 8;
    trad["Ok"] = 9;
    trad["Chuen"] = 10;
    trad["Eb"] = 11;
    trad["Ben"] = 12;
    trad["Ix"] = 13;
    trad["Men"] = 14;
    trad["Kib"] = 15;
    trad["Kaban"] = 16;
    trad["Etznab"] = 17;
    trad["Kawak"] = 18;
    trad["Ajaw"] = 19;

    int month = 0;
    trad["Pohp"] = month++;
    trad["Wo"] = month++;
    trad["Sip"] = month++;
    trad["Zotz"] = month++;
    trad["Sek"] = month++;
    trad["Xul"] = month++;
    trad["Yaxkin"] = month++;
    trad["Mol"] = month++;
    trad["Chen"] = month++;
    trad["Yax"] = month++;
    trad["Sak"] = month++;
    trad["Keh"] = month++;
    trad["Mak"] = month++;
    trad["Kankin"] = month++;
    trad["Muan"] = month++;
    trad["Pax"] = month++;
    trad["Kayab"] = month++;
    trad["Kumku"] = month++;
    trad["Wayeb"] = month++;

    int n_tc;
    scanf("%d", &n_tc);
    for (int tc = 0; tc < n_tc; ++tc) {

        if(tc) printf("\n");

        string part1, part2;
        cin >> part1 >> part2;
        int f1 = part1.find(".");
        int f2 = part2.find(".");

        int date[4];
        date[0]=atoi(part1.substr(0, f1).c_str())-1;
        date[1]=trad[part1.substr(f1+1, part1.length())];
        date[2]=atoi(part2.substr(0, f2).c_str())-1;
        date[3]=trad[part2.substr(f2+1, part2.length())];

        int diff = -1;

        for (int i = 0; i < MAX; ++i) {
            if( date[0]==dates[i][0]
                    && date[1]==dates[i][1]
                    && date[2]==dates[i][2]
                    && date[3]==dates[i][3]) {
                diff = i;
                break;
            }
        }

        if(diff==-1) {
            printf("NO SOLUTION\n");
            continue;
        }

        int absolute = start + diff;
        while (absolute < start+MAX) {
            int * p = convert(absolute);
            printf("%d.%d.%d.%d.%d\n", p[0], p[1], p[2], p[3], p[4]);
            absolute += PERIOD;
        }

    }
    return 0;
}
