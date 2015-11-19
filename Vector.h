#ifndef Vector_h_
#define Vector_h_

#include "Arduino.h"

// Minimal class to replace std::vector
/*template<typename Data>
class Vector {
	unsigned int d_size; // Stores no. of actually stored objects
	unsigned int d_capacity; // Stores allocated capacity
	Data *d_data; // Stores data

	public:

	Vector() :
	d_size(0),
	d_capacity(0),
	d_data(0) {}; // Default constructor

	Vector(Vector const &other) :
	d_size(other.d_size),
	d_capacity(other.d_capacity),
	d_data(0){
		d_data = (Data *)malloc(d_capacity*sizeof(Data));
		memcpy(d_data, other.d_data, d_size*sizeof(Data));
	}; // Copy constuctor

	~Vector() {
		free(d_data);
	}; // Destructor

	Vector &operator=(Vector const &other) {
		free(d_data);
		d_size = other.d_size;
		d_capacity = other.d_capacity;
		d_data = (Data *)malloc(d_capacity*sizeof(Data));
		memcpy(d_data, other.d_data, d_size*sizeof(Data));
		return *this;
	}; // Needed for memory management

	void push(Data const &x) {
		if (d_capacity == d_size) resize();
		d_data[d_size++] = x;
	}; // Adds new value. If needed, allocates more space

	void pop(Data const &x) {
		for (unsigned int i = 0; i < d_size; ++i){
			if(d_data[i] == x) return erase(i);
		}
	}; // Removes value by finding it's index and erasing it.

	void erase(unsigned int index) {
		for (unsigned int i = index; i < d_size; ++i){
			d_data[i] = d_data[i+1];
		}
		d_size--;
	}; // Pops a value at an specific index. All other values will be moved

	void clear() {
		d_size = 0;
		d_capacity = 0;
		free(d_data);
	}; // Clears all the data from the vector

	unsigned int size() const {
		return d_size;
	}; // Size getter

	Data const &operator[](unsigned int idx) const {
		return d_data[idx];
	}; // Const getter

	Data &operator[](unsigned int idx) {
		return d_data[idx];
	}; // Changeable getter

	private:

	void resize() {
		d_capacity = d_capacity ? d_capacity*2 : 1;
		Data *newdata = (Data *)malloc(d_capacity*sizeof(Data));
		memcpy(newdata, d_data, d_size * sizeof(Data));
		free(d_data);
		d_data = newdata;
	};// Allocates double the old space
};*/

class Input;
class VectorInputsPointer {
	typedef Input* Data;

	unsigned int d_size; // Stores no. of actually stored objects
	unsigned int d_capacity; // Stores allocated capacity
	Data *d_data; // Stores data

	public:

	VectorInputsPointer() :
	d_size(0),
	d_capacity(0),
	d_data(0) {}; // Default constructor

	VectorInputsPointer(VectorInputsPointer const &other) :
	d_size(other.d_size),
	d_capacity(other.d_capacity),
	d_data(0){
		d_data = (Data *)malloc(d_capacity*sizeof(Data));
		memcpy(d_data, other.d_data, d_size*sizeof(Data));
	}; // Copy constuctor

	~VectorInputsPointer() {
		free(d_data);
	}; // Destructor

	VectorInputsPointer &operator=(VectorInputsPointer const &other) {
		free(d_data);
		d_size = other.d_size;
		d_capacity = other.d_capacity;
		d_data = (Data *)malloc(d_capacity*sizeof(Data));
		memcpy(d_data, other.d_data, d_size*sizeof(Data));
		return *this;
	}; // Needed for memory management

	void push(Data const &x) {
		if (d_capacity == d_size) resize();
		d_data[d_size++] = x;
	}; // Adds new value. If needed, allocates more space

	void pop(Data const &x) {
		for (unsigned int i = 0; i < d_size; ++i){
			if(d_data[i] == x) return erase(i);
		}
	}; // Removes value by finding it's index and erasing it.

	void erase(unsigned int index) {
		for (unsigned int i = index; i < d_size; ++i){
			d_data[i] = d_data[i+1];
		}
		d_size--;
	}; // Pops a value at an specific index. All other values will be moved

	void clear() {
		d_size = 0;
		d_capacity = 0;
		free(d_data);
	}; // Clears all the data from the vector

	unsigned int size() const {
		return d_size;
	}; // Size getter

	Data const &operator[](unsigned int idx) const {
		return d_data[idx];
	}; // Const getter

	Data &operator[](unsigned int idx) {
		return d_data[idx];
	}; // Changeable getter

	private:

	void resize() {
		d_capacity = d_capacity ? d_capacity*2 : 1;
		Data *newdata = (Data *)malloc(d_capacity*sizeof(Data));
		memcpy(newdata, d_data, d_size * sizeof(Data));
		free(d_data);
		d_data = newdata;
	};// Allocates double the old space
};

class Node;
class VectorNodesPointer {
	typedef Node* Data;

