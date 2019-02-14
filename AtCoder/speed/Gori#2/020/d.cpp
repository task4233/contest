#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<":"<< (x) << "\n";

// q(1e5)がくるので,lognか1
// ai - bi y年
// vjとwj年が与えられたらlognか1で求めたい
//

struct UnionFind {
  vector< int > par;
  UnionFind(int n = 1) {
    init(n);
  }

  void init(int n = 1) {
    par.assign(n, -1);
  }
  
  int root(int n) {
    if (par[n] < 0) return n;
    return par[n] = root(par[n]);
  }

  bool merge(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (par[x] > par[y]) swap(x, y);
    par[x] += par[y];
    par[y] = x;

    return true;
  }

  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  int getSize(int x){
    return (-par[root(x)]);
  }
};

struct Edge{
	int fr, to, y;
};

struct Q{
	int fr, y, id;
};

int main() {
	int n, m;
	cin >> n >> m;
	vector< Edge > e(m);
	for(int i=0;i<m;++i) {
		cin >> e[i].fr >> e[i].to >> e[i].y;
	}

	sort(e.begin(), e.end(), [](Edge e1, Edge e2){ return e1.y > e2.y;});

	int qn; cin >> qn;
	vector< Q > q(qn);
	for(int i=0;i<qn;++i){
		cin >> q[i].fr >> q[i].y;
		q[i].id = i;
		// debug(q[i].id);
	}
	

	//for (int i=0; i<qn; ++i) {debug(i);debug(q[i].id);}
	
	sort(q.begin(), q.end(), [&](const Q &q1, const Q &q2){return q1.y > q2.y;});

	//for (int i=0; i<qn; ++i) {debug(i);debug(q[i].id);}

	vector< int > ans(qn, 0);
	UnionFind uf(n);
	int ei = 0;
	for(int qi=0;qi<qn;++qi){
		while (ei < m && q[qi].y < e[ei].y) {
			//debug(e[ei].y);
			uf.merge(e[ei].fr, e[ei].to);
			++ei;
		}

		/*
		debug(qi);
		debug(ei);
		debug(q[qi].id);
		debug(q[qi].fr);
		debug(uf.getSize(q[qi].fr));
		*/
		ans[q[qi].id] = uf.getSize(q[qi].fr);
		//cout << endl;
	}

	for(int i=0;i<qn;++i){
		cout << ans[i] << endl;
		//debug(q[i].id);
	}
	
			 
  return 0;
}
