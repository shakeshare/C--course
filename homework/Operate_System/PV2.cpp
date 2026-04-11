semaphore num=1, a=0,b=0,c=0;

int n=0;

process produce_num

{

      while(true)

{
         P(num);

         n=Producenum();

         if(n==0);

{

      V(c);

}

   else if(n%2==0)
{

     V(b);

}

  else 

{

    V(a);
}

​}

process A

{

      while(true)

{

      P(A);

     // take down

     V(num);
// 可运行的 C++ 示例：使用自定义信号量（基于 mutex + condition_variable）
// 模拟：生产者产生若干整数，0 -> 交给 C，偶数(非0) -> B，奇数 -> A

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <atomic>
#include <random>

class Semaphore {
public:
      explicit Semaphore(int count = 0) : count_(count) {}
      void P() {
            std::unique_lock<std::mutex> lk(m_);
            cv_.wait(lk, [&]{ return count_ > 0; });
            --count_;
      }
      void V() {
            std::lock_guard<std::mutex> lk(m_);
            ++count_;
            cv_.notify_one();
      }
private:
      std::mutex m_;
      std::condition_variable cv_;
      int count_;
};

// 全局信号量与共享槽位
Semaphore num(1), a(0), b(0), c(0);
int store = -1; // 货位（单槽）

void produceNumberLoop(int total, int delay_ms = 100) {
      std::mt19937 rng((unsigned)std::chrono::steady_clock::now().time_since_epoch().count());
      std::uniform_int_distribution<int> dist(0, 9);
      for (int i = 0; i < total; ++i) {
            std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
            num.P(); // 等待货位空
            int n = dist(rng);
            store = n; // 原子地放入货位（由 num 信号量保护）
            std::cout << "Producer 放入: " << n << std::endl;
            if (n == 0) {
                  c.V();
            } else if (n % 2 == 0) {
                  b.V();
            } else {
                  a.V();
            }
      }
      // 为了示例简单，等待一小段时间让消费者处理剩余项，然后退出程序
      std::this_thread::sleep_for(std::chrono::seconds(1));
      std::cout << "Producer 完成，程序结束。" << std::endl;
      std::exit(0);
}

void consumerA() {
      while (true) {
            a.P();
            int v = store;
            std::cout << "Consumer A 取走: " << v << std::endl;
            store = -1;
            num.V();
      }
}

void consumerB() {
      while (true) {
            b.P();
            int v = store;
            std::cout << "Consumer B 取走: " << v << std::endl;
            store = -1;
            num.V();
      }
}

void consumerC() {
      while (true) {
            c.P();
            int v = store;
            std::cout << "Consumer C 取走: " << v << std::endl;
            store = -1;
            num.V();
      }
}

int main() {
      const int totalItems = 20; // 示例总数
      std::thread prod(produceNumberLoop, totalItems, 100);
      std::thread tA(consumerA);
      std::thread tB(consumerB);
      std::thread tC(consumerC);
      prod.join();
      // 程序通过 prod 最后调用 exit(0) 提前结束，这里不会执行到
      tA.join(); tB.join(); tC.join();
      return 0;
}



}