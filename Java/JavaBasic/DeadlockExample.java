package JavaBasic;
public class DeadlockExample {

    // 创建两个共享资源
    private static final Object resource1 = new Object();
    private static final Object resource2 = new Object();

    public static void main(String[] args) {

        // 线程 A：先锁 resource1，再锁 resource2
        Thread threadA = new Thread(() -> {
            synchronized (resource1) {
                System.out.println("线程A 获得了 resource1 锁");

                try { Thread.sleep(100); } catch (InterruptedException e) {}

                synchronized (resource2) {
                    System.out.println("线程A 获得了 resource2 锁");
                }
            }
        });

        // 线程 B：先锁 resource2，再锁 resource1
        Thread threadB = new Thread(() -> {
            synchronized (resource2) {
                System.out.println("线程B 获得了 resource2 锁");

                try { Thread.sleep(100); } catch (InterruptedException e) {}

                synchronized (resource1) {
                    System.out.println("线程B 获得了 resource1 锁");
                }
            }
        });

        threadA.start();
        threadB.start();

        // 启动一个守护线程，30秒后强制退出
        new Thread(() -> {
            try {
                Thread.sleep(1000);
                System.out.println("检测到死锁，程序自动退出");
                System.exit(0);
            } catch (InterruptedException e) {
                // 忽略
            }
        }).start();
    }
}
