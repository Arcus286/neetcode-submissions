class Solution {
public:
    string minWindow(string s, string t) {
        if (t == "") return "";

        unordered_map<char,int> countT;
        unordered_map<char,int> window;

        //vector<int> result = {-1,-1};
        int minStart = 0;
        int resultLen = INT_MAX; 
        int start = 0;

        for (char c:t){
            countT[c]++;
        }

        int have = 0;
        int need = countT.size();

        for(int end = 0;end<s.size();end++){
            char c = s[end];
            window[c]++;

            if(countT.contains(c) && window[c] == countT[c]){
                have++;
            }

            while(have == need){
                if(end - start + 1 < resultLen) {
                    minStart = start;
                    resultLen = (end - start + 1);
                }
                window[s[start]]--;
                if(countT.contains(s[start]) && window[s[start]] < countT[s[start]]){
                    have--;
                }
                start++;
            }
        }
        return resultLen == INT_MAX ? "" : s.substr(minStart, resultLen);
    }
};
