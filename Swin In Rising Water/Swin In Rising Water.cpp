#include<limits.h>
#include<algorithm>

class Solution {
private:
    vector<vector<int>> weight;
    int size;
    vector<int> heights;
    void constructWeight(int lin, int col, vector<vector<int>>& grid){
        weight = vector<vector<int>>(lin, vector<int>(col, INT_MAX));
        heights.reserve(lin*col);
        for(int i = 0; i< lin; i++){
            for (int j = 0; j< col; j++){
                heights.push_back(grid[i][j]);
            }
        }
        sort(heights.begin(), heights.end());
    }
    void updateWeight(int i, int j, int weight1, int height1, int height2){
        int value(weight1);
        if(height2>weight1){
            value=height2;
        }
        if(weight[i][j]>value)
            weight[i][j] = value;
    }
    int iterate(int lin, int col, vector<vector<int>>& grid){
        int size = lin*col;
        int time = grid[0][0];
        weight[0][0] = grid[0][0];
        int t = lower_bound(heights.begin(), heights.end(), time)-heights.begin();
        while(weight[lin-1][col-1]==INT_MAX){
            //cout<<"Ola";
            time = heights[t];
            while(t+1 < heights.size() && heights[t+1] <= time) t++;
            t++;
            //cout<<"Ola2";
            stack<pair<int,int>> st;
            for(int i = 0; i<lin; i++){
                for(int j = 0; j < col; j++){
                    if(weight[i][j]!=INT_MAX){
                            if(j>0 && weight[i][j-1]==INT_MAX && grid[i][j-1]<=time)
                                st.push(make_pair(i,j-1));
                            if(j<col-1 && weight[i][j+1]==INT_MAX && grid[i][j+1]<=time)
                                st.push(make_pair(i,j+1));
                            if(i>0 && weight[i-1][j]==INT_MAX && grid[i-1][j]<=time)
                                st.push(make_pair(i-1,j));
                            if(i<lin-1 && weight[i+1][j]==INT_MAX && grid[i+1][j]<=time)
                                st.push(make_pair(i+1,j));
                    }
                }
            }
            //cout<<"Ola3";
            while(!st.empty()){
                int i(st.top().first), j(st.top().second);
                st.pop();
                if(weight[i][j]!=INT_MAX)
                    continue;
                weight[i][j] = time;
                if(j>0 && weight[i][j-1]==INT_MAX && grid[i][j-1]<=time)
                    st.push(make_pair(i,j-1));
                if(j<col-1 && weight[i][j+1]==INT_MAX && grid[i][j+1]<=time)
                    st.push(make_pair(i,j+1));
                if(i>0 && weight[i-1][j]==INT_MAX && grid[i-1][j]<=time)
                    st.push(make_pair(i-1,j));
                if(i<lin-1 && weight[i+1][j]==INT_MAX && grid[i+1][j]<=time)
                    st.push(make_pair(i+1,j));
            }
            //cout<<"Ola4";
        }
        return weight[lin-1][col-1];
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        if(grid.size()==1 && grid[0].size()==1)
            return 0;
        constructWeight(grid.size(), grid[0].size(), grid);
        weight[0][0] = grid[0][0];
        return iterate(grid.size(), grid[0].size(), grid);
    }
};