class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int end = 0;
        unordered_set<char> window;
        int maxWindow = 0;
        while(end < (int)s.size()){
            if(window.find(s[end]) == window.end()){
                window.insert(s[end]);
                maxWindow = max(maxWindow,(int)window.size());
                end++;
            } else {
                char c = s[end];
                while(window.find(c) != window.end()){
                    window.erase(s[start]);
                    start++;
                }
            }
        }
        return maxWindow;
    }
};
