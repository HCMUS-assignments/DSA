#include "lib.h"

// 1. Read the companies'information from a given file:
vector<Company> ReadCompanyList (string file_name) {
    fstream fin(file_name, ios::in);
    if (fin.fail()) {
        cout << "File not found!" << endl;
        exit(1);
    }

    // khai báo 
    string line_info;
    vector<Company> list_company;

    // bỏ qua dòng đầu file
    getline(fin, line_info);

    // đọc qua từng dòng và lấy thông tin lưu vào struct
    while (getline(fin, line_info)) {
        Company company;
        stringstream ss(line_info);
        getline(ss, company.name, '|');
        getline(ss, company.tax_code, '|');
        getline(ss, company.address, '\n');
        list_company.push_back(company);
    }
    
    return list_company;
}

// 2. Hash a string (company name):
long long HashString (string company_name) {
    if (company_name.length() > 20) {
        company_name = company_name.substr(company_name.length() - 20 , 20);
    }
    long long hash = 0;
    long long m =  round(pow(10, 9)) + 9;
    int p = 31;
    long long sum_mod_m = 0;
    long long r = 0;

    // xử lý tràn số: (a + b) % m = (a % m + b % m) % m; (a * b) % m = (a % m * b % m) % m;
    /*
        hash = (sum1 + sum2 +... + sum n) % m (n <= 20 )
        => hash = (hash + sum[i] % m) % m

        sum[i] = ascii * p^i
        => sum[i] % m = (ascii * p^i) % m = (ascii % m * p^i % m) % m
        
        với p = 31 thì p^i bắt đầu tràn số từ i = 13, nên ta tách tích ra lấy mod mỗi lần
        với i > 12 thì:
              r = p^i % m = (p^(i - 12) * p^12) % m = (p^(i - 12) % m * p^12 % m) % m
        => sum[i] % m = (ascii % m * r % m) % m
        => hash = (hash + (ascii % m * r % m) % m) % m
    */
    for (int i = 0; i < company_name.length(); i++) {
        if (i > 12) {
            long long a = round(pow(31, i - 12));
            a = a % m;
            long long b = round(pow(31, 12));
            b = b % m;
            r = (a *b) % m;
        } else {
            long long a = round(pow(31, i));
            r = a % m;
        }
        sum_mod_m = (company_name[i] * r ) % m; // company_name[i] % m == company_name[i] vì ascii < 256
        hash = (hash + sum_mod_m) % m;
    }
    return hash;
}

// 3. The function to create a hash table of size 2000, generated from the companies list:
Company *CreateHashTable (vector<Company> list_company) {
    Company *hash_table = new Company[2000];
    for (int i = 0; i < list_company.size(); i++) {
        long long key = HashString(list_company[i].name);
        int index = key % 2000;
        if (hash_table[index].name == "") {
            hash_table[index] = list_company[i];
        } else {
            while (hash_table[index].name != "") {
                index++;
                if (index == 2000) {
                    index = 0;
                }
            }
            hash_table[index] = list_company[i];
        }
    }
    return hash_table;
}

// 4. Add the info of a company into an existed hash table:
void Insert (Company *hash_table, Company company) {
    long long key = HashString(company.name);
    int index = key % 2000;
    if (hash_table[index].name == "") {
        hash_table[index] = company;
    } else {
        while (hash_table[index].name != "") {
            index++;
            if (index == 2000) {
                index = 0;
            }
        }
        hash_table[index] = company;
    }

}

// 5. Search for company information by its name:
Company *Search (Company *hash_table, string company_name) {
    long long key = HashString(company_name);
    int index = key % 2000;
    if (hash_table[index].name == company_name) {
        return &hash_table[index];
    } else {
        while (hash_table[index].name != company_name) {
            index++;
            if (index == 2000) {
                index = 0;
            }
        }
        return &hash_table[index];
    }
}

// ----------------Các hàm hổ trợ test chương trình-----------------

// Hàm in ra thông tin của 1 công ty
void PrintCompany(Company company) {
    cout << "Name: " << company.name << endl;
    cout << "Tax code: " << company.tax_code << endl;
    cout << "Address: " << company.address << endl;
}

// Hàm in ra thông tin của 1 danh sách công ty
void PrintCompanyList(vector<Company> list_company) {
    for (int i = 0; i < list_company.size(); i++) {
        PrintCompany(list_company[i]);
        cout << endl;
    }
}