#include "StdAfx.h"
#include "DMatrix.h"
#include "stdio.h"
#include "iostream"
#include "time.h"
using namespace std;

DMatrix::DMatrix(void)
{
	srand(time(NULL));
	Nstlb=5;
	Nstr=5;
	Matr=new int*[Nstr];
	for(int i=0; i<Nstr; i++)
	{
		Matr[i]=new int[Nstlb];
		for(int j=0; j<Nstlb; j++)
			Matr[i][j]=rand()%100;
	}
}

DMatrix::DMatrix(size_t nstlb, size_t nstr)
{
	srand(time(NULL));
	Nstlb=nstlb;
	Nstr=nstr;
	Matr=new int*[Nstr];
	for(int i=0; i<Nstr; i++)
	{
		Matr[i]=new int[Nstlb];
		for(int j=0; j<Nstlb; j++)
			Matr[i][j]=rand()%100;
	}
}

DMatrix::~DMatrix(void)
{
	for(int i=0; i<Nstr; i++)
		delete[]Matr[i];
	delete[]Matr;
	Nstlb=0;
	Nstr=0;
}

void DMatrix::ChangeNstlb(size_t n)
{
	if (n<Nstlb)
		Nstlb=n;
	else
	{
		for(int i=0; i<Nstr; i++)
		{
			Matr[i]=(int*)realloc(Matr[i],n*sizeof(int));
		    for(int j=Nstlb; j<n; j++)
				Matr[i][j]=0; 
		}
		Nstlb=n;
	}
}
void DMatrix::ChangeNstr(size_t n)
{
	if (n<Nstr)
	{
		for(int i=n; i<Nstr; i++)
			delete[]Matr[i];
		Nstr=n;
	}
	else
	{
		Matr=(int**)realloc(Matr,n*sizeof(int*));
		for(int i=Nstr; i<n; i++)
		{
			Matr[i]=new int[Nstlb];
			for(int j=0; j<Nstlb; j++)
				Matr[i][j]=0;
		}
		Nstr=n;
	}
}
void DMatrix::Print(size_t nstlb, size_t nstr)
{
	for(int i=0; i<nstr; i++)
	{
		for (int j=0; j<nstlb; j++)
			printf("%3d",Matr[i][j]);			
		cout<<endl;
	}
}
void DMatrix::PrintAll()
{
	for(int i=0; i<Nstr; i++)
	{
		for (int j=0; j<Nstlb; j++)
			printf("%3d",Matr[i][j]);
		cout<<endl;
	}
}
