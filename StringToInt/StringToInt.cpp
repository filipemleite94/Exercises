#include <limits.h>

class Solution {
private:
    bool convertCharToInt(char c, char &outInt){
        if(c>'9'||c<'0'){
            outInt = -1;
            return false;
        }            
        else{
            outInt = c - '0';
            return true;
        }
    }
public:
    int myAtoi(string str) {
        int size = str.length();
        int index = 0;
        if(size<1)  return 0;
        while(index<size&&str[index]==' ')
            index++;
        if(index==size) return 0;
        bool isPositive = true;
        if(str[index]=='+'||str[index]=='-'){
            if(str[index]=='-')
                isPositive = false;
            index++;
        }
        char charNum;
        if(index==size||!convertCharToInt(str[index],charNum)) return 0;
        int num = charNum;
        if(!isPositive) num = -num;
        index++;
        if(isPositive){
            int max10 = INT_MAX/10;
            while(index<size && convertCharToInt(str[index], charNum)){
                if(max10>=num && INT_MAX-charNum >= 10*num){
                    num = 10*num+charNum;
                }else{
                    return INT_MAX;
                }
                index++;
            }
        }else{
            int min10 = INT_MIN/10;
            while(index<size && convertCharToInt(str[index], charNum)){
                if(min10<=num && INT_MIN+charNum <= 10*num){
                    num = 10*num-charNum;
                }else{
                    return INT_MIN;
                }
                index++;
            }
        }
        return num;
    }
};