#include "CatAction.h"

CatAction::CatAction()
{

}

CatAction::~CatAction()
{

}

void CatAction::setTitle( const QString& tt )
{
	myTitle = tt;
}

void CatAction::setDescription( const QString& desc )
{
	myDescription = desc;
}

void CatAction::setErrorMessage( const QString& msg )
{
	myErrorMessage = msg;
}

bool ActionGroup::doIt()
{
	foreach(const Pointer& act,myActions)
	{
		if(!act->doIt())
			return false;
	}
	return true;
}

void ActionGroup::add( const Pointer& ad )
{
	myActions.append(ad); 
}

void ActionGroup::remove( const Pointer& rm )
{
	myActions.removeAll(rm);
}

int ActionGroup::count() const
{
	return myActions.size();
}
