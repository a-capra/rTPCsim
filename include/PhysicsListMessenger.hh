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
// $Id: PhysicsListMessenger.hh,v 1.3 2006-06-29 16:57:52 gunter Exp $
// GEANT4 tag $Name: not supported by cvs2svn $
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#ifndef PhysicsListMessenger_h
#define PhysicsListMessenger_h 1

#include "G4SystemOfUnits.hh"
#include "G4UImessenger.hh"

#include "G4UIdirectory.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithADouble.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithABool.hh"
/*! \class PhysicsListMessenger*/
/*! class derived from G4UImessenger*/
/*! taken from an example*/

class G4UIcommand;
class PhysicsList;
class G4UIcmdWithoutParameter;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class PhysicsListMessenger : public G4UImessenger {
 public:
  PhysicsListMessenger(PhysicsList *);
  ~PhysicsListMessenger();

  void SetNewValue(G4UIcommand *, G4String);

 private:
  PhysicsList *pPhysicsList;

  G4UIdirectory* physDir;
  G4UIcmdWithADoubleAndUnit *gammaCutCmd;
  G4UIcmdWithADoubleAndUnit *electCutCmd;
  G4UIcmdWithADoubleAndUnit *protoCutCmd;
  G4UIcmdWithADoubleAndUnit *allCutCmd;
  G4UIcmdWithAString *pListCmd;
  G4UIcmdWithADoubleAndUnit *lowLimitECmd;
  G4UIcmdWithoutParameter* addParamCmd;
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
