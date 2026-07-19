class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool> tracker(nums.size(),false);

        for(int i = 0;i<nums.size();i++){
            if(tracker[nums[i] - 1]){
                return nums[i];
            }
            tracker[nums[i] - 1] = true;
        }

        return -1;
    }
};
