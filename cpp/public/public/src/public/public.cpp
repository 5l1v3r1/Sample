// $B%X%C%@%U%!%$%k$N%$%s%/%k!<%I(B
// $B4{Dj$N%X%C%@(B
#include <iostream> // C++$BI8=`F~=PNO(B
// $BFH<+$N%X%C%@(B
#include "public.h" // $B%/%i%9(Bclass_public

// class_public$B$N%a%s%P$NDj5A(B.
// $B%a%s%P4X?t(Bprint_base()
void class_public::print_base(){ // class_base$B$N%a%s%P$r=PNO(B.

  // class_base$B$N%a%s%P$r=PNO(B.
  //private_variable_ = 1; // private$B$J$N$G%"%/%;%9IT2D(B.
  //private_function(); // private$B$J$N$G%"%/%;%9IT2D(B.
  protected_variable_ = 1; // protected$B$J$N$G%"%/%;%92D(B.
  std::cout << "protected_variable_ = " << protected_variable_ << std::endl; // protected$B$J$N$G%"%/%;%92D(B.
  protected_function(); // protected$B$J$N$G%"%/%;%92D(B.
  public_variable_ = 1; // public$B$J$N$G%"%/%;%92D(B.
  std::cout << "public_variable_ = " << public_variable_ << std::endl; // public$B$J$N$G%"%/%;%92D(B.
  public_function(); // public$B$J$N$G%"%/%;%92D(B.

}
