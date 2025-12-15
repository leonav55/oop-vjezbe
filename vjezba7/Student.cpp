#include "Student.h"
clear();
move_from(std::move(o));
}
return *this;
}


int Student::get_total_students() { return total_students; }


Student& Student::operator+=(const Course& c) {
Course* tmp = new Course[enrolled_count + 1];
for (size_t i = 0; i < enrolled_count; i++) tmp[i] = enrolled_courses[i];
tmp[enrolled_count++] = c;
delete[] enrolled_courses;
enrolled_courses = tmp;
return *this;
}


void Student::complete_course(size_t index) {
Course passed = enrolled_courses[index];


Course* new_completed = new Course[completed_count + 1];
for (size_t i = 0; i < completed_count; i++) new_completed[i] = completed_courses[i];
new_completed[completed_count++] = passed;


Course* new_enrolled = new Course[enrolled_count - 1];
for (size_t i = 0, j = 0; i < enrolled_count; i++)
if (i != index) new_enrolled[j++] = enrolled_courses[i];


delete[] enrolled_courses;
delete[] completed_courses;
enrolled_courses = new_enrolled;
completed_courses = new_completed;
enrolled_count--;
}


int Student::completed_ects_current_year() const {
return completed_count * 5;
}


Student& Student::operator++() {
if (completed_ects_current_year() >= UniversityConstants::REQUIRED_ECTS_PER_YEAR)
year++;
return *this;
}


Student Student::operator++(int) {
Student tmp(*this);
++(*this);
return tmp;
}


std::ostream& operator<<(std::ostream& os, const Student& s) {
os << "ID: " << s.id << ", " << s.name << ", Program: " << s.study_program
<< ", Year: " << s.year;
return os;
}


std::istream& operator>>(std::istream& is, Student& s) {
is >> s.id >> s.name >> s.study_program >> s.year;
return is;
}
