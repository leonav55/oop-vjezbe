#ifndef STUDENT_H
#define STUDENT_H


#include <string>
#include <iostream>
#include "Course.h"


class Student {
private:
int id;
std::string name;
std::string study_program;
int year;


Course* enrolled_courses;
size_t enrolled_count;


Course* completed_courses;
size_t completed_count;


static int total_students;


void copy_from(const Student& other);
void move_from(Student&& other) noexcept;
void clear();


public:
Student(int id = 0,
const std::string& name = "",
const std::string& study_program = "",
int year = 1);


// Rule of Five
Student(const Student& other);
Student(Student&& other) noexcept;
Student& operator=(const Student& other);
Student& operator=(Student&& other) noexcept;
~Student();


static int get_total_students();


void complete_course(size_t index);
int completed_ects_current_year() const;


Student& operator+=(const Course& c);
Student& operator++(); // prefix
Student operator++(int); // postfix


friend std::ostream& operator<<(std::ostream&, const Student&);
friend std::istream& operator>>(std::istream&, Student&);
friend class StudentOffice;
};


#endif
