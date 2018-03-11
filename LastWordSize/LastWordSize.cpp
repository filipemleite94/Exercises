class Solution {
public:
    int lengthOfLastWord(string s) {
        int l(0);
        for(int i = 0; i< s.length(); i++){
            if(s[i]==' '){
                while(i<s.length()&&s[i]==' '){
                    i++;
                }
                if(i==s.length())
                    return l;
                l = 1;
            }
            else
                l++;
        }
        return l;
    }
};