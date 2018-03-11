class Solution {
public:
    int numTrees(int n) {
        if(n<2)
            return max(n,0);
        vector<int> v;
        v.reserve(n+1);
        v.push_back(1);
        v.push_back(1);
        for(int i = 2; i<=n; i++){
            int k = i-1;
            int sum = 0;
            for(int j = 0; j<i; j++){
                sum+=v[j]*v[k--]; 
            }
            v.push_back(sum);
        }
        return v[n];
    }
};