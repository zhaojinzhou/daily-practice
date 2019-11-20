package jedis;

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;

class producer implements Runnable {
	BlockingQueue<Integer> bq;

	public producer(BlockingQueue<Integer> bq) {
		super();
		this.bq = bq;
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		while (true) {
			bq.offer(Integer.valueOf(1));
			try {
				Thread.sleep(100);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			System.out.println("size == " + bq.size() + "      " + Thread.currentThread().getId() + "     put one int");
		}
	}

}

class consumer implements Runnable {
	BlockingQueue<Integer> bq;

	public consumer(BlockingQueue<Integer> bq) {
		super();
		this.bq = bq;
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		while (true) {
			bq.poll();
			try {
				Thread.sleep(100);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			System.out
					.println("size == " + bq.size() + "      " + Thread.currentThread().getId() + "     take one int");
		}

	}

}

public class test {
	public static void main(String[] args) {
		BlockingQueue<Integer> bq = new LinkedBlockingQueue<Integer>(10);
		for (int i = 0; i < 5; i++) {
			new Thread(new producer(bq)).start();
			new Thread(new consumer(bq)).start();
		}
	}
}
