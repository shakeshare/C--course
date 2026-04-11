
/*
  PV 同步示例 — 单货位（只能放一台冰箱或一辆汽车）

  问题描述简化：
  - 船 A 卸汽车（Producer A）
  - 船 B 卸冰箱（Producer B）
  - 厂家甲等待提汽车（Consumer Car）
  - 厂家乙等待提冰箱（Consumer Fridge）
  - 货位为单一槽位，空时可放入一件货物

  采用 Dijkstra 风格的 P/V（即 wait/signal）信号量：

  信号量定义：
	semaphore empty = 1;    // 表示货位空闲（初值 1）
	semaphore car   = 0;    // 表示货位上有汽车可取（初值 0）
	semaphore fr    = 0;    // 表示货位上有冰箱可取（初值 0）

  进程/线程伪代码：

  // 船 A：卸汽车
  process ShipA() {
	  while (true) {
		  P(empty);             // 等待货位空
		  // 将汽车放到货位（原子操作）
		  // store = CAR;
		  V(car);               // 通知有汽车
		  // 继续下一批或结束
	  }
  }

  // 船 B：卸冰箱
  process ShipB() {
	  while (true) {
		  P(empty);             // 等待货位空
		  // 将冰箱放到货位（原子操作）
		  // store = FRIDGE;
		  V(fr);                // 通知有冰箱
	  }
  }

  // 厂家甲：取汽车
  process FactoryA() {   // 等待并取汽车
	  while (true) {
		  P(car);              // 等待汽车到达
		  // 从货位取走汽车（原子操作）
		  // store = EMPTY;
		  V(empty);            // 释放货位为空
		  // 处理汽车或离开
	  }
  }

  // 厂家乙：取冰箱
  process FactoryB() {   // 等待并取冰箱
	  while (true) {
		  P(fr);               // 等待冰箱到达
		  // 从货位取走冰箱（原子操作）
		  // store = EMPTY;
		  V(empty);            // 释放货位为空
	  }
  }

  说明：
  - 使用一个共享的 `empty` 信号量保证同一时间只有一个货物占用货位。
  - `car` 和 `fr` 分别用于区分货物类型，消费者仅对自己关心的类型 P()。
  - 由于生产者在放置货物后会对相应类型做 V()，相应的厂家会被唤醒并取走。
  - 该方案避免了错误提取（厂家只会在其对应的类型信号量上阻塞/唤醒）。

  这是标准的 P/V 同步解法，适用于题目中情况（1）。

*/

