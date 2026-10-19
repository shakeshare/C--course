// PV3.cpp
// 理发师睡眠问题 —— 用 P/V（信号量）操作表示的伪代码（中文注释）

/* 共享变量（初始值）
   chairs = N               // 等候椅总数（常量）
   waiting = 0              // 当前等待的顾客数

   // 信号量说明：P(s) 表示等待/占用，V(s) 表示释放/通知
   semaphore mutex = 1      // 二值信号量或互斥量
   semaphore customers = 0  // 顾客计数信号量（到达的顾客数）
   semaphore barberReady = 0// 理发师就绪信号量（用于唤醒特定顾客）
*/

// 理发师（P/V 形式伪代码）
/*
function Barber():
	loop forever:
		P(customers)         // 若无顾客则阻塞（理发师睡觉）

		P(mutex)
		waiting = waiting - 1 // 从候客区取出一名顾客去理发
		V(mutex)

		V(barberReady)       // 通知一个等待顾客：理发师已准备好

		CutHair()             // 理发（模拟耗时）
	end loop
*/

// 顾客（P/V 形式伪代码）
/*
function Customer(id):
	arrive at barber shop

	P(mutex)
	if waiting < chairs:            // 仍有空候位
		waiting = waiting + 1       // 占一个候位椅
		V(customers)                // 增加可服务顾客计数，若理发师睡着则唤醒
		V(mutex)

		P(barberReady)              // 等待理发师准备好（被选中去理发）
		GetHaircut()                // 接受理发
	else:
		V(mutex)
		leave shop                  // 无空位，离开
	end if
*/

// 要点说明（简要）
// - 使用 P(mutex)/V(mutex) 实现对共享变量 waiting 的互斥访问。
// - customers 用于表示等待/到达的顾客数；理发师对其执行 P(customers) 来等待顾客。
// - barberReady 用于在理发师准备好时唤醒一个具体顾客（避免唤醒混乱）。
// - 初始状态： waiting = 0, mutex = 1, customers = 0, barberReady = 0。

// 可选扩展：把上述伪代码直接实现为 C/C++（使用 std::mutex + std::condition_variable 或信号量）

