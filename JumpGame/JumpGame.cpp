class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        if(!size)
            return false;
        for(int i = 0; i < size-1; i++){
            int j(nums[i]-1);
            if(j<0)
                return false;
            if(nums[i+1]<j)
                nums[i+1] = j;
        }
        return true;
    }
};