#include "squiggle_c/squiggle.h"
#include "squiggle_c/squiggle_more.h"
#include <stdio.h>
#include <stdlib.h>

double sample_0(uint64_t * seed) { UNUSED(seed); return 0; }
double sample_1(uint64_t * seed) { UNUSED(seed); return 1; }

double sample_relative_value_of_less_valuable_part_of_cser(uint64_t * seed){
    // relative to the value of the more valuable part

    double p_minuscule = 0.2;
    double p_not_minuscule = 0.8;
    double sample_value_if_not_minuscule(uint64_t * seed) {
        double fraction_if_not_minuscule = sample_beta(1.9872200324266, 6.36630125578423, seed);
        // ^ 90% confidence interval: 0.05 to 0.5, i.e., 5% to 50%
        return fraction_if_not_minuscule;
    }

    int n_dists = 2;
    double weights[] = { p_minuscule, p_not_minuscule };
    double (*samplers[])(uint64_t*) = { sample_0, sample_value_if_not_minuscule };
    double relative_value_of_less_valuable_part_of_cser = sample_mixture(samplers, weights, n_dists, seed);
    return relative_value_of_less_valuable_part_of_cser;
}

double sample_fraction_funged_within_cser(uint64_t * seed){
    // Chance that it fully funges
    double p_full_funge = 0.2;

    // Chance that it's not funged at all
    double p_no_funge = 0.05;

    // Degree of funging if it's funged.
    double p_some_funging = 1 - p_full_funge - p_no_funge;
    double sample_fraction_funged_if_neither_zero_nor_full_funging(uint64_t* seed){
        return sample_beta(2.23634269185645, 3.73532102339597, seed);
        // 90% confidence interval: 0.1 to 0.7
    }

    // Note that those three ^ variables can be acted upon, 
    // e.g. with some scheme so that CSER decides on an allocation before our donation
    // Still, those schemes can fail
    
    int n_dists = 3;
    double weights[]  = {p_full_funge, p_no_funge, p_some_funging};
    double (*samplers[])(uint64_t*) = { sample_1, sample_0, sample_fraction_funged_if_neither_zero_nor_full_funging};

    double fraction_funged_within_cser = sample_mixture(samplers, weights, n_dists, seed);
    return fraction_funged_within_cser;
}

double sample_relative_value_after_funging_within_cser(uint64_t* seed){
    double fraction_funged_within_cser = sample_fraction_funged_within_cser(seed);
    double relative_value = fraction_funged_within_cser * sample_relative_value_of_less_valuable_part_of_cser(seed) +
        (1-fraction_funged_within_cser) * 1; 
    return relative_value;
}

double sample_relative_value_after_funging_with_open_philanthropy(uint64_t* seed){
    double p_chance_op_would_fund_if_sogive_doesnt_fund = sample_beta(3,8, seed);
    // 3 out of every 8 such opportunities?
    double value_open_phil_marginal_grant = sample_to(0.1, 2, seed);
    // a tenth to two times as valuable as a restricted cser grant? 
    // A problem here is that uncertainty is going to be really wide, 
    // but it's not going to be well captured by a lognormal
    // leave as is for now.
    double result = p_chance_op_would_fund_if_sogive_doesnt_fund * value_open_phil_marginal_grant +
        (1-p_chance_op_would_fund_if_sogive_doesnt_fund);
    return result;
}

double sample_relative_value_after_funging(uint64_t * seed){
    double value_after_funging_within_cser = sample_relative_value_after_funging_within_cser(seed);
    return value_after_funging_within_cser;
    // double value_after_funging_with_open_philanthropy = sample_value_after_funging_with_open_philanthropy(value_after_funging_within_cser, seed);
    // return value_after_funging_with_open_philanthropy;
    // Do not include funging with Open Philanthropy for now.
}
