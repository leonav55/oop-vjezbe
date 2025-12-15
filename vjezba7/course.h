#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <iostream>


class Course {
public:
std::string name;
std::string code;
int ects;


Course(const std::string& n = "", const std::string& c = "", int e = 5)
: name(n), code(c), ects(e) {}


friend std::ostream& operator<<(std::ostream&, const Course&);
friend std::istream& operator>>(std::istream&, Course&);
};
#endif
