class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //return lower_bound(nums.begin(), nums.end(), target)-nums.begin();
        int size(nums.size());
        if(!size)
            return 0;
        if(size<4){
            int ans = 0;
            while(ans<size && nums[ans]<target) ans++;
            return ans;
        }
        int ini(0), end(size-1), mid(size/2);
        int comp;
        while(ini < end-4){
            mid = (ini + end)>>1;
            comp = nums[mid]-target;
            if(!comp)
                return mid;
            if(comp>0){
                end = mid-1;
            }else{
                ini = mid+1;
            }
        }
        if(ini>0)
            ini--;
        while(ini<size && nums[ini]<target) ini++;
        return ini;
    }
};