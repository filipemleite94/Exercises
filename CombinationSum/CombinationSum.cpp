class Solution {
private:
    int size;
    vector<vector<int>> sol;
    
    void getSums(vector<int> &candidates, int i, int target, vector<int> &sofar){
        if(target<0) return;
        while(i<size && candidates[i]>target) i++;
        if(i == size) return;
        int cand;
        while(i<size){
            cand = candidates[i];
            sofar.push_back(cand);
            if(target-cand == 0)
                sol.push_back(sofar);
            getSums(candidates, i, target-cand, sofar);
            sofar.pop_back();
            i++;
        }
        return;
    }
    
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), [&](int i, int j){return i>j;});
        size = candidates.size();
        vector<int> vec;
        getSums(candidates, 0, target, vec);
        return sol;
    }
};