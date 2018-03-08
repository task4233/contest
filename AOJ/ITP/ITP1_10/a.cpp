#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <stdio.h>

using namespace std;

#define FOR(i,a,b) for(int i=int(a);i<int(b);++i)
#define RFOR(i,a,b) for(int i=int(b)-1;i>=int(a);--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)

int main() {
    double x1,x2,y1,y2,x,y;
    cin >> x1 >> y1 >> x2 >> y2;
    //cout << sqrt(pow(x2-x1,2)+pow(y2-y1,2)) << endl;
    printf("%.6lf\n", sqrt(pow(x2-x1,2)+pow(y2-y1,2)));
    return 0;
}
