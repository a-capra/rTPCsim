#ifndef GasModelParameters_hh
#define GasModelParameters_hh

#include "G4String.hh"
#include <map>

class HeedInterfaceModel;
class HeedOnlyModel;
class GasModelParametersMessenger;
class G4String;

typedef std::pair<double, double> EnergyRange_keV;
typedef std::multimap<const G4String, EnergyRange_keV> MapParticlesEnergy;

class GasModelParameters{
public:
	
  GasModelParameters();
  ~GasModelParameters();
  
  void AddParticleNameHeedOnly(const G4String particleName,double ekin_min_keV,double ekin_max_keV);
  void AddParticleNameHeedInterface(const G4String particleName,double ekin_min_keV,double ekin_max_keV);

  /*Getters and Setters*/

  //Name of the Magboltz file to be used (if needed)
  inline void SetGasFile(G4String _gasFile)         { gasFile = _gasFile; }
  inline G4String GetGasFile()               { return gasFile; }
  //Name of the Ion mobility file (if needed)
  inline void SetIonMobilityFile(G4String _ionMobFile) { ionMobFile = _ionMobFile; }
  inline G4String GetIonMobilityFile()       { return ionMobFile; }

  // Determines if the electrons are drifted, 
  // or only primary ionization is simulated
  inline void SetDriftElectrons(G4bool b)  { driftElectrons = b; }
  inline bool GetDriftElectrons()          { return driftElectrons; }
  inline void SetCreateAvalancheMC(bool b) { createAval=b; }
  inline bool GetCreateAvalancheMC()       { return createAval; }

  inline void SetDriftRKF(G4bool b)        { driftRKF=b; }
  inline bool GetDriftRKF()                { return driftRKF; }
  inline void SetTrackMicroscopic(G4bool b){ trackMicro=b; }
  inline bool GetTrackMicroscopic()        { return trackMicro; }

  inline void SetGenerateSignals(G4bool b) { generateSignals=b; }
  inline bool GetGenerateSignals()         { return generateSignals; }
  inline void SetAnodeNoiseLevel(double v) { awnoise=v; }
  inline double GetAnodeNoiseLevel()       { return awnoise; }
  inline void SetPadNoiseLevel(double v)   { pdnoise=v; }
  inline double GetPadNoiseLevel()         { return pdnoise; }

  inline void SetVisualizeChamber(bool b) { fVisualizeChamber = b; }
  inline bool GetVisualizeChamber()       { return fVisualizeChamber; }
  inline void SetVisualizeSignals(bool b) { fVisualizeSignal = b; }
  inline bool GetVisualizeSignals()       { return fVisualizeSignal; }
  inline void SetVisualizeField(bool b)   { fVisualizeField = b; }
  inline bool GetVisualizeField()         { return fVisualizeField; }

  inline void SetVoltageAnode(G4double v)   { vAnode = v; }
  inline double GetVoltageAnode()           { return vAnode; }
  inline void SetVoltageCathode(G4double v) { vCathode = v; }
  inline double GetVoltageCathode()         { return vCathode; }
  inline void SetVoltageField(G4double v)   { vField = v; }
  inline double GetVoltageField()           { return vField; }
    
  inline MapParticlesEnergy GetParticleNamesHeedOnly()
  { return fMapParticlesEnergyHeedOnly; }
  inline MapParticlesEnergy GetParticleNamesHeedInterface()
  { return fMapParticlesEnergyHeedInterface; }
	
private:
  GasModelParametersMessenger* fMessenger;
  MapParticlesEnergy fMapParticlesEnergyHeedOnly;
  MapParticlesEnergy fMapParticlesEnergyHeedInterface;
    
  G4String gasFile;
  G4String ionMobFile;
    
  bool driftElectrons;
  bool createAval;

  bool driftRKF;
  bool trackMicro;

  bool generateSignals;
  double awnoise;
  double pdnoise;

  bool fVisualizeChamber;
  bool fVisualizeSignal;
  bool fVisualizeField;
    
  double vAnode;
  double vCathode;
  double vField;
};

#endif

/* emacs
 * Local Variables:
 * tab-width: 8
 * c-basic-offset: 3
 * indent-tabs-mode: nil
 * End:
 */
