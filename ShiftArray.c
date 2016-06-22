#include <stdio.h>
#include <string.h>

typedef struct Result {
	int A[100];
	int N;
} Res;

Res solution(int A[], int N, int K) {
    Res result;
    // write your code in C99 (gcc 4.8.2)

    //Mimimera antalet rotationer.
    if (N == 0 || K == 0 || K == N)
    {
    	memcpy(result.A, A, N * sizeof(int));
        result.N = N;
        return result;
    }

    if (K > N)
    {
        K = K % N;
    }

    int A2[N];
    int x;
    for (x = 0; x < N; ++x)
    {
        if (x+K < N)
        {
            A2[(x+K) % N] = A[x];
        }
    }

    //void *memcpy(void *str1, const void *str2, size_t n)
    void* ret = memcpy(A, A2, N * sizeof(int));

    memcpy(result.A, A, N * sizeof(int));
    result.N = N;
    return result;
}


int main(){
	Res res;
	int A[] = {1,2,3};
	int K = 1;
	int N = 3;
	res = solution(A, N, K);
}
