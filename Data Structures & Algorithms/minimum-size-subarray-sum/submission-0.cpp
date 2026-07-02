class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0;
        int result = INT_MAX;
        int computation = 0;
        for(int end = 0;end<nums.size();end++){
            computation += nums[end]; 
            while(computation >= target){
                result = min(result,end - start + 1);
                computation -= nums[start];
                start++;
            }
        }
        if(result == INT_MAX){
            return 0;
        }
        return result;
    }
};