class Solution {
public:
    int mySqrt(int x) {
        int res = 0;
        int start = 1;
        int end = x;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if((long long) mid * mid == x){
                return mid;
            } else if(x < (long long) mid * mid){
                end = mid - 1;
            } else if(x > (long long) mid * mid){
                res = mid;
                start = mid + 1;
            }
        }
        return res;
    }
};