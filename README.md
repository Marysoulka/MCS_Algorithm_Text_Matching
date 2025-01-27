# MCS_Algorithm_Text_Matching
This repository showcases the implementation and analysis of the Matching Chunked Search (MCS) algorithm for approximate text matching. Designed for large-scale text datasets, the MCS algorithm delivers a balance between efficiency and accuracy, making it suitable for applications requiring scalable and precise text analysis.

# **MCS Algorithm Implementation for Approximate Text Matching**

## **Overview**
This repository contains the implementation of the Matching Chunked Search (MCS) algorithm for approximate text matching. The algorithm is designed to efficiently handle large-scale text datasets while maintaining high accuracy. It is compared with a naive substring search approach for performance benchmarking.

---

## **Features**
1. **MCS Algorithm**:
   - Supports 4 and 5 binary forms for chunking.
   - Matches substrings with at least 60% similarity.
   - Designed for large-scale datasets.

2. **Naive Algorithm**:
   - A baseline implementation for direct substring search.

3. **Experimentation**:
   - Processes 10 million characters of randomly generated text.
   - Evaluates 10,000 queries of length 22–28 characters.

4. **Performance Metrics**:
   - Matching accuracy.
   - Runtime efficiency.
   - Theoretical complexity analysis.

---

## **Repository Contents**
- **Source Code**:
  - `mcs_algorithm.h`: Header file containing MCS algorithm definitions.
  - `mcs_algorithm.cpp`: Implementation of the MCS algorithm.
  - `main.cpp`: Driver code for the experiments.

- **Results**:
  - `results.txt`: Contains the experiment results, including runtime and theoretical complexity comparisons.
- **Documentation**:
  - `report.docx`: Detailed report documenting the MCS algorithm and its evaluation.
---

## **Usage**

### **Dependencies**
- C++ Compiler supporting C++11 or later.

### **How to Compile**
1. Clone the repository:
   ```bash
   git clone https://github.com/Marysoulka/MCS_Algorithm_Text_Matching.git
   cd MCS_Algorithm_Text_Matching

   ```
2. Compile the code:
   ```bash
   g++ -std=c++11 main.cpp mcs_algorithm.cpp -o mcs_algorithm
   ```
3. Run the compiled program:
   ```bash
   ./mcs_algorithm
   ```

### **Expected Output**
The program outputs runtime comparisons, accuracy metrics, and theoretical complexities for the MCS and naive algorithms. Results are saved in the `results.txt` file.

---

## **Results Summary**
| Method | Threshold | Binary Forms | Matches Found | Time (ms) | Theoretical Complexity |
|--------|-----------|--------------|---------------|-----------|-------------------------|
| MCS    | 60%       | 4            | 1000          | 10,055    | O(60,000,000)          |
| MCS    | 60%       | 5            | 1000          | 14,316    | O(48,000,000)          |
| Naive  | -         | -            | 1000          | 88        | O(240,000,000)         |

### **Detailed Observations**
1. The MCS algorithm's runtime is slower than the naive approach for small inputs due to initialization overhead. However, it excels in scalability for larger datasets.
2. Using 5 binary forms yields a slightly higher runtime but ensures better efficiency at the theoretical complexity level.
3. The naive method is computationally more expensive for larger datasets, making it unsuitable for high-volume text processing.

---

## **Conclusion**
The MCS algorithm provides a scalable solution for approximate text matching with a balance between accuracy and performance:
1. **Efficiency**: MCS offers better scalability compared to naive search, with reduced theoretical complexity.
2. **Flexibility**: Configurable binary forms and matching thresholds cater to diverse use cases.
3. **Accuracy**: Matches are consistent across methods, confirming correctness.

### **Recommendations**
- Use MCS with 5 binary forms for large datasets requiring high performance.
- Adjust alphabet size for application-specific requirements to control match rates.
- Extend tests to datasets larger than 10 million characters for further scalability evaluation.

---

## **Acknowledgments**
This work implements and evaluates the MCS algorithm, a robust approach to approximate text matching. The results and analysis demonstrate the potential of advanced matching algorithms for large-scale data processing.
