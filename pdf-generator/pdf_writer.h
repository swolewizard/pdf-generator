/*********************************************
 * Describes PDF Writer
 *
 * Author: swo
 *********************************************/

#include <string>
#include <iostream>
#include <fstream> // file i/o
#include <iomanip> // set precision

using namespace std;

const string PDF_VERSION = "1.7"; 
const int DEFAULT_X = 50; // Writer initial x coordinate
const int DEFAULT_Y = 720; // Write initial y coordinate

class PDFWriter
{
  public:
	PDFWriter(string s, string o); 
	~PDFWriter();
	void write_to_pdf();

  private:
	// helper function
	string create_line(string s, int x, int y);

	ifstream file;
	string name;
	string out;
};
