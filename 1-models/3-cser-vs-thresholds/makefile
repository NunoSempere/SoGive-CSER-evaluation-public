# Threshold models
FIRST_PRINCIPLES=../1-thresholds/0-thresholds-from-first-principles/c/bounds.c
AI_COMMUNITY_THRESHOLD=../1-thresholds/2-ai-community-threshold/c/ai-community.c
THRESHOLDS=$(FIRST_PRINCIPLES) $(AI_COMMUNITY_THRESHOLD)

# CSER model
UK_AI_RISK=../2-cser/2-ai-existential-risk-uk/ai-existential-risk-uk.c
CSER_CONDITIONAL_IMPACT=../2-cser/3-conditional-impact-cser/conditional_impact.c
FUNGING=../2-cser/4-funging-adjustments/funging_model.c
CSER_MODEL=../2-cser/5-value-cser-bps/model.c
CSER_MODELS=$(UK_AI_RISK) $(CSER_CONDITIONAL_IMPACT) $(FUNGING) $(CSER_MODEL)

OUTPUT=./samples

build:
	gcc -O3 samples.c $(THRESHOLDS) $(CSER_MODELS) ./squiggle_c/squiggle.c  ./squiggle_c/squiggle_more.c -lm -fopenmp -o $(OUTPUT)

run:
	$(OUTPUT)

save:
	$(OUTPUT) > output.txt

install: 
	rm -r -f squiggle_c
	wget https://git.nunosempere.com/personal/squiggle.c/raw/branch/master/squiggle.c
	wget https://git.nunosempere.com/personal/squiggle.c/raw/branch/master/squiggle.h
	wget https://git.nunosempere.com/personal/squiggle.c/raw/branch/master/squiggle_more.c
	wget https://git.nunosempere.com/personal/squiggle.c/raw/branch/master/squiggle_more.h
	mkdir temp
	mv squiggle* temp
	mv temp squiggle_c

install-git:
	rm -r squiggle_c
	git clone https://git.nunosempere.com/personal/squiggle.c
	mv squiggle.c squiggle_c
	sudo rm -r squiggle_c/.git
