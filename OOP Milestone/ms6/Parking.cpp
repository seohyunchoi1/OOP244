/* Citation and Sources...
Final Project Milestone 6
Module: Parking
Filename: Parking.cpp
Version 1.0
Name	Seohyun Choi
StuID	169181187
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iomanip>
#include <iostream>
#include "Parking.h"

namespace sdds {

	int Parking::assignedVehicle(Vehicle* vehicle) {

		if (vehicle == nullptr || numOfPV >= numOfSpots) {

			return 0;
		}

		for (int i = 0; i < numOfSpots; i++) {

			if (parkingSpots[i] == nullptr) {

				parkingSpots[i] = vehicle;

				vehicle->setParkingSpot(i + 1);

				invalidNumOfPV(numOfPV + 1);

				return i + 1;
			}
		}
		return 0;
	}

	void Parking::clear() {

		m_filename = nullptr;
	}


	bool Parking::isEmpty() {

		return m_filename == nullptr;
	}

	void Parking::parkingStatus() {

		cout << "****** Seneca Valet Parking ******" << endl;
		cout << "*****  Available spots: " << numOfSpots - numOfPV << "    *****" << endl;

	}

	void Parking::parkVehicle() {

		if (numOfPV >= numOfSpots) {

			cout << "Parking is full" << endl;

			return;
		}

		int menu = m_vehicleMenu.run();

		Vehicle* vehicle;

		switch (menu) {

		case 1: {

			cout << "Parking Car";

			vehicle = new Car();
			vehicle->setCsv(false);
			vehicle->read(cin);

			if (assignedVehicle(vehicle) == 0) {

				cout << "Parking is Full" << endl;
			}
			else {

				cout << "Parking Ticket:" << vehicle->getParkingSpot() << endl;

				vehicle->carOfMotor();
			}
			break;
		}

		case 2: {

			cout << "Parking Motorcycle";

			vehicle = new Motorcycle();
			vehicle->setCsv(false);
			vehicle->read(cin);

			if (assignedVehicle(vehicle) == 0) {

				cout << "Parking is Full" << endl;
			}

			else {

				cout << "Parking Ticket:" << vehicle->getParkingSpot() << endl;

				vehicle->carOfMotor();
			}
			break;

		}
		default: {

			cout << "Cancelled parking";
		}
			   cout << endl;
		}
	}

	void Parking::returnVehicle() {

		cout << "Returning Vehicle" << endl;

		char LPN[100];

		cout << "Enter Licence Plate Number: ";
		cin >> LPN;

		while (strlen(LPN) > 8 || strlen(LPN) < 1) {

			cout << "Invalid Licence Plate, try again: ";
			cin >> LPN;
		};

		for (int i = 0; i < numOfSpots; i++) {

			if (parkingSpots[i] != nullptr && (*parkingSpots[i]) == LPN) {

				cout << "Returning: " << endl;

				parkingSpots[i]->carOfMotor();
				delete parkingSpots[i];
				parkingSpots[i] = nullptr;

				invalidNumOfPV(numOfPV - 1);

				return;
			}
		}
		cout << "License Plate " << LPN << " not found." << endl;
	}


	void Parking::listParkedVehicles() {

		cout << "*** List of parked vehicles ***" << endl;

		for (int i = 0; i < returnNumOfSpots(); i++) {

			if (parkingSpots[i] != nullptr) {

				parkingSpots[i]->carOfMotor();

				cout << "-------------------------------" << endl;
			}
		}
	}

	bool Parking::closeParking() {

		cout << "Closing Parking" << endl;

		if (numOfPV == 0) {

			return true;
		}

		cout << "This will Remove and tow all remaining Vehicles from the Parking! " << endl;
		cout << "Are you sure? (Y)es / (N)o: ";

		bool status;
		char yn;

		do {

			status = false;
			cin >> yn;

			if (cin.fail()) {

				cin.clear();
				cin.ignore(2000, '\n');
				status = true;
			}

			if (!status && yn != 'y' && yn != 'Y' && yn != 'n' && yn != 'N') {

				status = true;
			}

			if (!status && cin.get() != '\n') {

				status = true;
				cin.ignore(2000, '\n');
			}

			if (status) {

				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
			}

		} while (status);

		if (yn == 'N' || yn == 'n') {

			return false;
		}

		if (yn == 'Y' || yn == 'y') {

			cout << "Closing Parking" << endl;

			for (int i = 0; i < numOfSpots; i++) {

				if (parkingSpots[i] != nullptr) {

					cout << "Towing Request: " << endl;
					cout << "*****************************" << endl;

					parkingSpots[i]->carOfMotor();

					cout << endl;

					delete parkingSpots[i];
					parkingSpots[i] = nullptr;

					invalidNumOfPV(numOfPV - 1);
				}
			}
			return true;
		}
		return true;
	}

	bool Parking::exitParkingApp() {

		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";

		char yn;
		do {

			cin >> yn;

			if (cin.get() != '\n') {

				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				cin.ignore(2000, '\n');
				yn = '\0';
			}
		} while (yn != 'y' && yn != 'Y' && yn != 'n' && yn != 'N');

		return yn == 'y' || yn == 'Y';
	}

	bool Parking::loadData() {

		if (!isEmpty()) {

			char getFile;

			ifstream file(m_filename);
			Vehicle* vehicle;

			while (file.get(getFile)) {

				file.get();

				switch (tolower(getFile)) {

				case 'c':

					vehicle = new Car();
					vehicle->setCsv(true);
					vehicle->read(file);

					if (assignedVehicle(vehicle) == 0)
						cout << "Parking is Full" << endl;
					break;

				case 'm':

					vehicle = new Motorcycle();
					vehicle->setCsv(true);
					vehicle->read(file);

					if (assignedVehicle(vehicle) == 0)

						cout << "Parking is Full" << endl;

					break;

				default:

					file.ignore(2000, '\n');
					break;
				}
			}

			file.close();
			return true;
		}
		return false;
	}

	void Parking::saveData() {

		if (!isEmpty()) {

			ofstream file(m_filename);

			for (int i = 0; i < numOfSpots; i++) {

				if (parkingSpots[i] != nullptr) {

					int typeValue = parkingSpots[i]->returnVehicleType();

					if (typeValue == 0) {

						parkingSpots[i]->setCsv(true);
						parkingSpots[i]->write(file);
					}

					if (typeValue == 1) {

						parkingSpots[i]->setCsv(true);
						parkingSpots[i]->write(file);
					}
				}
			}
			file.close();
		}
	}


	void Parking::mainMenu() {

		m_parkingMenu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Close Parking (End of day)" << "Exit Program";
		m_vehicleMenu << "Car" << "Motorcycle" << "Cancel";
	}

	Parking::Parking(const char* filename) : m_parkingMenu("Parking Menu, select an action:"), m_vehicleMenu("Select type of the vehicle:", 1) {

		if (filename != nullptr && filename[0] != '\0') {

			m_filename = new char[strlen(filename) + 1];
			strcpy(m_filename, filename);
			invalidNumOfSpots(MAX_NUM_OF_PARKING_SPOTS);

			for (int i = 0; i < MAX_NUM_OF_PARKING_SPOTS; i++) {

				parkingSpots[i] = nullptr;
			}

			if (loadData()) {

				mainMenu();
			}

			else {

				cout << "Error in data file" << endl;

				clear();
			}
		}

		else {

			cout << "Error in data file" << endl;

			clear();
		}
	}

	Parking::~Parking() {

		saveData();
		delete[] m_filename;
	}

	Parking::Parking(const char* datafile, int noOfSpots) : m_parkingMenu("Parking Menu, select an action:"), m_vehicleMenu("Select type of the vehicle:", 1) {

		if (datafile != nullptr && datafile[0] != '\0') {

			m_filename = new char[strlen(datafile) + 1];
			strcpy(m_filename, datafile);

			if (noOfSpots < 10 || noOfSpots > MAX_NUM_OF_PARKING_SPOTS) {

				cout << "Invalid number of parking slots." << endl;

				clear();
			}

			else {

				invalidNumOfSpots(noOfSpots);

				for (int i = 0; i < noOfSpots; i++) {

					parkingSpots[i] = nullptr;
				}

				invalidNumOfPV(0);

				if (loadData()) {

					mainMenu();
				}

				else {

					cout << "Error in data file" << endl;

					clear();
				}
			}
		}
		else {

			cout << "Error in data file" << endl;

			clear();
		}
	}

	int Parking::run() {

		if (!isEmpty()) {

			bool endProgram;

			do {
				endProgram = false;
				parkingStatus();

				int menu = m_parkingMenu.run();

				switch (menu) {

				case 1: {

					parkVehicle();
					break;
				}

				case 2: {

					returnVehicle();
					break;
				}

				case 3: {

					listParkedVehicles();
					break;
				}

				case 4: {

					if (closeParking()) {
						endProgram = true;
					}

					break;
				}

				case 5: {

					if (exitParkingApp()) {

						endProgram = true;
						cout << "Exiting program!" << endl;
					}
					break;
				}
				}
			} while (!endProgram);

			return 1;
		}

		return 0;
	}

	int Parking::returnNumOfSpots() {

		return numOfSpots;
	}

	int Parking::invalidNumOfSpots(int setNOS) {

		if (setNOS < 10 || setNOS > MAX_NUM_OF_PARKING_SPOTS) {

			cout << "Invalid number of spots" << endl;
			return -1;
		}

		numOfSpots = setNOS;
		return numOfSpots;
	}

	int Parking::returnNumOfPV() {

		return numOfPV;
	}

	int Parking::invalidNumOfPV(int setPV) {

		numOfPV = setPV;
		return numOfPV;
	}
}