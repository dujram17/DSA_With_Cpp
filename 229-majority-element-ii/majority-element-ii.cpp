class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       vector<int>ans;
       int n = nums.size();
       for(int i = 0;i<n;i++){
        int count = 0;
        bool duplicate =false;
        for(int j = 0;j<i;j++){
            if(nums[i]==nums[j]){
                duplicate = true;
                break;
            }
        }
        if(duplicate) continue;

        for(int j = 0;j<n;j++){
            if(nums[i]==nums[j]){
                count++;
            }
        }
        if(count>n/3){
            ans.push_back(nums[i]);
        }

       }
       return ans;
    }
};
