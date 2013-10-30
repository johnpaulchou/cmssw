#ifndef GEMTrackMatch_H
#define GEMTrackMatch_H

#include "DQMServices/Core/interface/DQMStore.h"
#include "DQMServices/Core/interface/MonitorElement.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"


#include "SimDataFormats/Track/interface/SimTrackContainer.h"

#include "Geometry/Records/interface/MuonGeometryRecord.h"
#include "Geometry/CommonDetUnit/interface/GeomDet.h"
#include "Geometry/GEMGeometry/interface/GEMGeometry.h"
#include "Geometry/GEMGeometry/interface/GEMEtaPartition.h"
#include "Geometry/GEMGeometry/interface/GEMEtaPartitionSpecs.h"

#include "Validation/MuonGEMDigis/interface/SimTrackMatchManager.h"


class GEMTrackMatch 
{
public:
  GEMTrackMatch(DQMStore* , std::string , edm::ParameterSet );
  ~GEMTrackMatch();
  void analyze(const edm::Event& e, const edm::EventSetup&);

  void buildLUT();
  std::pair<int,int> getClosestChambers(int region, float phi);
  bool isSimTrackGood(const SimTrack& );
  void setGeometry(const GEMGeometry* geom) { theGEMGeometry = geom; }

  TH1F** GetDgEta() { return dg_eta; }
 private:

  edm::ParameterSet cfg_;
  std::string simInputLabel_;
  DQMStore* dbe_; 
  const GEMGeometry* theGEMGeometry;   

  MonitorElement* theEff_eta_dg_l1;
  
  TH1F* track_eta;
  TH1F* track_phi;

  TH1F* dg_eta[4];


  TH1F* dg_sh_eta[4]; 


  TH1F* dg_phi[4];
  
  TH1F* dg_sh_phi[4]; 

  TH1F* pad_eta[3];

  TH1F* pad_phi[3];

  TH1F* pad_sh_eta[3]

  TH1F* pad_sh_phi[3];


  TH1F* copad_eta; 
  TH1F* copad_phi; 
  

  TH1F* copad_sh_eta;
  TH1F* copad_sh_phi;

  
  std::pair<std::vector<float>,std::vector<int> > positiveLUT_;
  std::pair<std::vector<float>,std::vector<int> > negativeLUT_;

  edm::Handle<edm::SimTrackContainer> sim_tracks;
  edm::Handle<edm::SimVertexContainer> sim_vertices;
  
  float minPt_;
  float radiusCenter_, chamberHeight_;


};

#endif
