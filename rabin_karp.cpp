#include <iostream>
#include <string>
#include <vector>

using namespace std;

const long long PRIME1 = 1e9 + 7; // First prime for hashing
const long long PRIME2 = 1e9 + 9; // Second prime for hashing
const int BASE = 26;              // Base for alphabet ('a' to 'z')

// Function to calculate hash value of a string for a given prime using custom base update
pair<long long, long long> calculateDoubleHash(const string &str, int length) {
    long long hash1 = 0, hash2 = 0;
    long long base1 = 1, base2 = 1; // Initialize the base value for both hashes

    for (int i = 0; i < length; i++) {
        // Update hash using the current character and base, and update the base afterward
        hash1 = (hash1 + (str[i] - 'a') * base1) % PRIME1;
        base1 = (base1 * BASE) % PRIME1; // Update base1 for the next character

        hash2 = (hash2 + (str[i] - 'a') * base2) % PRIME2;
        base2 = (base2 * BASE) % PRIME2; // Update base2 for the next character
    }
    return {hash1, hash2};
}

// Function to perform the Rabin-Karp string matching algorithm with double hashing
vector<int> rabinKarpDoubleHashSearch(const string &text, const string &pattern) {
    int textLen = text.length();
    int patternLen = pattern.length();
    vector<int> result;

    if (patternLen > textLen) {
        return result; // Pattern length can't be greater than text length
    }

    // Compute the hash of the pattern and the first window of text
    auto patternHash = calculateDoubleHash(pattern, patternLen);
    auto textHash = calculateDoubleHash(text, patternLen);

    long long base1 = 1, base2 = 1; // Initial base value for sliding window
    for (int i = 0; i < patternLen - 1; i++) {
        base1 = (base1 * BASE) % PRIME1; // Compute BASE^(patternLen-1) % PRIME1
        base2 = (base2 * BASE) % PRIME2; // Compute BASE^(patternLen-1) % PRIME2
    }

    // Sliding window over text to check for matches
    for (int i = 0; i <= textLen - patternLen; i++) {
        // If both hashes match, check the actual substring for character by character match
        if (patternHash == textHash) {
            bool match = true;
            for (int j = 0; j < patternLen; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                result.push_back(i); // Pattern found at index i
            }
        }

        // Calculate the hash for the next window
        if (i < textLen - patternLen) {
            // Update hash1 (for PRIME1)
            textHash.first = (textHash.first - (text[i] - 'a') * base1) % PRIME1;
            textHash.first = (textHash.first + PRIME1) % PRIME1; // Ensure it's non-negative
            textHash.first = (textHash.first * BASE + (text[i + patternLen] - 'a')) % PRIME1;

            // Update hash2 (for PRIME2)
            textHash.second = (textHash.second - (text[i] - 'a') * base2) % PRIME2;
            textHash.second = (textHash.second + PRIME2) % PRIME2; // Ensure it's non-negative
            textHash.second = (textHash.second * BASE + (text[i + patternLen] - 'a')) % PRIME2;
        }
    }

    return result;
}

int main() {
    string text = "ababcabcabababd";
    string pattern = "ababd";

    vector<int> matches = rabinKarpDoubleHashSearch(text, pattern);

    if (!matches.empty()) {
        cout << "Pattern found at indices: ";
        for (int index : matches) {
            cout << index << " ";
        }
        cout << endl;
    } else {
        cout << "Pattern not found in the text." << endl;
    }

    return 0;
}
