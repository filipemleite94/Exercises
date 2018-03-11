class Solution {
private:
    vector<string> vec;
    int size;
    void getPermutation(string &s, int begin){
        while(begin<size && s[begin]>='0'&&s[begin]<='9'){
            begin++;
        }
        if(begin == size){
            vec.push_back(s);
            return;
        }
        getPermutation(s, begin+1);
        char c = s[begin];
        if(c<='Z'){
            s[begin] = c - 'A' + 'a';
        }else{
            s[begin] = c-'a'+'A';
        }
        getPermutation(s, begin+1);
        s[begin] = c;
        return;
    }
    
public:
    vector<string> letterCasePermutation(string S) {
        size = S.length();
        getPermutation(S, 0);
        return vec;
    }
};