class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i(-1), size{strs.size()};
        if(size==0)
            return "";
        if(size==1)
            return strs[0];
        int size1(strs[0].size());
        while(++i<size1){
            char c = strs[0][i];
            int j(0);
            bool flag(true);
            while(++j<size){
                if(i==strs[j].size()|| strs[j][i]!= c){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        return strs[0].substr(0, i);
    }
};