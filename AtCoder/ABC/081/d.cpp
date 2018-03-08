// ------------------------------------
// Date:2018/ 3/ 6
// Problem:ABC 081 Non-Decreasing d.cpp
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

  int N;
  cin >> N;
  vector< int > A(N);
  REP(i, N) {
    cin >> A[i];
  }

  vector< pair< int, int > > o;
  REP(i, N - 1) {
    if (A[i] <= A[i + 1]) continue;
    // 順番が逆の時
    if (A[i] <= 0) {
      // 次の値に加えられない時
      int tmp = -1e9;
      int num;
      FOR(j, i + 1, N) {
	if (tmp > A[j]) {
	  tmp = A[j];
	  num = j;
	}
      }
      if (tmp > 0) {
	A[i + 1] += A[num];
	o.emplace_back(make_pair(num, i+1));
      } else {
	REP(j, i + 1) {
	  o.emplace_back(make_pair(i+2, j+1));
	  A[j] += A[i + 1];
	}
      }
    } else {
      // 次の値に加えられる時
      o.emplace_back(make_pair(i+1, i+2));
      A[i + 1] += A[i];
    }
    // 見ているところを戻す
    --i;
  }

  cout << o.size() << endl;
  REP(i, o.size()) {
    cout << o[i].first << " " << o[i].second << endl;
  }
  
  return 0;
}

