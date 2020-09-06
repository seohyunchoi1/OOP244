/*	Name: Seohyun Choi
	StuID: 169181187
	The work I've done for the OOP244 (C++ Programming) course at Seneca under the Computer Programming & Analysis (CPA) program */

#ifndef SDDS_ENGINE_H
#define SDDS_ENGINE_H

namespace sdds {

	const int	TYPE_MAX_SIZE = 30;

	class Engine {

		double	m_size;
		char	m_type[TYPE_MAX_SIZE + 1];

	public:
		Engine();
		Engine(const char* type, double size);
		double	get() const;
		void	display() const;

	private:
		void	set(const char* type, double size);
	};
}
#endif
