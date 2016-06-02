#include "VectorUpdatablesPointer.h"

VectorUpdatablesPointer::VectorUpdatablesPointer() :
d_size(0),
d_capacity(0),
d_data(0) {}; // Default constructor

VectorUpdatablesPointer::VectorUpdatablesPointer(VectorUpdatablesPointer const &other) :
d_size(other.d_size),
d_capacity(other.d_capacity),
d_data(0){
	d_data = (VectorUpdatablesPointer::Data *)malloc(d_capacity*sizeof(VectorUpdatablesPointer::Data));
	memcpy(d_data, other.d_data, d_size*sizeof(VectorUpdatablesPointer::Data));
}; // Copy constuctor

VectorUpdatablesPointer::~VectorUpdatablesPointer() {
	free(d_data);
}; // Destructor

VectorUpdatablesPointer& VectorUpdatablesPointer::operator=(VectorUpdatablesPointer const &other) {
	free(d_data);
	d_size = other.d_size;
	d_capacity = other.d_capacity;
	d_data = (VectorUpdatablesPointer::Data *)malloc(d_capacity*sizeof(VectorUpdatablesPointer::Data));
	memcpy(d_data, other.d_data, d_size*sizeof(VectorUpdatablesPointer::Data));
	return *this;
}; // Needed for memory management

void VectorUpdatablesPointer::push(VectorUpdatablesPointer::Data const &x) {
	if (d_capacity == d_size) resize();
	d_data[d_size++] = x;
}; // Adds new value. If needed, allocates more space

void VectorUpdatablesPointer::pop(VectorUpdatablesPointer::Data const &x) {
	for (unsigned int i = 0; i < d_size; ++i){
		if(d_data[i] == x) return erase(i);
	}
}; // Removes value by finding it's index and erasing it.

void VectorUpdatablesPointer::erase(unsigned int index) {
	for (unsigned int i = index; i < d_size; ++i){
		d_data[i] = d_data[i+1];
	}
	d_size--;
}; // Pops a value at an specific index. All other values will be moved

void VectorUpdatablesPointer::clear() {
	d_size = 0;
	d_capacity = 0;
	free(d_data);
}; // Clears all the data from the vector

unsigned int VectorUpdatablesPointer::size() const {
	return d_size;
}; // Size getter


VectorUpdatablesPointer::Data const & VectorUpdatablesPointer::operator[](unsigned int idx) const {
	return d_data[idx];
}; // Const getter

VectorUpdatablesPointer::Data& VectorUpdatablesPointer::operator[](unsigned int idx) {
	return d_data[idx];
}; // Changeable getter


void VectorUpdatablesPointer::resize() {
	d_capacity = d_capacity ? d_capacity*2 : 1;
	VectorUpdatablesPointer::Data *newdata = (VectorUpdatablesPointer::Data *)malloc(d_capacity*sizeof(VectorUpdatablesPointer::Data));
	memcpy(newdata, d_data, d_size * sizeof(VectorUpdatablesPointer::Data));
	free(d_data);
	d_data = newdata;
};// Allocates double the old space

