
--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : lab4_seven_segment_display.vhf
-- /___/   /\     Timestamp : 11/14/2017 18:08:54
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -intstyle ise -family artix7 -flat -suppress -vhdl /home/kgopal/jaishreeram/jaishreeram.cache/wt/L88/lab4_seven_segment_display.vhf -w /home/kgopal/jaishreeram/jaishreeram.cache/wt/L88/lab4_seven_segment_display.sch
--Design Name: lab4_seven_segment_display
--Device: artix7
--Purpose:
--    This vhdl netlist is translated from an ECS schematic. It can be 
--    synthesized and simulated, but it should not be modified. 
--
----- CELL OR6_HXILINX_lab4_seven_segment_display -----
  
library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity OR6_HXILINX_lab4_seven_segment_display is
  
port(
    O  : out std_logic;

    I0  : in std_logic;
    I1  : in std_logic;
    I2  : in std_logic;
    I3  : in std_logic;
    I4  : in std_logic;
    I5  : in std_logic
  );
end OR6_HXILINX_lab4_seven_segment_display;

architecture OR6_HXILINX_lab4_seven_segment_display_V of OR6_HXILINX_lab4_seven_segment_display is
begin
  O <=  (I0 or I1 or I2 or I3 or I4 or I5);
end OR6_HXILINX_lab4_seven_segment_display_V;

library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity slowclockmahla_MUSER_lab4_seven_segment_display is
   port ( clock     : in    std_logic; 
          slowclock : out   std_logic);
end slowclockmahla_MUSER_lab4_seven_segment_display;

architecture BEHAVIORAL of slowclockmahla_MUSER_lab4_seven_segment_display is
   attribute BOX_TYPE   : string ;
   signal XLXN_25         : std_logic;
   signal XLXN_26         : std_logic;
   signal XLXN_28         : std_logic;
   signal XLXN_29         : std_logic;
   signal XLXN_30         : std_logic;
   signal XLXN_31         : std_logic;
   signal XLXN_33         : std_logic;
   signal XLXN_34         : std_logic;
   signal XLXN_36         : std_logic;
   signal XLXN_39         : std_logic;
   signal XLXN_40         : std_logic;
   signal XLXN_42         : std_logic;
   signal XLXN_43         : std_logic;
   signal XLXN_45         : std_logic;
   signal XLXN_46         : std_logic;
   signal XLXN_48         : std_logic;
   signal XLXN_49         : std_logic;
   signal XLXN_50         : std_logic;
   signal XLXN_51         : std_logic;
   signal XLXN_52         : std_logic;
   signal XLXN_53         : std_logic;
   signal XLXN_55         : std_logic;
   signal XLXN_56         : std_logic;
   signal XLXN_57         : std_logic;
   signal XLXN_58         : std_logic;
   signal XLXN_60         : std_logic;
   signal XLXN_61         : std_logic;
   signal XLXN_63         : std_logic;
   signal XLXN_64         : std_logic;
   signal XLXN_65         : std_logic;
   signal XLXN_66         : std_logic;
   signal XLXN_69         : std_logic;
   signal XLXN_72         : std_logic;
   signal slowclock_DUMMY : std_logic;
   component FD
      generic( INIT : bit :=  '0');
      port ( C : in    std_logic; 
             D : in    std_logic; 
             Q : out   std_logic);
   end component;
   attribute BOX_TYPE of FD : component is "BLACK_BOX";
   
   component INV
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute BOX_TYPE of INV : component is "BLACK_BOX";
   
begin
   slowclock <= slowclock_DUMMY;
   XLXI_1 : FD
      port map (C=>clock,
                D=>XLXN_26,
                Q=>XLXN_25);
   
   XLXI_42 : FD
      port map (C=>XLXN_25,
                D=>XLXN_29,
                Q=>XLXN_28);
   
   XLXI_43 : FD
      port map (C=>XLXN_28,
                D=>XLXN_31,
                Q=>XLXN_30);
   
   XLXI_44 : FD
      port map (C=>XLXN_30,
                D=>XLXN_34,
                Q=>XLXN_33);
   
   XLXI_45 : FD
      port map (C=>XLXN_33,
                D=>XLXN_36,
                Q=>XLXN_72);
   
   XLXI_46 : FD
      port map (C=>XLXN_72,
                D=>XLXN_40,
                Q=>XLXN_39);
   
   XLXI_47 : FD
      port map (C=>XLXN_39,
                D=>XLXN_43,
                Q=>XLXN_42);
   
   XLXI_48 : FD
      port map (C=>XLXN_42,
                D=>XLXN_46,
                Q=>XLXN_45);
   
   XLXI_49 : FD
      port map (C=>XLXN_45,
                D=>XLXN_49,
                Q=>XLXN_48);
   
   XLXI_50 : FD
      port map (C=>XLXN_48,
                D=>XLXN_51,
                Q=>XLXN_50);
   
   XLXI_51 : FD
      port map (C=>XLXN_50,
                D=>XLXN_53,
                Q=>XLXN_52);
   
   XLXI_52 : FD
      port map (C=>XLXN_52,
                D=>XLXN_56,
                Q=>XLXN_55);
   
   XLXI_53 : FD
      port map (C=>XLXN_55,
                D=>XLXN_58,
                Q=>XLXN_57);
   
   XLXI_54 : FD
      port map (C=>XLXN_57,
                D=>XLXN_61,
                Q=>XLXN_60);
   
   XLXI_55 : FD
      port map (C=>XLXN_60,
                D=>XLXN_64,
                Q=>XLXN_63);
   
   XLXI_56 : FD
      port map (C=>XLXN_63,
                D=>XLXN_66,
                Q=>XLXN_65);
   
   XLXI_57 : FD
      port map (C=>XLXN_65,
                D=>XLXN_69,
                Q=>slowclock_DUMMY);
   
   XLXI_58 : INV
      port map (I=>XLXN_25,
                O=>XLXN_26);
   
   XLXI_59 : INV
      port map (I=>XLXN_28,
                O=>XLXN_29);
   
   XLXI_60 : INV
      port map (I=>XLXN_30,
                O=>XLXN_31);
   
   XLXI_61 : INV
      port map (I=>XLXN_33,
                O=>XLXN_34);
   
   XLXI_62 : INV
      port map (I=>XLXN_72,
                O=>XLXN_36);
   
   XLXI_63 : INV
      port map (I=>XLXN_39,
                O=>XLXN_40);
   
   XLXI_64 : INV
      port map (I=>XLXN_42,
                O=>XLXN_43);
   
   XLXI_65 : INV
      port map (I=>XLXN_45,
                O=>XLXN_46);
   
   XLXI_66 : INV
      port map (I=>XLXN_48,
                O=>XLXN_49);
   
   XLXI_67 : INV
      port map (I=>XLXN_50,
                O=>XLXN_51);
   
   XLXI_68 : INV
      port map (I=>XLXN_52,
                O=>XLXN_53);
   
   XLXI_69 : INV
      port map (I=>XLXN_55,
                O=>XLXN_56);
   
   XLXI_70 : INV
      port map (I=>XLXN_57,
                O=>XLXN_58);
   
   XLXI_71 : INV
      port map (I=>XLXN_60,
                O=>XLXN_61);
   
   XLXI_72 : INV
      port map (I=>XLXN_63,
                O=>XLXN_64);
   
   XLXI_73 : INV
      port map (I=>XLXN_65,
                O=>XLXN_66);
   
   XLXI_74 : INV
      port map (I=>slowclock_DUMMY,
                O=>XLXN_69);
   
end BEHAVIORAL;



library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity vashisht_MUSER_lab4_seven_segment_display is
   port ( clock      : in    std_logic; 
          pushbutton : in    std_logic; 
          finalclock : out   std_logic);
end vashisht_MUSER_lab4_seven_segment_display;

