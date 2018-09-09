#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=998244353;
const LL LINF=1LL<<62;

struct edge {int a;int b;int c;};

int main(){
    int N;
    cin >> N;
    vector<edge> v;
    int t=0,s=N;
    while(s){
        s/=2;
        t++;
    }
    cout << t << " ";
    s=1;
    int sum=0;
    for(int i=1;i<t;i++){
        v.pb({i,i+1,0});
        v.pb({i,i+1,s});
        sum+=s;
        s*=2;
    }
    int p=1;
    int k=1;
    while(N!=1){
        if(N%2==1){
            v.pb({p,t,sum+1});
            sum+=k;
        }
        N/=2;
        p++;
        k*=2;
    }
    cout << v.size() << endl;
    for(int i=0;i<v.size();i++){
        edge e;
        e=v[i];
        cout << e.a << " " << e.b << " " << e.c << endl;
    }
    return 0;
}
