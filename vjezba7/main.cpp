#include <vector>
#include "StudentOffice.h"
#include "UniversityConstants.h"


int main() {
UniversityConstants::print_university_rules();


Student s1(1, "Ana", "CS", 1);
Student s2(2, "Ivan", "Math", 1);


Course c1("Programming", "CS101");
Course c2("Algorithms", "CS102");


StudentOffice::enroll_student(s1, c1);
StudentOffice::enroll_student(s1, c2);


StudentOffice::process_exam_results(s1, 0);
StudentOffice::process_exam_results(s1, 0);


std::vector<Student> students = {s1, s2};
StudentOffice::update_student_years(students);


for (const auto& s : students)
std::cout << s << '\n';


std::cout << "Total students: " << Student::get_total_students();
}
