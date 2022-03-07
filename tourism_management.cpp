// Tourist management CopyRights Hashtag corp

#include <conio.h>
#include <iostream>
#include <limits>
#include <fstream>
#include <iomanip>
#include <unistd.h>
#include <string>

using namespace std;
#define size 100
int reserve = 999;
int cancel = 0;
int seat[size];

string EnterPass()
{
    string numAsString = "";
    char ch = getch();

    while (ch != '\r')
    {
        cout << '*';
        numAsString += ch;
        ch = getch();
    }

    return numAsString;
}

//          TYPECAST:
//
//   while (!(cin >> x))
//         {
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');
//             cout << "Invalid input.  Try again: ";
//         }

//--------------------------------------------------------------------------------
//                     MAKING NODES FOR LINK LISTS  FLIGHT MANGER
//--------------------------------------------------------------------------------

struct node
{
    string fname, lname, origin, destination, menu, phone_num;
    long long int ID;
    int reserve_num, seat_num, price;
    node *next;
};

//--------------------------------------------------------------------------------
//                                FLIGHT MANGER
//--------------------------------------------------------------------------------

class ll
{
private:
    node *start, *temp, *temp2;

public:
    ll()
    {
        start = NULL;
        temp = NULL;
        temp2 = NULL;
    }

    // void seat_fill()
    // {
    //     for (int i = 0; i < size; i++)
    //     {
    //         seat[i] = 0;
    //     }
    // }

    //--------------------------------------------------------------------------------
    //      THIS FUNCTIION IS CHECKING FOR THE SEATS THAT ARE AVAILABLE OR BOOKED
    //--------------------------------------------------------------------------------
    

    bool taken = false;
    bool seat_no(int y)
    {

        for (int i = 0; i < size; i++)
        {
            if (seat[i] == -1)
            {
                taken = true;
                cout << "The seat is taken already. \n";
                cout << "Please choose another seat number from below." << endl;

                int j = 1;
                while (j < size + 1)
                {
                    if (seat[j - 1] == -1)
                        j++;
                    else
                    {
                        cout << "|" << j << "|";
                        if (j % 10 == 0)
                            cout << endl;
                        j++;
                    }
                }
            }
        }
        return true;
    }

    //--------------------------------------------------------------------------------
    //     THIS FUNCTION IS RESERVING SEATS AND GETTING DETAILS FROM USER
    //--------------------------------------------------------------------------------

    void make_reservation()
    {
        temp = new node;

        cout << "\n\nEnter First Name : ";
        cin.ignore();
        getline(cin, temp->fname);
        cout << "--------------------------------\n";

        //--------------------------------------------------------------------------------

        cout << "Enter Last Name : ";
        cin.ignore();
        getline(cin, temp->lname);
        cout << "--------------------------------\n";

        //--------------------------------------------------------------------------------

        cout << "Enter 13-digit CNIC ID : ";

        while (!(cin >> temp->ID))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.  Try again: ";
        }

