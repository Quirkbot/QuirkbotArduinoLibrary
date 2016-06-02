#include "VectorInputsPointer.h"

VectorInputsPointer::VectorInputsPointer() :
d_size(0),
d_capacity(0),
d_data(0) {}; // Default constructor

VectorInputsPointer::VectorInputsPointer(VectorInputsPointer const &other) :
d_size(other.d_size),
d_capacity(other.d_capacity),
d_data(0){
	d_data = (VectorInputsPointer::Data *)malloc(d_capacity*sizeof(VectorInputsPointer::Data));
	memcpy(d_data, other.d_data, d_size*sizeof(VectorInputsPointer::Data));
}; // Copy constuctor

VectorInputsPointer::~VectorInputsPointer() {
	free(d_data);
}; // Destructor

VectorInputsPointer& VectorInputsPointer::operator=(VectorInputsPointer const &other) {
	free(d_data);
	d_size = other.d_size;
	d_capacity = other.d_capacity;
	d_data = (VectorInputsPointer::Data *)malloc(d_capacity*sizeof(VectorInputsPointer::Data));
	memcpy(d_data, other.d_data, d_size*sizeof(VectorInputsPointer::Data));
	return *this;
}; // Needed for memory management

void VectorInputsPointer::push(VectorInputsPointer::Data const &x) {
	if (d_capacity == d_size) resize();
	d_data[d_size++] = x;
}; // Adds new value. If needed, allocates more space

void VectorInputsPointer::pop(VectorInputsPointer::Data const &x) {
	for (unsigned int i = 0; i < d_size; ++i){
		if(d_data[i] == x) return erase(i);
	}
}; // Removes value by finding it's index and erasing it.

void VectorInputsPointer::erase(unsigned int index) {
	for (unsigned int i = index; i < d_size; ++i){
		d_data[i] = d_data[i+1];
	}
	d_size--;
}; // Pops a value at an specific index. All other values will be moved

void VectorInputsPointer::clear() {
	d_size = 0;
	d_capacity = 0;
	free(d_data);
}; // Clears all the data from the vector

unsigned int VectorInputsPointer::size() const {
	return d_size;
}; // Size getter


VectorInputsPointer::Data const & VectorInputsPointer::operator[](unsigned int idx) const {
	return d_data[idx];
}; // Const getter

VectorInputsPointer::Data& VectorInputsPointer::operator[](unsigned int idx) {
	return d_data[idx];
}; // Changeable getter


void VectorInputsPointer::resize() {
	d_capacity = d_capacity ? d_capacity*2 : 1;
	VectorInputsPointer::Data *newdata = (VectorInputsPointer::Data *)malloc(d_capacity*sizeof(VectorInputsPointer::Data));
	memcpy(newdata, d_data, d_size * sizeof(VectorInputsPointer::Data));
	free(d_data);
	d_data = newdata;
};// Allocates double the old space

