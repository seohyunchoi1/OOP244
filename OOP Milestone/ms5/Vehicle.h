/* Citation and Sources...
Final Project Milestone 4
Module: Vehicle
Filename: Vehicle.h
Version 1.0
Name	Seohyun Choi
StuID	169181187
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H

#include <cstring>
#include <string>
#include <iostream>
#include <fstream>

#include "ReadWritable.h"

using namespace std;

namespace sdds {

	class Vehicle :
		
		public		ReadWritable {
		char		m_Licenseplate[9];
		char*		m_Makeandmodel;
		int			m_Parkingspotnumber;

		void		upper(char* upper) const;

	protected:

		void		setEmpty();
		bool		isEmpty() const;
		const char*	getLicensePlate() const;
		const char*	getMakeModel() const;
		void		setMakeModel(const char* value);

	public:

		int			getParkingSpot();
		void		setParkingSpot(const int value);

		bool		operator==(const char* value)const;
		bool		operator==(const Vehicle& rhs)const;

		virtual		istream& read(istream& istr);
		virtual		ostream& write(ostream& ostr) const;

		Vehicle(const char* Licenseplate, const char* Makeandmodel);
		Vehicle(const Vehicle& vehicle) = delete;
		Vehicle& operator=(const Vehicle& vehicle) = delete;

		Vehicle();
		~Vehicle();
	};
}
#endif