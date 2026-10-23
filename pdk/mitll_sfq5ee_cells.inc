* MIT-LL SFQ5ee Superconducting Standard Cell Library for JoSIM
* Calibrated under 8-Nb ColdFlux ERSFQ parameters
* Models:
.model jjmit jj(rtype=1, vg=2.8mV, cap=0.07pF, r0=160, rN=16, icrit=0.1mA)

* -------------------------------------------------------------
* 1-to-2 Active Splitter (SPLIT)
* Ports: A Q1 Q2
* -------------------------------------------------------------
.subckt SPLIT A Q1 Q2
B01 1 0 jjmit area=2.5
B02 3 0 jjmit area=2.5
B03 5 0 jjmit area=2.5
IB01 0 2 pwl(0 0 5p 569uA)
L01 A 1 1.4p
L02 1 2 2.0p
L03 2 3 1.9p
L04 3 Q1 2.0p
L05 2 4 1.9p
L06 4 5 1.9p
L07 5 Q2 2.0p
R01 1 0 3.88
R02 3 0 3.88
R03 5 0 3.88
.ends SPLIT

* -------------------------------------------------------------
* Josephson Transmission Line (JTLT)
* Ports: A Q
* -------------------------------------------------------------
.subckt JTLT A Q
B01 1 0 jjmit area=2.16
B02 3 0 jjmit area=2.16
IB01 0 2 pwl(0 0 5p 280uA)
L01 A 1 2.0p
L02 1 2 2.4p
L03 2 3 2.4p
L04 3 Q 2.0p
R01 1 0 5.23
R02 3 0 5.23
.ends JTLT

* -------------------------------------------------------------
* Delay Flip-Flop (DFFT)
* Ports: D CLK Q
* -------------------------------------------------------------
.subckt DFFT D CLK Q
B01 1 0 jjmit area=2.5
B02 3 0 jjmit area=2.0
B03 5 0 jjmit area=2.5
B04 7 0 jjmit area=2.0
IB01 0 2 pwl(0 0 5p 260uA)
IB02 0 6 pwl(0 0 5p 160uA)
L01 D 1 2.0p
L02 1 2 1.5p
L03 2 3 4.0p
L04 CLK 4 2.0p
L05 4 5 1.5p
L06 5 6 3.0p
L07 6 7 2.0p
L08 7 Q 2.0p
R01 1 0 3.88
R02 3 0 4.85
R03 5 0 3.88
R04 7 0 4.85
.ends DFFT

* -------------------------------------------------------------
* Inverter Gate (NOTT)
* Ports: A CLK Q
* -------------------------------------------------------------
.subckt NOTT A CLK Q
B01 1 0 jjmit area=2.1
B02 3 0 jjmit area=2.3
B03 5 0 jjmit area=1.5
IB01 0 2 pwl(0 0 5p 350uA)
IB02 0 4 pwl(0 0 5p 220uA)
L01 A 1 2.0p
L02 1 2 2.5p
L03 CLK 3 2.0p
L04 3 4 2.5p
L05 4 5 2.0p
L06 5 Q 2.0p
R01 1 0 4.5
R02 3 0 4.5
R03 5 0 5.5
.ends NOTT

* -------------------------------------------------------------
* 2-input AND Gate (AND2T)
* Ports: A B CLK Q
* -------------------------------------------------------------
.subckt AND2T A B CLK Q
B01 1 0 jjmit area=2.0
B02 3 0 jjmit area=2.0
B03 5 0 jjmit area=1.5
B04 7 0 jjmit area=2.2
B05 9 0 jjmit area=2.5
IB01 0 2 pwl(0 0 5p 230uA)
IB02 0 4 pwl(0 0 5p 230uA)
IB03 0 8 pwl(0 0 5p 220uA)
L01 A 1 2.0p
L02 1 2 2.5p
L03 B 3 2.0p
L04 3 4 2.5p
L05 2 5 3.0p
L06 4 5 3.0p
L07 CLK 6 2.0p
L08 6 7 2.0p
L09 5 8 2.5p
L10 7 8 2.0p
L11 8 9 2.0p
L12 9 Q 2.0p
R01 1 0 4.85
R02 3 0 4.85
R03 5 0 6.5
R04 7 0 4.4
R05 9 0 4.3
.ends AND2T

