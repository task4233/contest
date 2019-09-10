#include <bits/stdc++.h>
using namespace std;

int main(){
    random_device seed_gen;
    mt19937_64 rnd(seed_gen());
    
    uniform_int_distribution<int> dist_N(1, 1e6), dist_A(1, 1e6);
    int N = dist_N(rnd);
    vector<int> A(N);
    for(int i=0; i<N; i++) A[i] = dist_A(rnd);

    cout << N << endl;
    for(int i=0; i<N; i++) cout << A[i] << " \n"[i==N-1];
    return 0;
}
