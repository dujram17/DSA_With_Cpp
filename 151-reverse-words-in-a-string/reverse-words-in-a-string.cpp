class Solution {
public:
    string reverseWords(string s) {

        string word = "";
        string ans = "";

        for(int i = s.length() - 1; i >= 0; i--) {
            if(s[i] != ' ') {
                word = s[i] + word;
            }
            else if(word != "") {
                if(ans != "")
                    ans += " ";

                ans += word;
                word = "";
            }
        }

        if(word != "") {
            if(ans != "")
                ans += " ";

            ans += word;
        }

        return ans;
    }
};