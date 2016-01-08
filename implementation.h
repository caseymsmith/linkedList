#ifndef IMPLEMENTATION_H
#define IMPLEMENTATION_H
#include <fstream>
#include <iostream>
#include <list>
using namespace std;


class Student{
private:
    string first;
    string last;
    string id;
    string date; //birth date
    float gpa;
    char gender;
    string status; //freshman, sophomore, junior, senior


public:
    void setFirst(string fir);
    void setLast(string las);
    void setID(string id);
    void setBirthDate(string date);
    void setGender(char gender);
    void setGPA(float gpa);
    void setStatus(string status);

    string getFirst() const;
    string getLast() const;
    string getID() const;
    string getBirthDate()const;
    char getGender() const;
    float getGPA () const;
    string getStatus() const;

    friend istream& operator >> (istream& left, Student& right);
    friend ostream& operator << (ostream& right,const Student& left);

    Student();	//default constructor
    Student(const Student& student);


    friend void readFile(ifstream& infile, list <Student> & ll);
    friend void writeFile(ostream&, list <Student> & ll);
};


void insertOrder(list<Student> &orderedList, const Student &item);
void readFile(ifstream& infile, list <Student> & ll);
void writeFile(ostream&, list <Student> & ll);
bool doubleID(list<Student> &orderedList, string id);



#endif
