#include <iostream>
#include <vector>
using namespace std;

int str[] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

int main() {
	string A, B;
	cin >> A >> B;

	vector <int> check;
	for (int i = 0; i < A.size(); i++)
	{
		check.push_back(str[A[i] - 'A']);
		check.push_back(str[B[i] - 'A']);
	}
	while (1)

	{

		vector<int> temp;

		for (int i = 0; i < check.size() - 1; i++)

			temp.push_back((check[i] + check[i + 1]) % 10);



		check = temp;

		if (check.size() == 2)

			break;

	}
	cout << check[0] << check[1] << endl;
	return 0;
}