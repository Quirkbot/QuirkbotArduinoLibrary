#include "VectorNodesPointer.h"

VectorNodesPointer::VectorNodesPointer() :
d_size(0),
d_capacity(0),
d_data(0) {}; // Default constructor

VectorNodesPointer::VectorNodesPointer(VectorNodesPointer const &other) :
d_size(other.d_size),
d_capacity(other.d_capacity),
d_data(0){
	d_data = (VectorNodesPointer::Data *)malloc(d_capacity*sizeof(VectorNodesPointer::Data));
	memcpy(d_data, other.d_data, d_size*sizeof(VectorNodesPointer::Data));
}; // Copy constuctor

VectorNodesPointer::~VectorNodesPointer() {
	free(d_data);
}; // Destructor

VectorNodesPointer& VectorNodesPointer::operator=(VectorNodesPointer const &other) {
	free(d_data);
	d_size = other.d_size;
	d_capacity = other.d_capacity;
	d_data = (VectorNodesPointer::Data *)malloc(d_capacity*sizeof(VectorNodesPointer::Data));
	memcpy(d_data, other.d_data, d_size*sizeof(VectorNodesPointer::Data));
	return *this;
}; // Needed for memory management

void VectorNodesPointer::push(VectorNodesPointer::Data const &x) {
	if (d_capacity == d_size) resize();
	d_data[d_size++] = x;
}; // Adds new value. If needed, allocates more space

void VectorNodesPointer::pop(VectorNodesPointer::Data const &x) {
	for (unsigned int i = 0; i < d_size; ++i){
		if(d_data[i] == x) return erase(i);
	}
}; // Removes value by finding it's index and erasing it.

void VectorNodesPointer::erase(unsigned int index) {
	for (unsigned int i = index; i < d_size; ++i){
		d_data[i] = d_data[i+1];
	}
	d_size--;
}; // Pops a value at an specific index. All other values will be moved

void VectorNodesPointer::clear() {
	d_size = 0;
	d_capacity = 0;
	free(d_data);
}; // Clears all the data from the vector

unsigned int VectorNodesPointer::size() const {
	return d_size;
}; // Size getter


VectorNodesPointer::Data const & VectorNodesPointer::operator[](unsigned int idx) const {
	return d_data[idx];
}; // Const getter

VectorNodesPointer::Data& VectorNodesPointer::operator[](unsigned int idx) {
	return d_data[idx];
}; // Changeable getter


void VectorNodesPointer::resize() {
	d_capacity = d_capacity ? d_capacity*2 : 1;
	VectorNodesPointer::Data *newdata = (VectorNodesPointer::Data *)malloc(d_capacity*sizeof(VectorNodesPointer::Data));
	memcpy(newdata, d_data, d_size * sizeof(VectorNodesPointer::Data));
	free(d_data);
	d_data = newdata;
};// Allocates double the old space

