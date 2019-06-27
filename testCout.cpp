// testCout.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <boost/serialization/access.hpp>
#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

class A
{
private:
	//为了能让串行化类库能够访问私有成员，所以要声明一个友元类
	friend class boost::serialization::access;
	//对象的数据
	int a;
	double b;
	//串行化的函数，这一个函数完成对象的保存与恢复
	template <class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar & a; //就是这么简单，也可以使用 ar<<a 这样的语法
		ar & b;
	}

public:
	A(int aa, double bb): a(aa), b(bb)
	{
	}

	A()
	{
	}

	void print() { std::cout << a << ' ' << b << std::endl; }
};

int main()
{
	std::ofstream fout("file.txt"); //把对象写到file.txt文件中
	boost::archive::text_oarchive oa(fout); //文本的输出归档类，使用一个ostream来构造
	A obj(1, 2.5);
	oa << obj; //保存obj对象
	fout.close(); //关闭文件

	std::ifstream fin("file.txt");
	boost::archive::text_iarchive ia(fin); //文本的输入归档类
	A newobj;
	ia >> newobj; //恢复到newobj对象
	newobj.print();
	fin.close();
	system("pause");
	return 0;
}

// struct my_struct
// {
// 	// const char* a;
// 	// char b;
// 	// char c;
// 	int d;
//
// private:
// 	friend class boost::serialization::access;
//
// 	template <class Archive>
// 	void serialize(Archive& ar, const unsigned version)
// 	{
// 		// ar & a;
// 		// ar & b;
// 		// ar & c;
// 		ar & d;
// 	}
// };
//
// int main()
// {
// 	my_struct m_my_struct;
// 	memset(&m_my_struct, 0, sizeof(my_struct));
// 	m_my_struct.d = 333;
//
// 	std::ofstream ofs("filename");
//
// 	// save data to archive
// 	{
// 		boost::archive::text_oarchive oa(ofs);
// 		// write class instance to archive
// 		oa << m_my_struct;
// 		// archive and stream closed when destructors are called
// 	}
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
