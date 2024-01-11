#include <iostream>
#include <sstream>
#include <vector>

/// @brief Reads lines from the provided input stream until a line that contains only numbers is found.
/// 	Then, fills the provided vector with the numbers found on that line.
/// @param input
/// @param iVector A vector to store the numbers in. The vector will be cleared before reading the line.
void readLineNumbers(std::istream& input, std::vector<int>* iVector) {
	while (!input.eof()) {
		iVector->clear();

		std::string line;
		std::getline(input, line);
		std::stringstream lineStream(line);

		char nextChar = lineStream.peek();
		for (int n; nextChar != EOF && !lineStream.fail(); nextChar = lineStream.peek()) {
			lineStream >> n;
			iVector->push_back(n);
		}

		/* Since `lineStream` only contains one line, we know it ended when the next char is EOF. However,
			if we failed before reaching EOF, then we know the line was invalid and continue to the next line. */
		if (lineStream.eof()) break;
	}
}
