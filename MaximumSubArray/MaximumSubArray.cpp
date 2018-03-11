class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i(0), size(nums.size()), val;
        vector<int> sums;
        int max(INT_MIN);
        while(i<size){
            if(nums[i]<0){
                if(nums[i]>max)
                    max = nums[i];
                i++;
                continue;
            }
            val = nums[i];
            i++;
            while(i<size&&val>=0){
                if(val>max)
                    max = val;
                val+=nums[i];
                i++;
            }
            if(val>max)
                max = val;
        }
        return max;
    }
};