#!/bin/bash

export DD4hepExamplesINSTALL=`pwd`
source install/bin/thisOpticalTracker.sh;
prefix=install/examples/OpticalTracker

scripts/richsim.py \
  --numberOfEvents   10                         \
  --runType          run                        \
  --compactFile      $prefix/compact/pfrich.xml \
  --outputFile       sim.edm4hep.root           \
  --enableGun        --gun.energy "30*GeV"      \
  --gun.particle     "pi+"                      \
  --gun.thetaMin     "195.0*deg"                \
  --gun.thetaMax     "195.1*deg"                \
  --gun.distribution "cos(theta)"               \
  --part.userParticleHandler=''
