#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <stdio.h>

using namespace std;

#define PI 3.141592653589793
#define FOR(i,a,b) for(int i=int(a);i<int(b);++i)
#define RFOR(i,a,b) for(int i=int(b)-1;i>=int(a);--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)

int main() {
    int n;
    int x[1001], y[1001];
    double m,d,dm,dd,dt;
    cin >> n;
    REP(i,n) cin >> x[i];
    REP(i,n) cin >> y[i];
    // p == 1
    d = dm = dd = dt = 0.0;
    REP(i,n) {
        m = (double)abs(x[i]-y[i]);
        d += m;
        dm += pow(m,2);
        dd += pow(m,3);
        dt = m>dt?m:dt;
    }
    printf("%.6lf\n", d);
    printf("%.6lf\n", sqrt(dm));
    printf("%.6lf\n", pow(dd, 1.0/3.0));
    printf("%.6lf\n", dt);
    return 0;
}
