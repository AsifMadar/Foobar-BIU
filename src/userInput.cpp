#include <iostream>
#include <sstream>
#include <vector>

/// @brief Reads lines from the provided input stream until a line that contains only numbers is found.
/// 	Then, fills the provided vector with the numbers found on that line.
/// 	If no valid lines were found in the input stream, the vector will be empty and the function will return -1.
/// @param input An input stream reference
/// @param iVector A pointer to a vector that will store the numbers. The vector will be cleared before reading the line.
/// @param minNums The minimum amount of numbers that has to exist in the same input line to consider it valid (inclusive). Defaults to 1.
/// @param maxNums The maximum amount of numbers that has to exist in the same input line to consider it valid (inclusive). Defaults to 0 (unrestricted).
/// @return The function returns 0 if a valid line was found and -1 otherwise.
int readLineNumbers(std::istream& input, std::vector<int>* iVector, unsigned short minNums = 1, unsigned short maxNums = 0) {
	// Read each line separately until the end of the input stream. When a valid line is found, the loop will break.
	while (!input.eof()) {
		iVector->clear();

		// Extract the next line from the input stream into its own stream
		std::string line;
		std::getline(input, line);
		std::stringstream lineStream(line);

		// Read numbers until the end of the line, and stop early if invalid input was provided
		for (char nextChar = lineStream.peek(); nextChar != EOF && !lineStream.fail(); nextChar = lineStream.peek()) {
			int n;
			lineStream >> n;
			iVector->push_back(n);
		}

		/* Since `lineStream` only contains one line, we know it ended when the next char is EOF. However,
			if we failed before reaching EOF, then we know the line was invalid and continue to the next line. */
		int vecSize = iVector->size();
		if (lineStream.eof() && minNums <= vecSize && (vecSize <= maxNums || maxNums == 0)) return 0;
	}

	return -1;
}
