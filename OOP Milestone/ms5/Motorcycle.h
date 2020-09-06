/* Citation and Sources...
Final Project Milestone 5
Module: Motorcycle
Filename: Motorcycle.h
Version 1.0
Name	Seohyun Choi
StuID	169181187
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_MOTORCYCLE_H
#define SDDS_MOTORCYCLE_H

#include <cstring>
#include <string>
#include <iostream>
#include <fstream>

#include "Vehicle.h"

using namespace std;

namespace sdds {

	class Motorcycle :

		public	Vehicle {
		
		bool	m_HasSidecarflag;
	
	protected:
	
		bool	invalid(istream& istream);
	
	public:

		Motorcycle();
		Motorcycle(const char* Lisenseplate, const char* Makeandmodel);

		Motorcycle& operator=(const Motorcycle& motorcycle) = delete;
		
		virtual	istream& read(istream& istream);
		virtual	ostream& write(ostream& ostream) const;
	};
}
#endif