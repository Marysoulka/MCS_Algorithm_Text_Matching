// lab1.cpp
#include "lab1.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

// Generates a random text of the given size using the specified alphabet size
std::vector<std::string> generateRandomText(int size, int alphabetSize) {
    std::srand(std::time(nullptr));
    std::string text;
    for (int i = 0; i < size; i++) {
        char randomChar = 'A' + (std::rand() % alphabetSize);
        text += randomChar;
    }
    return { text };
}

// Generates random queries with sizes between minSize and maxSize
std::vector<std::string> generateRandomQueries(int count, int minSize, int maxSize) {
    std::srand(std::time(nullptr));
    std::vector<std::string> queries;
    for (int i = 0; i < count; i++) {
        int querySize = minSize + (std::rand() % (maxSize - minSize + 1));
        std::string query;
        for (int j = 0; j < querySize; j++) {
            query += 'A' + (std::rand() % 26);
        }
        queries.push_back(query);
    }
    return queries;
}

// Performs search using the MCS algorithm
std::vector<std::string> searchWithMCS(const std::string& text, const std::vector<std::string>& queries, double matchThreshold, int numBinaryForms) {
    std::vector<std::string> results;
    for (const auto& query : queries) {
        int matches = 0;
        for (size_t i = 0; i <= text.size() - query.size(); i++) {
            int matchCount = 0;

            // Divide the query into binary forms (chunks)
            int chunkSize = query.size() / numBinaryForms;
            for (int k = 0; k < numBinaryForms; k++) {
                for (size_t j = k * chunkSize; j < (k + 1) * chunkSize && j < query.size(); j++) {
                    if (text[i + j] == query[j]) {
                        matchCount++;
                    }
                }
                // Early exit if match threshold is met
                if (matchCount >= query.size() * matchThreshold) break;
            }
            if (matchCount >= query.size() * matchThreshold) {
                matches++;
            }
        }
        if (matches > 0) {
            results.push_back(query);
        }
    }
    return results;
}

// Performs a naive search for each query in the text
std::vector<std::string> naiveSearch(const std::string& text, const std::vector<std::string>& queries) {
    std::vector<std::string> results;
    for (const auto& query : queries) {
        if (text.find(query) != std::string::npos) {
            results.push_back(query);
        }
    }
    return results;
}
