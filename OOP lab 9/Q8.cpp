#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    virtual double getTuition(const string& status, int creditHours) const = 0;
    virtual ~Student() {}
};

class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    void setResearchTopic(const string& topic) {
        researchTopic = topic;
    }

    string getResearchTopic() const {
        return researchTopic;
    }

    double getTuition(const string& status, int creditHours) const override {
        if (status == "undergraduate") {
            return creditHours * 200;
        } else if (status == "graduate") {
            return creditHours * 300;
        } else if (status == "doctoral") {
            return creditHours * 400;
        } else {
            return 0.0;
        }
    }
};

int main() {
    GraduateStudent gs;
    gs.setResearchTopic("Artificial Intelligence");

    string status = "graduate";
    int creditHours = 9;

    cout << "Research Topic: " << gs.getResearchTopic() << endl;
    cout << "Tuition for " << creditHours << " credit hours as a " << status << " student: $"
         << gs.getTuition(status, creditHours) << endl;

    return 0;
}

