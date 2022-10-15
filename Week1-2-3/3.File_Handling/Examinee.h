#include <bits/stdc++.h>
using namespace std;

struct Examinee {
    string id;
    float maths,
          literature,
          physics,
          chemistry,
          biology,
          history,
          geography,
          civic_education,
          natural_science,
          social_science,
          foreign_language;
    
};
// 1. Read the information of one examinee:
Examinee readExaminee(string line_info);

// 2. Read the information of a list of examinees:
vector<Examinee> readExamineeList(string file_name);

// 3. Write the total score of examinees to file:
void writeScores(vector<Examinee> examinee_list, string out_file_name);


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