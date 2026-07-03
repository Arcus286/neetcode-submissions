class Solution {
   public:
    int characterReplacement(string s, int k) {
        int start = 0;
        int maxSize = 0;
        int maxFreq = 0;
        unordered_map<char, int> mp;

        // auto maxPairIt =
        //     max_element(mp.begin(), mp.end(), [](const auto& p1, const auto& p2) {
        //         return p1.second < p2.second;
        //     });

        for (int end = 0; end < s.size(); end++) {
            mp[s[end]]++;
            maxFreq = max(maxFreq,mp[s[end]]);
            int window_size = end - start + 1;
            if(window_size - maxFreq <= k){
                maxSize = max(maxSize,window_size);
            } else {
                while(window_size - maxFreq > k){
                    mp[s[start]]--;
                    start++;
                    window_size--;
                }
            }
        }
        return maxSize;
    }
};
