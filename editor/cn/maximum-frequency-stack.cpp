/*
 * @lc app=leetcode.cn id=895 lang=cpp
 * @lcpr version=30202
 *
 * [895] 最大频率栈
 */

// @lc code=start
class FreqStack {
public:
    FreqStack() =default;
    
    void push(int val) {
        int freq=valToFreq.count(val)?valToFreq[val]+1:1;
        valToFreq[val]=freq;
        freqToVals[freq].push(val);
        maxFreq=max(maxFreq,freq);
    }
    
    int pop() {
        int v=freqToVals[maxFreq].top();
        freqToVals[maxFreq].pop();
        valToFreq[v]--;
        if (freqToVals[maxFreq].empty()) {
          maxFreq--;
        }
        return v;
    }
private:
    int maxFreq=0;
    unordered_map<int,int> valToFreq;
    unordered_map<int,stack<int>> freqToVals;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end



/*
// @lcpr case=start
// ["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],\n[[],[5],[7],[5],[7],[4],[5],[],[],[],[]]\n
// @lcpr case=end

 */

