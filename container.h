#ifndef CONT_H
#define CONT_H

#include <string.h>
#define BASIC_SIZE 5

template<typename T>
class container {

private:
	int el_count;
	int max;
	
	T* tab;


public:

	container(int a = BASIC_SIZE): max(a), el_count(0){
		tab = new T[a];
	}

	~container(){
		delete [] tab;
	}


	T& operator[](int i);
	void push_back(const T& element);
	T pop_back();

	inline int size(){
		return el_count;
	}

	

	class iterator{

		const container<T>& cont;
		T* current;

	public:

		iterator(const container<T>& c): cont(c),current(c.tab) {}

		iterator(iterator& it): cont(it.cont), current(it.current){} 

		iterator& operator++(){current++;return *this;}

		iterator operator++(int){
			iterator it(*this);
			++current;

			return it;
		}

		operator bool()const{return current < &cont.tab[cont.el_count];}

		T operator*(){return *current;}

	};
};


template<typename T>
void container<T>::push_back(const T& element){
	
	if (el_count ==  max){
	
		max += BASIC_SIZE;
		T* new_tab = new T [max];
		
		memmove( new_tab, tab, el_count*sizeof(T) );

		tab = new_tab;
	}

	tab[el_count++] = element;
}


template<typename T>
T container<T>::pop_back(){
	
	T tmp = tab[--el_count];
	tab[el_count] = NULL;
	
	return tmp;
}

template<typename T>
T& container<T>::operator[](int i){
	
	return tab[i];
}




// specjalizacja calkowita dla typu bool
template<>
class container<bool>{

private:
	int el_count;
	int max;
	int bool_index;
	
	char* tab;


public:

	container(int a = BASIC_SIZE): max(a), el_count(0), bool_index(0){
		tab = new char[a];
	}

	~container(){
		delete [] tab;
	}




	void push_back(const bool& element){
	
		if (el_count ==  max){
	
			max += BASIC_SIZE;
			char* new_tab = new char [max];
		
			memmove( new_tab, tab, el_count*sizeof(char) );

			tab = new_tab;
		}


		if (!bool_index) tab[el_count] = 0;



		tab[el_count] += (int(element) << (bool_index++));


		if (bool_index == 8){
			++el_count;
			bool_index = 0;
		}
	}





	bool operator[](int i) const {
		int el = i / 8;
		int bool_in = i % 8;

		return ( tab[el] >> bool_in) % 2 ;
	}




	

	bool pop_back(){
	
		bool b = (*this)[el_count + (bool_index--) ];

		
		if (bool_index == 0){

			tab[--el_count]=0;
			bool_index = 8;
		
		}


		else{
			
			tab[el_count] -= (b << (bool_index));

		}


		return b;
	}




	inline int size() const{
		return el_count;
	}

	
	
	class iterator{

			const container<bool>& cont;
			char* current;
			int i;

		public:

			iterator(const container<bool>& c): cont(c),current(c.tab), i(0) {}

			iterator(iterator& it): cont(it.cont), current(it.current), i(it.i){} 

			iterator&operator++(){
				if ((!(i+1)%8)) // jesli i jest podzielne przez 8 to idziemy do nastepnego el tablicy char
					++current;
				++i;
				return *this;}

			iterator operator++(int){
				iterator it(*this);
				if ((!(i+1)%8))
					++current;
				++i;

				return it;
			}

			operator bool()const{return current < &cont.tab[cont.el_count];}

			bool operator*(){return cont[i];}

	};
	
};



#endif