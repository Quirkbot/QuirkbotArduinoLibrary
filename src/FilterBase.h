#ifndef FilterBase_h_
#define FilterBase_h_

class FilterBase {
	public:

	FilterBase();
	~FilterBase();

	virtual void push(float /* number */){};

	float get();
	void set(float v);

	float value;
};
#endif
