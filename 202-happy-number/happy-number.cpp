class Solution {
public:
    bool isHappy(int n) {
        while(n!=1 && n!=4){
            int sum = 0;
            while(n>0){
                int lastdigit = n%10;
                int sqr = lastdigit * lastdigit;
                sum = sum + sqr;
                n = n/10;
            }
            n = sum;
        }
        if(n==1){
            return true;
        }
        else{
            return false;
        }
    }
};