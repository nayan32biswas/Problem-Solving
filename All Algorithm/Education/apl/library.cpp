#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
using namespace std;

class library
{
    long long int id;
    char name[50];
    bool loan = false;
    bool member = false, book = false, category = false;

public:
    void add_member();
    // void delete_member();
    void edit_member();

    void add_book();
    // void delete_book();
    void edit_book();

    void add_category();
    // void delete_category();
    void edit_category();

    void loan_a_book();

    int retacno();
    bool is_loan();
    bool is_member();
    bool is_book();
    bool is_category();
    void show_details();
};

void library::add_member()
{
    cout << "\n\t\t\tEnter the member ID. : ";
    cin >> id;
    cout << "\n\n\t\t\tEnter the Name of the member : ";
    cin.ignore();
    cin.getline(name, 50);
    member = true;
}
void library::add_book()
{
    cout << "\n\t\t\tEnter the book ID. : ";
    cin >> id;
    cout << "\n\n\t\t\tEnter the book name : ";
    cin.ignore();
    cin.getline(name, 50);
    book = true;
}
void library::add_category()
{
    cout << "\n\t\t\tEnter the Category ID. : ";
    cin >> id;
    cout << "\n\n\t\t\tEnter the Name of the Category : ";
    cin.ignore();
    cin.getline(name, 50);
    category = true;
}

void library::edit_member()
{
    cout << "\n\t\t\tmember ID. : " << id;
    cout << "\n\t\t\tModify member Name : ";
    cin.ignore();
    cin.getline(name, 50);
}
void library::edit_book()
{
    cout << "\n\t\t\tbook ID. : " << id;
    cout << "\n\t\t\tModify book Name : ";
    cin.ignore();
    cin.getline(name, 50);
}
void library::edit_category()
{
    cout << "\n\t\t\tcategory ID. : " << id;
    cout << "\n\t\t\tModify category Name : ";
    cin.ignore();
    cin.getline(name, 50);
}
void library::loan_a_book()
{
    loan = true;
}
void library::show_details()
{
    string str;
    if (member)
        cout << setw(10) << "Member ID: " << id << " Name: " << setw(20) << name << endl;
    else if (book)
        cout << setw(10) << "Book ID: " << id << "Book Name: " << setw(10) << name << endl;
    else if (category)
        cout << setw(10) << "Category ID: " << id << " Category: " << setw(10) << name << endl;
}
int library::retacno()
{
    return id;
}
bool library::is_loan()
{
    return loan == true;
}
bool library::is_member()
{
    return member == true;
}
bool library::is_book()
{
    return book == true;
}
bool library::is_category()
{
    return category == true;
}

void add_member();
void delete_member(int);
void edit_member(int);

void add_book();
void delete_book(int);
void edit_book(int);

void add_category();
void delete_category(int);
void edit_category(int);

void loan_a_book(int);
void display(int);
void display_all();
void view_all_loan();

