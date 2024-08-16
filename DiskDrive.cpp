#include <iostream>
#include <cstring>

using namespace std;

class DiskDrive {
private:
    char data[256][512]; // Using an array to simulate disk blocks

public:
    // Implement methods to read and write blocks
    void readBlock(int blockNumber, char* buffer) {
        // Check for a valid blockNumber, then copy data from the disk to the buffer
        if (blockNumber >= 0 && blockNumber < 256) {
            memcpy(buffer, data[blockNumber], 512);
        } else {
            cerr << "Invalid block number! Please try again.\n";
        }
    }

    void writeBlock(int blockNumber, const char* data) {
        // Check for valid blockNumber, then copy data to the disk
        if (blockNumber >= 0 && blockNumber < 256) {
            memcpy(this->data[blockNumber], data, 512);
        } else {
            cerr << "Invalid block number! Please try again.\n";
        }
    }
};