	unsigned int d_size; // Stores no. of actually stored objects
	unsigned int d_capacity; // Stores allocated capacity
	Data *d_data; // Stores data

	public:

	VectorNodesPointer() :
	d_size(0),
	d_capacity(0),
	d_data(0) {}; // Default constructor

	VectorNodesPointer(VectorNodesPointer const &other) :
	d_size(other.d_size),
	d_capacity(other.d_capacity),
	d_data(0){
		d_data = (Data *)malloc(d_capacity*sizeof(Data));
		memcpy(d_data, other.d_data, d_size*sizeof(Data));
	}; // Copy constuctor

	~VectorNodesPointer() {
		free(d_data);
	}; // Destructor

	VectorNodesPointer &operator=(VectorNodesPointer const &other) {
		free(d_data);
		d_size = other.d_size;
		d_capacity = other.d_capacity;
		d_data = (Data *)malloc(d_capacity*sizeof(Data));
		memcpy(d_data, other.d_data, d_size*sizeof(Data));
		return *this;
	}; // Needed for memory management

	void push(Data const &x) {
		if (d_capacity == d_size) resize();
		d_data[d_size++] = x;
	}; // Adds new value. If needed, allocates more space

	void pop(Data const &x) {
		for (unsigned int i = 0; i < d_size; ++i){
			if(d_data[i] == x) return erase(i);
		}
	}; // Removes value by finding it's index and erasing it.

	void erase(unsigned int index) {
		for (unsigned int i = index; i < d_size; ++i){
			d_data[i] = d_data[i+1];
		}
		d_size--;
	}; // Pops a value at an specific index. All other values will be moved

	void clear() {
		d_size = 0;
		d_capacity = 0;
		free(d_data);
	}; // Clears all the data from the vector

	unsigned int size() const {
		return d_size;
	}; // Size getter

	Data const &operator[](unsigned int idx) const {
		return d_data[idx];
	}; // Const getter

	Data &operator[](unsigned int idx) {
		return d_data[idx];
	}; // Changeable getter

	private:

	void resize() {
		d_capacity = d_capacity ? d_capacity*2 : 1;
		Data *newdata = (Data *)malloc(d_capacity*sizeof(Data));
		memcpy(newdata, d_data, d_size * sizeof(Data));
		free(d_data);
		d_data = newdata;
	};// Allocates double the old space
};

class Updatable;
class VectorUpdatablesPointer {
	typedef Updatable* Data;

	unsigned int d_size; // Stores no. of actually stored objects
	unsigned int d_capacity; // Stores allocated capacity
	Data *d_data; // Stores data

	public:

	VectorUpdatablesPointer() :
	d_size(0),
	d_capacity(0),
	d_data(0) {}; // Default constructor

	VectorUpdatablesPointer(VectorUpdatablesPointer const &other) :
	d_size(other.d_size),
	d_capacity(other.d_capacity),
	d_data(0){
		d_data = (Data *)malloc(d_capacity*sizeof(Data));
		memcpy(d_data, other.d_data, d_size*sizeof(Data));
	}; // Copy constuctor

	~VectorUpdatablesPointer() {
		free(d_data);
	}; // Destructor

	VectorUpdatablesPointer &operator=(VectorUpdatablesPointer const &other) {
		free(d_data);
		d_size = other.d_size;
		d_capacity = other.d_capacity;
		d_data = (Data *)malloc(d_capacity*sizeof(Data));
		memcpy(d_data, other.d_data, d_size*sizeof(Data));
		return *this;
	}; // Needed for memory management

	void push(Data const &x) {
		if (d_capacity == d_size) resize();
		d_data[d_size++] = x;
	}; // Adds new value. If needed, allocates more space

	void pop(Data const &x) {
		for (unsigned int i = 0; i < d_size; ++i){
			if(d_data[i] == x) return erase(i);
		}
	}; // Removes value by finding it's index and erasing it.

	void erase(unsigned int index) {
		for (unsigned int i = index; i < d_size; ++i){
			d_data[i] = d_data[i+1];
		}
		d_size--;
	}; // Pops a value at an specific index. All other values will be moved

	void clear() {
		d_size = 0;
		d_capacity = 0;
		free(d_data);
	}; // Clears all the data from the vector

	unsigned int size() const {
		return d_size;
	}; // Size getter

	Data const &operator[](unsigned int idx) const {
		return d_data[idx];
	}; // Const getter

	Data &operator[](unsigned int idx) {
		return d_data[idx];
	}; // Changeable getter

	private:

	void resize() {
		d_capacity = d_capacity ? d_capacity*2 : 1;
		Data *newdata = (Data *)malloc(d_capacity*sizeof(Data));
		memcpy(newdata, d_data, d_size * sizeof(Data));
		free(d_data);
		d_data = newdata;
	};// Allocates double the old space
};

class InterruptUpdatable;
class VectorInterruptUpdatablesPointer {
	typedef InterruptUpdatable* Data;

