class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0;
        int count = 0;
        
        for(auto n: nums) {
            if(count == 0) {
                res = n;
            }
            
            count += (n == res) ? 1 : -1;
        }
        
        return res;
    }
};