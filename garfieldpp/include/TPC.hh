#ifndef TPC_H
#define TPC_H

#include <iostream>
#include <vector>
#include <string>

#include <cmath>

#include "Garfield/GeometrySimple.hh"
#include "Garfield/SolidTube.hh"
#include "Garfield/Medium.hh"

#include "ComponentBmap.hh"

#include "TPCBase.hh"

class TPC: public Garfield::ComponentBmap, public TPCBase
{
public:
  TPC(double V_c=-5325., double V_a=2050., double V_f=-227.);

  std::vector<std::string> GetAnodeReadouts(){ return anodes;};
  std::vector<std::string> GetPadReadouts(){ return pads;};
  std::vector<std::string> GetOtherReadouts(){ return readouts;};

  void SetGas(Garfield::Medium *m);
  void SetVoltage(double &vc, double& vaw, double& vfw);

  void init();

  double CathodeVoltage, AnodeVoltage, FieldVoltage;
protected:
  std::vector<std::string> anodes, pads, readouts;
  Garfield::GeometrySimple geo;
  Garfield::Medium *medium;
  Garfield::SolidTube* chamber;
};

#endif

/* emacs
 * Local Variables:
 * tab-width: 8
 * c-basic-offset: 3
 * indent-tabs-mode: nil
 * End:
 */
