#include <iostream>
#include <fstream>

using namespace std;

// Declaration of bookType class

const int MAX_BOOKS = 1000,
          MAX_AUTHORS = 4;

class bookType
{
    public:
        /** Default constructor */
        bookType();

        /** Default destructor */
        ~bookType();

        /** Add new bok record */
        void addBook();

        /** Update book record */
        void updateBook();

        /** Search book record */
        void searchBook();

        /** Book Menu */
        void bookMenu();

    protected:

        int totalAuthor[MAX_BOOKS],        /**< Total authors of book */
            publicationYear[MAX_BOOKS],    /**< Year of publication */
            totalBooks,                    /**< Total Book records in file */
            bookPrice[MAX_BOOKS],          /**< Book Price */
            stock[MAX_BOOKS],              /**< No. of copies in stock */
            i, j,                          /**< Looping variables */
            index;                         /** index of array */

        string title[MAX_BOOKS],                /**< Title of book */
               author[MAX_BOOKS][MAX_AUTHORS], /**< No of authors per book */
               publisher[MAX_BOOKS],            /**< Publisher of book */
               ISBNNumber[MAX_BOOKS],           /**< ISBN Number */
               temp;                            /**< Temporary variable */

        string inputFile;// = "book.in";     /**< Input file for book record */

};


// Declaration of memberType class

const int MAX_MEM   =   500;     // Maximum members

class memberType
{
    public:
        /** Default constructor */
        memberType();

        /** Default destructor */
        ~memberType();

        /** Add new member */
        void newMember();

        /** Search Member from record */
        void searchMember();

        /** update member record */
        void updateMember();

        /** Member menu */
        void memberMenu();

    protected:
        string name[MAX_MEM],        // Member name
               temp;

        string inputFile;

        int memberID[MAX_MEM],          // Member ID
            amountSpent[MAX_MEM],       // Amount spent on book store
            booksBought[MAX_MEM],       // No of books bought
            totalMembers,               // total Members
            i, j,
            index;

        char membershipFee[MAX_MEM];     // Membership fee yes = paid and no = not paid

};

// Declaration of bookStore class

class bookStore : public bookType, public memberType
{
    public:
        /** Default constructor */
        bookStore();

        /** Default destructor */
        ~bookStore();

        /** buy book from book store */
        void buyBook();

        /** Book store menu */
        void bookStoreMenu();

    protected:
        int i, j;

};

// Implementation of bookType class

bookType::bookType()
{
    //ctor

    inputFile = "book.in";

    // Reading book details from input file
    ifstream inFile;

    inFile.open(inputFile.c_str());

    inFile >> totalBooks;
    getline(inFile, temp, '\n');

    for(i = 0; i < totalBooks; i++)
    {
        getline(inFile, title[i], '\n');
        inFile >> totalAuthor[i];

        getline(inFile, temp, '\n');

        for(j = 0; j < totalAuthor[i]; j++)
        {
            getline(inFile, author[i][j], '\n');
        }

        getline(inFile, publisher[i], '\n');
        getline(inFile, ISBNNumber[i], '\n');

        inFile >> bookPrice[i]
               >> publicationYear[i]
               >> stock[i];

        getline(inFile, temp, '\n');
    }


    inFile.close();

}

bookType::~bookType()
{
    //dtor
}

/**
* Add new book record
*/
void bookType :: addBook()
{
    index = totalBooks;
    cout << "\n\t ADD NEW BOOK RECORD \n" << endl;

    cout << "Book Title: ";
    getline(cin, temp, '\n');
    getline(cin, title[index], '\n');

    cout << "No. of authors of book: ";
    cin >> totalAuthor[index];

    for(i = 0; i < totalAuthor[index]; i++)
    {
        cout << "Author " << (i + 1) << ": ";
        if(i == 0)
            getline(cin, temp, '\n');
        getline(cin, author[index][i], '\n');
    }

    cout << "Name of publisher: ";
    getline(cin, publisher[index], '\n');

    cout << "Enter ISBN Number: ";
    cin >> ISBNNumber[index];

    cout << "Year of publication: ";
    cin >> publicationYear[index];

    cout << "Book Price: ";
    cin >> bookPrice[index];

    cout << "Books in stock: ";
    cin >> stock[index];

    totalBooks++;
}

