#==========================================================================
#  AIDA Detector description implementation 
#--------------------------------------------------------------------------
# Copyright (C) Organisation europeenne pour la Recherche nucleaire (CERN)
# All rights reserved.
#
# For the licensing terms see $DD4hepINSTALL/LICENSE.
# For the list of contributors see $DD4hepINSTALL/doc/CREDITS.
#
#==========================================================================
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

IF(NOT TARGET DD4hep::DDCore)
  find_package ( DD4hep REQUIRED )
  include ( ${DD4hep_DIR}/cmake/DD4hep.cmake )
  include ( ${DD4hep_DIR}/cmake/DD4hepBuild.cmake )
  dd4hep_configure_output()
ENDIF()

dd4hep_set_compiler_flags()
#==========================================================================
dd4hep_print("|++> OpticalTracker: ROOT version: ${ROOT_VERSION}")

if(NOT ${ROOT_VERSION} VERSION_GREATER_EQUAL 6.18.00)
  dd4hep_print("|++> Not building optical tracker test")
  return()
endif()
dd4hep_print("|++> Building optical tracker test")

#--------------------------------------------------------------------------
dd4hep_configure_output()

set(OpticalTracker_INSTALL ${CMAKE_INSTALL_PREFIX}/examples/OpticalTracker)
dd4hep_add_plugin(OpticalTrackerExample SOURCES src/*.cpp
  USES DD4hep::DDCore DD4hep::DDCond ROOT::Core ROOT::Geom ROOT::GenVector ROOT::MathCore)
install(TARGETS OpticalTrackerExample LIBRARY DESTINATION lib)
install(DIRECTORY compact scripts DESTINATION ${OpticalTracker_INSTALL} )
dd4hep_configure_scripts( OpticalTracker DEFAULT_SETUP WITH_TESTS)

# TODO
# ---Testing: npsim
#  dd4hep_add_test_reg( Simulate_npsim
#    COMMAND    "${CMAKE_INSTALL_PREFIX}/bin/run_test_OpticalTracker.sh"
#    EXEC_ARGS ${OpticalTracker_INSTALL}/scripts/npsim.py
#      --numberOfEvents   10
#      --runType          run
#      --compactFile      $prefix/compact/pfrich.xml
#      --outputFile       sim.edm4hep.root
#      --enableGun        --gun.energy "30*GeV"
#      --gun.particle     "pi+"
#      --gun.thetaMin     "195.0*deg"
#      --gun.thetaMax     "195.1*deg"
#      --gun.distribution "cos(theta)"
#      --part.userParticleHandler=''
#    REGEX_PASS "."
#    REGEX_FAIL "TODO"
#    )
