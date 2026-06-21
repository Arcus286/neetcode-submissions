class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(),weights.end());
        int end = accumulate(weights.begin(),weights.end(), 0LL);
        int ans = end;
        while(start <= end){
            int mid = start + (end - start) / 2;
            int requiredDays = 1;
            int weightTracker = 0;
            for(int weight:weights){
                if(weightTracker + weight <= mid){
                    weightTracker += weight;
                } else {
                    requiredDays++;
                    weightTracker = weight;
                }
            }
            if(requiredDays <= days){
                ans = mid;
                end = mid - 1;
            } else{
                start = mid + 1;
            }
        }
        return ans;
    }
};