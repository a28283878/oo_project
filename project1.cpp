#include <string>
#include "project1_starter.h"
#include <iostream>
using namespace std;

////// Course //////
Course::Course(){
    setCourseName("");
    setCourseId(0);
}

Course::Course( const string name, long id){
    setCourseName(name);
    setCourseId(id);
}

Course::Course( const Course& c){
    setCourseName(c.getCourseName());
    setCourseId(c.getCourseId());
}

Course& Course::operator=( const Course& other ){
    if(this != &other){
			setCourseName(other.getCourseName());
            setCourseId(other.getCourseId());
		}

    return *this;
}

bool Course::operator==( const Course& c){
    if(this->getCourseName() == c.getCourseName() &&
        this->getCourseId() == c.getCourseId()) return true;
    else return false;
}

bool Course::operator!=( const Course& c){
    if(this->getCourseName() == c.getCourseName() &&
        this->getCourseId() == c.getCourseId()) return false;
    else return true;
}

string Course::getCourseName() const{
    return this->courseName;
}

long Course::getCourseId() const{
    return this->courseId;
}

void Course::setCourseName(const string name){
    this->courseName = name;
    return;
}

void Course::setCourseId( long id){
    this->courseId = id;
}
/////// End Course //////

////// Person //////
Person::Person(){
    setName("");
    setAddress("");
    setIdentification(0);
}

Person::Person( const string theName, unsigned long theSSN, Date theBday, const string theAddress ){
    setName(theName);
    setIdentification(theSSN);
    setAddress(theAddress);
    this->birthdate = theBday;
}

Person::Person( const Person& p){
    setName(p.getName());
    setIdentification(p.getIdentification());
    setAddress(p.getAddress());
    this->birthdate = p.getBirthDate();
}

Person& Person::operator=( const Person& other){
    if(this != &other){
			setName(other.getName());
            setIdentification(other.getIdentification());
            setAddress(other.getAddress());
            this->birthdate = other.getBirthDate();
		}

    return *this;
}

void Person::setName( const string theName ){
    this->name = theName;
    return;
}

string Person::getName() const{
    return this->name;
}

void Person::setAddress( const string theAddress ){
    this->address = theAddress;
    return;
}

string Person::getAddress() const{
    return this->address;
}

void Person::setBirthDate( const Date theBirthDate){
    this->birthdate = theBirthDate;
    return;
}

Date Person::getBirthDate() const{
    return this->birthdate;
}

unsigned long Person::getIdentification() const{
    return this->ssn;
}

void Person::setIdentification( unsigned long newID ){
    this->ssn = newID;
    return;
}

void Person::print() const{
    cout <<"name: " << name << endl << "address: "<< address << endl
        <<"ssn: "<< ssn << endl << "birthdate: " << birthdate << endl;
}

////// End Person //////

////// Student //////
Student::Student(){
    setName("");
    setAddress("");
    setIdentification(0);
    setStatus(sUnknown);
    setDepartment(dUnknown);
    numCourses = 0;
}

Student::Student( const string theName, 
           unsigned long theSSN, 
	       const Date  theBirthDate,
           const string theAddress, 
           StudentStatus theStatus,
           Department theDepartment ){
    setName(theName);
    setIdentification(theSSN);
    setBirthDate(theBirthDate);
    setAddress(theAddress);
    setStatus(theStatus);
    setDepartment(theDepartment);
}

Student::Student( const Student& s){
    setName(s.getName());
    setIdentification(s.getIdentification());
    setBirthDate(s.getBirthDate());
    setAddress(s.getAddress());
    setStatus(s.getStatus());
    setDepartment(s.getDepartment());    
}

Student& Student::operator=( const Student& other){
    if(this != &other){
			setName(other.getName());
            setIdentification(other.getIdentification());
            setBirthDate(other.getBirthDate());
            setAddress(other.getAddress());
            setStatus(other.getStatus());
            setDepartment(other.getDepartment());
            copy(other.enrolled, other.enrolled + MaxCoursesForStudent, this->enrolled);
		}
    return *this;
}

Student::~Student(){
    delete [] enrolled;
}

void Student::setStatus( StudentStatus aStatus ){
    this->status = aStatus;
}
StudentStatus Student::getStatus() const{
    return this->status;
}
void Student::setDepartment( Department dept ){
    this->department = dept;
}
Department Student::getDepartment() const{
    return this->department;
}
bool Student::enrollForCourse(const Course& aCourse){
    if(numCourses >= MaxCoursesForStudent) return false;
    
    enrolled[numCourses] = &aCourse;
    numCourses = numCourses + 1;
    return true;
}
bool Student::dropFromCourse(const Course& theCourse){
    for(int i=0; i<MaxCoursesForStudent; i++){
        if(enrolled[i]->getCourseId == theCourse.getCourseId){
            for(int j=i; j<MaxCoursesForStudent - 1;j++){
                enrolled[j] = enrolled[j+1];
            }
            enrolled[MaxCoursesForStudent] = new Course();
            numCourses = numCourses - 1;
            return true;
        }
    }
    return false;
}
void Student::listCoursesRegisteredFor() const{
    for(int i=0; i<MaxCoursesForStudent; i++){
        if(enrolled[i]->getCourseId != 0 || enrolled[i]->getCourseId != NULL){
            cout<< "CourseName: " << enrolled[i]->getCourseName()<< endl
                << "CourseId :" << enrolled[i]->getCourseId() << endl;
        }
    }
    return;
}
void Student::print() const{
    cout <<"name: " << this->getName << endl << "address: "<< this->getAddress << endl
        <<"ssn: "<< this->getIdentification << endl << "birthdate: " << this->getBirthDate << endl;

    cout<<"status: "<<status<<endl
        <<"department: "<<department<<endl
        <<"Courses: ";
    this->listCoursesRegisteredFor();
    cout<<endl<<"numCourses: "<<numCourses;
        
}
////// End Student //////

