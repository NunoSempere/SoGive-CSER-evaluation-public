Review of estimation strategies
===============================

## 1. Summary

Items in this table are ordered from ideal but intractable (top) to easily doable but missing desiderata (bottom). I think the sweet spot falls in items 4. to 7. 

| Strategy                          | Feasible?             | Recommended?  | Commentary | 
| ----------------------------------| --------------------- | ------ | ----------------- |
| 1. Randomized trial               | Impossible            | No     | Ideal in global development |
| 2. Shapley values                 | Even more impossible  | No     | Theoretically elegant, computationally intractable |
| 3. Natural experiments            | Unlikely              | No     | Would be good to have, but it seems unlikely I'd find one | 
| 4. Directly reduction in x-risk   | With effort           | Maybe  | Highly experimental and speculative, but ideal if one can achieve them |
| 5. Relative value comparison      | Yes                   | Maybe  | It does captures participants' intuitions of value. But is time-intensive, and it can be untransparent without even more effort |
| 6. Midway unit estimation         | Yes                   | Yes    | Incomplete step towards estimating value, yet very doable |  
| 7. Sanity checks                  | Yes                   | Yes    | Cheap and useful step towards estimating x-risk. Could be the only thing that is needed | 
| 8. Impact rubric                  | Yes                   | No     | Does not allow comparing options; two items with the same impact rubric score can be very differently valuable. Better than nothing but we can do better | 
| 9. Expert intuition               | Yes                   | No     | Good as an input into other options, but it seems unadvisable to rely on it on its own | 
| 10. Other funders as a benchmark  | Yes                   | No     | Other funders don't seem to be doing much estimation, and they are each subject to idiosyncratic concerns. Also leads to game of chicken dynamics and recursion problems. | 

## 2. Note on methodology

Taking into account the constraints of this project, I'm making the following judgment calls for this review:

- Keep it short and casual. The trappings of academic norms don't seem worth the overhead.
- Mostly focused on past EA work, at first. Will fix and improve as I go on.
- Meant to inform my research plan, rather than be 

## 3. Ideal yet impracticable

These are strategies which are unworkable. However, they represent an aspiration: they are what other methods will seek to approximate.

### 3.1. Randomized controlled trial

If we could have a treatment group Britain and a control group Britain, we could look at how they differed, and estimate the value of CSER based on that. This is the gold-standard in global health and development. 

### 3.2. Shapley values

