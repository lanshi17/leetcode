/*
 * @lc app=leetcode.cn id=641 lang=cpp
 * @lcpr version=30202
 *
 * [641] 设计循环双端队列
 */

// @lc code=start
class MyCircularDeque {
public:
    MyCircularDeque(int k):data(k),head(0),tail(0),capacity(k),count(0){
        
    }
    
    bool insertFront(int value) {
        if (isFull()) {
          return false;
        }
        head=(head-1+capacity)%capacity;
        data[head]=value;
        count++;
        return true;

    }
    
    bool insertLast(int value) {
        if (isFull()) {
          return false;
        }
        data[tail]=value;
        tail=(tail+1)%capacity;
        count++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) {
          return false;
        }
        head=(head+1)%capacity;
        count--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) {
          return false;
        }
        tail=(tail-1+capacity)%capacity;
        count--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) {
          return -1;
        }
        return data[head];
    }
    
    int getRear() {
        if (isEmpty()) {
          return -1;
        }
        return data[(tail-1+capacity)%capacity];
    }
    
    bool isEmpty() {
        return count?false:true;
    }
    
    bool isFull() {
        return (count==capacity)?true:false;
    }
private:
    vector<int> data;
    int head;
    int tail;
    int capacity;
    int count;

};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end



