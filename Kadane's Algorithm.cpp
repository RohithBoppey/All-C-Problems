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

void printVector(vector<int> a){
    for(auto x : a){
        cout << x << " ";
    }
    cout << endl;
}


int findMaxSubarraySum(vector<int> v){

    int n = v.size();
    if(n == 1){
        return v[0];
    }

    int cs = 0;
    int maxSum = INT_MIN;

    int start = 0, end = 0;

    for(int i = 0; i < n; i++){

        // updating current sum
        
            cs += v[i];
        

        if(cs > maxSum){
            maxSum = cs;
        }

        if(cs < 0){
            cs = 0;
        }
    }

    cout << cs << endl;
    return maxSum;
}

void Sol(){
    int n;
    vector<int> v;
    cin >> n;
    while(n){
        int t;
        cin >> t;
        v.pb(t);
        n--;
    }
    printVector(v);
    cout << findMaxSubarraySum(v) << endl;
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