# UTN San Carlos Campus - Graph Visualization

## Campus Overview
- **Total Nodes**: 27
- **Total Edges**: 33 (30 Open, 3 Blocked/Closed)
- **Buildings**: Main Building, Admin Building, Labs Building
- **Floors**: Ground (0), First (1), Second (2)

---

## GROUND FLOOR (Floor 0) - ASCII Diagram

```
                            (1)★                    MAIN BUILDING
                        Entrada Principal           
                        /            \              
                    8.5m              12m            
                   Outdoor           Outdoor         
                     /                  \            
                   (2)                  (3)          
                 Parqueo              Junction       
                                      /    \         
                                   6.5m    15m       
                                   Hall    Outdoor   
                                    /         \      
                                  (4)★       (9)     ADMIN BUILDING
                               Cafetería   Junction  
                                  |           |  \   
                                 7m          8m  18m 
                                 Hall       Hall Outdoor
                                  |           |    \  
                                (5)★       (10)★ (12)  LABS BUILDING
                              Biblioteca  Oficinas Jct 
                                  |           |     |  
                                 6m         7.5m   7m  
                                 Hall       Hall  Hall 
                                  |           |     |  
                                (6)         (11)★ (13) 
                               Baños      Registro Lab1
                                  |                 |  
                                5.5m             6.5m  
                                 Hall            Hall  
                                  |                 |  
                                (7)──3m──(8)      (14) 
                             Stairs    Elevator  Lab2  
                                  |      |         |   
                                  └──────┘        6m   
                                                 Hall  
                                                  |    
                                                (15)   
                                               Stairs  

        BLOCKED EDGES (Not shown above):
        ⛔ (4)──X──(9)   [Edge 31: Blocked - Maintenance]
        🌧️ (5)──X──(12)  [Edge 32: WeatherClosed]
```

---

## FIRST FLOOR (Floor 1) - ASCII Diagram

```
                            MAIN BUILDING                    LABS BUILDING
                                                            
                    (18)───5.5m──(17)                             (23)
                   Aula102  Hall  Aula101                        Lab Física
                                    |                                |
                                   5m                               6m
                                   Hall                             Hall
                                    |                                |
                                  (16)════════20m Bridge════════>(21)
                                Junction                         Junction
                                  / | \                          /    \
                               10m 5m 7m                      6.5m    |
                              Hall Hall Hall                  Hall    |
                               /   |   \                       /      |
                            (19) (20) [UP]                  (22)     [UP]
                          Aula103 Baños  to F2            Lab Redes  to F2
                             ↑
                             |
                        [FROM GROUND]
                        Stairs (7)──4.5m
                        Elevator (8)──4m
                        Ramp (6)──15m

        BLOCKED EDGES:
        🔧 (18)──X──(26)  [Edge 33: Maintenance - shortcut to F2]
```

---

## SECOND FLOOR (Floor 2) - ASCII Diagram

```
                            MAIN BUILDING
                                
                                (24)
                             Junction
                            /    |    \
                         6.5m   5m    7m
                         Hall  Hall  Hall
                          /     |     \
                       (25)★  (26)   (27)
                    Auditorio Aula201 Baños
                    
                        ↑
                        |
                   [FROM FIRST]
                   Stairs (16)──4.5m
                   Elevator (16)──4m
```

---

## VERTICAL CONNECTIONS (All Floors)

```
    GROUND (0)          FIRST (1)           SECOND (2)
    
       (7)───────────────(16)───────────────(24)
    Stairs 4.5m      Stairs 4.5m
    
       (8)───────────────(16)───────────────(24)
    Elevator 4m      Elevator 4m
    
       (6)───────────────(16)
    Ramp 15m (accessible)
    
                    LABS BUILDING
    
      (15)───────────────(21)
    Stairs 4.5m
```

---

## COMPLETE NODE LIST

```
ID   CODE        LABEL                    FLOOR  TYPE  LANDMARK
──────────────────────────────────────────────────────────────────
(1)  ENT-MAIN    Entrada Principal        0      6     ★★★ Lvl1
(2)  PARK-01     Parqueo Principal        0      9     ★ Lvl3
(3)  JCT-01      Cruce Edificio Princ.    0      5     
(4)  CAF-01      Cafetería Central        0      8     ★★ Lvl2
(5)  LIB-01      Biblioteca               0      7     ★★★ Lvl1
(6)  BATH-01     Baños Edif. Principal    0      4     
(7)  STAIR-01    Escaleras Edif. Princ.   0      2     
(8)  ELEV-01     Elevador Edif. Princ.    0      3     
(9)  JCT-02      Cruce Administración     0      5     
(10) OFF-01      Oficinas Adminis.        0      10    ★★ Lvl2
(11) OFF-02      Registro y Matrícula     0      10    ★ Lvl3
(12) JCT-03      Cruce Laboratorios       0      5     
(13) LAB-01      Lab. Computación         0      12    
(14) LAB-02      Lab. Electrónica         0      12    
(15) STAIR-02    Escaleras Labs           0      2     
(16) JCT-04      Cruce Primer Piso        1      5     
(17) CLASS-01    Aula 101                 1      11    
(18) CLASS-02    Aula 102                 1      11    
(19) CLASS-03    Aula 103                 1      11    
(20) BATH-02     Baños Primer Piso        1      4     
(21) JCT-05      Cruce Labs P1            1      5     
(22) LAB-03      Lab. Redes               1      12    
(23) LAB-04      Lab. Física              1      12    
(24) JCT-06      Cruce Segundo Piso       2      5     
(25) AUD-01      Auditorio Principal      2      13    ★★ Lvl2
(26) CLASS-04    Aula 201                 2      11    
(27) BATH-03     Baños Segundo Piso       2      4     
```

