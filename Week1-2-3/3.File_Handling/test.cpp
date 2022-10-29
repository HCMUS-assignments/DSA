#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<fstream>
using namespace std;

struct Examinee
{
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


string detect_infor(string &line_infor)// Hàm xác định từng thông tin của thí sinh.
{
    int index = line_infor.find(',');
    if(index == -1)
    {
        return line_infor;
    }
    else
    {
        string tok = line_infor.substr(0, index);
        line_infor.erase(0, index+1);
        return tok;
    }
}


float detect_score(string str)// Hàm xác định điểm của từng môn học.
{
    if(str == "")   return 0;
    return stof(str);
}

// 1. Read the information of one examinee:
Examinee readExaminee(string line_infor)
{
    Examinee exam;
    string tok;
    
    tok = detect_infor(line_infor);
    exam.id = tok;

    string name = detect_infor(line_infor);
    cout << "1: line info:" << line_infor << endl;

    float subjects[11] = {0};
    for (int i = 0; i < 11; i++)
    {
        subjects[i] = detect_score(detect_infor(line_infor));
        cout << i << ": line info:" << line_infor << endl;
    }
    memcpy(&exam.maths, subjects, sizeof(float)*11);// Copy giá trị của subject sang exam từ vị trí math đến 44byte tiếp theo.
    return exam;
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



// 2. Read the information of a list of examinees:
vector<Examinee> readExamineeList(string file_name)
{
    fstream fts;
    fts.open("data.txt", ios::in);
    if(fts.fail())
    {
        cout<< "Can not open file![1]" << endl;
        exit(1);
    }
    vector < Examinee > listExaminee;

    string file_infor;
    getline(fts, file_infor);
    string line_infor;
    // Đọc thông tin đến cuối file.
    int count = 0;
    while(!fts.eof())
    {
        if (count > 0) {
            break;
        }
        
        getline(fts, line_infor);
        Examinee exam = readExaminee(line_infor);
        outputExaminee(exam) ;
        listExaminee.push_back(exam);
        count ++;
    }
    fts.close();
    return listExaminee;
}

// 3. Write the total score of examinees to file
void writeScores(vector<Examinee> examinee_list, string out_file_name)
{
    fstream fts;
    fts.open(out_file_name, ios:: out);
    if(fts.fail())
    {
        cout<< "Can not open file![2]" << endl;
        return;
    }

    float totalScore = 0;
    float BB = 0, NS_Score = 0, SS_Score = 0;

    fts << "SBD BB KHTN KHXH" << endl;
    for (int i = 0; i < examinee_list.size(); i++)
    {
        BB = examinee_list[i].maths + examinee_list[i].literature + examinee_list[i].foreign_language;
        NS_Score = examinee_list[i].physics + examinee_list[i].chemistry + examinee_list[i].biology;
        SS_Score = examinee_list[i].history + examinee_list[i].geography + examinee_list[i].civic_education;
        totalScore += examinee_list[i].maths + examinee_list[i].literature + examinee_list[i].foreign_language + NS_Score + SS_Score;

        fts << examinee_list[i].id << " " << BB << " " << NS_Score << " " <<  SS_Score << endl;
    }
    fts << "The Total Score = " << totalScore << endl;

    // Close file.
    fts.close();

}

int main()
{
    vector <Examinee> listExaminee;
    listExaminee = readExamineeList("data.txt");

    string out_file_name = "Output.txt";
    writeScores(listExaminee, out_file_name);
    return 1;
}

