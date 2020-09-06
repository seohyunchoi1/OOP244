/* Citation and Sources...
Final Project Milestone 6
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
#include <ctype.h>

#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Menu.h"

using namespace std;

namespace sdds {

	const int	MAX_NUM_OF_PARKING_SPOTS = 100;

	class Parking {

		char*	 m_filename;
		Menu 	 m_parkingMenu;
		Menu	 m_vehicleMenu;

		int		 numOfSpots;
		Vehicle* parkingSpots[MAX_NUM_OF_PARKING_SPOTS];
		int		 numOfPV;
		int		 assignedVehicle(Vehicle* vehicle);


		void	 clear();

		bool	 isEmpty();
		void	 parkingStatus();
		void	 parkVehicle();
		void	 returnVehicle();
		void	 listParkedVehicles();
		bool	 closeParking();
		bool	 exitParkingApp();
		bool	 loadData();
		void	 saveData();

		void	 mainMenu();

	public:

		Parking(const char* filename);
		~Parking();
		Parking(const char* datafile, int noOfSpots);
		
		int		run();

		int		returnNumOfSpots();
		int		invalidNumOfSpots(int setNOS);

		int		returnNumOfPV();
		int		invalidNumOfPV(int setPV);
	};
}
#endif