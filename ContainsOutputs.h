#ifndef ContainsOutputs_h_
#define ContainsOutputs_h_

template <class T>
class Output;

template <class T1>
class Contains1Output{
	public:
		Contains1Output(Output<T1>& _0):
		out0(_0){}
		
		Output<T1> &out0;
};

template <
	class T1,
	class T2>
class Contains2Outputs :
public Contains1Output<T1>{
	public:
		Contains2Outputs(
			Output<T1>& _0, 
			Output<T2>& _1) :
		Contains1Output<
			T1>(
				_0),
		out1(_1){}
		
		Output<T2> &out1;
};

template <
	class T1,
	class T2,
	class T3>
class Contains3Outputs :
public Contains2Outputs<
	T1,
	T2>{
	public:
		Contains3Outputs(
			Output<T1>& _0, 
			Output<T2>& _1, 
			Output<T3>& _2) :
		Contains2Outputs<
			T1,
			T2>(
				_0,
				_1),
		out2(_2){}
		
		Output<T3> &out2;
};

template <
	class T1,
	class T2,
	class T3,
	class T4>
class Contains4Outputs :
public Contains3Outputs<
	T1,
	T2,
	T3>{
	public:
		Contains4Outputs(
			Output<T1>& _0, 
			Output<T2>& _1, 
			Output<T3>& _2,
			Output<T4>& _3) :
		Contains3Outputs<
			T1,
			T2,
			T3>(
				_0,
				_1,
				_2),
		out3(_3){}
		
		Output<T4> &out3;
};

template <
	class T1,
	class T2,
	class T3,
	class T4,
	class T5>
class Contains5Outputs :
public Contains4Outputs<
	T1,
	T2,
	T3,
	T4>{
	public:
		Contains5Outputs(
			Output<T1>& _0, 
			Output<T2>& _1, 
			Output<T3>& _2,
			Output<T4>& _3,
			Output<T5>& _4) :
		Contains4Outputs<
			T1,
			T2,
			T3,
			T4>(
				_0,
				_1,
				_2,
				_3),
		out4(_4){}
		
		Output<T5> &out4;
};

template <
	class T1,
	class T2,
	class T3,
	class T4,
	class T5,
	class T6>
class Contains6Outputs :
public Contains5Outputs<
	T1,
	T2,
	T3,
	T4,
	T5>{
	public:
		Contains6Outputs(
			Output<T1>& _0, 
			Output<T2>& _1, 
			Output<T3>& _2,
			Output<T4>& _3,
			Output<T5>& _4,
			Output<T6>& _5) :
		Contains5Outputs<
			T1,
			T2,
			T3,
			T4,
			T5>(
				_0,
				_1,
				_2,
				_3,
				_4),
		out5(_5){}
		
		Output<T6> &out5;
};

template <
	class T1,
	class T2,
	class T3,
	class T4,
	class T5,
	class T6,
	class T7>
class Contains7Outputs :
public Contains6Outputs<
	T1,
	T2,
	T3,
	T4,
	T5,
	T6>{
	public:
		Contains7Outputs(
			Output<T1>& _0, 
			Output<T2>& _1, 
			Output<T3>& _2,
			Output<T4>& _3,
			Output<T5>& _4,
			Output<T6>& _5,
			Output<T7>& _6) :
		Contains6Outputs<
			T1,
			T2,
			T3,
			T4,
			T5,
			T6>(
				_0,
				_1,
				_2,
				_3,
				_4,
				_5),
		out6(_6){}
		
		Output<T7> &out6;
};

#endif
