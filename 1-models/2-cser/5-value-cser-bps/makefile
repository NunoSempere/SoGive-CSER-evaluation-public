UK_AI_RISK=../2-ai-existential-risk-uk/ai-existential-risk-uk.c
CSER_CONDITIONAL_IMPACT=../3-conditional-impact-cser/conditional_impact.c
FUNGING=../4-funging-adjustments/funging_model.c
OUTPUT=./samples

build:
	gcc -O3 samples.c model.c $(UK_AI_RISK) $(CSER_CONDITIONAL_IMPACT) $(FUNGING) ./squiggle_c/squiggle.c  ./squiggle_c/squiggle_more.c -lm -fopenmp -o $(OUTPUT)

build-no-funging:
	gcc -O3 samples_no_funging.c model.c $(UK_AI_RISK) $(CSER_CONDITIONAL_IMPACT) $(FUNGING) ./squiggle_c/squiggle.c  ./squiggle_c/squiggle_more.c -lm -fopenmp -o $(OUTPUT)_no_funging

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
