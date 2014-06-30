#ifndef Streams_h
#define Streams_h

template <class T>
class Input;

template <class T>
class Output;

template <class T>
class OutputStream;

template <class T>
class InputStream{
	public:
		InputStream(Input<T>& _input):
		input(_input){}

		void connect(OutputStream<T>& stream){
			input.connect(stream.output);
		};
		
		Input<T> &input;
};

template <class T>
class OutputStream{
	public:
		OutputStream(Output<T>& _output):
		output(_output){}
		
		operator Output<T>&(){
			return output;
		}

		Output<T> &output;
};

template <class T>
class InputOutputStream : public InputStream<T>, public OutputStream<T>{
	public:
		InputOutputStream(Input<T>& _input, Output<T>& _output):
		InputStream<T>(_input),
		OutputStream<T>(_output)
		{}
};

#endif