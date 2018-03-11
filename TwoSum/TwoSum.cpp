#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void GetTwoSum(vector<int>&, int, int&, int&);

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j;
        GetTwoSum(nums, target, i, j);
		vector<int> ans;
		ans.push_back(i);
		ans.push_back(j);
        return ans;
    }
private:
};

struct AuxStruct{
	int i, val;
};

bool compare(AuxStruct aS1, AuxStruct aS2){
	return aS1.val < aS2.val;
}

void GetTwoSum(vector<int>& nums, int target, int& outi,int& outj){
    vector<AuxStruct> indexes;
	for(int i =0; i<nums.size(); i++){
		indexes.push_back(AuxStruct{i,nums[i]});
	}
	sort(indexes.begin(), indexes.end(), compare);
	int j = nums.size()-1;
	for(int i =0; i!=j;){
		int sum{indexes[i].val + indexes[j].val};
		if(sum==target){
			outi = indexes[i].i;
			outj = indexes[j].i;
			return;
		}
		if(sum<target){
			i++;
			continue;
		}
		if(sum>target){
			j--;
			continue;
		}
	}
}

int main(){
	int target;
	cin>>target;
	vector<int> p;
	int i;
	while(cin>>i) p.push_back(i);
	Solution sol;
	vector<int> v = sol.twoSum(p, target);
	cout<<v[0]<<" "<<v[1];
}