	unsigned int d_size; // Stores no. of actually stored objects
	unsigned int d_capacity; // Stores allocated capacity
	Data *d_data; // Stores data

	public:

	VectorInterruptUpdatablesPointer() :
	d_size(0),
	d_capacity(0),
	d_data(0) {}; // Default constructor

	VectorInterruptUpdatablesPointer(VectorInterruptUpdatablesPointer const &other) :
	d_size(other.d_size),
	d_capacity(other.d_capacity),
	d_data(0){
		d_data = (Data *)malloc(d_capacity*sizeof(Data));
		memcpy(d_data, other.d_data, d_size*sizeof(Data));
	}; // Copy constuctor

	~VectorInterruptUpdatablesPointer() {
		free(d_data);
	}; // Destructor

	VectorInterruptUpdatablesPointer &operator=(VectorInterruptUpdatablesPointer const &other) {
		free(d_data);
		d_size = other.d_size;
		d_capacity = other.d_capacity;
		d_data = (Data *)malloc(d_capacity*sizeof(Data));
		memcpy(d_data, other.d_data, d_size*sizeof(Data));
		return *this;
	}; // Needed for memory management

	void push(Data const &x) {
		if (d_capacity == d_size) resize();
		d_data[d_size++] = x;
	}; // Adds new value. If needed, allocates more space

	void pop(Data const &x) {
		for (unsigned int i = 0; i < d_size; ++i){
			if(d_data[i] == x) return erase(i);
		}
	}; // Removes value by finding it's index and erasing it.

	void erase(unsigned int index) {
		for (unsigned int i = index; i < d_size; ++i){
			d_data[i] = d_data[i+1];
		}
		d_size--;
	}; // Pops a value at an specific index. All other values will be moved

	void clear() {
		d_size = 0;
		d_capacity = 0;
		free(d_data);
	}; // Clears all the data from the vector

	unsigned int size() const {
		return d_size;
	}; // Size getter

	Data const &operator[](unsigned int idx) const {
		return d_data[idx];
	}; // Const getter

	Data &operator[](unsigned int idx) {
		return d_data[idx];
	}; // Changeable getter

	private:

	void resize() {
		d_capacity = d_capacity ? d_capacity*2 : 1;
		Data *newdata = (Data *)malloc(d_capacity*sizeof(Data));
		memcpy(newdata, d_data, d_size * sizeof(Data));
		free(d_data);
		d_data = newdata;
	};// Allocates double the old space
};

typedef void (Input::*TypedInputHandler)(float value);
class VectorTypedInputHandler {
	typedef TypedInputHandler Data;

	unsigned int d_size; // Stores no. of actually stored objects
	unsigned int d_capacity; // Stores allocated capacity
	Data *d_data; // Stores data

	public:

	VectorTypedInputHandler() :
	d_size(0),
	d_capacity(0),
	d_data(0) {}; // Default constructor

	VectorTypedInputHandler(VectorTypedInputHandler const &other) :
	d_size(other.d_size),
	d_capacity(other.d_capacity),
	d_data(0){
		d_data = (Data *)malloc(d_capacity*sizeof(Data));
		memcpy(d_data, other.d_data, d_size*sizeof(Data));
	}; // Copy constuctor

	~VectorTypedInputHandler() {
		free(d_data);
	}; // Destructor

	VectorTypedInputHandler &operator=(VectorTypedInputHandler const &other) {
		free(d_data);
		d_size = other.d_size;
		d_capacity = other.d_capacity;
		d_data = (Data *)malloc(d_capacity*sizeof(Data));
		memcpy(d_data, other.d_data, d_size*sizeof(Data));
		return *this;
	}; // Needed for memory management

	void push(Data const &x) {
		if (d_capacity == d_size) resize();
		d_data[d_size++] = x;
	}; // Adds new value. If needed, allocates more space

	void pop(Data const &x) {
		for (unsigned int i = 0; i < d_size; ++i){
			if(d_data[i] == x) return erase(i);
		}
	}; // Removes value by finding it's index and erasing it.

	void erase(unsigned int index) {
		for (unsigned int i = index; i < d_size; ++i){
			d_data[i] = d_data[i+1];
		}
		d_size--;
	}; // Pops a value at an specific index. All other values will be moved

	void clear() {
		d_size = 0;
		d_capacity = 0;
		free(d_data);
	}; // Clears all the data from the vector

	unsigned int size() const {
		return d_size;
	}; // Size getter

	Data const &operator[](unsigned int idx) const {
		return d_data[idx];
	}; // Const getter

	Data &operator[](unsigned int idx) {
		return d_data[idx];
	}; // Changeable getter

	private:

	void resize() {
		d_capacity = d_capacity ? d_capacity*2 : 1;
		Data *newdata = (Data *)malloc(d_capacity*sizeof(Data));
		memcpy(newdata, d_data, d_size * sizeof(Data));
		free(d_data);
		d_data = newdata;
	};// Allocates double the old space
};

#endif
