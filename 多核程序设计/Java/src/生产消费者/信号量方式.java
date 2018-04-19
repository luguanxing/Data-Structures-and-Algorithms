package 生产消费者;

import java.util.concurrent.Semaphore;

public class 信号量方式 {

	public static Integer product = 0;

	// 使用信号量0-1做成互斥量
	public static Semaphore semaphore = new Semaphore(1);

	public class Producer extends Thread {
		@Override
		public void run() {
			while (true) {
				try {
					semaphore.acquire();
					// 临界区开始：进行生产
					product++;
					System.out.println("+++" + currentThread() + "已生产" + product);
					// 临界区结束：结束生产
					semaphore.release();
					sleep(100);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		}
	}

	public class Customer extends Thread {
		@Override
		public void run() {
			while (true) {
				try {
					semaphore.acquire();
					// 临界区开始：进行消费
					if (product > 0) {
						product--;
						System.out.println("---" + currentThread() + "已消费" + product);
					}
					// 临界区结束：结束消费
					semaphore.release();
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		}
	}

	public static void main(String[] args) {
		for (int i = 1; i <= 3; i++)
			new Thread(new 信号量方式().new Producer(), "生产者" + i + "号").start();
		for (int i = 1; i <= 10; i++)
			new Thread(new 信号量方式().new Customer(), "消费者" + i + "号").start();
	}

}
