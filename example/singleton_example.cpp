#include <typeinfo>
#include <iostream>
#include <yomogi/design_pattern/singleton.hpp>

namespace sample{

namespace detail{

namespace {

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

  SampleClassDetail( value_type val1 , value_type val2)
    :val_( val1 + val2 )
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

  void *
  operator new(size_t size)
  {
    char * pMem = ( char * )malloc( size );

    // std::cout << std::type_info(size_t) << std::endl;
    std::cout << typeid( SampleClassDetail ).name() << std::endl;
    
    return pMem;
  }

};

} // namespace 
} // namespace detail


// ****************************************************************************************************
// テンプレートエイリアスは gcc4.7 から
// template <typename T>
// using SampleClass = yomogi::design_pattern::singleton< detail::SampleClassDetail<T> >;
//
// タイプジェネレータだと type が残ってかっこ悪い
// template <typename T>
// struct SampleClass{
//   typedef yomogi::design_pattern::singleton< sample::detail::SampleClassDetail<T> > type;
// };
//
// これで我慢
template <typename T>
class SampleClass
  : public yomogi::design_pattern::singleton< detail::SampleClassDetail<T> >
{};
//
// ^ だったら最初から継承しろよ
// class SampleClass : public yomogi::design_pattern::singleton の方がきれいそう。
// ****************************************************************************************************

} // namespace sample



int main()
{
  {
    // typedef typename sample::SampleClass<int>::type sci;
    // typedef yomogi::design_pattern::singleton< sample::detail::SampleClassDetail<int> > sci;
    typedef sample::SampleClass<int> sci;

    sci::create();
    std::cout << sci::instance()->get_val() << std::endl; // OK
    sci::destroy();

    const auto & hoge = sci::instance();

    sci::create( 4 );
    std::cout << sci::instance()->get_val() << std::endl; // OK
    sci::destroy();
  
    sci::create( 2, 3 );
    std::cout << sci::instance()->get_val() << std::endl; // OK variadic template すごい

    sci::create( 6 );
    std::cout << sci::instance()->get_val() << std::endl; // destroy されていないので変更が反映されない。
  }

  typedef sample::SampleClass<int> sci;

  sci::create( 7 );
  std::cout << sci::instance()->get_val() << std::endl; // スコープから抜けても destroy されてないと見れない

  typedef sample::SampleClass<char> scc;
  scc::create( 'a' );
  std::cout << scc::instance()->get_val() << std::endl; // 別の型なら関係なく見れる。
  scc::destroy();
  sci::destroy();

  scc::instance();		// create されてないときは見えない
  
  return 0;
}