////// Teacher //////
Teacher::Teacher(){
    setName("");
    setAddress("");
    setIdentification(0);
    setRank(rUnknown);
    setSalary(0);
    setDepartment(dUnknown);
    numCourses = 0;
    numGraders = 0;
}
Teacher::Teacher( const string theName, long theSSN, const Date theBirthDate,
        const string theAddress, Rank theRank, Department theDepartment){
    setName(theName);
    setAddress(theAddress);
    setIdentification(theSSN);
    setRank(theRank);
    setBirthDate(theBirthDate);
    setSalary(0);
    setDepartment(theDepartment);
    numCourses = 0;
    numGraders = 0;   
}
Teacher::Teacher( const Teacher& other ){
    setName(other.getName);
    setAddress(other.getAddress);
    setIdentification(other.getIdentification);
    setRank(other.getRank);
    setBirthDate(other.getBirthDate);
    setSalary(other.getSalary);
    setDepartment(other.getDepartment);
    copy(other.graders, other.graders + MaxGraders, this->graders);
    copy(other.coursesOffered, other.coursesOffered + MaxCoursesForTeacher, this->coursesOffered);
}
Teacher& Teacher::operator=( const Teacher& other ){
    if(this != &other){
			setName(other.getName);
            setAddress(other.getAddress);
            setIdentification(other.getIdentification);
            setRank(other.getRank);
            setBirthDate(other.getBirthDate);
            setSalary(other.getSalary);
            setDepartment(other.getDepartment);
            copy(other.graders, other.graders + MaxGraders, this->graders);
            copy(other.coursesOffered, other.coursesOffered + MaxCoursesForTeacher, this->coursesOffered);
		}
    return *this;
}
Teacher::~Teacher(){
    delete [] coursesOffered;
    delete [] graders;
}

void Teacher::setDepartment( Department dept ){
    this->department = dept;
    return;
}
Department Teacher::getDepartment() const{
    return this->department;
}

// change rank when the teacher is promoted
void Teacher::setRank( Rank newRank ){
    this->rank = newRank;
    return;
}
Rank Teacher::getRank() const{
    return this->rank;
}

void Teacher::listCoursesTaught() const{
    for(int i=0; i<MaxCoursesForStudent; i++){
        if(coursesOffered[i]->getCourseId != 0 || coursesOffered[i]->getCourseId != NULL){
            cout<< "CourseName: " << coursesOffered[i]->getCourseName()<< endl
                << "CourseId :" << coursesOffered[i]->getCourseId() << endl;
        }
    }
    return;
}
// offer this course
bool Teacher::offerCourse( const Course& aCourse ){
    if(numCourses >= MaxCoursesForStudent) return false;
    
    coursesOffered[numCourses] = &aCourse;
    numCourses = numCourses + 1;
    return true;
}
// cancel this course
bool Teacher::dropCourse( const Course& theCourse){
    for(int i=0; i<MaxCoursesForStudent; i++){
        if(coursesOffered[i]->getCourseId == theCourse.getCourseId){
            for(int j=i; j<MaxCoursesForStudent - 1;j++){
                coursesOffered[j] = coursesOffered[j+1];
            }
            coursesOffered[MaxCoursesForStudent] = new Course();
            numCourses = numCourses - 1;
            return true;
        }
    }
    return false;
}

bool Teacher::assignGrader( const string newGrader ){
    if(numGraders >= MaxGraders) return false;
    
    graders[numGraders] = &newGrader;
    numGraders = numGraders + 1;
    return true;
}
bool Teacher::dropGrader( const string grader ){
    for(int i=0; i<MaxGraders; i++){
        if(*graders[i] == grader){
            for(int j=i; j<MaxGraders - 1;j++){
                graders[j] = graders[j+1];
            }
            graders[MaxGraders] = new string();
            numGraders = numGraders - 1;
            return true;
        }
    }
    return false;
}
void Teacher::listGraders() const{
    for(int i=0; i<MaxGraders; i++){
        if(graders[i] != NULL){
            cout<< "Grader: " << graders[i]<< endl;
        }
    }
    return;
}

double Teacher::getSalary() const{
    return this->salary;
}
void Teacher::setSalary( double theSalary ){
    this->salary = theSalary;
    return;
}

void Teacher::print() const{
     cout <<"name: " << this->getName << endl << "address: "<< this->getAddress << endl
        <<"ssn: "<< this->getIdentification << endl << "birthdate: " << this->getBirthDate << endl;

    cout<<"rank: "<<rank<<endl
        <<"salary: "<<salary<<endl
        <<"Department: "<<department<<endl
        <<"numCourses: "<<numCourses<<endl
        <<"numGraders: "<<numGraders<<endl
        <<"Courses: "<<endl;
    this->listCoursesTaught();
    cout<<"Graders: "<<endl;
    this->listGraders();
}


////// End Teacher //////