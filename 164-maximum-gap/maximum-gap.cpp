class Solution {
public:
    int maximumGap(vector<int>& nums) {
       int maxi = 0;
       int diff;
       if(nums.size()<2){
        return 0;
       }
       sort(nums.begin(),nums.end());
       for(int i = 0;i<nums.size()-1;i++){
            diff = nums[i+1]-nums[i];
            if(diff>maxi){
                maxi = diff;
            }
       }
       return maxi;

    }
};