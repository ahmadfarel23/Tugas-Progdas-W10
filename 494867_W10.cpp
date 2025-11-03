#include <iostream>
#include <iomanip>
#include <string>
#include <vector>   // digunakan agar bisa menampung jumlah mahasiswa dinamis
using namespace std;

struct studentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

// --- Deklarasi fungsi ---
void readData(vector<studentType>& students);
void assignGrades(vector<studentType>& students);
int findHighestScore(const vector<studentType>& students);
void printHighestScorers(const vector<studentType>& students, int highestScore);
void printAllStudents(const vector<studentType>& students);

int main() {
    int numberOfStudents;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> numberOfStudents;
    cout << endl;

    vector<studentType> students(numberOfStudents);

    // 1. Membaca data
    readData(students);

    // 2. Menentukan grade
    assignGrades(students);

    // 3. Mencari nilai tertinggi
    int highestScore = findHighestScore(students);

    // 4. Menampilkan semua data mahasiswa
    printAllStudents(students);

    // 5. Menampilkan mahasiswa dengan nilai tertinggi
    printHighestScorers(students, highestScore);

    return 0;
}

// ---------------- DEFINISI FUNGSI ----------------

void readData(vector<studentType>& students) {
    cout << "Masukkan nama depan, nama belakang, dan nilai ujian setiap mahasiswa:\n";
    for (size_t i = 0; i < students.size(); i++) {
        cout << "Mahasiswa " << i + 1 << ": ";
        cin >> students[i].studentFName >> students[i].studentLName >> students[i].testScore;
    }
}

void assignGrades(vector<studentType>& students) {
    for (auto& s : students) {
        if (s.testScore >= 90)
            s.grade = 'A';
        else if (s.testScore >= 80)
            s.grade = 'B';
        else if (s.testScore >= 70)
            s.grade = 'C';
        else if (s.testScore >= 60)
            s.grade = 'D';
        else
            s.grade = 'F';
    }
}

int findHighestScore(const vector<studentType>& students) {
    int highest = students[0].testScore;
    for (const auto& s : students) {
        if (s.testScore > highest)
            highest = s.testScore;
    }
    return highest;
}

void printHighestScorers(const vector<studentType>& students, int highestScore) {
    cout << "\nNilai tertinggi: " << highestScore << endl;
    cout << "Mahasiswa dengan nilai tertinggi:\n";
    for (const auto& s : students) {
        if (s.testScore == highestScore)
            cout << s.studentLName << ", " << s.studentFName << endl;
    }
}

void printAllStudents(const vector<studentType>& students) {
    cout << left << setw(20) << "\nNama"
         << setw(15) << "Nilai Ujian"
         << "Grade" << endl;
    cout << "---------------------------------------\n";
    for (const auto& s : students) {
        string fullName = s.studentLName + ", " + s.studentFName;
        cout << left << setw(20) << fullName
             << setw(15) << s.testScore
             << s.grade << endl;
    }
}
