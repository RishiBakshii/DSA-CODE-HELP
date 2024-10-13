/*

class MinStack {
public:

    // in this pair
    // first element will be the top
    // second element will be the minimumElement
    
    vector<pair<int,int>> v;

    MinStack() {
        
    }
    
    void push(int val) {
        if(v.empty()){
            v.push_back({val,val});
        }
        else{
            if(val<v.back().second){
                // if new value is the new minimum
                v.push_back({val,val});
            }
            else{
                int prevMin = v.back().second;
                v.push_back({val,prevMin});
            }
        }
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v.back().first;
    }
    
    int getMin() {
        return v.back().second;
    }
};


 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 *

*/