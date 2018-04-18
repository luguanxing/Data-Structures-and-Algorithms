package 生产消费者;

public class synchronized方式 {

	public static Integer product = 0;

	// 锁对象，注意不能把product当成锁，否则修改导致不稳定，因用不变的对象做锁
	public static Object lock = new Object();

	public class Producer extends Thread {
		@Override
		public void run() {
			while (true) {
				synchronized (lock) {
					product++;
					System.out.println("+++" + currentThread() + "已生产" + product);
				}
				try {
					sleep(10);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}
	}

	public class Customer extends Thread {
		@Override
		public void run() {
			while (true) {
				synchronized (lock) {
					if (product > 0) {
						product--;
						System.out.println("---" + currentThread() + "已消费" + product);
					}
				}
			}
		}
	}

	public static void main(String[] args) {
		for (int i = 1; i <= 3; i++)
			new Thread(new synchronized方式().new Producer(), "生产者" + i + "号").start();
		for (int i = 1; i <= 10; i++)
			new Thread(new synchronized方式().new Customer(), "消费者" + i + "号").start();
	}

}
