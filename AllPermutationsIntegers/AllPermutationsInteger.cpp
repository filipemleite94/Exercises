class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int size(nums.size());
        vector<vector<int>> vec;
        if(nums.size()==0)
            return vec;
        stack<vector<int>> st;
        vector<int> vecAux(1, nums[0]);
        st.push(vecAux);
        for(int i  =1; i<size; i++){
            stack<vector<int>> stAux;
            int num(nums[i]);
            while(!st.empty()){
                vector<int> &temp = st.top();
                vector<int> v(i+1, 0);
                for(int j = 0; j <= i; j++){
                    int l(0);
                    while(l<j){
                        v[l] = temp[l];
                        l++;
                    }
                    v[l] = num;
                    while(l++<i){
                        v[l] = temp[l-1];
                    }
                    stAux.push(v);
                    
                }
                st.pop();
            }
            while(!stAux.empty()){
                st.push(stAux.top());
                stAux.pop();
            }
        }
        while(!st.empty()){
            vec.push_back(st.top());
            st.pop();
        }
        return vec;
    }
};

class Solution {
private:
    vector<vector<int>> vec;
    int size;
    
    void getPermutations(vector<int>& nums, int begin){
        if(begin==size){
            vec.push_back(nums);
            return;
        }
        for(int i = begin; i<size; i++){
            swap(nums[i], nums[begin]);
            getPermutations(nums, begin+1);
            swap(nums[i], nums[begin]);
        }
        return;
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        size = nums.size();
        vec.clear();
        long long aux = 1;
        for(int i = 2; i<=size; i++){
            aux*=i;
        }
        vec.reserve(aux);
        if(nums.size()==0)
            return vec;
        getPermutations(nums, 0);
        return vec;
    }
};