#include "squiggle_c/squiggle.h"
#include "squiggle_c/squiggle_more.h"
#include <stdio.h>
#include <stdlib.h>

/*

In my interview with Sean, he mentions a number of policy impact over the last few years:

- 2021 National AI Strategy
- Future Proof report
- Talks with Ministers; National Resilience Strategy, National AI strategy
- Reduced group-think
- Secondments: Hayden Belfield, Shahar Avin
- Open letters
- UK AI safety institute
- Frontier Model task force
  - Workshop for evaluation
  - Pushing for a different lead
- Advising Matt Clifford & others
- AI summit
- Inviting China to AI Summit
- OECD working group
- Foreign and Commonwealth Office
- China; Tsinghua and PKU and the Chinese Academy of Sciences
- Risks from open source report
- etc.

However, he takes care to mention that these are collaborative, and that the social proof that having many people providing the same suggestion increases its chances of adoption.

*/

double sample_conditional_impact_cser(uint64_t * seed){
  // Conditional on there otherwise being AI existential risk in the UK,
  // what is the chance that it's averted because of CSER?
  
  // Conditional on there otherwise being AI existential risk in the UK,
  // what is the chance that it's averted because of the general
  // AI risk community?
  double share_uk_risk_reduced_uk_community = sample_beta(1.86052521618428, 2.46603754984314, seed);
  // 0.1 to 0.8

  // What fraction of that can be attributed to CSER specifically?
  // Orgs: FHI, CSER, GovAI, CLTR, Apollo, etc. which are downstream of e.g., the UK AI institute
  double fraction_cser = sample_beta(2.53017245520986, 7.36092868549274, seed); 
  // 0.07 to 0.5 (7% to 50%)
  // (Not considered: less than 0%.)
  // Case for 7%: other orgs were already enough, CSER could have been kinda incompetent
  // Median case: around 25%; there are 3-4 orgs, CSER gets around 1/4th of the credit
  // Case for 50%: CSER could be particularly well connected, and particularly crucial after the reputational blow to FHI due to its various scandals 
  double conditional_impact_cser = share_uk_risk_reduced_uk_community * fraction_cser;
  return conditional_impact_cser;
}