        if (to_string(temp->ID).length() != 13)
        {
            do
            {
                cout << " Invalid Entry !!!";
                cout << " Try again. \n";
                cout << "Enter 13-digit CNIC ID : ";
                while (!(cin >> temp->ID))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input.  Try again: ";
                }

            } while (to_string(temp->ID).length() != 13);
            cout << "--------------------------------\n";
        }
        else
        {
            cout << "--------------------------------\n";
        }

        //--------------------------------------------------------------------------------

        cout << "Enter Phone Number of Person: ";
        cin >> temp->phone_num;

        if (temp->phone_num.length() != 11)
        {
            do
            {
                cout << " Invalid Entry !!!";
                cout << " Try again. \n";
                cout << "Enter Phone Number of Person: ";
                cin >> temp->phone_num;

            } while (temp->phone_num.length() != 11);
            cout << "--------------------------------\n";
        }
        else
        {
            cout << "--------------------------------\n";
        }

        //--------------------------------------------------------------------------------
        //              CONDITIONAL STATEMENTS FOR THE ROUTE OF PASSENGER
        //--------------------------------------------------------------------------------
    me:
        cout << " Choose one of the following cities below \n";
        cout << " @----- LAHORE \n @----- ISLAMABAD \n @----- KARACHI \n";

        cout << "\t\t\t\t\t------------------------------------------------------\n";
        cout << "\t\t\t\t\tDestination & Origin city should be in same format!!! \n";
        cout << "\t\t\t\t\t------------------------------------------------------\n";

        cout << "Enter Origin city : ";
        cin >> temp->origin;

        if ((temp->origin != "lahore" && temp->origin != "LAHORE" && temp->origin != "karachi" &&
             temp->origin != "KARACHI" && temp->origin != "islamabad" && temp->origin != "ISLAMABAD"))
        {
            do
            {
                cout << " Invalid Entry !!!";
                cout << " Try again. \n";
                cout << "Enter Origin city : ";
                cin >> temp->origin;

            } while ((temp->origin != "lahore" && temp->origin != "LAHORE" && temp->origin != "karachi" &&
                      temp->origin != "KARACHI" && temp->origin != "islamabad" && temp->origin != "ISLAMABAD"));
            cout << "--------------------------------\n";
        }
        else
        {
            cout << "--------------------------------\n";
        }

        // ------------------------------------------------------------------------------------------------------------------

        cout << "Enter Destination city : ";
        cin.ignore();
        cin.clear();
        cin >> temp->destination;

        if ((temp->destination != "lahore" && temp->destination != "LAHORE" && temp->destination != "karachi" &&
             temp->destination != "KARACHI" && temp->destination != "islamabad" && temp->destination != "ISLAMABAD"))
        {
            do
            {
                cout << " Invalid Entry !!!";
                cout << " Try again. \n";
                cout << "Enter Destination city : ";
                cin >> temp->destination;

            } while ((temp->destination != "lahore" && temp->destination != "LAHORE" && temp->destination != "karachi" &&
                      temp->destination != "KARACHI" && temp->destination != "islamabad" && temp->destination != "ISLAMABAD"));
            cout << "--------------------------------\n";
        }
        else
        {
            cout << "--------------------------------\n";
        }

        // ------------------------------------------------------------------------------------------------------------------

        if ((temp->origin == "LAHORE" && temp->destination == "ISLAMABAD") || (temp->origin == "ISLAMABAD" && temp->destination == "LAHORE"))
        {
            string ret;
            cout << "DO YOU WANT TO TAKE A RETURN TICKET?? \n Press y|Y for yes and any key for no : ";
            cin >> ret;
            if (ret == "Y" || ret == "y")
            {
                temp->price = 8500 * 2;
                cout << "Price is :" << temp->price << "Rs" << endl;
            }
            else
            {
                temp->price = 8500;
                cout << "Price is :" << temp->price << "Rs" << endl;
            }
        }
        else if ((temp->origin == "LAHORE" && temp->destination == "KARACHI") || (temp->origin == "KARACHI" && temp->destination == "LAHORE"))
        {

            {
                string ret;
                cout << "DO YOU WANT TO TAKE A RETURN TICKET?? \n Press y|Y for yes and any key for no : ";
                cin >> ret;
                if (ret == "Y" || ret == "y")
                {
                    temp->price = 12000 * 2;
                    cout << "Price is :" << temp->price << "Rs" << endl;
                }
                else
                {
                    temp->price = 1200;
                    cout << "Price is :" << temp->price << "Rs" << endl;
                }
            }
        }
        else if ((temp->origin == "ISLAMABAD" && temp->destination == "KARACHI") || (temp->origin == "KARACHI" && temp->destination == "ISLAMABAD"))
        {
            {
                string ret;
                cout << "DO YOU WANT TO TAKE A RETURN TICKET?? \n Press y|Y for yes and any key for no : ";
                cin >> ret;
                if (ret == "Y" || ret == "y")
                {
                    temp->price = 18000 * 2;
                    cout << "Price is :" << temp->price << "Rs" << endl;
                }
                else
                {
                    temp->price = 18000;
                    cout << "Price is :" << temp->price << "Rs" << endl;
                }
            }
        }
        else if ((temp->origin == "lahore" && temp->destination == "islamabad") || (temp->origin == "islamabad" && temp->destination == "lahore"))
        {
            string ret;
            cout << "DO YOU WANT TO TAKE A RETURN TICKET?? \n Press y|Y for yes and any key for no : ";
            cin >> ret;
            if (ret == "Y" || ret == "y")
            {
                temp->price = 8500 * 2;
                cout << "Price is :" << temp->price << "Rs" << endl;
            }
            else
            {
                temp->price = 8500;
                cout << "Price is :" << temp->price << "Rs" << endl;
            }
        }

        else if ((temp->origin == "lahore" && temp->destination == "karachi") || (temp->origin == "karachi" && temp->destination == "lahore"))
        {

            {
                string ret;
                cout << "DO YOU WANT TO TAKE A RETURN TICKET?? \n Press y|Y for yes and any key for no : ";
                cin >> ret;
                if (ret == "Y" || ret == "y")
                {
                    temp->price = 12000 * 2;
                    cout << "Price is :" << temp->price << "Rs" << endl;
                }
                else
                {
                    temp->price = 1200;
                    cout << "Price is :" << temp->price << "Rs" << endl;
                }
            }
        }
        else if ((temp->origin == "islamabad" && temp->destination == "karachi") || (temp->origin == "karachi" && temp->destination == "islamabad"))
        {
            {
                string ret;
                cout << "DO YOU WANT TO TAKE A RETURN TICKET?? \n Press y|Y for yes and any key for no : ";
                cin >> ret;
                if (ret == "Y" || ret == "y")
                {
                    temp->price = 18000 * 2;
                    cout << "Price is :" << temp->price << "Rs" << endl;
                }
                else
                {
                    temp->price = 18000;
                    cout << "Price is :" << temp->price << "Rs" << endl;
                }
            }
        }
        else
        {
            cout << " \t\t\t\t\t\n\n\nDestination & Origin city can not be same. Try Again.\n\n\n";
            goto me;
        }

        //--------------------------------------------------------------------------------
        //                 TAKING SEAT NUMBER
        //--------------------------------------------------------------------------------
        int meal_choice, x;

        do
        {
            cout << "\n..................................................\n";
        zx:
            cout << "Please Enter the Seat Number: ";

            while (!(cin >> x))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input.  Try again: ";
            }

            while (x > 100 || x <= 0)
            {
                cout << "   Try again:: ";
                goto zx;
            }

            cout << "--------------------------------\n";
            if ((seat[x - 1]) > -1)
                taken = false;
            else
                seat_no(x);
            seat[x - 1] = -1;
            temp->seat_num = x;
        } while (taken == true);

        //--------------------------------------------------------------------------------
        //                                MEAL PACKAGES
        //--------------------------------------------------------------------------------

        cout << "Please Enter Your Menu Preference from below: \n\n";
        cout << "   Veg     ..... '1'\n";
        cout << "   Non-Veg ..... '2'\n";
        cout << "   No meal ..... '3'\n\n";

    po:
        cout << "   \nEnter Your Choice :: ";
        while (!(cin >> meal_choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.  Try again: ";
        }

        switch (meal_choice)
        {
        case 1:
            temp->menu = "veg";
            break;

        case 2:
            temp->menu = "Non-Veg";
            break;

        case 3:
            temp->menu = "No meal";
            break;

        default:
            cout << "\n INVALID INPUT;  Try again::";
            goto po;

            break;
        }

        reserve++;
        temp->reserve_num = reserve;
        cout << "\n\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
        cout << "\t\t\t\t\t           YOUR RESERVATION NUMBER IS :: " << reserve;
        cout << "\n\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";

        temp->next = NULL;

        if (start == NULL)
            start = temp;
        else
        {
            temp2 = start;
            while (temp2->next != NULL)
            {
                temp2 = temp2->next;
            }
            temp2->next = temp;
        }

        //--------------------------------------------------------------------------------
        //                            MAKING A RECIPET
        //--------------------------------------------------------------------------------

        cout << "\n\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
        cout << "\t\t\t\t\t                        :: RECEIPT :: ";
        cout << "\n\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";

        cout << "First Name : " << temp->fname << endl;
        cout << "Last Name : " << temp->lname << endl;
        cout << "CNIC ID : " << temp->ID << endl;
        cout << "Phone number: " << temp->phone_num << endl;
        cout << "Seat Number: " << temp->seat_num << endl;
        cout << "Reservation No. " << temp->reserve_num << endl;
        cout << "Origin : " << temp->origin << endl;
        cout << "Destination : " << temp->destination << endl;
        cout << "Prize : " << temp->price << endl;

        //--------------------------------------------------------------------------------
        //                           WRITING DATA IN FILE
        //--------------------------------------------------------------------------------

        ofstream os("linkedList.txt", ios::out | ios::app);
        os << "First name: " << temp->fname << endl;
        os << "Last name: " << temp->lname << endl;
        os << "CNIC: " << temp->ID << endl;
        os << "Contact: " << temp->phone_num << endl;
        os << "Reservation number: " << temp->reserve_num << endl;
        os << "Origin: " << temp->origin << endl;
        os << "Destination: " << temp->destination << endl;
        os << "Prize: " << temp->price << endl;

        os.close();
        // return 0;
        cout << endl;
        cout << "\t\t\t\t\txxxxxxxxx:::::: PRESS ENTER TO CONTINUE ::::::::xxxxxxxxx\n";

        cin.get();
        if (cin.get() == '\n')
        {
            cout << "\n..................................................\n";
            system("CLS");
        }
    }

    //--------------------------------------------------------------------------------
    //              THIS FUNCTION IS CANCELLING THE RESERVATION
    //--------------------------------------------------------------------------------

    int cancel = 0;
    void cancel_reservation()
    {
        int num;
        cout << "Please Enter your reservation Number here: ";
        while (!(cin >> num))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.  Try again: ";
        }

        node *cur = start;
        if (cur != NULL)
        {

            if (start->reserve_num == num)
            {
                node *del = start;
                start = start->next;
                delete del;
                seat[0] = 0;
                cancel++;
                return;
            }
            else
            {
                node *pre, *cur;
                pre = start;
                cur = start->next;
                while (cur != NULL)
                {
                    if (cur->reserve_num == num)
                        break;
                    pre = cur;
                    cur = cur->next;
                }
                seat[cur->seat_num - 1] = 0;
                if (cur != NULL)
                    pre->next = cur->next;
            }

            cancel++;
        }
        else
        {
            cout << "!!! * Nothing to delete or invalid entry * !!! \n"
                 << endl;
        }
        ofstream fout("linkedList.txt", ios::trunc);
        node *temp = start;
        system("pause");
        while (temp != NULL)
        {
            fout << "\n"
                 << temp->fname << " " << temp->lname << " " << temp->ID << " " << temp->phone_num << " " << temp->menu << " " << temp->origin << " " << temp->destination << " " << temp->reserve_num << " " << temp->seat_num << " " << temp->price;
            temp = temp->next;
        }

        fout.close();
    }

    //--------------------------------------------------------------------------------
    //
    //--------------------------------------------------------------------------------

    void search_passenger()
    {
        int fake;
        cout << "Please enter your seat number here: ";
        while (!(cin >> fake))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.  Try again: ";
        }

        node *cur = start;
        while (cur != NULL)
        {
            if (cur->seat_num == fake)
            {
                cout << "First Name : " << cur->fname << endl;
                cout << "Last Name : " << cur->lname << endl;
                cout << "CNIC ID : " << cur->ID << endl;
                cout << "Phone number: " << cur->phone_num << endl;
                cout << "Seat Number: " << cur->seat_num << endl;
                cout << "Reservation No. " << cur->reserve_num << endl;
                cout << "Origin : " << cur->origin << endl;
                cout << "Destination : " << cur->destination << endl;
                cout << "Prize : " << cur->price << endl;
                return;
            }
            cur = cur->next;
        }
        cout << " Sorry!!! NOT FOUND \n\n";
    }

    //--------------------------------------------------------------------------------
    //
    //--------------------------------------------------------------------------------

    void change_reservation()

    {
        int option, next_seat;
    tt:
        cout << " \n Please enter your seat number: ";
        cin >> option;
        while (!option)
        {
            cin.clear();
            cin.ignore();
            cout << "\n INVALID INPUT;  Try again::";
            cin >> option;
            break;
        }

        node *cur;
        cur = start;

        while (cur != NULL)
        {
            if (cur->seat_num == option)
            {
                break;
                cur = cur->next;
            }
            else

                cout << " Seat not found :: Try again : ";
            goto tt;
        }
        cout << "Please choose another seat number from below.";
        int j = 1;
        while (j < size + 1)
        {
            if (seat[j - 1] == -1)
                j++;
            else
            {
                cout << "| " << j << "|";
                if (j % 10 == 0)
                    cout << endl;
                j++;
            }
        }
        cin >> next_seat;
        seat[cur->seat_num - 1] = 0;
        cur->seat_num = next_seat;
        seat[next_seat - 1] = -1;
    }

    //--------------------------------------------------------------------------------
    //
    //--------------------------------------------------------------------------------

    void print_list()
    {
        temp = start;
        if (temp == NULL)
            cout << " End of lists" << endl;
        else
        {
            int cnt = 1;

            while (temp != NULL)
            {
                cout << "First Name : " << temp->fname << endl;
                cout << "Last Name : " << temp->lname << endl;
                cout << "CNIC ID : " << temp->ID << endl;
                cout << "Phone number: " << temp->phone_num << endl;
                cout << "Seat Number: " << temp->seat_num << endl;
                cout << "Reservation No. " << temp->reserve_num << endl;
                cout << "Origin : " << temp->origin << endl;
                cout << "Destination : " << temp->destination << endl;
                cout << "Prize : " << temp->price << endl;

                temp = temp->next;
                cnt++;
            }
            cout << "\n\n";
        }
    }

    //--------------------------------------------------------------------------------
    //
    //--------------------------------------------------------------------------------

    void print_report()
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (seat[i] == -1)
                count++;
        }
        cout << "The number of reserved seats are: " << count << endl;
        cout << "The number of cancellations are: " << cancel << endl;
    }
};

//--------------------------------------------------------------------------------
//                     MAKING NODES FOR LINK LISTS  HOTEL MANAGER
//--------------------------------------------------------------------------------

struct Node
{
    string data1, data2, data3;
    int data;
    struct Node *next;
};

//--------------------------------------------------------------------------------
//                                HOTEL MANAGER
//--------------------------------------------------------------------------------

Node *head = NULL, *curr = NULL;
class linked_list
{

public:
    //--------------------------------------------------------------------------------
    //                            BOOK ROOM
    //--------------------------------------------------------------------------------

