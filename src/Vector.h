#ifndef Vector_h_
#define Vector_h_

#include "Arduino.h"

// Minimal class to replace std::vector
template<typename Data>
class Vector {
	unsigned int d_size; // Stores no. of actually stored objects
	unsigned int d_capacity; // Stores allocated capacity
	Data *d_data; // Stores data

	public:

	// Default constructor
	Vector() :
	d_size(0),
	d_capacity(0),
	d_data(0) {};

	// Copy constuctor
	Vector(Vector const &other) :
	d_size(other.d_size),
	d_capacity(other.d_capacity),
	d_data(0){
		d_data = (Data *)malloc(d_capacity*sizeof(Data));
		memcpy(d_data, other.d_data, d_size*sizeof(Data));
	};

	// Destructor
	~Vector() {
		free(d_data);
	};

	// Needed for memory management
	Vector &operator=(Vector const &other) {
		free(d_data);
		d_size = other.d_size;
		d_capacity = other.d_capacity;
		d_data = (Data *)malloc(d_capacity*sizeof(Data));
		memcpy(d_data, other.d_data, d_size*sizeof(Data));
		return *this;
	};

	// Adds new value. If needed, allocates more space
	void add(Data const &data) {
		if (d_capacity == d_size) resize(d_capacity + 1);
		d_data[d_size++] = data;
	};

	// Adds new value at specific index. If needed, allocates more space
	void addAt(unsigned int index, Data const &data) {
		if (index >= d_capacity) resize(index + 1);
		if (d_capacity == d_size) resize(d_capacity + 1);
		if (index >= d_size) {
			for (unsigned int i = d_size; i <= index; ++i) {
				d_data[i] = data;
			}
			d_size = index + 1;
		} else {
			for (unsigned int i = d_size; i > index; --i) {
				d_data[i] = d_data[i - 1];
			}
			d_data[index] = data;
			d_size++;
		}
	};

	// Removes value by finding it's index and erasing it.
	void remove(Data const &data) {
		for (unsigned int i = 0; i < d_size; ++i){
			if(d_data[i] == data) return removeAt(i);
		}
	};

	// Remove a value at an specific index. All other values will be moved
	void removeAt(unsigned int index) {
		if (index >= d_size) return;
		for (unsigned int i = index; i < d_size; ++i){
			d_data[i] = d_data[i+1];
		}
		d_size--;
	};

	// Find the position index of an item
	int position(Data const &data) {
		for (unsigned int i = 0; i < d_size; ++i){
			if(d_data[i] == data) return i;
		}
		return -1;
	};

	// Finds if the vector contains the item
	bool contains(Data const &data) {
		return position(data) != -1;
	};

	// Clears all the data from the vector
	void clear() {
		d_size = 0;
		d_capacity = 0;
		free(d_data);
	};

	// Size getter
	unsigned int size() const {
		return d_size;
	};

	// Const getter
	Data const &operator[](unsigned int index) const {
		return d_data[index];
	};

	// Changeable getter
	Data &operator[](unsigned int index) {
		return d_data[index];
	};

	private:

	// Allocates more space
	void resize(unsigned int newsize) {
		if (newsize <= d_size) return;
		d_capacity = newsize;
		Data *newdata = (Data *)malloc(d_capacity*sizeof(Data));
		memcpy(newdata, d_data, d_size * sizeof(Data));
		free(d_data);
		d_data = newdata;
	};
};
#endif
