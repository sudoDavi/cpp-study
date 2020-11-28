#include <cstdint>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

// Foward declaration to comply with the circular dependency
class Patient;

class Doctor {
private:
	std::string m_name{};
	std::vector<std::reference_wrapper<const Patient>> m_patients{};
public:
	Doctor(const std::string& name) : m_name{name} {}

	// Foward declarations since the functions will need to know what the patient class has
	void addPatient(Patient& patient);

	friend std::ostream& operator<<(std::ostream& out, const Doctor& doctor);

	const std::string& getName() const { return m_name; }
};

class Patient {
private:
	std::string m_name{};
	std::vector<std::reference_wrapper<const Doctor>> m_doctors{};

	void addDoctor(const Doctor& doctor) {
		m_doctors.push_back(doctor);
	}

public:
	Patient(const std::string& name) : m_name{name} {}

	const std::string& getName() const { return m_name; }

	friend std::ostream& operator<<(std::ostream& out, const Patient& patient) {
		if (patient.m_doctors.empty()) {
			out << patient.getName() << " has no doctors right now";
			return out;
		}

		out << patient.getName() << " is seeing doctors: ";
		for (const auto& doctor : patient.m_doctors)
			out << doctor.get().getName() << ' ';

		return out;
	}

	friend void Doctor::addPatient(Patient& patient);
};

void Doctor::addPatient(Patient& patient) {
	m_patients.push_back(patient);

	patient.addDoctor(*this);
}

std::ostream& operator<<(std::ostream& out, const Doctor& doctor) {
	if (doctor.m_patients.empty()) {
		out << doctor.m_name << " has no patients right now";
		return out;
	}

	out << doctor.m_name << " is seeing patients: ";
	for (const auto& patient : doctor.m_patients)
		out << patient.get().getName() << ' ' ;

	return out;
}

int main() {
	Patient dave{ "Dave" };
	Patient frank{ "Frank" };
	Patient betsy{ "Betsy" };

	Doctor james{ "James" };
	Doctor scott{ "Scott" };

	james.addPatient(dave);

	scott.addPatient(dave);
	scott.addPatient(betsy);

	std::cout << james << '\n';
	std::cout << scott << '\n';
	std::cout << dave << '\n';
	std::cout << frank << '\n';
	std::cout << betsy << '\n';

	return 0;
}
