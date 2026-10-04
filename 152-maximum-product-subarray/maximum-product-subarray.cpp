class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod = nums[0];
        int minprod = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            int a = maxprod * nums[i];
            int b = minprod * nums[i];

            maxprod = max(nums[i], max(a, b));
            minprod = min(nums[i], min(a, b));

            ans = max(ans, maxprod);
        }

        return ans;
    }
};