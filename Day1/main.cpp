#include <iostream>
#include <vector>

/*
Problem 1: Maximum sub - array sum
To find the largest possible sum of a sequence of consecutive values in the array
*/
int main()
{
	using namespace std;
	vector<int> arr{ {-1,2,4,-3,5,2,-5,2} };

	//Best Alg: Kadane's Alg.

	auto best{ 0 };
	auto sum{ 0 };
	for (int k = 0; k < arr.size(); ++k)
	{
		sum = max(arr[k], sum + arr[k]);
		best = max(best, sum);
	}

	cout << best << "\n";
	return 0;


}

