#include <iostream>

#include <yomogi/design_pattern/observer.hpp>


template<unsigned int PeriodValue>
class PeriodicSignal
{
  static constexpr unsigned int period_ = PeriodValue;
  unsigned int count_;

public:
  PeriodicSignal()
    : count_( 0 )
  {}

  inline static unsigned int period(){ return period_; }
  
  void update()
  {
    ++ count_;
    std::cout << "It's time to update!" << std::endl;
    if( count_ >= period_ ){
      count_ = 0;
      std::cout << "It's time to period!" << std::endl;
      // あれ!? 呼び出せない・・・,継承じゃないとダメかも
      // update_observers();
    }
  }
};

class ASlot
{
public :
  void update(){ std::cout << "A updated!" << std::endl; }
};

class BSlot
{
public:
  void update(){ std::cout << "B updated!" << std::endl; }
};

typedef PeriodicSignal<10> ps_ten_type;
typedef yomogi::design_pattern::observer<ASlot, ps_ten_type> as_observer_type;
typedef yomogi::design_pattern::observer<BSlot, ps_ten_type> bs_observer_type;
typedef yomogi::design_pattern::observee<ps_ten_type> ps_observee_type;



int main()
{
  ps_observee_type ps_observee{};
  as_observer_type as_observer( &ps_observee );
  bs_observer_type bs_observer( &ps_observee );

  for(size_t ite = 0; ite <= ps_ten_type::period(); ++ite){
    ps_observee.update();
  }
  
  return 0;
}








