//October 2015


#include <iostream>
#include <fstream>
#include "implementation.h"
#include <list>
#include <cstdlib>
#include <iomanip>

using namespace std;

void deleteStu(list<Student> &cosc220, string idNum);
string checkFname();
string checkLname();
string checkID();
string checkDate();
float checkGPA();
char checkGender();
string checkStatus();


int main() {


    ifstream infile;
    ofstream outfile;

    infile.open("/Users/Casey/Documents/data.txt");


    list<Student> cosc220;     //creates a blank list
    if (!infile.good()) {
        cout << "The file is not good" << endl;
        return 0;
    }

    int selection;
    Student x;
    string first;
    string last;
    string id;
    string date;
    float gpa;
    char gender;
    string status;

    bool repeat = false;

    readFile(infile, cosc220);

    cout << fixed << setprecision(2);
    do {

        if (!repeat) {

            cout << "\nThis is the current list of students:" << endl;
            list<Student>::iterator iter;
            for (iter = cosc220.begin(); iter != cosc220.end(); iter++) {
                cout << *iter << endl;
            }
            cout << "\nPlease make a valid selection from the following menu: \n"
                    << "1. Insert student record"
                    << "\n2. Delete student record"
                    << "\n3. Retrieve student record"
                    << "\n4. Modify student record"
                    << "\n5. Quit the system"
                    << endl << endl;
            cin >> selection;
        }
        repeat = false;

        if (selection == 1) {
            cout << endl;
            first=checkFname();
            last=checkLname();
            id=checkID();

            if (doubleID(cosc220, id)) {
                cout << "WARNING: The student ID you have entered is already in the list" << endl;
                repeat = true;
            }

            else {
                date=checkDate();
                gpa=checkGPA();
                gender=checkGender();
                status=checkStatus();
                //Validate user input

                x.setFirst(first);
                x.setLast(last);
                x.setID(id);
                x.setBirthDate(date);
                x.setGPA(gpa);
                x.setGender(gender);
                x.setStatus(status);
                //Set validated information to student "x"

                insertOrder(cosc220, x);
                //Insert validated student "x" information into the list.
            }

        }

        else if (selection == 2) {
            deleteStu(cosc220, checkID());  //calls function to delete the id number from the list
                                            //the user selects through the function parameter
        }

        else if (selection == 3) {

            int choice;

            list<Student> dupList = cosc220;

            do {
                cout << "\nHow would you like to retrieve the student record?" << endl
                        << "(make up to 2 selections)" << endl
                        << "1) First name" << endl
                        << "2) Last name" << endl
                        << "3) Student ID" << endl
                        << "4) Gender" << endl
                        << "5) Birthdate" << endl
                        << "6) Status" << endl
                        << "7) Print Results" << endl
                        << "8) Quit retrieve" << endl;


                cin >> choice;


                list<Student>::iterator iter;

                //iterator enables us to search through the list to find what we are
                //looking for (user enters target criteria via function)

                if (choice == 1) {
                    string name = checkFname();
                    for (iter = dupList.begin(); iter != dupList.end(); iter++) {
                        if (iter->getFirst() != name) {
                            dupList.erase(iter);
                        }
                    }
                }

                if (choice == 2) {
                    string name = checkLname();
                    for (iter = dupList.begin(); iter != dupList.end(); iter++) {
                        if (iter->getLast() != name) {
                            dupList.erase(iter);
                        }
                    }
                }

                else if (choice == 3) {
                    string id = checkID();
                    for (iter = dupList.begin(); iter != dupList.end(); iter++) {
                        if (iter->getID() != id) {
                            dupList.erase(iter);
                        }
                    }
                }

                else if (choice == 4) {
                    char g = checkGender();
                    for (iter = dupList.begin(); iter != dupList.end(); iter++) {
                        if (iter->getGender() != g) {
                            dupList.erase(iter);
                        }
                    }
                }

                else if (choice == 5) {
                    string date = checkDate();
                    for (iter = dupList.begin(); iter!=dupList.end(); iter++) {
                        if (iter->getBirthDate() != date) {
                            dupList.erase(iter);
                        }
                    }

                }

                else if (choice == 6) {
                    string stat = checkStatus();
                    for (iter = dupList.begin(); iter!=dupList.end(); iter++) {
                        if (iter->getStatus() != stat) {
                            dupList.erase(iter);
                        }
                    }
                }

                else if (choice == 7) {
                    list<Student>::iterator iter;
                    for (iter = dupList.begin(); iter != dupList.end(); iter++) {
                        cout << *iter << endl;
                    }
                }

            } while (choice != 8);

        }


        else if (selection == 4) {
            string modify;
            int numChoice;
            int confirm;
            string F;
            string L;
            float avg;
            string stat;

            bool retry = false;
            cout << "You chose to modify the student." << endl;
            modify = checkID();
            Student y;

            if (!retry){

                if (doubleID(cosc220, modify) == false) {
                    cout << "There is no such student with that ID" << endl;
                    retry = false;
                }
                //makes sure there is a student with the ID to modify. If not,
                //returns an error message.
            }


            //outputs the student with the target ID. Creates a copy of that
            //student in student object y. Shows list to offer user options
            //then checks the conditions based on what the user wants to
            //modify. After checking conditions, the user confirms whether
            //the update is correct and if it is, the update is inserted
            //into the list. If it is not what the user desires, the user
            //returns to the main menu.

            if(doubleID(cosc220, modify) == true){
                cout << "Here is the student with that ID:" << endl;

                list<Student>::iterator iter;
                bool found=false;
                for (iter = cosc220.begin(); iter != cosc220.end() && !found; iter++) {
                    if (iter->getID() == modify) {
                        y=*iter;
                        cosc220.erase(iter);
                        found=true;
                    }
                }

                cout << y << endl;

                cout << "\n What would you like to modify?" << endl
                    << "1. First name" << endl << "2. Last name" << endl << "3. GPA" << endl
                    << "4. Status" << endl;
                cin >> numChoice;

                if (numChoice == 1){
                    F= checkFname();
                    Student copy= y;
                    copy.setFirst(F);
                    cout << endl << copy << endl
                            << "Is the above the modified student you want in the list?" << endl
                            << "1. yes" << endl << "2. no" << endl;
                    cin >> confirm;

                    if(confirm == 1){

                        insertOrder(cosc220, copy);
                    }
                    else {
                        insertOrder(cosc220, y);
                        cout << "OK, you will now be returned to the main menu." << endl;
                    }

                }

                else if (numChoice == 2){
                    L= checkLname();
                    Student copy= y;
                    copy.setLast(L);
                    cout << endl << copy << endl
                            << "Is the above the modified student you want in the list?" << endl
                            << "1. yes" << endl << "2. no" << endl;
                    cin >> confirm;

                    if(confirm == 1){

                        insertOrder(cosc220, copy);
                    }
                    else {
                        insertOrder(cosc220, y);
                        cout << "OK, you will now be returned to the main menu." << endl;
                    }

                }

                else if(numChoice == 3){
                    avg= checkGPA();
                    Student copy= y;
                    copy.setGPA(avg);
                    cout << endl << copy << endl
                            << "Is the above the modified student you want in the list?" << endl
                            << "1. yes" << endl << "2. no" << endl;
                    cin >> confirm;

                    if(confirm == 1){

                        insertOrder(cosc220, copy);
                    }
                    else {
                        insertOrder(cosc220, y);
                        cout << "OK, you will now be returned to the main menu." << endl;
                    }

                }

                else if(numChoice == 4){
                    stat= checkStatus();
                    Student copy= y;
                    copy.setStatus(stat);
                    cout << endl << copy << endl
                            << "Is the above the modified student you want in the list?" << endl
                            << "1. yes" << endl << "2. no" << endl;
                    cin >> confirm;

                    if(confirm == 1){

                        insertOrder(cosc220, copy);
                    }
                    else {
                        insertOrder(cosc220, y);
                        cout << "OK, you will now be returned to the main menu." << endl;
                    }

                }

                else{
                    insertOrder(cosc220, y);
                    cout << "\n You have made an invalid selection." << endl
                            << "You will now return to the main menu." << endl;
                }

            }


            //display info for that student
            //user can only modify first, last, gpa , and status
            //new info must be validated
            //prompt user for confirmation of final update
        }


    }while (selection != 5 && selection < 5 && selection >= 1);

    if (selection > 5 || selection < 1){
        cout << "\nYou have made an invalid selection from the main menu. "
                "\nThe program will now end and we saved your changes." << endl;

    }   //enables user to escape main menu with an invalid number choice.
        //without this statement, the user would be given the same menu,
        //unable to quit unless he/she entered 5 to quit.


    infile.close();

    outfile.open("/Users/Casey/Documents/data.txt");

    writeFile(outfile, cosc220);

        return 0;
    }


