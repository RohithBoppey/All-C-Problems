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
    

void insertAtEnd(stack<int>& s, int k){
    if(s.size() == 0){
        s.push(k);
        return;
    }

    int t = s.top();
    s.pop();
    insertAtEnd(s, k);
    s.push(t);
    return;
}

void reverseStack(stack<int> &s){
    if(s.size() == 1){
        return;
    }

    int t = s.top();
    s.pop();
    reverseStack(s);
    insertAtEnd(s, t);
    return;
}


/*

    2
    5
    1 2 3 4 5    
    6
    2 5 -2 0 1 2

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
    printStack(s);
    reverseStack(s);
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