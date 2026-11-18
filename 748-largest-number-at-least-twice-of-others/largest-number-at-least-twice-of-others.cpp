class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        int max = nums[0];
        int secmax = -1;
        int idx = 0;
        for(int i = 1;i<n;i++){
            if(nums[i]>max){
                secmax = max;
                max = nums[i];
                idx = i;
            }
            else if(nums[i]>secmax){
                secmax = nums[i];
            }
        }
        if(max>=secmax*2){
            return idx;
        }
        else {
            return -1;
        }
    }
};