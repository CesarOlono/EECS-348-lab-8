#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

bool isValid(string s) { //takes the text s and answers true or false
    if (s.empty()) { //returns false if string is empty
	return false;
    }

    int i = 0; //makes i the position in the string the code looks at
    if (s[0] == '+' || s[0] == '-') { //checks if the first character is a sign
	i = 1; //if it is then it skips then starts at position 1
    }

    int digits = 0; //counter for number of digits
    while (i < s.size() && s[i] >= '0' && s[i] <= '9') { //loop runs as long as it doesnt run off end, at least the number is at 0 through 9
	i++; //moves to next character
	digits++; //counts each digit passed
    }
    if (digits == 0) { //returns false if no digits found like A and NaN
	return false;
    }
    if (i == s.size()) {
	return true;
    }
    if (s[i] == '.') {
        i++;
    } else {
	return false;
    }

    digits = 0;
    while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
	i++;
	digits++;
    }
    if (digits == 0) {
	return false;
    }
    return i == s.size(); //gives true when i reached the end and false when it didn't
}

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
	bool okA = isValid(a); //calls the function and stores the trur or false answer
	bool okB = isValid(b);
	if (!okA || !okB) { //checks if either one is invalid
	    cout << "line " << lineNum << ": ERROR: invalid number";
	    if (!okA) cout << " \"" << a << "\""; //adds token in quotes only if it's invalid
	    if (!okB) cout << " \"" << b << "\"";
	    cout << endl; //finally ends line
	    continue; //skips to next line
	}
	cout << "line " << lineNum << ": " << a << " and " << b << endl;
    }
}
