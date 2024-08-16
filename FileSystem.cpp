#include <iostream>
#include <fstream>
#include "DiskDrive.cpp"

using namespace std;

class FileSystem {
private:
    DiskDrive disk;

public:
    // Here we implement methods to handle file operations and allocation methods
    void displayFile(int fileIndex) {
        // Displays file content using disk.readBlock
    }

    void displayFileTable() {
        // Displays the file allocation table
    }

    void displayFreeSpaceBitmap() {
        // Displays the free space bitmap
    }

    void displayDiskBlock(int blockNumber) {
        // Displays the content of a disk block using disk.readBlock
    }

    void copyFileToSimulation(const string& realFilePath, const string& simulationFileName) {
        // Implement copying a file from the real system to the simulation using disk.writeBlock
        ifstream realFile(realFilePath, ios::binary);
        if (realFile.is_open()) {
            char buffer[512];
            int blockNumber = 2; // Start storing file content from the third block
            while (realFile.read(buffer, sizeof(buffer))) {
                disk.writeBlock(blockNumber++, buffer);
            }
            realFile.close();
            cout << "File has been copied to simulation.\n";
        } else {
            cerr << "Unable to open real file. Please try again.\n";
        }
    }

    void copyFileToRealSystem(const string& simulationFileName, const string& realFilePath) {
        // Implement copying a file from the simulation to the real system using "disk.readBlock"
        ofstream realFile(realFilePath, ios::binary);
        if (realFile.is_open()) {
            char buffer[512];
            int blockNumber = 2; // Must start reading file content from the third block
            do {
                disk.readBlock(blockNumber++, buffer);
                realFile.write(buffer, sizeof(buffer));
            } while (realFile);
            realFile.close();
            cout << "File has been copied to real system.\n";
        } else {
            cerr << "Unable to create real file. Please try again.\n";
        }
    }

    void deleteFile(int fileIndex) {
        // Implement deleting a file by marking corresponding blocks as free in the free space bitmap
    }
};