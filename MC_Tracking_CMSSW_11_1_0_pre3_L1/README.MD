```
cmsrel CMSSW_11_1_0_pre3
cd CMSSW_11_1_0_pre3/src/
git cms-merge-topic cmantill:l1trackseeds
scram b -j 10
git clone https://github.com/cmantill/CMS_HLT_Phase2_Tracking.git
cd CMS_HLT_Phase2_Tracking/MC_Tracking_CMSSW_11_1_0_pre3_L1/
```
Copy `step2.root`:
``
cp /afs/cern.ch/user/c/cmantill/work/public/hlttrack/CMSSW_11_1_0_pre3/src/step2.root .
```

Run step3:
```
cmsRun step3_RAW2DIGI_RECO_VALIDATION_DQM_v2.py 
```