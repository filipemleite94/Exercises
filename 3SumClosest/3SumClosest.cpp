class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3) return-1;
        sort(nums.begin(), nums.end());
        int value = nums[0] + nums[1] + nums[2] - target;
        int absClosest = (value>0)? value:-value;
        int sumClosest = value+target;
        int i, j ,k;
        for(i = 0; i<nums.size(); i++){
            j = i+1;
            k = nums.size()-1;
            int sum = nums[i] - target;
            while(j<k){
                value = nums[j] + nums[k] + sum;
                if(value<0){
                    j++;
                    if(-value<absClosest){
                        absClosest = -value;
                        sumClosest = value+target;
                    } 
                }else{
                    k--;
                    if(value<absClosest){ 
                        absClosest = value;
                        sumClosest = value + target;
                    }
                }
            }
        }
        return sumClosest;
    }
};