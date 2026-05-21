class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int n = operations.size();
        for(int i = 0;i<n;i++){
            if(operations[i] == "+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b);
                st.push(a);
                st.push(a + b);
            } else if(operations[i] == "C"){
                st.pop();
            } else if(operations[i] == "D"){
                int a = st.top();
                a = a * 2;
                st.push(a);
            } else {
                st.push(stoi(operations[i]));
            }
        }
        int result = 0;
        while(!st.empty()){
            int a = st.top();
            result += a;
            st.pop();
        }
        return result;
    }
};