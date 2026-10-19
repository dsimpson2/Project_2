#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std; // For simplicity, using namespace std in this example

class Student // Base class
{
protected:
    string firstName;
    string lastName;
    double gpa;
    int graduationYear;
    string graduationSemester;
    int enrolledYear;
    string enrolledSemester;
    string studentType; // Undergraduate or Graduate 

public: // Constructor with parameters

    // Default Constructor
    Student()
    {
        firstName = "Unknown";
        lastName = "Unknown";
        gpa = 0.0;
        graduationYear = 0;
        graduationSemester = "Unknown";
        enrolledYear = 0;
        enrolledSemester = "Unknown";
        studentType = "Undergraduate";
    }

    // Destructor
    virtual ~Student() {}

    // Setters
    void setName(string first, string last)
    {
        firstName = first;
        lastName = last;
    }

    void setGPA(double g)
    {
        gpa = g;
    }

    void setGraduationYear(int year)
    {
        graduationYear = year;
    }

    void setGraduationSemester(string sem)
    {
        graduationSemester = sem;
    }

    void setEnrolledYear(int year)
    {
        enrolledYear = year;
    }

    void setEnrolledSemester(string sem)
    {
        enrolledSemester = sem;
    }

    void setStudentType(string type)
    {
        studentType = type;
    }

    // Getters
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    double getGPA() const { return gpa; }
    int getGraduationYear() const { return graduationYear; }
    string getGraduationSemester() const { return graduationSemester; }
    int getEnrolledYear() const { return enrolledYear; }
    string getEnrolledSemester() const { return enrolledSemester; }
    string getStudentType() const { return studentType; }

    virtual void writeToFile(ofstream &out) const // Virtual function to write student data to file
    {
        out << "Name: " << firstName << " " << lastName << endl;
        out << "GPA: " << gpa << endl;
        out << "Graduation: " << graduationSemester
            << " " << graduationYear << endl;
        out << "Enrolled: " << enrolledSemester
            << " " << enrolledYear << endl;
        out << "Type: " << studentType << endl;
    }
};

class Art_Student : public Student // Derived class
{
private: // Additional attribute for Art Student
    string artEmphasis;

public: // Constructor
    Art_Student() : Student() // Call base class constructor
    {
        artEmphasis = "Art Studio";
    }

    ~Art_Student() {}

    void setArtEmphasis(string emphasis)
    {
        artEmphasis = emphasis;
    }

    string getArtEmphasis() const
    {
        return artEmphasis;
    }

    void writeToFile(ofstream &out) const override
    {
        out << "----- ART STUDENT -----" << endl;
        Student::writeToFile(out);
        out << "Art Emphasis: " << artEmphasis << endl;
        out << endl;
    }
};

class Physics_Student : public Student // Derived class
{
private: // Additional attribute for Physics Student
    string concentration;

public: // Constructor  
    Physics_Student() : Student()
    {
        concentration = "Physics";
    }

    ~Physics_Student() {}

    void setConcentration(string conc)
    {
        concentration = conc;
    }

    string getConcentration() const
    {
        return concentration;
    }

    void writeToFile(ofstream &out) const override // Override the base class function
    {
        out << "----- PHYSICS STUDENT -----" << endl;
        Student::writeToFile(out);
        out << "Concentration: " << concentration << endl;
        out << endl;
    }
};

int main()
{
    vector<Art_Student*> artStudents; // Vector to hold pointers to Art Students
    vector<Physics_Student*> physicsStudents; // Vector to hold pointers to Physics Students

    // Create 5 Art Students
    for (int i = 0; i < 5; i++)
    {
        artStudents.push_back(new Art_Student()); // Create a new Art Student and add to the vector
    }

    // Create 5 Physics Students
    for (int i = 0; i < 5; i++)
    {
        physicsStudents.push_back(new Physics_Student()); // Create a new Physics Student and add to the vector
    }

    // Assign values to Art Students
    artStudents[0]->setName("Alice", "Smith");
    artStudents[0]->setGPA(3.8);
    artStudents[0]->setGraduationYear(2027);
    artStudents[0]->setGraduationSemester("Spring");
    artStudents[0]->setEnrolledYear(2023);
    artStudents[0]->setEnrolledSemester("Fall");
    artStudents[0]->setStudentType("Undergraduate");
    artStudents[0]->setArtEmphasis("Art Studio");

    artStudents[1]->setName("Bob", "Jones");
    artStudents[1]->setGPA(3.5);
    artStudents[1]->setArtEmphasis("Art History");

    artStudents[2]->setName("Carol", "Lee");
    artStudents[2]->setGPA(3.9);
    artStudents[2]->setArtEmphasis("Art Education");

    artStudents[3]->setName("David", "Brown");
    artStudents[3]->setGPA(3.4);

    artStudents[4]->setName("Emma", "Wilson");
    artStudents[4]->setGPA(3.7);

    // Assign values to Physics Students
    physicsStudents[0]->setName("Frank", "Taylor");
    physicsStudents[0]->setGPA(3.9);
    physicsStudents[0]->setConcentration("Physics");

    physicsStudents[1]->setName("Grace", "Hall");
    physicsStudents[1]->setGPA(3.6);
    physicsStudents[1]->setConcentration("Earth and Planetary Sciences");

    physicsStudents[2]->setName("Henry", "Clark");
    physicsStudents[2]->setGPA(3.8);

    physicsStudents[3]->setName("Ivy", "King");
    physicsStudents[3]->setGPA(3.7);

    physicsStudents[4]->setName("Jack", "Young");
    physicsStudents[4]->setGPA(3.5);

    // Write all students to one file
    ofstream outFile("student_info.dat"); // Open the file for writing

    for (size_t i = 0; i < artStudents.size(); i++) // Write Art Students to file
    {
        artStudents[i]->writeToFile(outFile); // Call the virtual function to write student data to file
    }

    for (size_t i = 0; i < physicsStudents.size(); i++)
    {
        physicsStudents[i]->writeToFile(outFile);
    }

    outFile.close();

    // Delete allocated memory
    for (size_t i = 0; i < artStudents.size(); i++)
    {
        delete artStudents[i];
    }

    for (size_t i = 0; i < physicsStudents.size(); i++)
    {
        delete physicsStudents[i];
    }

    cout << "Student data written to student_info.dat" << endl; // Inform the user that the data has been written to the file

    return 0;
}  