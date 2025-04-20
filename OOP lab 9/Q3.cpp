#include <iostream>
#include <string>
#include <vector>

class PatientRecord {
private:
    std::string name;
    std::string patientID;
    std::string dob;
    std::string medicalHistory;
    std::string currentTreatment;
    std::string billingInfo;

public:
    PatientRecord(const std::string& n, const std::string& id, const std::string& date)
        : name(n), patientID(id), dob(date), medicalHistory(""), currentTreatment(""), billingInfo("") {}

    std::string getPublicData() const {
        return "Name: " + name + ", ID: " + patientID + ", DOB: " + dob;
    }

private:
    void updateMedicalHistory(const std::string& history) {
        medicalHistory = history;
    }

    void updateTreatment(const std::string& treatment) {
        currentTreatment = treatment;
    }

    std::string getMedicalData() const {
        return "Medical History: " + medicalHistory + ", Current Treatment: " + currentTreatment;
    }

    void addBillingDetails(const std::string& bill) {
        billingInfo = bill;
    }

    std::string getBillingInfo() const {
        return billingInfo;
    }

    friend class Doctor;
    friend class Billing;
};

class Doctor {
public:
    void updateMedical(PatientRecord& record, const std::string& history, const std::string& treatment) {
        record.updateMedicalHistory(history);
        record.updateTreatment(treatment);
    }

    void viewMedical(const PatientRecord& record) {
        std::cout << record.getMedicalData() << std::endl;
    }
};

class Billing {
public:
    void addBilling(PatientRecord& record, const std::string& bill) {
        record.addBillingDetails(bill);
    }

    void viewBilling(const PatientRecord& record) {
        std::cout << "Billing Info: " << record.getBillingInfo() << std::endl;
    }
};

class Receptionist {
public:
    void viewPublic(const PatientRecord& record) {
        std::cout << record.getPublicData() << std::endl;
    }

    void tryToAccessMedical(const PatientRecord& record) {
        // std::cout << record.getMedicalData(); // illegal
        std::cout << "Access Denied: Cannot view medical data." << std::endl;
    }

    void tryToAccessBilling(const PatientRecord& record) {
        // std::cout << record.getBillingInfo(); // illegal
        std::cout << "Access Denied: Cannot view billing data." << std::endl;
    }
};

int main() {
    PatientRecord patient("John Doe", "P12345", "1990-01-01");

    Doctor doc;
    doc.updateMedical(patient, "Diabetes Type 2", "Metformin 500mg");
    doc.viewMedical(patient);

    Billing billingStaff;
    billingStaff.addBilling(patient, "Total: $1200 - Paid");
    billingStaff.viewBilling(patient);

    Receptionist rec;
    rec.viewPublic(patient);
    rec.tryToAccessMedical(patient);
    rec.tryToAccessBilling(patient);

    return 0;
}

