//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//

#ifndef TPCSD_h
#define TPCSD_h 1

#include "G4VSensitiveDetector.hh"
#include "TPCHit.hh"
#include "ChamberHit.hh"
#include "AWHit.hh"

//class G4Step;
class G4HCofThisEvent;
class G4TouchableHistory;
class TPCSD : public G4VSensitiveDetector
{
public:
  TPCSD(G4String name);
  ~TPCSD();
  
  virtual void Initialize(G4HCofThisEvent *HCE);
  virtual G4bool ProcessHits(G4Step* aStep, G4TouchableHistory*);
  //  virtual void EndOfEvent(G4HCofThisEvent *HCE);

  inline void InsertChamberHit(ChamberHit* hit) {ChamberCollection->insert(hit); };
  void InsertAWHit(AWHit* hit) {AWCollection->insert(hit); };
  //inline int InsertAWHit(AWHit* hit) {AWCollection->insert(hit); return AWCollection->entries();};
  
private:
  TPCHitsCollection *TPCCollection;
  ChamberHitsCollection *ChamberCollection;
  AWHitsCollection *AWCollection;
};

#endif

/* emacs
 * Local Variables:
 * tab-width: 8
 * c-basic-offset: 3
 * indent-tabs-mode: nil
 * End:
 */
