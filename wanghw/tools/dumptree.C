// Author: Tao Luo
#include <TTree.h>
#include <TChain.h>
#include <TTreePlayer.h>

void dumptree(const Char_t* filename, const Char_t* variablename)
{
    TChain ddr("bs");
    //for signal MC
    ddr.Add(filename);
    TTree *tree = ddr.CloneTree(0);
    //tree=ddr.CopyTree("contSupCFMlp>0.2");
    tree=ddr.CopyTree("");
    ((TTreePlayer*)(tree->GetPlayer()))->SetScanRedirect(true); 
    ((TTreePlayer*)(tree->GetPlayer()))->SetScanFileName("tmp.txt"); 
    tree->Scan(variablename);
    return;
}
