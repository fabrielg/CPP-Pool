#include <iostream>
#include "Point.hpp"

bool	bsp(Point const A, Point const B, Point const C, Point const P);

int	main(void)
{
	Point	A(0.0f, 0.0f);
	Point	B(5.0f, 0.0f);
	Point	C(2.5f, 5.0f);

	Point	P_inside(2.5f, 2.0f);
	Point	P_edge(2.5f, 0.0f);
	Point	P_outside(5.0f, 5.0f);
	Point	P_vertex(0.0f, 0.0f);

	std::cout << "Triangle ABC: \n";
    std::cout << "A" << A;
    std::cout << "B" << B;
    std::cout << "C" << C << std::endl;

    std::cout << "P_inside: " << bsp(A, B, C, P_inside) << std::endl;
    std::cout << "P_edge: " << bsp(A, B, C, P_edge) << std::endl;
    std::cout << "P_outside: " << bsp(A, B, C, P_outside) << std::endl;
    std::cout << "P_vertex: " << bsp(A, B, C, P_vertex) << std::endl;

	return 0;
}