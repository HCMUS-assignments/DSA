#include <bits/stdc++.h>
using namespace std;

// the company structure is defined here
struct Company {
    string name ;
    string tax_code;
    string address;
};

// 1. Read the companies'information from a given file:
vector<Company> ReadCompanyList (string file_name) ;

// 2. Hash a string (company name function):
long long HashString (string company_name) ;

// 3. The function to create a hash table of size 2000, generated from the companies list:
Company *CreateHashTable (vector<Company> list_company) ;

// 4. Add the info of a company to the hash table:
void Insert (Company *hash_table, Company company) ;

// 5. Search for company information by its name:
Company *Search (Company *hash_table, string company_name) ;

