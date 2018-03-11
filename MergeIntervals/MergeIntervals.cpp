/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        auto comp = [&](Interval i1, Interval i2){return i1.start<i2.start;};
        sort(intervals.begin(), intervals.end(), comp);
        int size(intervals.size()-1);
        vector<Interval> vec;
        if(size<0)
            return vec;
        for(int i = 0; i<size; i++){
            int &end = intervals[i].end;
            if(end>= intervals[i+1].start){
                intervals[i+1].start = intervals[i].start;
                if(end>intervals[i+1].end)
                    intervals[i+1].end = end;
            }else{
                vec.push_back(intervals[i]);
            }
        }
        vec.push_back(intervals[size]);
        return vec;
    }
};