//All are functions below to check for particular criteria of each element.
//Functions return error messages for invalid user input.


    string checkLname() {
        string last;
        bool good = false;

        while (!good) {
            cout << "Please input the student's last name" << endl;
            cin >> last;

            if (last.size() >= 10000) {
                good = false;
                cout << "Your entry is invalid. Try again" << endl;
            }
            else
                for (int i = 0; i < last.size(); i++) {
                    if (isdigit(last[i])) {
                        good = false;
                        cout << "Your entry is invalid. Try again." << endl;
                    }
                    else
                        good = true;
                }
        }


        return last;
    }

    string checkFname() {
        string first;
        bool good = false;

        do{

            cout << "Please input the student's first name" << endl;
            cin >> first;

            if (first.size() >= 10000) {
                good = true;
                cout << "Your entry is invalid. Try again." << endl;
            }
            else
                for(int i = 0; i < first.size(); i++)
                    if(isdigit(first[i])) {
                        good = true;
                        cout << "Your entry is invalid. Try again." << endl;
                    }
                    else
                        good = false;
        }while(good);

        return first;
    }

    string checkID() {

        string id;
        bool bad = false;

        do {

           bad = false;

            cout << "Please input the student's 8 digit ID" << endl;
            cin >> id;

            if (id.size() == 8) {
                for (int i = 0; i < 8 && !bad; i++) {
                    if (!isdigit(id[i])) {
                        cout << "The ID number you have entered is invalid. Please try again." << endl;
                        bad = true;
                    }
                }
            }
            else {
                cout << "The ID number you have entered is invalid. Please try again." << endl;
                bad=true;
            }

        } while (bad);

        return id;

    }

    string checkDate() {
        string date;
        bool good = false;

        do {
            cout << "Please input the student's birthdate in the format mm/dd/yyyy" << endl;
            cin >> date;

            if (date.size() == 10 && date[2] == '/' && date[5] == '/' && isdigit(date[0]) && isdigit(date[1])
                    && isdigit(date[3]) && isdigit(date[4]) && isdigit(date[6])
                    && isdigit(date[7]) && isdigit(date[8]) && isdigit(date[9])) {
                good = false;
            }
            else {
                cout << "The date you have entered is invalid. Please try again." << endl;
                good = true;
            }

        } while (good);

        return date;

    }

    float checkGPA() {
        bool good = false;
        string gpa;

        do {
            cout << "Please input the student's  GPA in the format 0.00" << endl;
            cin >> gpa;

            if (gpa.size() == 4 && isdigit(gpa[0]) && gpa[1]=='.' && isdigit(gpa[2])
                    && isdigit(gpa[3])) {
                if(atoi(gpa.c_str()) >= 0 && atoi(gpa.c_str()) <=4 ) {
                    good = false;
                }
                else {
                    cout << "The GPA you have entered is invalid. It must be between 0 and 4" << endl;
                    good = true;
                }
            }

            else {
                cout << "The GPA you have entered is invalid." << endl;
                good = true;
            }

        } while (good);

        return (float) atof(gpa.c_str());
    }


    char checkGender() {
        char gender;
        bool good = false;

        do {
            cout << "Please input the student's gender (m/f)" << endl;
            cin >> gender;

            if (gender != 'm' && gender != 'f') {
                good = true;
                cout << "The gender you have entered is invalid." << endl;
            }
            else
                good = false;

        } while (good);

        return gender;
    }


    string checkStatus() {
        string status;
        bool good = false;

        do {
            cout << "Please input the student's status (freshman, sophomore, junior, senior)" << endl;
            cin >> status;

            if (status != "freshman" && status != "sophomore" && status != "junior"
                    && status != "senior" && status != "Freshman" && status != "Sophomore"
                    && status != "Junior" && status != "Senior") {
                cout << "The status you have intered is invalid." << endl;
                good = true;
            }
            else
                good = false;

        } while (good);

        return status;
    }


//Function to look through the list, find what we are looking for, delete
//the item in the list if it is found and then let the user know it was found
//and deleted. If it is not found, an error message is returned letting the
//user know it was not found in the list.
    void deleteStu(list<Student> &orderedList, string idNum) {
        list<Student>::iterator curr = orderedList.begin();
        list<Student>::iterator stop = orderedList.end();

        while (curr != stop && (curr->getID() != idNum)) {
            curr++;
        }


        if (curr != stop) {
            orderedList.erase(curr);
            cout << "The student has been removed from the list. \n You will now be "
                    "returned to the main menu." << endl;
        }

        else{
            cout << "The student ID you have entered was not in the list." <<
                    endl << "You will now be returned to the main menu." << endl;
        }


    }