---

## COMPLETE EDGE LIST

```
ID   FROM  TO   WEIGHT  TYPE       STATUS         SLOPE  NOTES
──────────────────────────────────────────────────────────────────────
1    2→1   8.5m  Outdoor    ✅ Open         0°     
2    1→3   12m   Outdoor    ✅ Open         0°     
3    3→4   6.5m  Hallway    ✅ Open         0°     
4    4→5   7m    Hallway    ✅ Open         0°     
5    5→6   6m    Hallway    ✅ Open         0°     
6    6→7   5.5m  Hallway    ✅ Open         0°     
7    7→8   3m    Hallway    ✅ Open         0°     
8    3→9   15m   Outdoor    ✅ Open         2.5°   
9    9→10  8m    Hallway    ✅ Open         0°     
10   10→11 7.5m  Hallway    ✅ Open         0°     
11   9→12  18m   Outdoor    ✅ Open         0°     
12   12→13 7m    Hallway    ✅ Open         0°     
13   13→14 6.5m  Hallway    ✅ Open         0°     
14   14→15 6m    Hallway    ✅ Open         0°     
15   7→16  4.5m  Stairs     ✅ Open         45°    🚫 Not wheelchair
16   8→16  4m    Elevator   ✅ Open         0°     ♿ Accessible
17   6→16  15m   Ramp       ✅ Open         8°     ♿ Accessible
18   16→17 5m    Hallway    ✅ Open         0°     
19   17→18 5.5m  Hallway    ✅ Open         0°     
20   16→19 10m   Hallway    ✅ Open         0°     
21   19→20 6m    Hallway    ✅ Open         0°     
22   15→21 4.5m  Stairs     ✅ Open         45°    🚫 Not wheelchair
23   21→22 6.5m  Hallway    ✅ Open         0°     
24   22→23 6m    Hallway    ✅ Open         0°     
25   16→21 20m   Bridge     ✅ Open         0°     
26   16→24 4.5m  Stairs     ✅ Open         45°    🚫 Not wheelchair
27   16→24 4m    Elevator   ✅ Open         0°     ♿ Accessible
28   24→25 6.5m  Hallway    ✅ Open         0°     
29   24→26 5m    Hallway    ✅ Open         0°     
30   24→27 7m    Hallway    ✅ Open         0°     
31   4→9   10m   Outdoor    ⛔ BLOCKED      1.5°   Maintenance
32   5→12  12m   Outdoor    🌧️ WEATHER     0°     Closed by rain
33   18→26 8m    Hallway    🔧 MAINTENANCE  0°     Under repair
```

---

## ACCESSIBILITY MATRIX

```
PROFILE              CAN USE STAIRS?  CAN USE RAMP?  CAN USE ELEVATOR?
────────────────────────────────────────────────────────────────────
Wheelchair           ❌ NO            ✅ YES         ✅ YES
Crutches             ⚠️ PENALTY 3x    ✅ YES         ✅ YES
LimitedMobility      ⚠️ PENALTY 2x    ✅ YES         ✅ YES
NewStudent           ✅ YES           ✅ YES         ✅ YES (prefers landmarks)
Regular              ✅ YES           ✅ YES         ✅ YES (shortest path)
Staff                ✅ YES           ✅ YES         ✅ YES
Visitor              ✅ YES           ✅ YES         ✅ YES
```

---

## TESTING SCENARIOS

### 1. Simple Path (Same Floor)
```
From: (1) Entrada Principal
To:   (5) Biblioteca
Expected: (1)→(3)→(4)→(5)
Distance: 25.5m (12+6.5+7)
```

### 2. Multi-Floor Path (Wheelchair User)
```
From: (1) Entrada Principal
To:   (17) Aula 101 (Floor 1)
Profile: Wheelchair
Must avoid: Stairs (edges 15, 26)
Options:
  - Via Elevator: (1)→(3)→(4)→(5)→(6)→(7)→(8)→(16)→(17)
  - Via Ramp:     (1)→(3)→(4)→(5)→(6)→(16)→(17)
Expected: Ramp route (shorter)
```

### 3. Blocked Edge Handling
```
From: (4) Cafetería
To:   (10) Oficinas Admin
Note: Direct path (edge 31) is BLOCKED
Expected: (4)→(3)→(9)→(10)
```

### 4. Cross-Building Journey
```
From: (2) Parqueo
To:   (22) Lab Redes (Floor 1, Labs Building)
Expected: (2)→(1)→(3)→...→(16)→(21)→(22)
Via: Bridge on Floor 1
```

### 5. NewStudent (Prefers Landmarks)
```
From: (1) Entrada Principal
To:   (19) Aula 103
Profile: NewStudent
Should favor: Routes passing through landmarks (4★, 5★)
Expected: Might take longer route to pass by Cafetería/Biblioteca
```

---

## LEGEND

**Symbols:**
- ★★★ = Landmark Level 1 (Very Important)
- ★★ = Landmark Level 2 (Important)
- ★ = Landmark Level 3 (Reference Point)
- ✅ = Open/Accessible
- ⛔ = Blocked
- 🌧️ = Weather Closed
- 🔧 = Under Maintenance
- ♿ = Wheelchair Accessible
- 🚫 = Not Wheelchair Accessible