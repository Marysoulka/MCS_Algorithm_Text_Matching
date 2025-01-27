// lab1.h
#ifndef LAB1_H
#define LAB1_H

#include <string>
#include <vector>

// Function declarations
// Generates a random text of a given size using the specified alphabet size
std::vector<std::string> generateRandomText(int size, int alphabetSize);

// Generates a specified number of random queries with sizes between minSize and maxSize
std::vector<std::string> generateRandomQueries(int count, int minSize, int maxSize);

// Performs a search using the Matching Chunked Search (MCS) algorithm
// text: The text to search in
// queries: A list of queries to search for
// matchThreshold: The minimum percentage of characters that must match
// numBinaryForms: The number of binary forms to divide the query into
std::vector<std::string> searchWithMCS(const std::string& text, const std::vector<std::string>& queries, double matchThreshold, int numBinaryForms);

// Performs a naive search for each query in the text
std::vector<std::string> naiveSearch(const std::string& text, const std::vector<std::string>& queries);

#endif // LAB1_H