/* $B%X%C%@%U%!%$%k$N%$%s%/%k!<%I(B */
#include <stdio.h> /* $BI8=`F~=PNO(B */
#include <time.h> /* UNIX$B;~4V(B */

/* main$B4X?t$NDj5A(B */
int main(void){

  /* $BJQ?t$N@k8@(B */
  time_t t; /* $B<hF@$7$?(BUNIX$B;~4V$r3JG<$7$F$*$/(Btime_t$B7?JQ?t(Bt. */

  /* $B8=:_$N(BUNIX$B;~4V$N<hF@$H=PNO(B. */
  t = time(NULL); /* time$B$N0z?t$K(BNULL$B$r;XDj$9$k$H(B, $BLa$jCM$H$7$F8=:_$N(BUNIX$B;~4V$,JV$k(B. */
  printf("UNIX Time: %ld\n", t); /* printf$B$G(Bt$B$r(B"%ld"$B$G=PNO(B. */

  /* $B%W%m%0%i%`$N=*N;(B */
  return 0;

}
