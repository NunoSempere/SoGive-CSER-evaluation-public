#include "squiggle_c/squiggle.h"
#include "squiggle_c/squiggle_more.h"
#include <stdio.h>
#include <stdlib.h>

#define THOUSANDS 1000
#define MILLIONS (1000 * 1000)
#define BILLIONS (1000 * 1000 * 1000)

int main()
{
    // set randomness seed
    uint64_t* seed = malloc(sizeof(uint64_t));
    *seed = 1000; // xorshift can't start with 0
    
    // Estimate upper bound

    /* Assuming that LTFF donations are positive */
    printf("#1. Assuming that LTFF donations must be positive\n");
    printf("Based on the impression that a donor should be willing to either beat the LTFF or donate to it...\n");

    double ltff_bound_willingness_to_pay_basis_point_if_ltff_positive(uint64_t* seed){
        double size_of_xrisk_community = sample_to(500, 20 * THOUSANDS, seed); 
        // partly this is a definitional question. Do we include anyone who has worked on any xrisk, like e.g., nuclear or possibly climate? Do we include researchers whose work might have xrisk implications, or who are doing pragmatic alignment on LLMs inside LLM companies? Partly this is a fuzzy quantity because it's a fuzzy domain to reason about.
        double reduction_in_xrisk_due_to_community = sample_beta(0.6946700156842451, 117.51307620479153, seed);
        // if the xrisk community did not exist, my guess is that xrisk would be 0.01% to 2% higher? I really don't know
        // to do: this assumes that the xrisk community is positive. But that might not be the case
        // I'm not sure how to deal with that case. Also if that is not the case we don't really have a threshold.
        // mmhh.
        double mean_reduction_in_xrisk_per_researcher = reduction_in_xrisk_due_to_community / size_of_xrisk_community;
        double reduction_in_xrisk_per_marginal_ltff_grantee = sample_to(0.05, 10, seed) * mean_reduction_in_xrisk_per_researcher;
        double cost_marginal_ltff_grantee = sample_to(40 * THOUSANDS, 120 * THOUSANDS, seed);
        // using my gut feeling, best judgment
        double result = cost_marginal_ltff_grantee / reduction_in_xrisk_per_marginal_ltff_grantee;
        return result;
    }

    ci ltff_bound_ci90_if_positive = sampler_get_ci((ci) { .low = 0.05, .high = 0.95 }, ltff_bound_willingness_to_pay_basis_point_if_ltff_positive, 1000000, seed);

    printf("a rough higher bound of how much one should be willing to pay for 1 basis point of xrisk reduction is [%.2fB, %.2fB]\n", ltff_bound_ci90_if_positive.low/BILLIONS, ltff_bound_ci90_if_positive.high/BILLIONS);

    printf("\n");
    /* Don't necessarily assume that LTFF donations can be positive */
    printf("#2. Not assuming that LTFF donations must be positive\n");
    printf("Based on the impression that a donor should be willing to either beat the LTFF or donate to it...\n");

    double ltff_bound_willingness_to_pay_basis_point(uint64_t* seed){
        double size_of_xrisk_community = sample_to(500, 20 * THOUSANDS, seed); 
        // partly this is a definitional question. Do we include anyone who has worked on any xrisk, like e.g., nuclear or possibly climate? Do we include researchers whose work might have xrisk implications, or who are doing pragmatic alignment on LLMs inside LLM companies? Partly this is a fuzzy quantity because it's a fuzzy domain to reason about.
        double reduction_in_xrisk_due_to_community = sample_beta(0.6946700156842451, 117.51307620479153, seed);
        // if the xrisk community did not exist, my guess is that xrisk would be 0.01% to 2% higher? I really don't know
        // to do: this assumes that the xrisk community is positive. But that might not be the case
        // I'm not sure how to deal with that case. Also if that is not the case we don't really have a threshold.
        // mmhh.
        double mean_reduction_in_xrisk_per_researcher = reduction_in_xrisk_due_to_community / size_of_xrisk_community;
        double reduction_in_xrisk_per_marginal_ltff_grantee = sample_normal_from_90_ci(-1, 5, seed) * mean_reduction_in_xrisk_per_researcher;
        double cost_marginal_ltff_grantee = sample_to(40 * THOUSANDS, 120 * THOUSANDS, seed);
        // using my gut feeling, best judgment
        double result = cost_marginal_ltff_grantee / reduction_in_xrisk_per_marginal_ltff_grantee;
        return result;
    }

    int n_threads = 16;
    size_t n_samples = 1 * MILLIONS;
    double* results = malloc(n_samples * sizeof(double));

    sampler_parallel(ltff_bound_willingness_to_pay_basis_point, results, n_threads, n_samples);
    double ltff_mean_value = array_mean(results, n_samples);
    ci ltff_bound_ci90 = array_get_ci((ci) { .low = 0.05, .high = 0.95 }, results, n_samples);
    ci ltff_bound_ci50 = array_get_ci((ci) { .low = 0.5, .high = 0.51 }, results, n_samples);

    printf("a rough higher bound of how much one should be willing to pay for 1 basis point of xrisk reduction is [%.2fB, %.2fB]; mean: %.2fB, median: %.2fB\n", ltff_bound_ci90.low/BILLIONS, ltff_bound_ci90.high/BILLIONS, ltff_mean_value/BILLIONS, ltff_bound_ci50.low/BILLIONS);

    // free seed
    free(seed);
}
