#include "squiggle_c/squiggle.h"
#include "squiggle_c/squiggle_more.h"

#define THOUSANDS 1000
#define MILLIONS (1000 * 1000)
#define BILLIONS (1000 * 1000 * 1000)

double cost_effectiveness_technical_ai_safety_community_if_positive(uint64_t* seed){
    double size_technical_ai_safety_community = sample_to(0.3, 10, seed); // THOUSANDS
    // There aren't that many people working on AI safety by that name. 
    // An estimate from 80.000 hours from 2022 (<https://80000hours.org/problem-profiles/artificial-intelligence/>, <https://web.archive.org/web/20240111114303/https://80000hours.org/problem-profiles/artificial-intelligence/>, <https://docs.google.com/spreadsheets/d/1e1Vh_nK_7VHKZUuQ9VNp3JWC2etjUAHVmVXbKarKMNw/edit#gid=2002428038>) puts the number of full time equivalent people working in AI safety as ranging from 100 to 800. 
    // That estimate has the upside of going organization by organization
    // But it is from 2022.
    // Also broader interest in AI safety, and research that is applicable to AI safety even if it doesn't go by that point;
    // see a post which makes this point here: <https://forum.effectivealtruism.org/posts/8ErtxW7FRPGMtDqJy/the-academic-contribution-to-ai-safety-seems-large> (<https://forum.nunosempere.com/posts/8ErtxW7FRPGMtDqJy/the-academic-contribution-to-ai-safety-seems-large> loads faster but might not exist over the longer term.
    double reduction_xrisk_due_to_technical = sample_beta(0.6946700156842451, 117.51307620479153, seed);
    // 0.01% to 2%, from <https://nunosempere.com/blog/2023/03/15/fit-beta/>
    // super wide estimate, though
    double average_cost_per_person = sample_to(70, 150, seed); // THOUSANDS.
      // uncertainty over the *average* salary
      // the distribution over individual salaries would be much wider; maybe 30 to 250k
    double average_career_duration = sample_to(3, 7, seed); // years
      // distribution over individuals would be like, half a year to 10 years
      // distribution over the average is lower
    double cost_per_basis_point_in_millions = size_technical_ai_safety_community * average_cost_per_person * average_career_duration / (reduction_xrisk_due_to_technical * (10 * THOUSANDS));
    // 10 * THOUSANDS = THOUSANDS * THOUSANDS * (0.01/100) / MILLION
    // the first thousands are keeping track of units
    // the second are because of the basis points
    return cost_per_basis_point_in_millions;
}
