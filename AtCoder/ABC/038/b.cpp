// ------------------------------------
// Date:2018/ 3/ 3
// Problem:ABC 038 ディスプレイ b.cpp
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
#define debug(x) cerr << #x << ":" << x << endl

typedef long long ll;

static const int MOD = 1000000007;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int H[2];
  int W[2];
  
  scanf("%d %d", &H[0], &W[0]);
  scanf("%d %d", &H[1], &W[1]);
  
  if (H[0] == H[1] or
      H[0] == W[1] or
      H[1] == W[0] or
      W[0] == W[1]) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}

