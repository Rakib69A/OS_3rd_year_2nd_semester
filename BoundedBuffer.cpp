#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

const int BUFFER_SIZE = 5;

class BoundedBuffer {
public:
    BoundedBuffer() : buffer(BUFFER_SIZE), in(0), out(0), count(0) {}

    void produce(int item) {
        unique_lock<mutex> lock(mutex_);
        while (count == BUFFER_SIZE) {
            not_full.wait(lock);
        }

        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        count++;

        cout << "Produced: " << item << ", Count: " << count << endl;

        not_empty.notify_all();
    }

    int consume() {
        unique_lock<mutex> lock(mutex_);
        while (count == 0) {
            not_empty.wait(lock);
        }

        int item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        count--;

        cout << "Consumed: " << item << ", Count: " << count << endl;

        not_full.notify_all();
        return item;
    }

private:
    vector<int> buffer;
    int in, out, count;
    mutex mutex_;
    condition_variable not_full, not_empty;
};

BoundedBuffer buffer;

void producer() {
    for (int i = 0; i < 10; i++) {
        buffer.produce(i);
        this_thread::sleep_for(chrono::milliseconds(100)); // Simulate production time
    }
}

void consumer() {
    for (int i = 0; i < 10; i++) {
        int item = buffer.consume();
        this_thread::sleep_for(chrono::milliseconds(150)); // Simulate consumption time
    }
}

int main() {
    thread producer_thread(producer);
    thread consumer_thread(consumer);

    producer_thread.join();
    consumer_thread.join();

    return 0;
}
