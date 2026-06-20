class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size() - 1;
        for(int i = 0;i<matrix.size();i++){
            if(matrix[i][0] <= target && matrix[i][n] >= target){
                int start = 0;
                int end = n;
                while(start <= end){
                    int mid = start + (end - start) / 2;
                    if(matrix[i][mid] == target){
                        return true;
                    } else if(target < matrix[i][mid]){
                        end = mid - 1;
                    } else {
                        start = mid + 1;
                    }
                }
                break;
            }
        }
        return false;
    }
};
