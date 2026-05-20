class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if(n == 0) return 0;
        vector<pair<int,int>> pairs(n);
        for(int i = 0;i<n;i++){
            pairs[i] = {position[i],speed[i]};
        }
        sort(pairs.begin(),pairs.end());
        stack<double> st;
        for(int i = n - 1;i>=0;i--){
            double time = (double) (target - pairs[i].first) / pairs[i].second;
            st.push(time);
            if(st.size() >= 2){
                double current_time = st.top();
                st.pop();
                double fleetTime = st.top();

                if(current_time <= fleetTime){

                }else{
                    st.push(current_time);
                }
            }
        }
        return st.size();
    }
};
