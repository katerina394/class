#ifndef _MATRIX_H
#define _MATRIX_H
class DMatrix
{
private:
	size_t Nstlb;
	size_t Nstr;
public:
	int **Matr;
	DMatrix(void);
	DMatrix(size_t nstlb, size_t nstr);
	~DMatrix(void);
	void ChangeNstlb(size_t n);
	void ChangeNstr(size_t n);
	void Print(size_t nstlb, size_t nstr);
	void PrintAll();
};

#endif