/**
* Update book record
*/
void bookType :: updateBook()
{
    string recordNo;
    int choice;

    cout << "\n\t UPDATE BOOK RECORD \n" << endl;

    cout << "Enter ISBN number to update book record: ";
    cin >> recordNo;

    for(i = 0; i < totalBooks; i++)
    {
        if(recordNo == ISBNNumber[i])
        {
            index = i;
            break;
        }
        else
        {
            index = -1;
        }
    }

    if(index >= 0)
    {
        do
        {
            do
            {
                cout << "Select option to update value\n" << endl
                     << "1 \t Title" << endl
                     << "2 \t Authors" << endl
                     << "3 \t Publisher Name" << endl
                     << "4 \t ISBN Number" << endl
                     << "5 \t Year of Publication" << endl
                     << "6 \t Book Price" << endl
                     << "7 \t Books in stock" << endl
                     << "0 \t EXIT" << endl
                     << "\n Enter Choice: ";
                cin >> choice;

                switch(choice)
                {
                    case 1:
                        cout << "Book Title: ";
                        getline(cin, temp, '\n');
                        getline(cin, title[index], '\n');
                        break;

                    case 2:
                        cout << "No. of authors of book: ";
                        cin >> totalAuthor[index];

                        for(i = 0; i < totalAuthor[index]; i++)
                        {
                            cout << "Author " << (i + 1) << ": ";
                            if (i == 0)
                                getline(cin, temp, '\n');
                            getline(cin, author[index][i], '\n');
                        }
                        break;

                    case 3:
                        cout << "Name of publisher: ";
                        getline(cin, temp, '\n');
                        getline(cin, publisher[index], '\n');
                        break;

                    case 4:
                        cout << "Enter ISBN Number: ";
                        cin >> ISBNNumber[index];
                        break;

                    case 5:
                        cout << "Year of publication: ";
                        cin >> publicationYear[index];
                        break;

                    case 6:
                        cout << "Book Price: ";
                        cin >> bookPrice[index];
                        break;

                    case 7:
                        cout << "Books in stock: ";
                        cin >> stock[index];
                        break;

                    case 0:
                        cout << "\n EXIT \n" << endl;
                        break;

                    default:
                        cout << "\n WRONG CHOICE." << endl;
                        break;
                };


            }while(choice < 0 || choice > 7);

        }while(choice != 0);
    }
    else
        cout << "\n\t RECORD NOT FOUND. \n" << endl;
}

/**
* Search book record
*/
void bookType :: searchBook()
{
    string recordNo;

    cout << "\n\t SEARCH BOOK RECORD \n" << endl;

    cout << "Enter ISBN number to search book record: ";
    cin >> recordNo;

    for(i = 0; i < totalBooks; i++)
    {
        if(recordNo == ISBNNumber[i])
        {
            index = i;
        }
        else
        {
            index = -1;
        }
    }

    if( index >= 0)
    {
        // Displaying Book details
        cout << "\n";
        cout << "Book Title: " << title[index] << endl;

        cout << "No. of authors of book: "<< totalAuthor[index] << endl;

        for(i = 0; i < totalAuthor[index]; i++)
        {
            cout << "Author " << (i + 1) << ": " << author[index][i] << endl;
        }

        cout << "Name of publisher: " << publisher[index] << endl;

        cout << "Enter ISBN Number: " << ISBNNumber[index] << endl;

        cout << "Year of publication: " << publicationYear[index] << endl;

        cout << "Book Price: " << bookPrice[index] << endl;

        cout << "Books in stock: " << stock[index] << endl << endl;
    }
    else
    {
        cout << "\n\t RECORD NOT FOUND. \n" << endl;
    }
}

/**
* Book Menu for Book Store
*/

void bookType :: bookMenu()
{
    int choice;
    cout << "\n\t BOOK MENU \n" << endl;

    do
    {
        do
        {
            cout << "Select option to perform action on record.\n" << endl
                 << "1 \t Add New Book" << endl
                 << "2 \t Update Book Record" << endl
                 << "3 \t Search Book Record" << endl
                 << "0 \t EXIT" << endl
                 << "\n Enter your choice: ";
            cin >> choice;

            switch(choice)
            {
                case 1:
                    addBook();
                    break;

                case 2:
                    updateBook();
                    break;

                case 3:
                    searchBook();
                    break;

                case 0:
                    cout << "\n EXIT \n";
                    break;

                default:
                    cout << "\n WRONG CHOICE \n" << endl;
                    break;
            };

        }while(choice < 0 || choice > 3);

    }while(choice != 0);
}

// Implementation of memberType class

