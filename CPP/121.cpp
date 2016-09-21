class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if (prices.size() == 0) {
    		return 0;
    	}
        int min = 0;
        int n = prices.size();
        min = prices[0];
        int max_profit = 0;
        for (int i = 1; i < n; i++) {
        	if (prices[i] < min) {
        		min = prices[i];
        	}
        	max_profit =  max(prices[i] - min, max_profit);
        }
        return max_profit;
    }
};
