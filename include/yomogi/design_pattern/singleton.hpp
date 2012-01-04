#ifndef YOMOGI_DESIGN_PATTERN_SINGLETON_HPP
#define YOMOGI_DESIGN_PATTERN_SINGLETON_HPP

namespace yomogi{
namespace design_pattern{

template <typename InstanceType>
class singleton
{
public:
  typedef InstanceType instance_type;

private:
  static instance_type * instance_ptr_;

private:
  singleton()
  { /* NI */ }
  
public:
  static
  instance_type *
  instance()
  {
    return instance_ptr_;
  }

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
    instance_ptr_ = 0;
  }
};

template <typename InstanceType>
typename singleton<InstanceType>::instance_type *
singleton<InstanceType>::instance_ptr_ = 0;

} // namespace design_pattern
} // namespace yomogi

#endif










