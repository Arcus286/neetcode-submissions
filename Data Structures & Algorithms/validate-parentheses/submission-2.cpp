class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }else{
                if(st.empty()){
                    return false;
                }
                char currentElem = s[i];
                char stackTop = st.top();
                if (currentElem == ')' && stackTop != '(') return false;
                if (currentElem == ']' && stackTop != '[') return false;
                if (currentElem == '}' && stackTop != '{') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
