#!/bin/sh                                                                       
# Author: Tao Luo

if [ $# -ne 2 ]; then
echo "Usage: $0 rootfilename variablenameinTree";
echo "eg: $0 kspi0.root bsbc";
exit 1;
fi

root -l 'dumptree.C+("'$1'","'$2'")'
#cat tmp.txt | awk '{if($4=="0") print $6}' > $2.txt
#to make sure the numbers are in normal format, not in scientific notation
cat tmp.txt | awk '{if($4=="0")  print sprintf("%.9f", $6);}' > $2.txt
rm -rf tmp.txt


