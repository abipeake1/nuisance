#!/usr/bin/env bash
#script to run comparisons in nuiscance
set -e
echo "Card file is $1"
#echo "ROOT file produced by nuiscomp is $2"
echo "Sample used is $2"
echo "PDF of plots $3"
nuiscomp -c $1 -o "$2.root"
#nuiscomp -c microboone_aparameters_newtune.xml -o newtune.root
nuisplot -s $2 -i "$2.root"  -o "$2.pdf" --chi2 -t "MicroBooNE 1Mu1p using tune G18_10a_02_11b"