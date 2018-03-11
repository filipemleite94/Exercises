class Solution {
private:
    void intToRomanAux(string &str, int &i, int &num, int baseNum, char base, char baseFive, char superior){
        if(num>=9*baseNum){
            str[i++] = base;
            str[i++] = superior;
            num-= 9*baseNum;
            return;
        }
        if(num>=5*baseNum){
            str[i++] = baseFive;
            num-=5*baseNum;
            while(num>=baseNum){
                str[i++] = base;
                num-=baseNum;
            }
            return;
        }
        if(num>=4*baseNum){
            str[i++] = base;
            str[i++] = baseFive;
            num-=4*baseNum;
            return;
        }
        while(num>=baseNum){
            str[i++] = base;
            num-=baseNum;
        }
        return;
    }
public:
    string intToRoman(int num) {
        string s(15, ' ');
        int i(0);
        intToRomanAux(s, i, num, 1000, 'M', 'E', 'X');
        intToRomanAux(s, i, num, 100, 'C', 'D', 'M');
        intToRomanAux(s, i, num, 10, 'X', 'L', 'C');
        intToRomanAux(s, i, num, 1, 'I', 'V', 'X');
        return s.substr(0,i);
    }
};