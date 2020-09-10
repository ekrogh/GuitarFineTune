// factorials (multiplies example)
#include <iostream>     // std::cout
#include <functional>   // std::multiplies
#include <numeric>      // std::partial_sum
#include <algorithm>	//std::transform
#include <vector>		//std::vector
#include <iterator>		//std::back_inserter
#include <complex>		//Complex

int main() {
	enum
	{
		numElements = 2048
	};
	std::complex<double> numbers[numElements] = { 0 };
	std::complex<double> factorials[numElements] = { 0 };
	std::complex<double> theResult[numElements] = { 0 };
	//std::vector<std::complex<double>> numbers(numElements);
	//std::vector<std::complex<double>> factorials(numElements);
	//std::vector<std::complex<double>> theResult(numElements);

	for (int teller = 0; teller < numElements; teller++)
	{
		numbers[teller] = std::complex<double>(teller, teller);
		factorials[teller] = std::complex<double>(teller, -teller);
		//numbers.push_back(std::complex<double>(teller, teller));
		//factorials.push_back(std::complex<double>(teller, -teller));
	}
	std::transform(numbers, numbers + numElements - 1, theResult, [](std::complex<double> const& x) {return std::conj(x); });
	//std::transform(numbers.begin(), numbers.end(), theResult.begin(), [](std::complex<double> const& x) {return std::conj(x); });
	//std::transform(numbers.begin(), numbers.end(), std::back_inserter(theResult), [](std::complex<double> const& x) {return std::conj(x); });
	//std::transform(numbers.begin(), numbers.end(), factorials.begin(), std::back_inserter(theResult), std::multiplies<double>());
	//std::transform(numbers.begin(), numbers.end(), factorials.begin(), theResult.begin(), std::multiplies<double>());

	//for (int i = 0; i < 9; i++)
	//	std::cout << theResult[i] << '\n';

	//char keyIn;
	//std::cin >> keyIn;

	return 0;
}
