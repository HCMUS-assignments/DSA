/*
Fulfill the following requirements:
1. Read the information of one examinee:
• Examinee readExaminee(string line_info);
• Input: line_info - a line from "data.txt" which provides the information of 1 examinee.
• Output: Return Examinee variable, which stores the info of the given examinee.
2. Read the information of a list of examinees:
• vector<Examinee> readExamineeList(string file_name);
• Input: file_name - path to input file "data.txt".
• Output: vector<Examinee> variable, which store the info of all examinees from the file.
3. Write the total score of examinees to file:
• void writeScores(vector<Examinee> examinee_list, string out_file_name);
• Input: examinee_list - List of examinees.
out_file_name - name of file to write.
• Output: Calculate the sum score of three subjects Maths, Literature, and Foreign language
(Compulsory Scores - BB) of each examinee and write to the out_file_name file using the
following format:
– The first line contains header information: "SBD BB KHTN KHXH"
– Each next line contains info of only one examinee: ID, Compulsory Scores, Natural Sciences
Scores, and Social Sciences Scores separated by a single space.
• Example:
SDB BB KHTN KHXH
XX001 28.0 29.25 0.0
...
XX999 20.0 0.0 28.75
The total score is calculated as follows:
• The score of Natural Sciences and Social Sciences column in data.txt is not available by default.
Calculate the score for each combination and store them into struct Examinee.
• The score of Natural Sciences combination = physics + chemistry + biology
• The score of Social Sciences combination = history + geography + civic education
• The total score = maths + literature + foreign language + natural sciences + social sciences
*/

#include "Examinee.h"

Examinee readExaminee (string line_info) {
    // declare examinee variable
    Examinee examinee;

    // divide string with comma
    stringstream ss(line_info);
    string token;
    if (ss >> token) {
            // store data into examinee variable
            examinee.id = token;

            // ignore full name
            ss >> token;

            ss >> token;
            examinee.maths = stof(token);
            ss >> token;
            examinee.literature = stof(token);
            ss >> token;
            examinee.physics = stof(token);
            ss >> token;
            examinee.chemistry = stof(token);
            ss >> token;
            examinee.biology = stof(token);
            ss >> token;
            examinee.history = stof(token);
            ss >> token;
            examinee.geography = stof(token);
            ss >> token;
            examinee.civic_education = stof(token);

            // ignore KHTN, KHXH
            ss >> token;
            ss >> token;

            ss >> token;
            examinee.foreign_language = stof(token);
    }

    // print examinee variable
    cout << examinee.id << " " << examinee.maths << " " << examinee.literature << " " << examinee.physics << " " << examinee.chemistry << " " << examinee.biology << " " << examinee.history << " " << examinee.geography << " " << examinee.civic_education << " " << examinee.foreign_language << endl;

    return examinee;
}

int main() {
    
    // declare string line_info
    string line_info;

    // open data.txt
    fstream data("data.txt", ios::in);

    // check whether file is opened or not
    if (data.fail()) {
        cout << "Error opening file" << endl;
        exit(225);
    }
    
    // read a line of data.txt
    getline(data, line_info);
    getline(data, line_info);

    readExaminee("data.txt");

    
    // close data.txt
    data.close();

    return 225;
}
