// ------------------------------------
// Date:2018/ 4/ 1
// Problem:A- Diverse Word a.cpp
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

string S;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> S;

  string ans;
  if (S.size() < 26) {
    // (S + Sで使われていない最小の文字)が辞書式配列で次にくる
    ans += S;
    map< int, int > mp;
    EACH(si, S) {
      mp[si - 97]++;
    }
    REP(i, 26) {
      if (mp[i] == 0) {
	// 使われていない文字を最後にくっつける
	ans += i + 97;
	break;
      }
    }
  } else {
    // 後ろから昇順に並んでいるものをカウントしていく
    // もし、その値が0のときは全ての文字が前から降順に並んでいることになるため,-1を出力する
    int point = 25;
    RREP(i, S.size() - 1) {
      if (S[i] < S[i + 1]) break;
      point = i;
    }

    if (point == 0) {
      // point == 0の時は全ての数字が前から降順に並んでいることになるため,
      // その文字列が辞書式最大の文字列である
      ans = "-1";
    } else {
      // 前からpoint - 1番目までの文字列に,
      // 前からpoint + 1番目の文字列のうち,最小の文字を出力すればよい
      ans = S.substr(0, point - 1);
      map< int, int > mp;
      FOR(i, point - 1, 26) {
	mp[S[i] - 97]++;
      }
      REP(i, 26) {
	if (mp[i] == 1 && i + 97 > S[point - 1]) {
	  // S[point - 1]より大きいもののうち,最小の文字をくっつける
	  ans += i + 97;
	  break;
	}
      }
    }
  }

  cout << ans << endl;

  return 0;
}

