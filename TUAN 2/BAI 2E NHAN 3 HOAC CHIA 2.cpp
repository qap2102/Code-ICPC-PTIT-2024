#include <bits/stdc++.h>
using namespace std;
#define faster                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define ll long long
bool chan(long long int n){
	return n % 2 == 0;
}

int mucua2 (long long int n){
	int count = 0;
	while (n > 1 && chan(n)){
		n /= 2;
		count++;
	}
	return count;
}

int main (){
	int n;
	cin >> n;
	
	long long int arr[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int count  = 0;
	for (int i = 0; i < n; i++){
		if (chan(arr[i])){
			count += mucua2 (arr[i]);
		}
	}
	cout << count << endl;
	return 0;
}
