class Solution {
public:
    void dfs(vector<int>& nums, int i, int target,vector<int>& combination){
        if(target == 0){
            result.push_back(combination);
            return;
        }

        if(target < 0 || i >= nums.size()){
            return;
        }
        
        combination.push_back(nums[i]);
        dfs(nums,i,target - nums[i],combination);

        combination.pop_back();
        dfs(nums,i+1,target,combination);
    }

    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> combination;
        dfs(nums,0,target,combination);
        return result;
    }
};
