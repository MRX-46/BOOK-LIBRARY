#include <iostream>
using namespace std;

const int MAX = 100;
class Book
{
private:
    string title;
    string author;
    int id;
    bool avaiable;

public:
    Book()
    {
        title = "";
        author = "";
        id = 0;
        avaiable = true;
    }

    void addBook()
    {
        cout << "Enter book ID : ";
        cin >> id;
        cin.ignore();
        cout << "Enter book title : ";
        getline(cin, title);
        cout << "Enter Author name : ";
        getline(cin, author);
        avaiable = true;
    }

    void display()
    {
        cout << "ID: " << id << " Title: " << title << " Author " << author << " Status " << (avaiable ? "Yes" : "Not") << endl;
    }

    bool match(string findetitle)
    {
        return title == findetitle;
    }

    int getID()
    {
        return id;
    }

    void issueBook()
    {
        if (avaiable)
        {
            avaiable = false;
            cout << "Book issued sucessfully" << endl;
        }

        else
        {
            cout << "Book is already issued " << endl;
        }
    }

    void returnBook()
    {
        avaiable = true;
        cout << "Book returned sucessfully ." << endl;
    }
};

int main()
{

    Book library[MAX];
    int choice, count = 0;

    while (true)
    {
        cout << "Library Menu" << endl;
        cout << "1. Add Book\n2. Show Book\n3. Search Book\n4. Issue Book\n5. Return Book\n6. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        if (choice == 1)
        {
            if (count < MAX)
            {
                library[count].addBook();
                count++;
            }
            else
            {
                cout << "Library is full" << endl;
            }
        }

        else if (choice == 2)
        {
            for (int i = 0; i < count; i++)
            {
                library[i].display();
            }
        }

        else if (choice == 3)
        {
            cin.ignore();
            string searchTitle;
            cout << "Enter your Book title ";
            getline(cin, searchTitle);
            bool found = false;
            for (int i = 0; i < count; i++)
            {
                if (library[i].match(searchTitle))
                {
                    library[i].display();
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Book not found " << endl;
            }
        }

        else if (choice == 4)
        {
            int id;
            cout << "Enter your book ID :";
            cin >> id;

            bool found = false;
            for (int i = 0; i < count; i++)
            {
                if (library[i].getID() == id)
                {
                    library[i].getID() == id;
                    {
                        library[i].issueBook();
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    cout << "Book ID not found" << endl;
                }
            }
        }

        else if (choice == 5)
        {
            int id;
            cout << "Enter Book ID to return : ";
            cin >> id;

            bool found = false;
            for (int i = 0; i < count; i++)
            {
                if (library[i].getID() == id)
                {
                    library[i].returnBook();
                    found = true;
                    break;
                }
                if (!found)
                {
                    cout << "Book ID not found !" << endl;
                }
            }
        }

        else if (choice == 6)
        {
            cout << "Exiting program !" << endl;
            break;
        }

        else
        {
            cout << "Invalid option you chouce !" << endl;
        }
    }

    return 0;
}