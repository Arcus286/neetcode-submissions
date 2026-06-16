class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(int i = 0;i<s.length();i++){
            string result = "";
            if(s[i] == ']'){
                string str;
                while(st.top() != '['){
                    str = st.top() + str;
                    st.pop();
                }
                st.pop();
                string strNum = "";
                while(!st.empty() && isdigit(st.top())){
                    strNum = st.top() + strNum;
                    st.pop();
                }
                int num = stoi(strNum);
                for(int j = 0;j<num;j++){
                    result += str;
                }
                for(char ch:result){
                    st.push(ch);
                }
            }else{
                st.push(s[i]);
            }
        }
        string final_answer = "";
        while(!st.empty()){
            final_answer = st.top() + final_answer;
            st.pop();
        }
        return final_answer;
    }
};