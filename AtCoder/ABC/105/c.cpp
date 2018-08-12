#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl;
#define OK(ok) cout << (ok ? "Yes" : "No") << endl;
typedef long long ll;

void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail) {
  cin >> head; CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)

const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

ll power(ll x, ll n) {
  ll res = 1ll;
  while (n > 0) {
    if (n & 1) {
      res *= x;
    }
    x *= x;
    n >>= 1;
  }
  return res;
}

void show(vector< int > a) {
  EACH(i, a) {
    cout << i;
  }
  cout << endl;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  cin >> N;


  int front;
  if (N == 0) {
    cout << 0 << endl;
    return 0;
  } else if (N == 1) {
    cout << 1 << endl;
  }

  if (N % 2 == 0) {
    front = 0;
  } else {
    front = 1;;
    N--;
  }

  ll tmp = 0;
  ll sm = 0ll;
  vector< int > ans;
  if (N > 0) {
    // N >= 2
    while (N > sm) {
      tmp++;
      sm += power(-2, 2 * tmp);
    }
    ans.emplace_back(1);
    // show(ans);
    sm = power(-2, 2 * tmp);
    RFOR(i, 1, 2 * tmp) {
      // show(ans);
      // debug(sm);
      // debug(i);
      // sm += power(-2, i);
      if (N - sm == 0) {
	ans.emplace_back(0);
	continue;
      }
      if (i % 2 == 0) {
	// 偶数
	if ((N - sm) < power((-2), i - 2)) {
	  // cout << 1 << endl;
	  ans.emplace_back(0);
	} else {
	  // cout << 2 << endl;
	  sm += power(-2, i);
	  ans.emplace_back(1);
	}
	
      } else {
	// 奇数
	if ((N - sm) < power((-2), i - 2)) {
	  //debug(i);
	  // cout << 3 << endl;
	  ans.emplace_back(1);
	  sm += power(-2, i);
	} else {
	  // cout << 4 << endl;
	  ans.emplace_back(0);
	}
	
      }
      // cout << endl;
    }
    
  } else {
    // N <= -2
     while (N < sm) {
      tmp++;
      sm += power(-2, 2 * tmp - 1);
    }
    ans.emplace_back(1);
    // show(ans);
    sm = power(-2, 2 * tmp - 1);
    RFOR(i, 1, 2 * tmp - 1) {
      // show(ans);
      // debug(sm);
      // debug(i);
      // sm += power(-2, i);
      if (N - sm == 0) {
	ans.emplace_back(0);
	continue;
      }
      if (i % 2 == 0) {
	// 偶数
	if ((N - sm) < power((-2), i - 2)) {
	  //  cout << 1 << endl;
	  ans.emplace_back(0);
	} else {
	  //  cout << 2 << endl;
	  sm += power(-2, i);
	  ans.emplace_back(1);
	}
	
      } else {
	// 奇数
	if ((N - sm) < power((-2), i - 2)) {
	  //debug(i);
	  // cout << 3 << endl;
	  ans.emplace_back(1);
	  sm += power(-2, i);
	} else {
	  // cout << 4 << endl;
	  ans.emplace_back(0);
	}
	
      }
      // cout << endl;
    }
  }

  ll sm2 = 0ll;
  reverse(ALL(ans));
  REP(i, ans.size()) {
    if (ans[i] == 1) {
      sm2 += power(-2, i + 1);
    }
  }
  reverse(ALL(ans));
  REP(i, ans.size()) {
    cout << ans[i];
  }
  cout << front << endl;

  // cout << endl <<  sm2 << endl;
  return 0;
}

