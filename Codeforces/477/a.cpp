// ------------------------------------
// Date:2018/ 4/29
// Problem:/ / / a.cpp
//
// ------------------------------------

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

const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 5000;

int N, S;
int table[MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> S;

  fill_n(table, MAX_N, 0);
  vector< int > data(N);
  REP(i, N) {
    int h, m;
    cin >> h >> m;
    data[i] = 60 * h + m;
    table[data[i]]++;
    table[data[i] + S + 1]--;
  }

  REP(i, MAX_N) {
    if(i > 0) table[i] += table[i - 1];
    // printf("table[%d], %d:%d, %d\n", i, i / 60, i % 60, table[i]);
  }

  int ans = 0;
  REP(i, MAX_N) {
    bool ok = true;
    FOR(j, i, i + S + 1) {
      if (table[j] > 0) ok = false;
    }
    if (ok) {
      ans = i;
      break;
    }
  }

  cout << (ans / 60) << " " << (ans % 60) << endl;

  

  return 0;
}