architecture BEHAVIORAL of vashisht_MUSER_lab4_seven_segment_display is
   attribute BOX_TYPE   : string ;
   signal XLXN_3     : std_logic;
   component MUXCY
      port ( CI : in    std_logic; 
             DI : in    std_logic; 
             S  : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of MUXCY : component is "BLACK_BOX";
   
   component slowclockmahla_MUSER_lab4_seven_segment_display
      port ( clock     : in    std_logic; 
             slowclock : out   std_logic);
   end component;
   
begin
   XLXI_2 : MUXCY
      port map (CI=>clock,
                DI=>XLXN_3,
                S=>pushbutton,
                O=>finalclock);
   
   XLXI_3 : slowclockmahla_MUSER_lab4_seven_segment_display
      port map (clock=>clock,
                slowclock=>XLXN_3);
   
end BEHAVIORAL;



library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity ringmehlu_MUSER_lab4_seven_segment_display is
   port ( clock : in    std_logic; 
          A     : out   std_logic_vector (3 downto 0));
end ringmehlu_MUSER_lab4_seven_segment_display;

architecture BEHAVIORAL of ringmehlu_MUSER_lab4_seven_segment_display is
   attribute BOX_TYPE   : string ;
   signal XLXN_1 : std_logic;
   signal XLXN_2 : std_logic;
   signal XLXN_3 : std_logic;
   signal XLXN_6 : std_logic;
   component FD
      generic( INIT : bit :=  '0');
      port ( C : in    std_logic; 
             D : in    std_logic; 
             Q : out   std_logic);
   end component;
   attribute BOX_TYPE of FD : component is "BLACK_BOX";
   
   component INV
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute BOX_TYPE of INV : component is "BLACK_BOX";
   
begin
   XLXI_1 : FD
   generic map( INIT => '1')
      port map (C=>clock,
                D=>XLXN_6,
                Q=>XLXN_1);
   
   XLXI_3 : FD
      port map (C=>clock,
                D=>XLXN_1,
                Q=>XLXN_2);
   
   XLXI_4 : FD
      port map (C=>clock,
                D=>XLXN_2,
                Q=>XLXN_3);
   
   XLXI_5 : FD
      port map (C=>clock,
                D=>XLXN_3,
                Q=>XLXN_6);
   
   XLXI_6 : INV
      port map (I=>XLXN_1,
                O=>A(0));
   
   XLXI_7 : INV
      port map (I=>XLXN_2,
                O=>A(1));
   
   XLXI_8 : INV
      port map (I=>XLXN_3,
                O=>A(2));
   
   XLXI_10 : INV
      port map (I=>XLXN_6,
                O=>A(3));
   
end BEHAVIORAL;



library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity gmehlu_MUSER_lab4_seven_segment_display is
   port ( d  : in    std_logic_vector (3 downto 0); 
          q1 : out   std_logic);
end gmehlu_MUSER_lab4_seven_segment_display;

architecture BEHAVIORAL of gmehlu_MUSER_lab4_seven_segment_display is
   attribute BOX_TYPE   : string ;
   signal q       : std_logic;
   signal XLXN_3  : std_logic;
   signal XLXN_4  : std_logic;
   signal XLXN_5  : std_logic;
   signal XLXN_6  : std_logic;
   signal XLXN_9  : std_logic;
   signal XLXN_10 : std_logic;
   signal XLXN_11 : std_logic;
   signal XLXN_12 : std_logic;
   signal XLXN_13 : std_logic;
   signal XLXN_14 : std_logic;
   signal XLXN_15 : std_logic;
   signal XLXN_16 : std_logic;
   signal XLXN_17 : std_logic;
   signal XLXN_18 : std_logic;
   signal XLXN_19 : std_logic;
   signal XLXN_24 : std_logic;
   component AND4
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             I3 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND4 : component is "BLACK_BOX";
   
   component OR4
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             I3 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of OR4 : component is "BLACK_BOX";
   
   component INV
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute BOX_TYPE of INV : component is "BLACK_BOX";
   
   component OR2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of OR2 : component is "BLACK_BOX";
   
begin
   XLXI_1 : AND4
      port map (I0=>XLXN_12,
                I1=>XLXN_11,
                I2=>XLXN_10,
                I3=>XLXN_9,
                O=>XLXN_3);
   
   XLXI_2 : AND4
      port map (I0=>d(0),
                I1=>XLXN_15,
                I2=>XLXN_14,
                I3=>XLXN_13,
                O=>XLXN_4);
   
   XLXI_3 : AND4
      port map (I0=>d(0),
                I1=>d(1),
                I2=>d(2),
                I3=>XLXN_16,
                O=>XLXN_5);
   
   XLXI_4 : AND4
      port map (I0=>XLXN_18,
                I1=>XLXN_17,
                I2=>d(2),
                I3=>d(3),
                O=>XLXN_6);
   
   XLXI_5 : OR4
      port map (I0=>XLXN_6,
                I1=>XLXN_5,
                I2=>XLXN_4,
                I3=>XLXN_3,
                O=>q);
   
   XLXI_6 : INV
      port map (I=>d(3),
                O=>XLXN_9);
   
   XLXI_7 : INV
      port map (I=>d(2),
                O=>XLXN_10);
   
   XLXI_8 : INV
      port map (I=>d(1),
                O=>XLXN_11);
   
   XLXI_9 : INV
      port map (I=>d(0),
                O=>XLXN_12);
   
   XLXI_10 : INV
      port map (I=>d(3),
                O=>XLXN_13);
   
   XLXI_11 : INV
      port map (I=>d(2),
                O=>XLXN_14);
   
   XLXI_12 : INV
      port map (I=>d(1),
                O=>XLXN_15);
   
   XLXI_13 : INV
      port map (I=>d(3),
                O=>XLXN_16);
   
   XLXI_14 : INV
      port map (I=>d(1),
                O=>XLXN_17);
   
   XLXI_15 : INV
      port map (I=>d(0),
                O=>XLXN_18);
   
   XLXI_16 : AND4
      port map (I0=>d(0),
                I1=>d(1),
                I2=>XLXN_19,
                I3=>d(3),
                O=>XLXN_24);
   
   XLXI_17 : OR2
      port map (I0=>XLXN_24,
                I1=>q,
                O=>q1);
   
   XLXI_18 : INV
      port map (I=>d(2),
                O=>XLXN_19);
   
end BEHAVIORAL;



library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity fmehlu_MUSER_lab4_seven_segment_display is
   port ( d  : in    std_logic_vector (3 downto 0); 
          q1 : out   std_logic);
end fmehlu_MUSER_lab4_seven_segment_display;

architecture BEHAVIORAL of fmehlu_MUSER_lab4_seven_segment_display is
   attribute BOX_TYPE   : string ;
   signal q       : std_logic;
   signal XLXN_5  : std_logic;
   signal XLXN_6  : std_logic;
   signal XLXN_7  : std_logic;
   signal XLXN_8  : std_logic;
   signal XLXN_10 : std_logic;
   signal XLXN_12 : std_logic;
   signal XLXN_13 : std_logic;
   signal XLXN_14 : std_logic;
   signal XLXN_15 : std_logic;
   signal XLXN_16 : std_logic;
   signal XLXN_17 : std_logic;
   signal XLXN_18 : std_logic;
   signal XLXN_19 : std_logic;
   signal XLXN_20 : std_logic;
   signal XLXN_23 : std_logic;
   signal XLXN_24 : std_logic;
   signal XLXN_29 : std_logic;
   signal XLXN_35 : std_logic;
   signal XLXN_36 : std_logic;
   component AND4
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             I3 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND4 : component is "BLACK_BOX";
   
   component OR5
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             I3 : in    std_logic; 
             I4 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of OR5 : component is "BLACK_BOX";
   
   component INV
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute BOX_TYPE of INV : component is "BLACK_BOX";
   
   component OR3
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of OR3 : component is "BLACK_BOX";
   
   component AND3
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND3 : component is "BLACK_BOX";
   
begin
   XLXI_1 : AND4
      port map (I0=>d(0),
                I1=>XLXN_14,
                I2=>XLXN_13,
                I3=>XLXN_12,
                O=>XLXN_5);
   
   XLXI_2 : AND4
      port map (I0=>XLXN_17,
                I1=>d(1),
                I2=>XLXN_16,
                I3=>XLXN_15,
                O=>XLXN_6);
   
   XLXI_3 : AND4
      port map (I0=>d(0),
                I1=>d(1),
                I2=>XLXN_19,
                I3=>XLXN_18,
                O=>XLXN_7);
   
   XLXI_4 : AND4
      port map (I0=>d(0),
                I1=>d(1),
                I2=>d(2),
                I3=>XLXN_20,
                O=>XLXN_8);
   
   XLXI_5 : AND4
      port map (I0=>d(0),
                I1=>XLXN_23,
                I2=>d(2),
                I3=>d(3),
                O=>XLXN_10);
   
   XLXI_7 : OR5
      port map (I0=>XLXN_10,
                I1=>XLXN_8,
                I2=>XLXN_7,
                I3=>XLXN_6,
                I4=>XLXN_5,
                O=>q);
   
   XLXI_8 : INV
      port map (I=>d(3),
                O=>XLXN_12);
   
   XLXI_9 : INV
      port map (I=>d(2),
                O=>XLXN_13);
   
   XLXI_10 : INV
      port map (I=>d(1),
                O=>XLXN_14);
   
   XLXI_11 : INV
      port map (I=>d(3),
                O=>XLXN_15);
   
   XLXI_12 : INV
      port map (I=>d(2),
                O=>XLXN_16);
   
   XLXI_13 : INV
      port map (I=>d(0),
                O=>XLXN_17);
   
   XLXI_14 : INV
      port map (I=>d(3),
                O=>XLXN_18);
   
   XLXI_15 : INV
      port map (I=>d(2),
                O=>XLXN_19);
   
   XLXI_16 : INV
      port map (I=>d(3),
                O=>XLXN_20);
   
   XLXI_20 : INV
      port map (I=>d(1),
                O=>XLXN_23);
   
   XLXI_21 : OR3
      port map (I0=>XLXN_35,
                I1=>q,
                I2=>XLXN_36,
                O=>q1);
   
   XLXI_22 : AND3
      port map (I0=>XLXN_24,
                I1=>d(1),
                I2=>d(2),
                O=>XLXN_36);
   
   XLXI_23 : INV
      port map (I=>d(0),
                O=>XLXN_24);
   
   XLXI_24 : AND4
      port map (I0=>d(0),
                I1=>d(1),
                I2=>XLXN_29,
                I3=>d(3),
                O=>XLXN_35);
   
   XLXI_25 : INV
      port map (I=>d(2),
                O=>XLXN_29);
   
end BEHAVIORAL;



library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity emehlu_MUSER_lab4_seven_segment_display is
   port ( d : in    std_logic_vector (3 downto 0); 
          q : out   std_logic);
end emehlu_MUSER_lab4_seven_segment_display;

architecture BEHAVIORAL of emehlu_MUSER_lab4_seven_segment_display is
   attribute BOX_TYPE   : string ;
   attribute HU_SET     : string ;
   signal XLXN_4  : std_logic;
   signal XLXN_5  : std_logic;
   signal XLXN_6  : std_logic;
   signal XLXN_7  : std_logic;
   signal XLXN_8  : std_logic;
   signal XLXN_9  : std_logic;
   signal XLXN_11 : std_logic;
   signal XLXN_12 : std_logic;
   signal XLXN_13 : std_logic;
   signal XLXN_14 : std_logic;
   signal XLXN_15 : std_logic;
   signal XLXN_16 : std_logic;
   signal XLXN_17 : std_logic;
   signal XLXN_18 : std_logic;
   signal XLXN_19 : std_logic;
   signal XLXN_20 : std_logic;
   signal XLXN_21 : std_logic;
   signal XLXN_22 : std_logic;
   signal XLXN_23 : std_logic;
   component AND4
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             I3 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND4 : component is "BLACK_BOX";
   
   component OR6_HXILINX_lab4_seven_segment_display
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             I3 : in    std_logic; 
             I4 : in    std_logic; 
             I5 : in    std_logic; 
             O  : out   std_logic);
   end component;
   
   component INV
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute BOX_TYPE of INV : component is "BLACK_BOX";
   
   attribute HU_SET of XLXI_8 : label is "XLXI_8_6";
begin
   XLXI_2 : AND4
      port map (I0=>d(0),
                I1=>XLXN_13,
                I2=>XLXN_12,
                I3=>XLXN_11,
                O=>XLXN_4);
   
   XLXI_3 : AND4
      port map (I0=>d(0),
                I1=>d(1),
                I2=>XLXN_15,
                I3=>XLXN_14,
                O=>XLXN_5);
   
   XLXI_4 : AND4
      port map (I0=>XLXN_18,
                I1=>XLXN_17,
                I2=>d(2),
                I3=>XLXN_16,
                O=>XLXN_6);
   
   XLXI_5 : AND4
      port map (I0=>d(0),
                I1=>XLXN_20,
                I2=>d(2),
                I3=>XLXN_19,
                O=>XLXN_7);
   
   XLXI_6 : AND4
      port map (I0=>d(0),
                I1=>d(1),
                I2=>d(2),
                I3=>XLXN_21,
                O=>XLXN_8);
   
   XLXI_7 : AND4
      port map (I0=>d(0),
                I1=>XLXN_23,
                I2=>XLXN_22,
                I3=>d(3),
                O=>XLXN_9);
   
   XLXI_8 : OR6_HXILINX_lab4_seven_segment_display
      port map (I0=>XLXN_9,
                I1=>XLXN_8,
                I2=>XLXN_7,
                I3=>XLXN_6,
                I4=>XLXN_5,
                I5=>XLXN_4,
                O=>q);
   
   XLXI_9 : INV
      port map (I=>d(3),
                O=>XLXN_11);
   
   XLXI_10 : INV
      port map (I=>d(2),
                O=>XLXN_12);
   
   XLXI_11 : INV
      port map (I=>d(1),
                O=>XLXN_13);
   
   XLXI_12 : INV
      port map (I=>d(3),
                O=>XLXN_14);
   
   XLXI_13 : INV
      port map (I=>d(2),
                O=>XLXN_15);
   
   XLXI_14 : INV
      port map (I=>d(3),
                O=>XLXN_16);
   
   XLXI_15 : INV
      port map (I=>d(1),
                O=>XLXN_17);
   
   XLXI_16 : INV
      port map (I=>d(0),
                O=>XLXN_18);
   
   XLXI_17 : INV
      port map (I=>d(3),
                O=>XLXN_19);
   
   XLXI_18 : INV
      port map (I=>d(1),
                O=>XLXN_20);
   
   XLXI_19 : INV
      port map (I=>d(3),
                O=>XLXN_21);
   
   XLXI_20 : INV
      port map (I=>d(2),
                O=>XLXN_22);
   
   XLXI_21 : INV
      port map (I=>d(1),
                O=>XLXN_23);
   
end BEHAVIORAL;



library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity dmehlu_MUSER_lab4_seven_segment_display is
   port ( d : in    std_logic_vector (3 downto 0); 
          q : out   std_logic);
end dmehlu_MUSER_lab4_seven_segment_display;

architecture BEHAVIORAL of dmehlu_MUSER_lab4_seven_segment_display is
   attribute BOX_TYPE   : string ;
   signal XLXN_2  : std_logic;
   signal XLXN_3  : std_logic;
   signal XLXN_4  : std_logic;
   signal XLXN_5  : std_logic;
   signal XLXN_6  : std_logic;
   signal XLXN_8  : std_logic;
   signal XLXN_9  : std_logic;
   signal XLXN_10 : std_logic;
   signal XLXN_11 : std_logic;
   signal XLXN_12 : std_logic;
   signal XLXN_17 : std_logic;
   signal XLXN_18 : std_logic;
   signal XLXN_19 : std_logic;
   signal XLXN_20 : std_logic;
   component AND4
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             I3 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND4 : component is "BLACK_BOX";
   
   component OR5
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             I3 : in    std_logic; 
             I4 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of OR5 : component is "BLACK_BOX";
   
   component INV
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute BOX_TYPE of INV : component is "BLACK_BOX";
   
begin
   XLXI_1 : AND4
      port map (I0=>d(0),
                I1=>XLXN_10,
                I2=>XLXN_9,
                I3=>XLXN_8,
                O=>XLXN_2);
   
   XLXI_2 : AND4
      port map (I0=>XLXN_17,
                I1=>XLXN_12,
                I2=>d(2),
                I3=>XLXN_11,
                O=>XLXN_3);
   
   XLXI_3 : AND4
      port map (I0=>d(0),
                I1=>d(1),
                I2=>d(2),
                I3=>XLXN_18,
                O=>XLXN_4);
   
   XLXI_4 : AND4
      port map (I0=>XLXN_20,
                I1=>d(1),
                I2=>XLXN_19,
                I3=>d(3),
                O=>XLXN_5);
   
   XLXI_5 : AND4
      port map (I0=>d(0),
                I1=>d(1),
                I2=>d(2),
                I3=>d(3),
                O=>XLXN_6);
   
   XLXI_6 : OR5
      port map (I0=>XLXN_6,
                I1=>XLXN_5,
                I2=>XLXN_4,
                I3=>XLXN_3,
                I4=>XLXN_2,
                O=>q);
   
   XLXI_7 : INV
      port map (I=>d(3),
                O=>XLXN_8);
   
   XLXI_8 : INV
      port map (I=>d(2),
                O=>XLXN_9);
   
   XLXI_9 : INV
      port map (I=>d(1),
                O=>XLXN_10);
   
   XLXI_10 : INV
      port map (I=>d(3),
                O=>XLXN_11);
   
   XLXI_12 : INV
      port map (I=>d(1),
                O=>XLXN_12);
   
   XLXI_13 : INV
      port map (I=>d(0),
                O=>XLXN_17);
   
   XLXI_14 : INV
      port map (I=>d(3),
                O=>XLXN_18);
   
   XLXI_15 : INV
      port map (I=>d(2),
                O=>XLXN_19);
   
   XLXI_16 : INV
      port map (I=>d(0),
                O=>XLXN_20);
   
end BEHAVIORAL;



library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity cmehlu_MUSER_lab4_seven_segment_display is
   port ( d : in    std_logic_vector (3 downto 0); 
          q : out   std_logic);
end cmehlu_MUSER_lab4_seven_segment_display;

architecture BEHAVIORAL of cmehlu_MUSER_lab4_seven_segment_display is
   attribute BOX_TYPE   : string ;
   signal XLXN_1  : std_logic;
   signal XLXN_2  : std_logic;
   signal XLXN_3  : std_logic;
   signal XLXN_4  : std_logic;
   signal XLXN_5  : std_logic;
   signal XLXN_6  : std_logic;
   signal XLXN_9  : std_logic;
   signal XLXN_10 : std_logic;
   signal XLXN_11 : std_logic;
   signal XLXN_12 : std_logic;
   component AND4
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             I3 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND4 : component is "BLACK_BOX";
   
   component OR4
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             I3 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of OR4 : component is "BLACK_BOX";
   
   component INV
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute BOX_TYPE of INV : component is "BLACK_BOX";
   
