class Solution {
public:
    int jump(vector<int>& nums) {
        const int size(nums.size());
        //if(size<2)
        //    return size-1;
        int i(size);
        vector<pair<int,int>> min(size);
        i--;
        min[i].first = 0;
        min[i].second = INT_MAX;
        while(i--){
            int last = std::min(i+nums[i], size-1);
            min[i].first = INT_MAX;
            min[i].second = i;
            for(int j = i+1; j<=last;){
                if(min[j].first<min[i].first){
                    if(min[j].second<=last){
                        if(min[j].first<min[i].first){
                            min[i] = min[j];
                        }
                    }else{
                        if(1+min[j].first<min[i].first){
                            min[i].first = 1+min[j].first;
                            min[i].second = j;
                        }
                    }
                }
                j = nums[j]+j+1;
            }
        }
        return min[0].first;
    }
};