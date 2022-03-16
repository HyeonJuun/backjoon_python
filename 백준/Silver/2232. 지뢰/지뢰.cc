#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, i, j;
	int* P;
	scanf("%d", &N);
	P = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++)
		scanf("%d", &P[i]);

	for (i = 0; i < N; i++)
	{
		if (i == N - 1 && P[i - 1] <= P[i])
			printf("%d\n",i+1);
		else if (P[i] >= P[i + 1])
		{
			printf("%d\n", i + 1);
			for (j = i; j < N - 1; j++)
				if (P[j] <= P[j + 1])
					break;
			i = j;
		}
	}

	free(P);
	return 0;
}