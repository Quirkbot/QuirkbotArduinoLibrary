#ifndef VectorUpdatablesPointer_h_
#define VectorUpdatablesPointer_h_

#include "Arduino.h"


class Updatable;
class VectorUpdatablesPointer {
		typedef Updatable* Data;

		unsigned int d_size; // Stores no. of actually stored objects
		unsigned int d_capacity; // Stores allocated capacity
		Data *d_data; // Stores data

	public:

		VectorUpdatablesPointer(); // Default constructor
		VectorUpdatablesPointer(VectorUpdatablesPointer const &other); // Copy constuctor

		~VectorUpdatablesPointer(); // Destructor

		VectorUpdatablesPointer &operator=(VectorUpdatablesPointer const &other); // Needed for memory management

		void push(Data const &x); // Adds new value. If needed, allocates more space

		void pop(Data const &x); // Removes value by finding it's index and erasing it.

		void erase(unsigned int index); // Pops a value at an specific index. All other values will be moved

		void clear(); // Clears all the data from the vector

		unsigned int size() const; // Size getter

		Data const &operator[](unsigned int idx) const; // Const getter

		Data &operator[](unsigned int idx); // Changeable getter

	private:

		void resize();// Allocates double the old space
};

#endif