    int book_Room(int n, string name, string address, string contact)
    {
        Node *tmp = new Node;
        tmp->data = n;
        tmp->data1 = name;
        tmp->data2 = address;
        tmp->data3 = contact;
        tmp->next = NULL;

        if (head != NULL)
        {
            Node *tmp2 = head;
            while (tmp2 != NULL)
            {
                //--------------------------------------------------------------------------------
                //                  CONDITION FOR ALREADY BOOK ROOM
                //--------------------------------------------------------------------------------
                if (tmp2->data == n)
                {
                    cout << "ALREADY BOOKED" << endl;
                    return 1;
                }
                else
                {
                    tmp2 = tmp2->next;
                }
            }
            curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = tmp;
        }
        else
        {
            head = tmp;
        }
        //--------------------------------------------------------------------------------
        //                         WRITING DATA IN FILE
        //--------------------------------------------------------------------------------
        ofstream os("linked.txt", ios::out | ios::app);
        os << "Room no : " << tmp->data << endl;
        os << "Name : " << tmp->data1 << endl;
        os << "Address : " << tmp->data2 << endl;
        os << "Contact : " << tmp->data3 << endl
           << endl;
        os.close();

        return 0;
    }
    //--------------------------------------------------------------------------------
    //                          ROOM ALLOCATION
    //--------------------------------------------------------------------------------
    void room_Allocation()
    {
        Node *temp = head;

        int j = 1;
        while (temp != NULL)
        {
            //--------------------------------------------------------------------------------
            //                    DISPLAYING DATA
            //--------------------------------------------------------------------------------
            cout << "BOOKING NUMBER :" << j << endl
                 << endl;
            cout << "Room number :" << temp->data << endl;
            cout << "Name :" << temp->data1 << endl;
            cout << "Address :" << temp->data2 << endl;
            cout << "contact :" << temp->data3 << endl
                 << endl
                 << endl;

            temp = temp->next;
            j++;
        }
    }
    //--------------------------------------------------------------------------------
    //                          SEARCHING OF COSTOMERS
    //--------------------------------------------------------------------------------
    int Costomer_records(int room)
    {
        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->data == room)
            {

                cout << "Guest stayed at room number " << temp->data << "is :" << temp->data1 << endl;
                cout << "Address is :" << temp->data2 << endl;
                cout << "Contact is :" << temp->data3 << endl;
                return 1;
            }
            else
            {
                temp = temp->next;
            }
        }
        cout << "Room data if not found" << endl;
        return 0;
    }
    //--------------------------------------------------------------------------------
    //                      DELETE RECORD
    //--------------------------------------------------------------------------------
    int Del_Record(int pos)
    {
        Node *temp = head;
        Node *next_node = NULL;
        int i = 1;
        while (i < pos - 1)
        {
            if (temp->next == NULL)
            {
                cout << "Room not found";
                return 0;
            }
            else
            {

                temp = temp->next;
                i++;
            }
        }
        next_node = temp->next;
        temp->next = next_node->next;
        free(next_node);
        return 0;
    }
    //--------------------------------------------------------------------------------
    //                         UPDATE RECORD FROM LINK LIST
    //--------------------------------------------------------------------------------
    void update_roomRecord(int data, string nme, string add, string cont)
    {
        Node *temp = head;

        int count = 0;
        if (head == NULL)
        {
            cout << "Invalid room No" << endl;
        }
        while (temp != NULL)

        {
            count = count + 1;
            if (temp->data == data)
            {
                temp->data1 = nme;
                temp->data2 = add;
                temp->data3 = cont;
                cout << "record Updated" << endl;
            }
            if (temp->next != NULL)
            {

                temp = temp->next;
            }
            else
            {
                break;
            }
        }
    }
    //--------------------------------------------------------------------------------
    //                              GET BILLS
    //--------------------------------------------------------------------------------
    void bill(int r_no, int D)
    {
        int total;
        if (r_no <= 20)
        {
            cout << "One day rent is 7000Rs" << endl;
            total = 7000 * D;
            cout << "Total Bill is :" << total << "Rs" << endl;
        }
        else if (r_no >= 21 && r_no <= 40)
        {
            cout << "One day rent is 5000Rs" << endl;
            total = 5000 * D;
            cout << "Total Bill is :" << total << "Rs" << endl;
        }
        else if (r_no >= 41 && r_no <= 50)
        {
            cout << "One day rent is 3000Rs" << endl;
            total = 3000 * D;
            cout << "Total Bill is :" << total << "Rs" << endl;
        }
        else
        {
            cout << "Room not available" << endl;
        }
    }
    //--------------------------------------------------------------------------------
    //                          DEL FIRST RECORD
    //--------------------------------------------------------------------------------
    void del_first()
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "No such room exist " << endl;
        }
        else
        {
            head = head->next;
            free(temp);
        }
    }
};

//--------------------------------------------------------------------------------
//                     MAKING NODES FOR LINK LISTS RAILWAY MANAGER
//--------------------------------------------------------------------------------

int reserve2 = 499;
int seat2[size];

struct node2
{
    string fname, lname, origin, destination, menu, phone_num;
    long long int ID;
    int reserve_num, seat_num, price;
    node2 *next;
};

//--------------------------------------------------------------------------------
//                                RAILWAY MANAGER
//--------------------------------------------------------------------------------

class Railway
{
private:
    node2 *start, *temp, *temp2;

public:
    Railway()
    {
        start = NULL;
        temp = NULL;
        temp2 = NULL;
    }

    //--------------------------------------------------------------------------------
    //      THIS FUNCTIION IS CHECKING FOR THE SEATS THAT ARE AVAILABLE OR BOOKED
    //--------------------------------------------------------------------------------

    bool taken = false;
    bool seat_no(int y)
    {

        for (int i = 0; i < size; i++)
        {
            if (seat2[i] == -1)
            {
                taken = true;
                cout << "The seat is taken already. \n";
                cout << "Please choose another seat number from below." << endl;

                int j = 1;
                while (j < size + 1)
                {
                    if (seat2[j - 1] == -1)
                        j++;
                    else
                    {
                        cout << "|" << j << "|";
                        if (j % 10 == 0)
                            cout << endl;
                        j++;
                    }
                }
            }
        }
        return true;
    }

    //--------------------------------------------------------------------------------
    //     THIS FUNCTION IS RESERVING SEATS AND GETTING DETAILS FROM USER
    //--------------------------------------------------------------------------------

    void make_reservation()
    {
        temp = new node2;

        cout << "\n\nEnter First Name : ";
        cin.ignore();
        getline(cin, temp->fname);
        cout << "--------------------------------\n";

        //--------------------------------------------------------------------------------

        cout << "Enter Last Name : ";
        cin.ignore();
        getline(cin, temp->lname);
        cout << "--------------------------------\n";

        //--------------------------------------------------------------------------------

        cout << "Enter 13-digit CNIC ID : ";

        while (!(cin >> temp->ID))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.  Try again: ";
        }

