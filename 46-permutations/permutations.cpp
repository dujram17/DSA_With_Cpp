class Solution {
public:
    vector<vector<int>>ans;
    void permutations(vector<int>nums,vector<int>temp){
        int n = nums.size();
        if(n==0){
            ans.push_back(temp);
            return;
        }
        for(int i = 0;i<nums.size();i++){
            int ch = nums[i];
            vector<int>nextnums = nums;
            nextnums.erase(nextnums.begin()+i);
            temp.push_back(ch);
             permutations(nextnums,temp);
             temp.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        permutations(nums,temp);
       return ans;
    }
};