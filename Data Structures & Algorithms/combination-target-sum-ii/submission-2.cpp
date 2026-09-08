class Solution {
public:
    vector<vector<int>> result;

    void dfs(vector<int>& candidates,int i, int target,vector<int>& combination,int total){
        if(target == total){
            result.push_back(combination);
            return;
        }

        if(i == candidates.size() || target < total){
            return;
        }

        combination.push_back(candidates[i]);
        dfs(candidates,i+1,target,combination,total + candidates[i]);

        combination.pop_back();

        while(i + 1 < candidates.size() && candidates[i] == candidates[i + 1]){
            i++;
        }

        dfs(candidates,i+1,target,combination,total);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> combination;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,0,target,combination,0);
        return result;
    }
};