int main()
{
    string str;
    long long num;
    do
    {
        cout << "\n\n\t\t\t\t======================\n";
        cout << "\t\t\t\tLIBRARY MANAGEMENT SYSTEM";
        cout << "\n\t\t\t\t======================\n";

        cout << "\t\t\t\t    ::MAIN MENU::\n";
        cout << "\n\t\t\t\t1. add_member";
        cout << "\n\t\t\t\t2. delete_member";
        cout << "\n\t\t\t\t3. edit_member";
        cout << "\n\t\t\t\t4. add_book";
        cout << "\n\t\t\t\t5. delete_book";
        cout << "\n\t\t\t\t6. edit_book";
        cout << "\n\t\t\t\t7. add_category";
        cout << "\n\t\t\t\t8. delete_category";
        cout << "\n\t\t\t\t9. edit_category";
        cout << "\n\t\t\t\t10. loan_a_book";
        cout << "\n\t\t\t\t11. display";
        cout << "\n\t\t\t\t12. display_all";
        cout << "\n\t\t\t\t13. view_all_loan";
        cout << "\n\t\t\t\t15. EXIT";
        cout << "\n\n\t\t\t\tSelect Your Option (1-15): ";
        cin >> str;

        if (str == "1")
        {
            add_member();
        }
        if (str == "2")
        {
            cout << "\n\n\t\t\tEnter The member ID. : ";
            cin >> num;
            delete_member(num);
        }
        if (str == "3")
        {
            cout << "\n\n\t\t\tEnter The member ID. : ";
            cin >> num;
            edit_member(num);
        }
        if (str == "4")
        {
            add_book();
        }
        if (str == "5")
        {
            cout << "\n\n\t\t\tEnter The Book ID. : ";
            cin >> num;
            delete_book(num);
        }
        if (str == "6")
        {
            cout << "\n\n\t\t\tEnter The Book ID. : ";
            cin >> num;
            edit_book(num);
        }
        if (str == "7")
        {
            add_category();
        }
        if (str == "8")
        {
            cout << "\n\n\t\t\tEnter The Category ID. : ";
            cin >> num;
            delete_category(num);
        }
        if (str == "9")
        {
            cout << "\n\n\t\t\tEnter The Category ID. : ";
            cin >> num;
            edit_category(num);
        }
        if (str == "10")
        {
            cout << "\n\n\t\t\tEnter The Book ID. : ";
            cin >> num;
            loan_a_book(num);
        }
        if (str == "11")
        {
            cout << "\n\n\t\t\tEnter A ID. : ";
            cin >> num;
            display(num);
        }
        if (str == "12")
        {
            display_all();
        }
        if (str == "13")
        {
            view_all_loan();
        }
        if (str == "15")
        {
            cout << "\n\n\t\t\tThanks for using the Banking System\n";
        }
    } while (str != "15");
    return 0;
}

/**********************************************************************************/
void add_member()
{
    library lib;
    ofstream outFile;
    outFile.open("library.dat", ios::binary | ios::app);
    lib.add_book();
    outFile.write(reinterpret_cast<char *>(&lib), sizeof(library));
    outFile.close();
}

