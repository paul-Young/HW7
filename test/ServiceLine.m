(* ::Package:: *)

BeginPackage["ServiceLine`"]

ExponentialFit::usage = "PrettyPlot[data] returns a fit of exponential 
distribution overlaid to a histogram of the data"



(* -------------------------------- Private -------------------------------- *)
Begin["`Private`"]

ExponentialFit[data_,label_]:=Module[{\[Lambda],fit},
fit = FindDistributionParameters[data,ExponentialDistribution[\[Lambda]]];
Show[{
Plot[
PDF[ExponentialDistribution[\[Lambda]/.fit],x]
,{x,0,1}
,PlotRange->All
,PlotStyle->{Red,Thick}
,PlotLabel->label[[1]]<>" Mean = " <>ToString[\[Lambda]/.fit]
,Frame->{True,True}
,FrameLabel->label
]

,

Histogram[data,Automatic,"PDF"]
}]
]

End[]
EndPackage[]
