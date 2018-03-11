class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        auto val = [&](vector<int> v){return abs(v[0])+abs(v[1]);};
        auto sub = [&](vector<int> v1, vector<int> v2){vector<int> v(2, 0); v[0] = v1[0]-v2[0]; v[1] = v1[1]-v2[1]; return v;};
        int dist(val(sub(vector<int>(2,0), target)));
        for(int i =0; i<ghosts.size(); i++){
            int distGhost(val(sub(ghosts[i], target)));
            if(distGhost<=dist)
                return false;
        }
        return true;
    }
};