begin
   XLXI_1 : AND4
      port map (I0=>XLXN_3,
                I1=>d(1),
                I2=>XLXN_2,
                I3=>XLXN_1,
                O=>XLXN_9);
   
   XLXI_2 : AND4
      port map (I0=>XLXN_5,
                I1=>XLXN_4,
                I2=>d(2),
                I3=>d(3),
                O=>XLXN_10);
   
   XLXI_3 : AND4
      port map (I0=>XLXN_6,
                I1=>d(1),
                I2=>d(2),
                I3=>d(3),
                O=>XLXN_11);
   
   XLXI_4 : AND4
      port map (I0=>d(0),
                I1=>d(1),
                I2=>d(2),
                I3=>d(3),
                O=>XLXN_12);
   
   XLXI_6 : OR4
      port map (I0=>XLXN_12,
                I1=>XLXN_11,
                I2=>XLXN_10,
                I3=>XLXN_9,
                O=>q);
   
   XLXI_7 : INV
      port map (I=>d(3),
                O=>XLXN_1);
   
   XLXI_8 : INV
      port map (I=>d(2),
                O=>XLXN_2);
   
   XLXI_9 : INV
      port map (I=>d(0),
                O=>XLXN_3);
   
   XLXI_10 : INV
      port map (I=>d(1),
                O=>XLXN_4);
   
   XLXI_11 : INV
      port map (I=>d(0),
                O=>XLXN_5);
   
   XLXI_12 : INV
      port map (I=>d(0),
                O=>XLXN_6);
   
end BEHAVIORAL;



library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity bmehlu_MUSER_lab4_seven_segment_display is
   port ( d : in    std_logic_vector (3 downto 0); 
          q : out   std_logic);
end bmehlu_MUSER_lab4_seven_segment_display;

architecture BEHAVIORAL of bmehlu_MUSER_lab4_seven_segment_display is
   attribute BOX_TYPE   : string ;
   attribute HU_SET     : string ;
   signal XLXN_34 : std_logic;
   signal XLXN_35 : std_logic;
   signal XLXN_36 : std_logic;
   signal XLXN_37 : std_logic;
   signal XLXN_38 : std_logic;
   signal XLXN_39 : std_logic;
   signal XLXN_40 : std_logic;
   signal XLXN_41 : std_logic;
   signal XLXN_42 : std_logic;
   signal XLXN_43 : std_logic;
   signal XLXN_44 : std_logic;
   signal XLXN_45 : std_logic;
   signal XLXN_46 : std_logic;
   signal XLXN_47 : std_logic;
   component AND4
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             I3 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND4 : component is "BLACK_BOX";
   
   component OR6_HXILINX_lab4_seven_segment_display
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             I3 : in    std_logic; 
             I4 : in    std_logic; 
             I5 : in    std_logic; 
             O  : out   std_logic);
   end component;
   
   component INV
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute BOX_TYPE of INV : component is "BLACK_BOX";
   
   attribute HU_SET of XLXI_14 : label is "XLXI_14_7";
begin
   XLXI_8 : AND4
      port map (I0=>d(0),
                I1=>XLXN_41,
                I2=>d(2),
                I3=>XLXN_40,
                O=>XLXN_34);
   
   XLXI_9 : AND4
      port map (I0=>XLXN_43,
                I1=>d(1),
                I2=>d(2),
                I3=>XLXN_42,
                O=>XLXN_35);
   
   XLXI_10 : AND4
      port map (I0=>d(0),
                I1=>d(1),
                I2=>XLXN_44,
                I3=>d(3),
                O=>XLXN_36);
   
   XLXI_11 : AND4
      port map (I0=>XLXN_45,
                I1=>XLXN_46,
                I2=>d(2),
                I3=>d(3),
                O=>XLXN_37);
   
   XLXI_12 : AND4
      port map (I0=>XLXN_47,
                I1=>d(1),
                I2=>d(2),
                I3=>d(3),
                O=>XLXN_38);
   
   XLXI_13 : AND4
      port map (I0=>d(0),
                I1=>d(1),
                I2=>d(2),
                I3=>d(3),
                O=>XLXN_39);
   
   XLXI_14 : OR6_HXILINX_lab4_seven_segment_display
      port map (I0=>XLXN_39,
                I1=>XLXN_38,
                I2=>XLXN_37,
                I3=>XLXN_36,
                I4=>XLXN_35,
                I5=>XLXN_34,
                O=>q);
   
   XLXI_15 : INV
      port map (I=>d(3),
                O=>XLXN_40);
   
   XLXI_16 : INV
      port map (I=>d(1),
                O=>XLXN_41);
   
   XLXI_17 : INV
      port map (I=>d(3),
                O=>XLXN_42);
   
   XLXI_18 : INV
      port map (I=>d(0),
                O=>XLXN_43);
   
   XLXI_19 : INV
      port map (I=>d(2),
                O=>XLXN_44);
   
   XLXI_20 : INV
      port map (I=>d(0),
                O=>XLXN_45);
   
   XLXI_21 : INV
      port map (I=>d(1),
                O=>XLXN_46);
   
   XLXI_22 : INV
      port map (I=>d(0),
                O=>XLXN_47);
   
end BEHAVIORAL;



library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity amehlu_MUSER_lab4_seven_segment_display is
   port ( d        : in    std_logic_vector (3 downto 0); 
          mehlunew : out   std_logic);
end amehlu_MUSER_lab4_seven_segment_display;

architecture BEHAVIORAL of amehlu_MUSER_lab4_seven_segment_display is
   attribute BOX_TYPE   : string ;
   signal mehlu    : std_logic;
   signal XLXN_1   : std_logic;
   signal XLXN_2   : std_logic;
   signal XLXN_3   : std_logic;
   signal XLXN_4   : std_logic;
   signal XLXN_13  : std_logic;
   signal XLXN_14  : std_logic;
   signal XLXN_15  : std_logic;
   signal XLXN_16  : std_logic;
   signal XLXN_17  : std_logic;
   signal XLXN_18  : std_logic;
   signal XLXN_19  : std_logic;
   signal XLXN_20  : std_logic;
   signal XLXN_21  : std_logic;
   signal XLXN_26  : std_logic;
   component AND4
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             I3 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND4 : component is "BLACK_BOX";
   
   component OR4
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             I3 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of OR4 : component is "BLACK_BOX";
   
   component INV
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute BOX_TYPE of INV : component is "BLACK_BOX";
   
   component OR2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of OR2 : component is "BLACK_BOX";
   
   component AND3
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND3 : component is "BLACK_BOX";
   
begin
   XLXI_1 : AND4
      port map (I0=>d(0),
                I1=>XLXN_15,
                I2=>XLXN_14,
                I3=>XLXN_13,
                O=>XLXN_1);
   
   XLXI_2 : AND4
      port map (I0=>XLXN_18,
                I1=>XLXN_17,
                I2=>d(2),
                I3=>XLXN_16,
                O=>XLXN_2);
   
   XLXI_3 : AND4
      port map (I0=>d(0),
                I1=>d(1),
                I2=>XLXN_19,
                I3=>d(3),
                O=>XLXN_3);
   
   XLXI_4 : AND4
      port map (I0=>d(0),
                I1=>XLXN_20,
                I2=>d(2),
                I3=>d(3),
                O=>XLXN_4);
   
   XLXI_5 : OR4
      port map (I0=>XLXN_4,
                I1=>XLXN_3,
                I2=>XLXN_2,
                I3=>XLXN_1,
                O=>mehlu);
   
   XLXI_6 : INV
      port map (I=>d(3),
                O=>XLXN_13);
   
   XLXI_7 : INV
      port map (I=>d(2),
                O=>XLXN_14);
   
   XLXI_8 : INV
      port map (I=>d(1),
                O=>XLXN_15);
   
   XLXI_9 : INV
      port map (I=>d(3),
                O=>XLXN_16);
   
   XLXI_14 : INV
      port map (I=>d(1),
                O=>XLXN_17);
   
   XLXI_15 : INV
      port map (I=>d(0),
                O=>XLXN_18);
   
   XLXI_16 : INV
      port map (I=>d(2),
                O=>XLXN_19);
   
   XLXI_17 : INV
      port map (I=>d(1),
                O=>XLXN_20);
   
   XLXI_18 : OR2
      port map (I0=>mehlu,
                I1=>XLXN_26,
                O=>mehlunew);
   
   XLXI_19 : AND3
      port map (I0=>XLXN_21,
                I1=>d(1),
                I2=>d(2),
                O=>XLXN_26);
   
   XLXI_20 : INV
      port map (I=>d(0),
                O=>XLXN_21);
   
end BEHAVIORAL;



library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity finalmehlu_MUSER_lab4_seven_segment_display is
   port ( d : in    std_logic_vector (3 downto 0); 
          q : out   std_logic_vector (6 downto 0));
end finalmehlu_MUSER_lab4_seven_segment_display;

architecture BEHAVIORAL of finalmehlu_MUSER_lab4_seven_segment_display is
   component amehlu_MUSER_lab4_seven_segment_display
      port ( d        : in    std_logic_vector (3 downto 0); 
             mehlunew : out   std_logic);
   end component;
   
   component bmehlu_MUSER_lab4_seven_segment_display
      port ( d : in    std_logic_vector (3 downto 0); 
             q : out   std_logic);
   end component;
   
   component cmehlu_MUSER_lab4_seven_segment_display
      port ( d : in    std_logic_vector (3 downto 0); 
             q : out   std_logic);
   end component;
   
   component dmehlu_MUSER_lab4_seven_segment_display
      port ( d : in    std_logic_vector (3 downto 0); 
             q : out   std_logic);
   end component;
   
   component emehlu_MUSER_lab4_seven_segment_display
      port ( d : in    std_logic_vector (3 downto 0); 
             q : out   std_logic);
   end component;
   
   component fmehlu_MUSER_lab4_seven_segment_display
      port ( d  : in    std_logic_vector (3 downto 0); 
             q1 : out   std_logic);
   end component;
   
   component gmehlu_MUSER_lab4_seven_segment_display
      port ( d  : in    std_logic_vector (3 downto 0); 
             q1 : out   std_logic);
   end component;
   
begin
   XLXI_19 : amehlu_MUSER_lab4_seven_segment_display
      port map (d(3 downto 0)=>d(3 downto 0),
                mehlunew=>q(0));
   
   XLXI_20 : bmehlu_MUSER_lab4_seven_segment_display
      port map (d(3 downto 0)=>d(3 downto 0),
                q=>q(1));
   
   XLXI_21 : cmehlu_MUSER_lab4_seven_segment_display
      port map (d(3 downto 0)=>d(3 downto 0),
                q=>q(2));
   
   XLXI_22 : dmehlu_MUSER_lab4_seven_segment_display
      port map (d(3 downto 0)=>d(3 downto 0),
                q=>q(3));
   
   XLXI_23 : emehlu_MUSER_lab4_seven_segment_display
      port map (d(3 downto 0)=>d(3 downto 0),
                q=>q(4));
   
   XLXI_24 : fmehlu_MUSER_lab4_seven_segment_display
      port map (d(3 downto 0)=>d(3 downto 0),
                q1=>q(5));
   
   XLXI_25 : gmehlu_MUSER_lab4_seven_segment_display
      port map (d(3 downto 0)=>d(3 downto 0),
                q1=>q(6));
   
end BEHAVIORAL;



library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity muxpartmehlu_MUSER_lab4_seven_segment_display is
   port ( v : in    std_logic_vector (3 downto 0); 
          w : in    std_logic_vector (3 downto 0); 
          q : out   std_logic);
end muxpartmehlu_MUSER_lab4_seven_segment_display;

architecture BEHAVIORAL of muxpartmehlu_MUSER_lab4_seven_segment_display is
   attribute BOX_TYPE   : string ;
   signal XLXN_4  : std_logic;
   signal XLXN_6  : std_logic;
   signal XLXN_8  : std_logic;
   signal XLXN_10 : std_logic;
   signal XLXN_40 : std_logic;
   signal XLXN_43 : std_logic;
   signal XLXN_47 : std_logic;
   signal XLXN_48 : std_logic;
   component AND2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND2 : component is "BLACK_BOX";
   
   component INV
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute BOX_TYPE of INV : component is "BLACK_BOX";
   
   component OR4
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             I3 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of OR4 : component is "BLACK_BOX";
   
begin
   XLXI_1 : AND2
      port map (I0=>XLXN_4,
                I1=>w(0),
                O=>XLXN_43);
   
   XLXI_2 : AND2
      port map (I0=>XLXN_6,
                I1=>w(1),
                O=>XLXN_47);
   
   XLXI_3 : AND2
      port map (I0=>XLXN_8,
                I1=>w(2),
                O=>XLXN_48);
   
   XLXI_4 : AND2
      port map (I0=>XLXN_10,
                I1=>w(3),
                O=>XLXN_40);
   
   XLXI_18 : INV
      port map (I=>v(0),
                O=>XLXN_4);
   
   XLXI_19 : INV
      port map (I=>v(1),
                O=>XLXN_6);
   
   XLXI_20 : INV
      port map (I=>v(2),
                O=>XLXN_8);
   
   XLXI_21 : INV
      port map (I=>v(3),
                O=>XLXN_10);
   
   XLXI_22 : OR4
      port map (I0=>XLXN_40,
                I1=>XLXN_48,
                I2=>XLXN_47,
                I3=>XLXN_43,
                O=>q);
   
end BEHAVIORAL;



