#include <iostream>
#include <sstream>
#include <string>
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

			/* If the input contains trailing whitespace, the last iteration will fail. In this case, the assignment to
				`n` will consume the trailing whitespace. We still want `lineStream.eof()` to return `true` in this
				case, so we try to read another character from the stream to trigger the `eofbit`. */
			if (lineStream.fail()) {
				lineStream.get(nextChar);
				break;
			} else {
				iVector->push_back(n);
			}
		}

		/* Since `lineStream` only contains one line, we know it ended when the next char is EOF. However,
			if we failed before reaching EOF, then we know the line was invalid and continue to the next line. */
		if (lineStream.eof() && minNums <= iVector->size() && (iVector->size() <= maxNums || maxNums == 0)) return 0;
	}

	// The read failed. Clear the vector and return -1
	iVector->clear();
	return -1;
}

/// @brief Checks if a number is between two other numbers
/// @param x The number to check
/// @param min The minimum of the range (inclusive)
/// @param max The maximum of the range (exclusive)
/// @return `true` if the `x` is in the range, and `false` otherwise
bool isInRange(int x, int min, int max) {
	return min <= x && x < max;
}

/// @brief Reads lines from the provided input stream until a line that contains valid input for the filter settings is found.
/// 	Then, fills the provided vector with the numbers found on that line.
/// 	If no valid lines were found in the input stream, the vector will be empty and the function will return -1.
/// @param input An input stream reference
/// @param settingsVec A pointer to a vector that will store the numbers. The vector will be cleared before reading the line.
/// @param maxIdVal The maximum value for each of the parameters after the first one (exclusive), and the maximum amuont of numbers that is considered valid (inclusive).
/// @return The function returns 0 if a valid line was found and -1 otherwise.
int getFilterSettings(std::istream& input, std::vector<int>* settingsVec, int maxIdVal) {
	/* Continue reading lines until we find a line with enough numbers, and the non-first numbers are all in range */
	while (true) {
		bool failure = readLineNumbers(input, settingsVec, 2, maxIdVal) == -1;
		if (failure) return -1; // `readLineNumbers()` has already cleared `settingsVec`

		bool valid = true;
		for (int i = 1; i < maxIdVal && valid; i++) {
			valid = settingsVec->size() < i+1 || isInRange((*settingsVec)[i], 1, maxIdVal);
		}
		if (valid) return 0;
	}
}
