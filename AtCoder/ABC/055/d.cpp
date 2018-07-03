#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

const int MAX_N = 1e6 + 1;

int N;
string S;

int memo[MAX_N];

bool check(int p, int q)
{
  memset(memo, 0, sizeof(memo));
  memo[0] = p;
  memo[1] = q;

  FOR(si, 1, N - 1) {
    /*
    cout << si << endl;
    REP(j, N) {
      cout << (memo[j] > 0 ? 'W' : 'S');
    }
    cout << endl;
    */
    if (memo[si] == 0) {
      if (S[si] == 'o') {
	memo[(si + 1) % N] = memo[si - 1];
      } else {
	memo[(si + 1) % N] = (memo[si - 1] + 1) % 2;
      }
    } else {
      if (S[si] != 'o') {
	memo[(si + 1) % N] = memo[si - 1];
      } else {
	memo[(si + 1) % N] = (memo[si - 1] + 1) % 2;
      }
    }
  }

  bool res = true;
  if (memo[0] == 0) {
    if (S[0] == 'o') res &= (memo[N - 1] == memo[1]);
    else             res &= (memo[N - 1] != memo[1]);
  } else {
    if (S[0] != 'o') res &= (memo[N - 1] == memo[1]);
    else             res &= (memo[N - 1] != memo[1]);
  }

  if (memo[N - 1] == 0) {
    if (S[N - 1] == 'o') res &= (memo[N - 2] == memo[0]);
    else                 res &= (memo[N - 2] != memo[0]);
  } else {
    if (S[N - 1] != 'o') res &= (memo[N - 2] == memo[0]);
    else                 res &= (memo[N - 2] != memo[0]);
  }

  return res;
}

int main()
{
  cin >> N >> S;

  REP(i, (1 << 2)) {
    int p = i & 1;
    int q = (i >> 1) & 1;
    // cout << p << q << endl;
    if (check(p, q)) {
      
      REP(j, N) {
	// cout << memo[j];
	cout << (memo[j] > 0 ? 'W' : 'S');
      }
      cout << endl;
      return 0;
    }
  }
  cout << "-1" << endl;
  return 0;
}