        if (to_string(temp->ID).length() != 13)
        {
            do
            {
                cout << " Invalid Entry !!!";
                cout << " Try again. \n";
                cout << "Enter 13-digit CNIC ID : ";
                while (!(cin >> temp->ID))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input.  Try again: ";
                }

            } while (to_string(temp->ID).length() != 13);
            cout << "--------------------------------\n";
        }
        else
        {
            cout << "--------------------------------\n";
        }

        //--------------------------------------------------------------------------------

        cout << "Enter Phone Number of Person: ";
        cin >> temp->phone_num;

        if (temp->phone_num.length() != 11)
        {
            do
            {
                cout << " Invalid Entry !!!";
                cout << " Try again. \n";
                cout << "Enter Phone Number of Person: ";
                cin >> temp->phone_num;

            } while (temp->phone_num.length() != 11);
            cout << "--------------------------------\n";
        }
        else
        {
            cout << "--------------------------------\n";
        }

        //--------------------------------------------------------------------------------
        //              CONDITIONAL STATEMENTS FOR THE ROUTE OF PASSENGER
        //--------------------------------------------------------------------------------
    me:
        cout << " Choose one of the following cities below \n";
        cout << " @----- LAHORE \n @----- ISLAMABAD \n @----- KARACHI \n";

        cout << "\t\t\t\t\t------------------------------------------------------\n";
        cout << "\t\t\t\t\tDestination & Origin city should be in same format!!! \n";
        cout << "\t\t\t\t\t------------------------------------------------------\n";

        cout << "Enter Origin city : ";
        cin >> temp->origin;

        if ((temp->origin != "lahore" && temp->origin != "LAHORE" && temp->origin != "karachi" &&
             temp->origin != "KARACHI" && temp->origin != "islamabad" && temp->origin != "ISLAMABAD"))
        {
            do
            {
                cout << " Invalid Entry !!!";
                cout << " Try again. \n";
                cout << "Enter Origin city : ";
                cin >> temp->origin;

            } while ((temp->origin != "lahore" && temp->origin != "LAHORE" && temp->origin != "karachi" &&
                      temp->origin != "KARACHI" && temp->origin != "islamabad" && temp->origin != "ISLAMABAD"));
            cout << "--------------------------------\n";
        }
        else
        {
            cout << "--------------------------------\n";
        }

        // ------------------------------------------------------------------------------------------------------------------

        cout << "Enter Destination city : ";
        cin.ignore();
        cin.clear();
        cin >> temp->destination;

        if ((temp->destination != "lahore" && temp->destination != "LAHORE" && temp->destination != "karachi" &&
             temp->destination != "KARACHI" && temp->destination != "islamabad" && temp->destination != "ISLAMABAD"))
        {
            do
            {
                cout << " Invalid Entry !!!";
                cout << " Try again. \n";
                cout << "Enter Destination city : ";
                cin >> temp->destination;

            } while ((temp->destination != "lahore" && temp->destination != "LAHORE" && temp->destination != "karachi" &&
                      temp->destination != "KARACHI" && temp->destination != "islamabad" && temp->destination != "ISLAMABAD"));
            cout << "--------------------------------\n";
        }
        else
        {
            cout << "--------------------------------\n";
        }

        // ------------------------------------------------------------------------------------------------------------------

        if ((temp->origin == "LAHORE" && temp->destination == "ISLAMABAD") || (temp->origin == "ISLAMABAD" && temp->destination == "LAHORE"))
        {
            string ret;
            cout << "DO YOU WANT TO TAKE A RETURN TICKET?? \n Press y|Y for yes and any key for no : ";
            cin >> ret;
            if (ret == "Y" || ret == "y")
            {
                temp->price = 8500 * 2;
                cout << "Price is :" << temp->price << "Rs" << endl;
            }
            else
            {
                temp->price = 8500;
                cout << "Price is :" << temp->price << "Rs" << endl;
            }
        }
        else if ((temp->origin == "LAHORE" && temp->destination == "KARACHI") || (temp->origin == "KARACHI" && temp->destination == "LAHORE"))
        {

            {
                string ret;
                cout << "DO YOU WANT TO TAKE A RETURN TICKET?? \n Press y|Y for yes and any key for no : ";
                cin >> ret;
                if (ret == "Y" || ret == "y")
                {
                    temp->price = 12000 * 2;
                    cout << "Price is :" << temp->price << "Rs" << endl;
                }
                else
                {
                    temp->price = 1200;
                    cout << "Price is :" << temp->price << "Rs" << endl;
                }
            }
        }
        else if ((temp->origin == "ISLAMABAD" && temp->destination == "KARACHI") || (temp->origin == "KARACHI" && temp->destination == "ISLAMABAD"))
        {
            {
                string ret;
                cout << "DO YOU WANT TO TAKE A RETURN TICKET?? \n Press y|Y for yes and any key for no : ";
                cin >> ret;
                if (ret == "Y" || ret == "y")
                {
                    temp->price = 18000 * 2;
                    cout << "Price is :" << temp->price << "Rs" << endl;
                }
                else
                {
                    temp->price = 18000;
                    cout << "Price is :" << temp->price << "Rs" << endl;
                }
            }
        }
        else if ((temp->origin == "lahore" && temp->destination == "islamabad") || (temp->origin == "islamabad" && temp->destination == "lahore"))
        {
            string ret;
            cout << "DO YOU WANT TO TAKE A RETURN TICKET?? \n Press y|Y for yes and any key for no : ";
            cin >> ret;
            if (ret == "Y" || ret == "y")
            {
                temp->price = 8500 * 2;
                cout << "Price is :" << temp->price << "Rs" << endl;
            }
            else
            {
                temp->price = 8500;
                cout << "Price is :" << temp->price << "Rs" << endl;
            }
        }

        else if ((temp->origin == "lahore" && temp->destination == "karachi") || (temp->origin == "karachi" && temp->destination == "lahore"))
        {

            {
                string ret;
                cout << "DO YOU WANT TO TAKE A RETURN TICKET?? \n Press y|Y for yes and any key for no : ";
                cin >> ret;
                if (ret == "Y" || ret == "y")
                {
                    temp->price = 12000 * 2;
                    cout << "Price is :" << temp->price << "Rs" << endl;
                }
                else
                {
                    temp->price = 1200;
                    cout << "Price is :" << temp->price << "Rs" << endl;
                }
            }
        }
        else if ((temp->origin == "islamabad" && temp->destination == "karachi") || (temp->origin == "karachi" && temp->destination == "islamabad"))
        {
            {
                string ret;
                cout << "DO YOU WANT TO TAKE A RETURN TICKET?? \n Press y|Y for yes and any key for no : ";
                cin >> ret;
                if (ret == "Y" || ret == "y")
                {
                    temp->price = 18000 * 2;
                    cout << "Price is :" << temp->price << "Rs" << endl;
                }
                else
                {
                    temp->price = 18000;
                    cout << "Price is :" << temp->price << "Rs" << endl;
                }
            }
        }
        else
        {
            cout << " \t\t\t\t\t\n\n\nDestination & Origin city can not be same. Try Again.\n\n\n";
            goto me;
        }

        //--------------------------------------------------------------------------------
        //                 TAKING SEAT NUMBER
        //--------------------------------------------------------------------------------
        int meal_choice, x;

        do
        {
            cout << "\n..................................................\n";
        zx:
            cout << "Please Enter the Seat Number: ";

            while (!(cin >> x))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input.  Try again: ";
            }

            while (x > 100 || x <= 0)
            {
                cout << "   Try again:: ";
                goto zx;
            }

            cout << "--------------------------------\n";
            if ((seat2[x - 1]) > -1)
                taken = false;
            else
                seat_no(x);
            seat2[x - 1] = -1;
            temp->seat_num = x;
        } while (taken == true);

        reserve2++;
        temp->reserve_num = reserve2;
        cout << "\n\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
        cout << "\t\t\t\t\t           YOUR TICKET NUMBER IS :: " << reserve2;
        cout << "\n\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";

        temp->next = NULL;

        if (start == NULL)
            start = temp;
        else
        {
            temp2 = start;
            while (temp2->next != NULL)
            {
                temp2 = temp2->next;
            }
            temp2->next = temp;
        }

        //--------------------------------------------------------------------------------
        //                            MAKING A RECIPET
        //--------------------------------------------------------------------------------

        cout << "\n\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
        cout << "\t\t\t\t\t                        :: RECEIPT :: ";
        cout << "\n\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";

        cout << "First Name : " << temp->fname << endl;
        cout << "Last Name : " << temp->lname << endl;
        cout << "CNIC ID : " << temp->ID << endl;
        cout << "Phone number: " << temp->phone_num << endl;
        cout << "Seat Number: " << temp->seat_num << endl;
        cout << "Ticket No. " << temp->reserve_num << endl;
        cout << "Origin : " << temp->origin << endl;
        cout << "Destination : " << temp->destination << endl;
        cout << "Prize : " << temp->price << endl;

        //--------------------------------------------------------------------------------
        //                           WRITING DATA IN FILE
        //--------------------------------------------------------------------------------

        ofstream os("linkedList.txt", ios::out | ios::app);
        os << "First name: " << temp->fname << endl;
        os << "Last name: " << temp->lname << endl;
        os << "CNIC: " << temp->ID << endl;
        os << "Contact: " << temp->phone_num << endl;
        os << "Ticket number: " << temp->reserve_num << endl;
        os << "Origin: " << temp->origin << endl;
        os << "Destination: " << temp->destination << endl;
        os << "Prize: " << temp->price << endl;

        os.close();
        // return 0;
        cout << endl;
        cout << "\t\t\t\t\txxxxxxxxx:::::: PRESS ENTER TO CONTINUE ::::::::xxxxxxxxx\n";

        cin.get();
        if (cin.get() == '\n')
        {
            cout << "\n..................................................\n";
            system("CLS");
        }
    }

    //--------------------------------------------------------------------------------
    //              THIS FUNCTION IS CANCELLING THE RESERVATION
    //--------------------------------------------------------------------------------

    int cancel = 0;
    void cancel_reservation()
    {
        int num;
        cout << "Please Enter your reservation Number here: ";
        while (!(cin >> num))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.  Try again: ";
        }

        node2 *cur = start;
        if (cur != NULL)
        {

            if (start->reserve_num == num)
            {
                node2 *del = start;
                start = start->next;
                delete del;
                seat2[0] = 0;
                cancel++;
                return;
            }
            else
            {
                node2 *pre, *cur;
                pre = start;
                cur = start->next;
                while (cur != NULL)
                {
                    if (cur->reserve_num == num)
                        break;
                    pre = cur;
                    cur = cur->next;
                }
                seat2[cur->seat_num - 1] = 0;
                if (cur != NULL)
                    pre->next = cur->next;
            }

            cancel++;
        }
        else
        {
            cout << "!!! * Nothing to delete or invalid entry * !!! \n"
                 << endl;
        }
        ofstream fout("linkedList.txt", ios::trunc);
        node2 *temp = start;
        system("pause");
        while (temp != NULL)
        {
            fout << "\n"
                 << temp->fname << " " << temp->lname << " " << temp->ID << " " << temp->phone_num << " " << temp->menu << " " << temp->origin << " " << temp->destination << " " << temp->reserve_num << " " << temp->seat_num << " " << temp->price;
            temp = temp->next;
        }

        fout.close();
    }

    //--------------------------------------------------------------------------------
    //                  THIS FUNCTION IS SEARCHING PASSANGER
    //--------------------------------------------------------------------------------
    void search_passenger()
    {
        int fake;
        cout << "Please enter your seat number here: ";
        while (!(cin >> fake))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.  Try again: ";
        }

        node2 *cur = start;
        while (cur != NULL)
        {
            if (cur->seat_num == fake)
            {
                cout << "First Name : " << cur->fname << endl;
                cout << "Last Name : " << cur->lname << endl;
                cout << "CNIC ID : " << cur->ID << endl;
                cout << "Phone number: " << cur->phone_num << endl;
                cout << "Seat Number: " << cur->seat_num << endl;
                cout << "Ticket No. " << cur->reserve_num << endl;
                cout << "Origin : " << cur->origin << endl;
                cout << "Destination : " << cur->destination << endl;
                cout << "Prize : " << cur->price << endl;
                return;
            }
            cur = cur->next;
        }
        cout << " Sorry!!! NOT FOUND \n\n";
    }

    //--------------------------------------------------------------------------------
    //                  THIS  IS FOR CHANGING/UPDATING RECORD
    //--------------------------------------------------------------------------------

    void change_reservation()

    {
        int option, next_seat;
    tt:
        cout << " \n Please enter your seat number: ";
        cin >> option;
        while (!option)
        {
            cin.clear();
            cin.ignore();
            cout << "\n INVALID INPUT;  Try again::";
            cin >> option;
            break;
        }

        node2 *cur;
        cur = start;

        while (cur != NULL)
        {
            if (cur->seat_num == option)
            {
                break;
                cur = cur->next;
            }
            else

                cout << " Seat not found :: Try again : ";
            goto tt;
        }

        //--------------------------------------------------------------------------------
        //                 TAKING ANOTHER SEAT TO CHANGE RESERVATION
        //--------------------------------------------------------------------------------

        cout << "Please choose another seat number from below.";
        int j = 1;
        while (j < size + 1)
        {
            if (seat2[j - 1] == -1)
                j++;
            else
            {
                cout << "| " << j << "|";
                if (j % 10 == 0)
                    cout << endl;
                j++;
            }
        }
        cin >> next_seat;
        seat2[cur->seat_num - 1] = 0;
        cur->seat_num = next_seat;
        seat2[next_seat - 1] = -1;
    }

    //--------------------------------------------------------------------------------
    //                      PRINTING RECORD FROM LINKED LIST
    //--------------------------------------------------------------------------------
    void print_list()
    {
        temp = start;
        if (temp == NULL)
            cout << " End of lists" << endl;
        else
        {
            int cnt = 1;

            while (temp != NULL)
            {
                //--------------------------------------------------------------------------------
                //                DISPLAYING DATA FROM LINK LIST
                //--------------------------------------------------------------------------------

                cout << "First Name : " << temp->fname << endl;
                cout << "Last Name : " << temp->lname << endl;
                cout << "CNIC ID : " << temp->ID << endl;
                cout << "Phone number: " << temp->phone_num << endl;
                cout << "Seat Number: " << temp->seat_num << endl;
                cout << "Ticket No. " << temp->reserve_num << endl;
                cout << "Origin : " << temp->origin << endl;
                cout << "Destination : " << temp->destination << endl;
                cout << "Prize : " << temp->price << endl;

                temp = temp->next;
                cnt++;
            }
            cout << "\n\n";
        }
    }

    //--------------------------------------------------------------------------------
    //                              PRINTING REPORT
    //-------------------------------------------------------------------------------

    void print_report()
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (seat2[i] == -1)
                count++;
        }
        cout << "The number of reserved seats are: " << count << endl;
        cout << "The number of cancellations are: " << cancel << endl;
    }
};

