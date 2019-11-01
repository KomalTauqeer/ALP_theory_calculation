#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pandas as pd
import numpy as np
import ROOT
from ROOT import gROOT,gPad
get_ipython().run_line_magic('jsroot', 'on')


# In[2]:


data = pd.read_csv('widths.csv')
print(data)


# In[3]:


mALP = np.array([10,80,350])
gr1 = ROOT.TGraph(3,mALP.astype('float'),np.array(data.iloc[0,1:4]).astype('float'))
gr2 = ROOT.TGraph(3,mALP.astype('float'),np.array(data.iloc[1,1:4]).astype('float'))
gr3 = ROOT.TGraph(3,mALP.astype('float'),np.array(data.iloc[2,1:4]).astype('float'))
gr4 = ROOT.TGraph(3,mALP.astype('float'),np.array(data.iloc[3,1:4]).astype('float'))
gr5 = ROOT.TGraph(3,mALP.astype('float'),np.array(data.iloc[4,1:4]).astype('float'))
gr6 = ROOT.TGraph(3,mALP.astype('float'),np.array(data.iloc[5,1:4]).astype('float'))


# In[4]:


gr1.SetTitle('Decay widths for different processes as a function of ALP mass')
gr1.GetXaxis().SetTitle('Mass of ALP [GeV]')
gr1.GetXaxis().SetTitleOffset(1.2)
gr1.GetYaxis().SetTitle('Decay Width [GeV]')

ax1 = gr1.GetXaxis()
ax1.SetLimits(5,5000)
ax2 = gr1.GetYaxis()
ax2.SetNdivisions(5)
gr1.GetHistogram().SetMinimum(1e-20);
gr1.GetHistogram().SetMaximum(1e10);

gr1.SetLineColor( 2 )
gr1.SetLineWidth( 4 )
gr1.SetMarkerColor( 2 )
gr1.SetMarkerStyle( 21 )
gr1.SetMarkerSize( 1.5 )

gr2.SetLineColor( 2 )
gr2.SetLineWidth( 4 )
gr2.SetMarkerColor( 3 )
gr2.SetMarkerStyle( 20 )
gr2.SetMarkerSize( 1.5 )

gr3.SetLineColor( 2 )
gr3.SetLineWidth( 4 )
gr3.SetMarkerColor( 4 )
gr3.SetMarkerStyle( 22 )
gr3.SetMarkerSize( 1.5 )

gr4.SetLineColor( 2 )
gr4.SetLineWidth( 4 )
gr4.SetMarkerColor( 41 )
gr4.SetMarkerStyle( 23 )
gr4.SetMarkerSize( 1.5 )

gr5.SetLineColor( 2 )
gr5.SetLineWidth( 4 )
gr5.SetMarkerColor( 6 )
gr5.SetMarkerStyle( 29 )
gr5.SetMarkerSize( 1.5 )

gr6.SetLineColor( 2 )
gr6.SetLineWidth( 4 )
gr6.SetMarkerColor( 38 )
gr6.SetMarkerStyle( 33 )
gr6.SetMarkerSize( 1.5 )


# In[5]:


leg = ROOT.TLegend(0.66,0.19,0.893,0.89)
leg.AddEntry(gr1,"#splitline{ALP#rightarrow gg;}{c_{g}=1}","P")
leg.AddEntry(gr2,"#splitline{ALP#rightarrow gg;}{c_{g}=1/(4#pi)}","P")
leg.AddEntry(gr3,"#splitline{ALP#rightarrow q#bar{q};}{c_{q}=1}","P")
leg.AddEntry(gr4,"#splitline{ALP#rightarrow gg Theory Prediction;}{c_{g}=1}","P")
leg.AddEntry(gr5,"#splitline{ALP#rightarrow gg Theory Prediction;}{c_{g}=1/(4#pi)}","P")
leg.AddEntry(gr6,"#splitline{ALP#rightarrow q#bar{q} Theory Prediction;}{c_{q}=1}","P")


# In[6]:


canvas = ROOT.TCanvas('','',200, 10, 1200, 800)
gPad.SetLogx()
gPad.SetLogy()
gr1.Draw('AP')
gr2.Draw('same P')
gr3.Draw('same P')
gr4.Draw('same P')
gr5.Draw('same P')
gr6.Draw('same P')
leg.Draw()


# In[7]:


canvas.Modified()
canvas.Update()
gROOT.GetListOfCanvases().Draw()
canvas.SaveAs("WidthsummaryPlot.pdf")

