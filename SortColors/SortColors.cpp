class Solution {
public:
    void sortColors(vector<int>& nums) {
        auto r(nums.begin()), w(nums.begin()), b(nums.end());
        if(r==b)
            return;
        b--;
        while(b>=w){
            switch(*w){
                case(0):
                    swap(*r++, *w++);
                    break;
                case(1):
                    w++;
                    break;
                case(2):
                    swap(*b--, *w);
                    break;
                default:
                    throw "Illegal argument";
                    break;
            }
        }
    }
};