// :::::::::::::::::::::::::::::: CITIES INFO ::::::::::::::::::::::::::::::::::::

//--------------------------------------------------------------------------------
//                                   LAHORE
//--------------------------------------------------------------------------------

void Lahore()
{
    cout << "-------------------------------LAHORE THE CITY OF TRADITIONS-------------------------------" << endl
         << endl;

    cout << "__ABOUT LAHORE__" << endl
         << endl;
    cout << "Lahore exerts a strong cultural influence over Pakistan.It is a UNESCO City " << endl;
    cout << "of Literature and major center for Pakistan's publishing industry.Lahore remains the foremost " << endl;
    cout << "center of Pakistan's literary scene. The city is also a major centre of education in Pakistan, " << endl;
    cout << "with some of Pakistan's leading universities based in the city." << endl
         << endl;
se:
    cout << "Press 1 to see all famous shopping Malls and their locations in Lahore" << endl;
    cout << "Press 2 to see all historical places and their locations in Lahore" << endl;
    cout << "Press 3 to see top restaurants and their locations in Lahore" << endl;
    cout << "Press 4 to see all picnic places and their location in Lahore" << endl;

    int choice;
    cout << "Where you want to go :";
    while (!(cin >> choice))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input.  Try again: ";
    }

    switch (choice)
    {
    case 1:
        cout << endl;
        cout << "--------------BEST MALLS IN LAHORE--------------" << endl
             << endl;

        cout << "==>Emporium mall" << endl;
        cout << "   Addresss: Johar Town" << endl;
        cout << "   RATING :9/10 " << endl
             << endl;

        cout << "==>Packages mall" << endl;
        cout << "   Address: Walton Road" << endl;
        cout << "   RATING : 8/10 " << endl
             << endl;

        cout << "==>Fortress Stadium mall" << endl;
        cout << "  Address: Fortress stadium, Cantt" << endl;
        cout << "  RATING: 8.5/10" << endl
             << endl;
        cout << "==>Amanah mall" << endl;
        cout << "   Address:Model Town Link Road" << endl;
        cout << "   RATING: 7/10" << endl
             << endl;

        break;

    case 2:
        cout << endl;
        cout << "--------------HISTORICAL PLACES IN LAHORE--------------" << endl
             << endl;

        cout << "==>Lahore Fort " << endl;
        cout << "   Address: Fort Rd, Walled City of Lahore, Lahore, Punjab " << endl;
        cout << "   Opening hours: 8:30am - 5pm (daily)" << endl
             << endl;

        cout << "==>Masjid Wazir Khan " << endl;
        cout << "   Address: Shahi Guzargah، Walled City of Lahore, Lahore, " << endl;
        cout << "   Opening hours: 5am - 8pm (daily)" << endl
             << endl;

        cout << "==>Haveli of Nau Nihal Singh " << endl;
        cout << "   Address: Mori Gali Bazar, Walled City of Lahore " << endl;
        cout << endl;

        cout << "==>Badshahi Mosque " << endl;
        cout << "    Address: Walled City of Lahore, Lahore, Punjab " << endl;
        cout << "    Opening hours: 8am - 8pm (daily)" << endl
             << endl;

        cout << "==>Shalamar Gardens " << endl;
        cout << "  Address: Shalamar Chowk، G. T. Road, Shalamar Town, Lahore " << endl;
        cout << "  Opening hours: 8am - 6pm (daily)" << endl
             << endl;

        cout << "==>Gulabi Bagh Gateway " << endl;
        cout << "  Address: Begampura, Lahore " << endl
             << endl;

        cout << "==>Lahore Museum " << endl;
        cout << "   Address: Mall Rd, Anarkali Bazaar, Lahore, Punjab 54000 " << endl;
        cout << "   Opening hours: Sat - Thu: 9am - 3:30pm (closed on Fri)" << endl
             << endl;

        break;

    case 3:
        cout << endl;
        cout << "--------------BEST RESTAURANTS IN LAHORE--------------" << endl
             << endl;

        cout << "==>Café Aylanto" << endl;
        cout << "   Address:MM Alam Road and DHA Phase III." << endl
             << endl;

        cout << "==>Wasabi" << endl;
        cout << "   Address:Gulberg and DHA Phase III" << endl
             << endl;

        cout << "==>Spice Bazaar" << endl;
        cout << "   Address:MM Alam and DHA Phase VI" << endl
             << endl;

        cout << "==>Pasta La Vista" << endl;
        cout << "    Address:DHA Phase II." << endl
             << endl;

        cout << "==>Bamboo Union" << endl;
        cout << "   Mall One and DHA Phase V." << endl
             << endl;

        break;

    case 4:
        cout << endl;
        cout << "--------------BEST PICNIC POINTS IN LAHORE--------------" << endl
             << endl;

        cout << "==>Lahore Zoo Safari" << endl;
        cout << "   Address: Safari Road, Lahore" << endl;
        cout << "   Timings: 7:00 AM to 8:00 PM " << endl
             << endl;

        cout << "==>Shalimar Gardens" << endl;
        cout << "   Address: Shalimar Chowk, G. T. Road, Shalimar Town, Lahore" << endl;
        cout << "   Timings: 8:00 AM to 6:00 PM " << endl
             << endl;

        cout << "==>Jallo Park" << endl;
        cout << "   Address: Bhagwanpura, Jallo Road, Lahore " << endl;
        cout << "   Timings: 6:00 AM to 5:00 PM" << endl
             << endl;

        cout << "==>Sozo Water Park" << endl;
        cout << "   Address: Canal Bank Road near Jallo Park, Lahore. " << endl;
        cout << "   Timings: 10:30 AM to 5:00 PM" << endl
             << endl;

        cout << "==>Jinnah Garden" << endl;
        cout << "   Address: Mall Road, Jubilee Town, Lahore. " << endl;
        cout << "   Timings: 5:00 AM to 10:00 PM" << endl
             << endl;
        break;

    default:
        cout << "Invalid input.  Try again: ";
        goto se;
        break;
    }
}

//--------------------------------------------------------------------------------
//                                   KARACHI
//--------------------------------------------------------------------------------

void Karachi()
{
    cout << "-------------------------------KARACHI THE CITY OF LIGHTS-------------------------------" << endl
         << endl;

    cout << "__ABOUT KARACHI__" << endl;
    cout << "Karachi is the largest city in Pakistan and the twelfth-largest city in the world. " << endl;
    cout << "It is the capital of the Pakistani province of Sindh.Ranked as a beta-global city, it is Pakistan's premier " << endl;
    cout << "industrial and financial centre, with an estimated GDP of $164 billion as of 2019 " << endl
         << endl;

sa:
    cout << "==>Press 1 to see all famous shopping Malls and their locations in Karachi" << endl;
    cout << "==>Press 2 to see all historical places and their locations in Karachi" << endl;
    cout << "==>Press 3 to see top restaurants and their locations in Karachi" << endl;
    cout << "==>Press 4 to see all picnic places and their location in Karachi" << endl;

    int choice;
    cout << "Where you want to go :";
    while (!(cin >> choice))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input.  Try again: ";
    }

    switch (choice)
    {
    case 1:
        cout << endl;
        cout << "--------------BEST MALLS IN KARACHI--------------" << endl
             << endl;

        cout << "==>Dolman mall clifton" << endl;
        cout << "   Address: Dolmen City, HC-3, Marine Promenade, Block 4 Clifton, Karachi" << endl;
        cout << "   Timings: 11am–11pm" << endl
             << endl;

        cout << "==>Port Grand" << endl;
        cout << "    Address: Port Grand Food St, Karachi, Karachi City, Sindh" << endl;
        cout << "    Timings: 4–11:45pm" << endl
             << endl;

        cout << "==>LuckyOne Mall" << endl;
        cout << "     Address: Main Rashid Minhas Rd, opp. UBL Sports Complex، Karachi" << endl;
        cout << "     Timings: 11am–11pm" << endl
             << endl;

        cout << "==>Emerald Tower" << endl;
        cout << "    Address:  Block 5 Clifton, Karachi, Karachi City, Sindh 75600i" << endl;
        cout << "    Timings: 8am–6pm" << endl
             << endl;

        break;

    case 2:
        cout << endl;
        cout << "--------------HISTORICAL PLACES IN KARACHI--------------" << endl
             << endl;

        cout << "==>Quaid e azam shrine" << endl;
        cout << "     Address:  Central Jacob Lines Ghm، Karachi, Karachi City, Sindh" << endl;
        cout << "     10am–5:30pm" << endl
             << endl;

        cout << "==>Mohatta Palace Museum" << endl;
        cout << "   Address:  Address: 7 Hatim Alvi Road, Block 5 Old Clifton, Karachi City, Sindh 75600, Pakistan" << endl;
        cout << "   Timings: Tues - Sun: 11am - 6pm (closed on Mon)" << endl
             << endl;

        cout << "==>Chaukhandi Tombs" << endl;
        cout << "   Address:  Address: N-5 near Landhi Town, Karachi, Karachi City, Sindh, Pakistan" << endl;
        cout << "   Timings: Open 24 hours daily" << endl
             << endl;

        cout << "==>Frere Hall" << endl;
        cout << "   Address:  Fatima Jinnah Road, Civil Lines Saddar, Karachi, Karachi City, Sindh, Pakistan" << endl;
        cout << "   Timings: Mon - Sat: 9am - 5pm (closed on Sun)" << endl
             << endl;

        break;

    case 3:
        cout << endl;
        cout << "--------------BEST RESTAURANTS IN KARACHI--------------" << endl
             << endl;
        cout << "==>BarBQ Tonight" << endl;
        cout << "   Address: 5/1, Boating Basin, Clifton, Block-5, Karachi, Pakistan" << endl
             << endl;

        cout << "==>Cafe Aylanto" << endl;
        cout << "   Address: D 141, Block 4 Clifton, Karachi" << endl
             << endl;

        cout << "==>Cafe Aylanto" << endl;
        cout << "   Address: 48-C, Lane 13, Bukhari Commercial DHA Phase 6, Karachi" << endl
             << endl;

        cout << "==>Kolachi" << endl;
        cout << "   Address: Beach Avenue, Do Darya, Devils Point, Phase 8, D.H.A, Karachi" << endl
             << endl;
        break;

    case 4:
        cout << endl;
        cout << "--------------BEST PICNIC ZONE IN KARACHI--------------" << endl
             << endl;
        cout << "==>Seaview Picnic Spot Clifton" << endl;
        cout << "   Address: Sahil Ave, D.H.A. Phase 8 Phase 8 Ext Defence Housing Authority, Karachi, Sindh 75500" << endl
             << endl;

        cout << "==>Dhabeji Picnic Point" << endl;
        cout << "   RG92+72X, Dhabeji, Karachi City, Sindh " << endl
             << endl;

        cout << "==>Picnic World Water Park" << endl;
        cout << "    Haroo Burro Ghot, Gandaku, Jamshoro " << endl
             << endl;
    default:
        cout << "Invalid input.  Try again: ";
        goto sa;
        break;
    }
}

