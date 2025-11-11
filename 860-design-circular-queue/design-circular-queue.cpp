class MyCircularQueue {
public:
    vector<int>q;
    int rear,front,currsize,cap;
    MyCircularQueue(int k) {
        //initialize the variables declared outside
        q.resize(k);
        rear=-1;
        front=0;
        currsize=0;
        cap=k;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        rear=(rear+1)%cap;
        q[rear]=value;
        currsize++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        front=(front+1)%cap;
        currsize--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return q[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return q[rear];
    }
    
    bool isEmpty() {
        return currsize==0;
    }
    
    bool isFull() {
        return currsize==cap;
    }
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