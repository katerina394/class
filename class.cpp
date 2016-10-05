// class.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "DMatrix.h"
#include "conio.h"
#include "iostream"
using namespace std;
void _tmain(int argc, _TCHAR* argv[])
{
	DMatrix A,B(4,3);
	cout<<"Matrix A"<<endl;
	A.PrintAll();
	cout<<"Matrix B"<<endl;
	B.PrintAll();
	cout<<"Submatrix of matrix A"<<endl;
	A.Print(2,2);
	A.ChangeNstlb(7);
	B.ChangeNstr(5);
	cout<<"Change a number of columns of the matrix A"<<endl;
	A.PrintAll();
	cout<<"Change a number of rows of the matrix B"<<endl;
	B.PrintAll();
	_getch();
}
