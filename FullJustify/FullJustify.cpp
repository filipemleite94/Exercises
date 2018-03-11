class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        const size_t sizeW(words.size());
        for(int i = 0; i<sizeW;){
            int size(maxWidth);
            int ini(i);
            size-=words[i++].length();
            while(i<sizeW && ((size-(int)(words[i].length()))>0)){
                size-=words[i++].length()+1;
            }
            string s(maxWidth, ' ');
            if(i==sizeW||i-ini==1){
                int j=0;
                while(ini<i){
                    const string &sAux = words[ini++];
                    s.replace(j, sAux.length(), sAux);
                    j+=sAux.length()+1;
                }
            }else{
                int j = 0;
                int k = size%(i-ini-1);
                int l = 1+size/(i-ini-1);
                while(k--){
                    const string &sAux = words[ini++];
                    s.replace(j, sAux.length(), sAux);
                    j+=sAux.length()+l+1;
                }
                while(ini<i){
                    const string &sAux = words[ini++];
                    s.replace(j, sAux.length(), sAux);
                    j+=sAux.length()+l;
                }
            }
            ans.push_back(s);            
        }
        return ans;
    }
};