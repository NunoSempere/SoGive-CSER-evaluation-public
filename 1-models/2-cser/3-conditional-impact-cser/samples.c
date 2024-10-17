#include "squiggle_c/squiggle.h"
#include "squiggle_c/squiggle_more.h"
#include "conditional_impact.h"
#include <stdio.h>
#include <stdlib.h>
#define MILLION (1000 * 1000)

int main()
{
    int n_samples = 1 * MILLION;
    int n_threads = 16;
    double* results = malloc((size_t)n_samples * sizeof(double));
    sampler_parallel(sample_conditional_impact_cser, results, n_threads, n_samples);

    printf("\n# Share of UK existential risk reduced by CSER\n");
    printf("\nStats: \n");
    array_print_stats(results, n_samples);
    int n_bins = 50;
    printf("\nHistogram: \n");
    array_print_histogram(results, n_samples, n_bins);

    free(results);
}
