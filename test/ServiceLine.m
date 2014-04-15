(* ::Package:: *)

BeginPackage["ServiceLine`"]

PrettyPlot::usage = "PrettyPlot[data] returns a fit of exponential 
distribution overlaid to a histogram of the data"



(* -------------------------------- Private -------------------------------- *)
Begin["`Private`"]

PrettyPlot[data_]:=Module[{\[Lambda],fit},
fit = FindDistributionParameters[data,ExponentialDistribution[\[Lambda]]];
Show[{
Plot[
PDF[ExponentialDistribution[\[Lambda]/.fit],x]
,{x,0,1}
,PlotRange->All
,PlotStyle->{Red,Thick}
,PlotLabel->"Arrival Mean = " <>ToString[\[Lambda]/.fit]
,Frame->{True,True}
,FrameLabel->{"Arrival Interval", "Relative Frequency"}
]

,

Histogram[data,Automatic,"PDF"]
}]
]

End[]
EndPackage[]
