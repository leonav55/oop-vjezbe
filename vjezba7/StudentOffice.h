#ifndef STUDENT_OFFICE_H
#define STUDENT_OFFICE_H
#include "Student.h"
#include <vector>


class StudentOffice {
public:
static void moveStudent(Student& s, std::string new_program);
static bool enroll_student(Student& s, const Course& c);
static void process_exam_results(Student& s, size_t index);
static void update_student_years(std::vector<Student>& students);
};
#endif
