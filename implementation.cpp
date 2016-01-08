#ifndef IMPLEMENTATION_CPP
#define IMPLEMENTATION_CPP
//Guard prevents recreating functions

#include "implementation.h"
using namespace std;
#include <iomanip>
#include <iterator>


//makes sure there isn't already a student with that id
bool doubleID(list<Student> &orderedList, string id) {
    list<Student>::iterator curr = orderedList.begin();
    list<Student>::iterator stop = orderedList.end();


    while (curr != stop && (curr->getID() != id)) {
        curr++;
    }
    return curr != stop && curr->getID() == id;
    //returns true if there is a duplicate
}

void insertOrder(list<Student> &orderedList, const Student &item) {
    list<Student>::iterator curr = orderedList.begin();
    list<Student>::iterator stop = orderedList.end();

    while (curr != stop && (curr->getID() < item.getID())) {
        curr++;
    }
    orderedList.insert(curr, item);
}


void readFile(ifstream &infile, list <Student> & ll) {
    Student tempStudent;

    while (infile.good() && !infile.eof()) {
        infile >> tempStudent;
        //operator overloading sets Student members

        if(!doubleID(ll, tempStudent.getID()))
        insertOrder(ll,tempStudent);

    }

    //creates a temporary student for every student in the file
    //then copies to the list
}

//prints list to the new file
void writeFile(ostream &out, list <Student> & ll) {

    list<Student>::iterator iter, iter2;

    //1st paramenter = position [0] in the linked list

    for (iter = ll.begin(); iter != ll.end(); iter++) {
        out << iter->first << ' ' << iter->last << ' ' << iter->id << ' '
                << iter->date << ' '
                << iter->gpa << ' '
                << iter->gender << ' '
                << iter->status << endl; //puts what's inside of iter into the out file
    }

}


//The following returns the input stream
istream &operator>>(istream &left, Student &right) {

    left >> right.first >> right.last >> right.id
            >> right.date >> right.gpa
            >> right.gender >> right.status;
    return left;
}

//The following returns the output stream
ostream &operator<<(ostream &out, const Student &right) {

    string word = right.last + ", " + right.first;

    out << word << ' '
            << right.id << ' '
            << right.date << ' '
            << right.gpa << ' '
            << right.gender << ' '
            << right.status;
    out << ' ';
    return out;
}


Student::Student(){
    first=" ";
    last=" ";
    id=" ";
    date=" ";
    gpa=00;
    gender=' ';
    status=" ";
}

Student::Student(const Student& student){
    first = student.getFirst();
    last = student.getLast();
    id = student.getID();
    date = student.getBirthDate();
    gender=student.getGender();
    gpa = student.getGPA();
    status = student.getStatus();

}



//this pointer (this->) enables compiler to understand which variable comes from where.
//ex. this->id=id;
//object from inside the class = parameter object


//This allows access and sets the first name
void Student::setFirst(string fir) {
    this->first = fir;
}

//This allows access and sets the last name
void Student::setLast(string las) {
    this->last = las;
}

//This allows access and sets the id number
void Student::setID(string id) {
    this->id = id;
}

//This allows access and sets the birthdate
void Student::setBirthDate(string date) {
    this->date=date;
}

//This allows access and sets the gender
void Student::setGender(char gender) {
    this->gender = gender;
}

//This allows access and sets the GPA
void Student::setGPA(float gpa) {
    this->gpa = gpa;
}

//This allows access and sets the status
void Student::setStatus(string status) {
    this->status = status;
}

//This allows access and sets the first name
string Student::getFirst() const {
    return first;
}

//This allows access and sets the last name
string Student::getLast() const {
    return last;
}

//This allows access and sets the ID
string Student::getID() const {
    return id;
}

//This allows access and sets the birthdate
string Student::getBirthDate()const{
    return date;
}

//This allows access and sets the gender
char Student::getGender() const {
    return gender;
}

//This allows access and sets the GPA
float Student::getGPA() const {
    return gpa;
}

//This allows access and sets the status
string Student::getStatus() const {
    return status;
}



#endif
