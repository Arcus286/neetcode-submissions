class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int maxProfit = 0;
        // int best_buy = prices[0];
        // for(int i = 1;i<prices.size();i++){
        //     if(best_buy < prices[i]){
        //         maxProfit = max(maxProfit,prices[i] - best_buy);
        //     }
        //     best_buy = min(best_buy,prices[i]);
        // }
        // return maxProfit;
        int left = 0;
        int right = left + 1;
        int maxProfit = 0;

        while(right != prices.size()){
            if(prices[left] > prices[right]){
                right++;
                left = right - 1;
            } else {
                maxProfit = max(maxProfit,prices[right] - prices[left]);
                right++;
            }
        }
        return maxProfit;
    }
};
