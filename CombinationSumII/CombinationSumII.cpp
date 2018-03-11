class Solution {
private:
    vector<vector<int>> sol;
    int size;
    
    void getSum2(vector<int>& candidates, int i, int target, vector<int> &sofar){
        while(i<size&&candidates[i]>target) i++;
        if(i==size) return;
        int cand;
        while(i<size){
            cand = candidates[i];
            if(target-cand>=0){
                sofar.push_back(cand);
                if(target-cand==0)
                    sol.push_back(sofar);
                getSum2(candidates, i+1, target-cand, sofar);
                sofar.pop_back();
            }          
            i++;
            while(i<size&&candidates[i]==candidates[i-1]) i++;
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        size = candidates.size();
        sort(candidates.begin(), candidates.end(), [&](int i, int j){return i>j;});
        vector<int> vec;
        getSum2(candidates, 0, target, vec);
        return sol;
    }
};