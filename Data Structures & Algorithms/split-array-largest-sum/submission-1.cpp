class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int start = *max_element(nums.begin(),nums.end());
        int end = 0;
        for(int num:nums){
            end += num;
        }
        int possibleAnswer = start;
        while(start <= end){
            int mid = start + (end - start) / 2;
            int numberOfSubarrays = 1;
            int result = 0;;
            for(int i = 0;i<nums.size();i++){
                if(result + nums[i] <= mid){
                    result += nums[i];
                } else {
                    numberOfSubarrays++;
                    result = nums[i];
                }
            }
            if(numberOfSubarrays <= k){
                possibleAnswer = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return possibleAnswer;
    }
};