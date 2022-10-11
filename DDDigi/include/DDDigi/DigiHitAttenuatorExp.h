//==========================================================================
//  AIDA Detector description implementation 
//--------------------------------------------------------------------------
// Copyright (C) Organisation europeenne pour la Recherche nucleaire (CERN)
// All rights reserved.
//
// For the licensing terms see $DD4hepINSTALL/LICENSE.
// For the list of contributors see $DD4hepINSTALL/doc/CREDITS.
//
// Author     : M.Frank
//
//==========================================================================
#ifndef DDDIGI_DIGIHITATTENUATOREXP_H
#define DDDIGI_DIGIHITATTENUATOREXP_H

// Framework include files
#include <DDDigi/DigiEventAction.h>


/// Namespace for the AIDA detector description toolkit
namespace dd4hep {

  /// Namespace for the Digitization part of the AIDA detector description toolkit
  namespace digi {

    /// Default base class for all Digitizer actions and derivates thereof.
    /**
     *  This is a utility class supporting properties, output and access to
     *  event and run objects through the context.
     *
     *  \author  M.Frank
     *  \version 1.0
     *  \ingroup DD4HEP_SIMULATION
     */
    class DigiHitAttenuatorExp : public DigiEventAction   {
    protected:
      /// Implementation declaration
      class internals_t;
      /// Reference to the actual implementation
      std::unique_ptr<internals_t> internals;

    protected:
      /// Define standard assignments and constructors
      DDDIGI_DEFINE_ACTION_CONSTRUCTORS(DigiHitAttenuatorExp);

      /// Default destructor
      virtual ~DigiHitAttenuatorExp();

    public:
      /// Standard constructor
      DigiHitAttenuatorExp(const DigiKernel& kernel, const std::string& nam);
      /// Main functional callback
      virtual void execute(DigiContext& context)  const;
    };
  }    // End namespace digi
}      // End namespace dd4hep
#endif // DDDIGI_DIGIHITATTENUATOREXP_H
