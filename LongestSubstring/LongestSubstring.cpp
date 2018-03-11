#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        int array[256] = {};
        int size = s.length();
        int curr(0);
        for(int i = 0; i< size; i++){
            if(i-array[s[i]]<curr){
                if(length<curr)
                    length = curr;
                curr=i-array[s[i]];
            }
            curr++;
            array[s[i]]=i+1;
        }
        if(length<curr) length = curr;
        return length;
    }
};