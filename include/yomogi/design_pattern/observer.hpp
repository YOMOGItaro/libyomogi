#ifndef YOMOGI_DESIGN_PATTERN_OBSERVER_HPP
#define YOMOGI_DESIGN_PATTERN_OBSERVER_HPP

#include <list>


namespace yomogi{
namespace design_pattern{

template<
  typename ObserveeType,
  typename ObserverType
  >
class observee;


template<
  typename ObserverType,
  typename ObserveeType
  >
class observer
{
  // t
public:
  typedef ObserverType observer_type;
  typedef observee<ObserveeType, ObserverType> observee_type;

  // m
private:
  observer_type instance_;
  observee_type * p_subject_;

  // c
public:
  template<typename ... ArgTypes>
  observer(
      observee_type * p_subject,
      ArgTypes ... Args
	   )
    : instance_( Args... )
    , p_subject_( p_subject )
  {
    p_subject_->add_observer( this );
  }

  // d
public:
  virtual
  ~observer()
  {
    p_subject_->rm_observer( this );
    // p_subject_ は解放しない
  }
  
  // s
public:
  void set_observee( observee_type * observee )
  {
    p_subject_ = observee;
  }

  // m f
public:
  inline void update()
  {
    instance_.update();
  }
};


template<
  typename ObserveeType,
  typename ... ObserverTypes
  >
class observee
{
  // t
public:
  typedef ObserveeType observee_type;
  typedef observer<ObserverType, ObserveeType> observer_type;
  typedef std::list<observer_type *> observer_ptrs_type;

  // m
private:
  observee_type instance_;
  observer_ptrs_type observer_ptrs_;

  // c
public:
  template<typename ... ArgTypes>
  observee( ArgTypes ... Args )
    : instance_( Args... )
  {
    
  }

  // pub m f
public:
  template<typename ... ArgTypes>
  void update( ArgTypes ... Args )
  {
    instance_.update( Args... );		// これはなんか違うかも instance から update を呼び出せない
    update_observers();
  }

  void
  add_observer( observer_type *  p_observer )
  {
    observer_ptrs_.push_back( p_observer );
  }

  void
  rm_observer( observer_type * p_observer )
  {
    observer_ptrs_.remove( p_observer );
  }
  
  // priv m f
private:
  void update_observers()
  {
    for( const auto & o : observer_ptrs_ ){
      o->update();
    }
  }
};
  
} // namespace design_pattern
} // namespace yomogi

#endif













