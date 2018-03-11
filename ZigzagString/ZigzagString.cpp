#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
		if(numRows==1||numRows>s.length())
			return s;
		int size = s.length();
		int auxNum = 2*(numRows-1);
		int complete = size/(auxNum);
		int incomplete = size%(auxNum);
		int completePlusOne = complete+1;
		int auxNum2 = completePlusOne*auxNum;
		int str[auxNum2] = {};
		int iS[auxNum2] = {};
		for(int i = 0; i<size; i++){
			iS[i] = s[i];
		}
		for(int i = size; i<auxNum2; i++){
			iS[i] = -1;
		}
		int k = 0;
		int ini = 0;
		for(int i = 0; i<completePlusOne; i++){
			str[ini] = iS[k++];
			ini += completePlusOne+i;
			for(int j = 1; j< numRows-1; j++){
				str[ini] = iS[k++];
				ini+=2*completePlusOne;
			}
			ini -= i;
			str[ini] = iS[k++];
			ini -= 2*completePlusOne - i - 1;
			for(int j = numRows-2; j>0; j--){
				str[ini] = iS[k++];
                ini-=2*completePlusOne;
			}
			ini -= i - completePlusOne;
			cout<< size<<" "<<ini<<" "<<k<<endl;
		}
		string ans(size, 's');
		k = 0;
		for(int i = 0; i<auxNum2; i++){
			cout<<str[i]<< " ";
			if(str[i]!=-1)
				ans[k++] = static_cast<char>(str[i]);
		}
		return ans;
    }
};

int main(){
	string s;
	cin>>s;
	Solution sol;
	cout<<sol.convert(s, 55);
	cout<<endl<<"Finished"<<endl;
	return 0;
}