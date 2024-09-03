#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx; // Mutex to ensure proper synchronization

void countUp() {
    for (int i = 1; i <= 20; i++) {
        lock_guard<mutex> lock(mtx); // Lock the mutex
        cout << "Count Up: " << i << endl;
    }
}

void countDown() {
    for (int i = 20; i >= 0; i--) {
        lock_guard<mutex> lock(mtx); // Lock the mutex
        cout << "Count Down: " << i << endl;
    }
}

int main() {
    thread thread1(countUp);   // Start the first thread to count up
    thread1.join();            // Wait for thread1 to finish

    thread thread2(countDown); // Start the second thread to count down
    thread2.join();            // Wait for thread2 to finish

    cout << "Goodbye. ♥" << endl;
    return 0;
}
