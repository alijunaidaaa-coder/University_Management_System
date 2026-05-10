#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include "Student.h"
#include "Assessment.h" // Include the assessment file we just made

class Course {
protected:
    std::string courseID;
    std::string title;
    std::string teacherID;
    std::vector<Student*> enrolledStudents;
    std::vector<Assessment*> assessments; // Array of pointers as requested

public:
    Course(std::string id, std::string t, std::string tId)
        : courseID(id), title(t), teacherID(tId) {}
    
    virtual ~Course() {
        // We will write the memory cleanup in the cpp file later
    }

    // Pure virtual functions for polymorphism
    virtual double calculateFinalGrade(Student* student) = 0;
    virtual int getExamDuration() const = 0;

    void enrollStudent(Student* student) { enrolledStudents.push_back(student); }
    
    std::string getCourseID() const { return courseID; }
    std::string getTitle() const { return title; }
};

class CoreCourse : public Course {
public:
    CoreCourse(std::string id, std::string t, std::string tId) : Course(id, t, tId) {}
    double calculateFinalGrade(Student* student) override;
    int getExamDuration() const override { return 3; } // 3-hour slot
};

class ElectiveCourse : public Course {
public:
    ElectiveCourse(std::string id, std::string t, std::string tId) : Course(id, t, tId) {}
    double calculateFinalGrade(Student* student) override;
    int getExamDuration() const override { return 2; } // 2-hour slot
};

class LabCourse : public Course {
public:
    LabCourse(std::string id, std::string t, std::string tId) : Course(id, t, tId) {}
    double calculateFinalGrade(Student* student) override;
    int getExamDuration() const override { return 0; } // No final exam, 100% continuous
};

#endif