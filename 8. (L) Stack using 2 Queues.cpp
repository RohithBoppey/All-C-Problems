https://leetcode.com/problems/implement-stack-using-queues/submissions/

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Implement Stack using Queues.
Memory Usage: 7 MB, less than 31.43% of C++ online submissions for Implement Stack using Queues.


class MyStack {
public:
    
    queue<int> q1;
    queue<int> q2;
    
    MyStack() {
    
    }
    
    void push(int x) {
        if(q1.empty() && q2.empty()){
            q1.push(x);
        }    
        else if(q1.empty() && !q2.empty()){
            q2.push(x);
        }else{
            q1.push(x);
        }
    }
    
    int pop() {
        int t;
        if(q1.empty()){
            // work on q2
            t = q2.back();
            while(q2.size() != 1){
                int temp = q2.front();
                q2.pop();
                q1.push(temp);
            }
            q2.pop();
            return t;
        }
        if(q2.empty()){
            // work on q1
            t = q1.back();
            while(q1.size() != 1){
                int temp = q1.front();
                q1.pop();
                q2.push(temp);
            }
            q1.pop();
            return t;
        }
        return t;
    }
    
    int top() {
        
        int t;
        if(q1.empty()){
            // work on q2
            return q2.back();
        }
        if(q2.empty()){
            // work on q1
            return q1.back();
        }
        return t;
    }
    
    bool empty() {
        return (q1.empty() && q2.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */