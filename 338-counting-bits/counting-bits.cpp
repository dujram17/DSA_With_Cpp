class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0;i<=n;i++){
            int n = i;
            int count = 0;
            while(n>0){
                count += n & 1;
                n = n>>1;

            }
            ans.push_back(count);
        }
        return ans;

    }
};