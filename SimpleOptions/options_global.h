#ifndef SIMPLEOPTIONS_GLOBAL_H
#define SIMPLEOPTIONS_GLOBAL_H

#include <QtGlobal>

#if defined(SIMPLEOPTIONS_LIBRARY)
#  define SIMPLEOPTIONSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define SIMPLEOPTIONSSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // SIMPLEOPTIONS_GLOBAL_H

