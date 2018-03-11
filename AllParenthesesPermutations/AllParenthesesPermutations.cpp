class Solution {
private:
    vector<string> getStrings(int firstIndex, int usedParentheses, int remainingParentheses){
        vector<string> str;
        int pos(2*usedParentheses-firstIndex+1);
        if(!remainingParentheses){
            str.push_back(string(pos-1, ')'));
            return str;
        }
        str.reserve(pos);
        for(int i =0; i<pos; i++){
            string s(i+1, ')');
            s[i] = '(';
            vector<string> vec = getStrings(firstIndex+i+1, usedParentheses+1, remainingParentheses-1);
            for(auto sub:vec){
                str.push_back(s+sub);
            }
        }
        return str;
    }
public:
    vector<string> generateParenthesis(int n) {
        if(n ==0)
            return vector<string>(1, "");
        int i = 0;
        int q = 1;
        while(i++<n){
            q*=i;
        }
        return getStrings(0, 0, n);
    }
};