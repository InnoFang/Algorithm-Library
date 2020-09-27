/**
 * Greedy ̰���㷨
 * ��Ӧ��ɾȥ���ٸ����䣬ת��Ϊ���Ĳ��ص������Ǽ���
 * ����Ҫ��Ӧ��ɾȥ���ٸ����䣬�Ϳ����� ������� - ������������� �õ�
 *  
 * Status: Accepted
 * 18 / 18 test cases passed.
 * Runtime: 32 ms
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if ( intervals.size() == 0 ) return 0;

        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        int pass = 1, pre = intervals[0][1];
        for ( int i = 1; i < intervals.size(); ++ i ) {
            if ( intervals[i][0] >= pre ) {
                ++ pass;
                pre = intervals[i][1];
            }
        }
        return intervals.size() - pass;
    }
};

