<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.6.2">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="1" fill="3" visible="no" active="no"/>
<layer number="3" name="Route3" color="4" fill="3" visible="no" active="no"/>
<layer number="4" name="Route4" color="1" fill="4" visible="no" active="no"/>
<layer number="5" name="Route5" color="4" fill="4" visible="no" active="no"/>
<layer number="6" name="Route6" color="1" fill="8" visible="no" active="no"/>
<layer number="7" name="Route7" color="4" fill="8" visible="no" active="no"/>
<layer number="8" name="Route8" color="1" fill="2" visible="no" active="no"/>
<layer number="9" name="Route9" color="4" fill="2" visible="no" active="no"/>
<layer number="10" name="Route10" color="1" fill="7" visible="no" active="no"/>
<layer number="11" name="Route11" color="4" fill="7" visible="no" active="no"/>
<layer number="12" name="Route12" color="1" fill="5" visible="no" active="no"/>
<layer number="13" name="Route13" color="4" fill="5" visible="no" active="no"/>
<layer number="14" name="Route14" color="1" fill="6" visible="no" active="no"/>
<layer number="15" name="Route15" color="4" fill="6" visible="no" active="no"/>
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
<layer number="51" name="tDocu" color="6" fill="1" visible="no" active="no"/>
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
<library name="relay" urn="urn:adsk.eagle:library:339">
<description>&lt;b&gt;Relays&lt;/b&gt;&lt;p&gt;
&lt;ul&gt;
&lt;li&gt;Eichhoff
&lt;li&gt;Finder
&lt;li&gt;Fujitsu
&lt;li&gt;HAMLIN
&lt;li&gt;OMRON
&lt;li&gt;Matsushita
&lt;li&gt;NAiS
&lt;li&gt;Siemens
&lt;li&gt;Schrack
&lt;/ul&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="MR24" urn="urn:adsk.eagle:footprint:24006/1" library_version="8">
<description>&lt;b&gt;RELAY&lt;/b&gt;&lt;p&gt;
4 x switch</description>
<wire x1="-6.096" y1="-12.192" x2="23.876" y2="-12.192" width="0.1524" layer="21"/>
<wire x1="23.876" y1="12.192" x2="-6.096" y2="12.192" width="0.1524" layer="21"/>
<wire x1="21.463" y1="-10.16" x2="20.32" y2="-10.16" width="0.1524" layer="21"/>
<wire x1="20.32" y1="-8.89" x2="20.32" y2="-10.16" width="0.1524" layer="21"/>
<wire x1="20.32" y1="-8.89" x2="7.62" y2="-8.89" width="0.1524" layer="21"/>
<wire x1="7.62" y1="-8.89" x2="5.08" y2="-9.525" width="0.1524" layer="21"/>
<wire x1="3.937" y1="-10.16" x2="5.715" y2="-10.16" width="0.1524" layer="21"/>
<wire x1="5.715" y1="-7.62" x2="-5.08" y2="-7.62" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-7.62" x2="-5.08" y2="-8.763" width="0.1524" layer="21"/>
<wire x1="5.715" y1="-10.16" x2="5.715" y2="-9.525" width="0.1524" layer="21"/>
<wire x1="5.715" y1="-7.62" x2="5.715" y2="-8.255" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-2.54" x2="-5.08" y2="-3.683" width="0.1524" layer="21"/>
<wire x1="5.715" y1="-2.54" x2="-5.08" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="5.715" y1="-2.54" x2="5.715" y2="-3.175" width="0.1524" layer="21"/>
<wire x1="3.937" y1="-5.08" x2="5.715" y2="-5.08" width="0.1524" layer="21"/>
<wire x1="5.715" y1="-5.08" x2="5.715" y2="-4.445" width="0.1524" layer="21"/>
<wire x1="7.62" y1="-3.81" x2="5.08" y2="-4.445" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-3.81" x2="7.62" y2="-3.81" width="0.1524" layer="21"/>
<wire x1="20.32" y1="-7.62" x2="10.16" y2="-7.62" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-3.81" x2="10.16" y2="-7.62" width="0.1524" layer="21"/>
<wire x1="20.32" y1="-7.62" x2="20.32" y2="-5.08" width="0.1524" layer="21"/>
<wire x1="20.32" y1="-5.08" x2="21.463" y2="-5.08" width="0.1524" layer="21"/>
<wire x1="20.32" y1="5.08" x2="21.463" y2="5.08" width="0.1524" layer="21"/>
<wire x1="20.32" y1="5.08" x2="20.32" y2="7.62" width="0.1524" layer="21"/>
<wire x1="20.32" y1="7.62" x2="10.16" y2="7.62" width="0.1524" layer="21"/>
<wire x1="10.16" y1="7.62" x2="10.16" y2="3.81" width="0.1524" layer="21"/>
<wire x1="10.16" y1="3.81" x2="7.62" y2="3.81" width="0.1524" layer="21"/>
<wire x1="7.62" y1="3.81" x2="5.08" y2="4.445" width="0.254" layer="21"/>
<wire x1="5.715" y1="5.08" x2="5.715" y2="4.445" width="0.1524" layer="21"/>
<wire x1="3.937" y1="5.08" x2="5.715" y2="5.08" width="0.1524" layer="21"/>
<wire x1="5.715" y1="2.54" x2="-5.08" y2="2.54" width="0.1524" layer="21"/>
<wire x1="5.715" y1="2.54" x2="5.715" y2="3.175" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="3.683" x2="-5.08" y2="2.54" width="0.1524" layer="21"/>
<wire x1="21.463" y1="10.16" x2="20.32" y2="10.16" width="0.1524" layer="21"/>
<wire x1="20.32" y1="10.16" x2="20.32" y2="8.89" width="0.1524" layer="21"/>
<wire x1="20.32" y1="8.89" x2="7.62" y2="8.89" width="0.1524" layer="21"/>
<wire x1="3.937" y1="10.16" x2="5.715" y2="10.16" width="0.1524" layer="21"/>
<wire x1="5.715" y1="10.16" x2="5.715" y2="9.525" width="0.1524" layer="21"/>
<wire x1="7.62" y1="8.89" x2="5.08" y2="9.525" width="0.254" layer="21"/>
<wire x1="5.715" y1="7.62" x2="5.715" y2="8.255" width="0.1524" layer="21"/>
<wire x1="5.715" y1="7.62" x2="-5.08" y2="7.62" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="8.763" x2="-5.08" y2="7.62" width="0.1524" layer="21"/>
<wire x1="15.24" y1="3.683" x2="15.24" y2="1.27" width="0.1524" layer="21"/>
<wire x1="15.24" y1="1.27" x2="12.7" y2="1.27" width="0.254" layer="21"/>
<wire x1="12.7" y1="1.27" x2="12.7" y2="-1.27" width="0.254" layer="21"/>
<wire x1="12.7" y1="-1.27" x2="13.97" y2="-1.27" width="0.254" layer="21"/>
<wire x1="17.78" y1="-1.27" x2="17.78" y2="1.27" width="0.254" layer="21"/>
<wire x1="17.78" y1="1.27" x2="16.51" y2="1.27" width="0.254" layer="21"/>
<wire x1="15.24" y1="-1.27" x2="15.24" y2="-3.683" width="0.1524" layer="21"/>
<wire x1="15.24" y1="-1.27" x2="17.78" y2="-1.27" width="0.254" layer="21"/>
<wire x1="13.97" y1="-1.27" x2="16.51" y2="1.27" width="0.1524" layer="21"/>
<wire x1="13.97" y1="-1.27" x2="15.24" y2="-1.27" width="0.254" layer="21"/>
<wire x1="16.51" y1="1.27" x2="15.24" y2="1.27" width="0.254" layer="21"/>
<wire x1="-6.096" y1="-12.192" x2="-6.096" y2="-11.176" width="0.1524" layer="21"/>
<wire x1="-6.096" y1="-9.144" x2="-6.096" y2="-11.176" width="0.1524" layer="51"/>
<wire x1="-6.096" y1="-9.144" x2="-6.096" y2="-6.096" width="0.1524" layer="21"/>
<wire x1="-6.096" y1="-4.064" x2="-6.096" y2="-6.096" width="0.1524" layer="51"/>
<wire x1="-6.096" y1="-4.064" x2="-6.096" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="-6.096" y1="1.016" x2="-6.096" y2="-1.016" width="0.1524" layer="51"/>
<wire x1="-6.096" y1="1.016" x2="-6.096" y2="4.064" width="0.1524" layer="21"/>
<wire x1="-6.096" y1="6.096" x2="-6.096" y2="4.064" width="0.1524" layer="51"/>
<wire x1="-6.096" y1="12.192" x2="-6.096" y2="11.176" width="0.1524" layer="21"/>
<wire x1="-6.096" y1="9.144" x2="-6.096" y2="11.176" width="0.1524" layer="51"/>
<wire x1="-6.096" y1="9.144" x2="-6.096" y2="6.096" width="0.1524" layer="21"/>
<wire x1="23.876" y1="12.192" x2="23.876" y2="11.176" width="0.1524" layer="21"/>
<wire x1="23.876" y1="9.144" x2="23.876" y2="11.176" width="0.1524" layer="51"/>
<wire x1="23.876" y1="9.144" x2="23.876" y2="6.096" width="0.1524" layer="21"/>
<wire x1="23.876" y1="4.064" x2="23.876" y2="6.096" width="0.1524" layer="51"/>
<wire x1="23.876" y1="-4.064" x2="23.876" y2="-6.096" width="0.1524" layer="51"/>
<wire x1="23.876" y1="-4.064" x2="23.876" y2="4.064" width="0.1524" layer="21"/>
<wire x1="23.876" y1="-12.192" x2="23.876" y2="-11.176" width="0.1524" layer="21"/>
<wire x1="23.876" y1="-9.144" x2="23.876" y2="-11.176" width="0.1524" layer="51"/>
<wire x1="23.876" y1="-9.144" x2="23.876" y2="-6.096" width="0.1524" layer="21"/>
<pad name="S1" x="-5.08" y="-10.16" drill="1.3208" shape="long"/>
<pad name="O1" x="2.54" y="-10.16" drill="1.3208" shape="long"/>
<pad name="1" x="15.24" y="-5.08" drill="1.3208" shape="long"/>
<pad name="P1" x="22.86" y="-10.16" drill="1.3208" shape="long"/>
<pad name="P2" x="22.86" y="-5.08" drill="1.3208" shape="long"/>
<pad name="P3" x="22.86" y="5.08" drill="1.3208" shape="long"/>
<pad name="P4" x="22.86" y="10.16" drill="1.3208" shape="long"/>
<pad name="S2" x="-5.08" y="-5.08" drill="1.3208" shape="long"/>
<pad name="O2" x="2.54" y="-5.08" drill="1.3208" shape="long"/>
<pad name="E" x="-5.08" y="0" drill="1.3208" shape="long"/>
<pad name="S3" x="-5.08" y="5.08" drill="1.3208" shape="long"/>
<pad name="O3" x="2.54" y="5.08" drill="1.3208" shape="long"/>
<pad name="S4" x="-5.08" y="10.16" drill="1.3208" shape="long"/>
<pad name="O4" x="2.54" y="10.16" drill="1.3208" shape="long"/>
<pad name="2" x="15.24" y="5.08" drill="1.3208" shape="long"/>
<text x="-6.604" y="-12.1158" size="1.778" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="-3.556" y="-0.889" size="1.778" layer="21" ratio="10">E</text>
<text x="15.875" y="-3.683" size="1.778" layer="21" ratio="10">1</text>
<text x="15.875" y="1.905" size="1.778" layer="21" ratio="10">2</text>
<text x="-6.604" y="-2.54" size="1.778" layer="27" ratio="10" rot="R90">&gt;VALUE</text>
<text x="1.27" y="-0.889" size="1.778" layer="51" ratio="10">MR24</text>
</package>
</packages>
<packages3d>
<package3d name="MR24" urn="urn:adsk.eagle:package:24339/1" type="box" library_version="8">
<description>RELAY
4 x switch</description>
<packageinstances>
<packageinstance name="MR24"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="K" urn="urn:adsk.eagle:symbol:23941/1" library_version="8">
<wire x1="-3.81" y1="-1.905" x2="-1.905" y2="-1.905" width="0.254" layer="94"/>
<wire x1="3.81" y1="-1.905" x2="3.81" y2="1.905" width="0.254" layer="94"/>
<wire x1="3.81" y1="1.905" x2="1.905" y2="1.905" width="0.254" layer="94"/>
<wire x1="-3.81" y1="1.905" x2="-3.81" y2="-1.905" width="0.254" layer="94"/>
<wire x1="0" y1="-2.54" x2="0" y2="-1.905" width="0.1524" layer="94"/>
<wire x1="0" y1="-1.905" x2="3.81" y2="-1.905" width="0.254" layer="94"/>
<wire x1="0" y1="2.54" x2="0" y2="1.905" width="0.1524" layer="94"/>
<wire x1="0" y1="1.905" x2="-3.81" y2="1.905" width="0.254" layer="94"/>
<wire x1="-1.905" y1="-1.905" x2="1.905" y2="1.905" width="0.1524" layer="94"/>
<wire x1="-1.905" y1="-1.905" x2="0" y2="-1.905" width="0.254" layer="94"/>
<wire x1="1.905" y1="1.905" x2="0" y2="1.905" width="0.254" layer="94"/>
<text x="1.27" y="2.921" size="1.778" layer="96">&gt;VALUE</text>
<text x="1.27" y="5.08" size="1.778" layer="95">&gt;PART</text>
<pin name="2" x="0" y="-5.08" visible="pad" length="short" direction="pas" rot="R90"/>
<pin name="1" x="0" y="5.08" visible="pad" length="short" direction="pas" rot="R270"/>
</symbol>
<symbol name="U" urn="urn:adsk.eagle:symbol:23944/1" library_version="8">
<wire x1="3.175" y1="5.08" x2="1.905" y2="5.08" width="0.254" layer="94"/>
<wire x1="-3.175" y1="5.08" x2="-1.905" y2="5.08" width="0.254" layer="94"/>
<wire x1="0" y1="1.27" x2="2.54" y2="5.715" width="0.254" layer="94"/>
<wire x1="0" y1="1.27" x2="0" y2="0" width="0.254" layer="94"/>
<circle x="0" y="1.27" radius="0.127" width="0.4064" layer="94"/>
<text x="2.54" y="0" size="1.778" layer="95">&gt;PART</text>
<pin name="O" x="5.08" y="5.08" visible="pad" length="short" direction="pas" rot="R180"/>
<pin name="S" x="-5.08" y="5.08" visible="pad" length="short" direction="pas"/>
<pin name="P" x="0" y="-2.54" visible="pad" length="short" direction="pas" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="MR24" urn="urn:adsk.eagle:component:24615/4" prefix="K" library_version="8">
<description>&lt;b&gt;RELAY&lt;/b&gt;&lt;p&gt;
4 x switch</description>
<gates>
<gate name="1" symbol="K" x="0" y="0" addlevel="must"/>
<gate name="2" symbol="U" x="20.32" y="5.08" addlevel="always"/>
<gate name="3" symbol="U" x="38.1" y="5.08" addlevel="always"/>
<gate name="4" symbol="U" x="20.32" y="-10.16" addlevel="always"/>
<gate name="5" symbol="U" x="38.1" y="-10.16" addlevel="always"/>
</gates>
<devices>
<device name="" package="MR24">
<connects>
<connect gate="1" pin="1" pad="1"/>
<connect gate="1" pin="2" pad="2"/>
<connect gate="2" pin="O" pad="O1"/>
<connect gate="2" pin="P" pad="P1"/>
<connect gate="2" pin="S" pad="S1"/>
<connect gate="3" pin="O" pad="O2"/>
<connect gate="3" pin="P" pad="P2"/>
<connect gate="3" pin="S" pad="S2"/>
<connect gate="4" pin="O" pad="O3"/>
<connect gate="4" pin="P" pad="P3"/>
<connect gate="4" pin="S" pad="S3"/>
<connect gate="5" pin="O" pad="O4"/>
<connect gate="5" pin="P" pad="P4"/>
<connect gate="5" pin="S" pad="S4"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:24339/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MANUFACTURER" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="PART_STATUS" value="" constant="no"/>
<attribute name="POPULARITY" value="0" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="4797-5-444-0330-151-00">
<packages>
<package name="SCHURTER_4797-5-444-0330-151-00">
<wire x1="21" y1="17" x2="21" y2="-17" width="0.127" layer="51"/>
<wire x1="21" y1="-17" x2="-21" y2="-17" width="0.127" layer="51"/>
<wire x1="-21" y1="-17" x2="-21" y2="17" width="0.127" layer="51"/>
<wire x1="-21" y1="17" x2="21" y2="17" width="0.127" layer="51"/>
<wire x1="-21.25" y1="17.25" x2="21.25" y2="17.25" width="0.05" layer="39"/>
<wire x1="21.25" y1="17.25" x2="21.25" y2="-17.25" width="0.05" layer="39"/>
<wire x1="21.25" y1="-17.25" x2="-21.25" y2="-17.25" width="0.05" layer="39"/>
<wire x1="-21.25" y1="-17.25" x2="-21.25" y2="17.25" width="0.05" layer="39"/>
<text x="-20.93" y="18.02" size="1.27" layer="25">&gt;NAME</text>
<text x="-20.93" y="-19.47" size="1.27" layer="27">&gt;VALUE</text>
<circle x="-17.9" y="13.5" radius="1" width="0.127" layer="51"/>
<circle x="-17.9" y="-13.5" radius="1" width="0.127" layer="51"/>
<wire x1="-21" y1="17" x2="21" y2="17" width="0.127" layer="21"/>
<wire x1="21" y1="17" x2="21" y2="-17" width="0.127" layer="21"/>
<wire x1="21" y1="-17" x2="-21" y2="-17" width="0.127" layer="21"/>
<wire x1="-21" y1="-17" x2="-21" y2="17" width="0.127" layer="21"/>
<pad name="2" x="-6.5" y="-6.35" drill="3.5"/>
<pad name="3" x="6.5" y="-6.35" drill="3.5"/>
<pad name="1" x="0" y="6.35" drill="3.5"/>
</package>
</packages>
<symbols>
<symbol name="4797-5-444-0330-151-00">
<wire x1="-5.08" y1="4.445" x2="5.08" y2="4.445" width="0.254" layer="94"/>
<wire x1="5.08" y1="4.445" x2="5.08" y2="-2.54" width="0.254" layer="94"/>
<wire x1="5.08" y1="-2.54" x2="-5.08" y2="-2.54" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-2.54" x2="-5.08" y2="4.445" width="0.254" layer="94"/>
<text x="-4.8759" y="5.5595" size="1.778" layer="95">&gt;NAME</text>
<text x="-5.1267" y="-5.1881" size="1.778" layer="96">&gt;VALUE</text>
<wire x1="-3.175" y1="-0.635" x2="-0.635" y2="-0.635" width="0.1524" layer="94"/>
<wire x1="-0.635" y1="-0.635" x2="-0.635" y2="0.635" width="0.1524" layer="94"/>
<wire x1="-0.635" y1="0.635" x2="-3.175" y2="0.635" width="0.1524" layer="94"/>
<wire x1="-3.175" y1="0.635" x2="-3.175" y2="-0.635" width="0.1524" layer="94"/>
<wire x1="0.635" y1="-0.635" x2="3.175" y2="-0.635" width="0.1524" layer="94"/>
<wire x1="3.175" y1="-0.635" x2="3.175" y2="0.635" width="0.1524" layer="94"/>
<wire x1="3.175" y1="0.635" x2="0.635" y2="0.635" width="0.1524" layer="94"/>
<wire x1="0.635" y1="0.635" x2="0.635" y2="-0.635" width="0.1524" layer="94"/>
<wire x1="-1.27" y1="1.905" x2="1.27" y2="1.905" width="0.1524" layer="94"/>
<wire x1="1.27" y1="1.905" x2="1.27" y2="3.175" width="0.1524" layer="94"/>
<wire x1="1.27" y1="3.175" x2="-1.27" y2="3.175" width="0.1524" layer="94"/>
<wire x1="-1.27" y1="3.175" x2="-1.27" y2="1.905" width="0.1524" layer="94"/>
<pin name="NEUTRAL" x="-10.16" y="0" visible="pad" length="middle" direction="pwr"/>
<pin name="LIVE" x="10.16" y="0" visible="pad" length="middle" direction="pwr" rot="R180"/>
<pin name="GND" x="10.16" y="2.54" visible="pad" length="middle" direction="pwr" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="4797-5-444-0330-151-00" prefix="P">
<description>4797-5 APPLIANCE OUTLET 16A 70  &lt;a href="https://pricing.snapeda.com/parts/4797-5-444-0330-151-00/Schurter%20Inc./view-part?ref=eda"&gt;Check availability&lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="4797-5-444-0330-151-00" x="0" y="0"/>
</gates>
<devices>
<device name="" package="SCHURTER_4797-5-444-0330-151-00">
<connects>
<connect gate="G$1" pin="GND" pad="1"/>
<connect gate="G$1" pin="LIVE" pad="3"/>
<connect gate="G$1" pin="NEUTRAL" pad="2"/>
</connects>
<technologies>
<technology name="">
<attribute name="AVAILABILITY" value="In Stock"/>
<attribute name="CHECK_PRICES" value="https://www.snapeda.com/parts/4797-5-444-0330-151-00/Schurter/view-part/?ref=eda"/>
<attribute name="DESCRIPTION" value=" Power Entry Connector Receptacle, Female Sockets IEC 320-2-2/J Panel Mount, Snap-In; Through Hole "/>
<attribute name="MF" value="Schurter Inc."/>
<attribute name="MP" value="4797-5-444-0330-151-00"/>
<attribute name="PACKAGE" value="None"/>
<attribute name="PRICE" value="None"/>
<attribute name="PURCHASE-URL" value="https://www.snapeda.com/api/url_track_click_mouser/?unipart_id=5679205&amp;manufacturer=Schurter Inc.&amp;part_name=4797-5-444-0330-151-00&amp;search_term=iec connector"/>
<attribute name="SNAPEDA_LINK" value="https://www.snapeda.com/parts/4797-5-444-0330-151-00/Schurter/view-part/?ref=snap"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="DD21.0121.1111">
<packages>
<package name="SCHURTER_DD21.0121.1111">
<wire x1="-32.5" y1="-9.5" x2="32.5" y2="-9.5" width="0.127" layer="21"/>
<wire x1="23.3" y1="14.9" x2="9.1" y2="14.9" width="0.127" layer="21"/>
<wire x1="9.1" y1="14.9" x2="9.1" y2="25.1" width="0.127" layer="21"/>
<wire x1="9.1" y1="25.1" x2="-23.3" y2="25.1" width="0.127" layer="21"/>
<wire x1="-32.5" y1="-9.5" x2="-32.5" y2="4.5" width="0.127" layer="21"/>
<wire x1="-32.5" y1="4.5" x2="-23.3" y2="4.5" width="0.127" layer="21"/>
<wire x1="-23.3" y1="4.5" x2="-23.3" y2="25.1" width="0.127" layer="21"/>
<wire x1="32.5" y1="-9.5" x2="32.5" y2="4.5" width="0.127" layer="21"/>
<wire x1="32.5" y1="4.5" x2="23.3" y2="4.5" width="0.127" layer="21"/>
<wire x1="23.3" y1="4.5" x2="23.3" y2="14.9" width="0.127" layer="21"/>
<wire x1="-32.5" y1="-13" x2="-32.5" y2="-9.5" width="0.127" layer="51"/>
<wire x1="-32.5" y1="-9.5" x2="-32.5" y2="4.5" width="0.127" layer="51"/>
<wire x1="-32.5" y1="4.5" x2="-23.3" y2="4.5" width="0.127" layer="51"/>
<wire x1="-23.3" y1="4.5" x2="-23.3" y2="25.1" width="0.127" layer="51"/>
<wire x1="9.1" y1="25.1" x2="-23.3" y2="25.1" width="0.127" layer="51"/>
<wire x1="9.1" y1="14.9" x2="9.1" y2="25.1" width="0.127" layer="51"/>
<wire x1="23.3" y1="14.9" x2="9.1" y2="14.9" width="0.127" layer="51"/>
<wire x1="23.3" y1="4.5" x2="23.3" y2="14.9" width="0.127" layer="51"/>
<wire x1="32.5" y1="4.5" x2="23.3" y2="4.5" width="0.127" layer="51"/>
<wire x1="32.5" y1="-13" x2="32.5" y2="-9.5" width="0.127" layer="51"/>
<wire x1="32.5" y1="-9.5" x2="32.5" y2="4.5" width="0.127" layer="51"/>
<wire x1="-32.5" y1="-13" x2="32.5" y2="-13" width="0.127" layer="51"/>
<wire x1="-32.75" y1="4.75" x2="-23.55" y2="4.75" width="0.05" layer="39"/>
<wire x1="-23.55" y1="4.75" x2="-23.55" y2="25.35" width="0.05" layer="39"/>
<wire x1="-23.55" y1="25.35" x2="9.35" y2="25.35" width="0.05" layer="39"/>
<wire x1="9.35" y1="25.35" x2="9.35" y2="15.15" width="0.05" layer="39"/>
<wire x1="9.35" y1="15.15" x2="23.55" y2="15.15" width="0.05" layer="39"/>
<wire x1="23.55" y1="15.15" x2="23.55" y2="4.75" width="0.05" layer="39"/>
<wire x1="23.55" y1="4.75" x2="32.75" y2="4.75" width="0.05" layer="39"/>
<wire x1="32.75" y1="4.75" x2="32.75" y2="-13.25" width="0.05" layer="39"/>
<wire x1="32.75" y1="-13.25" x2="-32.75" y2="-13.25" width="0.05" layer="39"/>
<wire x1="-32.75" y1="-13.25" x2="-32.75" y2="4.75" width="0.05" layer="39"/>
<text x="-23.5" y="27" size="1.27" layer="25">&gt;NAME</text>
<text x="-23.5" y="25.5" size="1.27" layer="27">&gt;VALUE</text>
<wire x1="-32.5" y1="-9.5" x2="32.5" y2="-9.5" width="0.127" layer="51"/>
<hole x="-28" y="0" drill="3.6"/>
<hole x="28" y="0" drill="3.6"/>
<pad name="L" x="-17.65" y="9.55" drill="1.4"/>
<pad name="N" x="-11.65" y="9.55" drill="1.4"/>
<pad name="PE" x="17.55" y="9.55" drill="1.7"/>
</package>
</packages>
<symbols>
<symbol name="DD21.0121.1111">
<wire x1="-12.065" y1="5.08" x2="2.54" y2="5.08" width="0.254" layer="94"/>
<wire x1="-7.62" y1="6.35" x2="-0.635" y2="6.35" width="0.254" layer="94"/>
<wire x1="-0.635" y1="6.35" x2="-0.635" y2="3.81" width="0.254" layer="94"/>
<wire x1="-0.635" y1="3.81" x2="-7.62" y2="3.81" width="0.254" layer="94"/>
<wire x1="-7.62" y1="3.81" x2="-7.62" y2="6.35" width="0.254" layer="94"/>
<wire x1="2.54" y1="6.35" x2="5.715" y2="5.08" width="0.254" layer="94"/>
<wire x1="5.715" y1="5.08" x2="10.16" y2="5.08" width="0.254" layer="94"/>
<wire x1="-12.065" y1="0" x2="-10.16" y2="0" width="0.254" layer="94"/>
<wire x1="-10.16" y1="0" x2="4.445" y2="0" width="0.254" layer="94"/>
<wire x1="4.445" y1="0" x2="10.16" y2="0" width="0.254" layer="94"/>
<wire x1="-12.065" y1="-5.08" x2="-7.62" y2="-5.08" width="0.254" layer="94"/>
<wire x1="-7.62" y1="-5.08" x2="-0.635" y2="-5.08" width="0.254" layer="94"/>
<wire x1="-0.635" y1="-5.08" x2="2.54" y2="-5.08" width="0.254" layer="94"/>
<wire x1="2.54" y1="-3.81" x2="5.715" y2="-5.08" width="0.254" layer="94"/>
<wire x1="5.715" y1="-5.08" x2="10.16" y2="-5.08" width="0.254" layer="94"/>
<wire x1="4.445" y1="6.35" x2="5.08" y2="6.985" width="0.254" layer="94"/>
<wire x1="5.08" y1="6.985" x2="4.445" y2="7.62" width="0.254" layer="94"/>
<wire x1="4.445" y1="7.62" x2="4.445" y2="8.255" width="0.254" layer="94"/>
<wire x1="3.175" y1="8.255" x2="5.715" y2="8.255" width="0.254" layer="94"/>
<wire x1="4.445" y1="3.81" x2="4.445" y2="2.54" width="0.254" layer="94"/>
<wire x1="4.445" y1="1.905" x2="4.445" y2="0.635" width="0.254" layer="94"/>
<wire x1="4.445" y1="0" x2="4.445" y2="-1.27" width="0.254" layer="94"/>
<wire x1="4.445" y1="-1.905" x2="4.445" y2="-3.175" width="0.254" layer="94"/>
<wire x1="4.445" y1="-3.81" x2="4.445" y2="-4.445" width="0.254" layer="94"/>
<wire x1="4.445" y1="4.445" x2="4.445" y2="6.35" width="0.254" layer="94"/>
<circle x="-12.7" y="5.08" radius="0.635" width="0.254" layer="94"/>
<circle x="-12.7" y="0" radius="0.635" width="0.254" layer="94"/>
<circle x="-12.7" y="-5.08" radius="0.635" width="0.254" layer="94"/>
<wire x1="-10.16" y1="0" x2="-10.16" y2="7.62" width="0.254" layer="94"/>
<circle x="-10.16" y="8.255" radius="0.635" width="0.254" layer="94"/>
<text x="-5.08" y="6.985" size="0.815078125" layer="97">F1</text>
<text x="-14.605" y="4.445" size="0.814615625" layer="97">L</text>
<text x="-15.24" y="-0.635" size="0.81421875" layer="97">PE</text>
<text x="-14.605" y="-5.715" size="0.813821875" layer="97">N</text>
<text x="-10.795" y="9.525" size="0.8145875" layer="97">PE</text>
<text x="11.43" y="0.635" size="0.8138875" layer="97">PE</text>
<text x="11.43" y="5.715" size="0.81363125" layer="97">L</text>
<text x="11.43" y="-4.445" size="0.814746875" layer="97">N</text>
<text x="-7.62" y="10.16" size="1.778" layer="95">&gt;NAME</text>
<text x="-7.62" y="-10.16" size="1.778" layer="96">&gt;VALUE</text>
<wire x1="-7.62" y1="-3.81" x2="-6.985" y2="-3.81" width="0.254" layer="94"/>
<wire x1="-6.35" y1="-3.81" x2="-5.715" y2="-3.81" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-3.81" x2="-4.445" y2="-3.81" width="0.254" layer="94"/>
<wire x1="-3.81" y1="-3.81" x2="-3.175" y2="-3.81" width="0.254" layer="94"/>
<wire x1="-2.54" y1="-3.81" x2="-1.905" y2="-3.81" width="0.254" layer="94"/>
<wire x1="-1.27" y1="-3.81" x2="-0.635" y2="-3.81" width="0.254" layer="94"/>
<wire x1="-0.635" y1="-3.81" x2="-0.635" y2="-4.445" width="0.254" layer="94"/>
<wire x1="-0.635" y1="-5.08" x2="-0.635" y2="-5.715" width="0.254" layer="94"/>
<wire x1="-0.635" y1="-6.35" x2="-1.27" y2="-6.35" width="0.254" layer="94"/>
<wire x1="-1.905" y1="-6.35" x2="-2.54" y2="-6.35" width="0.254" layer="94"/>
<wire x1="-3.175" y1="-6.35" x2="-3.81" y2="-6.35" width="0.254" layer="94"/>
<wire x1="-4.445" y1="-6.35" x2="-5.08" y2="-6.35" width="0.254" layer="94"/>
<wire x1="-5.715" y1="-6.35" x2="-6.35" y2="-6.35" width="0.254" layer="94"/>
<wire x1="-6.985" y1="-6.35" x2="-7.62" y2="-6.35" width="0.254" layer="94"/>
<wire x1="-7.62" y1="-6.35" x2="-7.62" y2="-5.715" width="0.254" layer="94"/>
<wire x1="-7.62" y1="-5.08" x2="-7.62" y2="-4.445" width="0.254" layer="94"/>
<text x="-5.08" y="-3.175" size="0.813534375" layer="97">F2</text>
<text x="2.54" y="3.175" size="0.814109375" layer="97">S</text>
<pin name="L" x="15.24" y="5.08" visible="off" length="middle" direction="pwr" rot="R180"/>
<pin name="PE" x="15.24" y="0" visible="off" length="middle" direction="pwr" rot="R180"/>
<pin name="N" x="15.24" y="-5.08" visible="off" length="middle" direction="pwr" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="DD21.0121.1111" prefix="J">
<description>Power Entry Connector Receptacle, Male Blades - Module IEC 320-C14 Panel Mount, Flange; Through Hole, Right Angle  &lt;a href="https://pricing.snapeda.com/parts/DD21.0121.1111/Schurter%20Inc./view-part?ref=eda"&gt;Check availability&lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="DD21.0121.1111" x="0" y="0"/>
</gates>
<devices>
<device name="" package="SCHURTER_DD21.0121.1111">
<connects>
<connect gate="G$1" pin="L" pad="L"/>
<connect gate="G$1" pin="N" pad="N"/>
<connect gate="G$1" pin="PE" pad="PE"/>
</connects>
<technologies>
<technology name="">
<attribute name="AVAILABILITY" value="In Stock"/>
<attribute name="CHECK_PRICES" value="https://www.snapeda.com/parts/DD21.0121.1111/Schurter+Inc./view-part/?ref=eda"/>
<attribute name="DESCRIPTION" value=" C14 Right Angle Through Hole IEC Conn Plug,Solder Term,Rated At 10A,250V ac | Schurter DD21.0121.1111 "/>
<attribute name="MF" value="Schurter Inc."/>
<attribute name="MP" value="DD21.0121.1111"/>
<attribute name="PACKAGE" value="None"/>
<attribute name="PRICE" value="None"/>
<attribute name="PURCHASE-URL" value="https://www.snapeda.com/api/url_track_click_mouser/?unipart_id=262444&amp;manufacturer=Schurter Inc.&amp;part_name=DD21.0121.1111&amp;search_term=iec connector"/>
<attribute name="SNAPEDA_LINK" value="https://www.snapeda.com/parts/DD21.0121.1111/Schurter+Inc./view-part/?ref=snap"/>
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
<symbol name="PE" urn="urn:adsk.eagle:symbol:26992/1" library_version="2">
<wire x1="-1.27" y1="-0.762" x2="1.27" y2="-0.762" width="0.254" layer="94"/>
<wire x1="-0.635" y1="-1.524" x2="0.635" y2="-1.524" width="0.254" layer="94"/>
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<text x="-4.445" y="-4.699" size="1.778" layer="96">&gt;VALUE</text>
<pin name="PE" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="PE" urn="urn:adsk.eagle:component:27038/1" prefix="SUPPLY" library_version="2">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="PE" symbol="PE" x="0" y="0"/>
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
<class number="0" name="default" width="1.524" drill="0">
</class>
</classes>
<parts>
<part name="K1" library="relay" library_urn="urn:adsk.eagle:library:339" deviceset="MR24" device="" package3d_urn="urn:adsk.eagle:package:24339/1"/>
<part name="P1" library="4797-5-444-0330-151-00" deviceset="4797-5-444-0330-151-00" device=""/>
<part name="P2" library="4797-5-444-0330-151-00" deviceset="4797-5-444-0330-151-00" device=""/>
<part name="UTILITY" library="DD21.0121.1111" deviceset="DD21.0121.1111" device=""/>
<part name="SOLAR" library="DD21.0121.1111" deviceset="DD21.0121.1111" device=""/>
<part name="SUPPLY1" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="PE" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="K1" gate="1" x="43.18" y="55.88" smashed="yes">
<attribute name="VALUE" x="44.45" y="58.801" size="1.778" layer="96"/>
<attribute name="PART" x="44.45" y="60.96" size="1.778" layer="95"/>
</instance>
<instance part="K1" gate="2" x="63.5" y="60.96" smashed="yes">
<attribute name="PART" x="66.04" y="60.96" size="1.778" layer="95"/>
</instance>
<instance part="K1" gate="3" x="81.28" y="60.96" smashed="yes">
<attribute name="PART" x="83.82" y="60.96" size="1.778" layer="95"/>
</instance>
<instance part="K1" gate="4" x="63.5" y="45.72" smashed="yes">
<attribute name="PART" x="66.04" y="45.72" size="1.778" layer="95"/>
</instance>
<instance part="K1" gate="5" x="81.28" y="45.72" smashed="yes">
<attribute name="PART" x="83.82" y="45.72" size="1.778" layer="95"/>
</instance>
<instance part="P1" gate="G$1" x="109.22" y="33.02" smashed="yes">
<attribute name="NAME" x="104.3441" y="38.5795" size="1.778" layer="95"/>
<attribute name="VALUE" x="104.0933" y="27.8319" size="1.778" layer="96"/>
</instance>
<instance part="P2" gate="G$1" x="109.22" y="73.66" smashed="yes">
<attribute name="NAME" x="104.3441" y="79.2195" size="1.778" layer="95"/>
<attribute name="VALUE" x="104.0933" y="68.4719" size="1.778" layer="96"/>
</instance>
<instance part="UTILITY" gate="G$1" x="20.32" y="25.4" smashed="yes">
<attribute name="NAME" x="12.7" y="35.56" size="1.778" layer="95"/>
<attribute name="VALUE" x="12.7" y="15.24" size="1.778" layer="96"/>
</instance>
<instance part="SOLAR" gate="G$1" x="17.78" y="81.28" smashed="yes">
<attribute name="NAME" x="10.16" y="91.44" size="1.778" layer="95"/>
<attribute name="VALUE" x="10.16" y="71.12" size="1.778" layer="96"/>
</instance>
<instance part="SUPPLY1" gate="PE" x="50.8" y="25.4" smashed="yes" rot="R90">
<attribute name="VALUE" x="55.499" y="20.955" size="1.778" layer="96" rot="R90"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="PE" class="0">
<segment>
<pinref part="UTILITY" gate="G$1" pin="PE"/>
<wire x1="35.56" y1="25.4" x2="48.26" y2="25.4" width="0.1524" layer="91"/>
<junction x="35.56" y="25.4"/>
<junction x="48.26" y="25.4"/>
<pinref part="SUPPLY1" gate="PE" pin="PE"/>
<label x="38.1" y="25.4" size="1.778" layer="95"/>
</segment>
<segment>
<wire x1="33.02" y1="81.28" x2="45.72" y2="81.28" width="0.1524" layer="91"/>
<pinref part="SOLAR" gate="G$1" pin="PE"/>
<label x="38.1" y="81.28" size="1.778" layer="95"/>
<junction x="33.02" y="81.28"/>
<junction x="45.72" y="81.28"/>
</segment>
<segment>
<wire x1="119.38" y1="35.56" x2="132.08" y2="35.56" width="0.1524" layer="91"/>
<pinref part="P1" gate="G$1" pin="GND"/>
<label x="124.46" y="35.56" size="1.778" layer="95"/>
<junction x="119.38" y="35.56"/>
<junction x="132.08" y="35.56"/>
</segment>
<segment>
<wire x1="119.38" y1="76.2" x2="132.08" y2="76.2" width="0.1524" layer="91"/>
<junction x="132.08" y="76.2"/>
<label x="127" y="78.74" size="1.778" layer="95"/>
<pinref part="P2" gate="G$1" pin="GND"/>
<junction x="119.38" y="76.2"/>
</segment>
</net>
<net name="LINE" class="0">
<segment>
<pinref part="UTILITY" gate="G$1" pin="L"/>
<wire x1="35.56" y1="30.48" x2="48.26" y2="30.48" width="0.1524" layer="91"/>
<label x="38.1" y="30.48" size="1.778" layer="95"/>
<junction x="35.56" y="30.48"/>
<junction x="48.26" y="30.48"/>
</segment>
<segment>
<wire x1="68.58" y1="66.04" x2="68.58" y2="78.74" width="0.1524" layer="91"/>
<pinref part="K1" gate="2" pin="O"/>
<junction x="68.58" y="78.74"/>
<junction x="68.58" y="66.04"/>
<label x="66.04" y="81.28" size="1.778" layer="95"/>
</segment>
</net>
<net name="NEUTRAL" class="0">
<segment>
<pinref part="UTILITY" gate="G$1" pin="N"/>
<wire x1="35.56" y1="20.32" x2="48.26" y2="20.32" width="0.1524" layer="91"/>
<label x="35.56" y="20.32" size="1.778" layer="95"/>
<junction x="48.26" y="20.32"/>
<junction x="35.56" y="20.32"/>
</segment>
<segment>
<wire x1="86.36" y1="66.04" x2="86.36" y2="78.74" width="0.1524" layer="91"/>
<pinref part="K1" gate="3" pin="O"/>
<junction x="86.36" y="78.74"/>
<junction x="86.36" y="66.04"/>
<label x="88.9" y="81.28" size="1.778" layer="95"/>
</segment>
</net>
<net name="LINEOUT" class="0">
<segment>
<pinref part="P1" gate="G$1" pin="NEUTRAL"/>
<wire x1="99.06" y1="33.02" x2="91.44" y2="33.02" width="0.1524" layer="91"/>
<label x="86.36" y="30.48" size="1.778" layer="95"/>
<junction x="99.06" y="33.02"/>
<junction x="91.44" y="33.02"/>
</segment>
<segment>
<wire x1="99.06" y1="73.66" x2="91.44" y2="73.66" width="0.1524" layer="91"/>
<pinref part="P2" gate="G$1" pin="NEUTRAL"/>
<junction x="99.06" y="73.66"/>
<junction x="91.44" y="73.66"/>
<label x="91.44" y="68.58" size="1.778" layer="95"/>
</segment>
<segment>
<wire x1="63.5" y1="58.42" x2="55.88" y2="58.42" width="0.1524" layer="91"/>
<pinref part="K1" gate="2" pin="P"/>
<label x="55.88" y="55.88" size="1.778" layer="95"/>
<junction x="63.5" y="58.42"/>
<junction x="55.88" y="58.42"/>
</segment>
</net>
<net name="NEUTRALOUT" class="0">
<segment>
<pinref part="P1" gate="G$1" pin="LIVE"/>
<wire x1="119.38" y1="33.02" x2="132.08" y2="33.02" width="0.1524" layer="91"/>
<label x="119.38" y="30.48" size="1.778" layer="95"/>
<junction x="119.38" y="33.02"/>
<junction x="132.08" y="33.02"/>
</segment>
<segment>
<wire x1="119.38" y1="73.66" x2="132.08" y2="73.66" width="0.1524" layer="91"/>
<pinref part="P2" gate="G$1" pin="LIVE"/>
<junction x="119.38" y="73.66"/>
<junction x="132.08" y="73.66"/>
<label x="129.54" y="71.12" size="1.778" layer="95"/>
</segment>
<segment>
<wire x1="81.28" y1="58.42" x2="93.98" y2="58.42" width="0.1524" layer="91"/>
<pinref part="K1" gate="3" pin="P"/>
<label x="83.82" y="55.88" size="1.778" layer="95"/>
<junction x="81.28" y="58.42"/>
<junction x="93.98" y="58.42"/>
</segment>
</net>
<net name="LINES" class="0">
<segment>
<pinref part="SOLAR" gate="G$1" pin="L"/>
<wire x1="33.02" y1="86.36" x2="45.72" y2="86.36" width="0.1524" layer="91"/>
<label x="38.1" y="86.36" size="1.778" layer="95"/>
<junction x="33.02" y="86.36"/>
<junction x="45.72" y="86.36"/>
</segment>
<segment>
<wire x1="58.42" y1="66.04" x2="58.42" y2="78.74" width="0.1524" layer="91"/>
<pinref part="K1" gate="2" pin="S"/>
<junction x="58.42" y="66.04"/>
<junction x="58.42" y="78.74"/>
<label x="55.88" y="81.28" size="1.778" layer="95"/>
</segment>
<segment>
<wire x1="30.48" y1="60.96" x2="43.18" y2="60.96" width="0.1524" layer="91"/>
<pinref part="K1" gate="1" pin="1"/>
<junction x="43.18" y="60.96"/>
<junction x="30.48" y="60.96"/>
<label x="30.48" y="63.5" size="1.778" layer="95"/>
</segment>
</net>
<net name="NEUTRALS" class="0">
<segment>
<pinref part="SOLAR" gate="G$1" pin="N"/>
<wire x1="33.02" y1="76.2" x2="45.72" y2="76.2" width="0.1524" layer="91"/>
<label x="35.56" y="73.66" size="1.778" layer="95"/>
<junction x="33.02" y="76.2"/>
<junction x="45.72" y="76.2"/>
</segment>
<segment>
<wire x1="76.2" y1="66.04" x2="76.2" y2="78.74" width="0.1524" layer="91"/>
<pinref part="K1" gate="3" pin="S"/>
<junction x="76.2" y="66.04"/>
<junction x="76.2" y="78.74"/>
<label x="73.66" y="81.28" size="1.778" layer="95"/>
</segment>
<segment>
<wire x1="30.48" y1="50.8" x2="43.18" y2="50.8" width="0.1524" layer="91"/>
<pinref part="K1" gate="1" pin="2"/>
<junction x="30.48" y="50.8"/>
<junction x="43.18" y="50.8"/>
<label x="33.02" y="45.72" size="1.778" layer="95"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
<errors>
<approved hash="104,1,99.06,33.02,P1,NEUTRAL,LINEOUT,,,"/>
<approved hash="104,1,119.38,33.02,P1,LIVE,NEUTRALOUT,,,"/>
<approved hash="104,1,119.38,35.56,P1,GND,PE,,,"/>
<approved hash="104,1,99.06,73.66,P2,NEUTRAL,LINEOUT,,,"/>
<approved hash="104,1,119.38,73.66,P2,LIVE,NEUTRALOUT,,,"/>
<approved hash="104,1,119.38,76.2,P2,GND,PE,,,"/>
<approved hash="104,1,35.56,30.48,UTILITY,L,LINE,,,"/>
<approved hash="104,1,35.56,20.32,UTILITY,N,NEUTRAL,,,"/>
<approved hash="104,1,33.02,86.36,SOLAR,L,LINES,,,"/>
<approved hash="104,1,33.02,76.2,SOLAR,N,NEUTRALS,,,"/>
</errors>
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
