class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        long double X = x;
      if(N<0){
        X = 1/X;
        N = -N;
      }
        double ans  = 1;
        while(N>0){
            int lastbit = N & 1;
            if(lastbit){
                 ans *= X;
            }
            X = X*X;
            N =  N>>1;
        }
        return ans;
    }
};