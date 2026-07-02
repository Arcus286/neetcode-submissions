class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int start = 0;
        int end = arr.size()-1;
        while(end - start + 1 > k){
            if(abs(x - arr[start]) > abs(x - arr[end])){
                start++;
            } else {
                end--;
            }
        }
        vector<int> result;
        for(int i = start;i<=end;i++){
            result.push_back(arr[i]);
        }
        return result;
    }
};