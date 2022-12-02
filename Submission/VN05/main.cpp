#include "lib.h"


int main() {
    // 1. Read the companies'information from a given file:
    vector<Company> list_company = ReadCompanyList("data.txt");

    // Print the 20 first companies:
    cout << "List of 20 first companies: " << endl;
    for (int i = 0; i < 20; i++) {
        cout << list_company[i].name << " | " << list_company[i].tax_code << " | " << list_company[i].address << endl;
    }
    cout << "size of list_company: " << list_company.size() << endl;
    cout << "--------------------------------------------" << endl;

    // 2. Create a hash table of size 2000, generated from the companies list:
    Company *hash_table = CreateHashTable(list_company);

    // Print the 20 first companies in the hash table:
    cout << "List of 20 first companies in the hash table: " << endl;
    for (int i = 0; i < 20; i++) {
        cout << hash_table[i].name << " | " << hash_table[i].tax_code << " | " << hash_table[i].address << endl;
    }
    cout << "--------------------------------------------" << endl;

    // 3. Search for company information by its name:
    Company *company = Search(hash_table, "CONG TY TNHH BEE VIET NAM");
    cout << "Search Company information: " << endl;
    cout << company->name << " | " << company->tax_code << " | " << company->address << endl;
    cout << "--------------------------------------------" << endl;

    // 4. Add the info of a company to the hash table:
    Company company_new;
    company_new.name = "CONG TY TNHH HCMUS - CTDLGT";
    company_new.tax_code = "K21";
    company_new.address = "P. Linh Trung, Q. Thu Duc, TP. Ho Chi Minh";

    Insert(hash_table, company_new);

    // Find the company in the hash table:
    company = Search(hash_table, "CONG TY TNHH HCMUS - CTDLGT");
    cout << "Added Company information: " << endl;
    cout << company->name << " | " << company->tax_code << " | " << company->address << endl;
    cout << "--------------------------------------------" << endl;

    // delete the hash table:
    delete[] hash_table;

    return 225;

}



