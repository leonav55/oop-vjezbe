#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <fstream>
#include <cmath>
#include <string>

//
// ===== 1. RAD S VEKTOROM BROJEVA =====
//
namespace number_utils {

bool is_power_of_two(int x) {
    if (x <= 0) return false;
    return (x & (x - 1)) == 0;
}

void process_numbers(std::vector<int>& v) {
    // prvi neparni
    auto firstOdd = std::find_if(v.begin(), v.end(),
        [](int x) { return x % 2 != 0; });

    if (firstOdd != v.end())
        std::cout << "Prvi neparni: " << *firstOdd << "\n";
    else
        std::cout << "Nema neparnih brojeva\n";

    // broj neparnih
    int oddCount = std::count_if(v.begin(), v.end(),
        [](int x) { return x % 2 != 0; });

    std::cout << "Broj neparnih: " << oddCount << "\n";

    // prosjek neparnih
    int oddSum = std::accumulate(v.begin(), v.end(), 0,
        [](int sum, int x) {
            return x % 2 != 0 ? sum + x : sum;
        });

    if (oddCount > 0) {
        double avg = static_cast<double>(oddSum) / oddCount;
        std::cout << "Prosjek neparnih: " << avg << "\n";
    }

    // zamjena potencija broja 2 sa 2
    std::replace_if(v.begin(), v.end(),
        is_power_of_two, 2);

    // ispis: parni pa neparni, sortirani
    std::vector<int> even, odd;
    std::copy_if(v.begin(), v.end(), std::back_inserter(even),
        [](int x) { return x % 2 == 0; });

    std::copy_if(v.begin(), v.end(), std::back_inserter(odd),
        [](int x) { return x % 2 != 0; });

    std::sort(even.begin(), even.end());
    std::sort(odd.begin(), odd.end());

    std::cout << "Parni: ";
    std::copy(even.begin(), even.end(),
        std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\nNeparni: ";
    std::copy(odd.begin(), odd.end(),
        std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
}

} // namespace number_utils

//
// ===== 2. MATH_UTILS =====
//
namespace math_utils {

struct Point {
    double x, y;
};

double distance(const Point& a, const Point& b = {0, 0}) {
    return std::sqrt((a.x - b.x) * (a.x - b.x) +
                     (a.y - b.y) * (a.y - b.y));
}

Point centroid(const std::vector<Point>& points) {
    Point sum = std::accumulate(points.begin(), points.end(), Point{0, 0},
        [](Point acc, const Point& p) {
            acc.x += p.x;
            acc.y += p.y;
            return acc;
        });

    return {
        sum.x / static_cast<double>(points.size()),
        sum.y / static_cast<double>(points.size())
    };
}

} // namespace math_utils

//
// ===== 3. STUDENT_RECORDS =====
//
namespace student_records {

struct Student {
    std::string ime;
    std::string prezime;
    int bodovi;
};

int bodovi_u_ocjenu(int bodovi) {
    if (bodovi < 40) return 1;
    if (bodovi < 55) return 2;
    if (bodovi < 70) return 3;
    if (bodovi < 85) return 4;
    return 5;
}

} // namespace student_records

//
// ===== MAIN =====
//
int main() {

    // ===== 1. BROJEVI =====
    std::cout << "=== BROJEVI ===\n";
    std::vector<int> brojevi = {1, 2, 3, 4, 5, 8, 16, 7, 9, 10};
    number_utils::process_numbers(brojevi);

    // ===== 2. TOCKE =====
    std::cout << "\n=== TOCKE ===\n";
    std::ifstream file("points.txt");
    std::vector<math_utils::Point> points(
        (std::istream_iterator<math_utils::Point>(file)),
         std::istream_iterator<math_utils::Point>());

    std::sort(points.begin(), points.end(),
        [](const math_utils::Point& a, const math_utils::Point& b) {
            return math_utils::distance(a) < math_utils::distance(b);
        });

    int firstQuadrant = std::count_if(points.begin(), points.end(),
        [](const math_utils::Point& p) {
            return p.x > 0 && p.y > 0;
        });

    std::cout << "Tocaka u prvom kvadrantu: " << firstQuadrant << "\n";

    auto c = math_utils::centroid(points);
    std::cout << "Centroid: (" << c.x << ", " << c.y << ")\n";

    std::transform(points.begin(), points.end(), points.begin(),
        [](math_utils::Point p) {
            p.x += 5;
            p.y += 3;
            return p;
        });

    points.erase(
        std::remove_if(points.begin(), points.end(),
            [](const math_utils::Point& p) {
                return p.x < 0 && p.y < 0;
            }),
        points.end()
    );

    std::copy(points.begin(), points.end(),
        std::ostream_iterator<math_utils::Point>(std::cout, "\n"));

    // ===== 3. STUDENTI =====
    std::cout << "\n=== STUDENTI ===\n";
    std::ifstream sf("studenti.txt");
    std::vector<student_records::Student> students(
        (std::istream_iterator<student_records::Student>(sf)),
         std::istream_iterator<student_records::Student>());

    students.erase(
        std::remove_if(students.begin(), students.end(),
            [](const student_records::Student& s) {
                return s.bodovi < 40;
            }),
        students.end()
    );

    std::transform(students.begin(), students.end(), students.begin(),
        [](student_records::Student s) {
            s.bodovi = student_records::bodovi_u_ocjenu(s.bodovi);
            return s;
        });

    double avgGrade = std::accumulate(students.begin(), students.end(), 0.0,
        [](double sum, const student_records::Student& s) {
            return sum + s.bodovi;
        }) / static_cast<double>(students.size());

    std::sort(students.begin(), students.end(),
        [](const student_records::Student& a,
           const student_records::Student& b) {
            return a.prezime < b.prezime;
        });

    for (const auto& s : students) {
        std::cout << s.ime << " " << s.prezime
                  << " - ocjena: " << s.bodovi << "\n";
    }

    std::cout << "Prosjek ocjena: " << avgGrade << "\n";

    return 0;
}
