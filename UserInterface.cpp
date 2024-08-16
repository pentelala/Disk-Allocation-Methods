#include <iostream>
#include "FileSystem.cpp"

using namespace std;

class UserInterface {
private:
    FileSystem fileSystem;

public:
    // Implementing methods to display menu and handle user input
    void displayMenu() {
        cout << "1. Display a file\n"
                  << "2. Display the file table\n"
                  << "3. Display the free space bitmap\n"
                  << "4. Display a disk block\n"
                  << "5. Copy a file from the simulation to a file on the real system\n"
                  << "6. Copy a file from the real system to a file in the simulation\n"
                  << "7. Delete a file\n"
                  << "8. Exit\n";
    }

    void processUserChoice(int choice) {
        switch (choice) {
            case 1: {
                int fileIndex;
                cout << "Enter the file index: ";
                cin >> fileIndex;
                fileSystem.displayFile(fileIndex);
                break;
            }
            case 2: {
                fileSystem.displayFileTable();
                break;
            }
            case 3: {
                fileSystem.displayFreeSpaceBitmap();
                break;
            }
            case 4: {
                int blockNumber;
                cout << "Enter the block number: ";
                cin >> blockNumber;
                fileSystem.displayDiskBlock(blockNumber);
                break;
            }
            case 5: {
                string realFilePath, simulationFileName;
                cout << "Enter the real file path: ";
                cin >> realFilePath;
                cout << "Enter the simulation file name: ";
                cin >> simulationFileName;
                fileSystem.copyFileToSimulation(realFilePath, simulationFileName);
                break;
            }
            case 6: {
                string simulationFileName, realFilePath;
                cout << "Enter the simulation file name: ";
                cin >> simulationFileName;
                cout << "Enter the real file path: ";
                cin >> realFilePath;
                fileSystem.copyFileToRealSystem(simulationFileName, realFilePath);
                break;
            }
            case 7: {
                int fileIndex;
                cout << "Enter the file index you would like to delete: ";
                cin >> fileIndex;
                fileSystem.deleteFile(fileIndex);
                break;
            }
            case 8: {
                cout << "Exiting program.\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    }
};