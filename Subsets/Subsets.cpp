class Solution {
private:
    void subsetsRec(vector<vector<int>> &ans, vector<int> &nums, int index, int ini){
        ans.push_back(vector<int>(nums.begin(), nums.begin()+index));
        while(ini<nums.size()){
            swap(nums[ini], nums[index]);
            subsetsRec(ans, nums, index+1, ini+1);
            swap(nums[ini], nums[index]);
            ini++;
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> vec;
        vector<int> v;
        subsetsRec(vec, nums, 0, 0);
        return vec;
    }
};