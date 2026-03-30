class StockSpanner {
public:
    stack<pair<int,int>> stock; // pair : {stock, count}
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count = 1;
        while(!stock.empty() && stock.top().first <= price){
            count += stock.top().second;
            stock.pop();
        }
        stock.push({price, count});
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */