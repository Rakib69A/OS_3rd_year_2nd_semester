#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int optimalPageReplacement(const vector<int>& pages, int numFrames) {
    int pageFaults = 0;
    vector<int> frames(numFrames, -1); // Initialize frames with -1 (indicating empty)

    for (int i = 0; i < pages.size(); i++) {
        int page = pages[i];

        // Check if the page is already in a frame
        bool pageFound = false;
        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == page) {
                pageFound = true;
                break;
            }
        }

        if (!pageFound) {
            int victimIndex = -1;
            int farthest = i;

            // Find the page in frames that will not be used for the longest time
            for (int j = 0; j < numFrames; j++) {
                int nextPageIndex = i + 1;
                while (nextPageIndex < pages.size()) {
                    if (frames[j] == pages[nextPageIndex]) {
                        if (nextPageIndex > farthest) {
                            farthest = nextPageIndex;
                            victimIndex = j;
                        }
                        break;
                    }
                    nextPageIndex++;
                }

                if (nextPageIndex == pages.size()) {
                    // If a page won't be used again, use it as the victim
                    victimIndex = j;
                    break;
                }
            }

            // Replace the victim page
            frames[victimIndex] = page;
            pageFaults++;
        }
    }

    return pageFaults;
}

int main() {
    vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int numFrames = 3;

    int pageFaults = optimalPageReplacement(pages, numFrames);

    cout << "Total page faults: " << pageFaults << endl;

    return 0;
}

