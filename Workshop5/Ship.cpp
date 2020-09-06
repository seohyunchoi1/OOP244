/*	Name: Seohyun Choi
	StuID: 169181187
	The work I've done for the OOP244 (C++ Programming) course at Seneca under the Computer Programming & Analysis (CPA) program */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <sstream>
#include <iomanip>

#include "Ship.h"

using namespace std;

namespace sdds {

	Ship::Ship() {

		m_type = new char[1];

		m_type[0] = '\0';

		m_engCnt = 0;
	}

	Ship::~Ship() {

		delete[] m_type;

		if (m_engines != nullptr) {

			delete[] m_engines;
		}
	}

	Ship::Ship(const char* type, const Engine arr[], int size) {

		if (type != nullptr && arr != nullptr && size > 0) {

			int stlength = strlen(type);

			m_engCnt = size;

			m_type = new char [stlength + 1];
			
			strncpy(m_type, type, stlength);
			
			m_type[stlength] = '\0';
			
			m_engines = new Engine [m_engCnt];
			
			for (int i = 0; i < size; i++) {

				m_engines[i] = arr[i];
			}
		}

		else {

			m_type = new char[1];

			m_type[0] = '\0';

			m_engCnt = 0;
		}
	}

	Ship::operator bool() const {

		if (m_engCnt == 0 || m_type[0] == '\0') {

			return false;
		}

		else {

			return true;
		}
	}

	Ship& Ship::operator+=(Engine engine) {

		if (!*this) {

			cout << "The object is not valid! Engine cannot be added!" << endl;
			return *this;
		}


		Engine* temp = new Engine[this->m_engCnt + 1];

		for (int i = 0; i < this->m_engCnt; i++) {

			temp[i] = m_engines[i];
		}

		temp[m_engCnt] = engine;

		this->m_engCnt++;

		delete[] m_engines;

		m_engines = temp;

		return *this;
	}

	double Ship::calculatePower() const {
		
		double i = 0;

		for (int l = 0; l < m_engCnt; l++) {

			i += (this->m_engines[l].get() * 5);
		}
		return i;
	}

	bool Ship::operator<(double power) const {

		return this->calculatePower() < power;
	}

	void Ship::display() const {

		if (*this) {
			ostringstream streamObj3;

			streamObj3 << std::fixed;

			streamObj3 << std::setprecision(2);

			streamObj3 << calculatePower();

			string strObj3 = streamObj3.str();

			while (strObj3.length() < 6) {

				strObj3 = " " + strObj3;
			}

			cout << m_type << " - " << strObj3 << endl;
			
			
			for (int i = 0; i < this->m_engCnt; i++) {

				this->m_engines[i].display();
			}
		}

		else {

			cout << "No available data" << endl;
		}
	}

	bool operator<(double power, const Ship& theShip) {

		return false;

		return power < theShip.calculatePower();
	}
}
