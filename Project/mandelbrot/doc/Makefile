all : report.tex references.bib
	xelatex report.tex
	bibtex report
	xelatex report.tex
	xelatex report.tex

clean :
	rm -f *.aux *.bbl *.blg *.log *.out *.pdf *.synctex.gz

.PHONY : all clean

