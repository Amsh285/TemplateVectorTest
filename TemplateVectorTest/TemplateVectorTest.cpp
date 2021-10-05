// TemplateVectorTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "VectorN.h"
#include "MatrixN.h"

int main()
{
	VectorN<float, 3> v1({ 1.0f, 1.0f, 1.0f });
	VectorN<float, 3> v2({ 1.0f, 1.0f, 0.0f });

	std::cout << "VectorAddition:" << std::endl;
	std::cout << v1 << std::endl;
	std::cout << v1 << std::endl;
	std::cout << v1 + v2 << std::endl;

	std::cout << "scalar multiplication:" << std::endl;
	std::cout << -1.0f << " * " << v1 << " = " << -1.0f * v1 << std::endl;
	std::cout << v1 << " unchanged" << std::endl;

	std::cout << "Dot Product:" << std::endl;
	std::cout << v1 << " * " << v2 << " = " << v1 * v2 << std::endl;
	std::cout << "Orthogonal :O " << VectorN<float, 3>({ 1.0f, 0.0f, 0.0f }) * VectorN<float, 3>({ 0.0f, 1.0f, 0.0f }) << std::endl;

	MatrixN<float, 3, 3> m1({ { 10.0f, 1.0f, 1.0f },
							{ 2.0f, 1.0f, 1.0f },
							{ 3.0f, 1.0f, 1.0f } });

	MatrixN<float, 3, 3> m2({ {1.0f, 0.0f, 0.0f},
							{0.0f, 1.0f, 0.0f},
							{0.0f, 0.0f, 1.0f} });

	std::cout << "Matrix Multiplication" << std::endl;
	std::cout << "m1 * v1 = " << m1 * v1 << std::endl;

	MatrixN<float, 3, 3> m3 = m1 * m2;

	try
	{
		v2[5];
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
