#include "Parameter.h"

Parameter::Parameter(){

}
void Parameter::onSourceUpdated(float value){
	this->value = value;
	parent->onParameterUpdated(*this);
}
void Parameter::setParent(BaseNode * parent){
	this->parent = parent;
}
void Parameter::setFromSource(Outputable * source){
	clearSource();
	this->source = source;
	source->outputUpdated->add(this, &Parameter::onSourceUpdated);
}
void Parameter::setFromValue(float value){
	clearSource();
	onSourceUpdated(value);
}
void Parameter::clearSource(){
	if(source)
		source->outputUpdated->remove(&Parameter::onSourceUpdated);
}
float Parameter::getValue(){
	return value;
}
Parameter& Parameter::operator=(const float &rhs){
	setFromValue(rhs);
}
Parameter& Parameter::operator=(Outputable &rhs){
	setFromSource(&rhs);
}