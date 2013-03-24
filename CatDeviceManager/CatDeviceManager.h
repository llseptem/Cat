#ifndef CATDEVICEMANAGER_H
#define CATDEVICEMANAGER_H

#include <QObject>
#include "catdevicemanager_global.h"
#include "DeviceImport.h"

class CATDEVICEMANAGER_EXPORT CatDeviceManager : public QObject
{
	Q_OBJECT

public:
	~CatDeviceManager();

	static CatDeviceManager& GetInstance();
	IAgilent34980A2Ptr Get34980() const;
	IAgilent34410Ptr Get34411() const;
private:
	CatDeviceManager(QObject *parent = 0);
};

#endif // CATDEVICEMANAGER_H