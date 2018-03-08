// ------------------------------------
// Date:2018/ 2/20
// Problem:AOJ 0582 TriangleTypes 0582.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define POW(n) (n)*(n)

int main()
{
  int acute,right,obtuse;
  acute = right = obtuse = 0;
  vector<int> length(3,0);
  while(scanf("%d %d %d",&length[0],&length[1],&length[2]) != EOF) {
    sort(ALL(length));
    if (length[2] >= length[0] + length[1]) break;
    else if (POW(length[2]) < POW(length[0]) + POW(length[1])) ++acute;
    else if (POW(length[2]) == POW(length[0]) + POW(length[1])) ++right;
    else ++obtuse;
  }
  printf("%d %d %d %d\n", acute+right+obtuse, right, acute, obtuse);
  return 0;
}

