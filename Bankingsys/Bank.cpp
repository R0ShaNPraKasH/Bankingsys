#include <iostream>
#include <string>
using namespace std;
class bank
{
    private :
    int total;
    string ID,PW;
    string pas = "TFAR777"; // Password Of Bank Admin
    struct person
    {
        string name,id,pw;
        int contact,cash;
    }person[200]; // 200 Bank Accounts Supported
    
    public :
    bank()
    {
        total = 0;
    }
    void choice();
    void newdata();
    void showdata();
    void update();
    void find();
    void transaction();
    void delet();
};
int main()
{
    bank b; // Object b is created
    b.choice();
    return 0;
}
void bank::choice()
{
    char ch;
    while(1) // For loop to run infinitely until manual exit
    {
        cout << "\n\nPlease choose from the following options: \n";
        cout << "1 for creating new account\n";
        cout << "2 for viewing customer list\n";
        cout << "3 for updating information of account\n";
        cout << "4 for details of account\n";
        cout << "5 for Debiting/Withdrawing money\n";
        cout << "6 for Removing Bank account\n";
        cout << "7 for Exit\n";
        cin >> ch;
        switch (ch)
        {
            case '1':
            bank::newdata();
            break;

            case '2':
            bank::showdata();
            break;

            case '3':
            bank::update();
            break;

            case '4':
            bank::find();
            break;

            case '5':
            bank::transaction();
            break;

            case '6':
            bank::delet();
            break;

            case '7':
            exit(0);  // Manual Exit
            break;
        }
    }
}
void bank::newdata()
{
    cout << "Enter data of person: " << total+1 << endl;
    cin.ignore(); // For getline to work properly
    cout << "Enter name: ";
    getline(cin, person[total].name); // To get The full name of the user including Space.
    cout << "Enter I.D: ";
    cin >> person[total].id;
    cout << "Enter Transaction Password: "; // Password of the user for Transactions and updating details.
    cin >> person[total].pw;
    cout << "Enter Contact no: ";
    cin >> person[total].contact;
    cout << "Enter Amount of cash initially debitted: ";
    cin >> person[total].cash;
    total ++;
}
void bank::showdata() // Func to display the entire customer list
{
    string pasw;
    cin.ignore(); // Again, for getline to work properly
    cout << "Enter Bank Owner's Password To View All Customer Details: ";
    getline(cin, pasw);
    if (pasw == pas) // Only Bank Admin should be able to View All the Accounts
    {
    for(int i=0;i<total;i++)
    {
        cout << "\nData of person " << i+1 << endl;
        cout << "Name: " << person[i].name << endl;
        cout << "I.D: " << person[i].id << endl;
        cout << "Contact No: " << person[i].contact << endl;
        cout << "Balance: " << person[i].cash << endl;
    }
    }
    else
    {
        cout << "Wrong Password!";
    }
}
void bank::update() // To update the personal details
{
    cout << "Enter I.D: ";
    cin >> ID;
    for(int i=0; i<total ; i++)
    {
        if (ID == person[i].id)
        {
            back1: // part of goto. Cursor will come here when password becomes wrong in line 157.
            cout << "Enter Transaction Password: ";
            cin >> PW;
            if(PW == person[i].pw) // Password Should Be Correct For Updating Details.
            {            
            cout << "Already Existing Data \n";
            cout << "Data of person " << i+1 << endl;
            cout << "Name: " << person[i].name << endl;
            cout << "I.D: " << person[i].id << endl;
            cout << "Transaction Password: " << person[i].pw << endl;
            cout << "Contact No: " << person[i].contact << endl;
            cout << "Balance: " << person[i].cash <<"\n\n";
            cout << "Enter New Data: \n";

            cin.ignore(); // For the getline in ln 143 to work properly.
            cout << "Enter name: ";
            getline(cin,person[i].id); // Again just cin would stop at the space in between the first name and the surname.
            cout << "Enter I.D: ";
            cin >> person[i].id;
            cout << "Enter New Transaction Password: ";
            cin >> person[i].pw;
            cout << "Enter Contact no: ";
            cin >> person[i].contact;
            cout << "Enter Amount of cash initially debitted: ";
            cin >> person[i].cash;  
            break;   
            } 
            else
            {
                cout << "Wrong Password . Try Again .";
                goto back1; // To return to line 127 for reenterring the password. 
            }      
        }
        if(i == total-1)
        {
            cout << "No Existing Account Found";
        }
    }
}
void bank::find() // To Find a specific account using the id.
{
    cout << "Enter I.D: ";
    cin >> ID;
    for(int i=0; i<total; i++)
    {
        if(ID == person[i].id)
        {
            cout << "Enter Password: ";
            cin >> PW;
            if(PW == person[i].pw)
            {
            cout << "Name: " << person[i].name << endl;
            cout << "I.D: " << person[i].id << endl;
            cout << "Contact No: " << person[i].contact << endl;
            cout << "Balance: " << person[i].cash << endl;
            break; 
            }           
        }
        if(i == total-1)
        {
            cout << "No Existing Account Found";
        }
    }
}
void bank::transaction() // For Withdrawing and Depositting Money
{
    int money;
    char inp;
    cout << "Enter I.D for Transaction: ";
    cin >> ID;
    for(int i=0;i<total;i++)
    {
        if(ID == person[i].id)
        {
            cout << "Enter Password: ";
            cin >> PW;
            if(PW == person[i].pw)
            {
            cout << "Name: " << person[i].name << endl;
            cout << "Contact No: " << person[i].contact << endl;
            cout << "\nBalance: " << person[i].cash << endl; 
            cout << "Press 1 for deposit\n";
            cout << "Press 2 for withdrawal\n";
            cin >> inp;
            switch(inp)
            {
                case '1':
                cout << "How much money to deposit: ";
                cin >> money;
                person[i].cash += money;
                cout << "Your new Balance is: " << person[i].cash;
                break;

                case '2':
                back:
                cout << "How much money to withdraw: ";
                cin >> money;
                if(money>person[i].cash)
                {
                    cout << money << " is greater than your existing balance of: " << person[i].cash << endl;
                    goto back;
                }
                person[i].cash -= money;
                cout << "Your new Balance is: " << person[i].cash;
                break;

                default:
                cout << "Invalid Input\n";
                break;
            } 
            break;
            }        
        }
        if(i == total-1)
        {
            cout << "No Existing Account Found";
        }
    }
}
void bank::delet() // Function to Delete Account.
{
    char inp;
    int l = 0;
    cout << "Enter 1 to delete One Account\n";
    cout << "Enter 2 to delete All Accounts\n";
    cin >> inp;
    switch(inp)
    {
        case '1':
        cout << "Enter I.D: ";
        cin >> ID;
        for(int i=0;i<total;i++)
        {
            if(ID == person[i].id)
            {
                for(int j = i;j<total;j++)
                {
                    person[j].name = person[j+1].name;
                    person[j].pw = person[j+1].pw;
                    person[j].cash = person[j+1].cash;
                    person[j].id = person[j+1].id;
                    person[j].contact = person[j+1].contact;
                    if (l==0)
                    {
                        total --;
                        l++;
                    }
                    
                    
                }
                break;
            }
            if(i==total-1)
            {
                cout << "No Such Existing Account Found";
                break;
            }
        }
        break;
        
        case '2':
        total = 0;
        cout << "All Record is deleted"<<endl;
        break;

        default:
        cout << "No Account Found\n";
        break;
    }

}