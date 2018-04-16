package 生产消费者;

public class synchronized方式 {

	public static Integer product = 0;
	
	public class Producer extends Thread {
		@Override
		public void run() {
			while (true) {
				synchronized (product) {
					product++;
					System.out.println("+++" + currentThread() + "已生产");
					try {
						sleep(1000);
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
			}
		}
	}
	
	public class Customer extends Thread {
		@Override
		public void run() {
			while (true) {
				synchronized (product) {
					if (product > 0) {
						product--;
						System.out.println("---" + currentThread() + "已消费");
					}
				}
			}
		}
	}
	
	public static void main(String[] args) {
		new Thread(new synchronized方式().new Producer(), "生产者1号").start();
		new Thread(new synchronized方式().new Customer(), "消费者1号").start();
		new Thread(new synchronized方式().new Customer(), "消费者2号").start();
		new Thread(new synchronized方式().new Customer(), "消费者3号").start();
	}

}