//--------------------------------------------------------------------------------
//                                  ISLAMABAD
//--------------------------------------------------------------------------------

void Islamabad()
{
    cout << "-------------------------------CAPITAL ISLAMABAD-------------------------------" << endl
         << endl;

    cout << "__ABOUT ISLAMABAD__" << endl;
    cout << "Islamabad is the capital city of Pakistan, and is administered by the " << endl;
    cout << "Pakistani federal government as part of the Islamabad Capital " << endl;
    cout << "Territory. It is the ninth-largest city in Pakistan, while the larger " << endl;
    cout << "Islamabad–Rawalpindi metropolitan area is the country's third-largest " << endl;
    cout << " with a population of about 4.1 million people" << endl
         << endl;

so:
    cout << "==>Press 1 to see all famous shopping Malls and their locations in Islamabad" << endl;
    cout << "==>Press 2 to see all historical places and their locations in Islamabad" << endl;
    cout << "==>Press 3 to see top restaurants and their locations in Islamabad" << endl;
    cout << "==>Press 4 to see all picnic places and their location in Islamabad" << endl;

    int choice;
    cout << "Where you want to go :";
    while (!(cin >> choice))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input.  Try again: ";
    }

    switch (choice)
    {
    case 1:
        cout << endl;
        cout << "--------------BEST MALLS IN ISLAMABAD--------------" << endl
             << endl;
        cout << "==>Safa Gold Mall Islamabad" << endl;
        cout << "   Address: Jinnah Super, F-7 Markaz" << endl;
        cout << "   Timings: 10am–11pm" << endl
             << endl;

        cout << "==>Centaurus Mall Islamabad" << endl;
        cout << "     Address: Jinnah Avenue, F-8/4" << endl;
        cout << "     Timings: 11am–11pm" << endl
             << endl;

        cout << "==>Amazon Outlet Mall Islamabad" << endl;
        cout << "     Address: Main G.T Road, DHA Phase 2" << endl;
        cout << "     Timings: 10am–10pm" << endl
             << endl;

        cout << "==>Olympus Mall Islamabad" << endl;
        cout << "     Address: F-11 Markaz" << endl;
        cout << "     Open 24 hours" << endl
             << endl;
        break;

    case 2:
        cout << endl;
        cout << "--------------HISTORICAL PLACES IN ISLAMABAD--------------" << endl
             << endl;
        cout << "==>Faisal Mosque" << endl;
        cout << "    Address: Shah Faisal Ave, E-8, Islamabad" << endl
             << endl;

        cout << "==>Daman-e-Koh" << endl;
        cout << "    Address: Daman -e- Koh Rd, E-7, Islamabad" << endl
             << endl;

        cout << "==>Margalla Hills" << endl;
        cout << "   Address: Northern Islamabad" << endl
             << endl;
        break;

    case 3:
        cout << endl;
        cout << "--------------BEST RESTAURANTS IN ISLAMABAD--------------" << endl
             << endl;
        cout << "==>Tuscany Courtyard Kohsar" << endl;
        cout << "    Address: No. 4, Kohsar market، Street 10, Islamabad" << endl
             << endl;

        cout << "==>The Monal" << endl;
        cout << "   Address: Margalla Hills" << endl
             << endl;

        cout << "==>Tandoori Restaurants" << endl;
        cout << "    Address:  St#30, 66 Street No 25, F-10/1 F 10/1 F-10, Islamabad," << endl
             << endl;

        cout << "==>Howdy Islamabad" << endl;
        cout << "       Address: Gol Market, Shop 6، F 7/3 F-7, Islamabad, Islamabad Capital Territory" << endl
             << endl;

        break;

    case 4:
        cout << endl;
        cout << "--------------PICNIC PLACES IN ISLAMABAD--------------" << endl
             << endl;
        cout << "==>Ficus Water Spring and Waterfall" << endl;
        cout << "           Address: Trail 5, Islamabad, Islamabad Capital Territory" << endl;
        cout << "    Timings: Opens 6:30AM" << endl
             << endl;

        cout << "==>Shakarparian Picnic Point" << endl;
        cout << "   Address: M3VH+P2C, Islamabad, Islamabad Capital Territory" << endl;
        cout << "   Timings: Opens 8AM" << endl
             << endl;

        cout << "==>Margalla Barbecue Point 1" << endl;
        cout << "    Address: Talhaar Rd, Talhaar, Islamabad, Islamabad Capital Territory 44000" << endl
             << endl;

        cout << "==>Shahdara Point" << endl;
        cout << "   Address: Shah Dara Rd, Islamabad, Islamabad Capital Territory" << endl
             << endl;
        cout << "   Timings: Opens 8AM" << endl
             << endl;
    default:
        cout << "Invalid input.  Try again: ";
        goto so;
        break;
    }
}

//--------------------------------------------------------------------------------
//                                 Gujranawala
//--------------------------------------------------------------------------------

void Gujranawala()
{
    cout << "-------------------------------GUJRANWALA-------------------------------" << endl
         << endl;

    cout << "__ABOUT GUJRANWALA__" << endl;
    cout << "Gujranwala is a city and capital of Gujranwala Division located in " << endl;
    cout << "Punjab, Pakistan. It is also known as City of Wrestlers and is quite " << endl;
    cout << "famous for its food. The city is Pakistan's 5th most-populous " << endl;
    cout << "metropolitan area, as well as 5th most populous city proper. " << endl
         << endl;

    cout << "==>Press 1 to see all famous shopping Malls and their locations in Gujranawala" << endl;
    cout << "==>Press 2 to see all historical places and their locations in Gujranawala" << endl;
    cout << "==>Press 3 to see top restaurants and their locations in Gujranawala" << endl;
    cout << "==>Press 4 to see all picnic places and their location in Gujranawala" << endl;

    int choice;
    cout << "Where you want to go :";
    while (!(cin >> choice))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input.  Try again: ";
    }

    switch (choice)
    {
    case 1:
        cout << endl;
        cout << "--------------BEST MALLS IN GUJRANWALA--------------" << endl
             << endl;
        cout << "==>Alfatah Shopping Mall ,Mall Of Gujranwala" << endl;
        cout << "   Address: Grand Trunk Rd, Qazi Town, Gujranwala, Punjab" << endl
             << endl;

        cout << "==>KINGS MALL" << endl;
        cout << "     Address: BYPASS ROAD, opposite WAPDA TOWN, Judicial Housing Colony Gujranwala, Punjab 52250" << endl
             << endl;
        break;

    case 2:
        cout << endl;
        cout << "--------------HISTORICAL PLACES IN GUJRANWALA--------------" << endl
             << endl;
        cout << "==>White Palace" << endl;
        cout << "    Address: 55FQ+MFF, Civil Lines, Gujranwala, Punjab" << endl
             << endl;

        cout << "==>Memorial Tomb of Jain Monk Atma Ramji" << endl;
        cout << "   Address: Parao Rd, Bakhtay Wala, Gujranwala, Punjab" << endl
             << endl;

        cout << "==>Kothi Darzian Wali" << endl;
        cout << "     Address: 556H+MM4, Mohalla Iqbal Gunj Mohalla Noor Bawa, Gujranwala" << endl
             << endl;

        cout << "==>Garjakhi Darwaza" << endl;
        cout << "    Address: College Rd, Abadi Mir Muzaffar, Gujranwala, Punjab" << endl
             << endl;

        break;

    case 3:
        cout << endl;
        cout << "--------------BEST RESTAURANTS IN GUJRANWALA--------------" << endl
             << endl;
        cout << "==>Shinghar Shinwari" << endl;
        cout << "    Address: GT Rd, Sadhoke, Gujranwala, Punjab" << endl
             << endl;
        cout << "==>China Citi Restaurant" << endl;
        cout << "   Block Aa Canal View Sector 2 Canal View, Gujranwala, Punjab" << endl
             << endl;

        break;

    case 4:
        cout << endl;
        cout << "--------------PICNIC PLACES IN GUJRANWALA--------------" << endl
             << endl;
        cout << "==>Fun Dunya Amusement Park Gujranwala" << endl;
        cout << "    Grand Trunk Rd, Rahwali Cantonment, Gujranwala, Punjab 52230" << endl
             << endl;

        break;
    }
}

//--------------------------------------------------------------------------------
//                          FUNCTION FOR TOURIST GUIDE
//--------------------------------------------------------------------------------

