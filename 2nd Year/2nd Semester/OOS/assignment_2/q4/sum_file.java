import java.io.*;

class File {
    BufferedReader br = null;
    String str;
    int buf;
    int curr = 0;
    long sum = 0;
    boolean reading = true;

    File(String path) throws Exception {
        br = new BufferedReader(new FileReader(path));
        str = br.readLine();
    }

    public synchronized void read() {
        if (str != null && curr < str.length()) {
            String temp = "";
            while (curr < str.length() && str.charAt(curr) != ' ') {
                temp += str.charAt(curr++);
            }
            curr++;
            if (!temp.isEmpty()) {
                buf = Integer.parseInt(temp);
                reading = false;
            }
        }
    }

    public synchronized void add() {
        sum += buf;
        reading = true;
    }
}

class t1 implements Runnable {
    File f;

    t1(File f) {
        this.f = f;
    }

    public void run() {
        synchronized (f) {
            while (f.curr < f.str.length()) {
                try {
                    while (!f.reading) {
                        f.wait();
                    }
                    f.read();
                    f.notify();
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }
}

class t2 implements Runnable {
    File f;

    t2(File f) {
        this.f = f;
    }

    public void run() {
        synchronized (f) {
            while (f.curr < f.str.length()) {
                try {
                    while (f.reading) {
                        f.wait();
                    }
                    f.add();
                    f.notify();
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }
}

class Main {
    public static void main(String args[]) throws Exception {
        File f = new File("a.txt");
        Thread producer = new Thread(new t1(f));
        Thread consumer = new Thread(new t2(f));
        producer.start();
        consumer.start();
        producer.join();
        consumer.join();
        System.out.println("Sum is " + f.sum);
    }
}

