class Solution {
private:
    void combineRec(vector<vector<int>> &ans, vector<int> &v, int index, int k, int iniValue, int cap){
        if(index==k){
            ans.push_back(v);
            return;
        }
        v.push_back(iniValue);
        while(cap>-1){
            v[index] = iniValue++;
            combineRec(ans, v, index+1, k, iniValue, cap--);
        }
        v.pop_back();
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        combineRec(ans, v, 0, k, 1, n-k);
        return ans;
    }
};