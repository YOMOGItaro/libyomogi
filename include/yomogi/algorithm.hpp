#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <boost/range/counting_range.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/algorithm/for_each.hpp>



namespace yomogi{
  template
  <typename Function>
  inline
  void
  countup_each(
      const size_t begin,
      const size_t end,
      const Function & func
	)
  {
    boost::for_each(boost::counting_range(begin, end), func);
  }

  template
  <typename Function>
  inline
  void
  countdown_each(
      const size_t begin,
      const size_t end,
      const Function & func
	)
  {
    boost::for_each(boost::irange(begin, end, -1), func);
    func(end);
  }

  template
  <typename Function>
  inline
  void
  times(
      const size_t count,
      const Function & func
	)
  {
    countup_each(0, count, func);
  }

  template <typename FunctionType>
  inline void
  twice(const FunctionType & func)
  {
    func();
    func();
  }  
}

#endif










