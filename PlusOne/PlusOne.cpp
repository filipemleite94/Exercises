class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size(digits.size());
        if(digits[size-1]<9){
            digits[size-1]++;
            return digits;
        }
        vector<int> vec(digits);
        int carry(1);
        int i(size-1);
        vec[i] = 0;
        while(i--){
            vec[i] = (carry+digits[i])%10;
            carry = (carry+digits[i])/10;
        }
        if(carry)
            vec.insert(vec.begin(), 1);
        return vec;
    }
};