#include <istream>
#include <sstream>
#include <string>
#include <vector>
#include "./InStreamInput.h"

/// @param input The stream to read input from
InStreamInput::InStreamInput(std::istream& input): inputStream(input) {};

/// @brief Reads lines from the provided input stream until a line that contains only numbers is found.
/// 	Then, fills the provided vector with the numbers found on that line.
/// 	If no valid lines were found in the input stream, the vector will be empty and the function will return -1.
/// @param iVector A pointer to a vector that will store the numbers. The vector will be cleared before reading the line.
/// @param minNums The minimum amount of numbers that has to exist in the same input line to consider it valid (inclusive). Defaults to 1.
/// @param maxNums The maximum amount of numbers that has to exist in the same input line to consider it valid (inclusive). Defaults to 0 (unrestricted).
/// @return The function returns 0 if a valid line was found and -1 otherwise.
int InStreamInput::readLineNumbers(std::vector<int>* iVector, unsigned short minNums, unsigned short maxNums) {
	// Read each line separately until the end of the input stream. When a valid line is found, the loop will break.
	while (!this->inputStream.eof()) {
		iVector->clear();

		// Extract the next line from the input stream into its own	 stream
		std::string line;
		std::getline(this->inputStream, line);
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
/// @param settingsVec A pointer to a vector that will store the numbers. The vector will be cleared before reading the line.
/// @param maxIdVal The maximum value for each of the parameters after the first one (exclusive).
/// @return The function returns 0 if a valid line was found and -1 otherwise.
int InStreamInput::getFilterSettings(std::vector<int>* settingsVec, int maxIdVal) {
	/* Continue reading lines until we find a line with enough numbers, and the non-first numbers are all in range */
	while (true) {
		bool failure = this->readLineNumbers(settingsVec, 2) == -1;
		if (failure) return -1; // `readLineNumbers()` has already cleared `settingsVec`

		// Return if all all settings parameters are valid
		bool valid = true;
		for (int i = 1; i < maxIdVal && valid; i++) {
			valid = settingsVec->size() < i+1 || isInRange((*settingsVec)[i], 1, maxIdVal);
		}
		if (valid) return 0;
	}
}

/// @brief Reads lines from the provided input stream until a line that contains a number which is between 1 and
/// 	`max` followed by a non-whitespace characters is found. Then, puts that number into the provided
/// 	`actionNumber`, and the rest of the line (ignoreing the leading whitespace) into the `url`.
/// 	If no valid lines were found in the input stream, the function will return -1.
/// @param actionNumber A pointer to an integer
/// @param url A pointer to a string
/// @param max The maximum valid value for the first number (exclusive)
/// @return The function returns 0 if a valid line was found and -1 otherwise.
int InStreamInput::getUserActionAndURL(int* actionNumber, std::string* url, int max) {
	// Read each line separately until the end of the input stream. When a valid line is found, the loop will break.
	while (!this->inputStream.eof()) {
		// Extract the next line from the input stream into its own stream
		std::string line;
		std::getline(this->inputStream, line);
		std::stringstream lineStream(line);

		int action;
		if (lineStream >> action) {
			std::string actionStr;
			if (1 <= action && action < max && lineStream >> actionStr) {
				// If both reads were successfull, update pointed variables and return 0
				*actionNumber = action;
				*url = actionStr;
				return 0;
			}
		}
	}

	return -1;
}
