#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define N 2000000000

int main(int argc, char *argv[]) {

    long long int limit = N;

    if (argc == 2) {
        limit *= atoi(argv[1]);
    }

    double sum = 0;

#pragma omp parallel for default(none) shared(limit) reduction(+: sum)
    for (long long int i = 1; i <= limit; ++i) {
        sum += 1 / (1 + pow(((double) i - 0.5) / limit, 2));
    }

    printf("Pi = %f\n", 4 * sum / limit);

    return 0;
}
