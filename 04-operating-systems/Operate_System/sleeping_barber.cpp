// sleeping_barber.cpp
// 模拟“理发师睡眠问题”的简单 C++ 实现（C++11）
// 说明：
// - 使用自实现的 Semaphore（基于 mutex + condition_variable）
// - barber 线程在没有顾客时等待；顾客到达时唤醒 barber 或坐等候椅
// - 若无空闲候位椅，顾客离开
// 这是教学示例，便于理解同步逻辑和信号量用法

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <random>

class Semaphore {
public:
    Semaphore(int count_ = 0) : count(count_) {}
    void notify() {
        std::unique_lock<std::mutex> lock(mtx);
        ++count;
        cv.notify_one();
    }
    void wait() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&](){ return count > 0; });
        --count;
    }
private:
    std::mutex mtx;
    std::condition_variable cv;
    int count;
};

// 全局同步变量
int chairs = 3;              // 等候椅数量（可调）
int waiting = 0;             // 当前等待的顾客数
std::mutex seatMutex;        // 保护 waiting 和座位相关变量
Semaphore customers(0);      // 顾客到达的计数信号量
Semaphore barberReady(0);    // 理发师就绪信号量，顾客等待理发师唤醒

void barber() {
    while (true) {
        // 等待有顾客
        customers.wait();

        // 有顾客，准备服务一个
        {
            std::lock_guard<std::mutex> lock(seatMutex);
            if (waiting > 0) --waiting; // 顾客走出等待区，去理发椅
        }

        // 通知某个顾客理发师准备好了
        barberReady.notify();

        // 理发（模拟耗时）
        std::cout << "理发师：正在理发...\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(800 + rand() % 800));
        std::cout << "理发师：理发完成。\n";
    }
}

void customer(int id) {
    // 到达理发店
    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000));
    std::cout << "顾客 " << id << " 到达。\n";

    {
        std::lock_guard<std::mutex> lock(seatMutex);
        if (waiting < chairs) {
            // 有空座位，坐下等待
            ++waiting;
            std::cout << "顾客 " << id << " 坐下等待（当前等待=" << waiting << ")。\n";

            // 通知理发师有顾客
            customers.notify();
        } else {
            // 没有座位，离开
            std::cout << "顾客 " << id << " 无空位，离开。\n";
            return;
        }
    }

    // 等待理发师就绪
    barberReady.wait();

    // 被理发
    std::cout << "顾客 " << id << " 正在理发。\n";
    // 理发实际在理发师线程模拟，这里仅表示顾客体验
}

int main() {
    srand((unsigned)time(nullptr));

    // 启动理发师线程（示例中设为分离线程）
    std::thread barberThread(barber);
    barberThread.detach();

    // 模拟一批顾客到来
    const int totalCustomers = 12;
    std::thread customersThreads[totalCustomers];
    for (int i = 0; i < totalCustomers; ++i) {
        customersThreads[i] = std::thread(customer, i + 1);
        // 随机到达间隔
        std::this_thread::sleep_for(std::chrono::milliseconds(200 + rand() % 400));
    }

    // 等待所有顾客线程结束（理发师线程为分离，程序结束时会一并退出）
    for (int i = 0; i < totalCustomers; ++i) {
        if (customersThreads[i].joinable()) customersThreads[i].join();
    }

    std::cout << "所有顾客已到达并处理完毕（或离开）。程序结束。\n";
    return 0;
}
