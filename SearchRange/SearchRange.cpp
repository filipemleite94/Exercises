class Solution {
private:
    int searchLowerBound(vector<int>& nums, int ini, int end, int target){
        if(nums[ini]==target) return ini;
        ini++;
        int mid((ini+end)/2);
        while(ini<end){
            if(nums[mid]>=target){
                if(nums[mid-1]<target){
                    return nums[mid]==target? mid:-1;
                }
                end = mid-1;
            }else{
                ini = mid+1;
            }
            mid = (ini+end)/2;
        }
        while(nums[ini-1]>=target)ini--;
        return nums[ini]==target? ini:-1;
    }
    
    int searchHigherBound(vector<int>& nums, int ini, int end, int target){
        if(nums[end]==target) return end;
        end--;
        int mid((ini+end)/2);
        while(ini<end){
            if(nums[mid]<=target){
                if(nums[mid+1]>target)
                    return mid;
                ini = mid+1;
            }else{
                end = mid-1;
            }
            mid = (ini+end)/2;
        }
        while(nums[end+1]<=target)end++;
        return end;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> vec(2,-1);
        int size(nums.size());
        if(size==0 || nums[0]>target || nums[size-1]<target) return vec;
        vec[0] = searchLowerBound(nums, 0, size-1, target);
        if(vec[0]==-1) return vec;
        vec[1] = searchHigherBound(nums, vec[0], size-1, target);
        return vec;
    }
};