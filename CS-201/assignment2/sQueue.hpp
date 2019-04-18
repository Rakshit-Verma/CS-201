template <typename E>
  class sQueue {					      // an interface for a queue
  public:
    int size() const;				      // number of items in queue
    bool empty() const;	
    const E& min();			      // is the queue empty?
    const E& front();	      // the front element
    void enqueue (const E& e);			      // enqueue element at rear
    void dequeue();		      // dequeue element at front
  };