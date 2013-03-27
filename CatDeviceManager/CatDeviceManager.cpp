#include "CatDeviceManager.h"

CatDeviceManager::CatDeviceManager(QObject *parent)
	: QObject(parent)
{
	::CoInitialize(NULL);
	ptr34980 = IAgilent34980A2Ptr(__uuidof(Agilent34980A));
	ptr34411 = IAgilent34410Ptr(__uuidof(Agilent34410));
}

CatDeviceManager::~CatDeviceManager()
{
// 	if(ptr34980)
// 		ptr34980->Close();
// 	if(ptr34411)
// 		ptr34411->Close();
	::CoUninitialize();
}

CatDeviceManager& CatDeviceManager::GetInstance()
{
	static CatDeviceManager mgr;
	return mgr;
}

IAgilent34980A2Ptr CatDeviceManager::Get34980() const
{
	return ptr34980;
}

IAgilent34410Ptr CatDeviceManager::Get34411() const
{
	return ptr34411;
}
