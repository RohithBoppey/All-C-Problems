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


bool solve(string s){
    // solving using stacks
    // open -> push

    // close -> check if corresponding closing bracket exists
    // direct closing bracket doesnt need to exist

    stack<char> st;

    int n = s.length();
    for(int i = 0; i < n; i++){
        if(s[i] == '{' || s[i] == '[' || s[i] == '('){
            st.push(s[i]);
        }else{
            
            // direct closing bracket doesnt need to exist
            if(st.empty() || s[i] == '}' and st.top() != '{'){
                return false;
            }
            if(st.empty() || s[i] == ')' and st.top() != '('){
                return false;
            }
            if(st.empty() || s[i] == ']' and st.top() != '['){
                return false;
            }
            st.pop();
        }
    }

    return st.empty();
}

void Sol(){
    string s;
    cin >> s;
    // cout << s << endl;
    cout << solve(s) << endl;
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