#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;cin>>q;
	list<int> li;
	auto it = li.end();

	auto insert = [&](int x){
		// std::list::insertは直前に挿入するので, その要素にポインタを持っていくためには--itが必要
		li.insert(it,x);
		--it;
	};

	auto move = [&](int d){
	  while(d<0) --it,++d;
		while(d>0) ++it,--d;
	};

	auto erase = [&](){
		it = li.erase(it);
	};
	
	while(q--){
		int query;cin>>query;
		if(query==0){
			// insert
			int x;cin>>x;
			insert(x);
		}else if(query==1){
			// move
			int d;cin>>d;
			move(d);
		}else{
			// erase
			erase();
		}
	}

	for(auto &&lj: li){
		cout<<lj<<endl;
	}
  return 0;
}
