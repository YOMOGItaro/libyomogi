#ifndef OSTREAM_EXT_HPP
#define OSTREAM_EXT_HPP

namespace yomogi{
  namespace ostream_ext{
    template <char Separator = ',', typename T>
    std::ostream&
    each_output(
	std::ostream & os,
	T val
		)
    {
      os << val;

      return os;
    }
  
    
    template <char Separator = ',', typename T, typename ...ArgTypes>
    std::ostream&
    each_output(
	std::ostream & os,
	T val,
	ArgTypes... args
		)
    {
      os << val << Separator;
      
      return each_output<Separator>(os, args...);
    }


    template <char Separator, typename ...ArgTypes>
    std::ostream&
    dsv(
	std::ostream & os,
	ArgTypes... args
		)
    {
      //os << '';
      each_output<Separator>(os, args...);
      //os << ')';

      return os;
    }

  }
}
#endif
