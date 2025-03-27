class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // If the input list is empty, return an empty list. 
        if (intervals.empty()) {
            return {};
        }

        // Utilizing a sort function, sort the intervals by the starting value of each interval. 
        sort(intervals.begin(), intervals.end());

        // Resulting vector holding the merged merged intervals. 
        vector<vector<int>> merged;

        // Add the first interval to the result. 
        merged.push_back(intervals[0]);

        // Using a for loop, iterate through the remaining intervals. 
        for (int i = 1; i < intervals.size(); ++i) {
            vector<int>& last = merged.back();
            vector<int>& current = intervals[i];

            // If the current interval overlaps with the previous merged interval, merge them. 
            if (current[0] <= last[1]) {
                last[1] = max(last[1], current[1]);
            } else {
                merged.push_back(current);
            }
        }

        return merged;
    }
};