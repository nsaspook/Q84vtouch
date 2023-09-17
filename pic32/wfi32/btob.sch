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
<library name="MLE-105-01-G-DV">
<description>&lt;10 Position, 1.00 mm Tiger Beam&amp;trade; Cost-Effective Single Beam Socket Strip&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by SamacSys&lt;/author&gt;</description>
<packages>
<package name="MLE-105-01-G-DV">
<description>&lt;b&gt;MLE-105-01-G-DV&lt;/b&gt;&lt;br&gt;
</description>
<smd name="1" x="2" y="-1.6855" dx="1.709" dy="0.61" layer="1" rot="R90"/>
<smd name="2" x="2" y="1.6855" dx="1.709" dy="0.61" layer="1" rot="R90"/>
<smd name="3" x="1" y="-1.6855" dx="1.709" dy="0.61" layer="1" rot="R90"/>
<smd name="4" x="1" y="1.6855" dx="1.709" dy="0.61" layer="1" rot="R90"/>
<smd name="5" x="0" y="-1.6855" dx="1.709" dy="0.61" layer="1" rot="R90"/>
<smd name="6" x="0" y="1.6855" dx="1.709" dy="0.61" layer="1" rot="R90"/>
<smd name="7" x="-1" y="-1.6855" dx="1.709" dy="0.61" layer="1" rot="R90"/>
<smd name="8" x="-1" y="1.6855" dx="1.709" dy="0.61" layer="1" rot="R90"/>
<smd name="9" x="-2" y="-1.6855" dx="1.709" dy="0.61" layer="1" rot="R90"/>
<smd name="10" x="-2" y="1.6855" dx="1.709" dy="0.61" layer="1" rot="R90"/>
<text x="0" y="0" size="1.27" layer="25" align="center">&gt;NAME</text>
<text x="0" y="0" size="1.27" layer="27" align="center">&gt;VALUE</text>
<wire x1="-2.6" y1="1.535" x2="2.6" y2="1.535" width="0.2" layer="51"/>
<wire x1="2.6" y1="1.535" x2="2.6" y2="-1.535" width="0.2" layer="51"/>
<wire x1="2.6" y1="-1.535" x2="-2.6" y2="-1.535" width="0.2" layer="51"/>
<wire x1="-2.6" y1="-1.535" x2="-2.6" y2="1.535" width="0.2" layer="51"/>
<wire x1="2.6" y1="1.535" x2="2.6" y2="-1.535" width="0.1" layer="21"/>
<wire x1="-2.6" y1="-1.535" x2="-2.6" y2="1.535" width="0.1" layer="21"/>
<circle x="2" y="-3.1855" radius="0.05" width="0.2" layer="25"/>
<wire x1="-3.8" y1="3.54" x2="3.8" y2="3.54" width="0.05" layer="51"/>
<wire x1="3.8" y1="3.54" x2="3.8" y2="-4.2855" width="0.05" layer="51"/>
<wire x1="3.8" y1="-4.2855" x2="-3.8" y2="-4.2855" width="0.05" layer="51"/>
<wire x1="-3.8" y1="-4.2855" x2="-3.8" y2="3.54" width="0.05" layer="51"/>
</package>
</packages>
<symbols>
<symbol name="MLE-105-01-G-DV">
<wire x1="5.08" y1="2.54" x2="17.78" y2="2.54" width="0.254" layer="94"/>
<wire x1="17.78" y1="-12.7" x2="17.78" y2="2.54" width="0.254" layer="94"/>
<wire x1="17.78" y1="-12.7" x2="5.08" y2="-12.7" width="0.254" layer="94"/>
<wire x1="5.08" y1="2.54" x2="5.08" y2="-12.7" width="0.254" layer="94"/>
<text x="19.05" y="7.62" size="1.778" layer="95" align="center-left">&gt;NAME</text>
<text x="19.05" y="5.08" size="1.778" layer="96" align="center-left">&gt;VALUE</text>
<pin name="1" x="0" y="-10.16" length="middle"/>
<pin name="2" x="22.86" y="-10.16" length="middle" rot="R180"/>
<pin name="3" x="0" y="-7.62" length="middle"/>
<pin name="4" x="22.86" y="-7.62" length="middle" rot="R180"/>
<pin name="5" x="0" y="-5.08" length="middle"/>
<pin name="6" x="22.86" y="-5.08" length="middle" rot="R180"/>
<pin name="7" x="0" y="-2.54" length="middle"/>
<pin name="8" x="22.86" y="-2.54" length="middle" rot="R180"/>
<pin name="9" x="0" y="0" length="middle"/>
<pin name="10" x="22.86" y="0" length="middle" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="MLE-105-01-G-DV" prefix="J">
<description>&lt;b&gt;10 Position, 1.00 mm Tiger Beam&amp;trade; Cost-Effective Single Beam Socket Strip&lt;/b&gt;&lt;p&gt;
Source: &lt;a href="http://suddendocs.samtec.com/prints/mle-1xx-xx-x-dv-x-mkt1.pdf"&gt; Datasheet &lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="MLE-105-01-G-DV" x="0" y="0"/>
</gates>
<devices>
<device name="" package="MLE-105-01-G-DV">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="10" pad="10"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
<connect gate="G$1" pin="8" pad="8"/>
<connect gate="G$1" pin="9" pad="9"/>
</connects>
<technologies>
<technology name="">
<attribute name="DESCRIPTION" value="10 Position, 1.00 mm Tiger Beam&amp;trade; Cost-Effective Single Beam Socket Strip" constant="no"/>
<attribute name="HEIGHT" value="mm" constant="no"/>
<attribute name="MANUFACTURER_NAME" value="SAMTEC" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="MLE-105-01-G-DV" constant="no"/>
<attribute name="MOUSER_PART_NUMBER" value="200-MLE10501GDV" constant="no"/>
<attribute name="MOUSER_PRICE-STOCK" value="https://www.mouser.co.uk/ProductDetail/Samtec/MLE-105-01-G-DV?qs=rU5fayqh%252BE2dXiDvl4XeQQ%3D%3D" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="con-lstb" urn="urn:adsk.eagle:library:162">
<description>&lt;b&gt;Pin Headers&lt;/b&gt;&lt;p&gt;
Naming:&lt;p&gt;
MA = male&lt;p&gt;
# contacts - # rows&lt;p&gt;
W = angled&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="MA05-2" urn="urn:adsk.eagle:footprint:8267/1" library_version="2">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-5.715" y1="2.54" x2="-4.445" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="2.54" x2="-3.81" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="1.905" x2="-3.175" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="2.54" x2="-1.905" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="2.54" x2="-1.27" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="2.54" x2="-6.35" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="1.905" x2="-0.635" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="2.54" x2="0.635" y2="2.54" width="0.1524" layer="21"/>
<wire x1="0.635" y1="2.54" x2="1.27" y2="1.905" width="0.1524" layer="21"/>
<wire x1="1.905" y1="2.54" x2="3.175" y2="2.54" width="0.1524" layer="21"/>
<wire x1="3.175" y1="2.54" x2="3.81" y2="1.905" width="0.1524" layer="21"/>
<wire x1="3.81" y1="1.905" x2="4.445" y2="2.54" width="0.1524" layer="21"/>
<wire x1="4.445" y1="2.54" x2="5.715" y2="2.54" width="0.1524" layer="21"/>
<wire x1="1.905" y1="2.54" x2="1.27" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="-1.905" x2="-4.445" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-1.905" x2="-1.905" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-2.54" x2="-3.175" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-2.54" x2="-3.81" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="1.905" x2="-6.35" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="-1.905" x2="-5.715" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="-2.54" x2="-5.715" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-1.905" x2="0.635" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-2.54" x2="-0.635" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-2.54" x2="-1.27" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="3.81" y1="-1.905" x2="3.175" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="5.715" y1="-2.54" x2="4.445" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="4.445" y1="-2.54" x2="3.81" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-1.905" x2="1.905" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="3.175" y1="-2.54" x2="1.905" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="6.35" y1="1.905" x2="6.35" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="5.715" y1="2.54" x2="6.35" y2="1.905" width="0.1524" layer="21"/>
<wire x1="6.35" y1="-1.905" x2="5.715" y2="-2.54" width="0.1524" layer="21"/>
<pad name="1" x="-5.08" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="3" x="-2.54" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="5" x="0" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="7" x="2.54" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="9" x="5.08" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="2" x="-5.08" y="1.27" drill="1.016" shape="octagon"/>
<pad name="4" x="-2.54" y="1.27" drill="1.016" shape="octagon"/>
<pad name="6" x="0" y="1.27" drill="1.016" shape="octagon"/>
<pad name="8" x="2.54" y="1.27" drill="1.016" shape="octagon"/>
<pad name="10" x="5.08" y="1.27" drill="1.016" shape="octagon"/>
<text x="-5.588" y="-4.191" size="1.27" layer="21" ratio="10">1</text>
<text x="-6.35" y="2.921" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="0" y="-4.191" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<text x="4.572" y="2.921" size="1.27" layer="21" ratio="10">10</text>
<rectangle x1="-2.794" y1="-1.524" x2="-2.286" y2="-1.016" layer="51"/>
<rectangle x1="-5.334" y1="-1.524" x2="-4.826" y2="-1.016" layer="51"/>
<rectangle x1="-0.254" y1="-1.524" x2="0.254" y2="-1.016" layer="51"/>
<rectangle x1="4.826" y1="-1.524" x2="5.334" y2="-1.016" layer="51"/>
<rectangle x1="2.286" y1="-1.524" x2="2.794" y2="-1.016" layer="51"/>
<rectangle x1="-5.334" y1="1.016" x2="-4.826" y2="1.524" layer="51"/>
<rectangle x1="-2.794" y1="1.016" x2="-2.286" y2="1.524" layer="51"/>
<rectangle x1="-0.254" y1="1.016" x2="0.254" y2="1.524" layer="51"/>
<rectangle x1="2.286" y1="1.016" x2="2.794" y2="1.524" layer="51"/>
<rectangle x1="4.826" y1="1.016" x2="5.334" y2="1.524" layer="51"/>
</package>
</packages>
<packages3d>
<package3d name="MA05-2" urn="urn:adsk.eagle:package:8329/1" type="box" library_version="2">
<description>PIN HEADER</description>
<packageinstances>
<packageinstance name="MA05-2"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="MA05-2" urn="urn:adsk.eagle:symbol:8266/1" library_version="2">
<wire x1="3.81" y1="-7.62" x2="-3.81" y2="-7.62" width="0.4064" layer="94"/>
<wire x1="1.27" y1="0" x2="2.54" y2="0" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-2.54" x2="2.54" y2="-2.54" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-5.08" x2="2.54" y2="-5.08" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="0" x2="-1.27" y2="0" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="-2.54" x2="-1.27" y2="-2.54" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="-5.08" x2="-1.27" y2="-5.08" width="0.6096" layer="94"/>
<wire x1="-3.81" y1="7.62" x2="-3.81" y2="-7.62" width="0.4064" layer="94"/>
<wire x1="3.81" y1="-7.62" x2="3.81" y2="7.62" width="0.4064" layer="94"/>
<wire x1="-3.81" y1="7.62" x2="3.81" y2="7.62" width="0.4064" layer="94"/>
<wire x1="1.27" y1="5.08" x2="2.54" y2="5.08" width="0.6096" layer="94"/>
<wire x1="1.27" y1="2.54" x2="2.54" y2="2.54" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="5.08" x2="-1.27" y2="5.08" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="2.54" x2="-1.27" y2="2.54" width="0.6096" layer="94"/>
<text x="-3.81" y="-10.16" size="1.778" layer="96">&gt;VALUE</text>
<text x="-3.81" y="8.382" size="1.778" layer="95">&gt;NAME</text>
<pin name="1" x="7.62" y="-5.08" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="3" x="7.62" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="5" x="7.62" y="0" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="2" x="-7.62" y="-5.08" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="4" x="-7.62" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="6" x="-7.62" y="0" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="7" x="7.62" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="9" x="7.62" y="5.08" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="8" x="-7.62" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1"/>
<pin name="10" x="-7.62" y="5.08" visible="pad" length="middle" direction="pas" swaplevel="1"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="MA05-2" urn="urn:adsk.eagle:component:8370/2" prefix="SV" uservalue="yes" library_version="2">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="MA05-2" x="0" y="0"/>
</gates>
<devices>
<device name="" package="MA05-2">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="10" pad="10"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
<connect gate="G$1" pin="8" pad="8"/>
<connect gate="G$1" pin="9" pad="9"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:8329/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
<attribute name="POPULARITY" value="14" constant="no"/>
</technology>
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
<part name="J1" library="MLE-105-01-G-DV" deviceset="MLE-105-01-G-DV" device=""/>
<part name="J2" library="MLE-105-01-G-DV" deviceset="MLE-105-01-G-DV" device=""/>
<part name="J3" library="MLE-105-01-G-DV" deviceset="MLE-105-01-G-DV" device=""/>
<part name="SV1" library="con-lstb" library_urn="urn:adsk.eagle:library:162" deviceset="MA05-2" device="" package3d_urn="urn:adsk.eagle:package:8329/1" value="header"/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="J1" gate="G$1" x="17.78" y="76.2" smashed="yes">
<attribute name="NAME" x="36.83" y="83.82" size="1.778" layer="95" align="center-left"/>
<attribute name="VALUE" x="36.83" y="81.28" size="1.778" layer="96" align="center-left"/>
</instance>
<instance part="J2" gate="G$1" x="101.6" y="76.2" smashed="yes">
<attribute name="NAME" x="120.65" y="83.82" size="1.778" layer="95" align="center-left"/>
<attribute name="VALUE" x="120.65" y="81.28" size="1.778" layer="96" align="center-left"/>
</instance>
<instance part="J3" gate="G$1" x="101.6" y="38.1" smashed="yes">
<attribute name="NAME" x="120.65" y="45.72" size="1.778" layer="95" align="center-left"/>
<attribute name="VALUE" x="120.65" y="43.18" size="1.778" layer="96" align="center-left"/>
</instance>
<instance part="SV1" gate="G$1" x="27.94" y="35.56" smashed="yes">
<attribute name="VALUE" x="24.13" y="25.4" size="1.778" layer="96"/>
<attribute name="NAME" x="24.13" y="43.942" size="1.778" layer="95"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="N$1" class="0">
<segment>
<pinref part="J1" gate="G$1" pin="9"/>
<wire x1="17.78" y1="76.2" x2="7.62" y2="76.2" width="0.1524" layer="91"/>
</segment>
<segment>
<wire x1="45.72" y1="40.64" x2="35.56" y2="40.64" width="0.1524" layer="91"/>
<pinref part="SV1" gate="G$1" pin="9"/>
</segment>
<segment>
<wire x1="101.6" y1="76.2" x2="91.44" y2="76.2" width="0.1524" layer="91"/>
<pinref part="J2" gate="G$1" pin="9"/>
</segment>
<segment>
<wire x1="101.6" y1="38.1" x2="91.44" y2="38.1" width="0.1524" layer="91"/>
<pinref part="J3" gate="G$1" pin="9"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="J1" gate="G$1" pin="7"/>
<wire x1="17.78" y1="73.66" x2="7.62" y2="73.66" width="0.1524" layer="91"/>
</segment>
<segment>
<wire x1="45.72" y1="38.1" x2="35.56" y2="38.1" width="0.1524" layer="91"/>
<pinref part="SV1" gate="G$1" pin="7"/>
</segment>
<segment>
<wire x1="101.6" y1="73.66" x2="91.44" y2="73.66" width="0.1524" layer="91"/>
<pinref part="J2" gate="G$1" pin="7"/>
</segment>
<segment>
<wire x1="101.6" y1="35.56" x2="91.44" y2="35.56" width="0.1524" layer="91"/>
<pinref part="J3" gate="G$1" pin="7"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="J1" gate="G$1" pin="5"/>
<wire x1="17.78" y1="71.12" x2="7.62" y2="71.12" width="0.1524" layer="91"/>
</segment>
<segment>
<wire x1="45.72" y1="35.56" x2="35.56" y2="35.56" width="0.1524" layer="91"/>
<pinref part="SV1" gate="G$1" pin="5"/>
</segment>
<segment>
<wire x1="101.6" y1="71.12" x2="91.44" y2="71.12" width="0.1524" layer="91"/>
<pinref part="J2" gate="G$1" pin="5"/>
</segment>
<segment>
<wire x1="101.6" y1="33.02" x2="91.44" y2="33.02" width="0.1524" layer="91"/>
<pinref part="J3" gate="G$1" pin="5"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="J1" gate="G$1" pin="3"/>
<wire x1="17.78" y1="68.58" x2="7.62" y2="68.58" width="0.1524" layer="91"/>
</segment>
<segment>
<wire x1="45.72" y1="33.02" x2="35.56" y2="33.02" width="0.1524" layer="91"/>
<pinref part="SV1" gate="G$1" pin="3"/>
</segment>
<segment>
<wire x1="101.6" y1="68.58" x2="91.44" y2="68.58" width="0.1524" layer="91"/>
<pinref part="J2" gate="G$1" pin="3"/>
</segment>
<segment>
<wire x1="101.6" y1="30.48" x2="91.44" y2="30.48" width="0.1524" layer="91"/>
<pinref part="J3" gate="G$1" pin="3"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="J1" gate="G$1" pin="1"/>
<wire x1="17.78" y1="66.04" x2="7.62" y2="66.04" width="0.1524" layer="91"/>
</segment>
<segment>
<wire x1="45.72" y1="30.48" x2="35.56" y2="30.48" width="0.1524" layer="91"/>
<pinref part="SV1" gate="G$1" pin="1"/>
</segment>
<segment>
<wire x1="101.6" y1="66.04" x2="91.44" y2="66.04" width="0.1524" layer="91"/>
<pinref part="J2" gate="G$1" pin="1"/>
</segment>
<segment>
<wire x1="101.6" y1="27.94" x2="91.44" y2="27.94" width="0.1524" layer="91"/>
<pinref part="J3" gate="G$1" pin="1"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="J1" gate="G$1" pin="10"/>
<wire x1="40.64" y1="76.2" x2="55.88" y2="76.2" width="0.1524" layer="91"/>
</segment>
<segment>
<wire x1="5.08" y1="40.64" x2="20.32" y2="40.64" width="0.1524" layer="91"/>
<pinref part="SV1" gate="G$1" pin="10"/>
</segment>
<segment>
<wire x1="124.46" y1="76.2" x2="139.7" y2="76.2" width="0.1524" layer="91"/>
<pinref part="J2" gate="G$1" pin="10"/>
</segment>
<segment>
<wire x1="124.46" y1="38.1" x2="139.7" y2="38.1" width="0.1524" layer="91"/>
<pinref part="J3" gate="G$1" pin="10"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="J1" gate="G$1" pin="8"/>
<wire x1="40.64" y1="73.66" x2="55.88" y2="73.66" width="0.1524" layer="91"/>
</segment>
<segment>
<wire x1="5.08" y1="38.1" x2="20.32" y2="38.1" width="0.1524" layer="91"/>
<pinref part="SV1" gate="G$1" pin="8"/>
</segment>
<segment>
<wire x1="124.46" y1="73.66" x2="139.7" y2="73.66" width="0.1524" layer="91"/>
<pinref part="J2" gate="G$1" pin="8"/>
</segment>
<segment>
<wire x1="124.46" y1="35.56" x2="139.7" y2="35.56" width="0.1524" layer="91"/>
<pinref part="J3" gate="G$1" pin="8"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="J1" gate="G$1" pin="6"/>
<wire x1="40.64" y1="71.12" x2="55.88" y2="71.12" width="0.1524" layer="91"/>
</segment>
<segment>
<wire x1="5.08" y1="35.56" x2="20.32" y2="35.56" width="0.1524" layer="91"/>
<pinref part="SV1" gate="G$1" pin="6"/>
</segment>
<segment>
<wire x1="124.46" y1="71.12" x2="139.7" y2="71.12" width="0.1524" layer="91"/>
<pinref part="J2" gate="G$1" pin="6"/>
</segment>
<segment>
<wire x1="124.46" y1="33.02" x2="139.7" y2="33.02" width="0.1524" layer="91"/>
<pinref part="J3" gate="G$1" pin="6"/>
</segment>
</net>
<net name="N$9" class="0">
<segment>
<pinref part="J1" gate="G$1" pin="4"/>
<wire x1="40.64" y1="68.58" x2="55.88" y2="68.58" width="0.1524" layer="91"/>
</segment>
<segment>
<wire x1="5.08" y1="33.02" x2="20.32" y2="33.02" width="0.1524" layer="91"/>
<pinref part="SV1" gate="G$1" pin="4"/>
</segment>
<segment>
<wire x1="124.46" y1="68.58" x2="139.7" y2="68.58" width="0.1524" layer="91"/>
<pinref part="J2" gate="G$1" pin="4"/>
</segment>
<segment>
<wire x1="124.46" y1="30.48" x2="139.7" y2="30.48" width="0.1524" layer="91"/>
<pinref part="J3" gate="G$1" pin="4"/>
</segment>
</net>
<net name="N$10" class="0">
<segment>
<pinref part="J1" gate="G$1" pin="2"/>
<wire x1="40.64" y1="66.04" x2="55.88" y2="66.04" width="0.1524" layer="91"/>
</segment>
<segment>
<wire x1="5.08" y1="30.48" x2="20.32" y2="30.48" width="0.1524" layer="91"/>
<pinref part="SV1" gate="G$1" pin="2"/>
</segment>
<segment>
<wire x1="124.46" y1="66.04" x2="139.7" y2="66.04" width="0.1524" layer="91"/>
<pinref part="J2" gate="G$1" pin="2"/>
</segment>
<segment>
<wire x1="124.46" y1="27.94" x2="139.7" y2="27.94" width="0.1524" layer="91"/>
<pinref part="J3" gate="G$1" pin="2"/>
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
