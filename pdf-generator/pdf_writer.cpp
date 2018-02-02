#include "pdf_writer.h"

// Public 
//
PDFWriter::PDFWriter(FILE *f, string e): file(f), extension(e), out(e)
{
	// TODO: Get the original name instead?
}

PDFWriter::PDFWriter(FILE *f, string e, string o): file(f), extension(e), out(o)
{
}

FILE* PDFWriter::write_to_pdf()
{
	FILE *pdf;
	switch(extension[0])
	{
		case 't':
			pdf = text_to_pdf();
			break;
		case 'j':
			pdf = img_to_pdf();
			break;
		case 'h':
			pdf = html_to_pdf();
			break;
		default:
			break;
	}

	return pdf;
}

// Private

FILE* PDFWriter::text_to_pdf()
{

	string line = "Hello, my name is Jack!";
	
    // string filename = out + ".pdf";
	// const char* f = filename.c_str();
	ofstream pdf;
	
	/* Line to modify I: version number aka overwrite first line */
	pdf.open("1.pdf", ios::in);
	pdf << "%PDF-" + PDF_VERSION;
	pdf.close();
	
	/* Open in append mode instead */
	pdf.open("1.pdf", ios::app);
	
	/* Length calculation */
	string::size_type length = line.size();
	length += 30; // The other stuff like font takes bytes too
	pdf << "<</Length " + to_string(length) + ">>\n";
	
	/* Put in the content */
	pdf << "stream\n";
	pdf << "BT /F1 12 Tf 175 720 Td\n";
	pdf << "(" + line + ")Tj ET\n";
	pdf << "endstream\n";
	pdf << "endobj\n";

	/* Put in the xref and etc stuff */
	pdf << "xref\n";
	pdf << "0 7\n";
	pdf << "0000000000 65535 f\n";
	pdf << "0000000009 00000 n\n";
	pdf << "0000000056 00000 n\n";
	pdf << "0000000111 00000 n\n";
	pdf << "0000000212 00000 n\n";
	pdf << "0000000250 00000 n\n";
	pdf << "0000000317 00000 n\n";
	pdf << "trailer <</Size 7/Root 1 0 R>>\n";
	pdf << "startxref\n";
	pdf << "406\n";
	pdf << "%%EOF\n";

	pdf.close();
}

FILE* PDFWriter::img_to_pdf()
{
}

FILE* PDFWriter::html_to_pdf()
{
}
