#include <utility>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i =0; i<nums.size(); i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            int sum = nums[i];
            int j(i+1);
            int k(nums.size()-1);
            while(j<k){
                int value(sum+nums[j]+nums[k]);
                if(value>0){
                    k--;
                    continue;
                }
                if(value<0){
                    j++;
                    continue;
                }
                vector<int> v;
                v.push_back(nums[i]);
                v.push_back(nums[j]);
                v.push_back(nums[k]);
                ans.push_back(v);
                j++;
                while(nums[j]==nums[j-1]) j++;
                k--;
                
            }
        }
        return ans;
    }
};