* -------------------------------------------------------------
* 2-input OR Gate (OR2T)
* Ports: A B CLK Q
* -------------------------------------------------------------
.subckt OR2T A B CLK Q
B01 1 0 jjmit area=2.5
B02 3 0 jjmit area=2.5
B03 5 0 jjmit area=2.0
B04 7 0 jjmit area=2.5
IB01 0 2 pwl(0 0 5p 440uA)
IB02 0 6 pwl(0 0 5p 200uA)
L01 A 1 2.5p
L02 1 2 2.0p
L03 B 3 2.5p
L04 3 2 2.0p
L05 2 4 1.5p
L06 CLK 5 2.0p
L07 5 6 2.0p
L08 4 6 2.5p
L09 6 7 2.0p
L10 7 Q 2.0p
R01 1 0 3.88
R02 3 0 3.88
R03 5 0 4.85
R04 7 0 3.88
.ends OR2T

* -------------------------------------------------------------
* 2-input XOR Gate (XORT)
* Ports: A B CLK Q
* -------------------------------------------------------------
.subckt XORT A B CLK Q
B01 1 0 jjmit area=2.5
B02 3 0 jjmit area=2.5
B03 5 0 jjmit area=2.0
B04 7 0 jjmit area=2.2
IB01 0 2 pwl(0 0 5p 225uA)
IB02 0 4 pwl(0 0 5p 225uA)
IB03 0 6 pwl(0 0 5p 180uA)
L01 A 1 2.5p
L02 1 2 2.1p
L03 B 3 2.5p
L04 3 4 2.1p
L05 CLK 5 2.0p
L06 2 6 2.0p
L07 4 6 2.0p
L08 5 6 2.5p
L09 6 7 2.0p
L10 7 Q 2.0p
R01 1 0 3.88
R02 3 0 3.88
R03 5 0 4.45
R04 7 0 4.45
.ends XORT

* -------------------------------------------------------------
* 2-input XNOR Gate (XNORT)
* Ports: A B CLK Q
* -------------------------------------------------------------
.subckt XNORT A B CLK Q
X1 A B CLK 1 XORT
X2 1 CLK Q NOTT
.ends XNORT

* -------------------------------------------------------------
* Compound AND-OR 2-1 Gate (AO21T)
* Ports: A B C CLK Q
* -------------------------------------------------------------
.subckt AO21T A B C CLK Q
X1 A B CLK 1 AND2T
X2 1 C CLK Q OR2T
.ends AO21T

* -------------------------------------------------------------
* Compound AND-OR-Invert 2-1 Gate (AOI21T)
* Ports: A B C CLK Q
* -------------------------------------------------------------
.subckt AOI21T A B C CLK Q
X1 A B C CLK 1 AO21T
X2 1 CLK Q NOTT
.ends AOI21T

* -------------------------------------------------------------
* Compound OR-AND 2-1 Gate (OA21T)
* Ports: A B C CLK Q
* -------------------------------------------------------------
.subckt OA21T A B C CLK Q
X1 A B CLK 1 OR2T
X2 1 C CLK Q AND2T
.ends OA21T

* -------------------------------------------------------------
* Compound OR-AND-Invert 2-1 Gate (OAI21T)
* Ports: A B C CLK Q
* -------------------------------------------------------------
.subckt OAI21T A B C CLK Q
X1 A B C CLK 1 OA21T
X2 1 CLK Q NOTT
.ends OAI21T

* -------------------------------------------------------------
* 3-input Majority Gate (MAJ3)
* Ports: A B C CLK Q
* -------------------------------------------------------------
.subckt MAJ3 A B C CLK Q
X1 A B CLK 1 AND2T
X2 B C CLK 2 AND2T
X3 A C CLK 3 AND2T
X4 1 2 CLK 4 OR2T
X5 4 3 CLK Q OR2T
.ends MAJ3

.subckt MAJ3T A B C CLK Q
X1 A B C CLK Q MAJ3
.ends MAJ3T

* -------------------------------------------------------------
* 1-bit Full Adder Macrocell (FAT)
* Ports: A B CIN CLK SUM COUT
* -------------------------------------------------------------
.subckt FAT A B CIN CLK SUM COUT
X1 A B CLK 1 XORT
X2 1 CIN CLK SUM XORT
X3 A B CIN CLK COUT MAJ3
.ends FAT