void delete_member(int id)
{
    library lib;
    ifstream inFile;
    ofstream outFile;
    inFile.open("library.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    outFile.open("Temp.dat", ios::binary);
    inFile.seekg(0, ios::beg);
    while (inFile.read(reinterpret_cast<char *>(&lib), sizeof(library)))
    {
        if (lib.retacno() != id || !lib.is_member())
        {
            outFile.write(reinterpret_cast<char *>(&lib), sizeof(library));
        }
    }
    inFile.close();
    outFile.close();
    remove("library.dat");
    rename("Temp.dat", "library.dat");
    cout << "\n\nRecord Deleted ..";
}

void edit_member(int id)
{
    bool found = false;
    library lib;
    fstream File;
    File.open("library.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *>(&lib), sizeof(library));
        if (lib.retacno() == id && lib.is_member())
        {
            lib.show_details();
            cout << "\n\n\t\t\tEnter The New Details of Member" << endl;
            lib.edit_member();
            int pos = (-1) * static_cast<int>(sizeof(library));
            File.seekp(pos, ios::cur); //fncallat1353
            File.write(reinterpret_cast<char *>(&lib), sizeof(library));
            cout << "\n\n\t\t\tRecord Updated";
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n\n\t\t\tRecord Not Found ";
}
/**********************************************************************************/

/**********************************************************************************/
void add_book()
{
    library lib;
    ofstream outFile;
    outFile.open("library.dat", ios::binary | ios::app);
    lib.add_book();
    outFile.write(reinterpret_cast<char *>(&lib), sizeof(library));
    outFile.close();
}

void delete_book(int id)
{
    library lib;
    ifstream inFile;
    ofstream outFile;
    inFile.open("library.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    outFile.open("Temp.dat", ios::binary);
    inFile.seekg(0, ios::beg);
    while (inFile.read(reinterpret_cast<char *>(&lib), sizeof(library)))
    {
        if (lib.retacno() != id || !lib.is_book())
        {
            outFile.write(reinterpret_cast<char *>(&lib), sizeof(library));
        }
    }
    inFile.close();
    outFile.close();
    remove("library.dat");
    rename("Temp.dat", "library.dat");
    cout << "\n\nRecord Deleted ..";
}

void edit_book(int id)
{
    bool found = false;
    library lib;
    fstream File;
    File.open("library.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *>(&lib), sizeof(library));
        if (lib.retacno() == id && lib.is_book())
        {
            lib.show_details();
            cout << "\n\n\t\t\tEnter The New Details of book" << endl;
            lib.edit_book();
            int pos = (-1) * static_cast<int>(sizeof(library));
            File.seekp(pos, ios::cur); //fncallat1353
            File.write(reinterpret_cast<char *>(&lib), sizeof(library));
            cout << "\n\n\t\t\tRecord Updated";
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n\n\t\t\tRecord Not Found ";
}
/**********************************************************************************/

/**********************************************************************************/
void add_category()
{
    library lib;
    ofstream outFile;
    outFile.open("library.dat", ios::binary | ios::app);
    lib.add_book();
    outFile.write(reinterpret_cast<char *>(&lib), sizeof(library));
    outFile.close();
}

void delete_category(int id)
{
    library lib;
    ifstream inFile;
    ofstream outFile;
    inFile.open("library.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    outFile.open("Temp.dat", ios::binary);
    inFile.seekg(0, ios::beg);
    while (inFile.read(reinterpret_cast<char *>(&lib), sizeof(library)))
    {
        if (lib.retacno() != id || !lib.is_category())
        {
            outFile.write(reinterpret_cast<char *>(&lib), sizeof(library));
        }
    }
    inFile.close();
    outFile.close();
    remove("library.dat");
    rename("Temp.dat", "library.dat");
    cout << "\n\nRecord Deleted ..";
}

void edit_category(int id)
{
    bool found = false;
    library lib;
    fstream File;
    File.open("library.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *>(&lib), sizeof(library));
        if (lib.retacno() == id && lib.is_category())
        {
            lib.show_details();
            cout << "\n\n\t\t\tEnter The New Details of category" << endl;
            lib.edit_category();
            int pos = (-1) * static_cast<int>(sizeof(library));
            File.seekp(pos, ios::cur); //fncallat1353
            File.write(reinterpret_cast<char *>(&lib), sizeof(library));
            cout << "\n\n\t\t\tRecord Updated";
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n\n\t\t\tRecord Not Found ";
}
/**********************************************************************************/

void loan_a_book(int id)
{
    library lib;
    bool flag = false;
    ifstream inFile;
    inFile.open("library.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    cout << "\n\t\t\tBALANCE DETAILS\n";
    while (inFile.read(reinterpret_cast<char *>(&lib), sizeof(library)))
    {
        if (lib.retacno() == id && lib.is_loan())
        {
            lib.loan_a_book();
            flag = true;
        }
    }
    inFile.close();
    if (flag == false)
        cout << "\n\n\t\t\tbook number does not exist";
}
/**********************************************************************************/
void display(int id)
{
    library lib;
    bool flag = false;
    ifstream inFile;
    inFile.open("library.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    cout << "\n\t\t\tBALANCE DETAILS\n";
    while (inFile.read(reinterpret_cast<char *>(&lib), sizeof(library)))
    {
        if (lib.retacno() == id)
        {
            lib.show_details();
            flag = true;
        }
    }
    inFile.close();
    if (flag == false)
        cout << "\n\n\t\t\tlibrary number does not exist";
}

void display_all()
{

    library lib;
    ifstream inFile;
    inFile.open("library.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    puts("\t\t\t===============");
    puts("\t\t\t SHOW ALL ENTITY");
    puts("\t\t\t===============");
    while (inFile.read(reinterpret_cast<char *>(&lib), sizeof(library)))
    {
        lib.show_details();
    }
    inFile.close();
}

void view_all_loan()
{
    library lib;
    ifstream inFile;
    inFile.open("library.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    puts("\t\t\t===============");
    puts("\t\t\t SHOW ALL LOAN");
    puts("\t\t\t===============");
    while (inFile.read(reinterpret_cast<char *>(&lib), sizeof(library)))
    {
        if (lib.is_loan())
        {
            lib.show_details();
        }
    }
    inFile.close();
}
