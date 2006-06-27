#ifndef L1GCTMAP_H
#define L1GCTMAP_H

#include "DataFormats/L1CaloTrigger/interface/L1CaloRegion.h"

/*!
 * \author Jim Brooke
 * \date May 2006
 */

/*! \class L1GctMap
 * \brief Get position information from Region, jet, EM objects
 *
 * This is a singleton, which breaks coding rules. Will be converted
 * to appropriate mechanism once we know what that is!
 *
 */


class L1GctMap {
 public:

  static const unsigned N_RGN_ETA;
  static const unsigned N_RGN_PHI;

 public:
  
  /// destructor
  ~L1GctMap();

  /// return the map
  static L1GctMap* getMap() { 
    if (m_instance==0) { m_instance = new L1GctMap(); }
    return m_instance;
  }
 
  /// get the RCT crate number
  unsigned rctCrate(L1CaloRegion r);

  /// get the SC number
  unsigned sourceCard(L1CaloRegion r);

  /// get the SC type
  unsigned sourceCardType(L1CaloRegion r);

  /// get the SC input
  unsigned sourceCardOutput(L1CaloRegion r);

  /// get the eta index within an RCT crate
  unsigned rctEta(L1CaloRegion r);

  /// get the phi index within an RCT crate
  unsigned rctPhi(L1CaloRegion r);

  /// get the global eta index
  unsigned eta(L1CaloRegion r);

  /// get the global phi index
  unsigned phi(L1CaloRegion r);

  // get physical eta 
  // double eta(L1CaloRegion r);

  // get physical eta 
  //  double phi(L1CaloRegion r);

  /// get ID from eta, phi indices
  unsigned id(unsigned ieta, unsigned iphi);

  /// get ID from position in system
  unsigned id(unsigned rctCrate, unsigned scType, unsigned in); 

  /// convert phi from rctCrate/jetFinder local to global coordinates
  unsigned globalPhi(unsigned iphi, unsigned jfphi);

  /// convert eta from rctCrate/jetFinder local to global coordinates
  unsigned globalEta(unsigned ieta, unsigned wheel);

  /// Conversion routines
  /// local eta from source card type and output
  unsigned rctEta(unsigned scType, unsigned in);

  /// local phi from source card type and output
  unsigned rctPhi(unsigned scType, unsigned in);

  /// source card type from local eta and phi
  unsigned sourceCardType(unsigned localEta, unsigned localPhi);

  /// source card number from local eta and phi
  unsigned sourceCardOutput(unsigned localEta, unsigned localPhi);

 private:        // methods

  L1GctMap();    // constructor, this is a singleton

 private:        // data

  static L1GctMap * m_instance;  // the instance, this is a singleton


};

#endif
