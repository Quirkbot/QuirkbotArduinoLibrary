#ifndef Filters_h_
#define Filters_h_

class FilterBase {
	public:

	virtual void push(float number){};
	
	float get(){
		return value;
	} 

	float alpha;
	float beta;
	float gamma;
	float value;
	
};

class NoFilter :
public FilterBase 
{
	public:
	void push(float number){
		value = number;
	}
};

class MedianFilter :
public FilterBase 
{
	public:
	
	MedianFilter(){
		a = 0;
		b = 0;
		c = 0;
		value = 0;
	}

	void push(float number){
		a = b;
		b = c;
		c = number;

		if (c < b) {
			if (c < a) {
				if (b < a) value = b;
				else value = a;
			}
			else value = c;
		}
		else {
			if (c < a) value = c;
			else {
				if (b < a) value = a;
				else value = b;
			}
		}
	}

	private:

	float a;
	float b;
	float c;
};

class LowPassFilter :
public FilterBase 
{
	public:
	
	LowPassFilter(){
		value = 0;
		alpha = 0.5;
	}

	void push(float number){
		value = value * alpha + number * (1 - alpha);
	}
};

class UpperFilter :
public FilterBase 
{
	public:
	
	UpperFilter(){
		a = 0;
		b = 0;
		c = 0;
		d = 0;
		value = 0;
	}

	void push(float number){
		a = b;
		b = c;
		c = d;
		d = number;

		value = max( max( max( a, b ), c ), d );
	}

	private:

	float a;
	float b;
	float c;
	float d;
};

#endif