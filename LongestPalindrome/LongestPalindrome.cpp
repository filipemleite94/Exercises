#include<string>
#include<stack>
#include<iostream>

using namespace std;

class Solution {
private:
	int max =1;
	int imax =0;
	int defMax=1;
	int size;
	string str;
	
	void expandOdd(int i){
		if(i-defMax<0||i+defMax>=size)
			return;
		int j = 0;
		while(j<defMax&&str[i-j]==str[i+j]) j++;
		if(str[i-j]!=str[i+j]) return;
		j++;
		while((i-j>-1)&&(i+j)<size && str[i-j]==str[i+j]) j++;
		defMax = j--;
		max = 1+2*j;
		imax = i-j;
	}
	
	void expandEven(int i){
		if(i-defMax<0||i+defMax+1>=size) return;
		int j =0;
		while(j<defMax&&str[i-j]==str[i+j+1]) j++;
		if(str[i-j]!=str[i+j+1]) return;
		j++;
		while((i-j>-1)&&(i+j+1)<size && str[i-j]==str[i+j+1]) j++;
		defMax = j--;
		max = 2*j+2;
		imax = i-j;
	}
	

	public:
    string longestPalindrome(string s) {
		str = s;
		size = s.length();
		if(size<2)
			return s;
		int j = size/3;
		int i = j;
		while(i<size) expandOdd(i++);
		i = j;
		while(i--)	expandOdd(i);
		i = j;
		defMax--;
		while(i<size) expandEven(i++);
		i = j;
		while(i--)	expandEven(i);
		return string(s, imax, max);
    }
};

int main(){
	string str;
	cin>>str;
	cout<<Solution().longestPalindrome(str);
}