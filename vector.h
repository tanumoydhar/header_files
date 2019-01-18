#ifndef VECT_H //Include guard: In the C and C++ programming languages, an #include guard, sometimes called a macro guard or header guard, is a particular construct used to avoid the problem of double inclusion when dealing with the include directive.- Wikipedia
#define VECT_H

using namespace std;


template<typename T, int N>
struct vect
{
	public:


double operator()(int i) const 
{
	if(i>=0 && i<N)
	{return data[i];}

	else
	{cout<<'\t'<<"Index out of bounds"<<endl;}
}
double & operator()(int i) 
{
	if(i>=0 && i<N)
	{return data[i];}

	else
	{cout<<'\t'<<"Index out of bounds"<<endl;}
}	

	void clear();//clear function	
	void copyOther(const vect &other);//copy function
	
	vect(); //CONSTRUCTOR
	
	~vect(); //DESTRUCTOR
	
	vect(const vect &other) // Copy constructor
	{
		copyOther(other);
		
	}
	
	
	vect & operator =(const vect &other) // Assignment operator
	{	if(this != &other)
		{
			clear();
			copyOther(other);
		}
	return (*this);
	}



    friend ostream& operator<<  (ostream& os, vect<T,N> &myVect) //cout
    {	
	    for(int i=0; i<N; i++)
	    {
	    os<<myVect.data[i];
	    cout<<'\t';
	    }
	    cout<<'\n';	
	    return os;
		 
    }


    friend istream& operator>>  (istream& is, vect<T,N> &myVect) //cin
    {	
	    for(int i=0; i<N; i++)
	    {
	    is>>myVect.data[i];
	    }	
	    return is;
    }


private:
	T* data;// = NULL;

};


template<typename T, int N> 
void vect<T,N>::clear()//clear function
{
//    free(data);
	delete [] data;
	data = NULL;
}

template<typename T, int N> 
void vect<T,N>::copyOther(const vect &other)//copy function
{
			data = new T [N]; 
			for(int i=0;i<N;i++)
			{
				data[i]=other.data[i];
			}

}

template<typename T, int N> 
vect<T,N>::vect()  //CONSTRUCTOR
{
	data = new T [N]; 
	for(int i=0;i<N;i++)
	{
		data[i]=0.0;
	}
}

template<typename T, int N>
vect<T,N>::~vect() //DESTRUCTOR
{
//	clean up allocated memory
	clear();
}


/******************************************************************************/
template<int m>
struct metaDot 
{
	template<typename T, int N>
	static T f(vect<T,N>& a, vect<T,N>& b)
	{
	return a[m]*b[m] + metaDot<m-1>::f(a,b);
	}
};	

template<> // the end of the recursion
struct metaDot<0> 
{
	template<typename T, int N>
	static T f(vect<T,N>& a, vect<T,N>& b)
	{
	return a[0]*b[0];
	}
};


// The dot() function invokes metaDot
	template<typename T, int N>
	inline T dot(vect<T,N>& a, vect<T,N>& b)
	{
	return metaDot<N-1>::f(a,b);
	}
	
//*****************************************************************************/

	template<typename T, int N>
	vect<T,N> operator+(vect<T,N> &a, vect<T,N> &b)
	{
		vect<T,N> answer;
		int i;
		for(i=0;i<N;i++)
		{
			answer(i)=a(i)+b(i);
		}
	return answer;
	}

	template<typename T, int N>
	vect<T,N> operator-(vect<T,N> &a, vect<T,N> &b)
	{
		vect<T,N> answer;
		int i;
		for(i=0;i<N;i++)
		{
			answer(i)=a(i)-b(i);
		}
	return answer;
	}	
//*****************************************************************************//
#endif
