/*
 * @lc app=leetcode.cn id=622 lang=cpp
 * @lcpr version=30202
 *
 * [622] 设计循环队列
 */

// @lc code=start
class MyCircularQueue {
public:
    MyCircularQueue(int k):data(k),head(0),tail(-1),capacity(k),count(0) {
        
    }
    
    bool enQueue(int value) {
        if (isFull()) {
          return false;
        }
        tail=(tail+1)%capacity;
        data[tail]=value;
        count++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
          return false;
        }    
        head=(head+1)%capacity;
        count--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
          return -1;
        }    
        return data[head];
    }
    
    int Rear() {
        if (isEmpty()) {
          return -1;
        }
        return data[tail];
    }
    
    bool isEmpty() {
        if (!count) {
          return true;
        }
        return false;
    }
    
    bool isFull() {
        if (count==capacity) {
          return true;
        }
        return false;
    }

private:
    vector<int> data;
    int head;
    int tail;
    int capacity;
    int count;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end



