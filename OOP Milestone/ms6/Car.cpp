/* Citation and Sources...
Final Project Milestone 5
Module: Car
Filename: Car.cpp
Version 1.0
Name	Seohyun Choi
StuID	169181187
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <string>
#include <iostream>
#include <fstream>

#include "Car.h"

namespace sdds {

	bool Car::invalid(istream& istream) {

		bool status;
		char yn;

		do {
			status = false;

			istream >> yn;

			if (istream.fail()) {

				istream.clear();

				istream.ignore(1000, '\n');

				status = true;
			}

			if (!status && yn != 'Y' && yn != 'y' && yn != 'N' && yn != 'n') {

				status = true;
			}

			if (!status && istream.get() != '\n') {
				
				status = true;
				
				istream.ignore(1000, '\n');
			}

			if (status) {
				
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
			}
		} while (status);

		return yn == 'Y' || yn == 'y';
	}
	
	Car::Car() :Vehicle() {

		m_Carwashflag = false;
	}

	Car::Car(const char* Lisenseplate, const char* Makeandmodel) : Vehicle(Lisenseplate, Makeandmodel) {

		m_Carwashflag = false;
	}

	istream& Car::read(istream& istream) {

		if (isCsv()) {

			int i;

			Vehicle::read(istream);

			istream >> i;

			m_Carwashflag = i;

			istream.ignore(1000, '\n');
		}

		else {

			cout << "\n" << "Car information entry" << "\n";

			Vehicle::read(istream);

			cout << "Carwash while parked? (Y)es/(N)o: ";

			m_Carwashflag = invalid(istream);
		}

		return istream;
	}

	ostream& Car::write(ostream& ostream) const {

		if (isEmpty()) {

			ostream << "Invalid Car Object" << "\n";

		}

		else {

			if (isCsv()) {

				ostream << "C,";

			}

			else {

				ostream << "Vehicle type: Car" << "\n";

			}

			Vehicle::write(ostream);

			if (isCsv()) {

				ostream << m_Carwashflag << "\n";

			}

			else {

				if (m_Carwashflag) {

					cout << "With Carwash";

				}

				else {

					cout << "Without Carwash";

				}

				ostream << "\n";
			}
		}

		return ostream;
	}
}