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
// $Id: LXeTrajectory.hh 72349 2013-07-16 12:13:16Z gcosmo $
//
/// \file optical/LXe/include/LXeTrajectory.hh
/// \brief Definition of the LXeTrajectory class
//
#ifndef DriftLineTrajectory_h
#define DriftLineTrajectory_h 1

#include "G4Trajectory.hh"
#include "G4Allocator.hh"
#include "G4ios.hh"
#include "globals.hh"
#include "G4ParticleDefinition.hh"
#include "G4TrajectoryPoint.hh"
#include "G4Track.hh"
#include "G4Step.hh"
#include "G4SystemOfUnits.hh"

typedef std::vector<G4VTrajectoryPoint*> DriftLineTrajectoryPointContainer;

class DriftLineTrajectory : public G4Trajectory
{
  public:

    DriftLineTrajectory();
    DriftLineTrajectory(DriftLineTrajectory &);
    virtual ~DriftLineTrajectory();
    virtual void AppendStep(const G4Step*){}; 
    void AppendStep(G4ThreeVector pos, G4double t);
    inline void* operator new(size_t);
    inline void  operator delete(void*);
    inline int operator == (const DriftLineTrajectory& right) const
     { return (this==&right); }
    virtual int GetPointEntries() const
     { return fpPointsContainer->size(); };
    virtual G4VTrajectoryPoint* GetPoint(G4int i) const
     { return (*fpPointsContainer)[i]; };
    inline G4double GetCharge() const
   { return +2.*eplus; }
  private:
    DriftLineTrajectoryPointContainer* fpPointsContainer;
};

extern G4ThreadLocal G4Allocator<DriftLineTrajectory>* DriftLineTrajectoryAllocator;

inline void* DriftLineTrajectory::operator new(size_t)
{
  if(!DriftLineTrajectoryAllocator)
      DriftLineTrajectoryAllocator = new G4Allocator<DriftLineTrajectory>;
  return (void*)DriftLineTrajectoryAllocator->MallocSingle();
}

inline void DriftLineTrajectory::operator delete(void* aTrajectory)
{
  DriftLineTrajectoryAllocator->FreeSingle((DriftLineTrajectory*)aTrajectory);
}

#endif

/* emacs
 * Local Variables:
 * tab-width: 8
 * c-basic-offset: 3
 * indent-tabs-mode: nil
 * End:
 */
