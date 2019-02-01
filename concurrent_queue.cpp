template<typename T>
class ConcurrentQueue {
public:
   ConcurrentQueue(const ConcurrentQueue &) = delete;
   void operator=(const ConcurrentQueue &)  = delete;
   ConcurrentQueue(void) : _mutex(), _condition(), _q() {}
   ~ConcurrentQueue() { _q.clear(); }

   void enqueue(T x) {
       std::list <T> tmp;
       tmp.emplace_back(x);
       {
           std::lock_guard <std::mutex> lock(_mutex);
           _q.splice(std::end(_q), tmp);
       }
       _condition.notify_all();
   }

   T dequeue() {
       T t = nullptr;
       std::unique_lock <std::mutex> qLock(_mutex);
       if (!_q.empty()) {
           _condition.wait(qLock, [&]() { return (!_q.empty()); });
           t = std::move(_q.front());
           _q.pop_front();
       }
       return t;
   }

   size_t size() {
       std::unique_lock <std::mutex> qLock(_mutex);
       return _q.size();
   }

private:
   std::mutex _mutex;
   std::list <T> _q;
   std::condition_variable _condition;
};


int main() {
   ConcurrentQueue<int> q;
   return 1;
}