library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity byas_MUSER_lab4_seven_segment_display is
   port ( a   : in    std_logic_vector (3 downto 0); 
          b0  : in    std_logic; 
          b1  : in    std_logic; 
          b2  : in    std_logic; 
          b3  : in    std_logic; 
          b4  : in    std_logic; 
          b5  : in    std_logic; 
          b6  : in    std_logic; 
          b7  : in    std_logic; 
          b8  : in    std_logic; 
          b9  : in    std_logic; 
          b10 : in    std_logic; 
          b11 : in    std_logic; 
          b12 : in    std_logic; 
          b13 : in    std_logic; 
          b14 : in    std_logic; 
          b15 : in    std_logic; 
          a1  : out   std_logic_vector (3 downto 0); 
          a2  : out   std_logic_vector (3 downto 0); 
          a3  : out   std_logic_vector (3 downto 0); 
          a4  : out   std_logic_vector (3 downto 0); 
          z   : out   std_logic_vector (3 downto 0));
end byas_MUSER_lab4_seven_segment_display;

architecture BEHAVIORAL of byas_MUSER_lab4_seven_segment_display is
   attribute BOX_TYPE   : string ;
   signal XLXN_62  : std_logic;
   signal XLXN_63  : std_logic;
   signal XLXN_65  : std_logic;
   signal XLXN_68  : std_logic;
   signal XLXN_69  : std_logic;
   signal XLXN_70  : std_logic;
   signal XLXN_71  : std_logic;
   signal XLXN_73  : std_logic;
   signal XLXN_74  : std_logic;
   signal XLXN_75  : std_logic;
   signal XLXN_76  : std_logic;
   signal XLXN_77  : std_logic;
   signal XLXN_79  : std_logic;
   signal XLXN_80  : std_logic;
   signal XLXN_81  : std_logic;
   signal XLXN_95  : std_logic;
   signal a1_DUMMY : std_logic_vector (3 downto 0);
   signal a2_DUMMY : std_logic_vector (3 downto 0);
   signal a3_DUMMY : std_logic_vector (3 downto 0);
   signal a4_DUMMY : std_logic_vector (3 downto 0);
   component muxpartmehlu_MUSER_lab4_seven_segment_display
      port ( q : out   std_logic; 
             v : in    std_logic_vector (3 downto 0); 
             w : in    std_logic_vector (3 downto 0));
   end component;
   
   component INV
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute BOX_TYPE of INV : component is "BLACK_BOX";
   
begin
   a1(3 downto 0) <= a1_DUMMY(3 downto 0);
   a2(3 downto 0) <= a2_DUMMY(3 downto 0);
   a3(3 downto 0) <= a3_DUMMY(3 downto 0);
   a4(3 downto 0) <= a4_DUMMY(3 downto 0);
   XLXI_1 : muxpartmehlu_MUSER_lab4_seven_segment_display
      port map (v(3 downto 0)=>a(3 downto 0),
                w(3 downto 0)=>a1_DUMMY(3 downto 0),
                q=>z(0));
   
   XLXI_2 : muxpartmehlu_MUSER_lab4_seven_segment_display
      port map (v(3 downto 0)=>a(3 downto 0),
                w(3 downto 0)=>a2_DUMMY(3 downto 0),
                q=>z(1));
   
   XLXI_3 : muxpartmehlu_MUSER_lab4_seven_segment_display
      port map (v(3 downto 0)=>a(3 downto 0),
                w(3 downto 0)=>a3_DUMMY(3 downto 0),
                q=>z(2));
   
   XLXI_4 : muxpartmehlu_MUSER_lab4_seven_segment_display
      port map (v(3 downto 0)=>a(3 downto 0),
                w(3 downto 0)=>a4_DUMMY(3 downto 0),
                q=>z(3));
   
   XLXI_6 : INV
      port map (I=>b0,
                O=>XLXN_62);
   
   XLXI_7 : INV
      port map (I=>XLXN_62,
                O=>a1_DUMMY(0));
   
   XLXI_8 : INV
      port map (I=>b2,
                O=>XLXN_63);
   
   XLXI_9 : INV
      port map (I=>XLXN_63,
                O=>a3_DUMMY(0));
   
   XLXI_10 : INV
      port map (I=>b1,
                O=>XLXN_65);
   
   XLXI_11 : INV
      port map (I=>XLXN_65,
                O=>a2_DUMMY(0));
   
   XLXI_12 : INV
      port map (I=>b4,
                O=>XLXN_68);
   
   XLXI_13 : INV
      port map (I=>XLXN_68,
                O=>a1_DUMMY(1));
   
   XLXI_14 : INV
      port map (I=>b6,
                O=>XLXN_69);
   
   XLXI_15 : INV
      port map (I=>XLXN_69,
                O=>a3_DUMMY(1));
   
   XLXI_16 : INV
      port map (I=>b7,
                O=>XLXN_70);
   
   XLXI_17 : INV
      port map (I=>XLXN_70,
                O=>a4_DUMMY(1));
   
   XLXI_18 : INV
      port map (I=>b8,
                O=>XLXN_71);
   
   XLXI_19 : INV
      port map (I=>XLXN_71,
                O=>a1_DUMMY(2));
   
   XLXI_20 : INV
      port map (I=>b3,
                O=>XLXN_73);
   
   XLXI_21 : INV
      port map (I=>XLXN_73,
                O=>a4_DUMMY(0));
   
   XLXI_22 : INV
      port map (I=>b10,
                O=>XLXN_74);
   
   XLXI_23 : INV
      port map (I=>XLXN_74,
                O=>a3_DUMMY(2));
   
   XLXI_24 : INV
      port map (I=>b11,
                O=>XLXN_75);
   
   XLXI_25 : INV
      port map (I=>XLXN_75,
                O=>a4_DUMMY(2));
   
   XLXI_26 : INV
      port map (I=>b5,
                O=>XLXN_76);
   
   XLXI_27 : INV
      port map (I=>XLXN_76,
                O=>a2_DUMMY(1));
   
   XLXI_28 : INV
      port map (I=>b12,
                O=>XLXN_77);
   
   XLXI_29 : INV
      port map (I=>XLXN_77,
                O=>a1_DUMMY(3));
   
   XLXI_32 : INV
      port map (I=>b14,
                O=>XLXN_79);
   
   XLXI_33 : INV
      port map (I=>XLXN_79,
                O=>a3_DUMMY(3));
   
   XLXI_34 : INV
      port map (I=>b15,
                O=>XLXN_80);
   
   XLXI_35 : INV
      port map (I=>XLXN_80,
                O=>a4_DUMMY(3));
   
   XLXI_36 : INV
      port map (I=>b13,
                O=>XLXN_81);
   
   XLXI_37 : INV
      port map (I=>XLXN_81,
                O=>a2_DUMMY(3));
   
   XLXI_40 : INV
      port map (I=>b9,
                O=>XLXN_95);
   
   XLXI_41 : INV
      port map (I=>XLXN_95,
                O=>a2_DUMMY(2));
   
end BEHAVIORAL;



library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity lab4_seven_segment_display is
   port ( b          : in    std_logic_vector (15 downto 0); 
          clk        : in    std_logic; 
          pushbutton : in    std_logic; 
          anode      : out   std_logic_vector (3 downto 0); 
          cathode    : out   std_logic_vector (6 downto 0));
end lab4_seven_segment_display;

architecture BEHAVIORAL of lab4_seven_segment_display is
   signal XLXN_41     : std_logic_vector (3 downto 0);
   signal XLXN_44     : std_logic;
   signal anode_DUMMY : std_logic_vector (3 downto 0);
   component byas_MUSER_lab4_seven_segment_display
      port ( a   : in    std_logic_vector (3 downto 0); 
             a1  : out   std_logic_vector (3 downto 0); 
             a2  : out   std_logic_vector (3 downto 0); 
             a3  : out   std_logic_vector (3 downto 0); 
             a4  : out   std_logic_vector (3 downto 0); 
             b0  : in    std_logic; 
             b1  : in    std_logic; 
             b10 : in    std_logic; 
             b11 : in    std_logic; 
             b12 : in    std_logic; 
             b13 : in    std_logic; 
             b14 : in    std_logic; 
             b15 : in    std_logic; 
             b2  : in    std_logic; 
             b3  : in    std_logic; 
             b4  : in    std_logic; 
             b5  : in    std_logic; 
             b6  : in    std_logic; 
             b7  : in    std_logic; 
             b8  : in    std_logic; 
             b9  : in    std_logic; 
             z   : out   std_logic_vector (3 downto 0));
   end component;
   
   component finalmehlu_MUSER_lab4_seven_segment_display
      port ( d : in    std_logic_vector (3 downto 0); 
             q : out   std_logic_vector (6 downto 0));
   end component;
   
   component ringmehlu_MUSER_lab4_seven_segment_display
      port ( A     : out   std_logic_vector (3 downto 0); 
             clock : in    std_logic);
   end component;
   
   component vashisht_MUSER_lab4_seven_segment_display
      port ( clock      : in    std_logic; 
             finalclock : out   std_logic; 
             pushbutton : in    std_logic);
   end component;
   
begin
   anode(3 downto 0) <= anode_DUMMY(3 downto 0);
   XLXI_37 : byas_MUSER_lab4_seven_segment_display
      port map (a(3 downto 0)=>anode_DUMMY(3 downto 0),
                b0=>b(0),
                b1=>b(1),
                b2=>b(2),
                b3=>b(3),
                b4=>b(4),
                b5=>b(5),
                b6=>b(6),
                b7=>b(7),
                b8=>b(8),
                b9=>b(9),
                b10=>b(10),
                b11=>b(11),
                b12=>b(12),
                b13=>b(13),
                b14=>b(14),
                b15=>b(15),
                a1=>open,
                a2=>open,
                a3=>open,
                a4=>open,
                z(3 downto 0)=>XLXN_41(3 downto 0));
   
   XLXI_38 : finalmehlu_MUSER_lab4_seven_segment_display
      port map (d(3 downto 0)=>XLXN_41(3 downto 0),
                q(6 downto 0)=>cathode(6 downto 0));
   
   XLXI_43 : ringmehlu_MUSER_lab4_seven_segment_display
      port map (clock=>XLXN_44,
                A(3 downto 0)=>anode_DUMMY(3 downto 0));
   
   XLXI_44 : vashisht_MUSER_lab4_seven_segment_display
      port map (clock=>clk,
                pushbutton=>pushbutton,
                finalclock=>XLXN_44);
   
end BEHAVIORAL;
----------------------------------------------------------------------------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity moreslow is
port(clk: in std_logic;
     clk1 : out std_logic);
     end moreslow;

ARCHITECTURE Behavioral1 OF moreslow IS
   signal abc1        : std_logic;
   signal abc2        : std_logic;
   signal abc3        : std_logic;
   signal abc4        : std_logic;
   signal abc5        : std_logic;
   signal abc6        : std_logic;
   signal abc7        : std_logic;
   signal abc8        : std_logic;
   signal abc9        : std_logic;
   signal abc10        : std_logic;
   signal abc11        : std_logic;
   signal abc12        : std_logic;
   signal abc13        : std_logic;

signal clk1_dummy         : std_logic;
begin
clk1<=clk1_dummy;
 abcd1 : FD
                     port map (C=>clk,
                               D=>abc1,
                               Q=>abc2);
               abcd2 : FD
                     port map (C=>abc2,
                               D=>abc3,
                               Q=>abc4);
               abcd3 : FD
                     port map (C=>abc4,
                               D=>abc5,
                               Q=>abc6);
               abcd4 : FD
                     port map (C=>abc6,
                               D=>abc7,
                               Q=>abc8);
          --     abcd5 : FD
          --           port map (C=>abc8,
          --                     D=>abc9,
          --                     Q=>abc10);
               abcd6 : FD
                     port map (C=>abc8,
                               D=>abc11,
                               Q=>abc12);
               abcd7 : FD
                     port map (C=>abc12,
                               D=>abc13,
                               Q=>clk1_dummy);


ad1 : INV
      port map (I=>abc2,
                O=>abc1);
ad2 : INV
      port map (I=>abc4,
                O=>abc3);
ad3 : INV
      port map (I=>abc6,
                O=>abc5);

ad4 : INV
      port map (I=>abc8,
                O=>abc7);
--ad5 : INV
--      port map (I=>abc10,
--              O=>abc9);
ad6 : INV
      port map (I=>abc12,
                O=>abc11);
ad7 : INV
      port map (I=>clk1_dummy,
                O=>abc13);

end Behavioral1;

library IEEE; 
use IEEE.STD_LOGIC_1164.all;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity encoder8to3 is
port(
din : in STD_LOGIC_VECTOR(7 downto 0);
dout : out integer
);
end encoder8to3;

architecture encoder8to3_arc of encoder8to3 is
begin
process(din)
begin
c1 : case din is
 when "10000000"=>
 dout <= 4 ;
 when "01000000"=>
 dout <= 5  ;
 when "00100000"=>
 dout <= 6  ;
 when "00000100"=>
 dout <= 3  ;
 when "00000010"=>
 dout <= 2  ;
 when  "00000001"=>
 dout<=1;
 when others =>
 dout<=0;
end case;
end process;
end encoder8to3_arc;


library IEEE;
use IEEE.STD_LOGIC_1164.all;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL; 

entity totalreq is
 port(
 a : in STD_LOGIC_VECTOR(3 downto 0);
 b : out integer
 );
end totalreq;
 
architecture bhv of totalreq is
begin
 
process(a)
begin
 if (a="0001") then
 b <= 1;
 elsif (a="0011") then
 b <= 2;
 elsif (a="0111") then
 b <= 3;
 elsif (a="1111") then
 b <= 4;
 else b<=0;
 end if;
end process;
 
end bhv;


library IEEE;
use IEEE.STD_LOGIC_1164.all;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL; 

