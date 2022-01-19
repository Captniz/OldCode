// NOTE: it is recommended to use this even if you don't understand the following code.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// constraints
#define MAXN 100000

// input data
int N, i;
int A[MAXN], B[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(2 == scanf("%d %d", &A[i], &B[i]));

    // insert your code here
    
    printf("%s\n", "YES"); // print the result
    return 0;
}
