/*

class StockSpanner {
public:

    // intialized a stack here of pair
    // pair.first will store stock price
    // pair.second will store it's span

    // span is basically the count of previous days
    // where in the price was lesser or equal to the price of today
    // so if today's price was 80
    // and last 4 days price was [10,20,30,40];

    // so including today's i.e span = 1;
    // and last 4 days i.e span = 4 // where the price was <=80;
    // total span for 80 is 5;


    stack<pair<int,int>> st;

    StockSpanner() {
        
    }
    
    int next(int price) {

        if(!st.empty()){

            // span for today's day
            int span = 1;

            // now going through all the past prices that were 
            // lesser or equal to today's price
            // and adding their span into our's today price

            while(!st.empty() && st.top().first<=price){
                span += st.top().second;
                st.pop();
            }

            // finally pushing the today's price and it's calculated span
            st.push({price,span});

            return span;
        }
        else{
            // if this the first price in the stack
            // that means there is no previous prices
            // so span will be one

            st.push({price,1});
            return 1;
        }
    }
};


 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);

*/