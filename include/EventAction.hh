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
/// \file include/EventAction.hh
/// \brief Definition of the EventAction class
//
//
// $Id$
//
// 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#ifndef EventAction_h
#define EventAction_h 1

#include "G4UserEventAction.hh"
#include "G4ThreeVector.hh"

#include "TPCHit.hh"
#include "ChamberHit.hh"
#include "AWHit.hh"

#include <vector>
#include <map>

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class RunAction;
class TClonesArray;
class EventAction : public G4UserEventAction
{
public:
  EventAction( RunAction* );
  virtual ~EventAction();

  void  BeginOfEventAction(const G4Event*);
  void    EndOfEventAction(const G4Event*);

  inline G4int GetEvtNb() { return fEvtNb; }
    
  void AddTPCHits(TPCHitsCollection*);
  void FillHisto(TPCHitsCollection*);

  void AddChamberHits(ChamberHitsCollection* CHC);
  void AddAWhits(AWHitsCollection* AWHC);

//  void AddSignals(AWHitsCollection* AWHC);
  void AddSignals(const std::map<uint,std::vector<int>*>* anodes, 
		  const std::map<std::pair<int,int>,std::vector<int>*>* pads,
		  G4String& model_name);
private:
  G4int fPrintModulo;
  RunAction* fRunAction;
  G4int fEvtNb;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

    

/* emacs
 * Local Variables:
 * tab-width: 8
 * c-basic-offset: 3
 * indent-tabs-mode: nil
 * End:
 */
