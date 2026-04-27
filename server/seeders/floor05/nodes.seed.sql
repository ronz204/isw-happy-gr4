INSERT INTO nodes (type, floor, px, py, code, label, isLandmark) VALUES
-- Baños Floor 5 (Verde)
(6, 5, 497.0, 220.0, 'BATH-F5', 'Baños', 1),

-- Zona Chilling (Amarillo)
(7, 5, 474.0, 187.0, 'CHILL-F5', 'Zona Libre F5', 1),

-- Aulas 316 a 318 (Rojo)
(1, 5, 369.0, 247.0, 'R-324-F5', 'Aula 324', 1),
(1, 5, 404.0, 247.0, 'R-323-F5', 'Aula 323', 1),
(1, 5, 437.0, 247.0, 'R-322-F5', 'Aula 322', 1),
(1, 5, 558.0, 247.0, 'R-321-F5', 'Aula 321', 1),
(1, 5, 592.0, 247.0, 'R-320-F5', 'Aula 320', 1),
(1, 5, 627.0, 247.0, 'R-319-F5', 'Aula 319', 1),

-- ========================================================

-- Elevator - Edificio  (Morado)
(5, 5, 526.0, 190.0, 'EL-EDI-F5', 'Elevador F5', 0),

-- Stairs Izquierda - Arriba F6 y Abajo F4 (Morado)
(3, 5, 370.0, 185.0, 'ST-L1-DOWN-F4', 'Escalera F5-F4', 0),
(4, 5, 625.0, 185.0, 'ST-R1-DOWN-F4', 'Escalera F5-F4', 0),

-- ========================================================

-- Waypoints - Eje Horizontal, Izquierda Edificio (3 puntos)
(0, 5, 437.0, 220.0, 'WP-F5-21', '', 0),
(0, 5, 402.0, 220.0, 'WP-F5-22', '', 0),
(0, 5, 368.0, 220.0, 'WP-F5-23', '', 0),

-- Waypoints - Eje Horizontal, Derecha Edificio (3 puntos)
(0, 5, 556.0, 220.0, 'WP-F5-24', '', 0),
(0, 5, 590.0, 220.0, 'WP-F5-25', '', 0),
(0, 5, 624.0, 220.0, 'WP-F5-26', '', 0);
