// ------------------------------------
// Date:2018/ 2/26
// Problem:AGC 013 HamiltonishPath b.cpp
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

using ll = long long;

#define MOD 1000000007

bool G[10000][10000];

int main()
{
  int N,M;
  bool state[10001];
  cin >> N >> M;
  memset(state,false,sizeof(state));
  vector<int> a(M);
  vector<int> b(M);
  REP(i,M) {
    cin >> a[i] >> b[i];
  }
  deque<int> ans = {1};
  int now = 1;
  int cnt = 1;
  bool flag = true;
  bool loop = false;
  while (flag) {
    loop = false;
    REP(i,M) {
      if (state[a[i]] || state[b[i]]) continue;
      if (a[i] == now) {
        if (!loop) ans.push_back(b[i]);
        else ans.push_front(b[i]);
        state[now] = true;
        now = b[i];
        /*
        cout << "a:" << a[i] << endl;
        REP(j,ans.size()) {
          cout << ans[j] << (j!=ans.size()?" ":"");
        }
        cout << endl;
        */
        continue;
      } else if (b[i] == now) {
        if (!loop) ans.push_back(a[i]);
        else ans.push_front(a[i]);
        state[now] = true;
        now = a[i];
        /*
        cout << "b:" << endl;
        REP(j,ans.size()) {
          cout << ans[j] << (j!=ans.size()?" ":"");
        }
        cout << endl;
         */
        continue;
      }
      if (!loop && i == M-1) {
        now = ans.front();
        i = -1;
        loop = true;
      }
    }
    if (ans.size() < 4) now = ++cnt;
    else flag = false;
  }
  int size = ans.size();
  cout << size << endl;
  REP(i,size) {
    cout << ans[i] << (i!=size?" ":"");
  }
  cout << endl;
  return 0;
}

