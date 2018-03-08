// ------------------------------------
// Date:2018/ 2/28
// Problem:ABC 054 TemplateMatching b.cpp
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

bool check(int x, int y);

int N, M;
string a[50];
string b[50];

int main()
{
  cin >> N >> M;
  REP(i, N) cin >> a[i];
  REP(i, M) cin >> b[i];
  bool ok;
  int h, w;
  h = w = 0;
  REP(yi, N - M + 1) {
    REP(xi, N - M + 1) {
      ok = true;
      REP(hi, M) {
        if (a[hi + yi].substr(xi, M) != b[hi]) {
          ok = false;
        }
      }
      if (ok) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No"<< endl;
  return 0;
}

