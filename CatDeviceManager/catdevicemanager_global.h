#ifndef CATDEVICEMANAGER_GLOBAL_H
#define CATDEVICEMANAGER_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef CATDEVICEMANAGER_LIB
# define CATDEVICEMANAGER_EXPORT Q_DECL_EXPORT
#else
# define CATDEVICEMANAGER_EXPORT Q_DECL_IMPORT
#endif

#endif // CATDEVICEMANAGER_GLOBAL_H