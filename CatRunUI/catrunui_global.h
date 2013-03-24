#ifndef CATRUNUI_GLOBAL_H
#define CATRUNUI_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef CATRUNUI_LIB
# define CATRUNUI_EXPORT Q_DECL_EXPORT
#else
# define CATRUNUI_EXPORT Q_DECL_IMPORT
#endif

#endif // CATRUNUI_GLOBAL_H
