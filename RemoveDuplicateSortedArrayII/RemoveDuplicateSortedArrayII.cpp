class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int end(nums.size());
        if(end<3) return end;
        int i(2);
        while(i<end && !(nums[i]==nums[i-1]&&nums[i]==nums[i-2])){
            i++;
        }
        int j(i++);
        while(i<end){
            if(!(nums[i]==nums[j-1]&&nums[i]==nums[j-2])){
                swap(nums[i],nums[j++]);
            }
            i++;
        }
        return j;
    }
};