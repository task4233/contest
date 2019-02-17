#include <bits/stdc++.h>
// statics
using namespace std;
using int64 = int_fast64_t;
using PAIR = pair<int64, int64>;
constexpr int INF = 1 << 30;
constexpr int64 LINF = 1LL << 60;
constexpr int MOD = 1e9 + 7;
constexpr int MAX_N = 3e5 + 1;

// init/input
#define int int64
#define INIT ios::sync_with_stdio(false);cin.tie(0);
#define VAR(type, ...) type __VA_ARGS__;MACRO_VAR_Scan(__VA_ARGS__);
template<typename T> void MACRO_VAR_Scan(T &t) {cin>>t;}
template<typename First, typename...Rest> void MACRO_VAR_Scan(First &first, Rest&...rest) {cin>>first;MACRO_VAR_Scan(rest...);}
#define VEC(type, c, n) vector<type> c(n);for(auto &&i:c)cin>>i;

// out
#define OUT(dist) cout<<(dist);
#define FOUT(n, dist) cout<<fixed<<setprecision(n)<<(dist);
#define SP cout<<" ";
#define BR cout<<endl;
#define zero(n) cout<<setfill('0')<<right<<setw(n)
#define debug(x) cerr<<#x<<":"<< (x);BR;

// utility
#define ALL(a) (a).begin(), (a).end()
#define EACH(i, a) for(auto &&i:(a))
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=0;--i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)

// ちょうどn本で作りたい
// 方針
// なるべく本数の少ないものを使いたい
// n
// 桁数が最も多いものが最大値

// 20
// 3 4 7 8
// 5 4 3 7
// 3 * 5 + 3
// 最小値で%をとって同じものを作る?
// 2 1 0 1
// 2

// 101
// 1 2 3 4 5 6 7 8 9
// 2,5,5,4,5,6,3,7,6
// 0 1 1 0 1 0 1 1 0
// 101 0

// 割り切れたら, 全てそれ
// 割り切れなかったら, あまりが同じものを選定する

// 15
// 4 5 6
// 0 1 2
// 1 1 1
// 数字は最後にソートすれば良い

int cost[9] = {2,5,5,4,5,6,3,7,6};
vector<int> d[202020];

signed main() {
  INIT;
	VAR(int, n, m);
	// first: その数字, second: コスト
	vector< PAIR > a;
	REP(i,m){
		VAR(int, t);
		a.push_back(make_pair(t, cost[t-1]));
	}

	sort(ALL(a), [](PAIR p1, PAIR p2){if(p1.second==p2.second) return p1.first > p2.first; return p1.second < p2.second;});

	FOR(i,1,a.size()){
		if (a[i].second == a[i-1].second) {
			a.erase(a.begin()+i);
		}
	}
	/*
	*/
	vector<PAIR> c;
	FOR(i,1, (1<<a.size())){
		int cost=0, num =0;
		vector<int> tmp;
		REP(j,a.size()){
			if((i>>j) & 1){
				cost += a[j].second;
				num += a[j].first;
				tmp.push_back(a[j].first);
			}
		}
		sort(ALL(tmp));
		reverse(ALL(tmp));
		
		d[num] = tmp;
		c.push_back(make_pair(num,cost));
	}

	sort(ALL(c), [](PAIR p1, PAIR p2){
			if(p1.second==p2.second) {
				if (p1.first == p2.first) return d[p1.first].size() > d[p2.first].size();
				return p1.first > p2.first;		
			}
			return p1.second < p2.second;});

	/*
	REP(i,c.size()){
		debug(c[i].first);
		debug(c[i].second);
	}
	*/
	
	
	vector< PAIR > b(c);
	REP(i, b.size()){
		b[i].second %= c[0].second;
	}
	
	vector<int>ans(n/c[0].second, c[0].first);
	/*
	REP(i,ans.size()){
		debug(ans[i]);
	}
	*/

	int rest = n%c[0].second;
	//debug(rest);
	REP(i, b.size()){
		if (c[i].second % c[0].second == rest) {
			//debug(i);
			//debug(c[i].first);
			int delete_num = (c[i].first > 9 ? d[c[i].first].size():c[i].second / c[0].second);
			ans.erase(ans.begin(), ans.begin()+delete_num);
			// ans.push_back(c[i].first);
			if (c[i].first > 9) {
				EACH(di,d[c[i].first]){
					ans.push_back(di);
				}
			} else {
				ans.push_back(c[i].first);
			}
			break;
		}
	}

	sort(ALL(ans));
	reverse(ALL(ans));
	EACH(ai,ans){
		cout << ai;
	}
	BR;
	
  return 0;
}
