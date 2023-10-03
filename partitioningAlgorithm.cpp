#include <iostream>
#include <vector>

using namespace std;

// Define the size of memory and the size of each partition
const int MEMORY_SIZE = 1024; // Total memory size
const int PARTITION_SIZE = 256; // Size of each partition

// Define a structure to represent a partition
struct Partition {
    int id;
    int size;
    bool allocated;
};

// Function to initialize memory with partitions
vector<Partition> initializeMemory() {
    int numPartitions = MEMORY_SIZE / PARTITION_SIZE;
    vector<Partition> memory(numPartitions);

    for (int i = 0; i < numPartitions; i++) {
        memory[i].id = i + 1;
        memory[i].size = PARTITION_SIZE;
        memory[i].allocated = false;
    }

    return memory;
}

// Function to allocate a process to a partition
void allocateProcess(vector<Partition>& memory, int processId, int processSize) {
    for (Partition& partition : memory) {
        if (!partition.allocated && partition.size >= processSize) {
            partition.allocated = true;
            cout << "Process " << processId << " allocated to Partition " << partition.id << endl;
            return;
        }
    }

    cout << "Process " << processId << " cannot be allocated. No suitable partition found." << endl;
}

int main() {
    vector<Partition> memory = initializeMemory();

    // Allocate processes to partitions
    allocateProcess(memory, 1, 200);
    allocateProcess(memory, 2, 400);
    allocateProcess(memory, 3, 300);
    allocateProcess(memory, 4, 150);
    allocateProcess(memory, 5, 500);

    return 0;
}

