class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size(nums.size());
        if(size < 2)
            return;
        int i(size-2);
        while(i>-1&&nums[i]>=nums[i+1]) i--;
        int j(size-1);
        int k(++i);
        while(k < j)
            swap(nums[k++], nums[j--]);
        if(i == 0)
            return;
        int look = upper_bound(nums.begin()+i, nums.end(), nums[i-1]) - nums.begin();
        swap(nums[i-1], nums[look]);
        return;
    }
};