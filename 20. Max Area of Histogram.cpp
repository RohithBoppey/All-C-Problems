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


vector<int> findSmallerToLeft(vector<int> v){
    int n = v.size();

    vector<int> ans;
    stack<int> st;

    for(int i = 0; i < n; i++){
        if(st.empty()){
            ans.pb(-1);
        }
        else{
            if(v[st.top()] < v[i]){
                ans.pb(st.top());
            }else{
                // <=
                while(!st.empty() && v[st.top()] >= v[i]){
                    st.pop();
                }

                if(st.empty()){
                    ans.pb(-1);
                }else{
                    ans.pb(st.top());
                }

            }
        }

        // storing index
        st.push(i);
    }


    return ans;
}


// slightly modified to have psuedoindex on extreme right -> n is the final index
vector<int> findSmallerToRight(vector<int> v){
    int n = v.size();

    vector<int> ans;
    stack<int> st;

    for(int i = n-1; i >= 0; i--){
        if(st.empty()){
            ans.pb(n);
        }
        else{
            if(v[st.top()] < v[i]){
                ans.pb(st.top());
            }else{
                // <=
                while(!st.empty() && v[st.top()] >= v[i]){
                    st.pop();
                }

                if(st.empty()){
                    ans.pb(n);
                }else{
                    ans.pb(st.top());
                }

            }
        }

        st.push(i);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}


int maxAreaOfHistogram(vector<int> v){

    int n = v.size();
    vector<int> left = findSmallerToLeft(v);
    vector<int> right = findSmallerToRight(v);
    
    // printVector(left);
    // printVector(right);

    // once left and right are calculated, we can find width

    vector<int> width;
    vector<int> area;
    
    int mx = 0;
    
    for(int i = 0; i < n; i++){
        width.pb(right[i] - left[i] - 1);
        area.pb(v[i] * width[i]);
        mx = max(mx, area[i]);
    }  

    return mx;
}


/*

    3
    2
    2 4
    6
    2 1 5 6 2 3 
    7
    6 2 5 4 5 1 6

*/

void Sol(){
    int n;
    cin >> n;
    vector<int> v = scanVector(n);  
    cout << maxAreaOfHistogram(v) << endl;
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