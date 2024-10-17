#include "squiggle_c/squiggle.h"
#include "squiggle_c/squiggle_more.h"
#include "../1-thresholds/0-thresholds-from-first-principles/c/bounds.h"
#include "../1-thresholds/2-ai-community-threshold/c/ai-community.h"
#include "../2-cser/2-ai-existential-risk-uk/ai-existential-risk-uk.h"
#include "../2-cser/3-conditional-impact-cser/conditional_impact.h"
#include "../2-cser/4-funging-adjustments/funging_model.h"
#include "../2-cser/5-value-cser-bps/model.h"
#include <stdio.h>
#include <stdlib.h>

// double low_bound_willingness_to_pay_basis_point(uint64_t* seed);
// double high_bound_willingness_to_pay_basis_point(uint64_t* seed);
// double cost_effectiveness_technical_ai_safety_community_if_positive(uint64_t* seed);
// double sample_value_cser_bps(uint64_t * seed);

int main()
{
    int n_samples = 1 * MILLION;
    int n_threads = 16;
    double* array_cost_effectiveness_cser_bps_per_million = malloc((size_t)n_samples * sizeof(double));
    sampler_parallel(sample_cost_effectiveness_cser_bps_per_million, array_cost_effectiveness_cser_bps_per_million, n_threads, n_samples);

    // CSER cost effectiveness 
    printf("\n# Cost-effectiveness of CSER's AI group, in basis points of existential risk averted per million: \n");
    printf("\nStats: \n");
    array_print_stats(array_cost_effectiveness_cser_bps_per_million, n_samples);
    int n_bins = 20;
    printf("\nHistogram: \n");
    array_print_90_ci_histogram(array_cost_effectiveness_cser_bps_per_million, n_samples, n_bins);

    // Lower bound
    double* array_lower_bound_bps_per_million = malloc((size_t)n_samples * sizeof(double));
    double sample_lower_bound_bps_per_million(uint64_t* seed){
        return 1/(low_bound_willingness_to_pay_basis_point(seed) / MILLION);
        // return low_bound_willingness_to_pay_basis_point(seed);
    }
    sampler_parallel(sample_lower_bound_bps_per_million, array_lower_bound_bps_per_million, n_threads, n_samples);

    printf("\n# Threshold based on first principles (bp/million higher than this is very good): \n");
    printf("\nStats: \n");
    array_print_stats(array_lower_bound_bps_per_million, n_samples);
    printf("\nHistogram: \n");
    array_print_90_ci_histogram(array_lower_bound_bps_per_million, n_samples, n_bins);

    // Comparison between CSER and the lower bound
    double sample_comparison_lower_bound(uint64_t* seed){
        return sample_cost_effectiveness_cser_bps_per_million(seed) - sample_lower_bound_bps_per_million(seed); // could also divide and see if this greater than 1
    }
    double* array_comparison_lower_bound = malloc((size_t)n_samples * sizeof(double));

    sampler_parallel(sample_comparison_lower_bound, array_comparison_lower_bound, n_threads, n_samples);

    printf("\n# CSER value – first principles threshold (higher than 0 is good): \n");
    printf("\nStats: \n");
    array_print_stats(array_comparison_lower_bound, n_samples);
    printf("\nHistogram: \n");
    array_print_90_ci_histogram(array_comparison_lower_bound, n_samples, n_bins);

    // AI safety community bound
    printf("\n# Threshold based on prudent spending in the AI safety community (bp/million higher than this means there isn't a readily available Pareto improvement): \n");
    double* array_prudent_ai_community_bps_per_million = malloc((size_t)n_samples * sizeof(double));
    double sample_prudent_ai_community_bps_per_million(uint64_t* seed){
        return 1/cost_effectiveness_technical_ai_safety_community_if_positive(seed);
    }
    sampler_parallel(sample_prudent_ai_community_bps_per_million, array_prudent_ai_community_bps_per_million, n_threads, n_samples);
    printf("\nStats: \n");
    array_print_stats(array_prudent_ai_community_bps_per_million, n_samples);
    printf("\nHistogram: \n");
    array_print_90_ci_histogram(array_prudent_ai_community_bps_per_million, n_samples, n_bins);


    // Comparison with AI safety community bound
    double sample_comparison_prudent_ai_community(uint64_t* seed){
        return sample_cost_effectiveness_cser_bps_per_million(seed) - sample_prudent_ai_community_bps_per_million(seed); // could also divide and see if this greater than 1
    }
    double* array_comparison_prudent_ai_community = malloc((size_t)n_samples * sizeof(double));

    sampler_parallel(sample_comparison_prudent_ai_community, array_comparison_prudent_ai_community, n_threads, n_samples);

    printf("\n# CSER value – AI community threshold (higher than 0 is good): \n");
    printf("\nStats: \n");
    array_print_stats(array_comparison_prudent_ai_community, n_samples);
    printf("\nHistogram: \n");
    array_print_90_ci_histogram(array_comparison_prudent_ai_community, n_samples, n_bins);
    
    // free
    free(array_cost_effectiveness_cser_bps_per_million);
    free(array_lower_bound_bps_per_million);
}
