#include "VectorTypedInputHandler.h"

VectorTypedInputHandler::VectorTypedInputHandler() :
d_size(0),
d_capacity(0),
d_data(0) {}; // Default constructor

VectorTypedInputHandler::VectorTypedInputHandler(VectorTypedInputHandler const &other) :
d_size(other.d_size),
d_capacity(other.d_capacity),
d_data(0){
	d_data = (VectorTypedInputHandler::Data *)malloc(d_capacity*sizeof(VectorTypedInputHandler::Data));
	memcpy(d_data, other.d_data, d_size*sizeof(VectorTypedInputHandler::Data));
}; // Copy constuctor

VectorTypedInputHandler::~VectorTypedInputHandler() {
	free(d_data);
}; // Destructor

VectorTypedInputHandler& VectorTypedInputHandler::operator=(VectorTypedInputHandler const &other) {
	free(d_data);
	d_size = other.d_size;
	d_capacity = other.d_capacity;
	d_data = (VectorTypedInputHandler::Data *)malloc(d_capacity*sizeof(VectorTypedInputHandler::Data));
	memcpy(d_data, other.d_data, d_size*sizeof(VectorTypedInputHandler::Data));
	return *this;
}; // Needed for memory management

void VectorTypedInputHandler::push(VectorTypedInputHandler::Data const &x) {
	if (d_capacity == d_size) resize();
	d_data[d_size++] = x;
}; // Adds new value. If needed, allocates more space

void VectorTypedInputHandler::pop(VectorTypedInputHandler::Data const &x) {
	for (unsigned int i = 0; i < d_size; ++i){
		if(d_data[i] == x) return erase(i);
	}
}; // Removes value by finding it's index and erasing it.

void VectorTypedInputHandler::erase(unsigned int index) {
	for (unsigned int i = index; i < d_size; ++i){
		d_data[i] = d_data[i+1];
	}
	d_size--;
}; // Pops a value at an specific index. All other values will be moved

void VectorTypedInputHandler::clear() {
	d_size = 0;
	d_capacity = 0;
	free(d_data);
}; // Clears all the data from the vector

unsigned int VectorTypedInputHandler::size() const {
	return d_size;
}; // Size getter


VectorTypedInputHandler::Data const & VectorTypedInputHandler::operator[](unsigned int idx) const {
	return d_data[idx];
}; // Const getter

VectorTypedInputHandler::Data& VectorTypedInputHandler::operator[](unsigned int idx) {
	return d_data[idx];
}; // Changeable getter


void VectorTypedInputHandler::resize() {
	d_capacity = d_capacity ? d_capacity*2 : 1;
	VectorTypedInputHandler::Data *newdata = (VectorTypedInputHandler::Data *)malloc(d_capacity*sizeof(VectorTypedInputHandler::Data));
	memcpy(newdata, d_data, d_size * sizeof(VectorTypedInputHandler::Data));
	free(d_data);
	d_data = newdata;
};// Allocates double the old space

