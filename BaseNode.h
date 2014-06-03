#ifndef BaseNode_h_
#define BaseNode_h_

#include "Bot.h"
#include "Parameter.h"

class Parameter;
class BaseNode{
	friend class Parameter;

	public:
	
		BaseNode();
		BaseNode(unsigned int id);
		~BaseNode();
	
	protected:
		
		virtual void onParameterUpdated(Parameter& parameter){};
		unsigned int id;

	private:
		
		static unsigned int ID_FACTORY;
};

#endif
