/*
 * nhocr-hcl.cpp
 *
 *  Created on: Jan 16, 2012
 *      Author: asanoki
 */

#include <fstream>
#include <iostream>
#include <cstdio>

int main(int argc, char **argv) {
	std::fstream input;
	std::fstream output;
	char buffer[16] = { 0 };
	char buffer_zero[512] = { 0 };
	if (argc < 2) {
		std::cerr << "Usage: ./nhocr-hcl <input-hcl-file> <output-img-file>"
				<< std::endl;
		return -1;
	}
	input.open(argv[1], std::ios::in | std::ios::binary);
	if (!input.good()) {
		std::cerr << "Failed to open input file" << std::endl;
		return -2;
	}
	output.open(argv[2], std::ios::out | std::ios::binary);
	if (!output.good()) {
		std::cerr << "Failed to create output file" << std::endl;
		return -3;
	}
	// Skip a header
	input.seekg(512);
	while (!input.eof()) {
		output.write((char *) buffer_zero, 512);
		for (int row = 0; row < 64; row++) {
			input.read(buffer + 4, 8);
			output.write((char *) buffer, 16);
		}
		output.write((char *) buffer_zero, 512);
	}
	return 0;
}
