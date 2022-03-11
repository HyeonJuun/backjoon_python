#include <iostream>
using namespace std;

void SelectionSort(int A[],int B[], int n)
{
	int i, j, MinIndex, temp;
	for (i = 0; i < n - 1; i++)
	{
		MinIndex = i;
		for (j = MinIndex + 1; j < n; j++)
			if (A[MinIndex] > A[j])
				MinIndex = j;
		if (MinIndex != i)
		{
			temp = A[i];
			A[i] = A[MinIndex];
			A[MinIndex] = temp;

			temp = B[i];
			B[i] = B[MinIndex];
			B[MinIndex] = temp;
		}
	}
}
int main()
{
	int N, i, Ti[1001] = {}, Si[1001] = {}, sum = 0, min = 1000000, gap = 0;
	bool IsPossible = true;

	cin >> N;
	for (i = 0; i < N; i++)
		cin >> Ti[i] >> Si[i];

	SelectionSort(Si, Ti, N);

	for (i = 0; i < N; i++)
	{
		sum += Ti[i];
		if (sum > Si[i])
		{
			IsPossible = false;
			break;
		}
		gap = Si[i] - sum;
		if (gap < min)
			min = gap;
	}
	IsPossible? cout << min : cout << -1;

	return 0;
}