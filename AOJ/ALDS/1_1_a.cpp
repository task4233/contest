#include <iostream>

void insertionSort(vector<int> a, int n){
	for(int i=0;i<n;++i){
		int v=a[i];
		for(int j=i-1;j>=0;--j){
			 a[j+1] =
		}
	}
}

int main(){
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;++i)cin>>a[i];

	insertionSort(a,n);
	return 0;
}
