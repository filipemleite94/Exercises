class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size(nums.size());
        if(size==0)
            return 1;
        for(int i = 0; i<size; i++){
            int j(nums[i]-1);
            if(j<size && j>=0 && nums[j]!=j+1){
                swap(nums[i], nums[j]);
                i--;
            }
        }
        int i = 1;
        while(i<=size && nums[i-1]==i) i++;
        return i;
    }
};