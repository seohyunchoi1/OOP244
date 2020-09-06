/* Citation and Sources...
Final Project Milestone 2
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

	void Parking::clear() {

		m_filename = nullptr;
	}


	bool Parking::isEmpty() {

		return m_filename == nullptr;
	}

	void Parking::parkingStatus() {

		cout << "****** Seneca Valet Parking ******" << endl;
	}

	void Parking::parkVehicle() {

		int menu = m_vehicleMenu.run();
		
		switch (menu) {

			case 1: {

				cout << "Parking Car";
				break;
			}
		
			case 2: {

				cout << "Parking Motorcycle";
				break;
			}

			default: {
			
			cout << "Cancelled parking";
			}
		}
		cout << endl;
	}

	void Parking::returnVehicle() {

		cout << "Returning Vehicle" << endl;
	}

	void Parking::listParkedVehicles() {

		cout << "Listing Parked Vehicles" << endl;
	}

	bool Parking::closeParking() {

		cout << "Closing Parking" << endl;
		return true;
	}

	bool Parking::exitParkingApp(){

		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";
		
		char yn;
		do {
			cin >> yn;
			
			if (cin.get() != '\n') {
				
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				cin.ignore(1000, '\n');
				yn = '\0';
			}
		} while (yn != 'y' && yn != 'Y' && yn != 'n' && yn != 'N');
		
		return yn == 'y' || yn == 'Y';
	}

	bool Parking::loadData() {

		if (!isEmpty()) {
			
			cout << "loading data from " << m_filename << endl;
			return true;
		}
		return false;
	}

	void Parking::saveData() {

		if (!isEmpty()) {
			
			cout << "Saving data into " << m_filename << endl;
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

	int Parking::run() {

		if (!isEmpty()) {
			
			bool endProgram;
			
			do {
				endProgram = false;
				parkingStatus();
				
				int select = m_parkingMenu.run();
				
				switch (select) {
				
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
}