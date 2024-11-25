#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

// Function for FIFO Page Replacement
void fifoPageReplacement(const vector<int>& pages, int frames) {
    queue<int> memoryQueue;   // Queue to implement FIFO memory
    vector<int> memoryState;  // Tracks the current state of memory
    int pageFaults = 0, pageHits = 0;

    // Header for output
    cout << left << setw(10) << "Step" << setw(20) << "Page Reference"
         << setw(30) << "Memory State" << setw(10) << "Result" << endl;

    for (int i = 0; i < pages.size(); ++i) {
        int page = pages[i];
        bool pageFound = false;
        string result;

        // Check if the page is already in memory (manual loop instead of `find`)
        for (int j = 0; j < memoryState.size(); ++j) {
            if (memoryState[j] == page) {
                pageFound = true;
                break;
            }
        }

        if (pageFound) {
            // Page hit
            pageHits++;
            result = "Hit";
        } else {
            // Page fault
            pageFaults++;
            result = "Fault";

            if (memoryState.size() < frames) {
                // Add the page to memory if there's space
                memoryQueue.push(page);
                memoryState.push_back(page);
            } else {
                // Remove the oldest page (FIFO rule)
                int oldestPage = memoryQueue.front();
                memoryQueue.pop();

                // Manually remove the page from memoryState
                for (int j = 0; j < memoryState.size(); ++j) {
                    if (memoryState[j] == oldestPage) {
                        memoryState[j] = page; // Replace the oldest page with the new one
                        break;
                    }
                }

                // Add the new page to the queue
                memoryQueue.push(page);
            }
        }

        // Print the current state
        cout << left << setw(10) << (i + 1) << setw(20) << page;
        for (int memPage : memoryState) {
            cout << memPage << " ";
        }
        cout << setw(30 - memoryState.size() * 2) << " " << result << endl;
    }

    // Print the total number of hits and faults
    cout << "\nTotal Page Faults: " << pageFaults << endl;
    cout << "Total Page Hits: " << pageHits << endl;
}

int main() {
    int numPages, numFrames;

    // Input the number of pages
    cout << "Enter the number of pages: ";
    cin >> numPages;

    vector<int> pages(numPages);
    cout << "Enter the page reference sequence: ";
    for (int i = 0; i < numPages; ++i) {
        cin >> pages[i];
    }

    // Input the number of frames
    cout << "Enter the number of frames: ";
    cin >> numFrames;

    // Perform FIFO Page Replacement and show detailed output
    fifoPageReplacement(pages, numFrames);

    return 0;
}