entity encoder2 is
 port(
 a : in STD_LOGIC_VECTOR(3 downto 0);
 b : out STD_LOGIC_VECTOR(2 downto 0)
 );
end encoder2;
 
architecture bhv of encoder2 is
begin
 
process(a)
begin
 if (a="0001") then
 b <= "100";
 elsif (a="0010") then
 b <= "101";
 elsif (a="0100") then
 b <= "110";
 elsif (a="1000") then
 b <= "111";
 else b<="000";
 end if;
end process;
 
end bhv;

library IEEE;
use IEEE.STD_LOGIC_1164.all;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity encoder1 is
 port(
 a : in STD_LOGIC_VECTOR(1 downto 0);
 b : out integer
 );
end encoder1;
 
architecture bhv of encoder1 is
begin
 
process(a)
begin
 if (a="00") then
 b <= 0;
 elsif (a="01") then
 b <= 1;
 elsif a="10" then
 b <= 2;
 else b<= 3 ;
 end if;
end process;
 
end bhv;


----------------------------------------------------------------------------------------------------------------------------------------------------

library IEEE;
--use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

ENTITY lab8_elevator_control is
PORT(up_request , down_request ,lift2_floor , lift1_floor: in std_logic_vector(3 downto 0);
up_request_indicator , down_request_indicator , lift2_floor_indicator , lift1_floor_indicator : out std_logic_vector(3 downto 0):="0000";
door_open , door_closed  : in std_logic_vector(1 downto 0);
reset  , clk: in std_logic:='0';
 cathode : out std_logic_vector(6 downto 0);
   anode : out std_logic_vector(3 downto 0)
);
END lab8_elevator_control;

ARCHITECTURE Behavioral OF lab8_elevator_control IS
	Signal sim_mode : std_logic:='0';
	Signal  done,clk2,clk1,clk2t: std_logic;
	signal output_valid_temp : std_logic:='0';
	signal totalreq_temp1,totalreq_temp2 : std_logic_vector(3 downto 0):="0000"; 
	signal i0,i1,i2,i3,i4,i5,i6,i7,i8,a0,a1,a2,a3,a4,l1f,l2f,ab,l1ft,l2ft,crs1109,crs2109,crs276,crs176,crs143,crs243 : integer:=0;
	signal ab3,ab1,ab2,ab4,ab5,ab6,ab7,x,x1,x2,x3,ax1,ax2 : integer;
	signal i10,i11,i12,i13,i14,i15,i16,i17,i18,a10,a11,a12,a13,a14 : integer :=0;
signal up_request_indicatord,down_request_indicatord,lift1_floor_indicatord,lift2_floor_indicatord : std_logic_vector(3 downto 0):="0000";
	Signal s1,s: std_logic_vector(2 downto 0):="000";
   Signal b: std_logic_vector(15 downto 0):="0110000000000000";
    Signal curr_req_status1,curr_req_status2,temp2req,temp1req: std_logic_vector(11 downto 0); 
    Signal l1fl,l2fl : std_logic_vector(1 downto 0):="00";
    signal l1fl_temp,l2fl_temp : std_logic_vector(2 downto 0):="000";
     signal l1fl1_temp,l2fl2_temp : std_logic_vector(1 downto 0);
    Signal l1s,l2s: std_logic_vector(3 downto 0):="0110";
    Signal req_temp: std_logic_vector(7 downto 0):="00000000";
    Signal dd_temp: std_logic_vector(7 downto 0):="00000000";
    Signal c: std_logic_vector(7 downto 0):="00000001";	
    Signal mn: std_logic_vector(15 downto 0):="0000000000000001";	
	COMPONENT lab4_seven_segment_display
	PORT (
	      b: in std_logic_vector(15 downto 0);
		  clk: in std_logic;
		  pushbutton:in std_logic;
		  anode: out std_logic_vector(3 downto 0);
		  cathode: out std_logic_vector(6 downto 0)
		 );
	END Component;
	component totalreq is
     port(
     a : in STD_LOGIC_VECTOR(3 downto 0);
     b : out integer
     );
    end component;
	component encoder8to3 is
    port(
    din : in STD_LOGIC_VECTOR(7 downto 0);
    dout : out integer
    );
    end component;
	COMPONENT encoder2
        PORT (  a : in STD_LOGIC_VECTOR(3 downto 0);
                b : out STD_LOGIC_VECTOR(2 downto 0)
             );
        END Component;
        component encoder1
         port(
         a : in STD_LOGIC_VECTOR(1 downto 0);
         b : out integer
         );
        end component;
        component slowclockmahla_MUSER_lab4_seven_segment_display is
           port ( clock     : in    std_logic; 
                  slowclock : out   std_logic);
        end component;
        component moreslow is
        port(clk: in std_logic;
             clk1 : out std_logic);
             end component;  
BEGIN
	b0 : ENTITY WORK.lab4_seven_segment_display
	port map (clk => clk,anode =>anode,cathode => cathode,b => b,pushbutton => sim_mode);
	b01 : ENTITY WORK.encoder2
       port map (a=>lift1_floor,b=>l1fl_temp);
  bb01 : ENTITY WORK.slowclockmahla_MUSER_lab4_seven_segment_display
          port map (clock=>clk,slowclock=>clk1);
     a02 : ENTITY WORK.encoder1
       port map (a=>l1fl,b=>l1f);
        aa02 : ENTITY WORK.moreslow
         port map (clk=>clk1,clk1=>clk2);
       m02 : ENTITY WORK.encoder8to3
              port map (din=>req_temp,dout=>ab);
 ee02 : ENTITY WORK.totalreq
           port map (a=>totalreq_temp1,b=>ab1);
  ee01 : ENTITY WORK.totalreq
             port map (a=>totalreq_temp2,b=>ab2);
 c01 : ENTITY WORK.encoder2
              port map (a=>lift2_floor,b=>l2fl_temp);
            c02 : ENTITY WORK.encoder1
              port map (a=>l2fl,b=>l2f);
 c03:ENTITY WORK.encoder1
           port map (a=>l2fl2_temp,b=>l2ft);
 c04:ENTITY WORK.encoder1
           port map (a=>l1fl1_temp,b=>l1ft);
c05:ENTITY WORK.encoder1
           port map ( a=>curr_req_status1(10 downto 9),b=>crs1109 );
c06:ENTITY WORK.encoder1
           port map ( a=>curr_req_status2(10 downto 9),b=>crs2109 );
c1:ENTITY WORK.encoder1
                      port map ( a=>curr_req_status2(7 downto 6),b=>crs276 );

c2:ENTITY WORK.encoder1
           port map ( a=>curr_req_status1(7 downto 6),b=>crs176 );

c3:ENTITY WORK.encoder1
           port map ( a=>curr_req_status2(4 downto 3),b=>crs243 );

c4:ENTITY WORK.encoder1
           port map ( a=>curr_req_status1(4 downto 3),b=>crs143 );

--c5:ENTITY WORK.encoder1
   --        port map ( a=>curr_req_status2(10 downto 9),b=>crs2109 );

--c6:ENTITY WORK.encoder1
  --         port map ( a=>curr_req_status1(10 downto 9),b=>crs2109 );

b<=l1s&"00"&l1fl&l2s&"00"&l2fl; 
l1fl1_temp <= l1fl_temp(1 downto 0);
l2fl2_temp <= l2fl_temp(1 downto 0);
req_temp<=down_request&up_request;
ab3<=10-2*ab2;
-----taken out from process
totalreq_temp1<=curr_req_status1(11)&curr_req_status1(8)&curr_req_status1(5)&curr_req_status1(2);
totalreq_temp2<=curr_req_status2(11)&curr_req_status2(8)&curr_req_status2(5)&curr_req_status2(2);
--process(clk1)
--begin
--clk2t<=clk2;
--end process;
--------------------------------------------request-handler---------------------------------------------------------       
process(clk1,reset)
 begin
if reset='1' then
 curr_req_status1<="000000000000";
 curr_req_status2<="000000000000";
 lift1_floor_indicator<="0000";
 down_request_indicator<="0000";
 up_request_indicator<="0000";
 lift2_floor_indicator<="0000"; 
 elsif clk1='1' and clk1'event then
 x<=ab4;
 x1<=ab5;
 x2<=ab6;
 x3<=ab7;
 if (x=0 and ab4=1) or (ab5=1 and x1=0) then
 curr_req_status1<=curr_req_status1(8 downto 0)&"000";
 lift1_floor_indicator(l1f)<='0';
 down_request_indicator(l1f)<='0';
 up_request_indicator(l1f)<='0';
 end if;
 if (ab6=1 and x2=0) or (ab7=1 and x3=0) then
 lift2_floor_indicator(l2f)<='0';
 down_request_indicator(l2f)<='0';
 up_request_indicator(l2f)<='0';
 curr_req_status2<=curr_req_status2(8 downto 0)&"000";
 end if;
 
 if  not(l1fl1_temp = l1fl and l1s="0110") and l1fl_temp(2)='1' then 
 if curr_req_status1(11)='0' then
 curr_req_status1(11) <= '1' ;
 curr_req_status1(10 downto 9) <= l1fl1_temp ;
  lift1_floor_indicator(l1ft)<='1'; 
 elsif curr_req_status1(8)='0' and curr_req_status1(10 downto 9)/=l1fl1_temp then
if (l1f<l1ft and l1ft<crs1109) or  (l1f>l1ft and l1ft>crs1109) then 
  curr_req_status1<='1'&l1fl1_temp&curr_req_status1(11 downto 3);
  else
 curr_req_status1(8)<='1';
 curr_req_status1(7 downto 6)<=l1fl1_temp ;    
 end if;
 lift1_floor_indicator(l1ft)<='1';
  elsif curr_req_status1(5)='0' and curr_req_status1(10 downto 9)/=l1fl1_temp and curr_req_status1(7 downto 6)/=l1fl1_temp then
if (l1f<l1ft and l1ft<crs1109) or  (l1f>l1ft and l1ft>crs1109) then
 curr_req_status1<='1'&l1fl1_temp&curr_req_status1(11 downto 3);
  elsif (crs1109<l1ft and l1ft<crs176) or (crs1109>l1ft and l1ft>crs176)  then
  curr_req_status1<=curr_req_status1(11 downto 9)&'1'&l1fl1_temp&curr_req_status1(8 downto 3);
  else
 curr_req_status1(5)<='1';
 curr_req_status1(4 downto 3)<=l1fl1_temp;
end if;
 lift1_floor_indicator(l1ft)<='1';
  elsif curr_req_status1(2)='0' and curr_req_status1(10 downto 9)/=l1fl1_temp and curr_req_status1(7 downto 6)/=l1fl1_temp and curr_req_status1(4 downto 3)/=l1fl1_temp  then
 if (l1f<l1ft and l1ft<crs1109) or  (l1f>l1ft and l1ft>crs1109) then
  curr_req_status1<='1'&l1fl1_temp&curr_req_status1(11 downto 3);
  elsif (crs1109<l1ft and l1ft<crs176) or (crs1109>l1ft and l1ft>crs176)  then
  curr_req_status1<=curr_req_status1(11 downto 9)&'1'&l1fl1_temp&curr_req_status1(8 downto 3);
  elsif (crs176<l1ft and l1ft<crs143) or (crs176>l1ft and l1ft>crs143)  then
  curr_req_status1<=curr_req_status1(11 downto 6)&'1'&l1fl1_temp&curr_req_status1(5 downto 3);
  else
 curr_req_status1(2)<='1';
 curr_req_status1(1 downto 0)<=l1fl1_temp;
 end if;
 lift1_floor_indicator(l1ft)<='1';
 end if;
 end if;
  if  not(l2fl2_temp = l2fl and l2s="0110") and l2fl_temp(2)='1' then
 if curr_req_status2(11)='0' then
 curr_req_status2(11) <= '1' ;
 curr_req_status2(10 downto 9) <= l2fl2_temp ;
 lift2_floor_indicator(l2ft)<='1';
 elsif curr_req_status2(8)='0' and curr_req_status2(10 downto 9)/=l2fl2_temp then
 if (l2f<l2ft and l2ft<crs2109) or  (l2f>l2ft and l2ft>crs2109) then 
 curr_req_status2<='1'&l2fl2_temp&curr_req_status2(11 downto 3);
 else
 curr_req_status2(8)<='1';
 curr_req_status2(7 downto 6)<=l2fl2_temp ;
 end if;
 lift2_floor_indicator(l2ft)<='1';    
  elsif curr_req_status2(5)='0' and curr_req_status2(10 downto 9)/=l2fl2_temp and curr_req_status2(7 downto 6)/=l2fl2_temp then
if (l2f<l2ft and l2ft<crs2109) or  (l2f>l2ft and l2ft>crs2109) then
curr_req_status2<='1'&l2fl2_temp&curr_req_status2(11 downto 3);
 elsif (crs2109<l2ft and l2ft<crs276) or (crs2109>l2ft and l2ft>crs276)  then
 curr_req_status2<=curr_req_status2(11 downto 9)&'1'&l2fl2_temp&curr_req_status2(8 downto 3);
 else
 curr_req_status2(5)<='1';
 curr_req_status2(4 downto 3)<=l2fl2_temp;
 end if;
 lift2_floor_indicator(l2ft)<='1';
  elsif curr_req_status2(2)='0' and curr_req_status2(10 downto 9)/=l2fl2_temp and curr_req_status2(7 downto 6)/=l2fl2_temp and curr_req_status2(4 downto 3)/=l2fl2_temp then
