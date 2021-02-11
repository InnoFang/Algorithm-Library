#include <queue>
/**
 * 10 / 10 test cases passed.
 * Status: Accepted
 * Runtime: 44 ms
 */
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        for (int i = 0; i < k - 1; ++ i) {
            minHeap.push(nums[i]); 
        } 
        for (int i = k - 1; i < nums.size(); ++ i) {
            maxHeap.push(nums[i]); 
        } 
    }
    
    int add(int val) {
        /*
            ������/���ȶ���
            һ����k - 1������С���ѣ�һ���Ǵ󶥶�
            ÿ������Ƚ��󶥶ѣ�Ȼ��Ӵ󶥶���ȡһ�������ŵ�С���ѣ��ٴ�С����ȡһ�����ŵ��󶥶�
            ��k������Ǵ󶥶ѵ�top
        */ 
        maxHeap.push(val);
        minHeap.push(this->maxHeap.top());  maxHeap.pop();
        maxHeap.push(this->minHeap.top());  minHeap.pop();
        return maxHeap.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, less<int>> maxHeap;
};


/**
 * 10 / 10 test cases passed.
 * Status: Accepted
 * Runtime: 40 ms
 */
class KthLargest2 {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (auto& num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;
};


/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
