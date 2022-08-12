# ChainSword

This project provides the code for a functionnal, 3D printed, chainsword using a microcontroller, a dc motor & a neopixel strip led.
 
The source code is a PlatformIO project, to build it you should open it in an IDE supporting PlatformIO. 
The project is configured to use a A-Star 32U4 Micro microcontroller.

The 3d models can be found [here](https://cults3d.com/fr/modèle-3d/jeu/space-wolves-chainsword).

## Building the chainsword
The following parameters explains how to build the chainsword. First you should gather all the needed parts :
- The 3D Printed parts
- The Hardware
- The Electronics

### Parts

#### 3D Printed Parts
To print the chainsword, I used the following parameters.

##### PLA 0.2mm
- Intermediate_Structure.stl x3 
- Bottom_Structure.stl x1
- Top_Structure x1
- Broom_Holder.stl x10
- Cross_Guard.stl x1
- Cross_Guard_Hatch.stl x1
- Guard.stl x1
- Handle.stl x1
- Base_Blade_Cover.stl x1
- Blade_Cover_First_Section.stl x1
- Blade_Cover_Second_Section.stl x1
- Blade_Cover_Third_Section.stl x1
- Blade_Cover_Head.stl x1
- Tooth_Base.stl x75

##### PLA 0.1mm
- Top_Structure_Gear_Rail.stl x1
- Top_Structure_End.stl x1
- Top_Gear_Wheel.stl x1
- Motorized_Gear_Wheel.stl x1
- Motorized_Gear_Wheel_Axis.stl x1
- Trigger.stl x1
- Trigger_Axis.stl x1
- Display_Gear_Wheel_Cover.stl x1
- Motor_Axis_Opening_Cover.stl x1
- Base_Blade_Cover_Teeth_Opening_Cover.stl x1

##### Phosphorescent PLA 0.1mm you could print these parts in normal PLA if you don't want to add leds in the blasde
- Blade_Cover_Head_Rune_Front.stl x1
- Blade_Cover_Head_Rune_Back.stl x1
- Blade_Cover_Third_Section_Front.stl x1
- Blade_Cover_Third_Section_Back.stl x1
- Blade_Cover_Second_Section_Front.stl x1
- Blade_Cover_Second_Section_Back.stl x1
- Blade_Cover_First_Section_Front.stl x1
- Blade_Cover_First_Section_Back.stl x1

##### Resin 0.05mm
- Display_Gear_Wheel.stl x1
- Tooth_Basic_Top.stl x64
- Tooth_V_Top.stl x1
- Tooth_L_Top.stl x1
- Tooth_K_Top.stl x2
- Tooth_A_Top.stl x2
- Tooth_F_Top.stl x1
- Tooth_E_Top.stl x1
- Tooth_N_Top.stl x1
- Tooth_R_Top.stl x1
- Tooth_Y_Top.stl x1

#### Hardware
You will also need the following hardware.

##### Screws
- M2x8 x4
- M2x12 x2
- M2x16 Screw x2
- M3x8 x7
- M3x12 x10
- M3x16 x40
- M3x20 x4
- M3x25 x2
- M3x30+ x1
- 3x20 wood screw x12

##### Nuts
- M2 x2
- M3 x55

##### Threaded Insert for plastic
- M3x10x5 x9
- M2x4x3.5 x6

##### Other
- Broom stick, around 120 cm, 25 mm diameter x1
- 608-zz ABEC bearing x2
- ~6x40mm spring x1
- ~7-20mm spring x1

#### Electronics
Finally the electronics part.

- GearMotor DG01D x1
- microswitch SS-5GL x1
- A-Star 32U4 Micro microcontroller x1
- WS2812B Led Strip x1 (at least 18 Leds)
- On/Off Switch x1
- transistor x1
- diode x1
- capacitor x1
- Battery 7.4v

### Tools
- M3 Hex Screwdriver
- M2 Hex Screwdriver
- Phillips Screwdriver
- Soldering Iron
- Cyanoacrylate Glue
- Plastic Glue
- Filler Primer
- Paint
- Sand paper


### Chainsword assembly
#### Chain assembly
**Parts**
- Tooth_Base.stl x75
- Tooth_Basic_Top.stl x64
- Tooth_V_Top.stl x1
- Tooth_L_Top.stl x1
- Tooth_K_Top.stl x2
- Tooth_A_Top.stl x2
- Tooth_F_Top.stl x1
- Tooth_E_Top.stl x1
- Tooth_N_Top.stl x1
- Tooth_R_Top.stl x1
- Tooth_Y_Top.stl x1

**Assembly**
1. Glue each _Top_ on each _Tooth_Base_ with Cyanoacrylate Glue.
2. Paint the teeth.
2. Clip the teeth with letters to form the text _VLKA FENRYKA_ separed by one normal tooth.
3. Clip the already formed chain and all the remaining teeth to form the final chain.

#### Cross Guard Assembly
**Parts**
- Cross_Guard.stl x1
- Trigger.stl x1
- Trigger_Axis.stl x1
- microswitch SS-5GL x1
- M2x4x3.5 Threaded Insert x4
- M2x16 Screw x2
- M2 Nut x2
- ~7-20mm spring x1

**Assembly**
1. Use filler primer on the _Cross_Guard_ and _Trigger_ parts, sand them and finally paint them.
2. Use a soldering iron to put the _inserts_ on the appropriate holes on the _Cross_Guard_ part.
3. Screw the _microswitch_ to the _Cross_Guard_ with the M2x16 Screws and the M2 Nuts (its easier to solder electric wire to the microswitch before fixing it).
4. Fix the _Trigger_ to the _Cross_Guard_ with the _Trigger_Axis_.
5. Put the _Sprint_ between the _Trigger_ and the _Cross_Guard_.

#### Structure assembly
**Parts**
- Intermediate_Structure.stl x3
- Bottom_Structure.stl x1
- Top_Structure x1
- Broom_Holder.stl x10
- Cross_Guard.stl x1
- Broom stick, around 120 cm, 25 mm diameter x1
- M3x16 x40
- M3x12 x10
- M3 Nuts x50

**Assembly**
1. Screw the _Cross_Guard_ with the _Bottom_Structure_ part using 2 M3x12 and 2 M3 Nuts.
2. Screw the 3 _Intermediate_Structure_ parts together and with the _Bottom_Structure_ using 6 M3x12 and 6 M3 Nuts.
3. Screw the _Top_Structure_ part with the result of the previous step using 2 M3x12 and 2 M3 Nuts.
4. Screw the _Broom_Holder_ parts to the structure using 40 M3x16 and 40 M3 Nuts.
5. Insert the _Broom Stick_ inside the holes along the structure.

#### Gears assembly
**Parts**
- GearMotor DG01D x1
- 608-zz ABEC bearing x2
- ~6x40mm spring x1
- Top_Structure_Gear_Rail.stl x1
- Top_Structure_End.stl x1
- Top_Gear_Wheel.stl x1
- Motorized_Gear_Wheel.stl x1
- Motorized_Gear_Wheel_Axis.stl x1
- M3x20 x2
- M3x25 x2
- M3 Nuts x4
- Chain

**Assembly**
1. Put the _Gear Motor_ on the location provided on the _Bottom_Structure_ part with 2 M3x25 screw and 2 M3 nuts.
2. Fix the _Motorized_Gear_Wheel_ to the _Gear Motor_.
3. Glue the _Motorized_Gear_Wheel_Axis_ to the _Motorized_Gear_Wheel_ then put 1 bearing on the location provided on the _Bottom_Structure_ in such a way that the _Motorized_Gear_Wheel_Axis_ is inside the bearing.
