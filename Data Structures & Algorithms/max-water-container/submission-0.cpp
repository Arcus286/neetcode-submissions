class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int n = height.size();
        int start = 0;
        int end = n - 1;
        while(start < end){
            int length = min(height[start],height[end]);
            int breadth = end - start;
            int area = length * breadth;
            maxWater = max(area,maxWater);
            if(height[start] < height[end]){
                start++;
            }
            else{
                end--;
            }
        } 
        return maxWater;
    }
};