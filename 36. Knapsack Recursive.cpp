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

int printMaxPossibleSum(vector<int> val, vector<int> weights, int n, int capacity){

    // base case
    // if all items are iterated or capacity is filled

    if(n == 0 || capacity == 0){
        return 0;
    }


    // if capacity is there, we can include or not
    if(weights[n-1] <= capacity){
        return max(val[n-1] + printMaxPossibleSum(val, weights, n - 1, capacity - weights[n - 1]), printMaxPossibleSum(val, weights, n - 1, capacity));
    }

    else{
        return printMaxPossibleSum(val, weights, n - 1, capacity);
    }

}

void Sol(){
    int n;
    cin >> n;
    vector<int> val = scanVector(n);
    vector<int> weights = scanVector(n);   
    int capacity;
    cin >> capacity;
    cout << printMaxPossibleSum(val, weights, n, capacity) << endl;
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