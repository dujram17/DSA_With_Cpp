class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0;
        int product = 1;
        while(n>0){
            int lastdgt = n%10;
            sum += lastdgt;
            product *= lastdgt;
            n /= 10;
        }
        return product-sum;
    }
};