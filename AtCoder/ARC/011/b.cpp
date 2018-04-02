// ------------------------------------
// Date:2018/ 4/ 1
// Problem:B - ルイス・キャロルの記憶術 b.cpp
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

char vowels[7] = {'a', 'i', 'u', 'e', 'o', '.', ','};

pair< char, int > data[20];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  data[0] = {'b', 1};
  data[1] = {'c', 1};
  data[2] = {'d', 2};
  data[3] = {'w', 2};
  data[4] = {'t', 3};
  data[5] = {'j', 3};
  data[6] = {'f', 4};
  data[7] = {'q', 4};
  data[8] = {'l', 5};
  data[9] = {'v', 5};
  data[10] = {'s', 6};
  data[11] = {'x', 6};
  data[12] = {'p', 7};
  data[13] = {'m', 7};
  data[14] = {'h', 8};
  data[15] = {'k', 8};
  data[16] = {'n', 9};
  data[17] = {'g', 9};
  data[18] = {'z', 0};
  data[19] = {'r', 0};
  
  CIN(N);
  vector< string > w(N);
  REP(i, N) {
    SCIN(tmp);
    if (tmp == "." or tmp == ",") {
      i--;
      continue;
    }
    string tmp2;
    EACH(ti, tmp) {
      bool ok = true;
      EACH(tj, vowels) {
	if (ti == tj) ok = false;
      }
      if (ok) {
	REP(j, 20) {
	  if (data[j].first == tolower(ti)) {
	    // debug(to_string(data[j].second));
	    w[i] += to_string(data[j].second);
	  }
	}
      }
    }
  }

  string ans;
  REP(i, N) {
    if (w[i].empty()) {
      continue;
    }
    ans += w[i];
    if (!w[i].empty() && i != N - 1) {
      ans += " ";
    }
  }

  while(ans.back() == ' ') ans.pop_back();
  cout << ans << endl;

  return 0;
}

