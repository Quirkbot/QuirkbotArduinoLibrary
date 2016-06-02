#include "VectorInterruptUpdatablesPointer.h"

VectorInterruptUpdatablesPointer::VectorInterruptUpdatablesPointer() :
d_size(0),
d_capacity(0),
d_data(0) {}; // Default constructor

VectorInterruptUpdatablesPointer::VectorInterruptUpdatablesPointer(VectorInterruptUpdatablesPointer const &other) :
d_size(other.d_size),
d_capacity(other.d_capacity),
d_data(0){
	d_data = (VectorInterruptUpdatablesPointer::Data *)malloc(d_capacity*sizeof(VectorInterruptUpdatablesPointer::Data));
	memcpy(d_data, other.d_data, d_size*sizeof(VectorInterruptUpdatablesPointer::Data));
}; // Copy constuctor

VectorInterruptUpdatablesPointer::~VectorInterruptUpdatablesPointer() {
	free(d_data);
}; // Destructor

VectorInterruptUpdatablesPointer& VectorInterruptUpdatablesPointer::operator=(VectorInterruptUpdatablesPointer const &other) {
	free(d_data);
	d_size = other.d_size;
	d_capacity = other.d_capacity;
	d_data = (VectorInterruptUpdatablesPointer::Data *)malloc(d_capacity*sizeof(VectorInterruptUpdatablesPointer::Data));
	memcpy(d_data, other.d_data, d_size*sizeof(VectorInterruptUpdatablesPointer::Data));
	return *this;
}; // Needed for memory management

void VectorInterruptUpdatablesPointer::push(VectorInterruptUpdatablesPointer::Data const &x) {
	if (d_capacity == d_size) resize();
	d_data[d_size++] = x;
}; // Adds new value. If needed, allocates more space

void VectorInterruptUpdatablesPointer::pop(VectorInterruptUpdatablesPointer::Data const &x) {
	for (unsigned int i = 0; i < d_size; ++i){
		if(d_data[i] == x) return erase(i);
	}
}; // Removes value by finding it's index and erasing it.

void VectorInterruptUpdatablesPointer::erase(unsigned int index) {
	for (unsigned int i = index; i < d_size; ++i){
		d_data[i] = d_data[i+1];
	}
	d_size--;
}; // Pops a value at an specific index. All other values will be moved

void VectorInterruptUpdatablesPointer::clear() {
	d_size = 0;
	d_capacity = 0;
	free(d_data);
}; // Clears all the data from the vector

unsigned int VectorInterruptUpdatablesPointer::size() const {
	return d_size;
}; // Size getter


VectorInterruptUpdatablesPointer::Data const & VectorInterruptUpdatablesPointer::operator[](unsigned int idx) const {
	return d_data[idx];
}; // Const getter

VectorInterruptUpdatablesPointer::Data& VectorInterruptUpdatablesPointer::operator[](unsigned int idx) {
	return d_data[idx];
}; // Changeable getter


void VectorInterruptUpdatablesPointer::resize() {
	d_capacity = d_capacity ? d_capacity*2 : 1;
	VectorInterruptUpdatablesPointer::Data *newdata = (VectorInterruptUpdatablesPointer::Data *)malloc(d_capacity*sizeof(VectorInterruptUpdatablesPointer::Data));
	memcpy(newdata, d_data, d_size * sizeof(VectorInterruptUpdatablesPointer::Data));
	free(d_data);
	d_data = newdata;
};// Allocates double the old space

