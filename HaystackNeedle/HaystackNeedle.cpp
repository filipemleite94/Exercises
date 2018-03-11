class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="")
            return 0;
        char c(needle[0]);
        int max(haystack.size()-needle.size()+1);
        for(int i =0; i<max; i++){
            if(haystack[i]==c){
                int j=0;
                while(++j < needle.size()){
                    if(haystack[i+j]!=needle[j]){
                        break;
                    }
                }
                if(j==needle.size())
                    return i;
            }
        }
        return -1;
    }
};