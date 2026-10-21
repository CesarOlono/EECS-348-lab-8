#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main(){
    string filename; //Makes variable to hold the text
    cout << "Enter file name: "; //prints question, then cin stores the input in filename
    cin >> filename;

    ifstream file(filename); //opens the file with a name for reading, File stands for the open file
    if (!file) {
	cout << "Could not open file" << endl;
	return 1; //incase the file doesn't open
    }
    string line;
    int lineNum = 0; //this is a counter for the line N: in the outputs. starting at 0
    while (getline(file, line)) {
	lineNum++; //adds 1 to the counter so the first line is line 1
	istringstream iss(line); //turns the line of text into something you can read from
	string a, b, extra;
	if (!(iss >> a >> b) || (iss >> extra)) { //checks if enough words are read
	    cout << "line " << lineNum << ": ERROR: expected exactly two numbers" << endl;
	    continue; //skips the rest and continues to the next line of the file
	}
	cout << "line " << lineNum << ": " << a << " and " << b << endl;
    }
}
