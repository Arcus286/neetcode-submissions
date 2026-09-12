class Solution {
public:
    vector<vector<int>> result;
    void dfs(vector<int>& nums, int i,vector<int>& subset){
        if(i == nums.size()){
            result.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(nums,i + 1,subset);

        subset.pop_back();
        while(i + 1 < nums.size() && nums[i] == nums[i + 1]){
            i++;
        }
        dfs(nums,i + 1,subset);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> subset;
        dfs(nums,0,subset);
        return result;
    }
};
