#ifndef CATACTION_GLOBAL_H
#define CATACTION_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef CATACTION_LIB
# define CATACTION_EXPORT Q_DECL_EXPORT
#else
# define CATACTION_EXPORT Q_DECL_IMPORT
#endif

#endif // CATACTION_GLOBAL_H
