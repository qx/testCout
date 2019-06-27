// // testCout.cpp : This file contains the 'main' function. Program execution begins and ends there.
// //
//
// #include <iostream>
// #include <ostream>
// #include <vector>
//
// template <typename T>
// std::ostream& operator<<(std::ostream& s, std::vector<T> t)
// {
// 	s << "[";
// 	for (std::size_t i = 0; i < t.size(); i++)
// 	{
// 		s << t[i] << (i == t.size() - 1 ? "" : ",");
// 	}
// 	return s << "]" << std::endl;
// }
//
// struct inner_stuct
// {
// 	int inn;
//
//
// 	friend std::ostream& operator<<(std::ostream& os, const inner_stuct& obj)
// 	{
// 		return os << "inn: " << obj.inn;
// 	}
// };
//
// struct my_struct
// {
// 	char a;
// 	char b;
// 	char c;
// 	int d;
// 	std::vector<inner_stuct> inner_stucts;
//
// 	friend std::ostream& operator<<(std::ostream& os, const my_struct& obj)
// 	{
// 		return os
// 			<< "a: " << obj.a
// 			<< " b: " << obj.b
// 			<< " c: " << obj.c
// 			<< " d: " << obj.d
// 			<< " inner_stucts: " << obj.inner_stucts;
// 	}
// };
//
// int main()
// {
// 	std::vector<my_struct> my_structs;
// 	for (int i = 0; i < 3; ++i)
// 	{
// 		my_struct m_my_struct;
// 		std::vector<inner_stuct> inner_stucts;
// 		for (int i = 0; i < 4; ++i)
// 		{
// 			inner_stuct m_inner_struct;
// 			memset(&m_inner_struct, 0, sizeof(inner_stuct));
// 			m_inner_struct.inn = i;
// 			inner_stucts.push_back(m_inner_struct);
// 		}
// 		memset(&m_my_struct, 0, sizeof(my_struct));
// 		m_my_struct.a = 'x\0';
// 		m_my_struct.b = 'bbb';
// 		m_my_struct.inner_stucts = inner_stucts;
// 		my_structs.push_back(m_my_struct);
// 	}
// 	std::cout << my_structs << std::endl;
// }
//
// // Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// // Debug program: F5 or Debug > Start Debugging menu
//
// // Tips for Getting Started: 
// //   1. Use the Solution Explorer window to add/manage files
// //   2. Use the Team Explorer window to connect to source control
// //   3. Use the Output window to see build output and other messages
// //   4. Use the Error List window to view errors
// //   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
// //   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
