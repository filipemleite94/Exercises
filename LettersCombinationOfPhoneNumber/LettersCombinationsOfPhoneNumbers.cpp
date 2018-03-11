class Solution {
private:
    vector<string> dic;
    void upString(vector<string> &str, int index){
        if(dic[index].size()<1) return;
        vector<string> copy(str);
        str.clear();
        //str.resize(copy.size()*dic[index].size());
        for(int i = 0; i<dic[index].size(); i++){
            for(int j = 0; j < copy.size(); j++){
                str.push_back(copy[j] + dic[index][i]);
            }
        }
        return;
    }
public:
    vector<string> letterCombinations(string digits) {
        dic.push_back(" ");
        dic.push_back("");
        dic.push_back("abc");
        dic.push_back("def");
        dic.push_back("ghi");
        dic.push_back("jkl");
        dic.push_back("mno");
        dic.push_back("pqrs");
        dic.push_back("tuv");
        dic.push_back("wxyz");
        vector<string> v;
        if(digits.size()<1) return v;
        v.push_back("");
        for(int i = 0; i < digits.size(); i++){
            upString(v, digits[i]-'0');
        }
        return v;
    }
};