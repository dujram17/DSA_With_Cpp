class Solution {
public:
    int Search(vector<int>&nums,int st,int end,int tar){
        if(st>end){
            return -1;
        }
        int mid = st+(end-st)/2;
        if(nums[mid]==tar){
            return mid;
        }
        if(nums[st]<=nums[mid]){
            if(nums[st]<=tar && tar<=nums[mid]){
                return Search(nums,st,mid-1,tar);
            }
            else{
                return Search(nums,mid+1,end,tar);
            }
        }
        else{
            if(nums[mid]<=tar && tar<=nums[end]){
                return Search(nums,mid+1,end,tar);
            }
            else{
                return Search(nums,st,mid-1,tar);
            }
        }
    }
    int search(vector<int>& nums, int target) {
        return Search(nums,0,nums.size()-1,target);
    }
};