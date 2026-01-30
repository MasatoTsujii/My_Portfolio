<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.5.2">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="pinhead" urn="urn:adsk.eagle:library:325">
<description>&lt;b&gt;Pin Header Connectors&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="2X24" urn="urn:adsk.eagle:footprint:22327/1" library_version="4">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-29.21" y1="-1.905" x2="-28.575" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-28.575" y1="-2.54" x2="-27.305" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-27.305" y1="-2.54" x2="-26.67" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-26.67" y1="-1.905" x2="-26.035" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-26.035" y1="-2.54" x2="-24.765" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-24.765" y1="-2.54" x2="-24.13" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-24.13" y1="-1.905" x2="-23.495" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-23.495" y1="-2.54" x2="-22.225" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-22.225" y1="-2.54" x2="-21.59" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-21.59" y1="-1.905" x2="-20.955" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-20.955" y1="-2.54" x2="-19.685" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-19.685" y1="-2.54" x2="-19.05" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-19.05" y1="-1.905" x2="-18.415" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-18.415" y1="-2.54" x2="-17.145" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-17.145" y1="-2.54" x2="-16.51" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-16.51" y1="-1.905" x2="-15.875" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-15.875" y1="-2.54" x2="-14.605" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-14.605" y1="-2.54" x2="-13.97" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-29.21" y1="-1.905" x2="-29.21" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-29.21" y1="1.905" x2="-28.575" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-28.575" y1="2.54" x2="-27.305" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-27.305" y1="2.54" x2="-26.67" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-26.67" y1="1.905" x2="-26.035" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-26.035" y1="2.54" x2="-24.765" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-24.765" y1="2.54" x2="-24.13" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-24.13" y1="1.905" x2="-23.495" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-23.495" y1="2.54" x2="-22.225" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-22.225" y1="2.54" x2="-21.59" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-21.59" y1="1.905" x2="-20.955" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-20.955" y1="2.54" x2="-19.685" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-19.685" y1="2.54" x2="-19.05" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-19.05" y1="1.905" x2="-18.415" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-18.415" y1="2.54" x2="-17.145" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-17.145" y1="2.54" x2="-16.51" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-16.51" y1="1.905" x2="-15.875" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-15.875" y1="2.54" x2="-14.605" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-14.605" y1="2.54" x2="-13.97" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-13.97" y1="1.905" x2="-13.335" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-13.335" y1="2.54" x2="-12.065" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-12.065" y1="2.54" x2="-11.43" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-11.43" y1="1.905" x2="-10.795" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-10.795" y1="2.54" x2="-9.525" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-9.525" y1="2.54" x2="-8.89" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="1.905" x2="-8.255" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="2.54" x2="-6.985" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="2.54" x2="-6.35" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="1.905" x2="-5.715" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="2.54" x2="-4.445" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="2.54" x2="-3.81" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="1.905" x2="-3.175" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="2.54" x2="-1.905" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="2.54" x2="-1.27" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="1.905" x2="-0.635" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="2.54" x2="0.635" y2="2.54" width="0.1524" layer="21"/>
<wire x1="1.27" y1="1.905" x2="0.635" y2="2.54" width="0.1524" layer="21"/>
<wire x1="1.27" y1="1.905" x2="1.905" y2="2.54" width="0.1524" layer="21"/>
<wire x1="3.175" y1="2.54" x2="1.905" y2="2.54" width="0.1524" layer="21"/>
<wire x1="3.175" y1="2.54" x2="3.81" y2="1.905" width="0.1524" layer="21"/>
<wire x1="3.81" y1="1.905" x2="4.445" y2="2.54" width="0.1524" layer="21"/>
<wire x1="5.715" y1="2.54" x2="4.445" y2="2.54" width="0.1524" layer="21"/>
<wire x1="5.715" y1="2.54" x2="6.35" y2="1.905" width="0.1524" layer="21"/>
<wire x1="6.35" y1="1.905" x2="6.985" y2="2.54" width="0.1524" layer="21"/>
<wire x1="8.255" y1="2.54" x2="6.985" y2="2.54" width="0.1524" layer="21"/>
<wire x1="8.255" y1="2.54" x2="8.89" y2="1.905" width="0.1524" layer="21"/>
<wire x1="8.89" y1="1.905" x2="9.525" y2="2.54" width="0.1524" layer="21"/>
<wire x1="10.795" y1="2.54" x2="9.525" y2="2.54" width="0.1524" layer="21"/>
<wire x1="10.795" y1="2.54" x2="11.43" y2="1.905" width="0.1524" layer="21"/>
<wire x1="11.43" y1="1.905" x2="12.065" y2="2.54" width="0.1524" layer="21"/>
<wire x1="13.335" y1="2.54" x2="12.065" y2="2.54" width="0.1524" layer="21"/>
<wire x1="13.335" y1="2.54" x2="13.97" y2="1.905" width="0.1524" layer="21"/>
<wire x1="13.97" y1="1.905" x2="14.605" y2="2.54" width="0.1524" layer="21"/>
<wire x1="15.875" y1="2.54" x2="14.605" y2="2.54" width="0.1524" layer="21"/>
<wire x1="15.875" y1="2.54" x2="16.51" y2="1.905" width="0.1524" layer="21"/>
<wire x1="16.51" y1="1.905" x2="17.145" y2="2.54" width="0.1524" layer="21"/>
<wire x1="18.415" y1="2.54" x2="17.145" y2="2.54" width="0.1524" layer="21"/>
<wire x1="18.415" y1="2.54" x2="19.05" y2="1.905" width="0.1524" layer="21"/>
<wire x1="19.05" y1="-1.905" x2="18.415" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="18.415" y1="-2.54" x2="17.145" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="16.51" y1="-1.905" x2="17.145" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="16.51" y1="-1.905" x2="15.875" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="15.875" y1="-2.54" x2="14.605" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="13.97" y1="-1.905" x2="14.605" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="13.97" y1="-1.905" x2="13.335" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="13.335" y1="-2.54" x2="12.065" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="11.43" y1="-1.905" x2="12.065" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="11.43" y1="-1.905" x2="10.795" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="9.525" y1="-2.54" x2="10.795" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="9.525" y1="-2.54" x2="8.89" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="8.89" y1="-1.905" x2="8.255" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="6.985" y1="-2.54" x2="8.255" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="6.985" y1="-2.54" x2="6.35" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="6.35" y1="-1.905" x2="5.715" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="5.715" y1="-2.54" x2="4.445" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="3.81" y1="-1.905" x2="4.445" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="3.81" y1="-1.905" x2="3.175" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="3.175" y1="-2.54" x2="1.905" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-1.905" x2="1.905" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-1.905" x2="0.635" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-2.54" x2="-0.635" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-1.905" x2="-0.635" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-1.905" x2="-1.905" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-2.54" x2="-3.175" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="-1.905" x2="-3.175" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="-1.905" x2="-4.445" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="-2.54" x2="-5.715" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="-1.905" x2="-5.715" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="-1.905" x2="-6.985" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="-2.54" x2="-8.255" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="-1.905" x2="-8.255" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="-1.905" x2="-9.525" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-9.525" y1="-2.54" x2="-10.795" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-11.43" y1="-1.905" x2="-10.795" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-11.43" y1="-1.905" x2="-12.065" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-12.065" y1="-2.54" x2="-13.335" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-13.97" y1="-1.905" x2="-13.335" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-26.67" y1="1.905" x2="-26.67" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-24.13" y1="1.905" x2="-24.13" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-21.59" y1="1.905" x2="-21.59" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-19.05" y1="1.905" x2="-19.05" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-16.51" y1="1.905" x2="-16.51" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-13.97" y1="1.905" x2="-13.97" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-11.43" y1="1.905" x2="-11.43" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="1.905" x2="-8.89" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="1.905" x2="-6.35" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="1.905" x2="-3.81" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="1.905" x2="-1.27" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="1.27" y1="1.905" x2="1.27" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="3.81" y1="1.905" x2="3.81" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="6.35" y1="1.905" x2="6.35" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="8.89" y1="1.905" x2="8.89" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="11.43" y1="1.905" x2="11.43" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="13.97" y1="1.905" x2="13.97" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="16.51" y1="1.905" x2="16.51" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="19.05" y1="1.905" x2="19.05" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="19.05" y1="1.905" x2="19.685" y2="2.54" width="0.1524" layer="21"/>
<wire x1="20.955" y1="2.54" x2="19.685" y2="2.54" width="0.1524" layer="21"/>
<wire x1="20.955" y1="2.54" x2="21.59" y2="1.905" width="0.1524" layer="21"/>
<wire x1="21.59" y1="-1.905" x2="20.955" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="20.955" y1="-2.54" x2="19.685" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="19.05" y1="-1.905" x2="19.685" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="21.59" y1="1.905" x2="21.59" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="21.59" y1="1.905" x2="22.225" y2="2.54" width="0.1524" layer="21"/>
<wire x1="23.495" y1="2.54" x2="22.225" y2="2.54" width="0.1524" layer="21"/>
<wire x1="23.495" y1="2.54" x2="24.13" y2="1.905" width="0.1524" layer="21"/>
<wire x1="24.13" y1="-1.905" x2="23.495" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="23.495" y1="-2.54" x2="22.225" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="21.59" y1="-1.905" x2="22.225" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="24.13" y1="1.905" x2="24.13" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="24.13" y1="1.905" x2="24.765" y2="2.54" width="0.1524" layer="21"/>
<wire x1="26.035" y1="2.54" x2="24.765" y2="2.54" width="0.1524" layer="21"/>
<wire x1="26.035" y1="2.54" x2="26.67" y2="1.905" width="0.1524" layer="21"/>
<wire x1="26.67" y1="-1.905" x2="26.035" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="26.035" y1="-2.54" x2="24.765" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="24.13" y1="-1.905" x2="24.765" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="26.67" y1="1.905" x2="26.67" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="26.67" y1="1.905" x2="27.305" y2="2.54" width="0.1524" layer="21"/>
<wire x1="28.575" y1="2.54" x2="27.305" y2="2.54" width="0.1524" layer="21"/>
<wire x1="28.575" y1="2.54" x2="29.21" y2="1.905" width="0.1524" layer="21"/>
<wire x1="29.21" y1="-1.905" x2="28.575" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="28.575" y1="-2.54" x2="27.305" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="26.67" y1="-1.905" x2="27.305" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="29.21" y1="1.905" x2="29.21" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="29.21" y1="1.905" x2="29.845" y2="2.54" width="0.1524" layer="21"/>
<wire x1="31.115" y1="2.54" x2="29.845" y2="2.54" width="0.1524" layer="21"/>
<wire x1="31.115" y1="2.54" x2="31.75" y2="1.905" width="0.1524" layer="21"/>
<wire x1="31.75" y1="-1.905" x2="31.115" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="31.115" y1="-2.54" x2="29.845" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="29.21" y1="-1.905" x2="29.845" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="31.75" y1="1.905" x2="31.75" y2="-1.905" width="0.1524" layer="21"/>
<pad name="1" x="-27.94" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="2" x="-27.94" y="1.27" drill="1.016" shape="octagon"/>
<pad name="3" x="-25.4" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="4" x="-25.4" y="1.27" drill="1.016" shape="octagon"/>
<pad name="5" x="-22.86" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="6" x="-22.86" y="1.27" drill="1.016" shape="octagon"/>
<pad name="7" x="-20.32" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="8" x="-20.32" y="1.27" drill="1.016" shape="octagon"/>
<pad name="9" x="-17.78" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="10" x="-17.78" y="1.27" drill="1.016" shape="octagon"/>
<pad name="11" x="-15.24" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="12" x="-15.24" y="1.27" drill="1.016" shape="octagon"/>
<pad name="13" x="-12.7" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="14" x="-12.7" y="1.27" drill="1.016" shape="octagon"/>
<pad name="15" x="-10.16" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="16" x="-10.16" y="1.27" drill="1.016" shape="octagon"/>
<pad name="17" x="-7.62" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="18" x="-7.62" y="1.27" drill="1.016" shape="octagon"/>
<pad name="19" x="-5.08" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="20" x="-5.08" y="1.27" drill="1.016" shape="octagon"/>
<pad name="21" x="-2.54" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="22" x="-2.54" y="1.27" drill="1.016" shape="octagon"/>
<pad name="23" x="0" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="24" x="0" y="1.27" drill="1.016" shape="octagon"/>
<pad name="25" x="2.54" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="26" x="2.54" y="1.27" drill="1.016" shape="octagon"/>
<pad name="27" x="5.08" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="28" x="5.08" y="1.27" drill="1.016" shape="octagon"/>
<pad name="29" x="7.62" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="30" x="7.62" y="1.27" drill="1.016" shape="octagon"/>
<pad name="31" x="10.16" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="32" x="10.16" y="1.27" drill="1.016" shape="octagon"/>
<pad name="33" x="12.7" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="34" x="12.7" y="1.27" drill="1.016" shape="octagon"/>
<pad name="35" x="15.24" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="36" x="15.24" y="1.27" drill="1.016" shape="octagon"/>
<pad name="37" x="17.78" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="38" x="17.78" y="1.27" drill="1.016" shape="octagon"/>
<pad name="39" x="20.32" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="40" x="20.32" y="1.27" drill="1.016" shape="octagon"/>
<pad name="41" x="22.86" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="42" x="22.86" y="1.27" drill="1.016" shape="octagon"/>
<pad name="43" x="25.4" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="44" x="25.4" y="1.27" drill="1.016" shape="octagon"/>
<pad name="45" x="27.94" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="46" x="27.94" y="1.27" drill="1.016" shape="octagon"/>
<pad name="47" x="30.48" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="48" x="30.48" y="1.27" drill="1.016" shape="octagon"/>
<text x="-29.21" y="3.175" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-29.21" y="-4.445" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-28.194" y1="-1.524" x2="-27.686" y2="-1.016" layer="51"/>
<rectangle x1="-28.194" y1="1.016" x2="-27.686" y2="1.524" layer="51"/>
<rectangle x1="-25.654" y1="1.016" x2="-25.146" y2="1.524" layer="51"/>
<rectangle x1="-25.654" y1="-1.524" x2="-25.146" y2="-1.016" layer="51"/>
<rectangle x1="-23.114" y1="1.016" x2="-22.606" y2="1.524" layer="51"/>
<rectangle x1="-23.114" y1="-1.524" x2="-22.606" y2="-1.016" layer="51"/>
<rectangle x1="-20.574" y1="1.016" x2="-20.066" y2="1.524" layer="51"/>
<rectangle x1="-18.034" y1="1.016" x2="-17.526" y2="1.524" layer="51"/>
<rectangle x1="-15.494" y1="1.016" x2="-14.986" y2="1.524" layer="51"/>
<rectangle x1="-20.574" y1="-1.524" x2="-20.066" y2="-1.016" layer="51"/>
<rectangle x1="-18.034" y1="-1.524" x2="-17.526" y2="-1.016" layer="51"/>
<rectangle x1="-15.494" y1="-1.524" x2="-14.986" y2="-1.016" layer="51"/>
<rectangle x1="-12.954" y1="1.016" x2="-12.446" y2="1.524" layer="51"/>
<rectangle x1="-12.954" y1="-1.524" x2="-12.446" y2="-1.016" layer="51"/>
<rectangle x1="-10.414" y1="1.016" x2="-9.906" y2="1.524" layer="51"/>
<rectangle x1="-10.414" y1="-1.524" x2="-9.906" y2="-1.016" layer="51"/>
<rectangle x1="-7.874" y1="1.016" x2="-7.366" y2="1.524" layer="51"/>
<rectangle x1="-7.874" y1="-1.524" x2="-7.366" y2="-1.016" layer="51"/>
<rectangle x1="-5.334" y1="1.016" x2="-4.826" y2="1.524" layer="51"/>
<rectangle x1="-5.334" y1="-1.524" x2="-4.826" y2="-1.016" layer="51"/>
<rectangle x1="-2.794" y1="1.016" x2="-2.286" y2="1.524" layer="51"/>
<rectangle x1="-2.794" y1="-1.524" x2="-2.286" y2="-1.016" layer="51"/>
<rectangle x1="-0.254" y1="1.016" x2="0.254" y2="1.524" layer="51"/>
<rectangle x1="-0.254" y1="-1.524" x2="0.254" y2="-1.016" layer="51"/>
<rectangle x1="2.286" y1="1.016" x2="2.794" y2="1.524" layer="51"/>
<rectangle x1="2.286" y1="-1.524" x2="2.794" y2="-1.016" layer="51"/>
<rectangle x1="4.826" y1="1.016" x2="5.334" y2="1.524" layer="51"/>
<rectangle x1="4.826" y1="-1.524" x2="5.334" y2="-1.016" layer="51"/>
<rectangle x1="7.366" y1="1.016" x2="7.874" y2="1.524" layer="51"/>
<rectangle x1="7.366" y1="-1.524" x2="7.874" y2="-1.016" layer="51"/>
<rectangle x1="9.906" y1="1.016" x2="10.414" y2="1.524" layer="51"/>
<rectangle x1="9.906" y1="-1.524" x2="10.414" y2="-1.016" layer="51"/>
<rectangle x1="12.446" y1="1.016" x2="12.954" y2="1.524" layer="51"/>
<rectangle x1="12.446" y1="-1.524" x2="12.954" y2="-1.016" layer="51"/>
<rectangle x1="14.986" y1="1.016" x2="15.494" y2="1.524" layer="51"/>
<rectangle x1="14.986" y1="-1.524" x2="15.494" y2="-1.016" layer="51"/>
<rectangle x1="17.526" y1="1.016" x2="18.034" y2="1.524" layer="51"/>
<rectangle x1="17.526" y1="-1.524" x2="18.034" y2="-1.016" layer="51"/>
<rectangle x1="20.066" y1="1.016" x2="20.574" y2="1.524" layer="51"/>
<rectangle x1="20.066" y1="-1.524" x2="20.574" y2="-1.016" layer="51"/>
<rectangle x1="22.606" y1="1.016" x2="23.114" y2="1.524" layer="51"/>
<rectangle x1="22.606" y1="-1.524" x2="23.114" y2="-1.016" layer="51"/>
<rectangle x1="25.146" y1="1.016" x2="25.654" y2="1.524" layer="51"/>
<rectangle x1="25.146" y1="-1.524" x2="25.654" y2="-1.016" layer="51"/>
<rectangle x1="27.686" y1="1.016" x2="28.194" y2="1.524" layer="51"/>
<rectangle x1="27.686" y1="-1.524" x2="28.194" y2="-1.016" layer="51"/>
<rectangle x1="30.226" y1="1.016" x2="30.734" y2="1.524" layer="51"/>
<rectangle x1="30.226" y1="-1.524" x2="30.734" y2="-1.016" layer="51"/>
</package>
<package name="2X24/90" urn="urn:adsk.eagle:footprint:22328/1" library_version="4">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-30.48" y1="-1.905" x2="-27.94" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-27.94" y1="-1.905" x2="-27.94" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-27.94" y1="0.635" x2="-30.48" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-30.48" y1="0.635" x2="-30.48" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-29.21" y1="6.985" x2="-29.21" y2="1.27" width="0.762" layer="21"/>
<wire x1="-27.94" y1="-1.905" x2="-25.4" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-25.4" y1="-1.905" x2="-25.4" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-25.4" y1="0.635" x2="-27.94" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-26.67" y1="6.985" x2="-26.67" y2="1.27" width="0.762" layer="21"/>
<wire x1="-25.4" y1="-1.905" x2="-22.86" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-22.86" y1="-1.905" x2="-22.86" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-22.86" y1="0.635" x2="-25.4" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-24.13" y1="6.985" x2="-24.13" y2="1.27" width="0.762" layer="21"/>
<wire x1="-22.86" y1="-1.905" x2="-20.32" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-20.32" y1="-1.905" x2="-20.32" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-20.32" y1="0.635" x2="-22.86" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-21.59" y1="6.985" x2="-21.59" y2="1.27" width="0.762" layer="21"/>
<wire x1="-20.32" y1="-1.905" x2="-17.78" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-17.78" y1="-1.905" x2="-17.78" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-17.78" y1="0.635" x2="-20.32" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-19.05" y1="6.985" x2="-19.05" y2="1.27" width="0.762" layer="21"/>
<wire x1="-17.78" y1="-1.905" x2="-15.24" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-15.24" y1="-1.905" x2="-15.24" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-15.24" y1="0.635" x2="-17.78" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-16.51" y1="6.985" x2="-16.51" y2="1.27" width="0.762" layer="21"/>
<wire x1="-15.24" y1="-1.905" x2="-12.7" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-12.7" y1="-1.905" x2="-12.7" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-12.7" y1="0.635" x2="-15.24" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-13.97" y1="6.985" x2="-13.97" y2="1.27" width="0.762" layer="21"/>
<wire x1="-12.7" y1="-1.905" x2="-10.16" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="-1.905" x2="-10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="0.635" x2="-12.7" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-11.43" y1="6.985" x2="-11.43" y2="1.27" width="0.762" layer="21"/>
<wire x1="-10.16" y1="-1.905" x2="-7.62" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="-1.905" x2="-7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="0.635" x2="-10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="6.985" x2="-8.89" y2="1.27" width="0.762" layer="21"/>
<wire x1="-7.62" y1="-1.905" x2="-5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-1.905" x2="-5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="0.635" x2="-7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="6.985" x2="-6.35" y2="1.27" width="0.762" layer="21"/>
<wire x1="-5.08" y1="-1.905" x2="-2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-1.905" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="0.635" x2="-5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="6.985" x2="-3.81" y2="1.27" width="0.762" layer="21"/>
<wire x1="-2.54" y1="-1.905" x2="0" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="0" y1="-1.905" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="6.985" x2="-1.27" y2="1.27" width="0.762" layer="21"/>
<wire x1="0" y1="-1.905" x2="2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="0.635" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="6.985" x2="1.27" y2="1.27" width="0.762" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-1.905" x2="5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="5.08" y1="0.635" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="3.81" y1="6.985" x2="3.81" y2="1.27" width="0.762" layer="21"/>
<wire x1="5.08" y1="-1.905" x2="7.62" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="7.62" y1="-1.905" x2="7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="7.62" y1="0.635" x2="5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="6.35" y1="6.985" x2="6.35" y2="1.27" width="0.762" layer="21"/>
<wire x1="7.62" y1="-1.905" x2="10.16" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-1.905" x2="10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="10.16" y1="0.635" x2="7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="8.89" y1="6.985" x2="8.89" y2="1.27" width="0.762" layer="21"/>
<wire x1="10.16" y1="-1.905" x2="12.7" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="12.7" y1="-1.905" x2="12.7" y2="0.635" width="0.1524" layer="21"/>
<wire x1="12.7" y1="0.635" x2="10.16" y2="0.635" width="0.1524" layer="21"/>
<wire x1="11.43" y1="6.985" x2="11.43" y2="1.27" width="0.762" layer="21"/>
<wire x1="12.7" y1="-1.905" x2="15.24" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="15.24" y1="-1.905" x2="15.24" y2="0.635" width="0.1524" layer="21"/>
<wire x1="15.24" y1="0.635" x2="12.7" y2="0.635" width="0.1524" layer="21"/>
<wire x1="13.97" y1="6.985" x2="13.97" y2="1.27" width="0.762" layer="21"/>
<wire x1="15.24" y1="-1.905" x2="17.78" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="17.78" y1="-1.905" x2="17.78" y2="0.635" width="0.1524" layer="21"/>
<wire x1="17.78" y1="0.635" x2="15.24" y2="0.635" width="0.1524" layer="21"/>
<wire x1="16.51" y1="6.985" x2="16.51" y2="1.27" width="0.762" layer="21"/>
<wire x1="17.78" y1="-1.905" x2="20.32" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="20.32" y1="-1.905" x2="20.32" y2="0.635" width="0.1524" layer="21"/>
<wire x1="20.32" y1="0.635" x2="17.78" y2="0.635" width="0.1524" layer="21"/>
<wire x1="19.05" y1="6.985" x2="19.05" y2="1.27" width="0.762" layer="21"/>
<wire x1="20.32" y1="-1.905" x2="22.86" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="22.86" y1="-1.905" x2="22.86" y2="0.635" width="0.1524" layer="21"/>
<wire x1="22.86" y1="0.635" x2="20.32" y2="0.635" width="0.1524" layer="21"/>
<wire x1="21.59" y1="6.985" x2="21.59" y2="1.27" width="0.762" layer="21"/>
<wire x1="22.86" y1="-1.905" x2="25.4" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="25.4" y1="0.635" x2="22.86" y2="0.635" width="0.1524" layer="21"/>
<wire x1="24.13" y1="6.985" x2="24.13" y2="1.27" width="0.762" layer="21"/>
<wire x1="25.4" y1="-1.905" x2="25.4" y2="0.635" width="0.1524" layer="21"/>
<wire x1="25.4" y1="-1.905" x2="27.94" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="27.94" y1="-1.905" x2="27.94" y2="0.635" width="0.1524" layer="21"/>
<wire x1="27.94" y1="0.635" x2="25.4" y2="0.635" width="0.1524" layer="21"/>
<wire x1="26.67" y1="6.985" x2="26.67" y2="1.27" width="0.762" layer="21"/>
<wire x1="27.94" y1="-1.905" x2="30.48" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="30.48" y1="-1.905" x2="30.48" y2="0.635" width="0.1524" layer="21"/>
<wire x1="30.48" y1="0.635" x2="27.94" y2="0.635" width="0.1524" layer="21"/>
<wire x1="29.21" y1="6.985" x2="29.21" y2="1.27" width="0.762" layer="21"/>
<pad name="2" x="-29.21" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="4" x="-26.67" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="6" x="-24.13" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="8" x="-21.59" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="10" x="-19.05" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="12" x="-16.51" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="14" x="-13.97" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="16" x="-11.43" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="18" x="-8.89" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="20" x="-6.35" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="22" x="-3.81" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="24" x="-1.27" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="26" x="1.27" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="28" x="3.81" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="30" x="6.35" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="32" x="8.89" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="34" x="11.43" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="36" x="13.97" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="38" x="16.51" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="1" x="-29.21" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="3" x="-26.67" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="5" x="-24.13" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="7" x="-21.59" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="9" x="-19.05" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="11" x="-16.51" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="13" x="-13.97" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="15" x="-11.43" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="17" x="-8.89" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="19" x="-6.35" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="21" x="-3.81" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="23" x="-1.27" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="25" x="1.27" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="27" x="3.81" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="29" x="6.35" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="31" x="8.89" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="33" x="11.43" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="35" x="13.97" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="37" x="16.51" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="40" x="19.05" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="39" x="19.05" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="41" x="21.59" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="42" x="21.59" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="43" x="24.13" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="44" x="24.13" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="45" x="26.67" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="46" x="26.67" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="47" x="29.21" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="48" x="29.21" y="-3.81" drill="1.016" shape="octagon"/>
<text x="-31.115" y="-3.81" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="32.385" y="-4.445" size="1.27" layer="27" rot="R90">&gt;VALUE</text>
<rectangle x1="-29.591" y1="0.635" x2="-28.829" y2="1.143" layer="21"/>
<rectangle x1="-27.051" y1="0.635" x2="-26.289" y2="1.143" layer="21"/>
<rectangle x1="-24.511" y1="0.635" x2="-23.749" y2="1.143" layer="21"/>
<rectangle x1="-21.971" y1="0.635" x2="-21.209" y2="1.143" layer="21"/>
<rectangle x1="-19.431" y1="0.635" x2="-18.669" y2="1.143" layer="21"/>
<rectangle x1="-16.891" y1="0.635" x2="-16.129" y2="1.143" layer="21"/>
<rectangle x1="-14.351" y1="0.635" x2="-13.589" y2="1.143" layer="21"/>
<rectangle x1="-11.811" y1="0.635" x2="-11.049" y2="1.143" layer="21"/>
<rectangle x1="-9.271" y1="0.635" x2="-8.509" y2="1.143" layer="21"/>
<rectangle x1="-6.731" y1="0.635" x2="-5.969" y2="1.143" layer="21"/>
<rectangle x1="-4.191" y1="0.635" x2="-3.429" y2="1.143" layer="21"/>
<rectangle x1="-1.651" y1="0.635" x2="-0.889" y2="1.143" layer="21"/>
<rectangle x1="0.889" y1="0.635" x2="1.651" y2="1.143" layer="21"/>
<rectangle x1="3.429" y1="0.635" x2="4.191" y2="1.143" layer="21"/>
<rectangle x1="5.969" y1="0.635" x2="6.731" y2="1.143" layer="21"/>
<rectangle x1="8.509" y1="0.635" x2="9.271" y2="1.143" layer="21"/>
<rectangle x1="11.049" y1="0.635" x2="11.811" y2="1.143" layer="21"/>
<rectangle x1="13.589" y1="0.635" x2="14.351" y2="1.143" layer="21"/>
<rectangle x1="16.129" y1="0.635" x2="16.891" y2="1.143" layer="21"/>
<rectangle x1="18.669" y1="0.635" x2="19.431" y2="1.143" layer="21"/>
<rectangle x1="-29.591" y1="-2.921" x2="-28.829" y2="-1.905" layer="21"/>
<rectangle x1="-27.051" y1="-2.921" x2="-26.289" y2="-1.905" layer="21"/>
<rectangle x1="-29.591" y1="-5.461" x2="-28.829" y2="-4.699" layer="21"/>
<rectangle x1="-29.591" y1="-4.699" x2="-28.829" y2="-2.921" layer="51"/>
<rectangle x1="-27.051" y1="-4.699" x2="-26.289" y2="-2.921" layer="51"/>
<rectangle x1="-27.051" y1="-5.461" x2="-26.289" y2="-4.699" layer="21"/>
<rectangle x1="-24.511" y1="-2.921" x2="-23.749" y2="-1.905" layer="21"/>
<rectangle x1="-21.971" y1="-2.921" x2="-21.209" y2="-1.905" layer="21"/>
<rectangle x1="-24.511" y1="-5.461" x2="-23.749" y2="-4.699" layer="21"/>
<rectangle x1="-24.511" y1="-4.699" x2="-23.749" y2="-2.921" layer="51"/>
<rectangle x1="-21.971" y1="-4.699" x2="-21.209" y2="-2.921" layer="51"/>
<rectangle x1="-21.971" y1="-5.461" x2="-21.209" y2="-4.699" layer="21"/>
<rectangle x1="-19.431" y1="-2.921" x2="-18.669" y2="-1.905" layer="21"/>
<rectangle x1="-19.431" y1="-5.461" x2="-18.669" y2="-4.699" layer="21"/>
<rectangle x1="-19.431" y1="-4.699" x2="-18.669" y2="-2.921" layer="51"/>
<rectangle x1="-16.891" y1="-2.921" x2="-16.129" y2="-1.905" layer="21"/>
<rectangle x1="-14.351" y1="-2.921" x2="-13.589" y2="-1.905" layer="21"/>
<rectangle x1="-16.891" y1="-5.461" x2="-16.129" y2="-4.699" layer="21"/>
<rectangle x1="-16.891" y1="-4.699" x2="-16.129" y2="-2.921" layer="51"/>
<rectangle x1="-14.351" y1="-4.699" x2="-13.589" y2="-2.921" layer="51"/>
<rectangle x1="-14.351" y1="-5.461" x2="-13.589" y2="-4.699" layer="21"/>
<rectangle x1="-11.811" y1="-2.921" x2="-11.049" y2="-1.905" layer="21"/>
<rectangle x1="-9.271" y1="-2.921" x2="-8.509" y2="-1.905" layer="21"/>
<rectangle x1="-11.811" y1="-5.461" x2="-11.049" y2="-4.699" layer="21"/>
<rectangle x1="-11.811" y1="-4.699" x2="-11.049" y2="-2.921" layer="51"/>
<rectangle x1="-9.271" y1="-4.699" x2="-8.509" y2="-2.921" layer="51"/>
<rectangle x1="-9.271" y1="-5.461" x2="-8.509" y2="-4.699" layer="21"/>
<rectangle x1="-6.731" y1="-2.921" x2="-5.969" y2="-1.905" layer="21"/>
<rectangle x1="-6.731" y1="-5.461" x2="-5.969" y2="-4.699" layer="21"/>
<rectangle x1="-6.731" y1="-4.699" x2="-5.969" y2="-2.921" layer="51"/>
<rectangle x1="-4.191" y1="-2.921" x2="-3.429" y2="-1.905" layer="21"/>
<rectangle x1="-1.651" y1="-2.921" x2="-0.889" y2="-1.905" layer="21"/>
<rectangle x1="-4.191" y1="-5.461" x2="-3.429" y2="-4.699" layer="21"/>
<rectangle x1="-4.191" y1="-4.699" x2="-3.429" y2="-2.921" layer="51"/>
<rectangle x1="-1.651" y1="-4.699" x2="-0.889" y2="-2.921" layer="51"/>
<rectangle x1="-1.651" y1="-5.461" x2="-0.889" y2="-4.699" layer="21"/>
<rectangle x1="0.889" y1="-2.921" x2="1.651" y2="-1.905" layer="21"/>
<rectangle x1="3.429" y1="-2.921" x2="4.191" y2="-1.905" layer="21"/>
<rectangle x1="0.889" y1="-5.461" x2="1.651" y2="-4.699" layer="21"/>
<rectangle x1="0.889" y1="-4.699" x2="1.651" y2="-2.921" layer="51"/>
<rectangle x1="3.429" y1="-4.699" x2="4.191" y2="-2.921" layer="51"/>
<rectangle x1="3.429" y1="-5.461" x2="4.191" y2="-4.699" layer="21"/>
<rectangle x1="5.969" y1="-2.921" x2="6.731" y2="-1.905" layer="21"/>
<rectangle x1="5.969" y1="-5.461" x2="6.731" y2="-4.699" layer="21"/>
<rectangle x1="5.969" y1="-4.699" x2="6.731" y2="-2.921" layer="51"/>
<rectangle x1="8.509" y1="-2.921" x2="9.271" y2="-1.905" layer="21"/>
<rectangle x1="11.049" y1="-2.921" x2="11.811" y2="-1.905" layer="21"/>
<rectangle x1="8.509" y1="-5.461" x2="9.271" y2="-4.699" layer="21"/>
<rectangle x1="8.509" y1="-4.699" x2="9.271" y2="-2.921" layer="51"/>
<rectangle x1="11.049" y1="-4.699" x2="11.811" y2="-2.921" layer="51"/>
<rectangle x1="11.049" y1="-5.461" x2="11.811" y2="-4.699" layer="21"/>
<rectangle x1="13.589" y1="-2.921" x2="14.351" y2="-1.905" layer="21"/>
<rectangle x1="16.129" y1="-2.921" x2="16.891" y2="-1.905" layer="21"/>
<rectangle x1="13.589" y1="-5.461" x2="14.351" y2="-4.699" layer="21"/>
<rectangle x1="13.589" y1="-4.699" x2="14.351" y2="-2.921" layer="51"/>
<rectangle x1="16.129" y1="-4.699" x2="16.891" y2="-2.921" layer="51"/>
<rectangle x1="16.129" y1="-5.461" x2="16.891" y2="-4.699" layer="21"/>
<rectangle x1="18.669" y1="-2.921" x2="19.431" y2="-1.905" layer="21"/>
<rectangle x1="18.669" y1="-5.461" x2="19.431" y2="-4.699" layer="21"/>
<rectangle x1="18.669" y1="-4.699" x2="19.431" y2="-2.921" layer="51"/>
<rectangle x1="21.209" y1="0.635" x2="21.971" y2="1.143" layer="21"/>
<rectangle x1="23.749" y1="0.635" x2="24.511" y2="1.143" layer="21"/>
<rectangle x1="21.209" y1="-2.921" x2="21.971" y2="-1.905" layer="21"/>
<rectangle x1="21.209" y1="-4.699" x2="21.971" y2="-2.921" layer="51"/>
<rectangle x1="21.209" y1="-5.461" x2="21.971" y2="-4.699" layer="21"/>
<rectangle x1="23.749" y1="-2.921" x2="24.511" y2="-1.905" layer="21"/>
<rectangle x1="23.749" y1="-5.461" x2="24.511" y2="-4.699" layer="21"/>
<rectangle x1="23.749" y1="-4.699" x2="24.511" y2="-2.921" layer="51"/>
<rectangle x1="26.289" y1="0.635" x2="27.051" y2="1.143" layer="21"/>
<rectangle x1="28.829" y1="0.635" x2="29.591" y2="1.143" layer="21"/>
<rectangle x1="26.289" y1="-2.921" x2="27.051" y2="-1.905" layer="21"/>
<rectangle x1="26.289" y1="-4.699" x2="27.051" y2="-2.921" layer="51"/>
<rectangle x1="26.289" y1="-5.461" x2="27.051" y2="-4.699" layer="21"/>
<rectangle x1="28.829" y1="-2.921" x2="29.591" y2="-1.905" layer="21"/>
<rectangle x1="28.829" y1="-5.461" x2="29.591" y2="-4.699" layer="21"/>
<rectangle x1="28.829" y1="-4.699" x2="29.591" y2="-2.921" layer="51"/>
</package>
<package name="1X05" urn="urn:adsk.eagle:footprint:22354/1" library_version="4">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="1.905" y1="1.27" x2="3.175" y2="1.27" width="0.1524" layer="21"/>
<wire x1="3.175" y1="1.27" x2="3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="3.81" y1="0.635" x2="3.81" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="3.81" y1="-0.635" x2="3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="0.635" x2="-0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="1.27" x2="0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="1.27" x2="1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="0.635" x2="1.27" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-0.635" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.27" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.27" x2="-1.27" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="1.905" y1="1.27" x2="1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-0.635" x2="1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="3.175" y1="-1.27" x2="1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="1.27" x2="-4.445" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="1.27" x2="-3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="0.635" x2="-3.81" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="-0.635" x2="-4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="0.635" x2="-3.175" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="1.27" x2="-1.905" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="1.27" x2="-1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="0.635" x2="-1.27" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-0.635" x2="-1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-1.27" x2="-3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-1.27" x2="-3.81" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="0.635" x2="-6.35" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="1.27" x2="-6.35" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="-0.635" x2="-5.715" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="-1.27" x2="-5.715" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="4.445" y1="1.27" x2="5.715" y2="1.27" width="0.1524" layer="21"/>
<wire x1="5.715" y1="1.27" x2="6.35" y2="0.635" width="0.1524" layer="21"/>
<wire x1="6.35" y1="0.635" x2="6.35" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="6.35" y1="-0.635" x2="5.715" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="4.445" y1="1.27" x2="3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="3.81" y1="-0.635" x2="4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="5.715" y1="-1.27" x2="4.445" y2="-1.27" width="0.1524" layer="21"/>
<pad name="1" x="-5.08" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="-2.54" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="3" x="0" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="4" x="2.54" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="5" x="5.08" y="0" drill="1.016" shape="long" rot="R90"/>
<text x="-6.4262" y="1.8288" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-6.35" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="2.286" y1="-0.254" x2="2.794" y2="0.254" layer="51"/>
<rectangle x1="-0.254" y1="-0.254" x2="0.254" y2="0.254" layer="51"/>
<rectangle x1="-2.794" y1="-0.254" x2="-2.286" y2="0.254" layer="51"/>
<rectangle x1="-5.334" y1="-0.254" x2="-4.826" y2="0.254" layer="51"/>
<rectangle x1="4.826" y1="-0.254" x2="5.334" y2="0.254" layer="51"/>
</package>
<package name="1X05/90" urn="urn:adsk.eagle:footprint:22355/1" library_version="4">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-6.35" y1="-1.905" x2="-3.81" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="-1.905" x2="-3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="0.635" x2="-6.35" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="0.635" x2="-6.35" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="6.985" x2="-5.08" y2="1.27" width="0.762" layer="21"/>
<wire x1="-3.81" y1="-1.905" x2="-1.27" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-1.905" x2="-1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="0.635" x2="-3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="6.985" x2="-2.54" y2="1.27" width="0.762" layer="21"/>
<wire x1="-1.27" y1="-1.905" x2="1.27" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-1.905" x2="1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="0.635" x2="-1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="6.985" x2="0" y2="1.27" width="0.762" layer="21"/>
<wire x1="1.27" y1="-1.905" x2="3.81" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="3.81" y1="-1.905" x2="3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="3.81" y1="0.635" x2="1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="6.985" x2="2.54" y2="1.27" width="0.762" layer="21"/>
<wire x1="3.81" y1="-1.905" x2="6.35" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="6.35" y1="-1.905" x2="6.35" y2="0.635" width="0.1524" layer="21"/>
<wire x1="6.35" y1="0.635" x2="3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="5.08" y1="6.985" x2="5.08" y2="1.27" width="0.762" layer="21"/>
<pad name="1" x="-5.08" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="-2.54" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="3" x="0" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="4" x="2.54" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="5" x="5.08" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<text x="-6.985" y="-3.81" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="8.255" y="-3.81" size="1.27" layer="27" rot="R90">&gt;VALUE</text>
<rectangle x1="-5.461" y1="0.635" x2="-4.699" y2="1.143" layer="21"/>
<rectangle x1="-2.921" y1="0.635" x2="-2.159" y2="1.143" layer="21"/>
<rectangle x1="-0.381" y1="0.635" x2="0.381" y2="1.143" layer="21"/>
<rectangle x1="2.159" y1="0.635" x2="2.921" y2="1.143" layer="21"/>
<rectangle x1="4.699" y1="0.635" x2="5.461" y2="1.143" layer="21"/>
<rectangle x1="-5.461" y1="-2.921" x2="-4.699" y2="-1.905" layer="21"/>
<rectangle x1="-2.921" y1="-2.921" x2="-2.159" y2="-1.905" layer="21"/>
<rectangle x1="-0.381" y1="-2.921" x2="0.381" y2="-1.905" layer="21"/>
<rectangle x1="2.159" y1="-2.921" x2="2.921" y2="-1.905" layer="21"/>
<rectangle x1="4.699" y1="-2.921" x2="5.461" y2="-1.905" layer="21"/>
</package>
<package name="1_05X2MM" urn="urn:adsk.eagle:footprint:22356/1" library_version="4">
<description>CON-M-1X5-200</description>
<text x="-4.5" y="1.5" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-4.75" y="-2.75" size="1.27" layer="27">&gt;VALUE</text>
<wire x1="-5" y1="0.5" x2="-4.5" y2="1" width="0.1524" layer="21"/>
<wire x1="-4.5" y1="1" x2="-3.5" y2="1" width="0.1524" layer="21"/>
<wire x1="-3.5" y1="1" x2="-3" y2="0.5" width="0.1524" layer="21"/>
<wire x1="-3" y1="-0.5" x2="-3.5" y2="-1" width="0.1524" layer="21"/>
<wire x1="-3.5" y1="-1" x2="-4.5" y2="-1" width="0.1524" layer="21"/>
<wire x1="-4.5" y1="-1" x2="-5" y2="-0.5" width="0.1524" layer="21"/>
<wire x1="-5" y1="0.5" x2="-5" y2="-0.5" width="0.1524" layer="21"/>
<wire x1="-3" y1="0.5" x2="-2.5" y2="1" width="0.1524" layer="21"/>
<wire x1="-2.5" y1="1" x2="-1.5" y2="1" width="0.1524" layer="21"/>
<wire x1="-1.5" y1="1" x2="-1" y2="0.5" width="0.1524" layer="21"/>
<wire x1="-1" y1="-0.5" x2="-1.5" y2="-1" width="0.1524" layer="21"/>
<wire x1="-1.5" y1="-1" x2="-2.5" y2="-1" width="0.1524" layer="21"/>
<wire x1="-2.5" y1="-1" x2="-3" y2="-0.5" width="0.1524" layer="21"/>
<wire x1="-3" y1="0.5" x2="-3" y2="-0.5" width="0.1524" layer="21"/>
<wire x1="-1" y1="0.5" x2="-0.5" y2="1" width="0.1524" layer="21"/>
<wire x1="-0.5" y1="1" x2="0.5" y2="1" width="0.1524" layer="21"/>
<wire x1="0.5" y1="1" x2="1" y2="0.5" width="0.1524" layer="21"/>
<wire x1="1" y1="-0.5" x2="0.5" y2="-1" width="0.1524" layer="21"/>
<wire x1="0.5" y1="-1" x2="-0.5" y2="-1" width="0.1524" layer="21"/>
<wire x1="-0.5" y1="-1" x2="-1" y2="-0.5" width="0.1524" layer="21"/>
<wire x1="-1" y1="0.5" x2="-1" y2="-0.5" width="0.1524" layer="21"/>
<wire x1="1" y1="0.5" x2="1.5" y2="1" width="0.1524" layer="21"/>
<wire x1="1.5" y1="1" x2="2.5" y2="1" width="0.1524" layer="21"/>
<wire x1="2.5" y1="1" x2="3" y2="0.5" width="0.1524" layer="21"/>
<wire x1="3" y1="-0.5" x2="2.5" y2="-1" width="0.1524" layer="21"/>
<wire x1="2.5" y1="-1" x2="1.5" y2="-1" width="0.1524" layer="21"/>
<wire x1="1.5" y1="-1" x2="1" y2="-0.5" width="0.1524" layer="21"/>
<wire x1="1" y1="0.5" x2="1" y2="-0.5" width="0.1524" layer="21"/>
<wire x1="3" y1="0.5" x2="3.5" y2="1" width="0.1524" layer="21"/>
<wire x1="3.5" y1="1" x2="4.5" y2="1" width="0.1524" layer="21"/>
<wire x1="4.5" y1="1" x2="5" y2="0.5" width="0.1524" layer="21"/>
<wire x1="5" y1="0.5" x2="5" y2="-0.5" width="0.1524" layer="21"/>
<wire x1="5" y1="-0.5" x2="4.5" y2="-1" width="0.1524" layer="21"/>
<wire x1="4.5" y1="-1" x2="3.5" y2="-1" width="0.1524" layer="21"/>
<wire x1="3.5" y1="-1" x2="3" y2="-0.5" width="0.1524" layer="21"/>
<wire x1="3" y1="0.5" x2="3" y2="-0.5" width="0.1524" layer="21"/>
<pad name="1" x="-4" y="0" drill="1.016" diameter="1.3" shape="square" rot="R90"/>
<pad name="3" x="0" y="0" drill="1.016" diameter="1.3" rot="R90"/>
<pad name="2" x="-2" y="0" drill="1.016" diameter="1.3" rot="R90"/>
<pad name="4" x="2" y="0" drill="1.016" diameter="1.3" rot="R90"/>
<pad name="5" x="4" y="0" drill="1.016" diameter="1.3" rot="R90"/>
<rectangle x1="-4.254" y1="-0.254" x2="-3.746" y2="0.254" layer="51"/>
<rectangle x1="-2.254" y1="-0.254" x2="-1.746" y2="0.254" layer="51"/>
<rectangle x1="-0.254" y1="-0.254" x2="0.254" y2="0.254" layer="51"/>
<rectangle x1="1.746" y1="-0.254" x2="2.254" y2="0.254" layer="51"/>
<rectangle x1="3.746" y1="-0.254" x2="4.254" y2="0.254" layer="51"/>
</package>
</packages>
<packages3d>
<package3d name="2X24" urn="urn:adsk.eagle:package:22452/2" type="model" library_version="4">
<description>PIN HEADER</description>
<packageinstances>
<packageinstance name="2X24"/>
</packageinstances>
</package3d>
<package3d name="2X24/90" urn="urn:adsk.eagle:package:22451/2" type="model" library_version="4">
<description>PIN HEADER</description>
<packageinstances>
<packageinstance name="2X24/90"/>
</packageinstances>
</package3d>
<package3d name="1X05" urn="urn:adsk.eagle:package:22469/2" type="model" library_version="4">
<description>PIN HEADER</description>
<packageinstances>
<packageinstance name="1X05"/>
</packageinstances>
</package3d>
<package3d name="1X05/90" urn="urn:adsk.eagle:package:22467/2" type="model" library_version="4">
<description>PIN HEADER</description>
<packageinstances>
<packageinstance name="1X05/90"/>
</packageinstances>
</package3d>
<package3d name="1_05X2MM" urn="urn:adsk.eagle:package:22466/2" type="model" library_version="4">
<description>CON-M-1X5-200</description>
<packageinstances>
<packageinstance name="1_05X2MM"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="PINH2X24" urn="urn:adsk.eagle:symbol:22326/1" library_version="4">
<wire x1="-6.35" y1="-33.02" x2="8.89" y2="-33.02" width="0.4064" layer="94"/>
<wire x1="8.89" y1="-33.02" x2="8.89" y2="30.48" width="0.4064" layer="94"/>
<wire x1="8.89" y1="30.48" x2="-6.35" y2="30.48" width="0.4064" layer="94"/>
<wire x1="-6.35" y1="30.48" x2="-6.35" y2="-33.02" width="0.4064" layer="94"/>
<text x="-6.35" y="31.115" size="1.778" layer="95">&gt;NAME</text>
<text x="-6.35" y="-35.56" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1" x="-2.54" y="27.94" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="2" x="5.08" y="27.94" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="3" x="-2.54" y="25.4" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="4" x="5.08" y="25.4" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="5" x="-2.54" y="22.86" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="6" x="5.08" y="22.86" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="7" x="-2.54" y="20.32" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="8" x="5.08" y="20.32" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="9" x="-2.54" y="17.78" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="10" x="5.08" y="17.78" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="11" x="-2.54" y="15.24" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="12" x="5.08" y="15.24" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="13" x="-2.54" y="12.7" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="14" x="5.08" y="12.7" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="15" x="-2.54" y="10.16" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="16" x="5.08" y="10.16" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="17" x="-2.54" y="7.62" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="18" x="5.08" y="7.62" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="19" x="-2.54" y="5.08" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="20" x="5.08" y="5.08" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="21" x="-2.54" y="2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="22" x="5.08" y="2.54" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="23" x="-2.54" y="0" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="24" x="5.08" y="0" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="25" x="-2.54" y="-2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="26" x="5.08" y="-2.54" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="27" x="-2.54" y="-5.08" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="28" x="5.08" y="-5.08" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="29" x="-2.54" y="-7.62" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="30" x="5.08" y="-7.62" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="31" x="-2.54" y="-10.16" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="32" x="5.08" y="-10.16" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="33" x="-2.54" y="-12.7" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="34" x="5.08" y="-12.7" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="35" x="-2.54" y="-15.24" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="36" x="5.08" y="-15.24" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="37" x="-2.54" y="-17.78" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="38" x="5.08" y="-17.78" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="39" x="-2.54" y="-20.32" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="40" x="5.08" y="-20.32" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="41" x="-2.54" y="-22.86" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="42" x="5.08" y="-22.86" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="43" x="-2.54" y="-25.4" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="44" x="5.08" y="-25.4" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="45" x="-2.54" y="-27.94" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="46" x="5.08" y="-27.94" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="47" x="-2.54" y="-30.48" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="48" x="5.08" y="-30.48" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
</symbol>
<symbol name="PINHD5" urn="urn:adsk.eagle:symbol:22353/1" library_version="4">
<wire x1="-6.35" y1="-7.62" x2="1.27" y2="-7.62" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-7.62" x2="1.27" y2="7.62" width="0.4064" layer="94"/>
<wire x1="1.27" y1="7.62" x2="-6.35" y2="7.62" width="0.4064" layer="94"/>
<wire x1="-6.35" y1="7.62" x2="-6.35" y2="-7.62" width="0.4064" layer="94"/>
<text x="-6.35" y="8.255" size="1.778" layer="95">&gt;NAME</text>
<text x="-6.35" y="-10.16" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1" x="-2.54" y="5.08" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="2" x="-2.54" y="2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="3" x="-2.54" y="0" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="4" x="-2.54" y="-2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="5" x="-2.54" y="-5.08" visible="pad" length="short" direction="pas" function="dot"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="PINHD-2X24" urn="urn:adsk.eagle:component:22523/5" prefix="JP" uservalue="yes" library_version="4">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="A" symbol="PINH2X24" x="0" y="0"/>
</gates>
<devices>
<device name="" package="2X24">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="10" pad="10"/>
<connect gate="A" pin="11" pad="11"/>
<connect gate="A" pin="12" pad="12"/>
<connect gate="A" pin="13" pad="13"/>
<connect gate="A" pin="14" pad="14"/>
<connect gate="A" pin="15" pad="15"/>
<connect gate="A" pin="16" pad="16"/>
<connect gate="A" pin="17" pad="17"/>
<connect gate="A" pin="18" pad="18"/>
<connect gate="A" pin="19" pad="19"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="20" pad="20"/>
<connect gate="A" pin="21" pad="21"/>
<connect gate="A" pin="22" pad="22"/>
<connect gate="A" pin="23" pad="23"/>
<connect gate="A" pin="24" pad="24"/>
<connect gate="A" pin="25" pad="25"/>
<connect gate="A" pin="26" pad="26"/>
<connect gate="A" pin="27" pad="27"/>
<connect gate="A" pin="28" pad="28"/>
<connect gate="A" pin="29" pad="29"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="30" pad="30"/>
<connect gate="A" pin="31" pad="31"/>
<connect gate="A" pin="32" pad="32"/>
<connect gate="A" pin="33" pad="33"/>
<connect gate="A" pin="34" pad="34"/>
<connect gate="A" pin="35" pad="35"/>
<connect gate="A" pin="36" pad="36"/>
<connect gate="A" pin="37" pad="37"/>
<connect gate="A" pin="38" pad="38"/>
<connect gate="A" pin="39" pad="39"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="40" pad="40"/>
<connect gate="A" pin="41" pad="41"/>
<connect gate="A" pin="42" pad="42"/>
<connect gate="A" pin="43" pad="43"/>
<connect gate="A" pin="44" pad="44"/>
<connect gate="A" pin="45" pad="45"/>
<connect gate="A" pin="46" pad="46"/>
<connect gate="A" pin="47" pad="47"/>
<connect gate="A" pin="48" pad="48"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
<connect gate="A" pin="7" pad="7"/>
<connect gate="A" pin="8" pad="8"/>
<connect gate="A" pin="9" pad="9"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:22452/2"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
</technology>
</technologies>
</device>
<device name="/90" package="2X24/90">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="10" pad="10"/>
<connect gate="A" pin="11" pad="11"/>
<connect gate="A" pin="12" pad="12"/>
<connect gate="A" pin="13" pad="13"/>
<connect gate="A" pin="14" pad="14"/>
<connect gate="A" pin="15" pad="15"/>
<connect gate="A" pin="16" pad="16"/>
<connect gate="A" pin="17" pad="17"/>
<connect gate="A" pin="18" pad="18"/>
<connect gate="A" pin="19" pad="19"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="20" pad="20"/>
<connect gate="A" pin="21" pad="21"/>
<connect gate="A" pin="22" pad="22"/>
<connect gate="A" pin="23" pad="23"/>
<connect gate="A" pin="24" pad="24"/>
<connect gate="A" pin="25" pad="25"/>
<connect gate="A" pin="26" pad="26"/>
<connect gate="A" pin="27" pad="27"/>
<connect gate="A" pin="28" pad="28"/>
<connect gate="A" pin="29" pad="29"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="30" pad="30"/>
<connect gate="A" pin="31" pad="31"/>
<connect gate="A" pin="32" pad="32"/>
<connect gate="A" pin="33" pad="33"/>
<connect gate="A" pin="34" pad="34"/>
<connect gate="A" pin="35" pad="35"/>
<connect gate="A" pin="36" pad="36"/>
<connect gate="A" pin="37" pad="37"/>
<connect gate="A" pin="38" pad="38"/>
<connect gate="A" pin="39" pad="39"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="40" pad="40"/>
<connect gate="A" pin="41" pad="41"/>
<connect gate="A" pin="42" pad="42"/>
<connect gate="A" pin="43" pad="43"/>
<connect gate="A" pin="44" pad="44"/>
<connect gate="A" pin="45" pad="45"/>
<connect gate="A" pin="46" pad="46"/>
<connect gate="A" pin="47" pad="47"/>
<connect gate="A" pin="48" pad="48"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
<connect gate="A" pin="7" pad="7"/>
<connect gate="A" pin="8" pad="8"/>
<connect gate="A" pin="9" pad="9"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:22451/2"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="PINHD-1X5" urn="urn:adsk.eagle:component:22529/5" prefix="JP" uservalue="yes" library_version="4">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="A" symbol="PINHD5" x="0" y="0"/>
</gates>
<devices>
<device name="" package="1X05">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:22469/2"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="69" constant="no"/>
</technology>
</technologies>
</device>
<device name="/90" package="1X05/90">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:22467/2"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="9" constant="no"/>
</technology>
</technologies>
</device>
<device name="5X2MM" package="1_05X2MM">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:22466/2"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply2" urn="urn:adsk.eagle:library:372">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
Please keep in mind, that these devices are necessary for the
automatic wiring of the supply signals.&lt;p&gt;
The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="+12V" urn="urn:adsk.eagle:symbol:26985/1" library_version="2">
<wire x1="0" y1="1.905" x2="0" y2="0.635" width="0.1524" layer="94"/>
<wire x1="-0.635" y1="1.27" x2="0.635" y2="1.27" width="0.1524" layer="94"/>
<circle x="0" y="1.27" radius="1.27" width="0.254" layer="94"/>
<text x="-2.54" y="3.175" size="1.778" layer="96">&gt;VALUE</text>
<pin name="+12V" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
<symbol name="+24V" urn="urn:adsk.eagle:symbol:26982/1" library_version="2">
<wire x1="-0.635" y1="1.27" x2="0.635" y2="1.27" width="0.1524" layer="94"/>
<wire x1="0" y1="0.635" x2="0" y2="1.905" width="0.1524" layer="94"/>
<circle x="0" y="1.27" radius="1.27" width="0.254" layer="94"/>
<text x="-2.54" y="3.175" size="1.778" layer="96">&gt;VALUE</text>
<pin name="+24V" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
<symbol name="GND" urn="urn:adsk.eagle:symbol:26990/1" library_version="2">
<wire x1="-1.27" y1="0" x2="1.27" y2="0" width="0.254" layer="94"/>
<wire x1="1.27" y1="0" x2="0" y2="-1.27" width="0.254" layer="94"/>
<wire x1="0" y1="-1.27" x2="-1.27" y2="0" width="0.254" layer="94"/>
<text x="-1.905" y="-3.175" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
<symbol name="VSS" urn="urn:adsk.eagle:symbol:27016/1" library_version="2">
<circle x="0" y="-1.27" radius="1.27" width="0.254" layer="94"/>
<text x="-1.905" y="-4.699" size="1.778" layer="96">&gt;VALUE</text>
<pin name="VSS" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="+12V" urn="urn:adsk.eagle:component:27033/1" prefix="SUPPLY" library_version="2">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="+12V" symbol="+12V" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="+24V" urn="urn:adsk.eagle:component:27040/1" prefix="SUPPLY" library_version="2">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="+24V" symbol="+24V" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="GND" urn="urn:adsk.eagle:component:27037/1" prefix="SUPPLY" library_version="2">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="GND" symbol="GND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="VSS" urn="urn:adsk.eagle:component:27065/1" prefix="SUPPLY" library_version="2">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="VSS" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="JP1" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-2X24" device="" package3d_urn="urn:adsk.eagle:package:22452/2"/>
<part name="JP5" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X5" device="" package3d_urn="urn:adsk.eagle:package:22469/2"/>
<part name="JP6" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X5" device="" package3d_urn="urn:adsk.eagle:package:22469/2"/>
<part name="JP7" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X5" device="" package3d_urn="urn:adsk.eagle:package:22469/2"/>
<part name="JP8" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X5" device="" package3d_urn="urn:adsk.eagle:package:22469/2"/>
<part name="JP9" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X5" device="/90" package3d_urn="urn:adsk.eagle:package:22467/2"/>
<part name="JP10" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X5" device="/90" package3d_urn="urn:adsk.eagle:package:22467/2"/>
<part name="JP11" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X5" device="/90" package3d_urn="urn:adsk.eagle:package:22467/2"/>
<part name="JP12" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X5" device="/90" package3d_urn="urn:adsk.eagle:package:22467/2"/>
<part name="JP2" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-2X24" device="" package3d_urn="urn:adsk.eagle:package:22452/2"/>
<part name="JP3" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-2X24" device="" package3d_urn="urn:adsk.eagle:package:22452/2"/>
<part name="JP4" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-2X24" device="" package3d_urn="urn:adsk.eagle:package:22452/2"/>
<part name="SUPPLY1" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="+12V" device=""/>
<part name="SUPPLY2" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="+24V" device=""/>
<part name="SUPPLY3" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="GND" device=""/>
<part name="SUPPLY4" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="VSS" device=""/>
<part name="SUPPLY5" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="+12V" device=""/>
<part name="SUPPLY6" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="+12V" device=""/>
<part name="SUPPLY7" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="+12V" device=""/>
<part name="SUPPLY8" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="+24V" device=""/>
<part name="SUPPLY9" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="+24V" device=""/>
<part name="SUPPLY10" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="+24V" device=""/>
<part name="SUPPLY11" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="GND" device=""/>
<part name="SUPPLY12" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="GND" device=""/>
<part name="SUPPLY13" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="GND" device=""/>
<part name="SUPPLY14" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="VSS" device=""/>
<part name="SUPPLY15" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="VSS" device=""/>
<part name="SUPPLY16" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="VSS" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="JP1" gate="A" x="27.94" y="38.1" smashed="yes" rot="R180">
<attribute name="NAME" x="34.29" y="6.985" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="34.29" y="73.66" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="JP5" gate="A" x="12.7" y="88.9" smashed="yes" rot="R180">
<attribute name="NAME" x="19.05" y="80.645" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="19.05" y="99.06" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="JP6" gate="A" x="45.72" y="88.9" smashed="yes" rot="R180">
<attribute name="NAME" x="52.07" y="80.645" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="52.07" y="99.06" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="JP7" gate="A" x="78.74" y="88.9" smashed="yes" rot="R180">
<attribute name="NAME" x="85.09" y="80.645" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="85.09" y="99.06" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="JP8" gate="A" x="111.76" y="88.9" smashed="yes" rot="R180">
<attribute name="NAME" x="118.11" y="80.645" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="118.11" y="99.06" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="JP9" gate="A" x="38.1" y="88.9" smashed="yes">
<attribute name="NAME" x="31.75" y="97.155" size="1.778" layer="95"/>
<attribute name="VALUE" x="31.75" y="78.74" size="1.778" layer="96"/>
</instance>
<instance part="JP10" gate="A" x="71.12" y="88.9" smashed="yes">
<attribute name="NAME" x="64.77" y="97.155" size="1.778" layer="95"/>
<attribute name="VALUE" x="64.77" y="78.74" size="1.778" layer="96"/>
</instance>
<instance part="JP11" gate="A" x="104.14" y="88.9" smashed="yes">
<attribute name="NAME" x="97.79" y="97.155" size="1.778" layer="95"/>
<attribute name="VALUE" x="97.79" y="78.74" size="1.778" layer="96"/>
</instance>
<instance part="JP12" gate="A" x="137.16" y="88.9" smashed="yes">
<attribute name="NAME" x="130.81" y="97.155" size="1.778" layer="95"/>
<attribute name="VALUE" x="130.81" y="78.74" size="1.778" layer="96"/>
</instance>
<instance part="JP2" gate="A" x="60.96" y="38.1" smashed="yes" rot="R180">
<attribute name="NAME" x="67.31" y="6.985" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="67.31" y="73.66" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="JP3" gate="A" x="93.98" y="38.1" smashed="yes" rot="R180">
<attribute name="NAME" x="100.33" y="6.985" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="100.33" y="73.66" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="JP4" gate="A" x="127" y="38.1" smashed="yes" rot="R180">
<attribute name="NAME" x="133.35" y="6.985" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="133.35" y="73.66" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="SUPPLY1" gate="+12V" x="15.24" y="50.8" smashed="yes">
<attribute name="VALUE" x="12.7" y="53.975" size="1.778" layer="96"/>
</instance>
<instance part="SUPPLY2" gate="+24V" x="15.24" y="71.12" smashed="yes">
<attribute name="VALUE" x="12.7" y="74.295" size="1.778" layer="96"/>
</instance>
<instance part="SUPPLY3" gate="GND" x="15.24" y="7.62" smashed="yes">
<attribute name="VALUE" x="13.335" y="4.445" size="1.778" layer="96"/>
</instance>
<instance part="SUPPLY4" gate="G$1" x="25.4" y="81.28" smashed="yes">
<attribute name="VALUE" x="23.495" y="76.581" size="1.778" layer="96"/>
</instance>
<instance part="SUPPLY5" gate="+12V" x="48.26" y="50.8" smashed="yes">
<attribute name="VALUE" x="45.72" y="53.975" size="1.778" layer="96"/>
</instance>
<instance part="SUPPLY6" gate="+12V" x="81.28" y="50.8" smashed="yes">
<attribute name="VALUE" x="78.74" y="53.975" size="1.778" layer="96"/>
</instance>
<instance part="SUPPLY7" gate="+12V" x="114.3" y="50.8" smashed="yes">
<attribute name="VALUE" x="111.76" y="53.975" size="1.778" layer="96"/>
</instance>
<instance part="SUPPLY8" gate="+24V" x="48.26" y="71.12" smashed="yes">
<attribute name="VALUE" x="45.72" y="74.295" size="1.778" layer="96"/>
</instance>
<instance part="SUPPLY9" gate="+24V" x="81.28" y="71.12" smashed="yes">
<attribute name="VALUE" x="78.74" y="74.295" size="1.778" layer="96"/>
</instance>
<instance part="SUPPLY10" gate="+24V" x="114.3" y="71.12" smashed="yes">
<attribute name="VALUE" x="111.76" y="74.295" size="1.778" layer="96"/>
</instance>
<instance part="SUPPLY11" gate="GND" x="48.26" y="7.62" smashed="yes">
<attribute name="VALUE" x="46.355" y="4.445" size="1.778" layer="96"/>
</instance>
<instance part="SUPPLY12" gate="GND" x="81.28" y="7.62" smashed="yes">
<attribute name="VALUE" x="79.375" y="4.445" size="1.778" layer="96"/>
</instance>
<instance part="SUPPLY13" gate="GND" x="114.3" y="7.62" smashed="yes">
<attribute name="VALUE" x="112.395" y="4.445" size="1.778" layer="96"/>
</instance>
<instance part="SUPPLY14" gate="G$1" x="124.46" y="81.28" smashed="yes">
<attribute name="VALUE" x="122.555" y="76.581" size="1.778" layer="96"/>
</instance>
<instance part="SUPPLY15" gate="G$1" x="91.44" y="81.28" smashed="yes">
<attribute name="VALUE" x="89.535" y="76.581" size="1.778" layer="96"/>
</instance>
<instance part="SUPPLY16" gate="G$1" x="58.42" y="81.28" smashed="yes">
<attribute name="VALUE" x="56.515" y="76.581" size="1.778" layer="96"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="+12V" class="0">
<segment>
<pinref part="JP1" gate="A" pin="32"/>
<pinref part="JP1" gate="A" pin="31"/>
<wire x1="22.86" y1="48.26" x2="30.48" y2="48.26" width="0.1524" layer="91"/>
<pinref part="JP1" gate="A" pin="29"/>
<pinref part="JP1" gate="A" pin="30"/>
<wire x1="30.48" y1="45.72" x2="22.86" y2="45.72" width="0.1524" layer="91"/>
<pinref part="JP1" gate="A" pin="27"/>
<pinref part="JP1" gate="A" pin="28"/>
<wire x1="30.48" y1="43.18" x2="22.86" y2="43.18" width="0.1524" layer="91"/>
<pinref part="JP1" gate="A" pin="23"/>
<pinref part="JP1" gate="A" pin="24"/>
<wire x1="30.48" y1="38.1" x2="22.86" y2="38.1" width="0.1524" layer="91"/>
<pinref part="JP1" gate="A" pin="25"/>
<pinref part="JP1" gate="A" pin="26"/>
<wire x1="30.48" y1="40.64" x2="22.86" y2="40.64" width="0.1524" layer="91"/>
<wire x1="22.86" y1="38.1" x2="22.86" y2="40.64" width="0.1524" layer="91"/>
<junction x="22.86" y="38.1"/>
<junction x="22.86" y="40.64"/>
<wire x1="22.86" y1="43.18" x2="22.86" y2="40.64" width="0.1524" layer="91"/>
<junction x="22.86" y="43.18"/>
<wire x1="22.86" y1="45.72" x2="22.86" y2="43.18" width="0.1524" layer="91"/>
<junction x="22.86" y="45.72"/>
<wire x1="22.86" y1="48.26" x2="22.86" y2="45.72" width="0.1524" layer="91"/>
<junction x="22.86" y="48.26"/>
<pinref part="SUPPLY1" gate="+12V" pin="+12V"/>
<wire x1="15.24" y1="48.26" x2="22.86" y2="48.26" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="32"/>
<pinref part="JP2" gate="A" pin="31"/>
<wire x1="55.88" y1="48.26" x2="63.5" y2="48.26" width="0.1524" layer="91"/>
<pinref part="JP2" gate="A" pin="29"/>
<pinref part="JP2" gate="A" pin="30"/>
<wire x1="63.5" y1="45.72" x2="55.88" y2="45.72" width="0.1524" layer="91"/>
<wire x1="55.88" y1="48.26" x2="55.88" y2="45.72" width="0.1524" layer="91"/>
<junction x="55.88" y="48.26"/>
<junction x="55.88" y="45.72"/>
<pinref part="JP2" gate="A" pin="27"/>
<pinref part="JP2" gate="A" pin="28"/>
<wire x1="63.5" y1="43.18" x2="55.88" y2="43.18" width="0.1524" layer="91"/>
<wire x1="55.88" y1="45.72" x2="55.88" y2="43.18" width="0.1524" layer="91"/>
<junction x="55.88" y="43.18"/>
<pinref part="JP2" gate="A" pin="25"/>
<pinref part="JP2" gate="A" pin="26"/>
<wire x1="63.5" y1="40.64" x2="55.88" y2="40.64" width="0.1524" layer="91"/>
<wire x1="55.88" y1="43.18" x2="55.88" y2="40.64" width="0.1524" layer="91"/>
<junction x="55.88" y="40.64"/>
<pinref part="JP2" gate="A" pin="23"/>
<pinref part="JP2" gate="A" pin="24"/>
<wire x1="63.5" y1="38.1" x2="55.88" y2="38.1" width="0.1524" layer="91"/>
<wire x1="55.88" y1="40.64" x2="55.88" y2="38.1" width="0.1524" layer="91"/>
<junction x="55.88" y="38.1"/>
<pinref part="SUPPLY5" gate="+12V" pin="+12V"/>
<wire x1="48.26" y1="48.26" x2="55.88" y2="48.26" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="JP3" gate="A" pin="32"/>
<pinref part="JP3" gate="A" pin="31"/>
<wire x1="88.9" y1="48.26" x2="96.52" y2="48.26" width="0.1524" layer="91"/>
<pinref part="JP3" gate="A" pin="29"/>
<pinref part="JP3" gate="A" pin="30"/>
<wire x1="96.52" y1="45.72" x2="88.9" y2="45.72" width="0.1524" layer="91"/>
<wire x1="88.9" y1="48.26" x2="88.9" y2="45.72" width="0.1524" layer="91"/>
<junction x="88.9" y="48.26"/>
<junction x="88.9" y="45.72"/>
<pinref part="JP3" gate="A" pin="27"/>
<pinref part="JP3" gate="A" pin="28"/>
<wire x1="96.52" y1="43.18" x2="88.9" y2="43.18" width="0.1524" layer="91"/>
<wire x1="88.9" y1="45.72" x2="88.9" y2="43.18" width="0.1524" layer="91"/>
<junction x="88.9" y="43.18"/>
<pinref part="JP3" gate="A" pin="25"/>
<pinref part="JP3" gate="A" pin="26"/>
<wire x1="96.52" y1="40.64" x2="88.9" y2="40.64" width="0.1524" layer="91"/>
<wire x1="88.9" y1="43.18" x2="88.9" y2="40.64" width="0.1524" layer="91"/>
<junction x="88.9" y="40.64"/>
<pinref part="JP3" gate="A" pin="23"/>
<pinref part="JP3" gate="A" pin="24"/>
<wire x1="96.52" y1="38.1" x2="88.9" y2="38.1" width="0.1524" layer="91"/>
<wire x1="88.9" y1="40.64" x2="88.9" y2="38.1" width="0.1524" layer="91"/>
<junction x="88.9" y="38.1"/>
<pinref part="SUPPLY6" gate="+12V" pin="+12V"/>
<wire x1="81.28" y1="48.26" x2="88.9" y2="48.26" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="JP4" gate="A" pin="32"/>
<pinref part="JP4" gate="A" pin="31"/>
<wire x1="121.92" y1="48.26" x2="129.54" y2="48.26" width="0.1524" layer="91"/>
<pinref part="JP4" gate="A" pin="29"/>
<pinref part="JP4" gate="A" pin="30"/>
<wire x1="129.54" y1="45.72" x2="121.92" y2="45.72" width="0.1524" layer="91"/>
<wire x1="121.92" y1="48.26" x2="121.92" y2="45.72" width="0.1524" layer="91"/>
<junction x="121.92" y="48.26"/>
<junction x="121.92" y="45.72"/>
<pinref part="JP4" gate="A" pin="27"/>
<pinref part="JP4" gate="A" pin="28"/>
<wire x1="129.54" y1="43.18" x2="121.92" y2="43.18" width="0.1524" layer="91"/>
<wire x1="121.92" y1="45.72" x2="121.92" y2="43.18" width="0.1524" layer="91"/>
<junction x="121.92" y="43.18"/>
<pinref part="JP4" gate="A" pin="25"/>
<pinref part="JP4" gate="A" pin="26"/>
<wire x1="129.54" y1="40.64" x2="121.92" y2="40.64" width="0.1524" layer="91"/>
<wire x1="121.92" y1="43.18" x2="121.92" y2="40.64" width="0.1524" layer="91"/>
<junction x="121.92" y="40.64"/>
<pinref part="JP4" gate="A" pin="23"/>
<pinref part="JP4" gate="A" pin="24"/>
<wire x1="129.54" y1="38.1" x2="121.92" y2="38.1" width="0.1524" layer="91"/>
<wire x1="121.92" y1="40.64" x2="121.92" y2="38.1" width="0.1524" layer="91"/>
<junction x="121.92" y="38.1"/>
<pinref part="SUPPLY7" gate="+12V" pin="+12V"/>
<wire x1="121.92" y1="48.26" x2="114.3" y2="48.26" width="0.1524" layer="91"/>
</segment>
</net>
<net name="+24V" class="0">
<segment>
<pinref part="JP1" gate="A" pin="36"/>
<pinref part="JP1" gate="A" pin="35"/>
<wire x1="22.86" y1="53.34" x2="30.48" y2="53.34" width="0.1524" layer="91"/>
<pinref part="JP1" gate="A" pin="40"/>
<pinref part="JP1" gate="A" pin="39"/>
<wire x1="22.86" y1="58.42" x2="30.48" y2="58.42" width="0.1524" layer="91"/>
<pinref part="JP1" gate="A" pin="41"/>
<pinref part="JP1" gate="A" pin="42"/>
<wire x1="30.48" y1="60.96" x2="22.86" y2="60.96" width="0.1524" layer="91"/>
<pinref part="JP1" gate="A" pin="48"/>
<pinref part="JP1" gate="A" pin="47"/>
<wire x1="22.86" y1="68.58" x2="30.48" y2="68.58" width="0.1524" layer="91"/>
<pinref part="JP1" gate="A" pin="45"/>
<pinref part="JP1" gate="A" pin="46"/>
<wire x1="30.48" y1="66.04" x2="22.86" y2="66.04" width="0.1524" layer="91"/>
<wire x1="22.86" y1="68.58" x2="22.86" y2="66.04" width="0.1524" layer="91"/>
<junction x="22.86" y="68.58"/>
<junction x="22.86" y="66.04"/>
<pinref part="JP1" gate="A" pin="44"/>
<pinref part="JP1" gate="A" pin="43"/>
<wire x1="22.86" y1="63.5" x2="30.48" y2="63.5" width="0.1524" layer="91"/>
<wire x1="22.86" y1="66.04" x2="22.86" y2="63.5" width="0.1524" layer="91"/>
<junction x="22.86" y="63.5"/>
<wire x1="22.86" y1="60.96" x2="22.86" y2="63.5" width="0.1524" layer="91"/>
<junction x="22.86" y="60.96"/>
<wire x1="22.86" y1="58.42" x2="22.86" y2="60.96" width="0.1524" layer="91"/>
<junction x="22.86" y="58.42"/>
<pinref part="JP1" gate="A" pin="37"/>
<pinref part="JP1" gate="A" pin="38"/>
<wire x1="30.48" y1="55.88" x2="22.86" y2="55.88" width="0.1524" layer="91"/>
<wire x1="22.86" y1="58.42" x2="22.86" y2="55.88" width="0.1524" layer="91"/>
<junction x="22.86" y="55.88"/>
<wire x1="22.86" y1="53.34" x2="22.86" y2="55.88" width="0.1524" layer="91"/>
<junction x="22.86" y="53.34"/>
<pinref part="JP1" gate="A" pin="34"/>
<pinref part="JP1" gate="A" pin="33"/>
<wire x1="30.48" y1="50.8" x2="22.86" y2="50.8" width="0.1524" layer="91"/>
<wire x1="22.86" y1="53.34" x2="22.86" y2="50.8" width="0.1524" layer="91"/>
<junction x="22.86" y="50.8"/>
<pinref part="SUPPLY2" gate="+24V" pin="+24V"/>
<wire x1="22.86" y1="68.58" x2="15.24" y2="68.58" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="48"/>
<pinref part="JP2" gate="A" pin="47"/>
<wire x1="55.88" y1="68.58" x2="63.5" y2="68.58" width="0.1524" layer="91"/>
<pinref part="JP2" gate="A" pin="45"/>
<pinref part="JP2" gate="A" pin="46"/>
<wire x1="63.5" y1="66.04" x2="55.88" y2="66.04" width="0.1524" layer="91"/>
<wire x1="55.88" y1="68.58" x2="55.88" y2="66.04" width="0.1524" layer="91"/>
<junction x="55.88" y="68.58"/>
<junction x="55.88" y="66.04"/>
<pinref part="JP2" gate="A" pin="44"/>
<pinref part="JP2" gate="A" pin="43"/>
<wire x1="55.88" y1="63.5" x2="63.5" y2="63.5" width="0.1524" layer="91"/>
<wire x1="55.88" y1="66.04" x2="55.88" y2="63.5" width="0.1524" layer="91"/>
<junction x="55.88" y="63.5"/>
<pinref part="JP2" gate="A" pin="41"/>
<pinref part="JP2" gate="A" pin="42"/>
<wire x1="63.5" y1="60.96" x2="55.88" y2="60.96" width="0.1524" layer="91"/>
<wire x1="55.88" y1="63.5" x2="55.88" y2="60.96" width="0.1524" layer="91"/>
<junction x="55.88" y="60.96"/>
<pinref part="JP2" gate="A" pin="40"/>
<pinref part="JP2" gate="A" pin="39"/>
<wire x1="55.88" y1="58.42" x2="63.5" y2="58.42" width="0.1524" layer="91"/>
<wire x1="55.88" y1="60.96" x2="55.88" y2="58.42" width="0.1524" layer="91"/>
<junction x="55.88" y="58.42"/>
<pinref part="JP2" gate="A" pin="37"/>
<pinref part="JP2" gate="A" pin="38"/>
<wire x1="63.5" y1="55.88" x2="55.88" y2="55.88" width="0.1524" layer="91"/>
<wire x1="55.88" y1="58.42" x2="55.88" y2="55.88" width="0.1524" layer="91"/>
<junction x="55.88" y="55.88"/>
<pinref part="JP2" gate="A" pin="36"/>
<pinref part="JP2" gate="A" pin="35"/>
<wire x1="55.88" y1="53.34" x2="63.5" y2="53.34" width="0.1524" layer="91"/>
<wire x1="55.88" y1="55.88" x2="55.88" y2="53.34" width="0.1524" layer="91"/>
<junction x="55.88" y="53.34"/>
<pinref part="JP2" gate="A" pin="33"/>
<pinref part="JP2" gate="A" pin="34"/>
<wire x1="63.5" y1="50.8" x2="55.88" y2="50.8" width="0.1524" layer="91"/>
<wire x1="55.88" y1="53.34" x2="55.88" y2="50.8" width="0.1524" layer="91"/>
<junction x="55.88" y="50.8"/>
<pinref part="SUPPLY8" gate="+24V" pin="+24V"/>
<wire x1="55.88" y1="68.58" x2="48.26" y2="68.58" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="JP3" gate="A" pin="48"/>
<pinref part="JP3" gate="A" pin="47"/>
<wire x1="88.9" y1="68.58" x2="96.52" y2="68.58" width="0.1524" layer="91"/>
<pinref part="JP3" gate="A" pin="45"/>
<pinref part="JP3" gate="A" pin="46"/>
<wire x1="96.52" y1="66.04" x2="88.9" y2="66.04" width="0.1524" layer="91"/>
<wire x1="88.9" y1="68.58" x2="88.9" y2="66.04" width="0.1524" layer="91"/>
<junction x="88.9" y="68.58"/>
<junction x="88.9" y="66.04"/>
<pinref part="JP3" gate="A" pin="44"/>
<pinref part="JP3" gate="A" pin="43"/>
<wire x1="88.9" y1="63.5" x2="96.52" y2="63.5" width="0.1524" layer="91"/>
<wire x1="88.9" y1="66.04" x2="88.9" y2="63.5" width="0.1524" layer="91"/>
<junction x="88.9" y="63.5"/>
<pinref part="JP3" gate="A" pin="41"/>
<pinref part="JP3" gate="A" pin="42"/>
<wire x1="96.52" y1="60.96" x2="88.9" y2="60.96" width="0.1524" layer="91"/>
<wire x1="88.9" y1="63.5" x2="88.9" y2="60.96" width="0.1524" layer="91"/>
<junction x="88.9" y="60.96"/>
<pinref part="JP3" gate="A" pin="40"/>
<pinref part="JP3" gate="A" pin="39"/>
<wire x1="88.9" y1="58.42" x2="96.52" y2="58.42" width="0.1524" layer="91"/>
<wire x1="88.9" y1="60.96" x2="88.9" y2="58.42" width="0.1524" layer="91"/>
<junction x="88.9" y="58.42"/>
<pinref part="JP3" gate="A" pin="37"/>
<pinref part="JP3" gate="A" pin="38"/>
<wire x1="96.52" y1="55.88" x2="88.9" y2="55.88" width="0.1524" layer="91"/>
<wire x1="88.9" y1="58.42" x2="88.9" y2="55.88" width="0.1524" layer="91"/>
<junction x="88.9" y="55.88"/>
<pinref part="JP3" gate="A" pin="36"/>
<pinref part="JP3" gate="A" pin="35"/>
<wire x1="88.9" y1="53.34" x2="96.52" y2="53.34" width="0.1524" layer="91"/>
<wire x1="88.9" y1="55.88" x2="88.9" y2="53.34" width="0.1524" layer="91"/>
<junction x="88.9" y="53.34"/>
<pinref part="JP3" gate="A" pin="33"/>
<pinref part="JP3" gate="A" pin="34"/>
<wire x1="96.52" y1="50.8" x2="88.9" y2="50.8" width="0.1524" layer="91"/>
<wire x1="88.9" y1="53.34" x2="88.9" y2="50.8" width="0.1524" layer="91"/>
<junction x="88.9" y="50.8"/>
<pinref part="SUPPLY9" gate="+24V" pin="+24V"/>
<wire x1="88.9" y1="68.58" x2="81.28" y2="68.58" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="JP4" gate="A" pin="33"/>
<pinref part="JP4" gate="A" pin="34"/>
<wire x1="129.54" y1="50.8" x2="121.92" y2="50.8" width="0.1524" layer="91"/>
<pinref part="JP4" gate="A" pin="36"/>
<pinref part="JP4" gate="A" pin="35"/>
<wire x1="121.92" y1="53.34" x2="129.54" y2="53.34" width="0.1524" layer="91"/>
<pinref part="JP4" gate="A" pin="48"/>
<pinref part="JP4" gate="A" pin="47"/>
<wire x1="121.92" y1="68.58" x2="129.54" y2="68.58" width="0.1524" layer="91"/>
<pinref part="JP4" gate="A" pin="45"/>
<pinref part="JP4" gate="A" pin="46"/>
<wire x1="129.54" y1="66.04" x2="121.92" y2="66.04" width="0.1524" layer="91"/>
<wire x1="121.92" y1="68.58" x2="121.92" y2="66.04" width="0.1524" layer="91"/>
<junction x="121.92" y="68.58"/>
<junction x="121.92" y="66.04"/>
<pinref part="JP4" gate="A" pin="44"/>
<pinref part="JP4" gate="A" pin="43"/>
<wire x1="121.92" y1="63.5" x2="129.54" y2="63.5" width="0.1524" layer="91"/>
<wire x1="121.92" y1="66.04" x2="121.92" y2="63.5" width="0.1524" layer="91"/>
<junction x="121.92" y="63.5"/>
<pinref part="JP4" gate="A" pin="41"/>
<pinref part="JP4" gate="A" pin="42"/>
<wire x1="129.54" y1="60.96" x2="121.92" y2="60.96" width="0.1524" layer="91"/>
<wire x1="121.92" y1="63.5" x2="121.92" y2="60.96" width="0.1524" layer="91"/>
<junction x="121.92" y="60.96"/>
<pinref part="JP4" gate="A" pin="40"/>
<pinref part="JP4" gate="A" pin="39"/>
<wire x1="121.92" y1="58.42" x2="129.54" y2="58.42" width="0.1524" layer="91"/>
<wire x1="121.92" y1="60.96" x2="121.92" y2="58.42" width="0.1524" layer="91"/>
<junction x="121.92" y="58.42"/>
<pinref part="JP4" gate="A" pin="37"/>
<pinref part="JP4" gate="A" pin="38"/>
<wire x1="129.54" y1="55.88" x2="121.92" y2="55.88" width="0.1524" layer="91"/>
<wire x1="121.92" y1="58.42" x2="121.92" y2="55.88" width="0.1524" layer="91"/>
<junction x="121.92" y="55.88"/>
<wire x1="121.92" y1="53.34" x2="121.92" y2="55.88" width="0.1524" layer="91"/>
<junction x="121.92" y="53.34"/>
<wire x1="121.92" y1="50.8" x2="121.92" y2="53.34" width="0.1524" layer="91"/>
<junction x="121.92" y="50.8"/>
<pinref part="SUPPLY10" gate="+24V" pin="+24V"/>
<wire x1="121.92" y1="68.58" x2="114.3" y2="68.58" width="0.1524" layer="91"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="JP1" gate="A" pin="22"/>
<pinref part="JP1" gate="A" pin="21"/>
<wire x1="22.86" y1="35.56" x2="30.48" y2="35.56" width="0.1524" layer="91"/>
<pinref part="JP1" gate="A" pin="19"/>
<pinref part="JP1" gate="A" pin="20"/>
<wire x1="30.48" y1="33.02" x2="22.86" y2="33.02" width="0.1524" layer="91"/>
<pinref part="JP1" gate="A" pin="18"/>
<pinref part="JP1" gate="A" pin="17"/>
<wire x1="22.86" y1="30.48" x2="30.48" y2="30.48" width="0.1524" layer="91"/>
<pinref part="JP1" gate="A" pin="15"/>
<pinref part="JP1" gate="A" pin="16"/>
<wire x1="30.48" y1="27.94" x2="22.86" y2="27.94" width="0.1524" layer="91"/>
<pinref part="JP1" gate="A" pin="1"/>
<pinref part="JP1" gate="A" pin="2"/>
<wire x1="30.48" y1="10.16" x2="22.86" y2="10.16" width="0.1524" layer="91"/>
<pinref part="JP1" gate="A" pin="4"/>
<pinref part="JP1" gate="A" pin="3"/>
<wire x1="22.86" y1="12.7" x2="30.48" y2="12.7" width="0.1524" layer="91"/>
<wire x1="22.86" y1="10.16" x2="22.86" y2="12.7" width="0.1524" layer="91"/>
<junction x="22.86" y="10.16"/>
<junction x="22.86" y="12.7"/>
<pinref part="JP1" gate="A" pin="5"/>
<pinref part="JP1" gate="A" pin="6"/>
<wire x1="30.48" y1="15.24" x2="22.86" y2="15.24" width="0.1524" layer="91"/>
<wire x1="22.86" y1="12.7" x2="22.86" y2="15.24" width="0.1524" layer="91"/>
<junction x="22.86" y="15.24"/>
<pinref part="JP1" gate="A" pin="7"/>
<pinref part="JP1" gate="A" pin="8"/>
<wire x1="30.48" y1="17.78" x2="22.86" y2="17.78" width="0.1524" layer="91"/>
<wire x1="22.86" y1="15.24" x2="22.86" y2="17.78" width="0.1524" layer="91"/>
<junction x="22.86" y="17.78"/>
<pinref part="JP1" gate="A" pin="10"/>
<pinref part="JP1" gate="A" pin="9"/>
<wire x1="22.86" y1="20.32" x2="30.48" y2="20.32" width="0.1524" layer="91"/>
<wire x1="22.86" y1="17.78" x2="22.86" y2="20.32" width="0.1524" layer="91"/>
<junction x="22.86" y="20.32"/>
<pinref part="JP1" gate="A" pin="11"/>
<pinref part="JP1" gate="A" pin="12"/>
<wire x1="30.48" y1="22.86" x2="22.86" y2="22.86" width="0.1524" layer="91"/>
<wire x1="22.86" y1="20.32" x2="22.86" y2="22.86" width="0.1524" layer="91"/>
<junction x="22.86" y="22.86"/>
<pinref part="JP1" gate="A" pin="14"/>
<pinref part="JP1" gate="A" pin="13"/>
<wire x1="22.86" y1="25.4" x2="30.48" y2="25.4" width="0.1524" layer="91"/>
<wire x1="22.86" y1="22.86" x2="22.86" y2="25.4" width="0.1524" layer="91"/>
<junction x="22.86" y="25.4"/>
<wire x1="22.86" y1="27.94" x2="22.86" y2="25.4" width="0.1524" layer="91"/>
<junction x="22.86" y="27.94"/>
<wire x1="22.86" y1="30.48" x2="22.86" y2="27.94" width="0.1524" layer="91"/>
<junction x="22.86" y="30.48"/>
<wire x1="22.86" y1="33.02" x2="22.86" y2="30.48" width="0.1524" layer="91"/>
<junction x="22.86" y="33.02"/>
<wire x1="22.86" y1="35.56" x2="22.86" y2="33.02" width="0.1524" layer="91"/>
<junction x="22.86" y="35.56"/>
<pinref part="SUPPLY3" gate="GND" pin="GND"/>
<wire x1="22.86" y1="10.16" x2="15.24" y2="10.16" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="JP2" gate="A" pin="22"/>
<pinref part="JP2" gate="A" pin="21"/>
<wire x1="55.88" y1="35.56" x2="63.5" y2="35.56" width="0.1524" layer="91"/>
<pinref part="JP2" gate="A" pin="19"/>
<pinref part="JP2" gate="A" pin="20"/>
<wire x1="63.5" y1="33.02" x2="55.88" y2="33.02" width="0.1524" layer="91"/>
<wire x1="55.88" y1="35.56" x2="55.88" y2="33.02" width="0.1524" layer="91"/>
<junction x="55.88" y="35.56"/>
<junction x="55.88" y="33.02"/>
<pinref part="JP2" gate="A" pin="18"/>
<pinref part="JP2" gate="A" pin="17"/>
<wire x1="55.88" y1="30.48" x2="63.5" y2="30.48" width="0.1524" layer="91"/>
<wire x1="55.88" y1="33.02" x2="55.88" y2="30.48" width="0.1524" layer="91"/>
<junction x="55.88" y="30.48"/>
<pinref part="JP2" gate="A" pin="15"/>
<pinref part="JP2" gate="A" pin="16"/>
<wire x1="63.5" y1="27.94" x2="55.88" y2="27.94" width="0.1524" layer="91"/>
<wire x1="55.88" y1="30.48" x2="55.88" y2="27.94" width="0.1524" layer="91"/>
<junction x="55.88" y="27.94"/>
<pinref part="JP2" gate="A" pin="14"/>
<pinref part="JP2" gate="A" pin="13"/>
<wire x1="55.88" y1="25.4" x2="63.5" y2="25.4" width="0.1524" layer="91"/>
<wire x1="55.88" y1="27.94" x2="55.88" y2="25.4" width="0.1524" layer="91"/>
<junction x="55.88" y="25.4"/>
<pinref part="JP2" gate="A" pin="11"/>
<pinref part="JP2" gate="A" pin="12"/>
<wire x1="63.5" y1="22.86" x2="55.88" y2="22.86" width="0.1524" layer="91"/>
<wire x1="55.88" y1="25.4" x2="55.88" y2="22.86" width="0.1524" layer="91"/>
<junction x="55.88" y="22.86"/>
<pinref part="JP2" gate="A" pin="10"/>
<pinref part="JP2" gate="A" pin="9"/>
<wire x1="55.88" y1="20.32" x2="63.5" y2="20.32" width="0.1524" layer="91"/>
<wire x1="55.88" y1="22.86" x2="55.88" y2="20.32" width="0.1524" layer="91"/>
<junction x="55.88" y="20.32"/>
<pinref part="JP2" gate="A" pin="7"/>
<pinref part="JP2" gate="A" pin="8"/>
<wire x1="63.5" y1="17.78" x2="55.88" y2="17.78" width="0.1524" layer="91"/>
<wire x1="55.88" y1="20.32" x2="55.88" y2="17.78" width="0.1524" layer="91"/>
<junction x="55.88" y="17.78"/>
<pinref part="JP2" gate="A" pin="5"/>
<pinref part="JP2" gate="A" pin="6"/>
<wire x1="63.5" y1="15.24" x2="55.88" y2="15.24" width="0.1524" layer="91"/>
<wire x1="55.88" y1="17.78" x2="55.88" y2="15.24" width="0.1524" layer="91"/>
<junction x="55.88" y="15.24"/>
<pinref part="JP2" gate="A" pin="4"/>
<pinref part="JP2" gate="A" pin="3"/>
<wire x1="55.88" y1="12.7" x2="63.5" y2="12.7" width="0.1524" layer="91"/>
<wire x1="55.88" y1="15.24" x2="55.88" y2="12.7" width="0.1524" layer="91"/>
<junction x="55.88" y="12.7"/>
<pinref part="JP2" gate="A" pin="1"/>
<pinref part="JP2" gate="A" pin="2"/>
<wire x1="63.5" y1="10.16" x2="55.88" y2="10.16" width="0.1524" layer="91"/>
<wire x1="55.88" y1="12.7" x2="55.88" y2="10.16" width="0.1524" layer="91"/>
<junction x="55.88" y="10.16"/>
<pinref part="SUPPLY11" gate="GND" pin="GND"/>
<wire x1="55.88" y1="10.16" x2="48.26" y2="10.16" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="JP3" gate="A" pin="1"/>
<pinref part="JP3" gate="A" pin="2"/>
<wire x1="96.52" y1="10.16" x2="88.9" y2="10.16" width="0.1524" layer="91"/>
<pinref part="JP3" gate="A" pin="4"/>
<pinref part="JP3" gate="A" pin="3"/>
<wire x1="88.9" y1="12.7" x2="96.52" y2="12.7" width="0.1524" layer="91"/>
<pinref part="JP3" gate="A" pin="5"/>
<pinref part="JP3" gate="A" pin="6"/>
<wire x1="96.52" y1="15.24" x2="88.9" y2="15.24" width="0.1524" layer="91"/>
<pinref part="JP3" gate="A" pin="7"/>
<pinref part="JP3" gate="A" pin="8"/>
<wire x1="96.52" y1="17.78" x2="88.9" y2="17.78" width="0.1524" layer="91"/>
<pinref part="JP3" gate="A" pin="11"/>
<pinref part="JP3" gate="A" pin="12"/>
<wire x1="96.52" y1="22.86" x2="88.9" y2="22.86" width="0.1524" layer="91"/>
<pinref part="JP3" gate="A" pin="15"/>
<pinref part="JP3" gate="A" pin="16"/>
<wire x1="96.52" y1="27.94" x2="88.9" y2="27.94" width="0.1524" layer="91"/>
<pinref part="JP3" gate="A" pin="19"/>
<pinref part="JP3" gate="A" pin="20"/>
<wire x1="96.52" y1="33.02" x2="88.9" y2="33.02" width="0.1524" layer="91"/>
<pinref part="JP3" gate="A" pin="22"/>
<pinref part="JP3" gate="A" pin="21"/>
<wire x1="88.9" y1="35.56" x2="96.52" y2="35.56" width="0.1524" layer="91"/>
<pinref part="JP3" gate="A" pin="18"/>
<pinref part="JP3" gate="A" pin="17"/>
<wire x1="88.9" y1="30.48" x2="96.52" y2="30.48" width="0.1524" layer="91"/>
<junction x="88.9" y="35.56"/>
<junction x="88.9" y="30.48"/>
<wire x1="88.9" y1="33.02" x2="88.9" y2="30.48" width="0.1524" layer="91"/>
<wire x1="88.9" y1="33.02" x2="88.9" y2="35.56" width="0.1524" layer="91"/>
<junction x="88.9" y="33.02"/>
<wire x1="88.9" y1="27.94" x2="88.9" y2="30.48" width="0.1524" layer="91"/>
<junction x="88.9" y="27.94"/>
<pinref part="JP3" gate="A" pin="14"/>
<pinref part="JP3" gate="A" pin="13"/>
<wire x1="88.9" y1="25.4" x2="96.52" y2="25.4" width="0.1524" layer="91"/>
<wire x1="88.9" y1="27.94" x2="88.9" y2="25.4" width="0.1524" layer="91"/>
<junction x="88.9" y="25.4"/>
<wire x1="88.9" y1="22.86" x2="88.9" y2="25.4" width="0.1524" layer="91"/>
<junction x="88.9" y="22.86"/>
<pinref part="JP3" gate="A" pin="10"/>
<pinref part="JP3" gate="A" pin="9"/>
<wire x1="88.9" y1="20.32" x2="96.52" y2="20.32" width="0.1524" layer="91"/>
<wire x1="88.9" y1="22.86" x2="88.9" y2="20.32" width="0.1524" layer="91"/>
<junction x="88.9" y="20.32"/>
<wire x1="88.9" y1="17.78" x2="88.9" y2="20.32" width="0.1524" layer="91"/>
<junction x="88.9" y="17.78"/>
<wire x1="88.9" y1="15.24" x2="88.9" y2="17.78" width="0.1524" layer="91"/>
<junction x="88.9" y="15.24"/>
<wire x1="88.9" y1="12.7" x2="88.9" y2="15.24" width="0.1524" layer="91"/>
<junction x="88.9" y="12.7"/>
<wire x1="88.9" y1="10.16" x2="88.9" y2="12.7" width="0.1524" layer="91"/>
<junction x="88.9" y="10.16"/>
<pinref part="SUPPLY12" gate="GND" pin="GND"/>
<wire x1="88.9" y1="10.16" x2="81.28" y2="10.16" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="JP4" gate="A" pin="22"/>
<pinref part="JP4" gate="A" pin="21"/>
<wire x1="121.92" y1="35.56" x2="129.54" y2="35.56" width="0.1524" layer="91"/>
<pinref part="JP4" gate="A" pin="19"/>
<pinref part="JP4" gate="A" pin="20"/>
<wire x1="129.54" y1="33.02" x2="121.92" y2="33.02" width="0.1524" layer="91"/>
<wire x1="121.92" y1="35.56" x2="121.92" y2="33.02" width="0.1524" layer="91"/>
<junction x="121.92" y="35.56"/>
<junction x="121.92" y="33.02"/>
<pinref part="JP4" gate="A" pin="18"/>
<pinref part="JP4" gate="A" pin="17"/>
<wire x1="121.92" y1="30.48" x2="129.54" y2="30.48" width="0.1524" layer="91"/>
<wire x1="121.92" y1="33.02" x2="121.92" y2="30.48" width="0.1524" layer="91"/>
<junction x="121.92" y="30.48"/>
<pinref part="JP4" gate="A" pin="15"/>
<pinref part="JP4" gate="A" pin="16"/>
<wire x1="129.54" y1="27.94" x2="121.92" y2="27.94" width="0.1524" layer="91"/>
<wire x1="121.92" y1="30.48" x2="121.92" y2="27.94" width="0.1524" layer="91"/>
<junction x="121.92" y="27.94"/>
<pinref part="JP4" gate="A" pin="14"/>
<pinref part="JP4" gate="A" pin="13"/>
<wire x1="121.92" y1="25.4" x2="129.54" y2="25.4" width="0.1524" layer="91"/>
<wire x1="121.92" y1="27.94" x2="121.92" y2="25.4" width="0.1524" layer="91"/>
<junction x="121.92" y="25.4"/>
<pinref part="JP4" gate="A" pin="11"/>
<pinref part="JP4" gate="A" pin="12"/>
<wire x1="129.54" y1="22.86" x2="121.92" y2="22.86" width="0.1524" layer="91"/>
<wire x1="121.92" y1="25.4" x2="121.92" y2="22.86" width="0.1524" layer="91"/>
<junction x="121.92" y="22.86"/>
<pinref part="JP4" gate="A" pin="10"/>
<pinref part="JP4" gate="A" pin="9"/>
<wire x1="121.92" y1="20.32" x2="129.54" y2="20.32" width="0.1524" layer="91"/>
<wire x1="121.92" y1="22.86" x2="121.92" y2="20.32" width="0.1524" layer="91"/>
<junction x="121.92" y="20.32"/>
<pinref part="JP4" gate="A" pin="7"/>
<pinref part="JP4" gate="A" pin="8"/>
<wire x1="129.54" y1="17.78" x2="121.92" y2="17.78" width="0.1524" layer="91"/>
<wire x1="121.92" y1="20.32" x2="121.92" y2="17.78" width="0.1524" layer="91"/>
<junction x="121.92" y="17.78"/>
<pinref part="JP4" gate="A" pin="5"/>
<pinref part="JP4" gate="A" pin="6"/>
<wire x1="129.54" y1="15.24" x2="121.92" y2="15.24" width="0.1524" layer="91"/>
<wire x1="121.92" y1="17.78" x2="121.92" y2="15.24" width="0.1524" layer="91"/>
<junction x="121.92" y="15.24"/>
<pinref part="JP4" gate="A" pin="4"/>
<pinref part="JP4" gate="A" pin="3"/>
<wire x1="121.92" y1="12.7" x2="129.54" y2="12.7" width="0.1524" layer="91"/>
<wire x1="121.92" y1="15.24" x2="121.92" y2="12.7" width="0.1524" layer="91"/>
<junction x="121.92" y="12.7"/>
<pinref part="JP4" gate="A" pin="1"/>
<pinref part="JP4" gate="A" pin="2"/>
<wire x1="129.54" y1="10.16" x2="121.92" y2="10.16" width="0.1524" layer="91"/>
<wire x1="121.92" y1="12.7" x2="121.92" y2="10.16" width="0.1524" layer="91"/>
<junction x="121.92" y="10.16"/>
<pinref part="SUPPLY13" gate="GND" pin="GND"/>
<wire x1="121.92" y1="10.16" x2="114.3" y2="10.16" width="0.1524" layer="91"/>
</segment>
</net>
<net name="VSS" class="0">
<segment>
<pinref part="JP8" gate="A" pin="1"/>
<pinref part="SUPPLY14" gate="G$1" pin="VSS"/>
<wire x1="124.46" y1="83.82" x2="114.3" y2="83.82" width="0.1524" layer="91"/>
<pinref part="JP12" gate="A" pin="5"/>
<wire x1="134.62" y1="83.82" x2="124.46" y2="83.82" width="0.1524" layer="91"/>
<junction x="124.46" y="83.82"/>
</segment>
<segment>
<pinref part="JP7" gate="A" pin="1"/>
<pinref part="SUPPLY15" gate="G$1" pin="VSS"/>
<wire x1="91.44" y1="83.82" x2="81.28" y2="83.82" width="0.1524" layer="91"/>
<pinref part="JP11" gate="A" pin="5"/>
<wire x1="101.6" y1="83.82" x2="91.44" y2="83.82" width="0.1524" layer="91"/>
<junction x="91.44" y="83.82"/>
</segment>
<segment>
<pinref part="JP6" gate="A" pin="1"/>
<pinref part="SUPPLY16" gate="G$1" pin="VSS"/>
<wire x1="58.42" y1="83.82" x2="48.26" y2="83.82" width="0.1524" layer="91"/>
<pinref part="JP10" gate="A" pin="5"/>
<wire x1="68.58" y1="83.82" x2="58.42" y2="83.82" width="0.1524" layer="91"/>
<junction x="58.42" y="83.82"/>
</segment>
<segment>
<pinref part="JP5" gate="A" pin="1"/>
<pinref part="SUPPLY4" gate="G$1" pin="VSS"/>
<wire x1="25.4" y1="83.82" x2="15.24" y2="83.82" width="0.1524" layer="91"/>
<pinref part="JP9" gate="A" pin="5"/>
<wire x1="35.56" y1="83.82" x2="25.4" y2="83.82" width="0.1524" layer="91"/>
<junction x="25.4" y="83.82"/>
</segment>
</net>
<net name="PWM1-1" class="0">
<segment>
<pinref part="JP5" gate="A" pin="3"/>
<wire x1="15.24" y1="88.9" x2="35.56" y2="88.9" width="0.1524" layer="91"/>
<label x="20.32" y="88.9" size="1.778" layer="95"/>
<pinref part="JP9" gate="A" pin="3"/>
</segment>
</net>
<net name="PWM2-2" class="0">
<segment>
<pinref part="JP6" gate="A" pin="2"/>
<wire x1="48.26" y1="86.36" x2="68.58" y2="86.36" width="0.1524" layer="91"/>
<label x="53.34" y="86.36" size="1.778" layer="95"/>
<pinref part="JP10" gate="A" pin="4"/>
</segment>
</net>
<net name="PWM3-1" class="0">
<segment>
<pinref part="JP7" gate="A" pin="3"/>
<wire x1="81.28" y1="88.9" x2="101.6" y2="88.9" width="0.1524" layer="91"/>
<label x="86.36" y="88.9" size="1.778" layer="95"/>
<pinref part="JP11" gate="A" pin="3"/>
</segment>
</net>
<net name="PWM3-2" class="0">
<segment>
<pinref part="JP7" gate="A" pin="2"/>
<wire x1="81.28" y1="86.36" x2="101.6" y2="86.36" width="0.1524" layer="91"/>
<label x="86.36" y="86.36" size="1.778" layer="95"/>
<pinref part="JP11" gate="A" pin="4"/>
</segment>
</net>
<net name="PWM4-1" class="0">
<segment>
<pinref part="JP8" gate="A" pin="3"/>
<wire x1="114.3" y1="88.9" x2="127" y2="88.9" width="0.1524" layer="91"/>
<label x="119.38" y="88.9" size="1.778" layer="95"/>
<pinref part="JP12" gate="A" pin="3"/>
<wire x1="127" y1="88.9" x2="129.54" y2="88.9" width="0.1524" layer="91"/>
<wire x1="134.62" y1="88.9" x2="129.54" y2="88.9" width="0.1524" layer="91"/>
</segment>
</net>
<net name="PWM4-2" class="0">
<segment>
<pinref part="JP8" gate="A" pin="2"/>
<wire x1="114.3" y1="86.36" x2="134.62" y2="86.36" width="0.1524" layer="91"/>
<label x="119.38" y="86.36" size="1.778" layer="95"/>
<pinref part="JP12" gate="A" pin="4"/>
</segment>
</net>
<net name="PWM1-2" class="0">
<segment>
<pinref part="JP5" gate="A" pin="2"/>
<wire x1="15.24" y1="86.36" x2="35.56" y2="86.36" width="0.1524" layer="91"/>
<label x="20.32" y="86.36" size="1.778" layer="95"/>
<pinref part="JP9" gate="A" pin="4"/>
</segment>
</net>
<net name="PWM2-1" class="0">
<segment>
<pinref part="JP6" gate="A" pin="3"/>
<wire x1="48.26" y1="88.9" x2="68.58" y2="88.9" width="0.1524" layer="91"/>
<label x="53.34" y="88.9" size="1.778" layer="95"/>
<pinref part="JP10" gate="A" pin="3"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
