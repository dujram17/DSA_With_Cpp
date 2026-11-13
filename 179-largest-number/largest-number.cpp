class Solution {
public:
    static bool cmp(int a, int b) {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);

        if (nums[0] == 0) {
            return "0";
        }

        string ans = "";

        for (int i = 0; i < nums.size(); i++) {
            ans += to_string(nums[i]);
        }

        return ans;
    }
};