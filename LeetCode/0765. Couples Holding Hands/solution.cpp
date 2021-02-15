/**
 * 56 / 56 test cases passed.
 * Status: Accepted
 * Runtime: 4 ms
 */
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> cache(n);
        for (int i = 0; i < n; ++ i) {
            cache[row[i]] = i;
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i += 2) {
            int couple = row[i] ^ 1;
            if (row[i + 1] != couple) {
                int coupleIdx = cache[couple];
                cache[row[i + 1]] = coupleIdx;
                cache[row[coupleIdx]] = i + 1;
                swap(row[coupleIdx], row[i + 1]);
                ans++;
            }
        }
        return ans;
    }
};

/**
 * 56 / 56 test cases passed.
 * Status: Accepted
 * Runtime: 0 ms
 */
// refer2: https://leetcode-cn.com/problems/couples-holding-hands/solution/cbing-cha-ji-best-100wo-hen-a-by-feng-zi-iw0m/
class Solution {
public:
    int find(int x) {
        return x == p[x] ? p[x] : p[x] = find(p[x]);
    }
    void merge(int a, int b) {
        p[find(a)] = p[find(b)];
    }
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int m = n / 2;
        p.resize(m);
        for (int i = 0; i < m; ++ i) p[i] = i;
        for (int i = 0; i < n; i += 2) {
            merge(row[i] / 2, row[i + 1] / 2);
        }
        int cnt = 0;
        for (int i = 0; i < m; ++ i) {
            if (find(i) == i) {
                cnt ++;
            }
        }
        // �������� - ���鼯����
        return m - cnt;
    }
private:
    vector<int> p;
};

/**
���ڽⷨ2��Solution2���й��ڴ𰸣������ܶ��� - ���鼯�����Ľ��� 

���鼯�ĸ�������ʾ�ж������±��ֳ���һ�ѣ�ע����һ�ѣ����Ǽ򵥵�һ��
��� A1 �� A2 ��һ�����£���ô���鼯 union ������ʱ���϶��ǵ����ֵ�һ�ѵģ������˲�����֮����
�෴��A1 �� B1 �϶�����һ�����£���ô union ʱ��� A1��B1��A2��B2 �ֳ�һ��

��ˣ������������·������������ܶ�����Ϊ m�� 
 1. ����������µ���λ��ȷ����ô m �����£����鼯�ĸ���Ҳ���� m ��������������Ϊ 0������Ҫ����
 2. ����� 2 ��������λ����ȷ����ô m �����£����鼯�����ͻ��� m - 1 �� ����ʾ�� 2 �����»�������һ�ѣ��������Ϊ 1������һ�ν���
 3. ����� 3 �Բ���ȷ�����鼯������Ϊ m - 2 ���� ��ʾ�� 3 �����»�����һ�ѣ��������Ϊ 2���������ν���
 4. ��� 4 �����»������� 2 �ѣ���ôÿ���ڲ����� 2 �����±���������ÿ������һ�ν��������� 4 �����±��������� 2 �Ѿ���Ҫ���� 2 �Ρ� 
    �� 4 �����»������� 2 ���ڲ��鼯�����ֳ������� m - 2 ���� ��ʾ������û�ֶԳɹ���������������һ��Ҳ�͵õ��˽�������Ϊ 2�� 
 
�Դ����ƣ�˵���ж��ٶ����»����ˣ���ô�����ܶ��� - ���鼯�����õ��Ľ�����ǣ��������¶��� - 1����ʾ��Ҫ�����Ĵ��� 
*/