Still, randomized trials and other methods of estimating the counterfactual value of a project suffer from double counting or triple-counting impact. [Shapley values](https://forum.nunosempere.com/posts/XHZJ9i7QBtAJZ6byW/shapley-values-better-than-counterfactuals) address this, but at the cost of being even more impossible for the purposes of estimating x-risk reduction and their value. If with RTCs we had to boot up two universes, this time we'd have to boot up a large number of universes, to see what share of impact corresponds to each actor.

We *could* estimate each of the components in the Shapley value formula. However, in practice, I think that the sweet spot is in remembering that counterfactuals are imperfect, and in making an adjustment where many people are working together. 

### 3.3 Natural experiments

If we didn't have a control group, but something similar enough, we could do the same analysis we would do for a randomized trial, but using organic data. For instance, if CSER had a fellowship, we could look at fellows right above and right below their bar for acceptance, and see if those who were barely accepted did better or worse than those who didn't. Most often, you don't find a (well-powered, etc.) natural experiment, and even if you do, you might still worry about unobserved cofounders. Still, the hope is that you could stumble into something which unarguably has the same explanatory power as an RTC.

## 4. Sweet spot of feasibility, informativeness, ambitiousness

### 4.1. Directly estimate reduction in x-risk

Estimate how much catastrophic or existential risk they avoid. This is going to be gnarly; how would you estimate a, say, 0.004% reduction in existential risk? Well, you could look at the pathway to impact of their activities, estimate their chances of success, and their impact if successful. Even if you do this estimation, and you become convinced of its validity, others might not have confidence in it.

Still, direct existential risk estimation seems enticing, and a good target for ambitious estimation. The result will be very speculative and uncertain. But even if they are, they do provide a straightforward point of comparison.

### 4.2. Relative value comparison

We could ask several people about how much they value different interventions relative to each other, as in [here](https://forum.nunosempere.com/posts/EPhDMkovGquHtFq3h/an-experiment-eliciting-relative-estimates-for-open) or [here](https://forum.nunosempere.com/posts/9hQFfmbEiAoodstDA/simple-comparison-polling-to-create-utility-functions). From these estimates, we can construct a linear scale and then place the different interventions in it to represent how much we value them relative to each other.

The academic literature has explored similar methods, under the keyword "discrete choice theory". However, they typically ask about binary choices, not about estimates of distributional relative value. Their objective is sometimes to estimate the value of features, e.g., of a renovated bathroom or bigger windows in the market for houses in a given city.

### 4.3. Midway point estimation

Instead of estimating points of existential risk averted, you could estimate some intermediate outcome, like quality and influence-adjusted...

- ...research papers
- ...research insights
- ...policy engagement
- ...mentoring

Each of these is a proxy for the ultimate impact. And we'd hope that these proxies scale roughly linearly. Or that if some organization has better proxies than another organization, they will be better overall.

### 4.4. Sanity checks and thresholds for making decisions

We could remember that ultimately, we want to make some decision—whether to fund some project or not. Are there any thresholds which would immediately resolve that?

- Is the project strictly worse or strictly better than some other project that we could fund instead?
- Is the organization not doing anything at all?
- Is the organization absurdly cost-inefficient?
- Is the organization absurdly cost-effective?

## 5. Current status quo

### 5.1. Comparison against other funders' thresholds

Look at the marginal grant for the, say, LTFF, and try to ascertain whether another project would meet that bar or not.

### 5.2. Construct an impact rubric

Look at some 

### 5.3. Rely on expert intuition

Ask people related to an ecosystem whether a project is "good" or not

## 5 Understanding the nature of the problem deeply vs building a model top down

## 6. Review of strategies for estimating value

My sense is that the sweet stop is for strategies in section 4. Start with sanity checks, scale up to estimating midway outcomes, and then attempt direct risk estimation if we have enough time. Partly as a point of professional pride, I consider methods in section 5 as inferior: they can be better than nothing, but I think we can do much better. I am actually pretty surprised that Charity Entrepeneurship is using rubrics, though my sense is that they are changing that.

## 7. Wrangling these estimates into a threshold

Here are some questions that one could be asking:

1. How much value does CSER produce?
2. How much value do each in a limited number of organizations produce?
3. Of a limited list of options under consideration, how should one allocate a $500K donation in 2024?
4. Of all the options available to donate $500K in 2024, which is the best?
5. As a community, what threshold should EA have such that it should be willing to fund projects above that threshold in 2024?
6. As a community, how should EA dynamically allocate its funding? What is the function that defines what its threshold should be each year?

Note that as you start going above #2, you start to encounter considerations around [multi-armed bandit](https://en.wikipedia.org/wiki/Multi-armed_bandit), e.g., you ideally want to consider the value of information of donations. 

As you reach #5, you need to start to consider community dynamics. My preference here is to be somewhat adversarial against Open Philanthropy, i.e., to only consider options that they wouldn't fund, rather than being happy to funge against their funding. This is because I think that they are subject to weird constraints, and that they make decisions at a past pace, so a smaller but more reflective funder should be able to beat them.

As you reach #6, you encounter a gnarly allocation problem. Some related work [here](https://globalprioritiesinstitute.org/wp-content/uploads/Trammell-Dynamic-Public-Good-Provision-under-Time-Preference-Heterogeneity.pdf) and [here](https://docs.google.com/document/d/1NcfTgZsqT9k30ngeQbappYyn-UO4vltjkm64n4or5r4/edit).

As I see it, what make sense for me to do is to start down that list, and deal with each item with enough clarity that it can serve as a reference for others. I imagine that I will deal with points 2-3, which leaves points 3-6 up to more hollistic strategic decisions. In particular, I'm thinking that I will explore how to estimate CSER's value using the methods in section 4, with some granularity, then apply the methods learnt to a finite list of options, with some granularity but with much less granularity than for CSER, and then put the two together using my judgment to make a recommendation.

---

