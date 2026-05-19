class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result;
        int n = temperatures.size();
        for(int i = 0 ;i < n;i++){
            if(i == n) result.push_back(0);
            int count = 0;
            for(int j = i + 1;j < n ;j++){
                if(temperatures[j] > temperatures[i]){
                    result.push_back(count + 1);
                    break;
                } else{
                    count++;
                }
                if(j == n - 1){
                    result.push_back(0);
                }
            }
        }
        result.push_back(0);
        return result;
    }
};
