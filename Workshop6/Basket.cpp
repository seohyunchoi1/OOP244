/*	Name: Seohyun Choi
	StuID: 169181187
	The work I've done for the OOP244 (C++ Programming) course at Seneca under the Computer Programming & Analysis (CPA) program */

#include <iomanip>
#include <cstring>

#include "Basket.h"

using namespace std;
namespace sdds {

	ostream& Basket::display(ostream& ost) const {

		if (*this) {

			ost << "Basket Content:" << endl;

			for (int i = 0; i < m_cnt; i++) {

				ost << setw(10) << right << m_fruits[i].m_name << ": " << setprecision(2) << fixed << m_fruits[i].m_qty << "kg" << endl;
			}

			ost << "Price: " << setprecision(2) << fixed << m_price << endl;
		}

		else {

			cout << "The basket is empty!" << endl;
		}

		return ost;
	}

	Basket::Basket() {

		m_fruits = nullptr;
		m_cnt = 0;
		m_price = 0.0;
	}

	Basket::Basket(const Fruit* fruits, int cnt, double price) {

		if (fruits != nullptr && cnt != 0 && price != 0.0) {
			
			m_cnt = cnt;
			m_fruits = new Fruit[m_cnt];

			for (int i = 0; i < m_cnt; i++){

				m_fruits[i] = fruits[i];
			}

			m_price = price;
		}
		
		else {

			m_fruits = nullptr;
			m_cnt = 0;
			m_price = 0.0;
		}
	}

	Basket::Basket(const Basket& bsk) {

		m_fruits = nullptr;
		m_cnt = 0;
		m_price = 0.0;
		*this = bsk;
	}

	Basket& Basket::operator=(const Basket& bsk) {

		if (this != &bsk) {

			delete[] m_fruits;
			m_cnt = bsk.m_cnt;
			m_fruits = new Fruit[bsk.m_cnt];

			for (int i = 0; i < m_cnt; i++) {

				m_fruits[i] = bsk.m_fruits[i];
			}
			
			m_price = bsk.m_price;
		}

		return *this;
	}

	Basket::~Basket() {

		delete[] m_fruits;
	}


	void Basket::setPrice(double price) {

		m_price = price;
	}

	Basket::operator bool() const {

		return m_cnt != 0 && m_fruits != nullptr;
	}

	Basket& Basket::operator+=(const Fruit& fruit) {

		Fruit* temp = new Fruit[m_cnt + 1];

		for (int i = 0; i < m_cnt; i++) {

			temp[i] = m_fruits[i];
		}

		delete[] m_fruits;
		m_fruits = temp;
		temp = nullptr;

		m_fruits[m_cnt++] = fruit;
		return *this;
	}

	ostream& operator<<(ostream& ost, const Basket& bsk) {

		return bsk.display(ost);
	}
}