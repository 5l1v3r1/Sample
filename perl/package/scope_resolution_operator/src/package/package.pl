#!/usr/bin/perl

# $B%Q%C%1!<%8(BPackageA
{
  package PackageA; # $B%Q%C%1!<%8(BPackageA$B$r@k8@(B.
  $var = 10;
  $str = "AAA";
}

# $B%Q%C%1!<%8(BPackageB
{
  package PackageB; # $B%Q%C%1!<%8(BPackageB$B$r@k8@(B.
  $var = 20;
  $str = "BBB";
}

# main$B%Q%C%1!<%8(B
$var = 30;
$str = "CCC";

# $B=PNO(B
print $PackageA::var."\n"; # PackageA$B$N(B$var.
print $PackageA::str."\n"; # PackageA$B$N(B$str.
print $PackageB::var."\n"; # PackageB$B$N(B$var.
print $PackageB::str."\n"; # PackageB$B$N(B$str.
print $main::var."\n"; # main$B$N(B$var.
print $main::str."\n"; # main$B$N(B$str.

# $BBeF~(B
$PackageA::str = "XXX"; # PackageA$B$N(B$str$B$K(B"XXX"$B$rBeF~(B.
$PackageB::var = 100; # PackageB$B$N(B$var$B$K(B100$B$rBeF~(B.

# $B=PNO(B
print "\n"; # $B2~9T(B.
print $PackageA::var."\n"; # PackageA$B$N(B$var.
print $PackageA::str."\n"; # PackageA$B$N(B$str.
print $PackageB::var."\n"; # PackageB$B$N(B$var.
print $PackageB::str."\n"; # PackageB$B$N(B$str.
print $main::var."\n"; # main$B$N(B$var.
print $main::str."\n"; # main$B$N(B$str.
