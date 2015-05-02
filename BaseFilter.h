#ifndef BaseFilter_h_
#define BaseFilter_h_

class BaseFilter {
	public:

	virtual void push(float number){};
	
	float get();
	void set(float v);

	float alpha;
	float beta;
	float gamma;
	float value;
};
#endif