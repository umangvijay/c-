#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Function for LRU Page Replacement
int lruPageReplacement(const vector<int>& pages, int frames) {
    vector<int> memory;                   // Memory to store current pages
    unordered_map<int, int> pageIndices; // Tracks the most recent index of each page
    int pageFaults = 0;

    for (int i = 0; i < pages.size(); ++i) {
        int page = pages[i];

        // Check if the page is already in memory
        if (find(memory.begin(), memory.end(), page) == memory.end()) {
            // Page fault
            pageFaults++;

            if (memory.size() < frames) {
                // Add the page if there's still space in memory
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

        // Update the index of the current page
        pageIndices[page] = i;
    }

    return pageFaults;
}

// Main function
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

    // Calculate page faults using LRU
    int pageFaults = lruPageReplacement(pages, numFrames);

    // Output the result
    cout << "Total Page Faults using LRU: " << pageFaults << endl;

    return 0;
}
