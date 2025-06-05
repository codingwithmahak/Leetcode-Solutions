#include <string>
#include <vector>
#include <numeric> 
#include <algorithm> 

class Solution {
public:
   
    std::vector<int> parent;

    // Find operation with path compression.
    // It returns the representative (root) of the set containing 'i'.
    int find(int i) {
        if (parent[i] == i) {
            // If the character is its own parent, it's the root of its set.
            return i;
        }
        // Path compression: set parent[i] directly to the root of its set.
        return parent[i] = find(parent[i]);
    }

    // Unite operation: merges the sets containing 'i' and 'j'.
    // The lexicographically smaller character becomes the new root.
    void unite(int i, int j) {
        int root_i = find(i); // Find the root of the set containing i.
        int root_j = find(j); // Find the root of the set containing j.

        if (root_i != root_j) {
            // If they are in different sets, merge them.
            // The smaller character's root becomes the parent of the larger character's root.
            if (root_i < root_j) {
                parent[root_j] = root_i;
            } else {
                parent[root_i] = root_j;
            }
        }
    }

    // Main function to find the smallest equivalent string.
    std::string smallestEquivalentString(std::string s1, std::string s2, std::string baseStr) {
        // Initialize the parent array.
        // Each character ('a' to 'z') is initially its own parent.
        parent.resize(26);
        std::iota(parent.begin(), parent.end(), 0); // Fills parent with 0, 1, 2, ..., 25

        // Process s1 and s2 to establish equivalence relations.
        // For each corresponding pair of characters in s1 and s2, unite their sets.
        for (size_t k = 0; k < s1.length(); ++k) {
            unite(s1[k] - 'a', s2[k] - 'a');
        }

        // Build the result string by transforming each character in baseStr.
        std::string result = "";
        for (char c : baseStr) {
          
            result += (char)(find(c - 'a') + 'a');
        }

        return result;
    }
};