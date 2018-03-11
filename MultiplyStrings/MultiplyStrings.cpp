class Solution {
private:
    string sumStrings(string &s1, const string &s2, int shift){
        int carry = 0;
        int i(s1.length());
        int j(s2.length());
        string resp(max(i, j+shift)+1 , '0');
        int k(resp.length());
        i--;
        j--;
        k--;
        while(shift--){
            resp[k--] = s1[i--];
        }
        while(i>-1&&j>-1){
            int num(carry+s1[i--]-'0'+s2[j--]-'0');
            carry = num/10;
            resp[k--] = num%10+'0';
        }
        while(i>-1){
            int num(carry+s1[i--]-'0');
            carry = num/10;
            resp[k--] = num%10+'0';
        }
        while(j>-1){
            int num(carry+s2[j--]-'0');
            carry = num/10;
            resp[k--] = num%10+'0';
        }
        resp[k--] = carry+'0';
        if(resp[0]=='0')
            return resp.substr(1, resp.length()-1);
        else
            return resp;
    }
    
    string mulStrings(string &s1, char c){
        int carry(0);
        int i(s1.length());
        int j(s1.length()+1);
        string resp(j,'0');
        i--;
        j--;
        while(i>-1){
            int num = carry + (s1[i--]-'0')*(c-'0');
            resp[j--] = num%10+'0';
            carry = num/10;
        }
        resp[j--] = carry+'0';
        if(resp[0]=='0')
            return resp.substr(1, resp.length()-1);
        else
            return resp;
    }
public:
    string multiply(string num1, string num2) {
        int carry = 0;
        int i(num1.length());
        int j(num2.length());
        if(!i)
            return num2;
        if(!j)
            return num1;
        if(num1=="0"||num2=="0"){
            return "0";
        }
        string resp;
        if(i<=j){
            resp = mulStrings(num2, num1[--i]);
            int size(i);
            while(i--){
                resp = sumStrings(resp, mulStrings(num2, num1[i]), size-i);
            }
        }else{
            resp = mulStrings(num1, num2[--j]);
            int size(j);
            while(j--){
                resp = sumStrings(resp, mulStrings(num1, num2[j]), size-j);
            }
        }
        return resp;
    }
};