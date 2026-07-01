class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        unordered_map<char,int> first_string;
        unordered_map<char,int> second_string;

        for(int i = 0;i<s1.size();i++){
            first_string[s1[i]]++;
        }
        int start = 0;

        for(int end = 0;end < s2.size();end++){
            second_string[s2[end]]++;
            if(end - start + 1 == s1.size()){
                if (first_string == second_string){
                    return true;
                } 
                
                if(second_string[s2[start]] == 1){
                    second_string.erase(s2[start]);
                } else {
                    second_string[s2[start]]--;
                }
                start++;
            }
        }
        return false;
    }
};
