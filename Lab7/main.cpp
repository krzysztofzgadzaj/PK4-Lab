#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <thread>
#include <ctime>
#include <mutex>

//Exercise 1
void SumValues(int values[], int firstIndex, int lastIndex, int &result)
{
	for (int i = firstIndex; i < lastIndex; ++i)
	{
		result += values[i];
	}
}

void Exercise1()
{
	//Exercise 1
	int values[100];

	for (int i = 0; i < 100; ++i)
	{
		values[i] = i;
	}

	int sum1 = 0;
	int sum2 = 0;

	std::thread thread1(&SumValues, values, 0, 50, std::ref(sum1));
	std::thread thread2(&SumValues, values, 50, 100, std::ref(sum2));

	thread1.join();
	thread2.join();

	int sum3 = sum1 + sum2;

	std::cout << sum3 << std::endl;

}

//Excersice 2
// Used to protect writing to the vector
std::mutex vectLock;
std::vector<unsigned int> primeVect;

void FindPrimes(unsigned int start,
	unsigned int end) {

	// Cycle through numbers while ignoring evens
	for (unsigned int x = start; x <= end; x += 2) {

		// If a modulus is 0 we know it isn't prime
		for (unsigned int y = 2; y < x; y++) {
			if ((x % y) == 0) {
				break;
			}
			else if ((y + 1) == x) {
				vectLock.lock();
				primeVect.push_back(x);
				vectLock.unlock();
			}
		}
	}
}

void FindPrimesWithThreads(int firstEl, int lastEl, int numThreads) 
{
	std::vector<std::thread> threadsVec;

	int threadSpread = lastEl / numThreads;
	int newLastEl = firstEl + threadSpread - 1;

	for (int x = 0; x < numThreads; x++) 
	{
		threadsVec.emplace_back(FindPrimes, firstEl, newLastEl);

		firstEl += threadSpread;
		newLastEl += threadSpread;
	}

	for (auto& t : threadsVec) 
	{
		t.join();
	}
}

int Exercise2()
{
	std::vector<unsigned int> primeVect;

	int startTime = clock();

	FindPrimes(1, 100000);

	// Get time after execution
	int endTime = clock();

	std::cout << "Execution Time : " <<
		(endTime - startTime) / double(CLOCKS_PER_SEC) << std::endl;

	startTime = clock();

	FindPrimesWithThreads(1, 100000, 5);

	endTime = clock();

	std::cout << "Execution Time : " <<
		(endTime - startTime) / double(CLOCKS_PER_SEC) << std::endl;

	return 0;
}

int main()
{
	Exercise1();
	Exercise2();
	system("pause");
	return 0;
}