memberType::memberType()
{
    //ctor

    inputFile = "member.in";

    // Reading member details from input file

    ifstream inFile;

    inFile.open(inputFile.c_str());

    inFile >> totalMembers;
    getline(inFile, temp, '\n');

    for(i = 0; i < totalMembers; i++)
    {
        getline(inFile, name[i], '\n');
        inFile >> memberID[i]
               >> amountSpent[i]
               >> booksBought[i]
               >> membershipFee[i];

        getline(inFile, temp, '\n');
    }

    inFile.close();
}

memberType::~memberType()
{
    //dtor
}

/**
* Add new member
*/

void memberType :: newMember()
{
    cout << "\n\t ADD NEW MEMBER \n" << endl;

    cout << "Enter membership details\n" << endl;

    index = totalMembers;

    cout << "Member Name: ";
    getline(cin, temp, '\n');
    getline(cin, name[index], '\n');

    cout << "Member ID: ";
    cin >> memberID[index];

    cout << "Amount Spent: ";
    cin >> amountSpent[index];

    cout << "No. of books bought: ";
    cin >> booksBought[index];

    cout << "Membership Fee Paid(Y/N): ";
    cin >> membershipFee[index];

    totalMembers++;

}

/**
* Search Member from record and show member details
*/

void memberType :: searchMember()
{
    int memID;

    cout << "\n\t SEARCH MEMBER \n" << endl;

    cout << "Enter member ID: ";
    cin >> memID;

    for(i = 0; i < totalMembers; i++)
    {
        if(memID == memberID[i])
        {
            index = i;
            break;
        }
        else
            index = -1;
    }
    cout << "index: " << index << endl;

    if(index >= 0)
    {
        cout << "\n MEMBER DETAILS\n" << endl;

        cout << "Member Name: " << name[index] << endl;

        cout << "Member ID: " << memberID[index] << endl;

        cout << "Amount Spent: " << amountSpent[index] << endl;

        cout << "No. of books bought: " << booksBought[index] << endl;

        cout << "Membership Fee Paid(Y/N): " << membershipFee[index] << endl;

    }
    else
    {
        cout << "\n MEMBER DOES NOT EXISTS \n" << endl;
    }
}

/**
* update member record
*/

void memberType :: updateMember()
{
    int memID,
        choice;

    cout << "\n\t UPDATE MEMBER \n" << endl;

    cout << "Enter member ID: ";
    cin >> memID;

    for(i = 0; i < totalMembers; i++)
    {
        if(memID == memberID[i])
        {
            index = i;
            break;
        }
        else
            index = -1;
    }

    if(index >= 0)
    {
        do
        {
            do
            {
                cout << "Select option to update value\n" << endl
                     << "1 \t Name" << endl
                     << "2 \t mamberID" << endl
                     << "3 \t Amount Spent" << endl
                     << "4 \t No. of books bought" << endl
                     << "5 \t Membership Fee Paid(Y/N)" << endl
                     << "0 \t EXIT" << endl
                     << "\n Enter Choice: ";
                cin >> choice;

                switch(choice)
                {
                    case 1:
                        cout << "Member Name: ";
                        getline(cin, temp, '\n');
                        getline(cin, name[index], '\n');

                        break;

                    case 2:
                        cout << "Member ID: ";
                        cin >> memberID[index];

                        break;

                    case 3:
                        cout << "Amount Spent: ";
                        cin >> amountSpent[index];

                        break;

                    case 4:
                        cout << "No. of books bought: ";
                        cin >> booksBought[index];
                        break;

                    case 5:
                        cout << "Membership Fee Paid(Y/N): ";
                        cin >> membershipFee[index];
                        break;

                    case 0:
                        cout << "\n EXIT \n" << endl;
                        break;

                    default:
                        cout << "\n WRONG CHOICE." << endl;
                        break;
                };


            }while(choice != 0);

        }while(choice != 0);

    }
    else
    {
        cout << "\n MEMBER DOES NOT EXISTS \n" << endl;
    }
}

/**
* Member Menu of Book Store
*/

void memberType :: memberMenu()
{
    int choice;
    cout << "\n\t BOOK STORE MEMBER MENU \n" << endl;

    do
    {
        do
        {
            cout << "Select option to perform action on record.\n" << endl
                 << "1 \t Add New Member" << endl
                 << "2 \t Update Member Record" << endl
                 << "3 \t Search Member Record" << endl
                 << "0 \t EXIT" << endl
                 << "\n Enter your choice: ";
            cin >> choice;

            switch(choice)
            {
                case 1:
                    newMember();
                    break;

                case 2:
                    updateMember();
                    break;

                case 3:
                    searchMember();
                    break;

                case 0:
                    cout << "\n EXIT \n";
                    break;

                default:
                    cout << "\n WRONG CHOICE \n" << endl;
                    break;
            };

        }while(choice < 0 || choice > 3);

    }while(choice != 0);
}

