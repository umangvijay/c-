#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Function for Optimal Page Replacement
void optimalPageReplacement(const vector<int>& pages, int frames) {
    vector<int> memory; // Memory to store current pages
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
                // Add the page if there's still space
                memory.push_back(page);
            } else {
                // Find the page to replace using Optimal strategy
                int farthestIndex = -1, pageToReplace = -1;

                for (int memPage : memory) {
                    // Find the next occurrence of each page in memory
                    auto it = find(pages.begin() + i + 1, pages.end(), memPage);
                    int nextIndex = (it == pages.end()) ? pages.size() : distance(pages.begin(), it);

                    // Replace the page that won't be used for the longest time
                    if (nextIndex > farthestIndex) {
                        farthestIndex = nextIndex;
                        pageToReplace = memPage;
                    }
                }

                // Replace the selected page
                replace(memory.begin(), memory.end(), pageToReplace, page);
            }
        }

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

    // Perform Optimal Page Replacement and show detailed output
    optimalPageReplacement(pages, numFrames);

    return 0;
}
