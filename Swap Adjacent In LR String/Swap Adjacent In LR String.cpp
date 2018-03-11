#include <algorithm>
#include <utility>

class Solution {
public:
    bool canTransform(string start, string end) {
        if(start.length()!=end.length())
            return false;
        int length(start.length());
        if(length==0)
            return true;
        int j = 0;
        int i = 0;
        while(i<length){
            while(i<length && start[i]!='L') i++;
            while(j<length && end[j]!= 'L' ) j++;
            if(i==length||j==length) break;
            while(i>j){
                if(start[i-1]!='X')
                    break;
                swap(start[i], start[i-1]);
                i--;
            }
            if(i!=j)
                return false;
            i++;
            j++;
        }
        if(i!=length||j!=length) return false;
        i--;
        j--;
        while(i>-1){
            while(i>-1 && start[i]!='R') i--;
            while(j>-1 && end[j]!='R') j--;
            if(i==-1||j==-1) break;
            while(i<j){
                if(start[i+1]!='X')
                    break;
                swap(start[i], start[i+1]);
                i++;
            }
            if(i!=j)
                return false;
            i--;
            j--;
        }
        if(i!=-1||j!=-1) return false;
        return true;
    }
};