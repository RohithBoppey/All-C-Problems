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


void printStack(stack<int> s){
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << "" << endl;
}
    

void deleteElement(stack<int>& s, int k){
    if(k == 1){
        s.pop();
        return;
    }

    int t = s.top();
    s.pop();
    deleteElement(s, k - 1);
    s.push(t);
}

void deleteMiddleElementOfStack(stack<int> &s){
    int sz = (s.size() / 2) + 1;
    deleteElement(s, sz);
}

/*

    2
    5
    1 2 3 4 5
    12
    20 59 42 94 12 46 51 40 67 41 7 56

*/

void Sol(){
    int n;
    cin >> n;
    stack<int> s;
    while(n){
        int t;
        cin >> t;
        s.push(t);
        n--;
    }
    // printStack(s);
    deleteMiddleElementOfStack(s);
    printStack(s);
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