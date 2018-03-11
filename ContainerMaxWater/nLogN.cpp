#include <utility>
#include <algorithm>

class Solution {
public:
    int maxArea(vector<int>& height) {
        int size(height.size());
        int index[size];
        int i(0);
        for(i = 0; i<size; i++) index[i] = i;
        sort(index, index + size, [&height](int l, int m){ return height[l]< height[m];});
        i = size-2;
        int minLeft(index[size-1]), maxRight(index[i]);
        if(minLeft>maxRight)
            swap(minLeft, maxRight);
        int areaMax((maxRight-minLeft)*height[index[i]]);
        while(i--){
            if(index[i] < minLeft){
                minLeft = index[i];
                int value = (maxRight-minLeft)*height[minLeft];
                if(value>areaMax)
                    areaMax = value;
            }
            else{
                if(index[i]>maxRight){
                    maxRight = index[i];
                    int value = (maxRight-minLeft)*height[maxRight];
                    if(value>areaMax)
                        areaMax = value;
                }
            }
        }
        return areaMax;
    }
};