#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>

using namespace std;


// Function to generate a random instance of the set cover problem
void generateSetCoverInstance(int numElements, int numSubsets, int maxSubsetSize, int maxSubsetWeight) {
    vector<int> universe(numElements);
    vector<pair<set<int>, int> > subsets(numSubsets);

    // Initialize the universe with elements 0 to numElements-1
    for (int i = 0; i < numElements; ++i) {
        universe[i] = i;
    }

    // Seed the random number generator
    srand(time(0));

    // Generate random subsets
    for (int i = 0; i < numSubsets; ++i) {
        int subsetSize = rand() % maxSubsetSize + 1; // Random subset size between 1 and maxSubsetSize
        int subsetWeight = rand() % maxSubsetWeight + 1;

        subsets[i].second = subsetWeight;

        while (subsets[i].first.size() < subsetSize) {
            int element = universe[rand() % numElements];
            subsets[i].first.insert(element);
        }
    }

    // Print the generated instance
    cout << "Universe: ";
    for (int elem : universe) {
        cout << elem << " ";
    }
    cout << endl;

    cout << "Subsets:" << endl;
    for (int i = 0; i < numSubsets; ++i) {
        cout << "Subset " << i << " (Weight: " << subsets[i].second << "): ";
        for (int elem : subsets[i].first) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
    int numElements = 10; // Number of elements in the universe
    int numSubsets = 5;   // Number of subsets
    int maxSubsetSize = 5; // Maximum size of each subset
    int maxSubsetWeight = 5;

    generateSetCoverInstance(numElements, numSubsets, maxSubsetSize, maxSubsetWeight);

    return 0;
}
