class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum;
        int arrsum = 0;
        int missing;
        sum = n*(n+1)/2;
        for(int i = 0;i<n;i++){
            arrsum += nums[i];
        }
        missing = sum-arrsum;
        return missing;
        
    }
};