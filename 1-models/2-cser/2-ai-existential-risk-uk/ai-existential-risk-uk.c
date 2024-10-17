#include "squiggle_c/squiggle.h"
#include "squiggle_c/squiggle_more.h"
#include <stdio.h>
#include <stdlib.h>

// First look at Britain specifically
// Later, look at interactions with other countries

double sample_ai_existential_risk_uk(uint64_t * seed){
  double p_transformative_ai = sample_beta(26.5528563290474, 1.7763655277372, seed); // 85% to 99%
  // ^ seems physically possible; coordinating against is hard.
  double p_existential_conditional_transformative_ai = sample_beta(2.27126465410532, 22.5911969267949, seed); // 2% to 20%; mean 9%
  double p_existential_ai = p_transformative_ai * p_existential_conditional_transformative_ai;
  double fraction_uk = sample_beta(4.05715325375548, 25.7675530361467, seed); 
  // 1/20th to 1/4th
  // Case for 1/20th: There are many cutting edge labs: OpenAI, DeepMind, Inflection, Anthropic, StabilityAI, Mistral, Facebook AI, Baidu/Tencent/Beijing Academy, Grok. More importantly, more are popping up, so it might even be predominantly likely that the winner is an organization that hasn't been founded yet.
  // Case for 1/4th: Truly cutting edge labs are OpenAI and DeepMind. DeepMind's influence divided half and half between UK and US (of its recent jobs page, which seems a reasonable proxy, about half of jobs are in the UK, half in the US.)
  // Useful ressource: <https://epochai.org/data/epochdb/table>
  double p_existential_ai_uk = p_transformative_ai * p_existential_conditional_transformative_ai * fraction_uk;
  return p_existential_ai_uk;
}
