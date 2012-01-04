#include <iostream>
#include <yomogi/design_pattern/singleton.hpp>

namespace sample{

namespace detail{
template <typename ValueType>
class SampleClassDetail
{
  // p t
public:
  typedef ValueType value_type;

  // m
private:
  const value_type val_;

  // c
public:
  SampleClassDetail()
    :val_( 2 )
  { }

  SampleClassDetail( value_type val )
    :val_( val )
  { }

  // g
  inline
  const
  value_type &
  get_val()
    const
  {
    return val_;
  }
};
} // namespace detail

template <typename T>
struct SampleClass{
  typedef yomogi::design_pattern::singleton< sample::detail::SampleClassDetail<T> > type;
};

} // namespace sample


int main()
{
  typedef typename sample::SampleClass<int>::type sc;
  
  sc::create();
  std::cout << sc::instance()->get_val() << std::endl; // OK
  sc::destroy();
  
  sc::create( 4 );
  std::cout << sc::instance()->get_val() << std::endl; // OK

  sc::create( 5 );
  std::cout << sc::instance()->get_val() << std::endl; // destroy されていないので変更が反映されない。
  sc::destroy();
  
  return 0;
}
