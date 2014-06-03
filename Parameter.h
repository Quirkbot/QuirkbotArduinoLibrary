#ifndef Parameter_h_
#define Parameter_h_

#include "BaseNode.h"
#include "Outputable.h"

class BaseNode;
class Outputable;
class Parameter{

	public:

	Parameter();
	void setParent(BaseNode * parent);
	void setFromSource(Outputable * source);
	void setFromValue(float value);
	void clearSource();
	float getValue();

	Parameter & operator=(const float &rhs);
	Parameter & operator=(Outputable &rhs);
	
	protected:

	void onSourceUpdated(float value);

	float value;
	BaseNode * parent;
	Outputable * source;

};

#endif
