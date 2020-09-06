/*	Name: Seohyun Choi
	StuID: 169181187
	The work I've done for the OOP244 (C++ Programming) course at Seneca under the Computer Programming & Analysis (CPA) program */

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>

#include "Engine.h"

using namespace std;

namespace sdds {

	void Engine::set(const char* type, double size) {

		if (type != nullptr && type[0] != '\0' && size > 0) {

			int stlength = strlen(type);

			if (stlength < TYPE_MAX_SIZE) {

				strncpy(m_type, type, stlength);
				m_type[stlength] = '\0';
			}

			else {

				strncpy(m_type, type, TYPE_MAX_SIZE);
				m_type[TYPE_MAX_SIZE + 1] = '\0';
			}

			this->m_size = size;
		}

		else {

			m_size = 0;
			m_type[0] = '\0';
		}
	}

	Engine::Engine() {

		m_size = 0;
		m_type[0] = '\0';
	}

	Engine::Engine(const char* type, double size) {

		set(type, size);
	}

	double sdds::Engine::get() const {

		return m_size;
	}

	void sdds::Engine::display() const {

		if (m_size == 0 || m_type[0] == '\0') {

			cout << "No available data." << endl;
		}
		else {

			ostringstream streamObj3;
			
			streamObj3 << std::fixed;
		
			streamObj3 << std::setprecision(2);
			
			streamObj3 << m_size;
			
			string strObj3 = streamObj3.str();

			cout << strObj3 << " liters - " << m_type << endl;
		}
	}
}
