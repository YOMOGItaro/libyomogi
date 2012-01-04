#ifndef YOMOGI_DESIGN_PATTERN_SINGLETON_HPP
#define YOMOGI_DESIGN_PATTERN_SINGLETON_HPP

#include <cassert>


namespace yomogi{
namespace design_pattern{

template <typename InstanceType>
class singleton
{
  // t
public:
  typedef InstanceType instance_type;

  // m
private:
  static instance_type * instance_ptr_;

  // c
private:
  singleton()
  { /* NTD */ }

  // d
public:
  virtual
  ~singleton()
  {
    delete instance_ptr_;
    instance_ptr_ = nullptr;
  }
  
  // g
public:
  static
  instance_type *
  instance()
  {
    assert( instance_ptr_ != nullptr );
    return instance_ptr_;
  }

  // m f
  template <typename ... ArgTypes>
  static
  void
  create( ArgTypes ... args )
  {
    if( ! instance_ptr_ ){
      instance_ptr_ = new instance_type( args... );
    }
  }

  static
  void
  destroy()
  {
    delete instance_ptr_;
    instance_ptr_ = nullptr;
  }
};

template <typename InstanceType>
typename singleton<InstanceType>::instance_type *
singleton<InstanceType>::instance_ptr_ = nullptr;

} // namespace design_pattern
} // namespace yomogi

#endif










