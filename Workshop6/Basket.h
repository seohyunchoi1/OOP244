/*	Name: Seohyun Choi
	StuID: 169181187
	The work I've done for the OOP244 (C++ Programming) course at Seneca under the Computer Programming & Analysis (CPA) program */

#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H

#include <iostream>
#include <cstring>

using namespace std;
namespace sdds {

	struct Fruit {

		char m_name[30 + 1];
		double m_qty;
	};


	class Basket {

		Fruit*		m_fruits;
		int			m_cnt;
		double		m_price;
		ostream&	display(ostream& ost) const;

	public:
		Basket();
		Basket(const Fruit* fruits, int cnt, double price);
		Basket(const Basket& bsk);
		Basket& operator=(const Basket& bsk);
		~Basket();
		
		void setPrice(double price);
		operator bool() const;
		Basket& operator+=(const Fruit& fruit);
		friend ostream& operator<<(ostream& ost, const Basket& bsk);
	};

}
#endif