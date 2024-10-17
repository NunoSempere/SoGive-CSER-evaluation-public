#include <stdio.h>
#include <stdlib.h>
#include "squiggle_c/squiggle.h"
#include "squiggle_c/squiggle_more.h"
#include "model.h"

int main()
{
    int n_samples = 1 * MILLION;
    int n_threads = 16;
    double* results = malloc((size_t)n_samples * sizeof(double));

    sampler_parallel(sample_cost_effectiveness_cser_bps_per_million_no_funging, results, n_threads, n_samples);
    printf("\n# Cost effectiveness of CSER's AI group, in basis points of existential risk averted per million: \n");
    printf("\nStats: \n");
    array_print_stats(results, n_samples);
    printf("\nHistogram: \n");
    int n_bins = 25;
    array_print_90_ci_histogram(results, n_samples, n_bins);

    FILE *fp;
    fp = fopen("samples_cost_effectiveness_cser_bps_per_million_no_funging.txt", "w");// "w" = write. destructive
    for(int i=0; i<n_samples; i++){
        fprintf(fp, "%lf\n", results[i]);
    }
    fclose(fp); //Don't forget to close the file when finished

    free(results);
}
