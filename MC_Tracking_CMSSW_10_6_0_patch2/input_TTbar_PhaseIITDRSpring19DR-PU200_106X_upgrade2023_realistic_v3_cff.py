import FWCore.ParameterSet.Config as cms

# Input source
source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
"root://xrootd-cms.infn.it//store/mc/PhaseIITDRSpring19DR/TTbar_14TeV_TuneCP5_Pythia8/GEN-SIM-DIGI-RAW/PU200_106X_upgrade2023_realistic_v3_ext1-v3/60000/FFB5D0CA-208F-6040-A9BF-3F5354D0AA59.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIITDRSpring19DR/TTbar_14TeV_TuneCP5_Pythia8/GEN-SIM-DIGI-RAW/PU200_106X_upgrade2023_realistic_v3_ext1-v3/60000/FAD64ED8-12B6-8944-8A92-DB34B8302AD3.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIITDRSpring19DR/TTbar_14TeV_TuneCP5_Pythia8/GEN-SIM-DIGI-RAW/PU200_106X_upgrade2023_realistic_v3_ext1-v3/60000/FAA44C43-4F04-0A42-9555-7D37B2974302.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIITDRSpring19DR/TTbar_14TeV_TuneCP5_Pythia8/GEN-SIM-DIGI-RAW/PU200_106X_upgrade2023_realistic_v3_ext1-v3/60000/FAA44C43-4F04-0A42-9555-7D37B2974302.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIITDRSpring19DR/TTbar_14TeV_TuneCP5_Pythia8/GEN-SIM-DIGI-RAW/PU200_106X_upgrade2023_realistic_v3_ext1-v3/60000/FA8F143E-26A5-0D46-BFB5-BF6619A2B779.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIITDRSpring19DR/TTbar_14TeV_TuneCP5_Pythia8/GEN-SIM-DIGI-RAW/PU200_106X_upgrade2023_realistic_v3_ext1-v3/60000/F693A9AC-6484-5147-99B1-8F281C407BA5.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIITDRSpring19DR/TTbar_14TeV_TuneCP5_Pythia8/GEN-SIM-DIGI-RAW/PU200_106X_upgrade2023_realistic_v3_ext1-v3/60000/F5B6A85F-F39C-1A4A-9313-B0AE5E469F4A.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIITDRSpring19DR/TTbar_14TeV_TuneCP5_Pythia8/GEN-SIM-DIGI-RAW/PU200_106X_upgrade2023_realistic_v3_ext1-v3/60000/F0EA2FED-7FAB-2741-9862-443DE2B5752B.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIITDRSpring19DR/TTbar_14TeV_TuneCP5_Pythia8/GEN-SIM-DIGI-RAW/PU200_106X_upgrade2023_realistic_v3_ext1-v3/60000/F037A381-8FA4-EC45-9B30-7CDA025AEAE3.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIITDRSpring19DR/TTbar_14TeV_TuneCP5_Pythia8/GEN-SIM-DIGI-RAW/PU200_106X_upgrade2023_realistic_v3_ext1-v3/60000/EE49EB78-D071-0643-B158-A776C404E8DF.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIITDRSpring19DR/TTbar_14TeV_TuneCP5_Pythia8/GEN-SIM-DIGI-RAW/PU200_106X_upgrade2023_realistic_v3_ext1-v3/60000/ECB818B0-4351-774B-A035-FBDABD1CA90E.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIITDRSpring19DR/TTbar_14TeV_TuneCP5_Pythia8/GEN-SIM-DIGI-RAW/PU200_106X_upgrade2023_realistic_v3_ext1-v3/60000/EC9BDA84-4F7E-0646-B9EA-5D95EAE21AA4.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIITDRSpring19DR/TTbar_14TeV_TuneCP5_Pythia8/GEN-SIM-DIGI-RAW/PU200_106X_upgrade2023_realistic_v3_ext1-v3/60000/EC424AE8-76A8-5142-8111-640534C1EF7A.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIITDRSpring19DR/TTbar_14TeV_TuneCP5_Pythia8/GEN-SIM-DIGI-RAW/PU200_106X_upgrade2023_realistic_v3_ext1-v3/60000/EB1607A3-B053-1E42-B9C5-418657AD9E2A.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIITDRSpring19DR/TTbar_14TeV_TuneCP5_Pythia8/GEN-SIM-DIGI-RAW/PU200_106X_upgrade2023_realistic_v3_ext1-v3/60000/EADD0493-D560-BF4C-8BDE-52D2E29AE588.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIITDRSpring19DR/TTbar_14TeV_TuneCP5_Pythia8/GEN-SIM-DIGI-RAW/PU200_106X_upgrade2023_realistic_v3_ext1-v3/60000/E9F104F6-8E35-C041-A3C4-DE02C9B5EABE.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIITDRSpring19DR/TTbar_14TeV_TuneCP5_Pythia8/GEN-SIM-DIGI-RAW/PU200_106X_upgrade2023_realistic_v3_ext1-v3/60000/E7B49A7A-079E-8841-A9CA-438B041628F7.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIITDRSpring19DR/TTbar_14TeV_TuneCP5_Pythia8/GEN-SIM-DIGI-RAW/PU200_106X_upgrade2023_realistic_v3_ext1-v3/60000/E6E9D899-3EDE-FD44-A8DD-0211C5FEAF5F.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIITDRSpring19DR/TTbar_14TeV_TuneCP5_Pythia8/GEN-SIM-DIGI-RAW/PU200_106X_upgrade2023_realistic_v3_ext1-v3/60000/E48ABBC9-01D0-6B49-8919-32AADE090354.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIITDRSpring19DR/TTbar_14TeV_TuneCP5_Pythia8/GEN-SIM-DIGI-RAW/PU200_106X_upgrade2023_realistic_v3_ext1-v3/60000/E28C7B13-55CC-0646-BAFD-4F0085B8AC81.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIITDRSpring19DR/TTbar_14TeV_TuneCP5_Pythia8/GEN-SIM-DIGI-RAW/PU200_106X_upgrade2023_realistic_v3_ext1-v3/60000/E21BE6B8-F362-B140-A049-56619C42C050.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIITDRSpring19DR/TTbar_14TeV_TuneCP5_Pythia8/GEN-SIM-DIGI-RAW/PU200_106X_upgrade2023_realistic_v3_ext1-v3/60000/E20E7D32-64C7-F34F-A35F-B6043C5B70CA.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIITDRSpring19DR/TTbar_14TeV_TuneCP5_Pythia8/GEN-SIM-DIGI-RAW/PU200_106X_upgrade2023_realistic_v3_ext1-v3/60000/E0AA2631-0C70-2649-B703-6F95E8F1547A.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIITDRSpring19DR/TTbar_14TeV_TuneCP5_Pythia8/GEN-SIM-DIGI-RAW/PU200_106X_upgrade2023_realistic_v3_ext1-v3/60000/DED805CC-B940-C849-9922-B316F6ABB754.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIITDRSpring19DR/TTbar_14TeV_TuneCP5_Pythia8/GEN-SIM-DIGI-RAW/PU200_106X_upgrade2023_realistic_v3_ext1-v3/60000/D7E64507-2006-7C4E-A9D8-97AA44D12419.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIITDRSpring19DR/TTbar_14TeV_TuneCP5_Pythia8/GEN-SIM-DIGI-RAW/PU200_106X_upgrade2023_realistic_v3_ext1-v3/60000/D7BC8491-AB79-8E49-90DC-B7EA2F30E307.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIITDRSpring19DR/TTbar_14TeV_TuneCP5_Pythia8/GEN-SIM-DIGI-RAW/PU200_106X_upgrade2023_realistic_v3_ext1-v3/60000/D3628B26-FCAC-C741-94FD-5B6764835AEE.root"    ),
    secondaryFileNames = cms.untracked.vstring()
)

