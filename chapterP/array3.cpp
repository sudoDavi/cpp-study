#include <iostream>
#include <iterator>

int main() {
	constexpr int scores[]{ 84, 92, 76, 81, 56 };
	constexpr int numStudents{ static_cast<int>(std::size(scores)) };

	int maxScoreIndex{ 0 };

	// now look for a larger score
	for (int student{ 0 }; student < numStudents; ++student)
	{
	    if (scores[student] > scores[maxScoreIndex])
	    {
	        maxScoreIndex = student;
	    }
	}

	std::cout << "The best score was " << scores[maxScoreIndex] << '\n';

	return 0;
}
