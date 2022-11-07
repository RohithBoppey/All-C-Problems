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


vector<int> scanVector(int n){
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    return v;
}

void printVector(vector <int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "" << endl;
}

void ShiftOnce(vector<int> &v){
    int n = v.size();
    
    // // left shift
    // int first = v[0];
    // for(int i = 0; i < n - 1; i++){
    //     v[i] = v[i+1];
    // }
    // v[n-1] = first;

    // right shift
    int last = v[n-1];
    for(int i = n - 1; i >= 1; i--){
        v[i] = v[i-1];
    }
    v[0] = last;
}

void rotateVector(vector<int> &v, int k){
    int n = v.size();
    if(k % n == 0){
        //nothing to change
        return;
    }

    // right shift
    for(int i = 0; i < k; i++){
        ShiftOnce(v);
    }

    return;
}

/*

    5
    1 2 3 4 5
    1

*/

bool checkIfPermutationIsPossible(string s, string goal){

    // should check if s2 is a permutation of s1

    // one way is to check until length given -> passing n

    // or since it comes under one form of rotation, we can combine string and check

    string combinedString = s1 + s1;
    return (combinedString.find(s1) != string::npos);
}

void Sol(){
    int n;
    cin >> n;
    vector<int> v = scanVector(n);
    int k;
    cin >> k;
    rotateVector(v, k);
    cout << checkIfPermutationIsPossible("abcde", "cdeab") << endl;
    printVector(v);
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