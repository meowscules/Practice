#ifndef CAPH_GLOBAL_H
#define CAPH_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CAPH_LIBRARY)
#  define CAPH_EXPORT Q_DECL_EXPORT
#else
#  define CAPH_EXPORT Q_DECL_IMPORT
#endif

#endif // CAPH_GLOBAL_H
