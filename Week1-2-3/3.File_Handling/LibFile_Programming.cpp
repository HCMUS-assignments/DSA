#include "Examinee.h"

// check the field of a subject and assign score to subject
float checkScore(string token) {
    if (token == "") {
        return 0;
    } else {
        return stof(token);
    }
}

// split string by delimiter comma 
string splitWithComma(string &str) {
    int pos = str.find(',');
    if (pos != -1) {
        string token = str.substr(0, pos);
        str.erase(0, pos + 1);
        return token;
    } else {
        return str;
    }
}

// printf the information of a examinee
void outputExaminee (Examinee examinee) {
    cout << "ID: " << examinee.id << endl;
    cout << "Maths: " << examinee.maths << endl;
    cout << "Literature: " << examinee.literature << endl;
    cout << "Physics: " << examinee.physics << endl;
    cout << "Chemistry: " << examinee.chemistry << endl;
    cout << "Biology: " << examinee.biology << endl;
    cout << "History: " << examinee.history << endl;
    cout << "Geography: " << examinee.geography << endl;
    cout << "Civic Education: " << examinee.civic_education << endl;
    cout << "Foreign Language: " << examinee.foreign_language << endl;
}

// 1. Read the information of one examinee:
Examinee readExaminee (string line_info) {
    // declare examinee variable
    Examinee examinee;

    // split string with comma
    string token;

    // store data into examinee variable
    token = splitWithComma(line_info);
    examinee.id = token;

    // ignore full name
    token = splitWithComma(line_info);

    // split string with comma to get the score of each subject
    token = splitWithComma(line_info);
    examinee.maths = checkScore(token);
    token = splitWithComma(line_info);
    examinee.literature = checkScore(token);
    token = splitWithComma(line_info);
    examinee.physics = checkScore(token);
    token = splitWithComma(line_info);
    examinee.chemistry = checkScore(token);
    token = splitWithComma(line_info);
    examinee.biology = checkScore(token);
    token = splitWithComma(line_info);
    examinee.history = checkScore(token);
    token = splitWithComma(line_info);
    examinee.geography = checkScore(token);
    token = splitWithComma(line_info);
    examinee.civic_education = checkScore(token);

    // ignore KHTN, KHXH
    token = splitWithComma(line_info);
    token = splitWithComma(line_info);

    token = splitWithComma(line_info);
    examinee.foreign_language = checkScore(token);

    outputExaminee(examinee);

    return examinee;
}

int main() {
    
    // declare string line_info
    string stringIgnore;
    string line_info;

    // open data.txt
    fstream data("data.txt", ios::in);

    // check whether file is opened or not
    if (data.fail()) {
        cout << "Error opening file" << endl;
        exit(225);
    }
    
    // read a line of data.txt
    getline(data, stringIgnore);
    cout << stringIgnore << endl;
    getline(data, line_info);
    cout << line_info << endl;

    readExaminee(line_info);
    
    // close data.txt
    data.close();

    return 225;
}