if (l2f<l2ft and l2ft<crs2109) or  (l2f>l2ft and l2ft>crs2109) then
curr_req_status2<='1'&l2fl2_temp&curr_req_status2(11 downto 3);
elsif (crs2109<l2ft and l2ft<crs276) or (crs2109>l2ft and l2ft>crs276)  then
curr_req_status2<=curr_req_status2(11 downto 9)&'1'&l2fl2_temp&curr_req_status2(8 downto 3);
elsif (crs276<l2ft and l2ft<crs243) or (crs276>l2ft and l2ft>crs243)  then
curr_req_status2<=curr_req_status2(11 downto 6)&'1'&l2fl2_temp&curr_req_status2(5 downto 3);
else
curr_req_status2(2)<='1';
curr_req_status2(1 downto 0)<=l2fl2_temp;
end if;
lift2_floor_indicator(l2ft)<='1';
end if;
end if;
 -------only reset if------------
 if (l2fl_temp(2) or l1fl_temp(2)) ='0' then
 --if ab/=0 then 
 if ab=1 then
  --if not((l1fl="00" and l1s="0110") or (l2fl="00" and l2s="0110")) then
 --up_request_indicator(0)<='1';
 --end if;
 if ((l1fl="00" and l1s="0110")  or (l2fl="00" and l2s="0110")) then 
 elsif ab1=ab2 then
 if l2f<l1f then
 if not((curr_req_status2(11)='1' and curr_req_status2(10 downto 9)="00") or(curr_req_status2(8)='1' and curr_req_status2(7 downto 6)="00") or (curr_req_status2(5)='1' and  curr_req_status2(4 downto 3)="00") or (curr_req_status2(2)='1' and  curr_req_status2(1 downto 0)="00")) then
 curr_req_status2(10-3*ab2 downto 9-3*ab2)<="00";
 curr_req_status2(11-3*ab2)<='1';
 up_request_indicator(0)<='1';
 end if;  
 elsif not((curr_req_status1(11)='1' and curr_req_status1(10 downto 9)="00") or(curr_req_status1(8)='1' and curr_req_status1(7 downto 6)="00") or (curr_req_status1(5)='1' and  curr_req_status1(4 downto 3)="00") or (curr_req_status1(2)='1' and  curr_req_status1(1 downto 0)="00")) then 
 curr_req_status1(10-3*ab1 downto 9-3*ab1)<="00";
 curr_req_status1(11-3*ab1)<='1';
 up_request_indicator(0)<='1'; 
 end if;
 elsif ab1>ab2 then
 if not((curr_req_status2(11)='1' and curr_req_status2(10 downto 9)="00") or(curr_req_status2(8)='1' and curr_req_status2(7 downto 6)="00") or (curr_req_status2(5)='1' and  curr_req_status2(4 downto 3)="00") or (curr_req_status2(2)='1' and  curr_req_status2(1 downto 0)="00")) then
 curr_req_status2(10-3*ab2 downto 9-3*ab2)<="00";
 curr_req_status2(11-3*ab2)<='1';
 up_request_indicator(0)<='1';
 end if;
 elsif not((curr_req_status1(11)='1' and curr_req_status1(10 downto 9)="00") or(curr_req_status1(8)='1' and curr_req_status1(7 downto 6)="00") or (curr_req_status1(5)='1' and  curr_req_status1(4 downto 3)="00") or (curr_req_status1(2)='1' and  curr_req_status1(1 downto 0)="00")) then
 if ab1<4 then
 curr_req_status1(10-3*ab1 downto 9-3*ab1)<="00";
 curr_req_status1(11-3*ab1)<='1';
 up_request_indicator(0)<='1';
 end if;
 end if;
 elsif ab=2 then
 --if not((l1fl="01" and l1s="0110") or (l2fl="01" and l2s="0110")) then
 --up_request_indicator(1)<='1';
 --end if; 
 if ((l1fl="01" and l1s="0110")  or (l2fl="01" and l2s="0110")) then 
 elsif   l1fl="00" and not(((curr_req_status2(11)='1' and curr_req_status2(10 downto 9)="01") or (curr_req_status2(8)='1' and curr_req_status2(7 downto 6)="01") or (curr_req_status2(5)='1' and  curr_req_status2(4 downto 3)="01") or (curr_req_status2(2)='1' and  curr_req_status2(1 downto 0)="01")) or (l2fl="01" and l2s="0110")) then 
 if not((curr_req_status1(11)='1' and curr_req_status1(10 downto 9)="01") or(curr_req_status1(8)='1' and curr_req_status1(7 downto 6)="01") or (curr_req_status1(5)='1' and  curr_req_status1(4 downto 3)="01") or (curr_req_status1(2)='1' and  curr_req_status1(1 downto 0)="01")) then
  curr_req_status1(10-3*ab1 downto 9-3*ab1)<="01";
 curr_req_status1(11-3*ab1)<='1';
 up_request_indicator(1)<='1';
 end if;
 elsif  l2fl="00" and not(((curr_req_status1(11)='1' and curr_req_status1(10 downto 9)="01") or (curr_req_status2(8)='1' and curr_req_status2(7 downto 6)="01") or (curr_req_status2(5)='1' and  curr_req_status2(4 downto 3)="01") or (curr_req_status2(2)='1' and  curr_req_status2(1 downto 0)="01")) or (l2fl="01" and l2s="0110")) then 
 if not((curr_req_status2(11)='1' and curr_req_status2(10 downto 9)="01") or(curr_req_status2(8)='1' and curr_req_status2(7 downto 6)="01") or (curr_req_status2(5)='1' and  curr_req_status2(4 downto 3)="01") or (curr_req_status2(2)='1' and  curr_req_status2(1 downto 0)="01")) then
 curr_req_status2(10-3*ab2 downto 9-3*ab2)<="01";
 curr_req_status2(11-3*ab2)<='1';
 up_request_indicator(1)<='1';
 end if;
 elsif l1fl="01" and l1s="1110" then
 if curr_req_status1(11)='1' and (curr_req_status1(10 downto 9)="00") then
 curr_req_status1<="101"&curr_req_status1(11 downto 3);
 up_request_indicator(1)<='1';
 end if;
  elsif l2fl="01" and l1s="1110" then
 if curr_req_status2(11)='1' and (curr_req_status2(10 downto 9)="00") then
   curr_req_status2<="101"&curr_req_status2(11 downto 3);
   up_request_indicator(1)<='1';
   end if;
 elsif ab1=ab2 then
 if l2f<l1f then
 if not((curr_req_status2(11)='1' and curr_req_status2(10 downto 9)="01") or(curr_req_status2(8)='1' and curr_req_status2(7 downto 6)="01") or (curr_req_status2(5)='1' and  curr_req_status2(4 downto 3)="01") or (curr_req_status2(2)='1' and  curr_req_status2(1 downto 0)="01")) then
  curr_req_status2(10-3*ab2 downto 9-3*ab2)<="01";
  curr_req_status2(11-3*ab2)<='1';
  up_request_indicator(1)<='1';
  end if; 
 else
 if not((curr_req_status1(11)='1' and curr_req_status1(10 downto 9)="01") or(curr_req_status1(8)='1' and curr_req_status1(7 downto 6)="01") or (curr_req_status1(5)='1' and  curr_req_status1(4 downto 3)="01") or (curr_req_status1(2)='1' and  curr_req_status1(1 downto 0)="01")) then 
  curr_req_status1(10-3*ab1 downto 9-3*ab1)<="01";
  curr_req_status1(11-3*ab1)<='1';
  up_request_indicator(1)<='1'; 
  end if;
 end if;
 elsif ab1>ab2 then
 if not((curr_req_status2(11)='1' and curr_req_status2(10 downto 9)="01") or(curr_req_status2(8)='1' and curr_req_status2(7 downto 6)="01") or (curr_req_status2(5)='1' and  curr_req_status2(4 downto 3)="01") or (curr_req_status2(2)='1' and  curr_req_status2(1 downto 0)="01")) then
 curr_req_status2(10-3*ab2 downto 9-3*ab2)<="01";
 curr_req_status2(11-3*ab2)<='1';
 up_request_indicator(1)<='1';
 end if;
 elsif not((curr_req_status1(11)='1' and curr_req_status1(10 downto 9)="01") or(curr_req_status1(8)='1' and curr_req_status1(7 downto 6)="01") or (curr_req_status1(5)='1' and  curr_req_status1(4 downto 3)="01") or (curr_req_status1(2)='1' and  curr_req_status1(1 downto 0)="01")) then
 if ab1<4 then
 curr_req_status1(10-3*ab1 downto 9-3*ab1)<="01";
 curr_req_status1(11-3*ab1)<='1';
 up_request_indicator(1)<='1';
 end if;
 end if; 
 elsif ab=3 then
 --if not((l1fl="10" and l1s="0110") or (l2fl="10" and l2s="0110")) then
 --up_request_indicator(2)<='1';
 --end if;
 if ((l1fl="10" and l1s="0110")  or (l2fl="10" and l2s="0110")) then 
 elsif  (curr_req_status1(11)='1' and curr_req_status1(10 downto 9)="11") and (l1fl="00" or l1fl="01" )then 
 if (curr_req_status1(8)='1' and curr_req_status1(7 downto 6)="10") then
 curr_req_status1<="110"&curr_req_status1(11 downto 9)&curr_req_status1(5 downto 0);
 up_request_indicator(2)<='1';
 elsif (curr_req_status1(5)='1' and curr_req_status1(4 downto 3)="10") then
 curr_req_status1<="110"&curr_req_status1(11 downto 6)&curr_req_status1(2 downto 0);
 up_request_indicator(2)<='1';
 elsif (curr_req_status1(2)='1' and curr_req_status1(1 downto 0)="10") then
 curr_req_status1<="110"&curr_req_status1(11 downto 3);
 up_request_indicator(2)<='1';
 else curr_req_status1<="110"&curr_req_status1(11 downto 3); up_request_indicator(2)<='1';
 end if ;
 elsif  (curr_req_status2(11)='1' and curr_req_status2(10 downto 9)="11") and (l2fl="00" or l2fl="01" ) then 
 if (curr_req_status2(8)='1' and curr_req_status2(7 downto 6)="10") then
 curr_req_status2<="110"&curr_req_status2(11 downto 9)&curr_req_status2(5 downto 0);
 up_request_indicator(2)<='1';
 elsif (curr_req_status2(5)='1' and curr_req_status2(4 downto 3)="10") then
 curr_req_status2<="110"&curr_req_status2(11 downto 6)&curr_req_status2(2 downto 0);
 up_request_indicator(2)<='1';
 elsif (curr_req_status1(2)='1' and curr_req_status1(1 downto 0)="10") then
 curr_req_status2<="110"&curr_req_status2(11 downto 3);
 up_request_indicator(2)<='1';
 else curr_req_status2<="110"&curr_req_status2(11 downto 3);
 up_request_indicator(2)<='1';
 end if ;
 elsif ab1=0 and ab2=0 and l1f=3 and l2f=3 then
 curr_req_status1(10-3*ab1 downto 9-3*ab1)<="10";
 curr_req_status1(11-3*ab1)<='1';
 up_request_indicator(2)<='1';
 elsif ab1=ab2 then
 if l2f>l1f and l1f<2 and l2f<2 then
  if not((curr_req_status2(11)='1' and curr_req_status2(10 downto 9)="10") or(curr_req_status2(8)='1' and curr_req_status2(7 downto 6)="10") or (curr_req_status2(5)='1' and  curr_req_status2(4 downto 3)="10") or (curr_req_status2(2)='1' and  curr_req_status2(1 downto 0)="10")) then
 curr_req_status2(10-3*ab2 downto 9-3*ab2)<="10";
 curr_req_status2(11-3*ab2)<='1';
 up_request_indicator(2)<='1';
 end if;
 elsif l1f<2 and l2f<2 and not((curr_req_status1(11)='1' and curr_req_status1(10 downto 9)="00") or(curr_req_status1(8)='1' and curr_req_status1(7 downto 6)="00") or (curr_req_status1(5)='1' and  curr_req_status1(4 downto 3)="00") or (curr_req_status1(2)='1' and  curr_req_status1(1 downto 0)="00")) then 
   curr_req_status1(10-3*ab1 downto 9-3*ab1)<="10";
   curr_req_status1(11-3*ab1)<='1';
   up_request_indicator(2)<='1'; 
 end if;
 if l2f=3 and l1f=0 and ab1=ab2 then
  if not((curr_req_status2(11)='1' and curr_req_status2(10 downto 9)="10") or(curr_req_status2(8)='1' and curr_req_status2(7 downto 6)="10") or (curr_req_status2(5)='1' and  curr_req_status2(4 downto 3)="10") or (curr_req_status2(2)='1' and  curr_req_status2(1 downto 0)="10")) then
 curr_req_status2(10-3*ab2 downto 9-3*ab2)<="10";
 curr_req_status2(11-3*ab2)<='1';
 up_request_indicator(2)<='1';
 end if;
 elsif not((curr_req_status1(11)='1' and curr_req_status1(10 downto 9)="00") or(curr_req_status1(8)='1' and curr_req_status1(7 downto 6)="00") or (curr_req_status1(5)='1' and  curr_req_status1(4 downto 3)="00") or (curr_req_status1(2)='1' and  curr_req_status1(1 downto 0)="00")) then 
    curr_req_status1(10-3*ab1 downto 9-3*ab1)<="10";
    curr_req_status1(11-3*ab1)<='1';
    up_request_indicator(2)<='1'; 
 end if;
 elsif ab1>ab2 then
 if not((curr_req_status2(11)='1' and curr_req_status2(10 downto 9)="10") or(curr_req_status2(8)='1' and curr_req_status2(7 downto 6)="10") or (curr_req_status2(5)='1' and  curr_req_status2(4 downto 3)="10") or (curr_req_status2(2)='1' and  curr_req_status2(1 downto 0)="10")) then
 curr_req_status2(10-3*ab2 downto 9-3*ab2)<="10";
 curr_req_status2(11-3*ab2)<='1';
 up_request_indicator(2)<='1';
 end if;
 elsif not((curr_req_status1(11)='1' and curr_req_status1(10 downto 9)="10") or(curr_req_status1(8)='1' and curr_req_status1(7 downto 6)="10") or (curr_req_status1(5)='1' and  curr_req_status1(4 downto 3)="10") or (curr_req_status1(2)='1' and  curr_req_status1(1 downto 0)="10")) then
 if ab1<4 then
 curr_req_status1(10-3*ab1 downto 9-3*ab1)<="10";
 curr_req_status1(11-3*ab1)<='1';
 up_request_indicator(2)<='1';
 end if;
 end if; 
 elsif ab=4 then
 --if not((l1fl="11" and l1s="0110") or (l2fl="11" and l2s="0110")) then
 --down_request_indicator(3)<='1';
 --end if;
 if ((l1fl="11" and l1s="0110")  or (l2fl="11" and l2s="0110")) then 
  elsif ab1=ab2 then
  if l2f>l1f then
  if not((curr_req_status2(11)='1' and curr_req_status2(10 downto 9)="11") or(curr_req_status2(8)='1' and curr_req_status2(7 downto 6)="11") or (curr_req_status2(5)='1' and  curr_req_status2(4 downto 3)="11") or (curr_req_status2(2)='1' and  curr_req_status2(1 downto 0)="11")) then
  curr_req_status2(10-3*ab2 downto 9-3*ab2)<="11";
  curr_req_status2(11-3*ab2)<='1';
  down_request_indicator(3)<='1';
  end if;  
  elsif not((curr_req_status1(11)='1' and curr_req_status1(10 downto 9)="11") or(curr_req_status1(8)='1' and curr_req_status1(7 downto 6)="11") or (curr_req_status1(5)='1' and  curr_req_status1(4 downto 3)="11") or (curr_req_status1(2)='1' and  curr_req_status1(1 downto 0)="11")) then 
  curr_req_status1(10-3*ab1 downto 9-3*ab1)<="11";
  curr_req_status1(11-3*ab1)<='1';
  down_request_indicator(3)<='1'; 
  end if;
 elsif ab1>ab2 then
  if not((curr_req_status2(11)='1' and curr_req_status2(10 downto 9)="11") or(curr_req_status2(8)='1' and curr_req_status2(7 downto 6)="11") or (curr_req_status2(5)='1' and  curr_req_status2(4 downto 3)="11") or (curr_req_status2(2)='1' and  curr_req_status2(1 downto 0)="11")) then
  curr_req_status2(10-3*ab2 downto 9-3*ab2)<="11";
  curr_req_status2(11-3*ab2)<='1';
  down_request_indicator(3)<='1';
  end if;
  elsif not((curr_req_status1(11)='1' and curr_req_status1(10 downto 9)="11") or(curr_req_status1(8)='1' and curr_req_status1(7 downto 6)="11") or (curr_req_status1(5)='1' and  curr_req_status1(4 downto 3)="11") or (curr_req_status1(2)='1' and  curr_req_status1(1 downto 0)="11")) then
  if ab1<4 then
  curr_req_status1(10-3*ab1 downto 9-3*ab1)<="11";
  curr_req_status1(11-3*ab1)<='1';
  down_request_indicator(3)<='1';
  end if;
  end if;
 elsif ab=5 then
 --if not((l1fl="10" and l1s="0110") or (l2fl="10" and l2s="0110")) then
 --down_request_indicator(2)<='1';
 --end if;
 ------------------------------------------------------refrence---------------------------------------------------
 if ((l1fl="10" and l1s="0110")  or (l2fl="10" and l2s="0110")) then 
  elsif   l1fl="11" and not(((curr_req_status2(11)='1' and curr_req_status2(10 downto 9)="10") or (curr_req_status2(8)='1' and curr_req_status2(7 downto 6)="10") or (curr_req_status2(5)='1' and  curr_req_status2(4 downto 3)="10") or (curr_req_status2(2)='1' and  curr_req_status2(1 downto 0)="10")) or (l2fl="10" and l2s="0110")) then 
  if not((curr_req_status1(11)='1' and curr_req_status1(10 downto 9)="10") or(curr_req_status1(8)='1' and curr_req_status1(7 downto 6)="10") or (curr_req_status1(5)='1' and  curr_req_status1(4 downto 3)="10") or (curr_req_status1(2)='1' and  curr_req_status1(1 downto 0)="10")) then
   curr_req_status1(10-3*ab1 downto 9-3*ab1)<="10";
  curr_req_status1(11-3*ab1)<='1';
  down_request_indicator(2)<='1';
  end if;
  elsif  l2fl="11" and not(((curr_req_status1(11)='1' and curr_req_status1(10 downto 9)="10") or (curr_req_status2(8)='1' and curr_req_status2(7 downto 6)="10") or (curr_req_status2(5)='1' and  curr_req_status2(4 downto 3)="10") or (curr_req_status2(2)='1' and  curr_req_status2(1 downto 0)="10")) or (l2fl="10" and l2s="0110")) then 
  if not((curr_req_status2(11)='1' and curr_req_status2(10 downto 9)="10") or(curr_req_status2(8)='1' and curr_req_status2(7 downto 6)="10") or (curr_req_status2(5)='1' and  curr_req_status2(4 downto 3)="10") or (curr_req_status2(2)='1' and  curr_req_status2(1 downto 0)="10")) then
  curr_req_status2(10-3*ab2 downto 9-3*ab2)<="10";
  curr_req_status2(11-3*ab2)<='1';
  down_request_indicator(2)<='1';
  end if;
  elsif l1fl="10" and l1s="1110" then
  if curr_req_status1(11)='1' and (curr_req_status1(10 downto 9)="11") then
  curr_req_status1<="110"&curr_req_status1(11 downto 3);
  down_request_indicator(2)<='1';
  end if;
   elsif l2fl="10" and l1s="1110" then
  if curr_req_status2(11)='1' and (curr_req_status2(10 downto 9)="11") then
    curr_req_status2<="110"&curr_req_status2(11 downto 3);
    down_request_indicator(2)<='1';
    end if;
  elsif ab1=ab2 then
  if l2f>l1f then
  if not((curr_req_status2(11)='1' and curr_req_status2(10 downto 9)="10") or(curr_req_status2(8)='1' and curr_req_status2(7 downto 6)="10") or (curr_req_status2(5)='1' and  curr_req_status2(4 downto 3)="10") or (curr_req_status2(2)='1' and  curr_req_status2(1 downto 0)="10")) then
   curr_req_status2(10-3*ab2 downto 9-3*ab2)<="10";
   curr_req_status2(11-3*ab2)<='1';
   down_request_indicator(2)<='1';
   end if; 
  else
  if not((curr_req_status1(11)='1' and curr_req_status1(10 downto 9)="10") or(curr_req_status1(8)='1' and curr_req_status1(7 downto 6)="10") or (curr_req_status1(5)='1' and  curr_req_status1(4 downto 3)="10") or (curr_req_status1(2)='1' and  curr_req_status1(1 downto 0)="10")) then 
   curr_req_status1(10-3*ab1 downto 9-3*ab1)<="10";
   curr_req_status1(11-3*ab1)<='1';
   down_request_indicator(2)<='1'; 
   end if;
  end if;
  elsif ab1>ab2 then
  if not((curr_req_status2(11)='1' and curr_req_status2(10 downto 9)="10") or(curr_req_status2(8)='1' and curr_req_status2(7 downto 6)="10") or (curr_req_status2(5)='1' and  curr_req_status2(4 downto 3)="10") or (curr_req_status2(2)='1' and  curr_req_status2(1 downto 0)="10")) then
  curr_req_status2(10-3*ab2 downto 9-3*ab2)<="10";
  curr_req_status2(11-3*ab2)<='1';
  down_request_indicator(2)<='1';
  end if;
  elsif not((curr_req_status1(11)='1' and curr_req_status1(10 downto 9)="10") or(curr_req_status1(8)='1' and curr_req_status1(7 downto 6)="10") or (curr_req_status1(5)='1' and  curr_req_status1(4 downto 3)="10") or (curr_req_status1(2)='1' and  curr_req_status1(1 downto 0)="10")) then
  if ab1<4 then
  curr_req_status1(10-3*ab1 downto 9-3*ab1)<="10";
  curr_req_status1(11-3*ab1)<='1';
  down_request_indicator(2)<='1';
  end if;
  end if; 
 -----------------------------------------------------------------------------------------------------------------
 elsif ab=6 then
 --if not((l1fl="01" and l1s="0110") or (l2fl="01" and l2s="0110")) then
 --down_request_indicator(1)<='1';
 --end if;
 if ((l1fl="01" and l1s="0110")  or (l2fl="01" and l2s="0110")) then 
 elsif  (curr_req_status1(11)='1' and curr_req_status1(10 downto 9)="00") and (l1fl="11" or l1fl="10" )then 
 if (curr_req_status1(8)='1' and curr_req_status1(7 downto 6)="01") then
 curr_req_status1<="101"&curr_req_status1(11 downto 9)&curr_req_status1(5 downto 0);
 down_request_indicator(1)<='1';
 elsif (curr_req_status1(5)='1' and curr_req_status1(4 downto 3)="01") then
 curr_req_status1<="101"&curr_req_status1(11 downto 6)&curr_req_status1(2 downto 0);
 down_request_indicator(1)<='1';
 elsif (curr_req_status1(2)='1' and curr_req_status1(1 downto 0)="01") then
 curr_req_status1<="101"&curr_req_status1(11 downto 3);
 down_request_indicator(1)<='1';
 else curr_req_status1<="101"&curr_req_status1(11 downto 3);
 down_request_indicator(1)<='1';
 end if ;
 elsif  (curr_req_status2(11)='1' and curr_req_status2(10 downto 9)="00") and (l2fl="11" or l2fl="10" ) then 
 if (curr_req_status2(8)='1' and curr_req_status2(7 downto 6)="01") then
 curr_req_status2<="101"&curr_req_status2(11 downto 9)&curr_req_status2(5 downto 0);
 down_request_indicator(1)<='1';
 elsif (curr_req_status2(5)='1' and curr_req_status2(4 downto 3)="01") then
 curr_req_status2<="101"&curr_req_status2(11 downto 6)&curr_req_status2(2 downto 0);
 down_request_indicator(1)<='1';
 elsif (curr_req_status1(2)='1' and curr_req_status1(1 downto 0)="01") then
 curr_req_status2<="101"&curr_req_status2(11 downto 3);
 down_request_indicator(1)<='1';
 else curr_req_status2<="101"&curr_req_status2(11 downto 3);
 down_request_indicator(1)<='1';
 end if ; 

