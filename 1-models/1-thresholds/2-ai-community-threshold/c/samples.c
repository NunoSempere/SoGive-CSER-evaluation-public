#include "squiggle_c/squiggle.h"
#include "squiggle_c/squiggle_more.h"
#include "ai-community.h"
#include <stdio.h>
#include <stdlib.h>

#define THOUSANDS 1000
#define MILLIONS (1000 * 1000)
#define BILLIONS (1000 * 1000 * 1000)

int main()
{

    int n_samples = 1 * MILLIONS;
    int n_threads = 16;
    double* samples = malloc(sizeof(double) * (size_t) n_samples);
    sampler_parallel(cost_effectiveness_technical_ai_safety_community_if_positive, samples, n_threads, n_samples);
    printf("\nStats: \n");
    array_print_stats(samples, n_samples);
    printf("\nHistogram: \n");
    array_print_90_ci_histogram(samples, n_samples, 20);

    FILE *fp;
    fp = fopen("samples_ai_community.txt", "w");// "w" = write. destructive
    for(int i=0; i<n_samples; i++){
        fprintf(fp, "%lf\n", 1.0/samples[i]);
    }
    fclose(fp); //Don't forget to close the file when finished
}
