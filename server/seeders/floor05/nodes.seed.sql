INSERT INTO nodes (type, floor, px, py, code, label, isLandmark) VALUES
-- Baños Floor 5 (Verde)
(6, 5, 932.0, 445.0, 'BATH-F5', 'Baños', 1),

-- Zona Chilling (Amarillo)
(7, 5, 892.0, 333.0, 'CHILL-F5', 'Zona Chilling', 1),

-- Aulas 316 a 318 (Rojo)
(1, 5, 693.0, 456.0, 'R-324-F5', 'Aula 324', 1),
(1, 5, 755.0, 456.0, 'R-323-F5', 'Aula 323', 1),
(1, 5, 818.0, 456.0, 'R-322-F5', 'Aula 322', 1),
(1, 5, 1042.0, 456.0, 'R-321-F5', 'Aula 321', 1),
(1, 5, 1109.0, 456.0, 'R-320-F5', 'Aula 320', 1),
(1, 5, 1175.0, 456.0, 'R-319-F5', 'Aula 319', 1),

-- ========================================================

-- Elevator - Edificio  (Morado)
(5, 5, 986.0, 345.0, 'EL-EDI-F5', 'Elevador F5', 0),

-- Stairs Izquierda - Arriba F6 y Abajo F4 (Morado)
(3, 5, 696.0, 346.0, 'ST-L1-DOWN-F4', 'Escalera F5-F4', 0),
(4, 5, 1172.0, 346.0, 'ST-R1-DOWN-F4', 'Escalera F5-F4', 0),

-- ========================================================

-- Waypoints - Eje Horizontal, Izquierda Edificio (4 puntos)
(0, 5, 884.0, 394.0, 'WP-F5-29', '', 0),
(0, 5, 821.0, 394.0, 'WP-F5-30', '', 0),
(0, 5, 754.0, 394.0, 'WP-F5-31', '', 0),
(0, 5, 687.0, 394.0, 'WP-F5-32', '', 0),

-- Waypoints - Eje Horizontal, Derecha Edificio (4 puntos)
(0, 5, 984.0, 394.0, 'WP-F5-33', '', 0),
(0, 5, 1041.0, 394.0, 'WP-F5-34', '', 0),
(0, 5, 1109.0, 394.0, 'WP-F5-35', '', 0),
(0, 5, 1174.0, 394.0, 'WP-F5-36', '', 0),

-- Waypoints - Eje Horizontal, Centro de Pasillo (1 punto)
(0, 5, 930.0, 394.0, 'WP-F5-37', '', 0),
