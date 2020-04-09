#include "PermutatedSequence.h"

PermutatedSequence::PermutatedSequence()
{
	sequence = { 1, 2, 3 };
}

void PermutatedSequence::allPermutations()
{
	do {

		for (auto el : sequence)
		{
			std::cout << el << " ";
		}
		std::cout << std::endl;

	} while (std::next_permutation(sequence.begin(), sequence.end()));
}
