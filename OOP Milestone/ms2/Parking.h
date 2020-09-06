/* Citation and Sources...
Final Project Milestone 2
Module: Parking
Filename: Parking.h
Version 1.0
Name	Seohyun Choi
StuID	169181187
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H

#include <cstring>
#include <iomanip>
#include <iostream>

#include "Menu.h"

using namespace std;

namespace sdds {

	class Parking {

		char*	m_filename;
		Menu	m_parkingMenu;
		Menu	m_vehicleMenu;

		void	clear();

		bool	isEmpty();
		void	parkingStatus();
		void	parkVehicle();
		void	returnVehicle();
		void	listParkedVehicles();
		bool	closeParking();
		bool	exitParkingApp();
		bool	loadData();
		void	saveData();

		void	mainMenu();

	public:

		Parking(const char* filename);
		~Parking();

		int		run();
	};
}
#endif