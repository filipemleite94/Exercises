class Solution {
private:
    int target;
    
    int binSearchRange(vector<int>& nums, int ini, int end){
        int i = lower_bound(nums.begin()+ini, nums.begin()+end, target) - nums.begin();
        if(i==end)
            return -1;
        return target ==nums[i] ? i:-1;
    }
    
    int searchRec(vector<int>& nums, int ini, int end){
        if(end-ini<3){
            int i = ini-1;
            while(i++<end){
                if(nums[i]==target)
                    return i;
            }
            return -1;
        }
        int mid((ini+end)/2);
        int val(nums[mid]);
        if(target==val) return mid;
        if(nums[ini]>=val){
            if( target > val && target <= nums[end] ) return binSearchRange(nums, mid+1, end+1);
            return searchRec(nums, ini, mid-1);
        }else{
            if(target<val && nums[ini]<=target) return binSearchRange(nums, ini, mid);
            return searchRec(nums, mid+1, end);
        }
    }
public:
    int search(vector<int>& nums, int target) {
        int size(nums.size());
        if(size==0) return -1;
        this->target = target;
        if(nums[size-1]>=nums[0]){
            return binSearchRange(nums, 0, size);
        }
        return searchRec(nums, 0, size-1);
    }
};