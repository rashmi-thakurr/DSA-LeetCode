class MedianFinder {
public:
    
    //We meed two pqs. minHeap would be required to store the second half of the data and maxGeap would store the first half of the data. Median would be the average of two elements at the top of the two heaps in case if the size of two heaps are equal else the median would be the top element of the heap with greater size with the size diff of the two heaps not more than 1.
    priority_queue<int> mxH; //maxheap
    priority_queue<int,vector<int>,greater<int>> mnH; //mnheap
    
    MedianFinder() {
      mxH.push(1);
        mxH.pop();
    }
    
    void addNum(int num) {
        if(mxH.top()>num || mxH.size()==0) mxH.push(num);
        else mnH.push(num);
        
        //Balancing the heaps;
        while(mxH.size() > mnH.size()+1){
            mnH.push(mxH.top());
            mxH.pop();
        }
        
        while(mnH.size() > mxH.size()+1){
            mxH.push(mnH.top());
            mnH.pop();
        }
    }
    
    double findMedian() {
        if(mnH.size()==mxH.size()){
            if(mxH.empty()) return 0;
            return (mnH.top() + mxH.top())/2.0;
        }
        else if(mnH.size() > mxH.size()){
            return mnH.top();
        }
        else return mxH.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */