// main.cpp
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>
#include <fstream>
#include "lab1.h"
#include <thread>
#include <mutex>

// Mutex for thread-safe operations (if multi-threading is introduced)
std::mutex resultsMutex;

int main() {
    // Define the size of the random text and the alphabet size
    int textSize = 10000000;
    int alphabetSize = 26;
    std::cout << "Generating random text of size 10M \n";

    // Generate random text
    std::string text = generateRandomText(textSize, alphabetSize)[0];
    std::cout << "Random text generated.\n";

    // Save the generated random text to a file
    std::ofstream textFile("randomtext.txt");
    textFile << text;
    textFile.close();
    std::cout << "Random text saved to randomtext.txt\n";

    // Define query parameters
    int queryCount = 10000;
    int minQuerySize = 22;
    int maxQuerySize = 28;
    std::cout << "Generating 10K random queries of size between "
        << minQuerySize << " and " << maxQuerySize << "...\n";

    // Generate random queries
    std::vector<std::string> queries = generateRandomQueries(queryCount, minQuerySize, maxQuerySize);
    std::cout << "Random queries generated.\n";

    // Define the match threshold for the MCS algorithm
    double matchThreshold = 0.6;

    // Open results file to log output
    std::ofstream resultsFile("results.txt");
    resultsFile << std::left << std::setw(15) << "Method"
        << std::setw(15) << "Threshold"
        << std::setw(15) << "Binary Forms"
        << std::setw(20) << "Matches Found"
        << std::setw(15) << "Time (ms)"
        << std::setw(25) << "Theoretical Complexity"
        << "\n";
    resultsFile << std::string(110, '-') << "\n";

    std::cout << "\nPerforming MCS search with match threshold: " << matchThreshold * 100 << "%\n";

    // Define the binary forms used for the MCS algorithm
    std::vector<std::string> binaryForms = {
        "111111111111111100000000",
        "111111110000111100001111",
        "111100001111000011110000",
        "110011001100110011001100",
        "101010101010101010101010"
    };

    // Iterate over configurations for 4 and 5 binary forms
    for (size_t numBinaryForms = 4; numBinaryForms <= 5; numBinaryForms++) {
        std::cout << "  Using " << numBinaryForms << " binary forms:\n";

        // Display binary forms used
        for (size_t i = 0; i < numBinaryForms; i++) {
            std::cout << "    Form " << i + 1 << ": " << binaryForms[i] << "\n";
        }

        auto start = std::chrono::high_resolution_clock::now();

        // Process queries in batches
        size_t batchSize = 1000;
        size_t totalMatches = 0;

        // Calculate theoretical complexity for the current configuration
        long long theoreticalComplexity = static_cast<long long>(textSize) * (minQuerySize + maxQuerySize) / 2 / numBinaryForms;

        for (size_t startIdx = 0; startIdx < queries.size(); startIdx += batchSize) {
            size_t endIdx = std::min(startIdx + batchSize, queries.size());
            std::vector<std::string> batch(queries.begin() + startIdx, queries.begin() + endIdx);

            // Perform search on the current batch
            std::vector<std::string> results = searchWithMCS(text, batch, matchThreshold, numBinaryForms);

            // Update total matches found
            totalMatches += results.size();
        }

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

        std::cout << "    Matches found: " << totalMatches << "\n";
        std::cout << "    Time taken: " << duration << " ms\n";

        resultsFile << std::setw(15) << "MCS"
            << std::setw(15) << matchThreshold * 100
            << std::setw(15) << numBinaryForms
            << std::setw(20) << totalMatches
            << std::setw(15) << duration
            << std::setw(25) << "O(" + std::to_string(theoreticalComplexity) + ")"
            << "\n";
    }

    // Perform naive search as a baseline comparison
    std::cout << "\nPerforming naive search...\n";
    auto startNaive = std::chrono::high_resolution_clock::now();
    std::vector<std::string> naiveResults = naiveSearch(text, queries);
    auto endNaive = std::chrono::high_resolution_clock::now();

    auto durationNaive = std::chrono::duration_cast<std::chrono::milliseconds>(endNaive - startNaive).count();
    long long theoreticalComplexityNaive = static_cast<long long>(textSize) * (minQuerySize + maxQuerySize) / 2;

    std::cout << "  Matches found: " << naiveResults.size() << "\n";
    std::cout << "  Time taken: " << durationNaive << " ms\n";

    resultsFile << std::setw(15) << "Naive"
        << std::setw(15) << "-"
        << std::setw(15) << "-"
        << std::setw(20) << naiveResults.size()
        << std::setw(15) << durationNaive
        << std::setw(25) << "O(" + std::to_string(theoreticalComplexityNaive) + ")"
        << "\n";

    resultsFile.close();
    std::cout << "Results saved to results.txt\n";
    return 0;
}