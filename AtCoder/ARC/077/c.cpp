// ------------------------------------
// Date:2018/ 3/17
// Problem:ARC 077 PushPush c.cpp
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
#define debug(x) cerr << #x << ":" << x << endl

typedef long long ll;
typedef vector< ll > V;

void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail) {
  cin >> head;CINT(move(tail)...);
}

#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)

static const int MOD = 1000000007;
static const int MAX_N = 1e4;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  CIN(N);
  vector< int > a(N);
  REP(i, N) cin >> a[i];
  deque< int > dq;
  int tmp = N % 2;
  REP(i, N) {
    if (i % 2 == tmp) {
      dq.push_back(a[i]);
    } else {
      dq.push_front(a[i]);
    }
  }

  while(!dq.empty()) {
    cout << dq.front();
    dq.pop_front();
    if (!dq.empty()) cout << " ";
  }
  cout << endl;

  return 0;
}

