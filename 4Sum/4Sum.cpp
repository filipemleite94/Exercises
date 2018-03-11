class Solution {
private:
    unordered_map<int, int> mapCount;
    unordered_map<int, vector<int>> map;
    int merge[4];
    int target;
    int size;
    
    void constructMaps(vector<int> &nums, int target){
        this->target = target;
        size = nums.size();
        for(int i = 0; i<size;){
            for(int j = i+1; j < size;){
                vector<int> &v = map[nums[i]+nums[j]];
                v.push_back(i);
                v.push_back(j);
                
                j++;
                while(j<size && nums[j] == nums[j-1]) j++;
            }
            int &numI = mapCount[nums[i]];
            numI++;
            i++;
            while(i < size && nums[i] == nums[i-1]){
                numI++;
                i++;
            }
        }
    }
    
    bool getSums(int sum, vector<int> &v1, vector<int> &v2){
        auto it1 = map.find(sum);
        auto it2 = map.find(target-sum);
        if(it1 == map.end()||it2 == map.end()){
            return false;
        }
        v1 = (it1->second);
        v2 = (it2->second);
        return true;
    }
    
    void mergeV(int *v1, int *v2){
        int i = 0, j = 0, k = 0;
        while(i<2&&j<2)
            merge[k++] = (v1[i]<v2[j])? v1[i++]:v2[j++];
        while(i<2)
            merge[k++] = v1[i++];
        while(j<2)
            merge[k++] = v2[j++];
    }
    
    bool verify(){
        for(int i = 0; i < 4;){
            int numI = mapCount[merge[i]];
            numI--;
            i++;
            while(i < 4 && merge[i] == merge[i-1]){
                numI--;
                i++;
            }
            if(numI<0)
                return false;
        }
        return true;
    }
    
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        constructMaps(nums, target);
        vector<int> v1;
        vector<int> v2;
        vector<vector<int>> ans;
        for(int i  = 0; i<size; i++){
            int ivalue(nums[i]);
            for(int j = 0; j < size; j++){
                int jvalue(nums[j]);
                if(!getSums(ivalue+jvalue, v1, v2))
                    continue;
                for(int k = 0; k<v1.size(); k+=2){
                    for(int l = 0; l<v2.size(); l+=2){
                        int av1[2] = {nums[v1[k]], nums[v1[k+1]]}, av2[2] = {nums[v2[l]], nums[v2[l+1]]};
                        mergeV(av1, av2);
                        if(merge[0]!=ivalue||merge[1]!=jvalue)
                            continue;
                        if(!verify())
                            continue;
                        vector<int> aux(merge, merge+4);
                        ans.push_back(aux);
                    }
                }
                j++;
                while(j<size && nums[j] == nums[j-1]) j++;
                j--;
            }
            i++;
            while(i<size && nums[i] == nums[i-1]) i++;
            i--;
        }
        return ans;
    }
};