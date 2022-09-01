#!/bin/bash

export DD4hepExamplesINSTALL=`pwd`
source install/bin/thisOpticalTracker.sh
prefix=install/examples/OpticalTracker

outputFile=geo.root
compactFile=$prefix/compact/pfrich.xml
dd_web_display --export -o $outputFile $compactFile
printf "\nproduced $outputFile\n -> open it with jsroot to view the geometry\n\n"
