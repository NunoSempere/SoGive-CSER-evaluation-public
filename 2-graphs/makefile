DIR=/home/nuno/Documents/core/jobs/past/sogive-cser/SoGive-CSER-evaluation-public

graph:
	rm -rf imgs
	mkdir imgs
	r graph.R

pull:
	rm -rf samples/
	mkdir ./samples
	cp $(DIR)/1-models/2-cser/5-value-cser-bps/samples_cost_effectiveness_cser_bps_per_million.txt samples/samples_cost_effectiveness_cser_bps_per_million.txt
	cp $(DIR)/1-models/2-cser/5-value-cser-bps/samples_cost_effectiveness_cser_bps_per_million_no_funging.txt samples/samples_cost_effectiveness_cser_bps_per_million_no_funging.txt
	cp $(DIR)/1-models/1-thresholds/0-thresholds-from-first-principles/c/samples_low_bound.txt samples/samples_low_bound.txt
	cp $(DIR)/1-models/1-thresholds/2-ai-community-threshold/c/samples_ai_community.txt samples/samples_ai_community.txt
