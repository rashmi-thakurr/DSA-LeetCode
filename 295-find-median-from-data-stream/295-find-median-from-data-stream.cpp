class MedianFinder {
public:
    
    //We meed two pqs. minHeap would be required to store the second half of the data and maxGeap would store the first half of the data. Median would be the average of two elements at the top of the two heaps in case if the size of two heaps are equal else the median would be the top element of the heap with greater size with the size diff of the two heaps not more than 1.
    priority_queue<int> mnH; //maxheap
    priority_queue<int,vector<int>,greater<int>> mxH; //mnheap
    
    MedianFinder() {
      mnH.push(1);
        mnH.pop();
    }
    
    void addNum(int num) {
        if(mnH.top()>num || mnH.size()==0) mnH.push(num);
        else mxH.push(num);
        
        //Balancing the heaps;
        while(mnH.size() > mxH.size()+1){
            mxH.push(mnH.top());
            mnH.pop();
        }
        
        while(mxH.size() > mnH.size()+1){
            mnH.push(mxH.top());
            mxH.pop();
        }
    }
    
    double findMedian() {
        if(mnH.size()==mxH.size()){
            if(mnH.empty()) return 0;
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