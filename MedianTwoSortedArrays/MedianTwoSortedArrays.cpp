#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
private:
    int minSize, maxSize;
	double binSearch(vector<int> &min, vector<int> &max){
        if(minSize==0){
            if(maxSize%2==0)
                return static_cast<double>(max[maxSize/2]+max[maxSize/2 + 1])/2.0;
            return static_cast<double>(max[maxSize/2]);
        }
        
		int total = minSize+maxSize;
		int lsize = (total+1)/2;
		int ini = 0, end = minSize, mid;
		while(ini+1<end){
			mid = (ini + end)/2;
			if(mid>0&&(lsize-mid<maxSize)&&min[mid-1]>max[lsize-mid]){
				end = mid;
				continue;
			}
			if(mid<minSize&&(lsize-mid)>0&&max[lsize-mid-1]>min[mid]){
				ini = mid;
				continue;
			}
            break;
		}
        mid = (ini + end)/2;
        int prox = (mid==minSize||(lsize-mid)<maxSize&&max[lsize-mid]<=min[mid])? max[lsize-mid]:min[mid];
        if(total%2==1)
            return static_cast<double>(prox);
        int prev = (mid==0||(lsize-mid>0)&&max[lsize-mid-1]>=min[mid-1])? max[lsize-mid-1]:min[mid-1];
        return static_cast<double>(prev+prox)/2.0;
	}
	
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		minSize = nums1.size();
		maxSize = nums2.size();
		vector<int>* minpV = &nums1;
		vector<int>* maxpV = &nums2;
		
		if(minSize==maxSize){
			if(minSize==0) return 0.0;
			if(nums1[0]>=nums2[maxSize-1])
				return (nums1[0]+nums2[maxSize-1])/2.0;
			if(nums1[minSize-1]<=nums2[0])
				return (nums1[minSize-1]+nums2[0])/2.0;
		}
		
		if(minSize>maxSize||minSize==maxSize&&nums1[minSize-1]>nums2[maxSize-1]){
            swap(minSize,maxSize);
			swap(minpV,maxpV);
		}
		return binSearch(*minpV, *maxpV);
		
    }
};
