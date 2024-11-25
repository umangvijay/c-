#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

using namespace std;

// Function for LRU Page Replacement
void lruPageReplacement(const vector<int>& pages, int frames) {
    vector<int> memory;                   // Memory to store current pages
    unordered_map<int, int> pageIndices; // Tracks the most recent index of each page
    int pageFaults = 0, pageHits = 0;

    cout << left << setw(10) << "Step" << setw(20) << "Page Reference"
         << setw(30) << "Memory State" << setw(10) << "Result" << endl;

    for (int i = 0; i < pages.size(); ++i) {
        int page = pages[i];
        string result;

        // Check if the page is already in memory
        if (find(memory.begin(), memory.end(), page) != memory.end()) {
            // Page hit
            pageHits++;
            result = "Hit";
        } else {
            // Page fault
            pageFaults++;
            result = "Fault";

            if (memory.size() < frames) {
                // Add the page if there's space
                memory.push_back(page);
            } else {
                // Find the least recently used (LRU) page to replace
                int lruIndex = i;
                int lruPage = -1;

                for (int memPage : memory) {
                    if (pageIndices[memPage] < lruIndex) {
                        lruIndex = pageIndices[memPage];
                        lruPage = memPage;
                    }
                }

                // Replace the LRU page with the new page
                replace(memory.begin(), memory.end(), lruPage, page);
            }
        }

        // Update the recent index for the page
        pageIndices[page] = i;

        // Print the current state
        cout << left << setw(10) << (i + 1) << setw(20) << page;
        for (int memPage : memory) {
            cout << memPage << " ";
        }
        cout << setw(30 - memory.size() * 2) << " " << result << endl;
    }

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

    // Perform LRU Page Replacement and show detailed output
    lruPageReplacement(pages, numFrames);

    return 0;
}
