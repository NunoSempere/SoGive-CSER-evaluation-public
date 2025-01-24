# make build

# Filenames
INPUT=index.md
OUTPUT=cser.pdf

# Config options
PDF_ENGINE=--pdf-engine=xelatex
URL_PROPERTIES=-V colorlinks=true -V linkcolor=blue -V urlcolor=blue 
VERBOSE=--verbose
MARKDOWN_IMAGES=-f markdown-implicit_figures

build: $(OUTPUT)

$(OUTPUT): $(INPUT) header.md
	rm -rf imgs/
	cp -r ../../2-graphs/imgs imgs
	rm -f tmp.md
	cat header.md >> tmp.md && tail -n +4 $(INPUT) >> tmp.md
	# sed -i 's|##|## \\S\\thinspace|g' tmp.md
	pandoc tmp.md --output $(OUTPUT) $(PDF_ENGINE) $(URL_PROPERTIES) $(VERBOSE) $(MARKDOWN_IMAGES) --table-of-contents
	rm tmp.md

force:
	rm -rf imgs/
	cp -r ../../../2-graphs/imgs imgs
	rm -f tmp.md
	cat header.md >> tmp.md && tail -n +4 $(INPUT) >> tmp.md
	# sed -i 's|##|## \\S\\thinspace|g' tmp.md
	pandoc tmp.md --output $(OUTPUT) $(PDF_ENGINE) $(URL_PROPERTIES) $(VERBOSE) $(MARKDOWN_IMAGES) --table-of-contents
	rm tmp.md


loop:
	while true; do date && make build && clear && echo "Done" && date && sleep 1; done;
