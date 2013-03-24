#include "CatDeviceManager.h"

CatDeviceManager::CatDeviceManager(QObject *parent)
	: QObject(parent)
{
	long rst = ::CoInitializeEx(NULL,COINIT_MULTITHREADED);
}

CatDeviceManager::~CatDeviceManager()
{
	::CoUninitialize();
}

CatDeviceManager& CatDeviceManager::GetInstance()
{
	static CatDeviceManager mgr;
	return mgr;
}

IAgilent34980A2Ptr CatDeviceManager::Get34980() const
{
	static IAgilent34980A2Ptr ptr(__uuidof(Agilent34980A));
	return ptr;
}

IAgilent34410Ptr CatDeviceManager::Get34411() const
{
	static IAgilent34410Ptr ptr(__uuidof(Agilent34410));
	return ptr;
}
