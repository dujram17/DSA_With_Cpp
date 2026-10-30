class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for(int j = 1;j<n;j++){
            string ans = "";
        
        for(int i  = 0;i<s.length();i++){
            int count  = 1;

        while(i+1<s.length() && s[i]==s[i+1]){
            count++;
            i++;
        }
        ans += to_string(count);
        ans += s[i];
        }
        
        s = ans;
        }
        return s;

    }
};