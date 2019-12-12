#include <string>
#include "project1_starter.h"
#include <iostream>
using namespace std;

Course::Course(){
    courseName = "";
    courseId = 0;
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

string Course::getCourseName(){
    return this->courseName;
}

long Course::getCourseId(){
    return this->courseId;
}

void Course::setCourseName(const string name){
    this->courseName = name;
    return;
}

void Course::setCourseId( long id){
    this->courseId = id;
}