----------------------------------------------------start
 elsif ab1=0 and ab2=0 and l1f=0 and l2f=0 then
   curr_req_status1(10-3*ab1 downto 9-3*ab1)<="01";
   curr_req_status1(11-3*ab1)<='1';
   down_request_indicator(1)<='1';
 elsif ab1=ab2 then
   if l2f>l1f and l1f<2 and l2f<2 then
    if not((curr_req_status2(11)='1' and curr_req_status2(10 downto 9)="01") or(curr_req_status2(8)='1' and curr_req_status2(7 downto 6)="01") or (curr_req_status2(5)='1' and  curr_req_status2(4 downto 3)="01") or (curr_req_status2(2)='1' and  curr_req_status2(1 downto 0)="01")) then
   curr_req_status2(10-3*ab2 downto 9-3*ab2)<="01";
   curr_req_status2(11-3*ab2)<='1';
   down_request_indicator(1)<='1';
   end if;
   elsif l1f<2 and l2f<2 and not((curr_req_status1(11)='1' and curr_req_status1(10 downto 9)="11") or(curr_req_status1(8)='1' and curr_req_status1(7 downto 6)="11") or (curr_req_status1(5)='1' and  curr_req_status1(4 downto 3)="11") or (curr_req_status1(2)='1' and  curr_req_status1(1 downto 0)="11")) then 
     curr_req_status1(10-3*ab1 downto 9-3*ab1)<="01";
     curr_req_status1(11-3*ab1)<='1';
     down_request_indicator(1)<='1'; 
   end if;
   if l2f=3 and l1f=0 and ab1=ab2 then
    if not((curr_req_status2(11)='1' and curr_req_status2(10 downto 9)="01") or(curr_req_status2(8)='1' and curr_req_status2(7 downto 6)="01") or (curr_req_status2(5)='1' and  curr_req_status2(4 downto 3)="01") or (curr_req_status2(2)='1' and  curr_req_status2(1 downto 0)="01")) then
   curr_req_status2(10-3*ab2 downto 9-3*ab2)<="01";
   curr_req_status2(11-3*ab2)<='1';
   down_request_indicator(1)<='1';
   end if;
   elsif not((curr_req_status1(11)='1' and curr_req_status1(10 downto 9)="11") or(curr_req_status1(8)='1' and curr_req_status1(7 downto 6)="11") or (curr_req_status1(5)='1' and  curr_req_status1(4 downto 3)="11") or (curr_req_status1(2)='1' and  curr_req_status1(1 downto 0)="11")) then 
   curr_req_status1(10-3*ab1 downto 9-3*ab1)<="01";
   curr_req_status1(11-3*ab1)<='1';
   down_request_indicator(1)<='1';
   end if;
