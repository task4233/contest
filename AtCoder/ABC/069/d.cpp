// ------------------------------------
// Date:2018/ 3/13
// Problem:ABC 069 GridColoring d.cpp
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
static const int MAX_N = 101;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// c[hi][wi];
int c[MAX_N][MAX_N] = {-1};

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int H, W, N;
  cin >> H >> W >> N;
  vector< int > A(N);
  REP(i, N) {
    cin >> A[i];
  }
    
  int tmp = 0;
  REP(hi, H) {
    REP(wi, W) {
      c[hi][wi] = tmp + 1;
      A[tmp]--;
      if (A[tmp] <= 0) {
	tmp++;
      }
    }
  }

  bool order = true;
  REP(hi, H) {
    REP(wi, W) {
      if (order) {
	cout << c[hi][wi];
      } else {
	cout << c[hi][W - wi - 1];
      }
      if (wi != W - 1) cout << " ";
    }
    order = !order;
    cout << endl;
  }
  return 0;
}

