#include <bits/stdc++.h>
using namespace std;
#define faster                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define ll long long
int ucln(int a, int b){
	return (b==0) ? a : ucln(b,a%b);
}
int gcd(int b[], int n){
	int x=b[0];
	for(int i=0;i<n;i++){
		x=ucln(x,b[i]);
	}
	return x;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		cout<<gcd(a,n)<<endl;
		}
	}