-----------------------------------end
 elsif ab1>ab2 then
 if not((curr_req_status2(11)='1' and curr_req_status2(10 downto 9)="01") or(curr_req_status2(8)='1' and curr_req_status2(7 downto 6)="01") or (curr_req_status2(5)='1' and  curr_req_status2(4 downto 3)="01") or (curr_req_status2(2)='1' and  curr_req_status2(1 downto 0)="01")) then
 curr_req_status2(10-3*ab2 downto 9-3*ab2)<="01";
 curr_req_status2(11-3*ab2)<='1';
 down_request_indicator(1)<='1';
 end if;
 elsif not((curr_req_status1(11)='1' and curr_req_status1(10 downto 9)="01") or(curr_req_status1(8)='1' and curr_req_status1(7 downto 6)="01") or (curr_req_status1(5)='1' and  curr_req_status1(4 downto 3)="01") or (curr_req_status1(2)='1' and  curr_req_status1(1 downto 0)="01")) then
 if ab1<4 then
 curr_req_status1(10-3*ab1 downto 9-3*ab1)<="01";
 curr_req_status1(11-3*ab1)<='1';
 down_request_indicator(1)<='1';
 end if;
 end if; 
 end if ;
 end if;
 end if; 
 --end if;           
 end process;      
-----------------------------------------lift1-control-system-----------------------------------------------
PROCESS(clk2,reset)
BEGIN
temp1req<=curr_req_status1;
if reset='1' then
s<="000";
i0<=0;
i1<=0;
i2<=0;
i3<=0;
i4<=0;
i5<=0;
i6<=0;
i7<=0;
i8<=0;
a0<=0;
a1<=0;
a2<=0;
a3<=0;
a4<=0;
temp1req<="000000000000";
elsif clk2='1' and clk2'event then
c1 : case s is 
when "000"=>
if i0=0 then
--temp1req<="000000000000";
l1fl <= "00";
l1s <= "0110";
i0<=i0+1;
elsif door_closed(0)='1' and i1=0 and i2=0 then 
i1<=1;
--s<="010";
elsif ((temp1req(11)='1' and temp1req(10 downto 9)/=l1fl)) and i2=0  and i1=0 then
i2<=1;
end if;
if i2<6 and i2>0  then
i2<=i2+1;
end if;
if i1<6 and i1>0 then
i1<=i1+1;
end if;
if i2=6 then
s<="100";
end if;
if i1=6 then
s<="010";
end if;
when "001"=>
ax1<=0;
ab5<=0;
i6<=0;
i7<=0;   
a0<=0;
a1<=0;
a2<=0;
if i3=0 then
temp1req<="000000000000";
l1s<="0110";
i3<=i3+1;
elsif door_closed(0)='1' and i4=0 and i5=0 then
i4<=1;
elsif ((temp1req(11)='1' and temp1req(10 downto 9)/=l1fl)) and i4=0  and i5=0 then
i5<=1;
end if;
if i4<6 and i4>0 then
i4<=i4+1;
end if;
if i5<6 and i5>0 then
i5<=i5+1;
end if;
if i4=6 then
s<="010";
end if;
if i5=6 then
s<="100";
end if; 
when "010"=>
i0 <=0;
i1<=0;   
i2<=0;
i4<=0;
i3<=0;   
i5<=0;
if i6=0 then
temp1req<="000000000000";
l1s<="1110";
i6<=i6+1;
elsif  l1fl_temp(2)='1' and  to_integer(unsigned(l1fl1_temp)) > to_integer(unsigned(l1fl)) and i7=0 then
s<="110";
elsif l1fl_temp(2)='1' and to_integer(unsigned(l1fl1_temp)) < to_integer(unsigned(l1fl)) and i7=0  then
s<="101";
elsif temp1req(11)='1' and (to_integer(unsigned(temp1req(10 downto 9))) > to_integer(unsigned(l1fl))) and i7=0 then
s<="110";
elsif temp1req(11)='1' and (to_integer(unsigned(temp1req(10 downto 9))) < to_integer(unsigned(l1fl))) and i7=0 then
s<="101";
elsif (door_open(0) or up_request(l1f) or down_request(l1f))='1' and i7=0 then 
i7<=1;
end if;
if i7>0 and i7 <6 then
i7<=i7+1;
end if;
if i7=6 then 
s<="001";
end if;
when "011"=>
ax1<=1;
a0<=0;
ab4<=0;
a1<=0;
a2<=0;
if i8=0 then
l1s<="0110";---------------lift open------------ 
i8<=1;
end if;
if i8<16 and i8>0 then
i8<=i8+1;
end if;
if i8=16 then
s<="100";
end if;
when "100"=>
i8<=0;
i4<=0;
i3<=0;   
i5<=0;
i0 <=0;
i1<=0;   
i2<=0;
a3<=0;
a4<=0;
if a0=0 then
l1s<="1110";--------------------lift close---------------------
a0<=1;
elsif (temp1req(11)='1' and temp1req(10 downto 9)=l1fl) and temp1req(8)='1' and a1=0 and a2=0 and ax1=0 then
a1<=1; 
elsif (temp1req(11)='1' and (to_integer(unsigned(temp1req(10 downto 9))) > to_integer(unsigned(l1fl)))) and a1=0 and a2=0 then
s<="110"; 
elsif (temp1req(11)='1' and (to_integer(unsigned(temp1req(10 downto 9))) < to_integer(unsigned(l1fl)))) and a1=0 and a2=0 then
s<="101";
elsif temp1req(8)='0' and a1=0 and a2=0 then 
a2<=1;
end if;
if door_open(0)='1' then
s<="011";
end if;
if a1<6 and a1>0 then
a1<=a1+1;
end if;
if a2<6 and a2>0 then
a2<=a2+1;
end if;
if a1=6 then 
s<="011";
ab4<=1;
--lift1_floor_indicatord(l1f)<='0';
--down_request_indicatord(l1f)<='0';
--up_request_indicatord(l1f)<='0';
temp1req<=temp1req(8 downto 0)&"000";
end if;
if a2=6 then
ab5<=1;
temp1req<="000000000000";
s<="001";
end if; 
when "101"=>
ax1<=0;
i6<=0;
i7<=0;   
a0<=0;
a1<=0;
a2<=0;
l1s<="1101";
if a3>-1 and a3<24 then
a3<= a3+1;
end if;
if a3=24 then
a3<=a3+1;
if l1fl="11" then
l1fl<="10";
elsif l1fl="10" then
l1fl<="01";
elsif l1fl="01" then
l1fl<="00";
elsif l1fl="00" then s<="100";
end if;
end if;
if a3=25 then
if  temp1req(10 downto 9)=l1fl then
s<="100";
else 
a3<=0;
end if;
end if;
when others=>
ax1<=0;
i6<=0;
i7<=0;   
a0<=0;
a1<=0;
a2<=0;
l1s<="1011";
--when "110"
if a4>-1 and a4<24 then
a4<= a4+1;
end if;
if a4=24 then
--l1fl<=l1fl+1;
if l1fl=00 then
l1fl<="01";
elsif l1fl=01 then
l1fl<="10";
elsif l1fl=10 then
l1fl<="11";
elsif l1fl=11 then s<="100";
end if;
a4<=a4+1;
end if;
if a4=25 then
if  temp1req(10 downto 9)=l1fl then
s<="100";
else 
a4<=0;
end if;
end if;
end case c1;
end if;
END PROCESS;
-----------------------------------------------lift2-control-system-------------------------------------------------------------------------
--l1s
PROCESS(clk2,reset)
BEGIN
temp2req<=curr_req_status2;
if reset='1' then
temp2req<="000000000000";
s1<="000";
i10<=0;
i11<=0;
i12<=0;
i13<=0;
i14<=0;
i15<=0;
i16<=0;
i17<=0;
i18<=0;
a10<=0;
a11<=0;
a12<=0;
a13<=0;
a14<=0;
elsif clk2='1' and clk2'event then
cc1 : case s1 is 
when "000"=>
if i10=0 then
--temp2req<="000000000000";
l2fl <= "00";
l2s <= "0110";
i10<=i10+1;
elsif door_closed(1)='1' and i11=0 and i12=0 then 
i11<=1;
--s<="010";
elsif ((temp2req(11)='1' and temp2req(10 downto 9)/=l2fl)) and i12=0  and i11=0 then
i12<=1;
end if;
if i12<6 and i12>0  then
i12<=i12+1;
end if;
if i11<6 and i11>0 then
i11<=i11+1;
end if;
if i12=6 then
s1<="100";
end if;
if i11=6 then
s1<="010";
end if;
when "001"=>
ax2<=0;
i16<=0;
ab7<=0;
i17<=0;   
a10<=0;
a11<=0;
a12<=0;
if i13=0 then
temp2req<="000000000000";
l2s<="0110";
i13<=i13+1;
elsif door_closed(1)='1' and i14=0 and i15=0 then
i14<=1;
elsif ((temp2req(11)='1' and temp2req(10 downto 9)/=l2fl)) and i14=0  and i15=0 then
i15<=1;
end if;
if i14<6 and i14>0 then
i14<=i14+1;
end if;
if i15<6 and i15>0 then
i15<=i15+1;
end if;
if i14=6 then
s1<="010";
end if;
if i15=6 then
s1<="100";
end if; 
when "010"=>
i10 <=0;
i11<=0;   
i12<=0;
i14<=0;
i13<=0;   
i15<=0;
if i16=0 then
temp2req<="000000000000";
l2s<="1110";
i16<=i16+1;
elsif  l2fl_temp(2)='1' and to_integer(unsigned(l2fl2_temp)) > to_integer(unsigned(l2fl)) and i17=0 then
s1<="110";
elsif l2fl_temp(2)='1' and to_integer(unsigned(l2fl2_temp)) < to_integer(unsigned(l2fl)) and i17=0  then
s1<="101";
elsif temp2req(11)='1' and (to_integer(unsigned(temp2req(10 downto 9))) > to_integer(unsigned(l2fl))) and i17=0 then
s1<="110";
elsif temp2req(11)='1' and (to_integer(unsigned(temp2req(10 downto 9))) < to_integer(unsigned(l2fl))) and i17=0 then
s1<="101";
elsif (door_open(1) or up_request(l2f) or down_request(l2f))='1' and i17=0 then 
i17<=1;
end if;
if i17>0 and i17 <6 then
i17<=i17+1;
end if;
if i17=6 then 
s1<="001";
end if;
when "011"=>
ax2<=1;
a10<=0;
ab6<=0;
a11<=0;
a12<=0;
if i18=0 then
l2s<="0110";
i18<=1;
end if;
if i18<16 and i18>0 then
i18<=i18+1;
end if;
if i18=16 then
s1<="100";
end if;
when "100"=>
i18<=0;
i14<=0;
i13<=0;   
i15<=0;
i10 <=0;
i11<=0;   
i12<=0;
a13<=0;
a14<=0;
if a10=0 then
l2s<="1110";
a10<=1;
elsif (temp2req(11)='1' and temp2req(10 downto 9)=l2fl) and temp2req(8)='1' and a11=0 and a12=0 and ax2=0 then
a11<=1; 
elsif (temp2req(11)='1' and (to_integer(unsigned(temp2req(10 downto 9))) > to_integer(unsigned(l2fl)))) and a11=0 and a12=0 then
s1<="110"; 
elsif (temp2req(11)='1' and (to_integer(unsigned(temp2req(10 downto 9))) < to_integer(unsigned(l2fl)))) and a11=0 and a12=0 then
s1<="101";
elsif temp2req(8)='0' and a11=0 and a12=0 then 
a12<=1;
end if;
if door_open(0)='1' then
s1<="011";
end if;
if a11<6 and a11>0 then
a11<=a11+1;
end if;
if a12<6 and a12>0 then
a12<=a12+1;
end if;
if a11=6 then 
ab6<=1;
--lift2_floor_indicatord(l2f)<='0';
--down_request_indicatord(l2f)<='0';
--up_request_indicatord(l2f)<='0';
s1<="011";
temp2req<=temp2req(8 downto 0)&"000";
end if;
if a12=6 then
ab7<=1;
temp2req<="000000000000";
s1<="001";
end if; 
when "101"=>
ax2<=0;
i16<=0;
i17<=0;   
a10<=0;
a11<=0;
a12<=0;
l2s<="1101";
if a13>-1 and a13<24 then
a13<= a13+1;
end if;
if a13=24 then
a13<=a13+1;
if l2fl="11" then
l2fl<="10";
elsif l2fl="10" then
l2fl<="01";
elsif l2fl="01" then
l2fl<="00";
elsif l2fl="00" then s1<="100";
end if;
end if;
if a13=25 then
if  temp2req(10 downto 9)=l2fl then
s1<="100";
else 
a13<=0;
end if;
end if;
when others=>
ax2<=0;
i16<=0;
i17<=0;   
a10<=0;
a11<=0;
a12<=0;
l2s<="1011";
--when "110"
if a14>-1 and a14<24 then
a14<= a14+1;
end if;
if a14=24 then
a14<=a14+1;
if l2fl=00 then
l2fl<="01";
elsif l2fl=01 then
l2fl<="10";
elsif l2fl=10 then
l2fl<="11";
elsif l2fl=11 then s1<="100";
end if;
end if;
if a14=25 then
if  temp2req(10 downto 9)=l2fl then
s1<="100";
else 
a14<=0;
end if;
end if;
end case cc1;
end if;
END PROCESS;
END Behavioral;
