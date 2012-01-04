#ifndef FUNCTION_HPP
#define FUNCTION_HPP

namespace yomogi{
namespace function{

template <unsigned int PeriodValue,
	  typename FunctionType>
class periodic
{
  static constexpr unsigned int period = PeriodValue;

public:
  periodic(FunctionType & func)
    : func_(func)
    , time_(0)     
  {
    
  }
  
  void
  operator()()
  {
    ++time_;
    if( time_ >= period ){
      time_ = 0;
      func_();
    }
  }

private:
  FunctionType & func_;
  size_t time_;

};

} // namespace 
} // namespace yomogi



#endif
