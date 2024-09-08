#include <bits/stdc++.h>
using namespace std;
#define faster                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define ll long long
int n, a[100], cot[100], dx[100], dn[100];
int cnt=0;
void thu(int i){
	// duyet kha nang x[i] nhan duoc
	for(int j=1;j<=n;j++){
		if(cot[j]==1&&dx[i-j+n]==1&&dn[i+j-1]==1){
			// nhung phan ma quan hau quan duoc trong ban co
			a[i]=j;
			// vi tri dat quan hau 
			cot[j]=dx[i-j+n]=dn[i+j-1]=0;// backtrack1
			if(i==n){
				++cnt;
			}
			else{
			 thu(i+1);
			 }// de quy voi vi tri khac
			// backtrack2
			cot[j]=dx[i-j+n]=dn[i+j-1]=1;
		}
	}
}
int main(){
	faster;
	cin>>n;
	for(int i=1;i<=99;i++){
		cot[i]=dx[i]=dn[i]=1;
	}
	thu(1);
	cout<<cnt<<endl;
	return 0;
}
// dx duong cheo chinh i-j+n
// dn duong cheo nguoc i+j-1
