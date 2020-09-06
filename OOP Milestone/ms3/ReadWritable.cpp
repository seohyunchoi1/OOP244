/* Citation and Sources...
Final Project Milestone 3
Module: ReadWritable
Filename: ReadWritable.cpp
Version 1.0
Name	Seohyun Choi
StuID	169181187
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include <iostream>
#include <fstream>

#include "ReadWritable.h"

namespace sdds {
	
	ReadWritable::ReadWritable() {

		m_flag = false;
	}

	ReadWritable::~ReadWritable() {
	}


	bool ReadWritable::isCsv() const {

		return m_flag;
	}

	void ReadWritable::setCsv(bool value) {

		m_flag = value;
	}


	istream& operator>>(istream& istr, ReadWritable& ReadWritable) {

		return ReadWritable.read(istr);
	}

	ostream& operator<<(ostream& ostr, const ReadWritable& ReadWritable) {

		return ReadWritable.write(ostr);
	}
}