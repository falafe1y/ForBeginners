#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
    try {
        Queue q(4); // Queue with capacity 4

        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.enqueue(40);

        vector<int> qData1 = q.getQueue();
        for (int i = 0; i < q.getCapacity(); ++i) {
            cout << qData1[i] << ' ';
        }
        cout << '\n';

        std::cout << "First element: " << q.peek() << std::endl;

        std::cout << "Deleted: " << q.dequeue() << std::endl;

        vector<int> qData2 = q.getQueue();

        for (int i = 0; i < q.getCapacity(); ++i) {
            cout << qData2[i] << ' ';
        }
        cout << '\n';

        q.enqueue(50);
        q.enqueue(60);  // This elemetn will not add to queue 
                        // because it's full and capacity already = 4

        vector<int> qData3 = q.getQueue();

        for (int i = 0; i < q.getCapacity(); ++i) {
            cout << qData3[i] << ' ';
        }
        cout << '\n';

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}