/*	Name: Seohyun Choi
	StuID: 169181187
	The work I've done for the OOP244 (C++ Programming) course at Seneca under the Computer Programming & Analysis (CPA) program */

#ifndef SDDS_SHIP_H
#define SDDS_SHIP_H

#include "Engine.h"

namespace sdds {

	const int		NUM_OF_ENGINES = 10;
	const double	MIN_STD_POWER = 90.111;
	const double	MAX_STD_POWER = 99.999;


	class Ship {

		Engine* m_engines = nullptr;
		int m_engCnt;
		char* m_type;

	public:
		Ship();
		~Ship();
		Ship(const char* type, const Engine arr[], int size);
		operator bool() const;
		Ship& operator+=(Engine engine);
		bool		operator<(double power) const;
		double		calculatePower() const;
		void		display() const;
	};

	bool			operator<(double power, const Ship& theShip);
}
#endif