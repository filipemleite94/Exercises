class Solution {
public:
    int romanToInt(string s) {
        int size(s.length());
        if(size<1) return 0;
        int num(0);
        int i(0);
        int dic[256];
        dic['I'] = 1;
        dic['V'] = 5;
        dic['X'] = 10;
        dic['L'] = 50;
        dic['C'] = 100;
        dic['D'] = 500;
        dic['M'] = 1000;
        char current;
        while(i<size){
            current = s[i];
            int value(dic[current]);
            int accumuled(value);
            i++;
            while(i<size && s[i]==current){
                accumuled+=value;
                i++;
            }
            if(i<size && dic[s[i]]>value){
                num-=accumuled;
            }else{
                num+=accumuled;
            }
        }
        return num;
    }
};