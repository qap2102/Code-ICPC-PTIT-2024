#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
using namespace std;

long long fibo (long long n, long long m){
    if (n == 0) return 0;
    if (n == 1) return 1;
    long long a = 0, b = 1;
    for (int i = 2; i <= n; i++){
        long long c = (a + b) % m;
        a = b;
        b = c;
    }
    return b;
}

long long gcd (long long a, long long b){
    while (b!=0){
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main (){
    int test;
    cin >> test;

    while (test--){
        long long a, b, m;
        cin >> a >> b >> m;
        cout << fibo ( gcd(a, b), m ) << endl;
    }

    return 0;
}