// Implementation of bookStore class

bookStore::bookStore() : bookType(), memberType()   // calling cunstructor of base classes
{
    //ctor
}

bookStore::~bookStore()
{
    //dtor
}

/**
* But book from book store
*/

void bookStore :: buyBook()
{
    int maxBook = 10,
        bookIndex,
        memIndex;
    float discount = 0;

    string ISBNNo;

    // Taking value of ISBN number for buying book
    cout << "\n\t BUY BOOK \n" << endl;

    cout << "Enter ISBN number of book: ";
    cin >> ISBNNo;

    // Finding book in database
    for(i = 0; i < totalBooks; i++)
    {
        if(ISBNNo == ISBNNumber[i])
        {
            bookIndex = i;
            break;
        }
        else
            bookIndex = -1;
    }

    // If book found
    if(bookIndex >= 0)
    {
        char mem;
        int memID;
        // Check book in stock or not
        if(stock[bookIndex] > 0)
        {
            cout << "Are you a member(Y/N): ";
            cin >> mem;
            // If customer is a member
            if(mem == 'Y' || mem == 'y')
            {
                cout << "Enter member ID: ";
                cin >> memID;

                // Find member in database
                for(i = 0; i < totalMembers; i++)
                {
                    if(memID == memberID[i])
                    {
                        memIndex = i;
                        break;
                    }
                    else
                        memIndex = -1;
                }

                // If member found
                if(memIndex >= 0)
                {
                    // Find discount if member has paid membership
                    if(membershipFee[memIndex] == 'Y' || membershipFee[memIndex] == 'y')
                        discount = 5 * bookPrice[bookIndex] / 100;
                    else
                        discount = 0;

                    // Add average of amount spent in discount if booksBought = 10 and set spent amount to 0
                    if(booksBought[memIndex] == maxBook)
                    {
                        discount += amountSpent[memIndex] / 10;
                    }
                }
                else
                {
                    cout << "\n\t MEMBER DOES NOT EXISTS \n" << endl;
                }
            }
            // Show book cost
            int buy;
            cout << "\n Cost of book: " << bookPrice[bookIndex] << endl
                 << "Discount = " << discount << endl
                 << "Book Price: " << (bookPrice[bookIndex] - discount) << endl
                 << "Press 1 to buy: ";
            cin >> buy;

            if(buy == 1)
            {
                cout << "\n Book Purchased. Thanks. \n" << endl;
                if(mem == 'Y' || mem == 'y')
                {
                    // updating value in database of member
                    if(booksBought[memIndex] == maxBook)
                    {
                        amountSpent[memIndex] = 0;
                    }
                    else
                    {
                        // If books bought < 10, increment books bought and add price in amount spent
                        booksBought[memIndex]++;
                        amountSpent[memIndex] += bookPrice[bookIndex];
                    }
                }
            }
        }
        else
        {
            cout << "\n\t BOOK IS NOT IN STORE \n" << endl;
        }
    }
}

/**
* Book store menu for accessing books and members
*/

void bookStore :: bookStoreMenu()
{
    int choice,
        memID;

    cout << "\n\t BOOK STORE MENU \n" << endl;

    do
    {
        do
        {
            cout << "Select any option" << endl
                 << "1 \t Book Menu" << endl
                 << "2 \t Membership Menu" << endl
                 << "3 \t Buy Book" << endl
                 << "0 \t EXIT" << endl
                 << "\n Enter your choice: ";
            cin >> choice;

            switch(choice)
            {
                case 1:
                    bookMenu();
                    break;

                case 2:
                    memberMenu();
                    break;

                case 3:
                    buyBook();
                    break;

                case 0:
                    cout << "\n\t EXIT" << endl;
                    break;

                default:
                    cout << "\n\t WRONG CHOICE" << endl;
                    break;
            }

        }while(choice < 0 || choice > 3);

    }while(choice != 0);
}

// Main Method

int main()
{
    bookStore book;

    book.bookStoreMenu();

    return 0;
}


//book.in

// 2
// Book title1
// 2
// author 1
// author 2
// publisher 1
// 101
// 200
// 2009
// 10
// Book title2
// 3
// author 1
// author 2
// author 3
// publisher 2
// 1002
// 200
// 2010
// 10


// member.in

// 2
// Book title1
// 2
// author 1
// author 2
// publisher 1
// 101
// 200
// 2009
// 10
// Book title2
// 3
// author 1
// author 2
// author 3
// publisher 2
// 1002
// 200
// 2010
// 10