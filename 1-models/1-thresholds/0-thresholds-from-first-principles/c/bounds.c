#include "squiggle_c/squiggle.h"
#include "squiggle_c/squiggle_more.h"

#define THOUSANDS 1000
#define MILLIONS (1000 * 1000)
#define BILLIONS (1000 * 1000 * 1000)

// Based on the impression that the x-risk community should be willing to spend all of its funding to nullify existential risk...
double low_bound_willingness_to_pay_basis_point(uint64_t* seed){
    double low_bound_xrisk_funding = sample_to(3, 15, seed); // billions of dollars
    double estimated_total_xrisk = sample_beta(4.69161493088365, 22.7055822097144, seed); 
    // 7% to 30%, per <https://nunosempere.com/blog/2023/03/15/fit-beta/>
    double result = low_bound_xrisk_funding/estimated_total_xrisk * (BILLIONS * (0.01/100)); 
    // compute (BILLIONS * (0.01/100)) like that for numerical stability
    return result;
}

// Based on the impression that humanity can't really spend all its future at once...
double high_bound_willingness_to_pay_basis_point(uint64_t* seed){
    double people = sample_to(10 , 100, seed); // in MILLIONS
    double cost_per_person = sample_to(20, 200, seed); // in THOUSANDS
    double duration = sample_to(5, 50, seed);
    double result = people * cost_per_person * duration * (MILLIONS * THOUSANDS * (0.01/100));
    // compute MILLIONS * THOUSANDS * (0.01/100) like that for numerical stability
    return result;
}
