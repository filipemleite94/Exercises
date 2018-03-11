class Solution {
private:
    string readInt(int i){
        if(i == 1){
            return "1";
        }
        string aux = readInt(i-1);
        int auxSize = aux.length();
        string num = string(2*auxSize, ' ');
        int indexAux = 0, indexNum = 0;
        while(indexAux < auxSize){
            char last = aux[indexAux];
            int q = 1;
            indexAux++;
            while(indexAux < auxSize && aux[indexAux]==last){
                indexAux++;
                q++;
            }
            stack<char> st;
            while(q>0){
                st.push(q%10 + '0');
                q/=10;
            }
            while(!st.empty()){
                num[indexNum++] = st.top();
                st.pop();
            }
            num[indexNum++] = last;
        }
        return num.substr(0, indexNum);
    }
public:
    string countAndSay(int n) {
        if(!n) return "";
        return readInt(n);
    }
};

#include <sstream>

class Solution {
private:
    string readInt(int i){
        if(i == 1){
            return "1";
        }
        string aux = readInt(i-1);
        int auxSize = aux.length();
        stringstream num;
        int indexAux = 0, indexNum = 0;
        while(indexAux < auxSize){
            char last = aux[indexAux];
            int q = indexAux;
            indexAux++;
            while(indexAux < auxSize && aux[indexAux]==last){
                indexAux++;
            }
            num<<indexAux - q;
            num<<last;
        }
        return num.str();
    }
public:
    string countAndSay(int n) {
        if(!n) return "";
        return readInt(n);
    }
};