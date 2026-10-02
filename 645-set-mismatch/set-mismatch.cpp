class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int duplicate = 0;
        for(int i = 0;i<nums.size();i++){
            for(int j = i+1;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    duplicate = nums[i];
                    
                }
            }
        }
                int missing  = 0;
                int sum = 0;
                int arrsum = 0;
                for(int i = 0;i<nums.size();i++){
                    arrsum+= nums[i];
                }
                sum = nums.size()*(nums.size()+1)/2;
                missing = sum - arrsum + duplicate;
                
        
        return {duplicate, missing};
    }
};