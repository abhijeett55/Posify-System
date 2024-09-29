#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>

using namespace std;

class Bill {
    private :
    string Item ;
    int Rate, Quantity;

    public: 
    Bill():Item(" "), Rate(0), Quantity(0) { }

    void setItem(string item) {
        Item = item;
    }

     void setRate(int rate) {
        Rate = rate;
    }

    void setQuant(int quant) {
        Quantity = quant;
    }

    string getItem () {
        return Item;
    }

    int getRate() {
        return Rate;
    }
    int getQuant() {
        return Quantity;
    }
};

void addItem(Bill b) {
    bool close = false;
    while (!close) {
        int choice;
        cout << "\t1.Add" <<endl;
        cout << "\t2.Close" <<endl;
        cout << "\t Enter Choice : " <<endl;
        cin >> choice;

        if (choice == 1) {
            system("cls");
            string item;
            int rate;
            int quant;

            cout <<"\tEnter Item Name: ";
            cin >> item;
            b.setItem(item);

            cout <<"\t Enter Rate of Item: ";
            cin>> rate;
            b.setRate(rate);

            cout <<"\t Enter Quantity of Item: ";
            cin>> quant;
            b.setQuant(quant);

            ofstream out ("C:/Users/abhii/OneDrive/Documents/GitHub/Posify-System/resource/Bill.txt", ios:: app);
            if (!out) {
                cout << "\t Error: File Cant't Open!" <<endl;
            }
            else {
                cout << "\t" << b.getItem() << " : " << b.getRate() << " : " <<b.getQuant() <<endl <<endl;
            }
            out.close();
            cout << "\tItem added Successfully" << endl;
            Sleep(3000);
        }

        else if(choice == 2) {
            system("cls");
            close = true;
            cout << "\t Back to Main Menu" << endl;
            Sleep(3000);
        }
    } 
}

int main() {
    //Object
    Bill b;

    bool exit = false;
    while (!exit) {
        system("cls");
        int val;
        cout <<"\t Welcome to Posify Management System" <<endl;
        cout <<"\t ***********************************" <<endl;
        cout << "\t \t1.Add Item." <<endl;
        cout << "\t \t2.Print Bill." <<endl;
        cout << "\t \t3.Exit." <<endl;
        cout << "\t \tEnter Choice: ";
        cin >> val;

        if (val==1) {
            addItem(b);
        }
    }
}