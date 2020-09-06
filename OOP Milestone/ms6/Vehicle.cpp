/* Citation and Sources...
Final Project Milestone 6
Module: Vehicle
Filename: Vehicle.cpp
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

#include "Vehicle.h"

namespace sdds {

	//code auxiliary function
	void Vehicle::upper(char* upper) const {

		int letter = strlen(upper) + 1;

		for (int i = 0; i < letter; i++) {

			if (upper[i] >= 'a' && upper[i] <= 'z') {

				upper[i] = upper[i] - 32;
			}
		}
	}

	void Vehicle::setEmpty() {

		m_Licenseplate[0] = '\0';
		m_Makeandmodel = nullptr;
		m_Parkingspotnumber = 0;
	}

	bool Vehicle::isEmpty() const {

		return	m_Licenseplate[0] == '\0' &&
			m_Makeandmodel == nullptr &&
			m_Parkingspotnumber == 0;
	}

	//the main code.
	const char* Vehicle::getLicensePlate() const {

		return m_Licenseplate;
	}

	const char* Vehicle::getMakeModel() const {

		return m_Makeandmodel;
	}

	void Vehicle::setMakeModel(const char* size) {

		if (size != nullptr && size[0] != '\0') {

			delete[] m_Makeandmodel;
			m_Makeandmodel = new char[strlen(size) + 1];
			strcpy(m_Makeandmodel, size);
		}

		else {

			delete[] m_Makeandmodel;
			setEmpty();
		}
	}

	int	Vehicle::getParkingSpot() {

		return m_Parkingspotnumber;
	}

	void Vehicle::setParkingSpot(const int size) {

		m_Parkingspotnumber = size;

		if (size < 0) {

			delete[] m_Makeandmodel;
			setEmpty();
		}
	}

	bool Vehicle::operator== (const char* size) const {

		if (size != nullptr && size[0] != '\0') {

			char number[9];
			strncpy(number, size, 8);
			number[8] = '\0';
			upper(number);
			return strcmp(m_Licenseplate, number) == 0;
		}

		return false;
	}

	bool Vehicle::operator== (const Vehicle& vehicle) const {

		if (isEmpty() && vehicle.isEmpty()) {

			return false;
		}

		return strcmp(getLicensePlate(), vehicle.getLicensePlate()) == 0;
	}

	istream& Vehicle::read(istream& istream) {

		char value[100];

		if (isCsv()) {

			istream >> m_Parkingspotnumber;
			istream.get();
			istream.get(value, 9, ',');

			strcpy(m_Licenseplate, value);
			upper(m_Licenseplate);

			istream.get();
			istream.get(value, 100, ',');

			delete[] m_Makeandmodel;
			m_Makeandmodel = new char[strlen(value) + 1];
			strcpy(m_Makeandmodel, value);
			istream.get();
		}

		else {

			char temp[100];
			cout << "Enter Licence Plate Number: ";
			istream >> temp;

			while (strlen(temp) > 8) {
				cout << "Invalid Licence Plate, try again: ";
				istream >> temp;
			};
			upper(temp);

			strncpy(m_Licenseplate, temp, 8);
			m_Licenseplate[8] = '\0';

			istream.ignore();
			cout << "Enter Make and Model: ";
			istream.getline(temp, sizeof(temp));

			while (strlen(temp) < 2 || strlen(temp) > 60) {
				cout << "Invalid Make and model, try again: ";
				istream >> temp;
			}

			delete[] m_Makeandmodel;
			m_Makeandmodel = new char[strlen(temp) + 1];

			strcpy(m_Makeandmodel, temp);
			m_Parkingspotnumber = 0;
		}

		if (istream.fail()) {
			delete[] m_Makeandmodel;
			setEmpty();
		}
		return istream;
	}

	ostream& Vehicle::write(ostream& ostream) const {

		if (isEmpty()) {

			ostream << "Invalid Vehicle Object" << endl;
		}

		else {

			if (isCsv()) {

				ostream << m_Parkingspotnumber << "," << m_Licenseplate << "," << m_Makeandmodel << ",";

			}
			else {

				cout << "Parking Spot Number: ";

				if (m_Parkingspotnumber == 0) {

					cout << "N/A";
				}

				else {

					cout << m_Parkingspotnumber;
				}

				cout << endl;
				cout << "Licence Plate: " << m_Licenseplate << endl;
				cout << "Make and Model: " << m_Makeandmodel << endl;

			}
		}
		return ostream;
	}

	Vehicle::Vehicle() {

		setEmpty();
	}

	Vehicle::Vehicle(const char* Licenseplate, const char* Makeandmodel) {

		if (Licenseplate != nullptr && Licenseplate[0] != '\0' && Makeandmodel != nullptr && Makeandmodel[0] != '\0') {

			int lsize = strlen(Licenseplate), msize = strlen(Makeandmodel);

			if (lsize < 9 && msize > 1 && msize < 61) {

				strcpy(m_Licenseplate, Licenseplate);
				upper(m_Licenseplate);
				m_Makeandmodel = new char[strlen(Makeandmodel) + 1];

				strcpy(m_Makeandmodel, Makeandmodel);
				m_Parkingspotnumber = 0;
			}

			else {

				setEmpty();
			}
		}
		else {

			setEmpty();
		}
	}

	Vehicle::~Vehicle() {

		delete[] m_Makeandmodel;
	}

	void Vehicle::carOfMotor() {

		if (!isEmpty()) {

			if (vehicleType == 0) {

				cout << "Vehicle type: Car" << endl;
			}

			if (vehicleType == 1) {

				cout << "Vehicle type: Motorcycle" << endl;
			}

			cout << "Parking Spot Number: " << m_Parkingspotnumber << endl;
			cout << "License Plate: " << getLicensePlate() << endl;
			cout << "Make and Model: " << getMakeModel() << endl;
		}

		else {

			cout << "Invalid vehicle" << endl;
		}
	}

	int Vehicle::returnVehicleType() {

		return vehicleType;
	}
}
