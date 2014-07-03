#ifndef ContainsInputs_h_
#define ContainsInputs_h_

template <class T>
class Input;

template <class T1>
class Contains1Input{
	public:
		Contains1Input(
			Input<T1>& _0):
		in0(_0){}

		template <class TT1>
		void use(const TT1 &_0){
			in0 = _0;
		}
		
		Input<T1> &in0;
};

template <
	class T1,
	class T2>
class Contains2Inputs :
public Contains1Input<T1>{
	public:
		Contains2Inputs(
			Input<T1>& _0, 
			Input<T2>& _1) :
		Contains1Input<T1>(
			_0),
		in1(_1){}

		template <
			class TT1,
			class TT2>
		void use(
			const TT1 &_0, 
			const TT2 &_1){

			Contains1Input<T1>::use(_0);
			in1 = _1;
		}
		
		Input<T2> &in1;
};

template <
	class T1,
	class T2,
	class T3>
class Contains3Inputs :
public Contains2Inputs<
	T1,
	T2>{
	public:
		Contains3Inputs(
			Input<T1>& _0, 
			Input<T2>& _1, 
			Input<T3>& _2) :
		Contains2Inputs<
			T1,
			T2>(
				_0,
				_1),
		in2(_2){}

		template <
			class TT1,
			class TT2,
			class TT3>
		void use(
			const TT1 &_0, 
			const TT2 &_1, 
			const TT3 &_2){

			Contains2Inputs<
				T1,
				T2>::use(
				_0, 
				_1);
			in2 = _2;
		}
		
		Input<T3> &in2;
};

template <
	class T1,
	class T2,
	class T3,
	class T4>
class Contains4Inputs :
public Contains3Inputs<
	T1,
	T2,
	T3>{
	public:
		Contains4Inputs(
			Input<T1>& _0, 
			Input<T2>& _1, 
			Input<T3>& _2,
			Input<T4>& _3) :
		Contains3Inputs<
			T1,
			T2,
			T3>(
				_0,
				_1,
				_2),
		in3(_3){}

		template <
			class TT1,
			class TT2,
			class TT3,
			class TT4>
		void use(
			const TT1 &_0, 
			const TT2 &_1, 
			const TT3 &_2,
			const TT4 &_3){

			Contains3Inputs<
				T1,
				T2,
				T3>::use(
				_0, 
				_1,
				_2);
			in3 = _3;
		}
		
		Input<T4> &in3;
};

template <
	class T1,
	class T2,
	class T3,
	class T4,
	class T5>
class Contains5Inputs :
public Contains4Inputs<
	T1,
	T2,
	T3,
	T4>{
	public:
		Contains5Inputs(
			Input<T1>& _0, 
			Input<T2>& _1, 
			Input<T3>& _2,
			Input<T4>& _3,
			Input<T5>& _4) :
		Contains4Inputs<
			T1,
			T2,
			T3,
			T4>(
				_0,
				_1,
				_2,
				_3),
		in4(_4){}

		template <
			class TT1,
			class TT2,
			class TT3,
			class TT4,
			class TT5>
		void use(
			const TT1 &_0, 
			const TT2 &_1, 
			const TT3 &_2,
			const TT4 &_3,
			const TT5 &_4){

			Contains4Inputs<
				T1,
				T2,
				T3,
				T4>::use(
				_0, 
				_1,
				_2,
				_3);
			in4 = _4;
		}
		
		Input<T5> &in4;
};

template <
	class T1,
	class T2,
	class T3,
	class T4,
	class T5,
	class T6>
class Contains6Inputs :
public Contains5Inputs<
	T1,
	T2,
	T3,
	T4,
	T5>{
	public:
		Contains6Inputs(
			Input<T1>& _0, 
			Input<T2>& _1, 
			Input<T3>& _2,
			Input<T4>& _3,
			Input<T5>& _4,
			Input<T6>& _5) :
		Contains5Inputs<
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
		in5(_5){}

		template <
			class TT1,
			class TT2,
			class TT3,
			class TT4,
			class TT5,
			class TT6>
		void use(
			const TT1 &_0, 
			const TT2 &_1, 
			const TT3 &_2,
			const TT4 &_3,
			const TT5 &_4,
			const TT6 &_5){

			Contains5Inputs<
				T1,
				T2,
				T3,
				T4,
				T5>::use(
				_0, 
				_1,
				_2,
				_3,
				_4);
			in5 = _5;
		}
		
		Input<T6> &in5;
};

template <
	class T1,
	class T2,
	class T3,
	class T4,
	class T5,
	class T6,
	class T7>
class Contains7Inputs :
public Contains6Inputs<
	T1,
	T2,
	T3,
	T4,
	T5,
	T6>{
	public:
		Contains7Inputs(
			Input<T1>& _0, 
			Input<T2>& _1, 
			Input<T3>& _2,
			Input<T4>& _3,
			Input<T5>& _4,
			Input<T6>& _5,
			Input<T7>& _6) :
		Contains6Inputs<
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
		in6(_6){}

		template <
			class TT1,
			class TT2,
			class TT3,
			class TT4,
			class TT5,
			class TT6,
			class TT7>
		void use(
			const TT1 &_0, 
			const TT2 &_1, 
			const TT3 &_2,
			const TT4 &_3,
			const TT5 &_4,
			const TT6 &_5,
			const TT7 &_6){

			Contains6Inputs<
				T1,
				T2,
				T3,
				T4,
				T5,
				T6>::use(
				_0, 
				_1,
				_2,
				_3,
				_4,
				_5);
			in6 = _6;
		}
		
		Input<T7> &in6;
};

template <
	class T1,
	class T2,
	class T3,
	class T4,
	class T5,
	class T6,
	class T7,
	class T8>
class Contains8Inputs :
public Contains7Inputs<
	T1,
	T2,
	T3,
	T4,
	T5,
	T6,
	T7>{
	public:
		Contains8Inputs(
			Input<T1>& _0, 
			Input<T2>& _1, 
			Input<T3>& _2,
			Input<T4>& _3,
			Input<T5>& _4,
			Input<T6>& _5,
			Input<T7>& _6,
			Input<T8>& _7) :
		Contains7Inputs<
			T1,
			T2,
			T3,
			T4,
			T5,
			T6,
			T7>(
				_0,
				_1,
				_2,
				_3,
				_4,
				_5,
				_6),
		in7(_7){}
		
		template <
			class TT1,
			class TT2,
			class TT3,
			class TT4,
			class TT5,
			class TT6,
			class TT7,
			class TT8>
		void use(
			const TT1 &_0, 
			const TT2 &_1, 
			const TT3 &_2,
			const TT4 &_3,
			const TT5 &_4,
			const TT6 &_5,
			const TT7 &_6,
			const TT8 &_7){

			Contains7Inputs<
				T1,
				T2,
				T3,
				T4,
				T5,
				T6,
				T7>::use(
				_0, 
				_1,
				_2,
				_3,
				_4,
				_5,
				_6);
			in7 = _7;
		}

		Input<T8> &in7;
};
#endif
