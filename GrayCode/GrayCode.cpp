class Solution {
private:
    vector<int> gray(int aux, int i){
        vector<int> v;
        if(i==1){
            v.push_back(0);
            v.push_back(1);
            return v;
        }
        v = gray(aux>>1, i-1);
        int j(v.size());
        while(j--){
            v.push_back(aux|v[j]);
        }
        return v;
    }
public:
    vector<int> grayCode(int n) {
        vector<int> vec;
        if(!n){
            vec.push_back(0);
            return vec;
        }
        return gray(1<<(n-1), n);
    }
};