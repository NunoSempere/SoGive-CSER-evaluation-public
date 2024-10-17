default:
	make install
	make extract
	# https://github.com/0xabu/pdfannots

extract:
	pdfannots comments.pdf

save: 
	pdfannots comments.pdf > comments.md

install:
	pip3 install pdfannots
