#include <bits/stdc++.h>
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

/*
    2
    6
    3 0 0 2 0 4
    12
    0 1 0 2 1 0 1 3 2 1 2 1
*/

// Kinda tricky, needs more understanding
int findMaxWaterRetained(vector<int> v){
    
    int ans = 0;

    int n = v.size();
    
    vector<int> left(n);
    vector<int> right(n);

    // we are not generating nearest greater 

    // we are retaining the nearest greater so far and moving on

    // left - 3 3 3 3 3 4
    // right - 4 4 4 4 4 4

    left[0] = v[0];
    right[n-1] = v[n-1];

    // retaining the max so far and updating if any

    for(int i = 1; i < n; i++){
        left[i] = max(left[i-1], v[i]);
    }   

    for(int i = n-2; i > -1; i--){
        right[i] = max(right[i+1], v[i]);
    }

    // printVector(left);
    // printVector(right);  


    // since the limit is on the lower cap of both maximas 
    // find min of both maximas
    // that much water is present on top of that level
    
    for(int i = 0; i < n; i++){
        ans += min(left[i], right[i]) - v[i];
    } 

    return ans;
}

void Sol(){
    int n;
    cin >> n;
    vector<int> v = scanVector(n);
    cout << findMaxWaterRetained(v) << endl;
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
    RepSolution();
    // Sol();
    return 0;
}