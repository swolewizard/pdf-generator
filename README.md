# PDF Generator

A tool that takes a text file and converts it into PDF with the following specifications:
* 12pt Times New Roman font
* 612 x 792 page size

## Usage

Download and unzip repository.

Inside pdf-generator directory, compile the code  
``make ``

Then run  
``./pdf_generator in.txt out``

Note: out is output filename. It is optional and uses "in" as out name by default.

## Limitations
Compared to the many PDF converters out there, this version is very much a toy project. If you are looking for a reliable converter for work, this might not be the tool. Here are a few reasons:
* No compression
* Not the most efficient method of conversion
* Only works for one file type, txt

## Credit
* idrsolutions blog for the easy to understand PDF format breakdown!





