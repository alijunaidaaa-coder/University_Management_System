#ifndef ASSESSMENT_H
#define ASSESSMENT_H

#include <string>

class Assessment {
protected:
    std::string type;
    double rawScore;
    double maxScore;
    double weightage;

public:
    Assessment(std::string t, double raw, double max, double w)
        : type(t), rawScore(raw), maxScore(max), weightage(w) {}
    
    virtual ~Assessment() = default;

    // Calculates how much this assessment contributes to the final grade
    double getCalculatedScore() const {
        return (rawScore / maxScore) * weightage;
    }
};

class Exam : public Assessment {
public:
    Exam(double raw, double max, double w) : Assessment("Exam", raw, max, w) {}
};

class Quiz : public Assessment {
public:
    Quiz(double raw, double max, double w) : Assessment("Quiz", raw, max, w) {}
};

class Assignment : public Assessment {
public:
    Assignment(double raw, double max, double w) : Assessment("Assignment", raw, max, w) {}
};

#endif