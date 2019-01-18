#ifndef MATRIX3D_H //Include guard: In the C and C++ programming languages, an #include guard, sometimes called a macro guard or header guard, is a particular construct used to avoid the problem of double inclusion when dealing with the include directive.- Wikipedia
#define MATRIX3D_H
#include<iostream>
#include<stdlib.h>
#include "vector.h"

using namespace std;

//matrix3d class : 3D array

// for calling use matrix3d<double, no. of grids in x , no. of grids in y, no. of grids in z> U
// where U can be any scalar or vector field


/******************************************************************************************************************/
template <typename T, int row, int column, int depth>   //row by column by depth
class matrix3d
{
	public:
  

	
	T operator()(const int i, const int j, const int k) const 
	{
		if(i>=0 && i<row && j>=0 && j<column && k>=0 && k<depth)
			{return mat3[k*row*column + i*column + j];}

		else
			{cout<<'\t'<<"Index out of bounds"<<endl;}

	}
	
	T& operator()(const int i,const int j, const int k) 
	{
		if(i>=0 && i<row && j>=0 && j<column && k>=0 && k<depth)
			{return mat3[k*row*column + i*column + j];}

		else
			{cout<<'\t'<<"Index out of bounds"<<endl;}

	} 

	void clear(); //clear function
	void copyOther(const matrix3d &other);//copy function	
		
	matrix3d(); //CONSTRUCTOR	
	~matrix3d(); //DESTRUCTOR	

	matrix3d(const matrix3d &other) // Copy constructor
	{
	copyOther(other);
	}
	
	matrix3d & operator =(const matrix3d & other) // Assn. operator
	{	if(this != &other)
		{
			clear();
			copyOther(other);
		}
	return *this;
	}


private:	
	T *mat3 ;

};


template <typename T, int row, int column, int depth>
	void matrix3d<T,row,column,depth>::clear() //clear function
	{
	delete [] mat3;
	mat3 = NULL;
	}
	
template <typename T, int row, int column, int depth>
	void matrix3d<T,row,column,depth>::copyOther(const matrix3d &other)//copy function
	{
			mat3 = new T [row*column*depth]; 
			for(int i=0;i<row*column*depth;i++)
			{
				mat3[i]=other.mat3[i];
			}
	}
	
template <typename T, int row, int column, int depth>
	matrix3d<T,row,column,depth>::matrix3d() //CONSTRUCTOR
	{
		mat3 = new T [row*column*depth]; 
		for(int i=0;i<row*column*depth;i++)
		{mat3[i]= 0;}
	}

template <typename T, int row, int column, int depth>
	matrix3d<T,row,column,depth>::~matrix3d()//DESTRUCTOR
	{
//		clean up allocated memory
		if(mat3!=NULL)
		{clear();
		}
	}


template <typename T, int row, int column, int depth>
	std::ostream & operator<<  (std::ostream& os, matrix3d<T,row,column,depth> &mymatrix3d) //overloading output operator 
	{	
		int i,j,k;
		for(k=0;k<depth;k++)
		{
			std::cout<<'\n';
			for(i=0;i<row;i++)
			{	
				for(j=0;j<column;j++)
				{
				os<<mymatrix3d(i,j,k);
				std::cout<<'\t';
				}
				std::cout<<'\n';
			}
		}
	
	return os;
	}

template <typename T, int row, int column, int depth>
	std::istream & operator>>  (std::istream& is, matrix3d<T,row,column,depth> &mymatrix3d)//overloading input operator 
	{	
		int i,j,k;
		
		for(k=0;k<depth;k++)	
		{	for(i=0;i<row;i++)
			{	
				for(j=0;j<column;j++)
				{	
				is>>mymatrix3d(i,j,k);
				}
			std::cout<<'\n';	
			}
		}
	return is;
	}

	
template <typename T, int row, int column, int depth> 
	matrix3d<T,row,column,depth> operator+  ( matrix3d<T,row,column,depth> &a, matrix3d<T,row,column,depth> &b)//overloading + operator
	{
	int i,j,k;
	matrix3d<T,row,column,depth> answer;
		for(k=0;k<depth;k++)	
		{	
			for(i=0;i<row;i++)
			{	
				for(j=0;j<column;j++)
				{
				answer(i,j,k)=a(i,j,k)+b(i,j,k);
				}	
		
			}
		}	
	return answer;
	}

	
template <typename T, int row, int column, int depth>  
	matrix3d<T,row,column,depth> operator-  ( matrix3d<T,row,column,depth> &a, matrix3d<T,row,column,depth> &b)//overloading - operator 
	{
	int i,j,k;
	matrix3d<T,row,column,depth> answer;
		for(k=0;k<depth;k++)	
		{	
			for(i=0;i<row;i++)
			{	
				for(j=0;j<column;j++)
				{
				answer(i,j,k)=a(i,j,k)-b(i,j,k);
				}	
		
			}
		}	
	return answer;
	}

//overload * operator, multiplication by a scalar
	template <typename T, int row, int column, int depth>  
	matrix3d<T,row,column,depth> operator*  ( T a, matrix3d<T,row,column,depth> &b)//overloading * operator 
	{
	int i,j,k;
	matrix3d<T,row,column,depth> answer;
		for(k=0;k<depth;k++)	
		{	
			for(i=0;i<row;i++)
			{	
				for(j=0;j<column;j++)
				{
				answer(i,j,k)= a * b(i,j,k);
				}	
		
			}
		}	
	return answer;
	}


/******************************************************************************************************************/
/******************************************************************************************************************/
#endif
