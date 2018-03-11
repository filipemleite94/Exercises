class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char, int> map;
        for(int i = 0; i<S.length(); i++){
            map[S[i]] = i;
        }
        for(int i = 0; i<T.length(); i++){
            auto it = map.find(T[i]);
            if(it==map.end()){
                map[T[i]] = -1;
            }
        }
        auto l = [&](char c1, char c2){return map[c1]<map[c2];};
        sort(T.begin(), T.end(), l);
        return T;
    }
};