#include <iostream>
using namespace std;

bool check (int n){
    if (n % 4 == 0 || n % 7 == 0){
        return true;
    }
    else{
        n -= 7;
        while (n > 3){
            if (n % 4 == 0){
                return true;
            }
            n -= 7;
        }
        return false;
    }
}

int main (){
    int n;
    cin >> n;
    if(check(n)){
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    return 0;
}