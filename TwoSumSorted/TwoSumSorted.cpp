#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unsigned int i{0}, j{numbers.size()-1};
		vector<int> ans;
		while(i!=j){
			int sum = numbers[i] + numbers[j];
			if(sum==target)
			{
				ans.push_back(i);
				ans.push_back(j);
				break;
			}
			if(sum<target){
				i++;
				continue;
			}
			//if(sum>target){
				j--;
				continue;
			//}
		}
		return ans;
    }
};