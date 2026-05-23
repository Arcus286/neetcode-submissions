class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        for(int i = 0;i<n;i++){
            int currElem = asteroids[i];
            bool exploded = false;

            while(!st.empty() && st.top() > 0 && currElem < 0){
                if(abs(st.top()) < abs(currElem)){
                    st.pop();
                } else if(abs(st.top()) == abs(currElem)){
                    st.pop();
                    exploded = true;
                    break;
                } else{
                    exploded = true;
                    break;
                }
            }

            if(!exploded){
                st.push(currElem);
            }
        }

        vector<int> result;
        while(!st.empty()){
            int a = st.top();
            st.pop();
            result.push_back(a);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};