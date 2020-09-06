/* Citation and Sources...
Final Project Milestone 5
Module: Car
Filename: Car.h
Version 1.0
Name	Seohyun Choi
StuID	169181187
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <cstring>
#include <string>
#include <iostream>
#include <fstream>

#include "Vehicle.h"

using namespace std;

namespace sdds {

	class Car : public Vehicle {

		bool	m_Carwashflag;

	protected:

		bool	invalid(istream& istream);

	public:

		Car();
		Car		(const char* Lisenseplate, const char* Makeandmodel);

		Car&	operator=(const Car& car) = delete;

		virtual	istream& read(istream& istream);
		virtual	ostream& write(ostream& istream) const;
	};
}
#endif