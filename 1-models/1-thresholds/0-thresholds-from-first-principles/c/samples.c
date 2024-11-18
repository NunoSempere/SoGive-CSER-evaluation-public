#include "squiggle_c/squiggle.h"
#include "squiggle_c/squiggle_more.h"
#include "bounds.h"
#include <stdio.h>
#include <stdlib.h>

#define THOUSANDS 1000
#define MILLIONS (1000 * 1000)
#define BILLIONS (1000 * 1000 * 1000)

int main()
{
    // set randomness seed
    int n_samples = 1 * MILLION;
    
    // Estimate lower bound
    double* low_bound_samples = malloc(sizeof(double) * (size_t) n_samples);
    sampler_parallel(low_bound_willingness_to_pay_dollars_per_basis_point, low_bound_samples, 16, n_samples);

    printf("Based on the impression that the x-risk community should be willing to spend all of its funding to nullify existential risk...\n");
    printf("a rough lower bound (in $/bp) should be...\n");
    array_print_stats(low_bound_samples, n_samples);
    printf("\n");

    FILE *fp;
    fp = fopen("samples_low_bound.txt", "w");// "w" = write. destructive
    for(int i=0; i<n_samples; i++){
        fprintf(fp, "%lf\n", low_bound_samples[i]);
    }
    fclose(fp); //Don't forget to close the file when finished


    // In bp/MILLION instead 
    printf("\nIn bp/M$ instead this is...");
    sampler_parallel(low_bound_bp_per_million, low_bound_samples, 16, n_samples);
    array_print_stats(low_bound_samples, n_samples);
    printf("\n");

    // Estimate upper bound
    double* high_bound_samples = malloc(sizeof(double) * (size_t) n_samples);
    sampler_parallel(high_bound_willingness_to_pay_dollars_per_basis_point, high_bound_samples, 16, n_samples);

    printf("Based on the impression that humanity can't really spend all its future at once...\n");
    printf("a rough higher bound of how much one should be willing to pay for 1 basis point of xrisk reduction is...\n");
    array_print_stats(high_bound_samples, n_samples);

    fp = fopen("samples_high_bound.txt", "w");// "w" = write. destructive
    for(int i=0; i<n_samples; i++){
        fprintf(fp, "%lf\n", high_bound_samples[i]);
    }
    fclose(fp); //Don't forget to close the file when finished
    
    // In bp/MILLION instead 
    printf("\nIn bp/M$ instead this is...");
    sampler_parallel(high_bound_bp_per_million, high_bound_samples, 16, n_samples);
    array_print_stats(high_bound_samples, n_samples);
    printf("\n");


}
