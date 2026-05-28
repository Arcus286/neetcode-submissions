class Solution {
public:
    string simplifyPath(string path) {
        vector<string> pathVec;
        stringstream ss(path);
        string segment;

        while(getline(ss, segment, '/')) {
            pathVec.push_back(segment);
        }

        stack<string> st;
        for(string c : pathVec){
            if(c == ".."){
                if(!st.empty())
                    st.pop();
            }
            else if(c != "" && c != "."){
                st.push(c);
            }
        }
        string result = "";

        while(!st.empty()){
            result = "/" + st.top() + result;
            st.pop();
        }

        return result.empty() ? "/" : result;
    }
};