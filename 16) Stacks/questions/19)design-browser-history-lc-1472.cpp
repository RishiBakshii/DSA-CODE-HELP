/*

class BrowserHistory {
public:

    stack<string> browserStack;
    stack<string> forwardStack;

    BrowserHistory(string homepage) {
        browserStack.push(homepage);
    }
    
    void visit(string url) {
        browserStack.push(url);
        while(!forwardStack.empty()) forwardStack.pop();
    }
    
    string back(int steps) {

        while(browserStack.size()>1 && steps){
            forwardStack.push(browserStack.top());
            browserStack.pop();
            steps--;
        }

        return browserStack.top();

    }
    
    string forward(int steps) {
        while(!forwardStack.empty() && steps){
            browserStack.push(forwardStack.top());
            forwardStack.pop();
            steps--;
        }

        return browserStack.top();
    }
};


 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);


*/