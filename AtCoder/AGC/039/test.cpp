#include <bits/stdc++.h>
using namespace std;

int main(){
    random_device seed_gen;
    mt19937_64 rnd(seed_gen());
    
    uniform_int_distribution<int> dist_N(1, 10), dist_A(1, 1e7);
    int N = dist_N(rnd);
    string s = "";
    for(int i=0;i<N;++i){
      if(dist_N(rnd)%2==0) s += 'a';
      else s += 'b';
    }

    cout<<s<<" "<<dist_A(rnd)<<endl;
    return 0;
}
