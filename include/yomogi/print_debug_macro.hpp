#ifndef LIBYOMOGI_PRINT_DEBUG_MACRO_HPP
#define LIBYOMOGI_PRINT_DEBUG_MACRO_HPP

#include <iostream>

#define	YOMOGI_PRINT_DEBUG(arg)				\
  do {							\
    std::cout << #arg << " : " << arg << std::endl;	\
  } while(0)						

#define YOMOGI_PRINT_CONTAINER_ELEMENTS(container)			\
  do {									\
    std::cout << #container << " contains : { ";			\
    for(const auto & ite : container){					\
      std::cout << ite << " ";						\
    }									\
    std::cout << "}" << std::endl;					\
  } while(0)								

#define YOMOGI_PRINT_VECTOR_PROPERTY(v)		\
  do {						\
    YOMOGI_PRINT_DEBUG(v.empty());		\
    YOMOGI_PRINT_DEBUG(v.size());		\
    YOMOGI_PRINT_DEBUG(v.capacity());		\
    YOMOGI_PRINT_DEBUG(v.max_size());		\
    YOMOGI_PRINT_CONTAINER_ELEMENTS(v);		\
  }while(0)



#endif
