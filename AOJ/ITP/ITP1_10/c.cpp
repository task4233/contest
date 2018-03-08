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
    double a,b,c;
    cin >> a >> b >> c;
    c = 180/c;
    //cout << a*b*sin(PI/c)/2.0 << endl;
    printf("%.5lf\n", a*b*sin(PI/c)/2.0);
    printf("%.5lf\n", sqrt(pow(a,2)+pow(b,2)-2.0*a*b*cos(PI/c))+a+b);
    printf("%.5lf\n", b*sin(PI/c));
    return 0;
}
