-- UTN San Carlos Campus Edges
-- pathType: 1=Hallway, 2=Stairs, 3=Ramp, 4=Elevator, 5=Outdoor, 6=Bridge
-- status: 1=Open, 2=Closed, 3=Blocked, 4=Maintenance, 5=WeatherClosed, 6=EventClosed

-- Ground Floor Connections
INSERT INTO edges (id, weight, fromNodeId, toNodeId, status, pathType, slope) VALUES

-- Parking to Main Entrance (outdoor path)
(1, 8.5, 1, 2, 1, 5, 0.0),

-- Main Entrance to Main Building Junction
(2, 12.0, 1, 3, 1, 5, 0.0),

-- Main Building Ground Floor (hallways)
(3, 6.5, 3, 4, 1, 1, 0.0),     -- Junction to Cafeteria
(4, 7.0, 4, 5, 1, 1, 0.0),     -- Cafeteria to Library
(5, 6.0, 5, 6, 1, 1, 0.0),     -- Library to Bathrooms
(6, 5.5, 6, 7, 1, 1, 0.0),     -- Bathrooms to Stairs
(7, 3.0, 7, 8, 1, 1, 0.0),     -- Stairs to Elevator

-- Connection to Admin Building (outdoor)
(8, 15.0, 3, 9, 1, 5, 2.5),    -- Main Junction to Admin Junction (slight slope)

-- Admin Building Ground Floor
(9, 8.0, 9, 10, 1, 1, 0.0),    -- Admin Junction to Offices
(10, 7.5, 10, 11, 1, 1, 0.0),  -- Offices to Registry

-- Connection to Labs Building (outdoor)
(11, 18.0, 9, 12, 1, 5, 0.0),  -- Admin to Labs Junction

-- Labs Building Ground Floor
(12, 7.0, 12, 13, 1, 1, 0.0),  -- Labs Junction to Comp Lab
(13, 6.5, 13, 14, 1, 1, 0.0),  -- Comp Lab to Electronics Lab
(14, 6.0, 14, 15, 1, 1, 0.0),  -- Electronics Lab to Stairs

-- Vertical Connections - Main Building (Ground to Floor 1)
(15, 4.5, 7, 16, 1, 2, 45.0),  -- Stairs G to F1 (steep slope for stairs)
(16, 4.0, 8, 16, 1, 4, 0.0),   -- Elevator G to F1 (no slope)

-- Ramp alternative (accessible route)
(17, 15.0, 6, 16, 1, 3, 8.0),  -- Ramp from G bathrooms to F1 (gentle slope)

-- First Floor - Main Building
(18, 5.0, 16, 17, 1, 1, 0.0),  -- F1 Junction to Class 101
(19, 5.5, 17, 18, 1, 1, 0.0),  -- Class 101 to Class 102
(20, 10.0, 16, 19, 1, 1, 0.0), -- F1 Junction to Class 103
(21, 6.0, 19, 20, 1, 1, 0.0),  -- Class 103 to F1 Bathrooms

-- Vertical Connections - Labs Building (Ground to Floor 1)
(22, 4.5, 15, 21, 1, 2, 45.0), -- Stairs Labs G to F1

-- First Floor - Labs Building
(23, 6.5, 21, 22, 1, 1, 0.0),  -- F1 Labs Junction to Networks Lab
(24, 6.0, 22, 23, 1, 1, 0.0),  -- Networks Lab to Physics Lab

-- Connection between buildings on Floor 1 (bridge)
(25, 20.0, 16, 21, 1, 6, 0.0), -- Bridge Main to Labs F1

-- Vertical Connections - Main Building (Floor 1 to Floor 2)
(26, 4.5, 16, 24, 1, 2, 45.0), -- Stairs F1 to F2 (continues from same stairs)
(27, 4.0, 16, 24, 1, 4, 0.0),  -- Elevator F1 to F2

-- Second Floor - Main Building
(28, 6.5, 24, 25, 1, 1, 0.0),  -- F2 Junction to Auditorium
(29, 5.0, 24, 26, 1, 1, 0.0),  -- F2 Junction to Class 201
(30, 7.0, 24, 27, 1, 1, 0.0),  -- F2 Junction to F2 Bathrooms

-- Blocked/Special Status Edges (for testing scenarios)
(31, 10.0, 4, 9, 3, 5, 1.5),   -- Alternative outdoor path (Blocked - maintenance)
(32, 12.0, 5, 12, 5, 5, 0.0),  -- Shortcut Library to Labs (WeatherClosed - outdoor)
(33, 8.0, 18, 26, 4, 1, 0.0);  -- Shortcut stairwell Class 102 to Class 201 (Maintenance)