void tourist_guide()
{
    cout << "Enter Lahore to visit Lahore tour Guide" << endl;
    cout << "Enter Karachi to visit Karachi tour Guide" << endl;
    cout << "Enter Islamabad to visit Islamabad tour Guide" << endl;
    cout << "Enter Gujranawala to visit Gujranawala tour Guide" << endl
         << endl
         << endl;

    string choice;

dr:
    cout << "Enter city name :";
    cin >> choice;
    if (choice == "Lahore" || choice == "lahore" || choice == "LAHORE")
    {
        cout << endl;
        Lahore();
    }

    else if (choice == "Karachi" || choice == "karachi" || choice == "KARACHI")
    {
        cout << endl;
        Karachi();
    }
    else if (choice == "Islamabad" || choice == "islamabad" || choice == "ISLAMABAD")
    {
        cout << endl;
        Islamabad();
    }
    else if (choice == "Gujranwala" || choice == "gujranwala" || choice == "GUJRANWALA")
    {
        cout << endl;
        Gujranawala();
    }
    else
    {
        cout << "Invalid choice" << endl;
        cout << "Invalid identation,format or spelling of input...!" << endl;
        goto dr;
    }
}

//===================================================
//                    MAIN FUNCTIION
// ==================================================

int main()
{
    int mnchoice, ch;

    cout << "\t\t\t\t\t||+=================================+||" << endl;
    cout << "\t\t\t\t\t||+------- HASHTAG TOURISTA --------+||" << endl;
    cout << "\t\t\t\t\t||+=================================+||" << endl
         << endl;

    do
    {

        cout << "---------------------------------" << endl;
        cout << "FLIGHT MANAGER________________'1'" << endl;
        cout << "---------------------------------" << endl;
        cout << "HOTEL MANAGER_________________'2'" << endl;
        cout << "---------------------------------" << endl;
        cout << "RAILWAY MANAGER_______________'3'" << endl;
        cout << "---------------------------------" << endl;
        cout << "Tousrist Guide________________'4'" << endl;
        cout << "---------------------------------" << endl;
        cout << "User manual___________________'5'" << endl;
        cout << "---------------------------------" << endl;
        cout << "About Us______________________'6'" << endl;
        cout << "---------------------------------" << endl;
        cout << "EXIT__________________________'7'" << endl;
        cout << "---------------------------------" << endl;

        cout << "Enter your choice :";

        while (!(cin >> mnchoice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.  Try again: ";
        }

        switch (mnchoice)
        {
        case 1:
        {
            system("CLS");

            cout << "\t\t\t\t\t:::::::::::::::::::::::::::::::::::::::::::::::" << endl;
            cout << "\t\t\t\t\t      AIRLINE RESERVATION SYSTEM \n";
            cout << "\t\t\t\t\t:::::::::::::::::::::::::::::::::::::::::::::::" << endl
                 << endl;
            do
            {
                ll fly;
                cout << "Press 1 to login as Admin" << endl;
                cout << "Press 2 to to reserve a airplane seat" << endl;
                cout << "Press 3 to exit" << endl;

                cout << "Make choice :";
                cin >> ch;
                while (!ch)
                {
                    cin.clear();
                    cin.ignore();
                    cin >> ch;
                }

                switch (ch)
                {

                case 1:
                {

                    string user_name, password;
                    cout << "Enter user_name :";
                    cin >> user_name;
                    while (user_name != "Admin")
                    {
                        cout << "Wrong user name! Try Again\n";
                        cout << "Enter user name :";
                        cin >> user_name;
                    }

                    char c = ' ';
                    string pass = "";
                    cout << "Enter password: ";
                    while (c != 13)
                    {
                        c = getch();
                        if (c != 13)
                        {
                            pass += c;
                            cout << "*";
                        }
                    }
                    if (pass == "123")
                        cout << " password accepted\n\n";
                    else
                        cout << " wrong password";
                    getch();
                    system("CLS");

                    if (user_name == "Admin" && pass == "123")
                    {

                        int choice;
                        ll fly;

                        do
                        {

                            cout << " ::::::::::::::::: MENU OPTIONS :::::::::::::::::\n"
                                 << endl;

                            cout << "\t Make Reservation    ...... '1' \n";
                            cout << "\t Cancel Reservation  ...... '2' \n";
                            cout << "\t Search Passenger    ...... '3' \n";
                            cout << "\t Change Reservation  ...... '4' \n";
                            cout << "\t Print a file        ...... '5' \n";
                            cout << "\t Print status Report ...... '6' \n";
                            cout << "\t Print list          ...... '7' \n";
                            cout << "\t Quit                ...... '8' \n";

                            cout << ":::::::::::::::::::::::::::::::::::::::::::::::\n";
                            cout << "\n Option : ";

                            while (!(cin >> choice))
                            {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Invalid input.  Try again: ";
                            }

                            switch (choice)
                            {
                            case 1:
                                system("CLS");
                                fly.make_reservation();
                                break;

                            case 2:
                                system("CLS");
                                fly.cancel_reservation();
                                break;

                            case 3:
                                system("CLS");
                                fly.search_passenger();
                                break;

                            case 4:
                                system("CLS");
                                fly.change_reservation();
                                break;

                            case 5:
                            {
                                system("CLS");
                                // bluesky.print_list();
                                char str;
                                ifstream is;
                                is.open("linkedList.txt");
                                while (is)
                                {
                                    is.get(str);
                                    cout << str;
                                }
                            }

                            break;
                            case 6:
                                system("CLS");
                                fly.print_report();
                                break;

                            case 7:
                                system("CLS");
                                fly.print_list();
                                break;

                            case 8:
                                cout << "\n\nThank you come again\n\n\n";
                                break;

                            default:
                                cout << " ERROR!!! \n\n";
                                break;

                            } // Ending case loop.

                            cout << "\nxxxxxxxxx:::::::::: PROCESS COMPLETED ::::::::::xxxxxxxxx\n";
                            cout << "\nxxxxxxxxx:::::: PRESS ENTER TO CONTINUE ::::::::xxxxxxxxx\n";

                            cin.get();
                            if (cin.get() == '\n')
                                // system("CLS");

                                cout << "\n\n ..................................................\n"
                                     << endl;

                        } while (choice != 8);
                    }
                    else

                    {
                        cout << "Invalid choice" << endl;
                    }
                }
                break;
                case 2:
                {
                    fly.make_reservation();
                }
                break;
                case 3:
                    mnchoice = 8;

                    break;
                }
            } while (ch != 3);
        }
        break;

        case 2:
        {
            int days;

            linked_list a;
            char ch = 'y';
            string name, address, contact;
            int room_no;
            int j = 1;
            system("CLS");

            do
            {
                cout << "-----------------------WELCOME TO THE HOTEL SITE-----------------------" << endl
                     << endl;

                cout << "OPTIONS___CHOICE CODE" << endl;
                cout << "ADMIN LOGIN___'1'" << endl;
                cout << "USER TO BOOK A ROOM___'2" << endl;
                cout << "EXIT__'3'" << endl;

                int choice;
                cout << endl;
                cout << "User or Admin :" << endl;

                while (!(cin >> choice))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input.  Try again: ";
                }

                if (choice == 1)
                {
                    int i = 0;
                    cout << "----------------ENTER USER AND PASSWORD----------------" << endl
                         << endl;
                    string user_name, password;
                    cout << "Enter user_name :";

                    while (!(cin >> user_name))
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input.  Try again: ";
                    }

                    char c = ' ';
                    string pass = "";
                    cout << "Enter password: ";
                    while (c != 13)
                    {
                        c = getch();
                        if (c != 13)
                        {
                            pass += c;
                            cout << "*";
                        }
                    }
                    if (pass == "123")
                        cout << " password accepted\n\n";
                    else
                        cout << " wrong password";
                    getch();
                    system("CLS");

                    if (user_name == "Admin" && password == "123")
                    {

                        int i = 0;
                        while (i < 5)
                        {
                            cout << "-----------ADMIN SITE EMPLOYEE CAN SEE ALL RECORDS OF HOTEL-----------" << endl
                                 << endl;

                            cout << "BOOK ROOM___'1'" << endl;
                            cout << "COSTOMER RECORDS__'2'" << endl;
                            cout << "ROOM ALLOCATION___'3'" << endl;
                            cout << "EDIT RECORDS__'4'" << endl;
                            cout << "EXIT__'5'" << endl;
                            cout << endl;
                            int choice2;

                            cout << "Enter choice of hotel Admin" << endl;
                            cin >> choice2;

                            while (!(cin >> choice2))
                            {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Invalid input.  Try again: ";
                            }

                            switch (choice2)
                            {

                            case 1:
                                cout << "----------------ENTER GUEST RECORD----------------" << endl
                                     << endl;
                                cout << "Enter room no :";
                                cin >> room_no;
                                if (room_no > 50)
                                {
                                    cout << "Only 50 rooms Available" << endl;
                                    cout << "Enter room no :";
                                    cin >> room_no;
                                }

                                while (!(cin >> room_no))
                                {
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    cout << "Invalid input.  Try again: ";
                                }

                                cin.ignore();
                                cout << "Enter name :";
                                getline(cin, name);
                                cout << "Enter address :";
                                getline(cin, address);
                                cout << "Enter contact :";
                                getline(cin, contact);

                                a.book_Room(room_no, name, address, contact);
                                cout << endl;

                                break;
                            case 2:
                                cout << "----------------GET COSTOMER AND ROOM RECORD----------------" << endl
                                     << endl;
                                int Records;
                                cout << "Enter Room number :" << endl;

                                while (!(cin >> Records))
                                {
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    cout << "Invalid input.  Try again: ";
                                }

                                a.Costomer_records(Records);
                                cout << endl;
                                break;

                            case 3:

                                cout << "----------------GET ALL THE ROOM ALLOCATION----------------" << endl
                                     << endl;
                                {
                                    char str;
                                    ifstream is;
                                    is.open("linked.txt");
                                    while (is)
                                    {
                                        is.get(str);
                                        cout << str;
                                    }
                                }
                                // a.room_Allocation();
                                // cout << endl
                                //      << endl;

                                break;

                            case 4:
                                cout << "-----------UPDATE/DELETE OR GET BILLS OF RECORD-----------" << endl
                                     << endl;
                                cout << "UPDATE COSTOMER___'1'" << endl;
                                cout << "DELETE COSTOMER___'2'" << endl;
                                cout << "GET BILLS___'3'" << endl;

                                cout << "Press 4 to Exit" << endl;

                                cout << endl;
                                int choice3;
                                cout << "Enter Admin choice to Edit Records :";
                                while (!(cin >> choice3))
                                {
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    cout << "Invalid input.  Try again: ";
                                }

                                switch (choice3)
                                {

                                case 1:
                                    cout << "----------------UPGRADE RECORD OF ANY ROOM----------------" << endl
                                         << endl;
                                    cout << endl;
                                    cout << "Enter room number :";
                                    while (!(cin >> room_no))
                                    {
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cout << "Invalid input.  Try again: ";
                                    }
                                    cin.ignore();
                                    cout << "Enter name :";
                                    getline(cin, name);
                                    cout << "Enter address :";
                                    getline(cin, address);
                                    cout << "Enter contact :";
                                    getline(cin, contact);

                                    a.update_roomRecord(room_no, name, address, contact);

                                    break;

                                case 2:
                                    cout << "----------------DELETE RECORD OF ROOM----------------" << endl
                                         << endl;
                                    cout << endl;
                                    int pos;

                                    cout << "Enter Booking Number to Delete Costomer Record :";
                                    cin >> pos;

                                    if (pos == 1)
                                    {
                                        a.del_first();
                                    }
                                    else
                                    {
                                        a.Del_Record(pos);
                                    }
                                    break;

                                case 3:
                                    cout << "----------------GET BILLS----------------" << endl
                                         << endl;

                                    cout << "Enter Room number to get bill :";
                                    while (!(cin >> room_no))
                                    {
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cout << "Invalid input.  Try again: ";
                                    }

                                    cout << "Enter number of days guest stayed :";
                                    cin >> days;
                                    cout << endl;
                                    a.bill(room_no, days);
                                    cout << endl
                                         << endl;
                                    break;

                                case 4:

                                    return 0;
                                    break;
                                }
                                break;

                            case 5:
                                return 0;
                                break;
                            }
                        }
                    }
                    else
                    {
                        cout << "Invalid Login" << endl;
                    }
                }

                if (choice == 2)
                {
                    cout << "-----------BOOK A ROOM YOURSELF-----------" << endl
                         << endl;
                    cout << "Enter room no :";
                    while (!(cin >> room_no))
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input.  Try again: ";
                    }
                    if (room_no > 50)
                    {
                        cout << "Only 50 rooms Available" << endl;
                        cout << "Enter room no :";
                        while (!(cin >> room_no))
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Invalid input.  Try again: ";
                        }
                    }

                    cin.ignore();
                    cout << "Enter name :";
                    getline(cin, name);
                    cout << "Enter address :";
                    getline(cin, address);
                    cout << "Enter contact :";
                    getline(cin, contact);

                    a.book_Room(room_no, name, address, contact);
                }
                if (choice == 3)
                {
                    return 0;
                }
                cout << "Want portal again?? Y or N" << endl;
                cin >> ch;

            } while (ch == 'y');
            return 0;
        }
        break;
        case 3:
        {
            system("CLS");
            cout << "\n:::::::::::::::::::::::::::::::::::::::::::::::" << endl;
            cout << "\t     RAILWAY RESERVATION SYSTEM \n";
            cout << ":::::::::::::::::::::::::::::::::::::::::::::::" << endl
                 << endl;
            do
            {
                Railway train;

                system("CLS");
                cout << "Press 1 to login as Admin" << endl;
                cout << "Press 2 to to reserve a Train seat" << endl;
                cout << "Press 3 to exit" << endl;

                cout << "Make choice :";
                while (!(cin >> ch))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input.  Try again: ";
                }

                switch (ch)
                {
                case 1:
                {

                    cout << "----------------ENTER USER AND PASSWORD----------------" << endl
                         << endl;
                    string user_name, password;
                    cout << "Enter user_name :";
                    cin >> user_name;
                    while (user_name != "Admin")
                    {
                        cout << "Wrong user name! Try Again\n";
                        cout << "Enter user name :";
                        cin >> user_name;
                    }

                    char c = ' ';
                    string pass = "";
                    cout << "Enter password: ";
                    while (c != 13)
                    {
                        c = getch();
                        if (c != 13)
                        {
                            pass += c;
                            cout << "*";
                        }
                    }
                    if (pass == "123")
                        cout << " password accepted\n\n";
                    else
                        cout << " wrong password";
                    getch();
                    system("CLS");

                    if (user_name == "Admin" && pass == "123")
                    {

                        int choice;

                        do
                        {

                            cout << " ::::::::::::::::: MENU OPTIONS :::::::::::::::::\n"
                                 << endl;

                            cout << "\t Make Reservation    ...... '1' \n";
                            cout << "\t Cancel Reservation  ...... '2' \n";
                            cout << "\t Search Passenger    ...... '3' \n";
                            cout << "\t Change Reservation  ...... '4' \n";
                            cout << "\t Print a file        ...... '5' \n";
                            cout << "\t Print status Report ...... '6' \n";
                            cout << "\t Print list          ...... '7' \n";
                            cout << "\t Quit                ...... '8' \n";

                            cout << ":::::::::::::::::::::::::::::::::::::::::::::::\n";
                            cout << "\n Option : ";

                            cin >> choice;
                            while (!choice)
                            {
                                cin.clear();
                                cin.ignore();
                                cout << "\n INVALID INPUT;  Try again::";
                                cin >> choice;
                                break;
                            }

                            switch (choice)
                            {
                            case 1:
                                system("CLS");
                                train.make_reservation();
                                break;

                            case 2:
                                system("CLS");
                                train.cancel_reservation();
                                break;

                            case 3:
                                system("CLS");
                                train.search_passenger();
                                break;

                            case 4:
                                system("CLS");
                                train.change_reservation();
                                break;

                            case 5:
                            {
                                system("CLS");
                                // bluesky.print_list();
                                char str;
                                ifstream is;
                                is.open("linkedList.txt");
                                while (is)
                                {
                                    is.get(str);
                                    cout << str;
                                }
                            }

                            break;
                            case 6:
                                system("CLS");
                                train.print_report();
                                break;

                            case 7:
                                system("CLS");
                                train.print_list();
                                break;

                            case 8:
                                cout << "\n\nThank you come again\n\n\n";
                                break;

                            default:
                                cout << " ERROR!!! \n\n";
                                break;

                            } // Ending case loop.
                            cout << endl;
                            cout << "\t\t\t\t\txxxxxxxxx:::::::::: PROCESS COMPLETED ::::::::::xxxxxxxxx\n";
                            cout << "\t\t\t\t\txxxxxxxxx:::::: PRESS ENTER TO CONTINUE ::::::::xxxxxxxxx\n";

                            cin.get();
                            if (cin.get() == '\n')

                                cout << "\n..................................................\n"
                                     << endl;

                        } while (choice != 8);
                    }
                    else

                    {
                        cout << "Invalid choice" << endl;
                    }
                }
                break;

                    break;
                case 2:
                {
                    system("CLS");
                    train.make_reservation();
                }
                break;
                case 3:
                    mnchoice = 8;

                    break;
                }
            } while (ch != 3);
        }

        break;
        case 4:
            system("CLS");
            {
                cout << endl;
                cout << "----------------------------HASHTAG TOURIST AGENCY-------------------------------" << endl;
                cout << endl;
                cout << endl;

                tourist_guide();
            }
            break;

        case 6:
            system("CLS");
            cout << "\t\t\t\t\t:::::::::::::::::::::::::::::::::::  ABOUT US ::::::::::::::::::::::::::::::::" << endl;
            cout << "\t\t\t\t\t                 MADE BY : SYED ABDULLAH SHAH & MOAZ MUMMTAZ                   \n";
            cout << "If you are a tourist then then definately you will travel alot. \nThe major issues every tourist face is to not getting\n a single environment to make reservations and guidance in their travelling. ";
            cout << "Hashtag corp is giving you a system \nthat allows you to make all your \ntravel and hotelling reservation under a single softwere envioronment. \n"
                 << endl;

            cout << "\t\t\t\t\t              FOR MORE DETAILS CONTACT AT:               \n";
            cout << "\t\t\t\t\t              =>   SA.ABDULLAHSHAH.2001@GMAIL.COM        \n";
            cout << "\t\t\t\t\t              =>     MOAZMUMMTAZ998@GMAIL.COM            \n";

            cout << "CopyRights 'Hashtag corp' ®" << endl;

            cout << endl
                 << endl
                 << endl;

            break;

        case 5:
            system("CLS");
            cout << "\t\t\t\t\t :::::::::::::::::::::::::::::::::::::::::::::::" << endl;
            cout << "\t\t\t\t\t                USER MANUAL \n";
            cout << "\t\t\t\t\t :::::::::::::::::::::::::::::::::::::::::::::::" << endl
                 << endl;
            cout << "ADMIN: " << endl;
            cout << "If you want to login or sign up as a Admin make sure ADMIN username or password should \n";
            cout << "be correct. Make sure that all choice input types should be in numbers any alphabet or characater \n";
            cout << "should not be entertained." << endl
                 << endl;

            cout << "USER :" << endl;
            cout << "User can only be able to make reservations. \n Make sure all the input types were in their desired form" << endl;
            break;

        case 7:
            cout << "\n\nThank you come again\n\n\n";

            return 0;
            break;

        default:
            cout << " ERROR!!! \n\n";
            break;
        }

        cout << "\nxxxxxxxxx:::::::::: PROCESS COMPLETED ::::::::::xxxxxxxxx\n";
        cout << "\nxxxxxxxxx:::::: PRESS ENTER TO CONTINUE ::::::::xxxxxxxxx\n";

    } while (mnchoice != 7);
    return 0;
}

// Tourist management CopyRights Hashtag corp
