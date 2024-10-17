#include "squiggle_c/squiggle.h"
#include "squiggle_c/squiggle_more.h"
#include "../2-ai-existential-risk-uk/ai-existential-risk-uk.h"
#include "../3-conditional-impact-cser/conditional_impact.h"
#include "../4-funging-adjustments/funging_model.h"
#include <stdio.h>
#include <stdlib.h>


double sample_value_cser_bps_no_funging(uint64_t * seed){
    double ai_existential_risk_uk = sample_ai_existential_risk_uk(seed);
    double conditional_impact_cser = sample_conditional_impact_cser(seed);

    double value_cser_bps_uk = ai_existential_risk_uk * conditional_impact_cser / (0.01/100);

    double international_influence_multiplier = 1 + sample_beta(1.9872200324266, 6.36630125578423, seed);
    // 5% to 50% more. Influence in China seems particularly valuable, influence in the Vatican less so
    // I think, internally, CSER people, and the UK as a nation, believes that the UK has an outsize influence
    // and things like the AI summit do seem to confirm that
    // however, I think it would be easy to overstate that, and I think that the value here is going to be some fraction of the value at home, rather than many multiples of it.
    double value_cser_bps_international = value_cser_bps_uk * international_influence_multiplier;

    int n_dists = 2;
    double weights[] = { 0.2, 0.8 };
    double sample_relative_value_current_personnel(uint64_t * seed) { UNUSED(seed); return 1; }
    double sample_relative_value_marginal_new_person(uint64_t * seed){ return sample_beta(3,2, seed); }
    double (*samplers[])(uint64_t*) = { sample_relative_value_current_personnel, sample_relative_value_marginal_new_person};
    double marginal_room_for_funding_multiplier = sample_mixture(samplers, weights, n_dists, seed);
    // how valuable should we expect subsequent hires to be, as a fraction of the value of current hires?
    // I'm very confused about this variable, and about whether I should even be trying to model it here. 
    // It's also possible that more funding could be used to prevent people of the current caliber from leaving, 
    // e.g. Maathis Maas.
    double value_cser_bps = value_cser_bps_international * marginal_room_for_funding_multiplier;
    return value_cser_bps; 
}

double sample_value_cser_bps(uint64_t * seed){

    double value_cser_bps = sample_value_cser_bps_no_funging(seed) * sample_relative_value_after_funging(seed);
    return value_cser_bps; 
}


double sample_cost_effectiveness_cser_bps_per_million_no_funging(uint64_t * seed){
    double cost_cser_millions = 6 * 5 * 0.1; 
    // 6 people/year for 100k each for 5 years
    // this is the AI part of CSER
    // keep as constant for now before getting more data 
    double value_cser_bps_per_million = sample_value_cser_bps_no_funging(seed)/cost_cser_millions;
    return value_cser_bps_per_million;
}

double sample_cost_effectiveness_cser_bps_per_million(uint64_t * seed){
    double cost_cser_millions = 6 * 5 * 0.1; 
    // 6 people/year for 100k each for 5 years
    // this is the AI part of CSER
    // keep as constant for now before getting more data 
    double value_cser_bps_per_million = sample_value_cser_bps(seed)/cost_cser_millions;
    return value_cser_bps_per_million;
}
