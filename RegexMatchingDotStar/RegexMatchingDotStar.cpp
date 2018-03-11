class Solution {
private:
    bool charMatch(char c1, char c2){
        return c2=='.' ||c1==c2;
    }
public:
    bool isMatch(string s, string p) {
        int sizeS(s.length()), sizeP(p.length());
        int i(sizeS), j(sizeP);
        bool m[sizeS+1][sizeP+1];
        
        m[sizeS][sizeP] = true;
        while(j--){
            if(j<sizeP && p[j+1]=='*' )
                m[sizeS][j] = m[sizeS][j+2];
            else
                m[sizeS][j] = false;
        }
        
        while(i--){
            j = sizeP;
            m[i][sizeP] = false;
            while(j--){
                m[i][j] = charMatch(s[i], p[j]) && 
                    (m[i+1][j+1]||j < sizeP && p[j+1] == '*' && m[i+1][j]) 
                    || j < sizeP && p[j+1] == '*' && m[i][j+2];
            }
        }
        return m[0][0];
    }
};