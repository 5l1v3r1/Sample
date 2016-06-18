// 独自のヘッダ
#include "protected.h" // クラスclass_protected

// class_publicのメンバの定義.
// メンバ関数print_base()
void class_protected::print_base(){ // class_baseのメンバを出力.

  // class_baseのメンバを出力.
  //private_variable_ = 1; // privateなのでアクセス不可.
  //private_function(); // privateなのでアクセス不可.
  protected_variable_ = 1; // protectedなのでアクセス可.
  std::cout << "protected_variable_ = " << protected_variable_ << std::endl; // protectedなのでアクセス可.
  protected_function(); // protectedなのでアクセス可.
  public_variable_ = 1; // publicなのでアクセス可.
  std::cout << "public_variable_ = " << public_variable_ << std::endl; // publicなのでアクセス可.
  public_function(); // publicなのでアクセス可.

}
