class Solution {
public:
    int numTilings(int N) {
        if(N<0) return 0;
        if(N<2) return 1;
        if(N==2) return 2;
        vector<long long> v(N+1, 0);
        v[0] = v[1] = 1;
        v[2] = 2;
        for(int i = 3; i<N+1; i++){
            v[i] = (2*v[i-1] + v[i-3])%(1000000000ll+7ll);
        }
        return v[N];
    }
};