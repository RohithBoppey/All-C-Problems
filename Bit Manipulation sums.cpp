//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>

#define pb push_back
#define ll long long int

using namespace std;

/*-------------------------------------------
--------------Rohith's Solution--------------
---------------------------------------------*/

#define maxX(a,b) (a>b?a:b)
#define minX(a,b) (a<b?a:b)
#define isEven(a) ((a%2==0)?1:0)
#define isOdd(a) ((a%2==0)?0:1)
#define isNeg(a) ((a<0)?1:0)
#define loop(n) for(int i = 0; i < n; i++)
#define loop2(n) for(int j = 0; j < n; j++)
#define abs(a) ((a<0)?-a:a)


long long int find2PowerN(int n){
    return 1 << (n); 
}

int ithBitOfNumber(int n, int k){
    // 3 - 010
    // 14 - 01110
    // 15 - 01111
    // 16 - 10000
    // from right, ith bit

    return (n >> k) % 2;
}

int countNumberof1s(int n){
    // xor sum -> count number of steps using the same number
    int steps = 0;
    while(n){
        steps++;
        n = n & n - 1;
    }
    return steps;
}


int checkFor2powern(int n){
    return (n & n -1 == 0 ? 1 : 0);
}

void Sol(){
    int n;
    cin >> n;
    cout << find2PowerN(n) << endl;
    cout << ithBitOfNumber(n, 2) << endl;
    cout << countNumberof1s(n) << endl;
    cout << checkFor2powern(n) << endl;
}

void RepSolution(){
    int t;
    cin >> t;
    while(t!=0){
        Sol();
        t--;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //RepSolution();
    Sol();
    return 0;
}