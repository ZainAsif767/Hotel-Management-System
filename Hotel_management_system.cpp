#include <iostream>
#include <conio.h>
using namespace std;

int room_per_day = 1000;

class node
{
public:
    int id;
    int price;
    int no_of_rooms_booked;
    int no_of_days_of_stay;
    string name, email, address;
    node *next;
};

class hotel_management_system
{
public:
    node *head = NULL;
    void insert()
    {
        int ID;
        string n;
        string mail;
        string add;
        int No_of_Rooms;
        int days_of_stay;

        cout << "\n\n Enter ID: ";
        cin >> ID;
        cout << "\n\n Enter Name: ";
        cin >> n;
        cout << "\n\n Enter Email: ";
        cin >> mail;
        cout << "\n\n Enter your Address: ";
        cin >> add;
        cout << "\n\n Enter Number of Rooms: ";
        cin >> No_of_Rooms;
        cout << "\n\n Enter Number of Days of your Stay: ";
        cin >> days_of_stay;

        node *new_node = new node;
        new_node->id = ID;
        new_node->name = n;
        new_node->email = mail;
        new_node->address = add;
        new_node->no_of_rooms_booked = No_of_Rooms;
        new_node->no_of_days_of_stay = days_of_stay;
        new_node->price = room_per_day * No_of_Rooms * days_of_stay;
        new_node->next = NULL;
        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            node *p = head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = new_node;
        }
        cout << "\n\n\n New Record Node has been Inserted Successfully....";
    }

    void Search()
    {
        if (head == NULL)
        {
            cout << "\n\n Empty Linked list...";
        }
        else
        {
            int ID;
            int found = 0;
            cout << "\n\n Enter ID for search: ";
            cin >> ID;
            node *ptr = head;
            while (ptr != NULL)
            {
                if (ID == ptr->id)
                {
                    cout << "\n\n ID: " << ptr->id;
                    cout << "\n\n Name: " << ptr->name;
                    cout << "\n\n Email: " << ptr->email;
                    cout << "\n\n Address: " << ptr->address;
                    cout << "\n\n Number of Rooms Booked: " << ptr->no_of_rooms_booked;
                    cout << "\n\n Number of Days of Staying: " << ptr->no_of_days_of_stay;
                    cout << "\n\n Total Bill: " << ptr->price;
                    found++;
                }
                ptr = ptr->next;
            }
            if (found == 0)
            {
                cout << "\n\n Searched ID: " << ID << " Record Not Found...";
            }
        }
    }

    void Count()
    {
        if (head == NULL)
        {
            cout << "\n\n Empty Linked list...";
        }
        else
        {
            int c = 0;
            node *ptr = head;
            while (ptr != NULL)
            {
                c++;
                ptr = ptr->next;
            }
            cout << "\n\n Total Number of Record Nodes: " << c;
        }
    }

    void Update()
    {
        if (head == NULL)
        {
            cout << "\n\n Empty Linked list...";
        }
        else
        {
            int ID;
            int found = 0;
            cout << "\n\n Enter ID to update: ";
            cin >> ID;
            node *ptr = head;
            while (ptr != NULL)
            {
                if (ID == ptr->id)
                {
                    cout << "\n\n Enter New ID: ";
                    cin >> ptr->id;
                    cout << "\n\n Enter New Name: ";
                    cin >> ptr->name;
                    cout << "\n\n Enter New Email: ";
                    cin >> ptr->email;
                    cout << "\n\n Enter New your Address: ";
                    cin >> ptr->address;
                    cout << "\n\n Enter New Number of Rooms: ";
                    cin >> ptr->no_of_rooms_booked;
                    cout << "\n\n Enter New Number of Days of your Stay: ";
                    cin >> ptr->no_of_days_of_stay;
                    ptr->price = (room_per_day * ptr->no_of_rooms_booked * ptr->no_of_days_of_stay);
                    found = 1;
                    cout << "\n\n Record Updated Successfully...";
                }
                ptr = ptr->next;
            }
            if (found == 0)
            {
                cout << "\n\n ID for Updation: " << ID << " Record Not Found...";
            }
        }
    }

    void deletion()
    {
        if (head == NULL)
        {
            cout << "\n\n Empty Linked list...";
        }
        else
        {
            int ID;
            int found = 0;
            cout << "\n\n Enter ID to Delete Record: ";
            cin >> ID;
            if (ID == head->id)
            {
                node *ptr = head;
                head = head->next;
                cout << "\n\n Record has been Deleted Successfully....";
                found++;
                delete ptr;
            }
            else
            {
                node *prev = head;
                node *ptr = head->next;
                while (ptr != NULL)
                {
                    if (ID == ptr->id)
                    {
                        prev->next == ptr->next;
                        cout << "\n\n Record has been deleted Successfully...";
                        found++;
                        delete ptr;
                        break;
                    }
                    else
                    {
                        prev = ptr;
                        ptr = ptr->next;
                    }
                }
            }
            if (found == 0)
            {
                cout << "\n\n ID for deletion: " << ID << " Record Not Found...";
            }
        }
    }

    void Display()
    {
        if (head == NULL)
        {
            cout << "\n\n Empty Linked list...";
        }
        else
        {
            node *ptr = head;
            while (ptr != NULL)
            {
                cout << "\n\n ID: " << ptr->id;
                cout << "\n\n Name: " << ptr->name;
                cout << "\n\n Email: " << ptr->email;
                cout << "\n\n Address: " << ptr->address;
                cout << "\n\n Number of Rooms Booked: " << ptr->no_of_rooms_booked;
                cout << "\n\n Number of Days of Staying: " << ptr->no_of_days_of_stay;
                cout << "\n\n Total Bill: " << ptr->price;

                ptr = ptr->next;
            }
        }
    }
};

int main()
{
    hotel_management_system obj;
    int choice;
clr:
    cout << "\n\n";

    cout << "\t\tHOTEL MANAGEMENT SYSTEM\t\t";
    cout << "\n\n 1. Insert Record";
    cout << "\n\n 2. Search Record";
    cout << "\n\n 3. Number of Records";
    cout << "\n\n 4. Update Record";
    cout << "\n\n 5. Delete Record";
    cout << "\n\n 6. Show All Record";
    cout << "\n\n 7. Exit";
    cout << "\n\n\n Enter Your Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        obj.insert();
        break;

    case 2:
        obj.Search();
        break;
    case 3:
        obj.Count();
        break;
    case 4:
        obj.Update();
        break;
    case 5:
        obj.deletion();
        break;
    case 6:
        obj.Display();
        break;
    case 7:
        exit(0);
    default:
        cout << "\n\n\n Invalid Choice... Please Try Again";
    }
    getch();
    goto clr;
}
