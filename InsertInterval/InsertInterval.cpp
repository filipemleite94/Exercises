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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int size(intervals.size());
        vector<Interval> v;
        if(!size){
            v.push_back(newInterval);
            return v;
        }
        v.reserve(intervals.size());
        auto comp = [&](const Interval &i1, const Interval &i2){return i1.start<i2.start;};
        auto it = lower_bound(intervals.begin(), intervals.end(), newInterval, comp);
        if(it != intervals.begin()){
            it--;
            v.insert(v.end(), intervals.begin(), it);
            Interval &interval = *it;
            if(interval.end<newInterval.start){
                v.push_back(interval);
            }
            else{
                newInterval.start = interval.start;
                if(newInterval.end<interval.end)
                    newInterval.end = interval.end;
            }
            it++;
            //cout<<it->start;
        }
        while(it!=intervals.end() && newInterval.end>=(*it).start){
            if(newInterval.end<(*it).end)
                newInterval.end = (*it).end;
            it++;
        }
        v.push_back(newInterval);
        v.insert(v.end(), it, intervals.end());
        return v;
    }
};