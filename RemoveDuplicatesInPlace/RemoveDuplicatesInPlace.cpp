class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i (0);
        int j (1);
        while(j<nums.size()){
            while(j<nums.size() && nums[j]==nums[i]) j++;
            if(j==nums.size()) break;
            nums[++i] = nums[j++];
        }
        if(i+1<nums.size())
            nums.resize(i+1);
//            nums.erase(nums.begin()+i+1, nums.end());
        return nums.size();
    }
};