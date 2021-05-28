
//
// File: moving_average.cpp
//
//
//  g++ -std=c++20 -O3 -Wall -Wextra -o moving_average.exe moving_average.cpp
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

// Here is an example stream of integers which could be provided to your code via AddSample:
// 8, 6, 19, 6, 12, 16, 11, 14, 17, 16, 16, 19, 4, 19, 4, 10, 4, 10, 2, 16

// If GetAverage were called after each call to AddSample above (assuming W = 10), it would be expected to return the following output:
// 0, 1, 3, 3, 5, 6, 7, 9, 10, 12, 13, 14, 13, 14, 13, 13, 12, 11, 10, 10

using IntVector = vector<int>;

class NumStream {
public:
	void AddSample(int val);
	int GetAverage();
private:
        IntVector myFifo;
	int W {10};
};

auto NumStream::AddSample(int val) -> void
{
	myFifo.emplace_back(val);

	if ((int)myFifo.size() > W) {
		myFifo.erase(myFifo.begin());	// remove the last most element; top of stack
	}
}

auto NumStream::GetAverage() -> int
{
//    int sum = accumulate(begin(myFifo), end(myFifo), 0);
//    return (sum / W);       // successful
    return (accumulate(begin(myFifo), end(myFifo), 0) / W);
}

int main()
{
	NumStream numStream;

    // the iterator constructor can also be used to construct from arrays:
    int myints[] = { 8, 6, 19, 6, 12, 16, 11, 14, 17, 16, 16, 19, 4, 19, 4, 10, 4, 10, 2, 16 };
    IntVector nums(begin(myints), end(myints));

    cout << "inputs to calculate moving average" << endl;

    for (auto iter : nums) {
        cout << iter << " ";
    }
    cout << endl;

    cout << "moving average" << endl;
    for (auto iter : nums) {
        numStream.AddSample(iter);
        int retVal = numStream.GetAverage();
        cout << retVal << " ";
    }
    cout << endl;

        return 0;
}

