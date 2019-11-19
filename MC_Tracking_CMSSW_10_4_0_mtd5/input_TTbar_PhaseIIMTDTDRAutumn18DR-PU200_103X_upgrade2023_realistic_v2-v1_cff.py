import FWCore.ParameterSet.Config as cms

# input_TTbar_PhaseIIMTDTDRAutumn18DR-PU200_103X_upgrade2023_realistic_v2-v1_cff
# Input source
source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
"root://xrootd-cms.infn.it//store/mc/PhaseIIMTDTDRAutumn18DR/TTbar_14TeV_TuneCP5_Pythia8/FEVT/PU200_103X_upgrade2023_realistic_v2-v1/80000/9F184E96-958D-774B-8242-CEB1F61F7505.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIIMTDTDRAutumn18DR/TTbar_14TeV_TuneCP5_Pythia8/FEVT/PU200_103X_upgrade2023_realistic_v2-v1/80000/A56961F4-A999-F041-87EC-B0B3AE7BC451.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIIMTDTDRAutumn18DR/TTbar_14TeV_TuneCP5_Pythia8/FEVT/PU200_103X_upgrade2023_realistic_v2-v1/80000/1A45B5C4-5E39-2C40-878A-4954D178D762.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIIMTDTDRAutumn18DR/TTbar_14TeV_TuneCP5_Pythia8/FEVT/PU200_103X_upgrade2023_realistic_v2-v1/80000/362E2A03-9819-7B4B-9AD1-0F1544A6B16D.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIIMTDTDRAutumn18DR/TTbar_14TeV_TuneCP5_Pythia8/FEVT/PU200_103X_upgrade2023_realistic_v2-v1/80000/061E6A7D-DAFA-EA45-86DD-C8504E7C3A24.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIIMTDTDRAutumn18DR/TTbar_14TeV_TuneCP5_Pythia8/FEVT/PU200_103X_upgrade2023_realistic_v2-v1/80000/32AEB5C3-B03C-E942-A28B-458834BE9E94.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIIMTDTDRAutumn18DR/TTbar_14TeV_TuneCP5_Pythia8/FEVT/PU200_103X_upgrade2023_realistic_v2-v1/80000/981A067C-A5E7-5841-B181-3F9FB6BE2669.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIIMTDTDRAutumn18DR/TTbar_14TeV_TuneCP5_Pythia8/FEVT/PU200_103X_upgrade2023_realistic_v2-v1/80000/8E79E006-C866-8F47-835A-E9F0B542CB05.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIIMTDTDRAutumn18DR/TTbar_14TeV_TuneCP5_Pythia8/FEVT/PU200_103X_upgrade2023_realistic_v2-v1/80000/44384221-A552-864B-96DB-839C3E21C364.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIIMTDTDRAutumn18DR/TTbar_14TeV_TuneCP5_Pythia8/FEVT/PU200_103X_upgrade2023_realistic_v2-v1/80000/0D298922-5C0F-2C4F-92E8-551996C83542.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIIMTDTDRAutumn18DR/TTbar_14TeV_TuneCP5_Pythia8/FEVT/PU200_103X_upgrade2023_realistic_v2-v1/80000/A6BF9985-734E-8C42-A3AC-5A1618D2D22B.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIIMTDTDRAutumn18DR/TTbar_14TeV_TuneCP5_Pythia8/FEVT/PU200_103X_upgrade2023_realistic_v2-v1/80000/39DD6BEE-A61F-F146-89C1-C6FC0768D9DA.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIIMTDTDRAutumn18DR/TTbar_14TeV_TuneCP5_Pythia8/FEVT/PU200_103X_upgrade2023_realistic_v2-v1/80000/1E659E87-3DEE-6F4E-9C2F-B3CCDA1175BA.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIIMTDTDRAutumn18DR/TTbar_14TeV_TuneCP5_Pythia8/FEVT/PU200_103X_upgrade2023_realistic_v2-v1/80000/8026FE38-21CF-524C-9637-30A7ED936BA4.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIIMTDTDRAutumn18DR/TTbar_14TeV_TuneCP5_Pythia8/FEVT/PU200_103X_upgrade2023_realistic_v2-v1/80000/5879A635-DC63-7F40-85C3-748C55C2D917.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIIMTDTDRAutumn18DR/TTbar_14TeV_TuneCP5_Pythia8/FEVT/PU200_103X_upgrade2023_realistic_v2-v1/80000/9C05CC03-62F6-C141-8BEF-5D2D7A3671F0.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIIMTDTDRAutumn18DR/TTbar_14TeV_TuneCP5_Pythia8/FEVT/PU200_103X_upgrade2023_realistic_v2-v1/80000/275C4478-D59A-2143-BC3F-734AED7FD085.root",
"root://xrootd-cms.infn.it//store/mc/PhaseIIMTDTDRAutumn18DR/TTbar_14TeV_TuneCP5_Pythia8/FEVT/PU200_103X_upgrade2023_realistic_v2-v1/80000/C4A1A7F5-55FA-E143-9258-781785307922.root",

    ),
    secondaryFileNames = cms.untracked.vstring()
)

