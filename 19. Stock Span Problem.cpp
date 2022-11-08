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

vector<int> findGreaterToLeft(vector<int> v){
    int n = v.size();

    vector<int> ans;
    stack<int> st;

    for(int i = 0; i < n; i++){
        if(st.empty()){
            ans.pb(-1);
        }
        else{
            if(st.top() > v[i]){
                ans.pb(st.top());
            }else{
                // <=
                while(!st.empty() && st.top() <= v[i]){
                    st.pop();
                }

                if(st.empty()){
                    ans.pb(-1);
                }else{
                    ans.pb(st.top());
                }

            }
        }

        st.push(v[i]);
    }


    return ans;
}

vector<int> stockSpanProblem(vector<int> v){

    // similar to finding greater to left
    
    // because greater to left means all the numbers will be <= that number only

    // so should find the count of that difference between indices
    // gives the number of days


    vector<int> ans;

    int n = v.size();

    stack<int> st;

    for(int i = 0; i < n; i++){
        if(st.empty()){
            ans.pb(-1);
        }
        else{
            if(st.top() > v[i]){
                ans.pb(v[st.top()]);
            }else{
                // <=
                while(!st.empty() && v[st.top()] <= v[i]){
                    st.pop();
                }

                if(st.empty()){
                    ans.pb(-1);
                }else{
                    ans.pb(st.top());
                }
            }
        }

        st.push(i);
    }

    // printVector(ans);

    // finding difference of indices to give number of days in between

    for(int i = 0; i < n; i++){
        ans[i] = i - ans[i];
    }

    return ans;
}

void Sol(){
    int n;
    cin >> n;
    vector<int> v = scanVector(n);  
    printVector(stockSpanProblem(v));
    // printVector(findGreaterToLeft(v));
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