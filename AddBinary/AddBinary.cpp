class Solution {
public:
    string addBinary(string a, string b) {
        string *minS(&a), *maxS(&b);
        if(a.length()>b.length())
            swap(minS, maxS);
        string &min = *minS, &max = *maxS;
        char carry(0);
        int i(min.length()), j(max.length());
        while(i--){
            j--;
            const int aux(carry + min[i] -'0' + max[j] - '0');
            //cout<<aux<<endl;
            max[j] = aux%2+'0';
            carry = aux/2;
        }
        //cout<<carry<<min[i+1]<<max[j-1];
        while(j--&&carry){
            const int aux(carry + max[j] - '0');
            //cout<<aux<<endl;
            max[j] = aux%2+'0';
            carry = aux/2;
        }
        if(!carry)
            return max;
        return '1'+ max;
    }
};