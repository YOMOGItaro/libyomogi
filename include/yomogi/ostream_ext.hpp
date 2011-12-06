#ifndef OSTREAM_EXT_HPP
#define OSTREAM_EXT_HPP

  template<typename T>
  std::ostream&
  ostream_each(
      std::ostream & os,
      T val
      	       )
  {
    os << val;

    return os;
  }
  
  
  template <typename T, typename ...ArgTypes>
  std::ostream&
  ostream_each(
      std::ostream & os,
      T val,
      ArgTypes... args
	       )
  {
    os << val;

    return ostream_each(os, args...);
  }


#endif
