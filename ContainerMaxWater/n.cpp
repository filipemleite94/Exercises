#include <utility>
#include <algorithm>

class Solution {
public:
    int maxArea(vector<int>& height) {
        int size(height.size());
        int i(0), j(size-1);
        int max(-1);
        int minIndex;
        int value;
        while(i<j){
            minIndex = (height[i]<height[j])? i:j;
            value = (j-i)*height[minIndex];
            if(value>max) max = value;
            if(minIndex==i)  i++;
            else j--;
        }
        return max;
    }
};